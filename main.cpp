#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "SongCollection.h"

using namespace std;

void insert_ordered(vector<pair<string, double>>& vect, pair<string, double> temp_pair)
{
	auto iter = vect.begin();

	while (iter != vect.end() && iter->second < temp_pair.second)
	{
		iter++;
	}

	vect.insert(iter, temp_pair);
}

int main()
{
	cout << "Welcome to \"Just Beat It\"" << endl;
	cout << "Reading in song information..." << endl << endl;
	SongCollection songs;
	songs.importSongs();

	//========== Getting User Input ==========//
	vector<Song> user_input;
	int i;
	int j;
	int count = 0;
	string name;
	string temp;
	bool found = false;

	cout << "Number of songs being inputted: ";
	getline(cin, temp);

	i = stoi(temp);

	while (count < i)
	{
		cout << "Please enter song name: ";
		getline(cin, name);
		cout << "Finding song..." << endl;

		j = 0;
		found = false;


		while (found == false && j < songs.getSongs().size())
		{
			if (songs.getSongs()[j].getName().find(name) != -1)
			{
				cout << endl << "Is this the correct song? (Y/N)" << endl;
				cout << songs.getSongs()[j].getName() << ", " << songs.getSongs()[j].getArtists()[0] << endl;

				string response;
				getline(cin, response);

				if (response == "Y")
				{
					user_input.push_back(songs.getSongs()[j]);
					found = true;
					break;
				}

				else if (response == "N")
				{
					cout << "Continuing search..." << endl;
				}

				else
				{
					cout << "Next time please respond with either 'Y' or 'N'" << endl;
					cout << "Continuing previous search" << endl;
					j--;
				}
			}

			j++;

		}

		if (found)
		{
			cout << endl <<  "Succesfully found song." << endl;
			cout << user_input[count].getName() << ", " << user_input[count].getArtists()[0] << endl << endl;
			count++;
		}

		else
		{
			cout << "Could not find song with name \"" << name << ".\" Please ensure that you entered the name properly" << endl;
		}
	}
	vector<pair<double, double>> song_statistics;

	double acousticness = 0;
	double dance = 0;
	double energy = 0;
	double instrumental = 0;
	double liveness = 0;
	double loudness = 0;
	double speech = 0;
	double tempo = 0;
	double valence = 0;
	
	//========== Calculating Means ==========//
	for (unsigned int i = 0; i < user_input.size(); i++)
	{
		acousticness += user_input[i].getAttribute("acoustic");
		dance = user_input[i].getAttribute("dance");
		energy += user_input[i].getAttribute("energy");
		instrumental += user_input[i].getAttribute("instrumental");
		liveness += user_input[i].getAttribute("liveness");
		loudness += user_input[i].getAttribute("loudness");
		speech += user_input[i].getAttribute("speech");
		tempo += user_input[i].getAttribute("tempo");
		valence += user_input[i].getAttribute("valence");
	}

	double m_acousticness = acousticness / user_input.size();
	double m_dance = dance / user_input.size();
	double m_energy = energy / user_input.size();
	double m_instrumental = instrumental / user_input.size();
	double m_liveness = liveness / user_input.size();
	double m_loudness = loudness / user_input.size();
	double m_speech = speech / user_input.size();
	double m_tempo = tempo / user_input.size();
	double m_valence = valence / user_input.size();

	//========== Calculating Standard Deviations ==========//
	double d_acousticness = 0;
	double d_dance = 0;
	double d_energy = 0;
	double d_instrumental = 0;
	double d_liveness = 0;
	double d_loudness = 0;
	double d_speech = 0;
	double d_tempo = 0;
	double d_valence = 0;

	for (unsigned int i = 0; i < user_input.size(); i++)
	{
		d_acousticness += pow(user_input[i].getAttribute("acoustic") - m_acousticness, 2);
		d_dance += pow(user_input[i].getAttribute("dance") - m_dance, 2);
		d_energy += pow(user_input[i].getAttribute("energy") - m_energy, 2);
		d_instrumental += pow(user_input[i].getAttribute("instrumental") - m_instrumental, 2);
		d_liveness += pow(user_input[i].getAttribute("liveness") - m_liveness, 2);
		d_loudness += pow(user_input[i].getAttribute("loudness") - m_loudness, 2);
		d_speech += pow(user_input[i].getAttribute("speech") - m_speech, 2);
		d_tempo += pow(user_input[i].getAttribute("tempo") - m_tempo, 2);
		d_valence += pow(user_input[i].getAttribute("valence") - m_valence, 2);
	}

	double s_acousticness = pow(d_acousticness / user_input.size(), .5);
	double s_dance = pow(d_dance / user_input.size(), .5);
	double s_energy = pow(d_energy / user_input.size(), .5);
	double s_instrumental = pow(d_instrumental / user_input.size(), .5);
	double s_liveness = pow(d_liveness / user_input.size(), .5);
	double s_loudness = pow(d_loudness / user_input.size(), .5);
	double s_speech = pow(d_speech / user_input.size(), .5);
	double s_tempo = pow(d_tempo / user_input.size(), .5);
	double s_valence = pow(d_valence / user_input.size(), .5);
	//========== End Calculations ==========//

	vector<pair<string, double>> sorted_vect;
	insert_ordered(sorted_vect, make_pair("Acoustic", s_acousticness));
	insert_ordered(sorted_vect, make_pair("Dance", s_dance));
	insert_ordered(sorted_vect, make_pair("Energy", s_energy));
	insert_ordered(sorted_vect, make_pair("Instrumental", s_instrumental));
	insert_ordered(sorted_vect, make_pair("Liveness", s_liveness));
	insert_ordered(sorted_vect, make_pair("Loudness", s_loudness));
	insert_ordered(sorted_vect, make_pair("Speech", s_speech));
	insert_ordered(sorted_vect, make_pair("Tempo", s_tempo));
	insert_ordered(sorted_vect, make_pair("Valence", s_valence));

	cout << "Which value would you like to match by? (Recommended: " << sorted_vect[0].first << ")" << endl;
	
	for (int i = 0; i < sorted_vect.size(); i++)
	{
		cout << i + 1 << ". " << sorted_vect[i].first << ": " << sorted_vect[i].second << endl;
	}

	cout << "Please enter the number of the option.";

	string response;
	getline(cin, response);
	int i1 = stoi(response);

	cout << endl << "Which sorting algorithm would you like to use?" << endl;
	cout << "1. Heap Sort" << endl;
	cout << "2. Quick Sort" << endl;

	getline(cin, response);
	int i2 = stoi(response);

	if (i2 == 1)
	{
		songs.heapSort(sorted_vect[i1 - 1].first);
	}

	else if (i2 == 2)
	{
		songs.quickSort(sorted_vect[i1 - 1].first, 0, songs.getNumSongs() - 1);
	}

	return 0;
}