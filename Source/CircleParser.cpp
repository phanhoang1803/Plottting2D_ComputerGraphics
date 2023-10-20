#include "CircleParser.h"
#include "Circle.h"
#include "Utils.h"

Object* CircleParser::parse(string org) {
	// 2 XT YT R
	vector<string> tokens = Utils::String::split(org, " ");
	float XT = stof(tokens[0]);
	float YT = stof(tokens[1]);
	float R = stof(tokens[2]);

	return new Circle(XT, YT, R);
}