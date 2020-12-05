#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "SongCollection.h"

using namespace std;



int main()
{
	SongCollection songs;
	songs.importSongs();

	// songs.heapSort("Loudness");
	// songs.testPrint();

	vector<Song> user_input;

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
	for (int i = 0; i < user_input.size(); i++)
	{
		acousticness += user_input[i].getAcoustic();
		dance = user_input[i].getDance();
		energy += user_input[i].getEnergy();
		instrumental += user_input[i].getInstrumental();
		liveness += user_input[i].getLiveness();
		loudness += user_input[i].getLoudness();
		speech += user_input[i].getSpeech();
		tempo += user_input[i].getTempo();
		valence += user_input[i].getValence();
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

	for (int i = 0; i < user_input.size(); i++)
	{
		d_acousticness += pow(user_input[i].getAcoustic() - m_acousticness, 2);
		d_dance += pow(user_input[i].getDance() - m_dance, 2);
		d_energy += pow(user_input[i].getEnergy() - m_energy, 2);
		d_instrumental += pow(user_input[i].getInstrumental() - m_instrumental, 2);
		d_liveness += pow(user_input[i].getLiveness() - m_liveness, 2);
		d_loudness += pow(user_input[i].getLoudness() - m_loudness, 2);
		d_speech += pow(user_input[i].getSpeech() - m_speech, 2);
		d_tempo += pow(user_input[i].getTempo() - m_tempo, 2);
		d_valence += pow(user_input[i].getValence() - m_valence, 2);
	}

	double s_acousticness = pow(d_acousticness / user_input.size(), .5);
	double s_dance = pow(d_energy / user_input.size(), .5);
	double s_energy = pow(d_energy / user_input.size(), .5);
	double s_instrumental = pow(d_instrumental / user_input.size(), .5);
	double s_liveness = pow(d_liveness / user_input.size(), .5);
	double s_loudness = pow(d_loudness / user_input.size(), .5);
	double s_speech = pow(d_speech / user_input.size(), .5);
	double s_tempo = pow(d_tempo / user_input.size(), .5);
	double s_valence = pow(d_valence / user_input.size(), .5);
	//========== End Calculations ==========//


	return 0;
}