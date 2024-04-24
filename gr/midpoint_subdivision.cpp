#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

const int INSIDE = 0;  // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

const int xMin = 50;
const int yMin = 50;
const int xMax = 250;
const int yMax = 250;

int computeCode(int x, int y) {
    int code = INSIDE;

    if (x < xMin)
        code |= LEFT;
    else if (x > xMax)
        code |= RIGHT;

    if (y < yMin)
        code |= BOTTOM;
    else if (y > yMax)
        code |= TOP;

    return code;
}

void midpoint(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    // Both inside 
    if (code1 == 0 && code2 == 0) {
        line(x1, y1, x2, y2);
        return;  
    }

    // Both outside 
    if (code1 & code2 != 0) {
        return;
    }

    
    int xmid = round((x1 + x2) / 2), ymid = round((y1 + y2) / 2);
    int codemid = computeCode(xmid, ymid);

   
    if (codemid) { // midpoint outside 
        if (code1) { // first endpoint outside
            midpoint(x2, y2, xmid, ymid);
        } else {
            midpoint(x1, y1, xmid, ymid);
        }
    } else { // midpoint inside
        if (code1) { // first endpoint outside
            midpoint(x1, y1, xmid, ymid); 
        } else {
            midpoint(x2, y2, xmid, ymid); 
        }
    }
}

int main() {
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; 
    initgraph(&gd, &gm, data);

    int x1, y1, x2, y2;
    cout << "Enter coordinates of first point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter coordinates of second point (x2 y2): ";
    cin >> x2 >> y2;

    rectangle(xMin, yMin, xMax, yMax);
    midpoint(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
