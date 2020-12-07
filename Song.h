#pragma once
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;


class Song
{
private:
	double valence;
	int year;
	double acoustic;
	vector<string> artists; // there may be multiple artists per song
	double dance;
	int duration; // in milliseconds
	double energy;
	int exp; // explicit, 0 or 1
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
	double difference;

public:
	Song(); // default constructor of a song object
	Song(double valence, int year, double acoustic, vector<string> artists, double dance, int duration, double energy, int exp, string id, double instrumental, int key, double liveness, double loudness, int mode, string name, int popularity, int release_year, double speech, double tempo);
	double getAttribute(string attribute); // returns the specified song attribute
	vector<string> getArtists(); // returns the vector of artists
	string getName(); // returns name of song
	void setDifference(double difference); // sets difference value of song; based on statistics calculations
	
};