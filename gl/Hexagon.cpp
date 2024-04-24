#include <windows.h>
#include <GL/glut.h>
#include <cmath>

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);  // Green
    float radius = 1.0f;
    for (int i = 0; i < 6; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / 6.0f;  // Angle for each vertex
        float x = radius * cosf(theta);  // Calculate x component
        float y = radius * sinf(theta);  // Calculate y component
        glVertex2f(x, y);  // Define vertex at (x, y)
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Simple Hexagon");
    glutInitWindowSize(320, 240);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
