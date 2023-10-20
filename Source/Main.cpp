#include "ParserFactory.h"
#include "IParsable.h"
#include "IShape.h"
#include <vector>
#include "Utils.h"
#include <stdio.h>
#include <cstring>
#include <chrono>
#include <fstream>
#include <string>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

vector<IShape*> shapes;
vector<string> lines;       // Use for comparision
int currentShapeIndex = 0;

int readShapes() {
    string fileName;
    cout << "\nPlease enter the file name (.txt) containing information about your shapes (note that, if you choose comparison mode, please enter the file name containing the information of the line segments): ";
    cin >> ws;
    cin >> fileName;

    std::ifstream inputFile(fileName);
    std::string line;

    ParserFactory factory;      // Use to create parsers

    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            // Example: circle = "2 0 0 5"
            int splitPos = line.find_first_of(" ");
            string type = line.substr(0, splitPos);         // Get object type

            IParsable* parser = factory.create(type);       // "Circle"=> CircleParser

            string data = line.substr(splitPos + 1);    
            IShape* shape = (IShape*)parser->parse(data);   // "0 0 5" => Circle(XT = 0, YT = 0, R = 0)

            shapes.push_back(shape);
            lines.push_back(line);
        }
        inputFile.close();
    }
    else {
        std::cerr << "Error: Unable to open the file.\n" << std::endl;
        //exit(1); // Return an error code
        return 1;
    }

    return 0;
}

void displayShape() {
    // Set window title by the shape's name.
    glutSetWindowTitle(shapes[currentShapeIndex]->toString().c_str());
    glClear(GL_COLOR_BUFFER_BIT);

    cout << "\nShape " << currentShapeIndex << ": "<< shapes[currentShapeIndex]->toString();

    // Start timer
    auto start = std::chrono::high_resolution_clock::now();
    shapes[currentShapeIndex]->plotShape();     // Draw a shape at the currentShapeIndex position in the list
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "The time period for drawing the shape is: " << duration.count() << " (microseconds)" << endl;
    glFlush();
    glutSwapBuffers();          // Swap buffer to display the shape due to DOUBLE mode
}

// Callback for Enter event
void keyboardCallback(unsigned char key, int x, int y) {
    if (key == 13) {
        currentShapeIndex++;                // Move to the next shape
        if (currentShapeIndex >= shapes.size())
            currentShapeIndex = 0;          // Return to the first shape if the entire list has been drawn
        displayShape();                     // Draw shape
    }
}

void comparisonDisplay() {
    // Only compare lines
    vector<string> tokens = Utils::String::split(lines[currentShapeIndex], " ");
    if (tokens[0] != "0" && tokens[0] != "1")
        return;

    // My plot
    // Set window title by the shape's name.
    glutSetWindowTitle(shapes[currentShapeIndex]->toString().c_str());
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f); // Set color of pixels to red

    cout << "\nShape " << currentShapeIndex << ": " << shapes[currentShapeIndex]->toString();

    // Start timer
    auto start = std::chrono::high_resolution_clock::now();
    shapes[currentShapeIndex]->plotShape();     // Draw a shape at the currentShapeIndex position in the list
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "The time period of my function for drawing the shape is      : " << duration.count() << " (microseconds)" << endl;
    glFlush();

    // OpenGL's plot

    // 1 X1 Y1 X2 Y2
    float X1 = stof(tokens[1]);
    float Y1 = stof(tokens[2]);
    float X2 = stof(tokens[3]);
    float Y2 = stof(tokens[4]);
    
    glColor3f(0.0f, 0.0f, 1.0f); // Set color of pixels to blue
    start = std::chrono::high_resolution_clock::now();
    glBegin(GL_LINES); 
    glVertex2f(X1 + 10, Y1); // Endpoint (x1, y1)
    glVertex2f(X2 + 10, Y2); // Endpoint (x2, y2)
    glEnd(); 
    end = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "The time period of OpenGL's function for drawing the shape is: " << duration.count() << " (microseconds)" << endl;

    glFlush();   

    glutSwapBuffers();          // Swap buffer to display the shape due to DOUBLE mode
}

// Callback for Enter event
void keyboardCallbackForComparision(unsigned char key, int x, int y) {
    if (key == 13) {
        currentShapeIndex++;                // Move to the next shape
        if (currentShapeIndex >= shapes.size())
            currentShapeIndex = 0;          // Return to the first shape if the entire list has been drawn
        comparisonDisplay();                // Draw shape
    }
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set white background
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
    glColor3f(1.0f, 0.0f, 0.0f); // Set color of pixels to red
}

int main(int argc, char** argv) {
    string compare;
    cout << "Please enter the program's mode. Enter 0 to display the shapes. Enter other number to perform a line drawing comparison between the program's function and the OpenGL library function.\nMode = ";
    cin >> ws;
    cin >> compare;

    

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    //glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    // Locate the window as being in the middle of the screen
    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    int windowPosX = (screenWidth - WINDOW_WIDTH) / 2;
    int windowPosY = (screenHeight - WINDOW_HEIGHT) / 2;
    glutInitWindowPosition(windowPosX, windowPosY);

    glutCreateWindow("Shapes Display");
    
    init();

    if (compare != "0") {
        // Register callbacks for events
        glutDisplayFunc(comparisonDisplay);                 // Drawing
        glutKeyboardFunc(keyboardCallbackForComparision);   // Handle keyboard events
    }
    else {
        // Register callbacks for events
        glutDisplayFunc(displayShape);                      // Drawing
        glutKeyboardFunc(keyboardCallback);                 // Handle keyboard events
    }

    // Read information of shapes
    while (readShapes() != 0);

    glutMainLoop();

    return 0;
}
