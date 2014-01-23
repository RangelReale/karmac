#include "KarMac/Lib/KMPackage/PackageEditor.h"
#include "KarMac/Lib/KMPackage/FileDef.h"
#include "KarMac/exception.h"

#include <fstream>
#include <cstring>

namespace KarMac {
namespace Lib {
namespace KMPackage {


PackageEditorSong::PackageEditorSong() :
	_data()
{

}

void PackageEditorSong::setData(const std::string &data)
{
	_data = data;
}

void PackageEditorSong::setData(std::istream &data)
{
	std::istreambuf_iterator<char> eos;
	_data = std::string(std::istreambuf_iterator<char>(data), eos);
}

void PackageEditorSong::setDataFromFile(const std::string filename)
{
	std::fstream f(filename, std::ios_base::in | std::ios_base::binary);
	setData(f);
}


PackageEditor::PackageEditor()
{

}

PackageEditor::PackageEditor(const std::string &filename)
{
	load(filename);
}

void PackageEditor::load(const std::string &filename)
{
	shared_ptr<std::istream> f = new std::ifstream(filename.c_str(), std::ios_base::in | std::ios_base::binary);
	f->exceptions (std::ifstream::failbit|std::ifstream::badbit);

	KMFileDef header;
	f->read(reinterpret_cast<char*>(&header), sizeof(header));

	if (strncmp(reinterpret_cast<char*>(header.magic), KMFILEDEF_MAGIC, KMFILEDEF_MAGIC_SIZE) != 0)
		throw Exception("Invalid package file");
}

void PackageEditor::save(const std::string &filename)
{
	std::fstream f(filename, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
	f.exceptions (std::ifstream::failbit|std::ifstream::badbit);

	KMFileDef header;
	strncpy((char*)header.magic, KMFILEDEF_MAGIC, KMFILEDEF_MAGIC_SIZE);
	header.version = KMFILEDEF_VERSION;
	strncpy(header.name, _name.c_str(), KMFILEDEF_MAX_NAME);
	strncpy(header.author, _author.c_str(), KMFILEDEF_MAX_NAME);
	strncpy(header.producer, "001", 3);
	strncpy(header.collection, "01", 2);
	header.amount = _songs.size();

	f.write((char*)&header, sizeof(header));

	for (songs_t::iterator i=_songs.begin(); i!=_songs.end(); i++)
	{
		KMFileSongDef song;
		strncpy((char*)song.magic, KMFILEDEF_SONG_MAGIC, KMFILEDEF_MAGIC_SIZE);
		strncpy(song.title, (*i)->getTitle().c_str(), KMFILEDEF_MAX_NAME);
		strncpy(song.artist, (*i)->getArtist().c_str(), KMFILEDEF_MAX_NAME);
		song.size = (*i)->getData().size();

		f.write((char*)&song, sizeof(song));
	}

	for (songs_t::iterator i=_songs.begin(); i!=_songs.end(); i++)
	{
		f.write((*i)->getData().c_str(), (*i)->getData().size());
	}

	f.close();
}

PackageEditorSong::Ptr PackageEditor::add()
{
	PackageEditorSong::Ptr ret(new PackageEditorSong);
	_songs.push_back(ret);
	return ret;
}

} } } // KarMac::Lib::KMPackage
