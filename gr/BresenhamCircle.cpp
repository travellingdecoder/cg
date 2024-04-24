#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
using namespace std;

void points(int xc, int yc, int x, int y){
    putpixel(xc+x,yc+y,3);
    putpixel(xc+y,yc+x,3);
    putpixel(xc+y,yc-x,3);
    putpixel(xc+x,yc-y,3);
    putpixel(xc-x,yc+y,3);
    putpixel(xc-y,yc+x,3);
    putpixel(xc-y,yc-x,3);
    putpixel(xc-x,yc-y,3);
}
int main(){
    int gm, gd=DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    initgraph(&gd,&gm,data);
    int x,y,r,d,xc,yc;
    cout<<"Enter the radius"<<endl;
    cin>>r;
    x=0; y=r;
    d=3-2*r;
    cout<<"Enter the center coordinates of the circle"<<endl;
    cin>>xc>>yc;
    points(xc,yc,x,y);
    while(y>=x){
        x++; 
        if(d>0){ 
            y--;  
            d=d+4*(x-y)+10; 
        } 
        else
            d=d+4*x+6;
        points(xc,yc,x,y);
    }
    getch();
    closegraph();
}