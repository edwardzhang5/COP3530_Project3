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
	int numSongs;

public:
	SongCollection();
	SongCollection(vector<Song> songs);
	void importSongs();

	void quickSort(string attribute, int low, int high);
	int partition(string attribute, int low, int high);
	void swap(int index1, int index2);

	void heapifyDown(int index,string attribute, int size);
	void heapSort(string attribute);

	int getNumSongs();

	void testPrint();
};