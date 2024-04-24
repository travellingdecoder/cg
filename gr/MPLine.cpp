#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
using namespace std;

void Mid_Point(int x_1, int y_1, int x_2, int y_2){
    int dx=x_2-x_1;
    int dy=y_2-y_1;
    int p=2*dy - dx;
    int x=x_1;
    int y=y_1;
    for(int i=0;i<dx;i++){
        x++;
        if(p<0){
            p=p+2*dy;
        }
        else{
            p=p+2*dy-2*dx;
            y++;
        }
        cout<<x<<","<<y<<endl;
        putpixel(x,y,3);
        delay(100);
    }
}

int main(){
    int gm, gd=DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    initgraph(&gd,&gm,data);  
    int x_1 = 40;
    int y_1 = 80;
    int x_2 = 90;
    int y_2 = 120;
    cout<<"Mid-Points through Line Generation Algorithm are: ";
    Mid_Point(x_1, y_1, x_2, y_2);
    getch();
    closegraph();
    return 0;
}