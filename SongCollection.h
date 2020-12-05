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
	SongCollection(vector<Song> songs);
	void importSongs();
	void heapifyDown(int index,string attribute, int size);
	void heapSort(string attribute);
	void testPrint();
};