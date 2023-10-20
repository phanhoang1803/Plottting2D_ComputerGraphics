#include "DDALine.h"
#include <sstream>
#include "Utils.h"

DDALine::DDALine() {
    _X1 = 0;
    _Y1 = 0;
    _X2 = 0;
    _Y2 = 0;
}

DDALine::DDALine(float X1, float Y1, float X2, float Y2) {
    _X1 = X1;
    _Y1 = Y1;
    _X2 = X2;
    _Y2 = Y2;
}

string DDALine::toString() {
    stringstream builder;

    builder << "DDALine: A(" << _X1 << ", " << _Y1 << ") - B(" << _X2 << ", " << _Y2 << ")\n";

    string res = builder.str();
    return res;
}

void DDALine::plotShape() {
    float Dx = _X2 - _X1, Dy = _Y2 - _Y1;
    
    float steps = max(abs(Dx), abs(Dy));
    
    //float m = Dy / Dx;
    double x = _X1, y = _Y1;

    double x_inc = Dx * 1.0 / steps;
    double y_inc = Dy * 1.0 / steps;

    for (float i = 0; i < steps; i++) {
        Utils::GLUtils::setPixel(round(x), round(y));
        x += x_inc;
        y += y_inc;
    }

    glFlush();
}