#include "Utils.h"

vector<string> Utils::String::split(string haystack, string needle) {
	vector<string> res;

	int start, end = -1 * needle.size();
	do {
		start = end + needle.size();
		end = haystack.find(needle, start);
		res.push_back(haystack.substr(start, end - start));
	} while (end != -1);

	return res;
}

//void Utils::GLUtils::myinit(void)
//{
//    glClearColor(1.0, 1.0, 1.0, 0.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
//}

void Utils::GLUtils::setPixel(GLint x, GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

//void Utils::GLUtils::initWindow(int argc, char** argv, const char* windowName) {
//    glutInit(&argc, argv);
//    glutInitWindowSize(640, 480);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow(windowName);
//    myinit();
//}