#include "KarMac/Lib/KMPackage/Package.h"
#include "KarMac/Lib/KMPackage/FileDef.h"
#include "KarMac/exception.h"

#include <fstream>
#include <cstring>

namespace KarMac {
namespace Lib {
namespace KMPackage {

Package::Package()
{

}

Package::Package(const std::string &filename)
{
	load(filename);
}

void Package::load(const std::string &filename)
{
	shared_ptr<std::istream> f = new std::ifstream(filename.c_str(), std::ios_base::in | std::ios_base::binary);
	f->exceptions (std::ifstream::failbit|std::ifstream::badbit);

	KMFileDef header;
	f->read(reinterpret_cast<char*>(&header), sizeof(header));

	if (strncmp(reinterpret_cast<char*>(header.magic), KMFILEDEF_MAGIC, KMFILEDEF_MAGIC_SIZE) != 0)
		throw Exception("Invalid package file");

	_stream = f;
}

} } } // KarMac::Lib::KMPackage
