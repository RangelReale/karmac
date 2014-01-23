#ifndef H__KMPACKAGE_FILEDEF__H
#define H__KMPACKAGE_FILEDEF__H

#include <string>
#include <iostream>
#include <cstdint>

#define KMFILEDEF_MAX_NAME 200

#define KMFILEDEF_VERSION 1

#define KMFILEDEF_MAGIC_SIZE 4
#define KMFILEDEF_MAGIC "KMPK"
#define KMFILEDEF_SONG_MAGIC "KMSG"

namespace KarMac {
namespace Lib {
namespace KMPackage {


#pragma pack(push, 1)

typedef struct _KMFileDef
{
	int8_t magic[KMFILEDEF_MAGIC_SIZE];
	int8_t version;
	char name[KMFILEDEF_MAX_NAME];
	char author[KMFILEDEF_MAX_NAME];

	// ID
	char producer[3];
	char collection[2];
	int16_t amount;
} KMFileDef;

typedef struct _KMFileSongDef
{
	int8_t magic[KMFILEDEF_MAGIC_SIZE];
	char title[KMFILEDEF_MAX_NAME];
	char artist[KMFILEDEF_MAX_NAME];
	int32_t size;
} KMFileSongDef;

#pragma pack(pop)

} } } // KarMac::Lib::KMPackage

#endif // H__KMPACKAGE_FILEDEF__H