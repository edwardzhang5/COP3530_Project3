#include "SongCollection.h"

using namespace std;

SongCollection::SongCollection()
{
	songs = {};
	numSongs = 0;
}

SongCollection::SongCollection(vector<Song> songs)
{
	this->songs = songs;
	numSongs = songs.size();
}

void SongCollection::importSongs()
{
	ifstream file;
	file.open("data.csv");
	string line;

	getline(file, line); // gets rid of first line of csv
	
	while (getline(file, line)) {
		numSongs++; // Keeps track of number of songs in collection

		//========== Valence ==========//
		string temp;
		auto i1 = line.find(",");
		temp = line.substr(0, i1);
		double valence = stod(temp);
		if (valence > 1) { valence = 1; }
		if (valence < 0) { valence = 0; }
		// cout << temp << ", ";
		line = line.substr(i1 + 1);


		//========== Year ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		int year = stoi(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);


		//========== Acoustic ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		double acoustic = stod(temp);
		if (acoustic > 1) { acoustic = 1; }
		if (acoustic < 0) { acoustic = 0; }
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

		//========== Finding Artists ==========//
		vector<string> artists;
		i1 = line.find("[");
		auto i2 = line.find(",");
		auto i3 = line.find("]");

		while (i2 < i3)
		{
			temp = line.substr(i1 + 2, i2 - i1 - 3);
			artists.push_back(temp);
			// cout << temp << ", ";
			line = line.substr(i2 + 1);
			i1 = line.find(" ");
			i2 = line.find(",");
			i3 = line.find("]");
		}

		temp = line.substr(i1 + 2, i3 - i1 - 3);
		artists.push_back(temp);
		// cout << temp << ", ";
		line = line.substr(i2 + 1);
		//========== End Finding Artists ==========//

		
		//========== Dance ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		double dance = stod(temp);
		if (dance > 1) { dance = 1; }
		if (dance < 0) { dance = 0; }
		// cout << temp << ", ";
		line = line.substr(i1 + 1);


		//========== Duration ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		int duration = stoi(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);


		//========== Energy ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		double energy = stod(temp);
		if (energy > 1) { energy = 1; }
		if (energy < 0) { energy = 0; }
		// cout << temp << ", ";
		line = line.substr(i1 + 1);


		//========== Explicit ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		int exp = stoi(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);


		//========== ID ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		string id = temp;
		// cout << temp << ", ";
		line = line.substr(i1 + 1);


		//========== Instrumental ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		double instrumental = stod(temp);
		if (instrumental > 1) { instrumental = 1; }
		if (instrumental < 0) { instrumental = 0; }
		// cout << temp << ", ";
		line = line.substr(i1 + 1);


		//========== Key ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		int key = stoi(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);


		//========== Liveness ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		double liveness = stod(temp);
		if (liveness > 1) { liveness = 1; }
		if (liveness < 0) { liveness = 0; }
		// cout << temp << ", ";
		line = line.substr(i1 + 1);


		//========== Loudness ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		double loudness = stod(temp);
		if (loudness > 0) { loudness = 0; }
		if (loudness < -60) { loudness = -60; }
		loudness += 60;
		loudness = loudness / 60;
		// Min: Multiple : -60
		// Max: Multiple : 0
		// cout << temp << ", ";
		line = line.substr(i1 + 1);


		//========== Mode ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		int mode = stoi(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);


		//========== Finding Name ==========//
		i1 = line.find("\"");
		i2 = line.find_last_of("\"");
		string name;

		if (i1 != -1)
		{
			temp = line.substr(i1 + 1, i2 - i1);
			name = temp;
			// cout << temp << ", ";
			line = line.substr(i2 + 2);
		}

		else
		{
			i1 = line.find(",");
			temp = line.substr(0, i1);
			name = temp;
			// cout << temp << ", ";
			line = line.substr(i1 + 1);
		}
		//========== End Finding Name ==========//


		//========== Popularity ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		int popularity = stoi(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

		
		//========== Release Year ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		int release_year = stoi(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);
		
		
		//========== Speech ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		double speech = stod(temp);
		if (speech > 1) { speech = 1; }
		if (speech < 0) { speech = 0; }
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

		
		//========== Tempo ==========//
		i1 = line.find(",");
		temp = line.substr(0, i1);
		double tempo = stod(temp);
		tempo = tempo / 243.507;
		// Min: Multiple : 0
		// Max: "I Don't Want You On My Mind" : 243.507
		// cout << temp << endl;

		Song se(valence, year, acoustic, artists, dance, duration, energy, exp, id, instrumental, key, liveness, loudness, mode, name, popularity, release_year, speech, tempo);
		songs.push_back(se);

	}
	// cout << songs.size();

}

void SongCollection::quickSort(string attribute, int low, int high)
{
	if (low < high) 
	{
		int piv = partition(attribute, low, high);

		// Sorts elements before and after partition
		quickSort(attribute, low, piv - 1);
		quickSort(attribute, piv + 1, high);

	}
}

int SongCollection::partition(string attribute, int low, int high)
{
	if (attribute == "Acoustic" || attribute == "acoustic")
	{
		
	}

	else if (attribute == "Dance" || attribute == "dance")
	{

	}

	else if (attribute == "Energy" || attribute == "energy")
	{
		
	}

	else if (attribute == "Instrumental" || attribute == "instrumental")
	{
		
	}

	else if (attribute == "Liveness" || attribute == "liveness")
	{
		
	}

	else if (attribute == "Loudness" || attribute == "loudness")
	{
		
	}

	else if (attribute == "Speech" || attribute == "speech")
	{
		
	}

	else if (attribute == "Valence" || attribute == "valence")
	{
		
	}

	else if (attribute == "Tempo" || attribute =="tempo")
	{
		
	}

}

void SongCollection::swap(int index1, int index2)
{
	auto temp = songs[index1];
	songs[index1] = songs[index2];
	songs[index2] = temp;
}

void SongCollection::heapifyDown(int index, string attribute, int size)
{
	
		int leftIndex = (2 * index) + 1;
		int rightIndex = (2 * index) + 2;
		int greatestIndex = index;
		
		//Different if branch is entered depending on which attribute we are sorting by
		if (attribute == "Acoustic")
		{
			if (leftIndex < size && songs.at(leftIndex).getAcoustic() > songs.at(greatestIndex).getAcoustic())
			{
				greatestIndex = leftIndex;
			}

			if (rightIndex < size && songs.at(rightIndex).getAcoustic() > songs.at(greatestIndex).getAcoustic())
			{
				greatestIndex = rightIndex;
			}
		}

		else if (attribute == "Dance")
		{
			if (leftIndex < size && songs.at(leftIndex).getDance() > songs.at(greatestIndex).getDance())
			{
				greatestIndex = leftIndex;
			}

			if (rightIndex < size && songs.at(rightIndex).getDance() > songs.at(greatestIndex).getDance())
			{
				greatestIndex = rightIndex;
			}
		}

		else if (attribute == "Energy")
		{
			if (leftIndex < size && songs.at(leftIndex).getEnergy() > songs.at(greatestIndex).getEnergy())
			{
				greatestIndex = leftIndex;
			}

			if (rightIndex < size && songs.at(rightIndex).getEnergy() > songs.at(greatestIndex).getEnergy())
			{
				greatestIndex = rightIndex;
			}
		}

		else if (attribute == "Instrumental")
		{
			if (leftIndex < size && songs.at(leftIndex).getInstrumental() > songs.at(greatestIndex).getInstrumental())
			{
				greatestIndex = leftIndex;
			}

			if (rightIndex < size && songs.at(rightIndex).getInstrumental() > songs.at(greatestIndex).getInstrumental())
			{
				greatestIndex = rightIndex;
			}
		}

		else if (attribute == "Liveness")
		{
			if (leftIndex < size && songs.at(leftIndex).getLiveness() > songs.at(greatestIndex).getLiveness())
			{
				greatestIndex = leftIndex;
			}

			if (rightIndex < size && songs.at(rightIndex).getLiveness() > songs.at(greatestIndex).getLiveness())
			{
				greatestIndex = rightIndex;
			}
		}

		else if (attribute == "Loudness")
		{
			if (leftIndex < size && songs.at(leftIndex).getLoudness() > songs.at(greatestIndex).getLoudness())
			{
				greatestIndex = leftIndex;
			}

			if (rightIndex < size && songs.at(rightIndex).getLoudness() > songs.at(greatestIndex).getLoudness())
			{
				greatestIndex = rightIndex;
			}
		}

		else if (attribute == "Speech")
		{
			if (leftIndex < size && songs.at(leftIndex).getSpeech() > songs.at(greatestIndex).getSpeech())
			{
				greatestIndex = leftIndex;
			}

			if (rightIndex < size && songs.at(rightIndex).getSpeech() > songs.at(greatestIndex).getSpeech())
			{
				greatestIndex = rightIndex;
			}
		}

		else if (attribute == "Valence")
		{
			if (leftIndex < size && songs.at(leftIndex).getValence() > songs.at(greatestIndex).getValence())
			{
				greatestIndex = leftIndex;
			}

			if (rightIndex < size && songs.at(rightIndex).getValence() > songs.at(greatestIndex).getValence())
			{
				greatestIndex = rightIndex;
			}
		}

		else if (attribute == "Tempo")
		{
			if (leftIndex < size && songs.at(leftIndex).getTempo() > songs.at(greatestIndex).getTempo())
			{
				greatestIndex = leftIndex;
			}

			if (rightIndex < size && songs.at(rightIndex).getTempo() > songs.at(greatestIndex).getTempo())
			{
				greatestIndex = rightIndex;
			}
		}

	
		// swap if one of the children of index are greater
		if (greatestIndex != index)
		{
			Song temp = songs.at(index);
			songs.at(index) = songs.at(greatestIndex);
			songs.at(greatestIndex) = temp;
			heapifyDown(greatestIndex,attribute,size);
		}
	
}

void SongCollection::heapSort(string attribute)
{
	//build max heap
	for (int i = songs.size() / 2; i > 0; i--)
	{
		//heapify based on which attribute we are sorting by
		heapifyDown(i - 1, attribute, songs.size());
	}

	int endIndex = songs.size() - 1;
	for (endIndex; endIndex > 0; endIndex--)
	{
		Song temp = songs.at(0);
		songs.at(0) = songs.at(endIndex);
		songs.at(endIndex) = temp;

		heapifyDown(0, attribute, endIndex);
		
	}

}

int SongCollection::getNumSongs()
{
	return numSongs;
}

//test print method to see if sorts worked
void SongCollection::testPrint()
{
	for (int x = 0; x < songs.size(); x++)
	{
		cout << songs.at(x).getLoudness() <<" " << songs.at(x).getName() << endl;
	}

}