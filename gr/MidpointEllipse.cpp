#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
using namespace std;
int main(){
    int gm, gd=DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; 
    initgraph(&gd,&gm,data);
    int rx, ry, dx, dy, x, y, p1, p2, xc, yc;
    cout<<"Enter the value of rx and ry: "<<endl;
    cin>>rx>>ry;
    cout<<"Enter center of ellipse: "<<endl;
    cin>>xc>>yc;
    x = 0;
    y = ry;
    dx=2*ry*ry*x;
    dy=2*rx*rx*y;
    p1=(ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);

    //region 1
    while(dx<dy){
        putpixel(x + xc,y + yc,3);
        putpixel(-x + xc,y + yc,3);
        putpixel(x + xc,-y + yc,3);
        putpixel(-x + xc,-y + yc,3);
       if(p1<0){
        x++;
        dx=2*ry*ry*x; 
        p1=p1+dx+(ry*ry);
       }
       else{
        x++; y--;
        dx=2*ry*ry*x; dy=2*rx*rx*y;
        p1=p1+dx-dy +(ry*ry);
       }

    }
    //Region 2
    p2=((ry * ry) * ((x + 0.5) * (x + 0.5))) + 
         ((rx * rx) * ((y - 1) * (y - 1))) -
          (rx * rx * ry * ry);
    while(y>0){
        putpixel(x + xc,y + yc,3);
        putpixel(-x + xc,y + yc,3);
        putpixel(x + xc,-y + yc,3);
        putpixel(-x + xc,-y + yc,3);
        if(p2>0){
            y--;
            dy = 2 * rx * rx*y;
            p2=p2-dy+(rx*rx);
        }
        else{
            x++; y--;
            dx = 2 * ry * ry*x;
            dy = 2 * rx * rx*y;
            p2=p2+(dx-dy)+(rx*rx);
        }
    }
    getch();
    closegraph();

}