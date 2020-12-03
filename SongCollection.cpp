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
		

		int i1;
		int i2;
		int i3;
		string temp;
		
		i1 = line.find(",");
		temp = line.substr(0, i1);
		double valence = stod(temp);
		cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		int year = stoi(temp);
		cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		int acoustic = stod(temp);
		cout << temp << ", ";
		line = line.substr(i1 + 1);

		//========== Finding Artists ==========//
		vector<string> artists;
		i1 = line.find("[");
		i2 = line.find(",");
		i3 = line.find("]");

		while (i2 < i3)
		{
			temp = line.substr(i1 + 2, i2 - i1 - 3);
			artists.push_back(temp);
			cout << temp << ", ";
			line = line.substr(i2 + 1);
			i1 = line.find(" ");
			i2 = line.find(",");
			i3 = line.find("]");
		}

		temp = line.substr(i1 + 2, i3 - i1 - 3);
		artists.push_back(temp);
		cout << temp << ", ";
		line = line.substr(i2 + 1);
		//========== End Finding Artists ==========//

		i1 = line.find(",");
		temp = line.substr(0, i1);
		double dance = stod(temp);
		cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		int duration = stoi(temp);
		cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		double energy = stod(temp);
		cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		int exp = stoi(temp);
		cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		string id = temp;
		cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		double instrumental = stod(temp);
		cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		int key = stoi(temp);
		cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		double liveness = stod(temp);
		cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		double loudness = stod(temp);
		cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		int mode = stoi(temp);
		cout << temp << ", ";
		line = line.substr(i1 + 1);

		//========== Finding Name ==========//
		i1 = line.find("\"");
		i2 = line.find_last_of("\"");
		string name;

		if (i1 != -1)
		{
			temp = line.substr(i1 + 1, i2 - i1 - 2);
			name = temp;
			cout << temp << ", ";
			line = line.substr(i2 + 2);
		}

		else
		{
			i1 = line.find(",");
			temp = line.substr(0, i1);
			name = temp;
			cout << temp << ", ";
			line = line.substr(i1 + 1);
		}

		i1 = line.find(",");
		temp = line.substr(0, i1);
		int popularity = stoi(temp);
		cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		int release_year = stoi(temp);
		cout << temp << ", ";
		line = line.substr(i1 + 1);
		
		i1 = line.find(",");
		temp = line.substr(0, i1);
		double speech = stod(temp);
		cout << temp << ", ";
		line = line.substr(i1 + 1);

		i1 = line.find(",");
		temp = line.substr(0, i1);
		double tempo = stod(temp);
		cout << temp << endl;

		Song se(valence, year, acoustic, artists, dance, duration, energy, exp, id, instrumental, key, liveness, loudness, mode, name, popularity, release_year, speech, tempo);
		songs.push_back(se);

		/*
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
		if (temp.find("\"") != string::npos) {
			temp = temp.substr(3);
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
		}
		else {
			temp = temp.substr(2);
			auto c = temp.find("'");
			string oneName = temp.substr(0, c);
			artists.push_back(oneName);
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

		
		getline(s, temp, ',');
		string temp1 = "";
		int found = 0;
		if (temp.find('\"') != string::npos) {
			getline(s, temp1, '\"');
			found = 1;
		}
		string name = temp.substr(found)+temp1;
		
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
		*/
	}

}

