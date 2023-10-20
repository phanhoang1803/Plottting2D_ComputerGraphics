#pragma once
#include "IParsable.h"

class ElipParser :public IParsable
{
private:

public:
	Object* parse(string org);
	string toString() { return ""; };
};

