#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class Song
{
private:
	double valence;
	int year;
	double acoustic;
	vector<string> artists;
	double dance;
	int duration; // in milliseconds
	double energy;
	bool exp; // explicit, 0 or 1
	string id;
	double instrumental;
	int key;
	double liveness;
	double loudness;
	int mode;
	string name;
	int popularity;
	int release_year;
	double speech;
	double tempo;

public:
	Song();
	Song(double valence, int year, double acoustic, vector<string> artists, double dance, int duration, double energy, bool exp, string id, double instrumental, int key, double liveness, double loudness, int mode, string name, int popularity, int release_year, double speech, double tempo);
};