#ifndef H__KMPACKAGE_PACKAGE__H
#define H__KMPACKAGE_PACKAGE__H

#include "KarMac/shared_ptr.h"

#include <string>
#include <iostream>
#include <sstream>

namespace KarMac {
namespace Lib {
namespace KMPackage {

class Package 
{
public:
	Package();
	Package(const std::string &filename);
	virtual ~Package() {}

	void load(const std::string &filename);
private:
	shared_ptr<std::istream> _stream;
};

} } } // KarMac::Lib::KMPackage

#endif // H__KMPACKAGE_PACKAGE__H