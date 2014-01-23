#include <KarMac/Lib/KMPackage/PackageEditor.h>

#include <fstream>

using namespace KarMac::Lib::KMPackage;

int main(int argc, char *argv[])
{
	PackageEditor p;

	p.setName("Random Test Music Selection");
	p.setAuthor("Rangel Reale <rangelspam@gmail.com>");
	
	PackageEditorSong::Ptr song1 = p.add();
	song1->setTitle("Be Bop a Lula");
	song1->setArtist("Unknown");
	song1->setDataFromFile("C:\\mp3\\kar\\be_bop_a_lula_karaoke_songs_NifterDotCom.kar");

	PackageEditorSong::Ptr song2 = p.add();
	song2->setTitle("Born to be Wild");
	song2->setArtist("Steppenwolf");
	song2->setDataFromFile("C:\\mp3\\kar\\born_to_be_wild_karaoke_songs_NifterDotCom.kar");

	PackageEditorSong::Ptr song3 = p.add();
	song3->setTitle("California Dreamin");
	song3->setArtist("The Mammas and the Pappas");
	song3->setDataFromFile("C:\\mp3\\kar\\california_dreamin_karaoke_songs_NifterDotCom.kar");

	PackageEditorSong::Ptr song4 = p.add();
	song4->setTitle("Can't wait to be king");
	song4->setArtist("The Lion King");
	song4->setDataFromFile("C:\\mp3\\kar\\can't_wait_to_be_king_karaoke_songs_NifterDotCom.kar");

	PackageEditorSong::Ptr song5 = p.add();
	song5->setTitle("Cocaine");
	song5->setArtist("Elthon John");
	song5->setDataFromFile("C:\\mp3\\kar\\can'cocaine_karaoke_songs_NifterDotCom.kar");

	p.save("C:\\mp3\\kar\\package1.kmp");
}