#include "Hyperbol.h"
#include <sstream>
#include "Utils.h"

#define MAX_LEN 2000

Hyperbol::Hyperbol() {
	_XT = 0;
	_YT = 0;
	_A = 0;
	_B = 0;
};
Hyperbol::Hyperbol(float XT, float YT, float A, float B) {
	_XT = XT;
	_YT = YT;
	_A = A;
	_B = B;
}
string Hyperbol::toString() {
	stringstream builder;

	builder << "Hyperbol: I(" << _XT << ", " << _YT << "), a = " << _A << ", b = " << _B << "\n";

	string res = builder.str();
	return res;
}

void Hyperbol::plotShape() {
	if (_A == 0 || _B == 0)
		return;
	
	float a = abs(_A) / 2;
	float b = abs(_B) / 2;
	
	float upper_bound = b >= a ? MAX_LEN : INFINITY;
	
	float a2 = a * a;
	float b2 = b * b;
	float p1, p2, x, y, dx, dy;
	x = a;
	y = 0;
	dx = 2 * b2 * x;
	dy = -2 * a2 * y;

	// Region 1: m > 1
	p1 = a * b2 - a2 + 0.25 * b2;
	// When b >= a, abs(dy) is always smaller than abs(dx), so there will be no stopping point. 
	// Therefore set a limit on the value of y.
	while (abs(dy) < abs(dx) && y < upper_bound) {	// dx < dy
		Utils::GLUtils::setPixel(_XT + x, _YT + y);
		Utils::GLUtils::setPixel(_XT + x, _YT - y);
		Utils::GLUtils::setPixel(_XT - x, _YT + y);
		Utils::GLUtils::setPixel(_XT - x, _YT - y);

		y++;
		dy += -2 * a2;
		if (p1 > 0)
			p1 += dy - a2;
		else {
			x++;
			dx += 2 * b2;
			p1 += dx + dy - a2;
		}
	}
	glFlush();

	// Region 2: m < 1
	p2 = b2 * (x + 1) * (x + 1) - a2 * (y + 0.5) * (y + 0.5) - a2 * b2;
	while (x < MAX_LEN + a) {			// because the hyperbola is not limited to two directions along the x axis, 
														// so limit the value of x so that the program can stop
		Utils::GLUtils::setPixel(_XT + x, _YT + y);
		Utils::GLUtils::setPixel(_XT + x, _YT - y);
		Utils::GLUtils::setPixel(_XT - x, _YT + y);
		Utils::GLUtils::setPixel(_XT - x, _YT - y);

		x++;
		dx += 2 * b2;
		if (p1 < 0)
			p1 += dx + b2;
		else {
			y++;
			dy += -2 * a2;
			p1 += dx + b2 + dy;
		}
	}
	glFlush();

};
