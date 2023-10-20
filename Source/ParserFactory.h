#pragma once
#include "Object.h"
#include "IParsable.h"

class ParserFactory :public Object
{
private:

public:
	IParsable* create(string type);
	string toString() { return ""; };
};

