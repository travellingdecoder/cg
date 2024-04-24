#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
using namespace std;
int main(){
    int gm, x, y, gd = DETECT, i; //graph driver and graph mode
    int x1, y1, x2, y2, dx, dy, steps, xinc, yinc;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    initgraph(&gd, &gm, data);
    cout<<"Enter values of x1 and y1"<<endl;
    cin>>x1>>y1;
    cout<<"Enter values of x2 and y2"<<endl;
    cin>>x2>>y2;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy)){
        steps=abs(dx);
    }
    else{
        steps=abs(dy);
    }
    xinc=dx/steps;
    yinc=dy/steps;
    for(i=0;i<steps;i++){
        putpixel(x1,y1,3);
        x1=x1+xinc;
        y1=y1+yinc;
    }
    getch();
    closegraph();

    return 0;
}
