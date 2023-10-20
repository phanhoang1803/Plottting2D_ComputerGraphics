#include "ParabolParser.h"
#include "Parabol.h"
#include "Utils.h"

Object* ParabolParser::parse(string org) {
	// 4 XT YT P
	vector<string> tokens = Utils::String::split(org, " ");
	float XT = stof(tokens[0]);
	float YT = stof(tokens[1]);
	float P = stof(tokens[2]);

	return new Parabol(XT, YT, P);
}