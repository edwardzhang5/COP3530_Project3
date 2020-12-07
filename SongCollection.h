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
	int numSongs; // number of songs in dataset

public:
	SongCollection(); // default constructor
	SongCollection(vector<Song> songs);
	vector<Song> songs; // vector of all songs in dataset
	vector<Song> recommended1; // vector of recommended song outputs
	vector<Song> recommended2; // copy of vector of song outputs; used for sort time comparison

	void importSongs(); // method to read in all files from data.csv

	void quickSort(string attribute, int low, int high); // quick sort method 
	int partition(string attribute, int low, int high); // partition method used in quick sort
	void swap(int index1, int index2); // swaps two elements of the song vector based on input
	void heapifyDown(int index,string attribute, int size); // heapify down method used in heapsort
	void heapSort(string attribute); // heap sort based on selected attribute
	int getNumSongs(); // returns the number of songs
	void testPrint(string attribute); // prints all song names and selected attribute
};