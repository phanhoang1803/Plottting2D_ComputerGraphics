#include "Circle.h"
#include <sstream>
#include "Utils.h"


Circle::Circle() {
	_XT = 0;
	_YT = 0;
	_R = 0;
};
Circle::Circle(float XT, float YT, float R) {
	_XT = XT;
	_YT = YT;
	_R = R;
}
string Circle::toString() {
	stringstream builder;

	builder << "Circle I(" << _XT << ", " << _YT << "), R = " << _R << "\n";

	string res = builder.str();
	return res;
}

void Circle::plotShape() {
	if (_R <= 0)
		return;

    float x = 0;
    float y = _R;

    Utils::GLUtils::setPixel(_XT, _YT + _R);
    Utils::GLUtils::setPixel(_XT, _YT - _R);
    Utils::GLUtils::setPixel(_XT + _R, _YT);
    Utils::GLUtils::setPixel(_XT - _R, _YT);

    float p = 5/4 - _R;                 // Set the initial value of p
    while (x <= y) {
        if (p < 0)                      // Case p < 0: yk+1 = yk
            p += 2 * (x + 1) + 1;
        else {
            p += 2 * (x - y) + 5;
            y -= 1;                     // Case p >= 0: yk+1 = yk - 1
        }
        x++;

        Utils::GLUtils::setPixel(_XT + x, _YT + y);
        Utils::GLUtils::setPixel(_XT + x, _YT - y);
        Utils::GLUtils::setPixel(_XT - x, _YT + y);
        Utils::GLUtils::setPixel(_XT - x, _YT - y);
        Utils::GLUtils::setPixel(_XT + y, _YT + x);
        Utils::GLUtils::setPixel(_XT + y, _YT - x);
        Utils::GLUtils::setPixel(_XT - y, _YT + x);
        Utils::GLUtils::setPixel(_XT - y, _YT - x);
    }
    glFlush();
}
