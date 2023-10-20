#include "HyperbolParser.h"
#include "Hyperbol.h"
#include "Utils.h"

Object* HyperbolParser::parse(string org) {
	// 5 XT YT A B
	vector<string> tokens = Utils::String::split(org, " ");
	float XT = stof(tokens[0]);
	float YT = stof(tokens[1]);
	float A = stof(tokens[2]);
	float B = stof(tokens[3]);
	return new Hyperbol(XT, YT, A, B);
}