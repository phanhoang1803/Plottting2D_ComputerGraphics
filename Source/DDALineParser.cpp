#include "DDALineParser.h"
#include "DDALine.h"
#include "Utils.h"

Object* DDALineParser::parse(string org) {
	// 0 X1 Y1 X2 Y2
	vector<string> tokens = Utils::String::split(org, " ");
	float X1 = stof(tokens[0]);
	float Y1 = stof(tokens[1]);
	float X2 = stof(tokens[2]);
	float Y2 = stof(tokens[3]);

	return new DDALine(X1, Y1, X2, Y2);
}