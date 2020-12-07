/*
Title: Just Beat It
Authors: Edward Zhang, Arthur Liu, Taylor Frederick
Date: 12/7/2020
*/


#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <exception>
#include <math.h>
#include "SongCollection.h"

using namespace std;
using namespace std::chrono;

// Helper function to find the smallest standard deviation
void insert_ordered(vector<pair<string, double>>& vect, pair<string, double> temp_pair)
{
	auto iter = vect.begin();

	while (iter != vect.end() && iter->second < temp_pair.second)
	{
		iter++;
	}

	vect.insert(iter, temp_pair);
}


// Helper function to find the songs with the smallest deviation from the mean of the inputted songs
void insert_ordered(vector<pair<double, Song>>& vect, pair<double, Song> temp_pair)
{
	auto iter = vect.begin();

	while (iter != vect.end() && iter->first < temp_pair.first)
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


	//==================== Getting User Input ====================//
	vector<Song> user_input;
	int i;
	unsigned int j;
	int count = 0;
	string name;
	string temp;
	bool found = false;

	cout << "Number of songs being inputted: ";
	getline(cin, temp);

	i = stoi(temp);
	

	//==================== Finding User Input Songs ====================//
	while (count < i)
	{
		cout << "Please enter song name: ";
		getline(cin, name);
		cout << "Would you like to filter by artist (Y/N): ";
		
		string art;
		getline(cin, art);


		if (art == "N" || art == "n")
		{
			cout << "Finding song..." << endl;
			cout << "Type \"E\" to exit the current search at anytime." << endl;

			j = 0;
			found = false;


			while (found == false && j < songs.songs.size())
			{
				// Checks with user to ensure correct song has been found
				if (songs.songs[j].getName().find(name) != -1)
				{
					cout << endl << "Is this the correct song? (Y/N)" << endl;

					cout << songs.songs[j].getName() << ", " << songs.songs[j].getArtists()[0];
					if (songs.songs[j].getArtists().size() > 1)
						cout << ", " << songs.songs[j].getArtists()[1] << "..." << endl;
					else
						cout << endl;

					string response;
					getline(cin, response);

					if (response == "Y" || response == "y")
					{
						user_input.push_back(songs.songs[j]);
						found = true;
						break;
					}

					else if (response == "E" || response == "e") // option to break out of search loop
					{
						cout << "Exiting current search..." << endl;
						break;
					}

					else if (response == "N" || response == "n")
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
		}

		// uses artist as an additional comparison to find songs
		else if (art == "Y" || art == "y")
		{
			cout << "Please enter artist name: ";
			getline(cin, art);

			cout << "Finding song..." << endl;
			cout << "Type \"E\" to exit the current search at anytime." << endl;

			j = 0;
			found = false;


			while (found == false && j < songs.songs.size())
			{
				// Checks with user to ensure correct song has been found
				if (songs.songs[j].getName().find(name) != -1)
				{
					bool art_found = false;
					for (unsigned int k = 0; k < songs.songs[j].getArtists().size(); k++)
					{
						if (songs.songs[j].getArtists()[k].find(art) != -1)
						{
							art_found = true;
							break;
						}
					}


					if (art_found)
					{
						cout << endl << "Is this the correct song? (Y/N)" << endl;

						cout << songs.songs[j].getName() << ", " << songs.songs[j].getArtists()[0];
						if (songs.songs[j].getArtists().size() > 1)
							cout << ", " << songs.songs[j].getArtists()[1] << "..." << endl;
						else
							cout << endl;

						string response;
						getline(cin, response);

						if (response == "Y" || response == "y")
						{
							user_input.push_back(songs.songs[j]);
							found = true;
							break;
						}

						else if (response == "E" || response == "e")
						{
							cout << "Exiting current search..." << endl;
							break;
						}

						else if (response == "N" || response == "n")
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
				}

				j++;
			}
		}
		

		// The song was succesfully found ... add it to the vector
		if (found)
		{
			cout << endl <<  "Succesfully found song." << endl;
			cout << user_input[count].getName() << ", " << user_input[count].getArtists()[0] << endl << endl;
			count++;
		}
		// song was not successfully found :(
		else
		{
			cout << "Could not find song with name \"" << name << ".\" Please ensure that you entered the name properly" << endl;
		}
	}
	vector<pair<double, double>> song_statistics;

	double acousticness = 0;
	double dance = 0;
	double energy = 0;
	double liveness = 0;
	double loudness = 0;
	double speech = 0;
	double tempo = 0;
	double valence = 0;
	
	//==================== Calculating Means ====================//
	for (unsigned int i = 0; i < user_input.size(); i++)
	{
		acousticness += user_input[i].getAttribute("acoustic");
		dance += user_input[i].getAttribute("dance");
		energy += user_input[i].getAttribute("energy");
		liveness += user_input[i].getAttribute("liveness");
		loudness += user_input[i].getAttribute("loudness");
		speech += user_input[i].getAttribute("speech");
		tempo += user_input[i].getAttribute("tempo");
		valence += user_input[i].getAttribute("valence");
	}

	double m_acousticness = acousticness / user_input.size();
	double m_dance = dance / user_input.size();
	double m_energy = energy / user_input.size();
	double m_liveness = liveness / user_input.size();
	double m_loudness = loudness / user_input.size();
	double m_speech = speech / user_input.size();
	double m_tempo = tempo / user_input.size();
	double m_valence = valence / user_input.size();

	//==================== Calculating Standard Deviations ====================//
	double d_acousticness = 0;
	double d_dance = 0;
	double d_energy = 0;
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
		d_liveness += pow(user_input[i].getAttribute("liveness") - m_liveness, 2);
		d_loudness += pow(user_input[i].getAttribute("loudness") - m_loudness, 2);
		d_speech += pow(user_input[i].getAttribute("speech") - m_speech, 2);
		d_tempo += pow(user_input[i].getAttribute("tempo") - m_tempo, 2);
		d_valence += pow(user_input[i].getAttribute("valence") - m_valence, 2);
	}

	double s_acousticness = pow(d_acousticness / user_input.size(), .5);
	double s_dance = pow(d_dance / user_input.size(), .5);
	double s_energy = pow(d_energy / user_input.size(), .5);
	double s_liveness = pow(d_liveness / user_input.size(), .5);
	double s_loudness = pow(d_loudness / user_input.size(), .5);
	double s_speech = pow(d_speech / user_input.size(), .5);
	double s_tempo = pow(d_tempo / user_input.size(), .5);
	double s_valence = pow(d_valence / user_input.size(), .5);
	//==================== End Calculations ====================//


	// Sorting the standard deviations so the lowest is at the front of the vector
	vector<pair<string, double>> sorted_vect;
	insert_ordered(sorted_vect, make_pair("Acoustic", s_acousticness));
	insert_ordered(sorted_vect, make_pair("Dance", s_dance));
	insert_ordered(sorted_vect, make_pair("Energy", s_energy));
	insert_ordered(sorted_vect, make_pair("Liveness", s_liveness));
	insert_ordered(sorted_vect, make_pair("Loudness", s_loudness));
	insert_ordered(sorted_vect, make_pair("Speech", s_speech));
	insert_ordered(sorted_vect, make_pair("Tempo", s_tempo));
	insert_ordered(sorted_vect, make_pair("Valence", s_valence));

	bool looping = true;
	int i1;
	string response;
	vector<string> choices;

	while (looping && sorted_vect.size() > 0)
	{
		std::cout << "Which values would you like to match by? (Recommended: " << sorted_vect[0].first << ")" << endl;
		std::cout << "Please type \"0\" when you are done selecting attributes." << endl;

		for (unsigned int i = 0; i < sorted_vect.size(); i++)
		{
			std::cout << i + 1 << ". " << sorted_vect[i].first << ": " << sorted_vect[i].second << endl;
		}

		std::cout << "Please enter the number of the option: ";

		std::getline(cin, response);
		bool inputFlag = false;

		// Ensuring the user has given a proper input
		while (!inputFlag) {
			try
			{
				i1 = stoi(response);

				if (i1 < 9 && i1>-1) {
					inputFlag = true;
				}
				else {
					std::cout << "Please enter a number 0-" << sorted_vect.size() << endl;
					std::getline(cin, response);
				}
			}
			catch (exception& e)
			{
				std::cout << "Please enter a valid number (0-" << sorted_vect.size() << ")" << endl;
				std::getline(cin, response);
			}
		}

		if (i1 == 0)
		{
			// breaks out of user input loop
			looping = false;
		}

		else
		{
			// pushes back chosen statistic
			choices.push_back(sorted_vect[i1 - 1].first);
			sorted_vect.erase(sorted_vect.begin() + i1 - 1);
		}

		cout << endl;
	}
	
	vector<pair<double, double>> statistics; // <mean, SD>

	for (unsigned int i = 0; i < choices.size(); i++)
	{
		if (choices[i] == "Acoustic") { statistics.push_back(make_pair(m_acousticness, s_acousticness)); }
		else if (choices[i] == "Dance") { statistics.push_back(make_pair(m_dance, s_dance)); }
		else if (choices[i] == "Energy") { statistics.push_back(make_pair(m_energy, s_energy)); }
		else if (choices[i] == "Liveness") { statistics.push_back(make_pair(m_liveness, s_liveness)); }
		else if (choices[i] == "Loudness") { statistics.push_back(make_pair(m_loudness, s_loudness)); }
		else if (choices[i] == "Speech") { statistics.push_back(make_pair(m_speech, s_speech)); }
		else if (choices[i] == "Tempo") { statistics.push_back(make_pair(m_tempo, s_tempo)); }
		else if (choices[i] == "Valence") { statistics.push_back(make_pair(m_valence, s_valence)); }
	}



	//==================== Begin FInding Recommended Songs ====================//
	cout << "Calculating the variations of every song...this may take a little while." << endl;
	auto start = high_resolution_clock::now();

	for (auto iter = songs.songs.begin(); iter != songs.songs.end(); iter++)
	{
		double temp = 0;
		bool removed = false;

		for (unsigned int i = 0; i < choices.size(); i++)
		{
			// If any of the statistics are out of bounds of one standard deviation, remove them from consideration
			if (iter->getAttribute(choices[i]) > statistics[i].first + 3 * statistics[i].second || iter->getAttribute(choices[i]) < statistics[i].first - 3 * statistics[i].second)
			{
				removed = true;
				break;
			}

			else
			{
				temp += abs(statistics[i].first - iter->getAttribute(choices[i]));
			}
		}

		if (!removed)
		{
			iter->setDifference(temp);
			// pushes back songs onto both recommended1 and recommended2 to compare runtime speeds of quick sort and heap sort
			songs.recommended1.push_back(*iter);
			songs.recommended2.push_back(*iter);
		}
	}

	auto stop = high_resolution_clock::now();
	auto dur = duration_cast<milliseconds>(stop - start);
	cout << "Calculating differences took " << dur.count() << " milliseconds." << endl;



	//==================== Sorting Section ====================//
	cout << endl << "Performing Sorting Algorithms" << endl;
	cout << "Heap Sort" << endl;
	cout << "Sorting..." << endl;
	
	// Timing the heap sort
	auto start1 = high_resolution_clock::now();
	songs.heapSort("Difference");
	auto stop1 = high_resolution_clock::now();
	auto dur1 = duration_cast<milliseconds>(stop1 - start1);
	cout << "The HeapSort took: " << dur1.count() << " milliseconds" << endl;


	cout << endl << "Quick Sort" << endl;
	cout << "Sorting..." << endl;
	// Timing the quick sort
	auto start2 = high_resolution_clock::now();
	songs.quickSort("Difference", 0, songs.recommended2.size() - 1);
	auto stop2 = high_resolution_clock::now();
	auto dur2 = duration_cast<milliseconds>(stop2 - start2);
	cout << "The QuickSort took: " << dur2.count() << " milliseconds" << endl;


	//==================== Printing Recommended Songs ====================//
	cout << endl << "Finding recommended songs..." << endl << endl;

	// Caps the amount of recommended songs to the user to only recommended most relevant songs
	int recommendCap = 0;
	if (songs.recommended1.size() == 0) {
		cout << "Sorry, we could not find any songs to recommend." << endl;
		return 0;
	}

	else if (songs.recommended1.size() > 50) {
		recommendCap = 50;
	}
	else
		recommendCap = songs.recommended1.size();

	cout << endl << "How many songs would you like to be recommended? (Max: " << recommendCap << ")" << endl;;
	getline(cin, response);
	int songCount=0;

	// Ensuring the user has given a proper input
	bool inputFlag = false;
	while (!inputFlag) {
		try
		{
			songCount = stoi(response);
			if (count <= recommendCap && count>0)
				inputFlag = true;
			else {
				cout << "Please enter a valid response (1-" << recommendCap << ")" << endl;
				getline(cin, response);
			}
		}
		catch (exception& e)
		{
			cout << "Please enter a valid response (1-" << recommendCap << ")" << endl;
			getline(cin, response);
		}
	}
	
	

	// Printing out the recommended songs
	cout << "\nYour top " << songCount << " most relevant songs are: \n" << endl;
	for (int i = 0; i < songCount; i++)
	{
		cout << i + 1 << ". " << songs.recommended1[i].getName() << " | ";

		for (unsigned int j = 0; j < songs.recommended1[i].getArtists().size(); j++)
		{
			if (j != songs.recommended1[i].getArtists().size() && j != 0)
			{
				cout << ", ";
			}
			cout << songs.recommended1[i].getArtists()[j];
		}

		cout << endl;
	}

	return 0;
}