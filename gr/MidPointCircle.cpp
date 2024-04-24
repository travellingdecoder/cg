#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
using namespace std;
int main(){
    int gm, gd=DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    initgraph(&gd,&gm,data);
    int x,y,r,d,xc,yc;
    cout<<"Enter the radius"<<endl;
    cin>>r;
    x=0; y=r;
    d=(5/4)-r;
    cout<<"Enter the center coordinates of the circle"<<endl;
    cin>>xc>>yc;
    do{
        putpixel(xc+x,yc+y,3);
        putpixel(xc+y,yc+x,3);
        putpixel(xc+y,yc-x,3);
        putpixel(xc+x,yc-y,3);
        putpixel(xc-x,yc+y,3);
        putpixel(xc-y,yc+x,3);
        putpixel(xc-y,yc-x,3);
        putpixel(xc-x,yc-y,3);
        delay(100);
        if(d<0){
            d=d+2*x+3;
            x++;
        }
        else{
            d=d+(2*x)-(2*y)+5;
            x++;
            y--;
        }
    }while(x<y);
     
}