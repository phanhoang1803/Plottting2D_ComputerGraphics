#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <GL/glut.h>

using namespace std;

namespace Utils {
    class String {
    public:
        static vector<string> split(string haystack, string needle);
    };

    class GLUtils {
    public:
        static void myinit(void);
        static void setPixel(GLint x, GLint y);
        static void initWindow(int argc, char** argv, const char* windowName);
    };
}
