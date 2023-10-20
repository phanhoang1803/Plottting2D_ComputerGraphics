#include "ParserFactory.h"
#include "CircleParser.h"
#include "DDALineParser.h"
#include "BreLineParser.h"
#include "ParabolParser.h"
#include "HyperbolParser.h"
#include "ElipParser.h"
#include <map>

IParsable* ParserFactory::create(string type) {
	map<string, IParsable*> container = {
		{"0", new DDALineParser()},
		{"1", new BreLineParser()},
		{"2", new CircleParser()},
		{"3", new ElipParser()},
		{"4", new ParabolParser()},
		{"5", new HyperbolParser()},
	};

	IParsable* parser = container[type];

	return parser;
}

//string ParserFactory::toString() {
//	return "";
//};