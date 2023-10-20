#pragma once
#include "IParsable.h"

class DDALineParser :public IParsable
{
private:

public:
	Object* parse(string org);
	string toString() { return ""; };
};

