#ifndef H__KMPACKAGE_PACKAGEEDITOR__H
#define H__KMPACKAGE_PACKAGEEDITOR__H

#include "KarMac/shared_ptr.h"

#include <string>
#include <iostream>
#include <sstream>
#include <cstdint>
#include <vector>

namespace KarMac {
namespace Lib {
namespace KMPackage {

class PackageEditorSong
{
public:
	typedef shared_ptr<PackageEditorSong> Ptr;

	PackageEditorSong();
	virtual ~PackageEditorSong() {}

	const std::string &getTitle() const { return _title; }
	void setTitle(const std::string &title) { _title = title; }

	const std::string &getArtist() const { return _artist; }
	void setArtist(const std::string &artist) { _artist = artist; }

	const std::string &getData() const { return _data; }

	void setData(const std::string &data);
	void setData(std::istream &data);
	void setDataFromFile(const std::string filename);
private:
	std::string _title;
	std::string _artist;
	std::string _data;
};

class PackageEditor
{
public:
	typedef std::vector<PackageEditorSong::Ptr> songs_t;

	PackageEditor();
	PackageEditor(const std::string &filename);
	virtual ~PackageEditor() {}

	const std::string &getName() const { return _name; }
	void setName(const std::string &name) { _name = name; }

	const std::string &getAuthor() const { return _author; }
	void setAuthor(const std::string &author) { _author = author; }

	songs_t &getSongs() { return _songs; }

	void load(const std::string &filename);
	void save(const std::string &filename);

	PackageEditorSong::Ptr add();
private:
	std::string _name;
	std::string _author;
	songs_t _songs;
};

} } } // KarMac::Lib::KMPackage

#endif // H__KMPACKAGE_PACKAGEEDITOR__H