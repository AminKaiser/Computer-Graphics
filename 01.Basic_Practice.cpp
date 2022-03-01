#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	initwindow(1000,1000);
	cout<<"Bismillah";
	
	line(150,150,450,150);
	line(0,350,750,350);
	line(350,0,350,750);
	line(375+20,350-20,375+50,350-20);
	line(375+20,350-20,375+20,350-50);
	setcolor(GREEN);
	outtextxy(900,10,"Bismillah");  
	rectangle(150,150,450,450);
	rectangle(250,250,550,470);
	rectangle(20,20,900,900);
	setcolor(RED);
	circle(500,200,100);
	floodfill(500,200,RED);
	
	getch();
	closegraph();
	return 0;
}
