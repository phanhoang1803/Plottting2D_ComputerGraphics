#include "Parabol.h"
#include <sstream>
#include "Utils.h"

#define UPPER_LIMIT 2000

Parabol::Parabol() {
	_XT = 0;
	_YT = 0;
	_P = 0;
};
Parabol::Parabol(float XT, float YT, float P) {
	_XT = XT;
	_YT = YT;
	_P = P;
}
string Parabol::toString() {
	stringstream builder;

	builder << "Parabol I(" << _XT << ", " << _YT << "), P = " << _P << "\n";

	string res = builder.str();
	return res;
}

void Parabol::plotShape() {
	if (_P == 0)
		return;

	float sign = _P > 0 ? 1 : -1;
	float f = abs(_P);

	float p1, p2, x, y, dx, dy;
	x = 0, y = 0;

	dx = 2 * x;
	dy = -4 * f;
	
	// Part 1
	p1 = 1 - 2 * f;
	while (dx < abs(dy)) {
		Utils::GLUtils::setPixel(_XT + x, _YT + sign *y);
		Utils::GLUtils::setPixel(_XT - x, _YT + sign * y);

		x++;
		dx += 2;
		if (p1 < 0)
			p1 += dx + 1;
		else {
			y += 1;
			p1 += dx + 1 + dy;
		}
	}
	glFlush();

	// Part 2
	p2 = (x + 0.5) * (x + 0.5) - 4 * f * (y + 1);
	while (y < UPPER_LIMIT) { // The parabola has no upper limit, so we set an upper limit to stop the program
		Utils::GLUtils::setPixel(_XT + x, _YT + sign * y);
		Utils::GLUtils::setPixel(_XT - x, _YT + sign * y);
	
		y += 1;
		if (p2 > 0)
			p2 += dy;
		else {
			x++;
			dx += 2;
			p2 += dx + dy;
		}
	}
	glFlush();
};
