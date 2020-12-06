#include "Song.h"

Song::Song() {
	valence = 0;
	year = 0;
	acoustic = 0;
	artists = {};
	dance = 0;
	duration = 0;
	energy = 0;
	exp = 0;
	id = "";
	instrumental = 0;
	key = 0;
	liveness = 0;
	loudness = 0;
	mode = 0;
	name = "";
	popularity = 0;
	release_year = 0;
	speech = 0;
	tempo = 0;
}


Song::Song(double valence, int year, double acoustic, vector<string> artists, double dance, int duration, double energy, int exp, string id, double instrumental, int key, double liveness, double loudness, int mode, string name, int popularity, int release_year, double speech, double tempo)
{
	this->valence = valence;
	this->year = year;
	this->acoustic = acoustic;
	this->artists = artists;
	this->dance = dance;
	this->duration = duration;
	this->energy = energy;
	this->exp = exp;
	this->id = id;
	this->instrumental = instrumental;
	this->key = key;
	this->liveness = liveness;
	this->loudness = loudness;
	this->mode = mode;
	this->name = name;
	this->popularity = popularity;
	this->release_year = release_year;
	this->speech = speech;
	this->tempo = tempo;
}

double Song::getAttribute(string attribute)
{
	if (attribute == "Acoustic" || attribute == "acoustic")
	{
		return acoustic;
	}

	else if (attribute == "Dance" || attribute == "dance")
	{
		return dance;
	}

	else if (attribute == "Energy" || attribute == "energy")
	{
		return energy;
	}

	else if (attribute == "Instrumental" || attribute == "instrumental")
	{
		return instrumental;
	}

	else if (attribute == "Liveness" || attribute == "liveness")
	{
		return liveness;
	}

	else if (attribute == "Loudness" || attribute == "loudness")
	{
		return loudness;
	}

	else if (attribute == "Speech" || attribute == "speech")
	{
		return speech;
	}

	else if (attribute == "Valence" || attribute == "valence")
	{
		return valence;
	}

	else if (attribute == "Tempo" || attribute == "tempo")
	{
		return tempo;
	}
	else {
		std::cout << "Improper Attribute was referenced!" << std::endl;
		return 0;
	}
}



string Song::getName()
{
	return name;
}