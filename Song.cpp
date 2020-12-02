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

Song::Song(double valence, int year, double acoustic, vector<string> artists, double dance, int duration, double energy, bool exp, string id, double instrumental, int key, double liveness, double loudness, int mode, string name, int popularity, int release_year, double speech, double tempo)
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