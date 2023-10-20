#include "Elip.h"
#include <sstream>
#include "Utils.h"
#include "Circle.h"

Elip::Elip() {
	_XT = 0;
	_YT = 0;
	_A = 0;
	_B = 0;
};
Elip::Elip(float XT, float YT, float A, float B) {
	_XT = XT;
	_YT = YT;
	_A = A;
	_B = B;
}
string Elip::toString() {
	stringstream builder;

	builder << "Elip: I(" << _XT << ", " << _YT << "), a = " << _A << ", b = " << _B << "\n";

	string res = builder.str();
	return res;
}

void Elip::plotShape() {
	if (_A <= 0 || _B <= 0)
		return;

	// Handle the case when A is equal to B (drawing a circle)
	if (_A == _B) {		
		Circle circle(_XT, _YT, _A);
		circle.plotShape();
		return;
	}

	// For non-circular ellipses
	float p1, p2, x, y, a2, b2, dx, dy;
	x = 0;
	y = _B;
	a2 = _A * _A;
	b2 = _B * _B;
	dx = 2 * b2 * x;
	dy = 2 * a2 * y;


	// Region 1: -1 < m < 0
	p1 = b2 - a2 * _B + 0.25 * a2;
	while (dx < dy) {				// dx < dy
		Utils::GLUtils::setPixel(_XT + x, _YT + y);
		Utils::GLUtils::setPixel(_XT + x, _YT - y);
		Utils::GLUtils::setPixel(_XT - x, _YT + y);
		Utils::GLUtils::setPixel(_XT - x, _YT - y);

		x++;
		dx += 2 * b2;
		if (p1 < 0)
			p1 += dx + b2;
		else {
			y--;
			dy -= 2 * a2;
			p1 += dx - dy + b2;
		}
	}
    glFlush();

	// Region 2: m < -1
	p2 = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;
	while (y >= 0) {
		Utils::GLUtils::setPixel(_XT + x, _YT + y);
		Utils::GLUtils::setPixel(_XT + x, _YT - y);
		Utils::GLUtils::setPixel(_XT - x, _YT + y);
		Utils::GLUtils::setPixel(_XT - x, _YT - y);

		y--;
		dy -= 2 * a2;
		if (p2 > 0)
			p2 += -dy + a2;
		else {
			x++;
			dx += 2 * b2;
			p2 += dx - dy + a2;
		}
	}
    glFlush();
};
