#include "ElipParser.h"
#include "Elip.h"
#include "Utils.h"

Object* ElipParser::parse(string org) {
	// 3 XT YT A B
	vector<string> tokens = Utils::String::split(org, " ");
	float XT = stof(tokens[0]);
	float YT = stof(tokens[1]);
	float A = stof(tokens[2]);
	float B = stof(tokens[3]);
	return new Elip(XT, YT, A, B);
}