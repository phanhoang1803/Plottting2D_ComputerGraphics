#pragma once
#include "IParsable.h"

class BreLineParser :public IParsable
{
private:

public:
	Object* parse(string org);
	string toString() { return ""; };
};

