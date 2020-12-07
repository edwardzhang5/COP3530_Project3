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
	int numSongs;

public:
	SongCollection();
	SongCollection(vector<Song> songs);
	vector<Song> songs;
	vector<Song> recommended1;
	vector<Song> recommended2;

	void importSongs();

	void quickSort(string attribute, int low, int high);
	int partition(string attribute, int low, int high);
	void swap(int index1, int index2);

	void heapifyDown(int index,string attribute, int size);
	void heapSort(string attribute);

	int getNumSongs();

	void testPrint(string attribute);
};