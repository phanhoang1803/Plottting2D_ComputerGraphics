#include "BreLine.h"
#include <sstream>
#include "Utils.h"

BreLine::BreLine() {
    _X1 = 0;
    _Y1 = 0;
    _X2 = 0;
    _Y2 = 0;
}

BreLine::BreLine(float X1, float Y1, float X2, float Y2) {
    _X1 = X1;
    _Y1 = Y1;
    _X2 = X2;
    _Y2 = Y2;
}

string BreLine::toString() {
    stringstream builder;

    builder << "BreLine: A(" << _X1 << ", " << _Y1 << ") - B(" << _X2 << ", " << _Y2 << ")\n";

    string res = builder.str();
    return res;
}

float sign(float n) {
    if (n > 0)
        return 1;
    if (n < 0)
        return -1;
    return 0;
}

void BreLine::plotShape() {
    // Source: https://www.uobabylon.edu.iq/eprints/publication_2_22893_6215.pdf
    if (_X1 > _X2) {
        swap(_X1, _X2);
        swap(_Y1, _Y2);
    }

    float x = _X1, y = _Y1;
    float dx = abs(_X2 - _X1), dy = abs(_Y2 - _Y1);
    float s1 = sign(_X2 - _X1), s2 = sign(_Y2 - _Y1);
    bool interchange;       //  interchange the roles of the xand y directions
                            //  interchange = true if |m| > 1, it mean, x = f(y), y += 1 or y -= 1 for each step.

    if (dy > dx) {          // m > 1
        swap(dx, dy);
        interchange = true;
    }
    else
        interchange = false;

    float p = 2 * dy - dx;          // The initial value of p
    float c1 = 2 * dy;              // pi+1 = pi + c1 when pi < 0
    float c2 = 2 * dy - 2 * dx;     // pi+1 = pi + c2 when pi >=0

    Utils::GLUtils::setPixel(x, y);
    for (float i = 0; i < dx; i++) {
        if (p < 0) {            
            if (interchange)        // Case: |m| > 1
                y += s2;            // if m > 1, y += 1 each step (y2 > y1 -> s2 = 1)
                                    // if m < -1, y -= 1 each step (y2 < y1 -> s2 = -1) 
            
            else                    // Case: |m| <= 1
                x += s1;            // we set _X1 < _X2, so x always increase by 1 (s1 = 1)
            p += c1;
        }
        else {                      // In case p >= 0, we always increase (or decrease) x (or y) by  
            y += s2;            
            x += s1;
            p += c2;
        }
        Utils::GLUtils::setPixel(x, y);
    }

    glFlush(); // Force the rendering
}
