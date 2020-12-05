#include <iostream>
#include <string>
#include <vector>

#include "SongCollection.h"

using namespace std;



int main()
{
	SongCollection songs;
	songs.importSongs();

	songs.heapSort("Acoustic");
	songs.testPrint();

	

	return 0;
}