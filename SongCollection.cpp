#include "SongCollection.h"

using namespace std;

SongCollection::SongCollection()
{
	songs = {};
}

void SongCollection::importSongs()
{
	ifstream file;
	file.open("data.csv");
	string line;

	getline(file, line); // gets rid of first line of csv

	while (getline(file, line)) {
		stringstream s (line);
		string temp;

		getline(s, temp, ',');
		double valence = stod(temp);

		getline(s, temp, ',');
		int year = stoi(temp);
		
		getline(s, temp, ',');
		double acoustic = stod(temp);

		getline(s, temp, ']');
		// Code for inserting these things into a vector!
		vector<string> artists;

		temp = temp.substr(2);
		auto c = temp.find("'");
		string oneName;
		while (c != string::npos) {
			oneName = temp.substr(0, c);
			artists.push_back(oneName);
			if (temp.size() > (4 + c))
				temp = temp.substr(c + 4);
			else
				break;
			c = temp.find("'");
		}

		getline(s, temp, ','); // Moving getline to correct position
		getline(s, temp, ',');
		double dance = stod(temp);

		getline(s, temp, ',');
		int duration = stoi(temp);

		getline(s, temp, ',');
		double energy = stod(temp);

		getline(s, temp, ',');
		int exp = stoi(temp);

		getline(s, temp, ',');
		string id = temp;

		getline(s, temp, ',');
		double instrumental = stod(temp);

		getline(s, temp, ',');
		int key = stoi(temp);

		getline(s, temp, ',');
		double liveness = stod(temp);

		getline(s, temp, ',');
		double loudness = stod(temp);

		getline(s, temp, ',');
		int mode = stoi(temp);

		getline(s, temp, '"');
		getline(s, temp, '"');
		string name = temp;
		
		getline(s, temp, ','); // moving getline to right position
		getline(s, temp, ',');
		int popularity = stoi(temp);

		getline(s, temp, ',');
		int release_year = stoi(temp);

		getline(s, temp, ',');
		double speech = stod(temp);

		getline(s, temp, ',');
		double tempo = stod(temp);
		
		Song se(valence, year, acoustic, artists, dance, duration, energy, exp, id, instrumental, key, liveness, loudness, mode, name, popularity, release_year, speech, tempo);
		songs.push_back(se);
	}

}

