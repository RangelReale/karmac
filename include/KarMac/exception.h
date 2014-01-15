#ifndef H__KARMAC_EXCEPTION__H
#define H__KARMAC_EXCEPTION__H

#include <stdexcept>
#include <string>

namespace KarMac 
{

class Exception : public std::exception
{
public:
	Exception(const std::string &m) : m(m) {}
	const char* what() const throw() { return m.c_str(); }
private:
	std::string m;
};

} // KarMac

#endif