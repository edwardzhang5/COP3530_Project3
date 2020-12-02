#include "SongCollection.h"

using namespace std;

SongData::SongData()
{
}

void SongData::importSongs()
{
	ifstream file;
	file.open("data.csv");
	string line;

	getline(file, line); // gets rid of first line of csv

	while (getline(file, line)) {
		stringstream s (line);
		string temp;

		getline(s, temp, ',');
		try {
			double valence = stod(temp);
		}
		catch (std::exception& e) {
			cout << e.what() << endl;
		}

		getline(s, temp, ',');
		try {
			int year = stoi(temp);
		}
		catch (std::exception& e) {
			cout << e.what() << endl;
		}
		
		getline(s, temp, ',');
		try {
			double acoustic = stod(temp);
		}
		catch (std::exception& e) {
			cout << e.what() << endl;
		}

	

	}

}

