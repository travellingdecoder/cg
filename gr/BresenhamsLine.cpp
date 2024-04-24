#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
using namespace std;
int main(){
    int gm, gd=DETECT;
    int x1,y1,x2,y2,dx,dy,p;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    initgraph(&gd,&gm,data);
    cout<<"Enter values of x1 and y1"<<endl;
    cin>>x1>>y1;
    cout<<"Enter values of x2 and y2"<<endl;
    cin>>x2>>y2;
    dx=x2-x1;
    dy=y2-y1;
    p=2*dy-dx;
    putpixel(x1,y1,3);
    for(int k=0;k<dx;k++){
        if(p<0){
            x1++;
            p=p+2*dy;
        }
        else{
            x1++; y1++;
            p=p+2*dy-2*dx;
        }
        putpixel(x1,y1,3);
    }
    getch();
    closegraph();
}
