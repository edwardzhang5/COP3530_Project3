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

		string temp;
		auto i1 = line.find(",");
		temp = line.substr(0, i1);
		double valence = stod(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		int year = stoi(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		int acoustic = stoi(temp);
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

		i1 = line.find(",");
		temp = line.substr(0, i1);
		double dance = stod(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		int duration = stoi(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		double energy = stod(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		int exp = stoi(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		string id = temp;
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		double instrumental = stod(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		int key = stoi(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		double liveness = stod(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		double loudness = stod(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

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
			temp = line.substr(i1 + 1, i2 - i1 - 2);
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

		i1 = line.find(",");
		temp = line.substr(0, i1);
		int popularity = stoi(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		int release_year = stoi(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);
		
		i1 = line.find(",");
		temp = line.substr(0, i1);
		double speech = stod(temp);
		// cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		double tempo = stod(temp);
		// cout << temp << endl;

		Song se(valence, year, acoustic, artists, dance, duration, energy, exp, id, instrumental, key, liveness, loudness, mode, name, popularity, release_year, speech, tempo);
		songs.push_back(se);

	}

}

