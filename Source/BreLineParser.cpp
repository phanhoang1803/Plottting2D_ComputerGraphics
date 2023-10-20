#include "BreLineParser.h"
#include "BreLine.h"
#include "Utils.h"

Object* BreLineParser::parse(string org) {
	// 1 X1 Y1 X2 Y2
	vector<string> tokens = Utils::String::split(org, " ");
	float X1 = stof(tokens[0]);
	float Y1 = stof(tokens[1]);
	float X2 = stof(tokens[2]);
	float Y2 = stof(tokens[3]);

	return new BreLine(X1, Y1, X2, Y2);
}