#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <exception>

#include "Song.h"

class SongData 
{
private:
	vector<Song> songs;

public:
	SongData();
	void importSongs();
};