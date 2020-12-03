#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <exception>

#include "Song.h"

class SongCollection
{
private:
	vector<Song> songs;

public:
	SongCollection();
	void importSongs();
};