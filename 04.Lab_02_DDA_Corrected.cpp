#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	initwindow(900,900);
	cout<<"Bismillah"<<endl;
	
	float x1,y1,x2,y2,m,x,y;

	outtextxy(350,10,"Lab - 02");  
	
	int x_max = getmaxx(), y_max = getmaxy();
	
	cout<<x_max<<"\t"<<y_max<<endl;
	
	rectangle(0,0,x_max,y_max);
	
	line(0,y_max/2,x_max,y_max/2);
	line(x_max/2,0,x_max/2,y_max);
	
	line(x_max/2+100, y_max/2-100, x_max/2+200, y_max/2-100);
	
//	Scan Converting Line using DDA
	
//	x1 = x_max/2 + 0;
//	y1 = y_max/2 - 250;
//	x2 = x_max/2 + 100;
//	y2 = y_max/2 - 0;

	x1 = 0, y1 = 0, x2 = 6, y2 = 8;
	
	m = (y2-y1)/(x2-x1);
	
	cout<<"Value of m is : "<<m<<endl;
	
	
	cout<<"x \t"<<"\t y"<<endl;

	if(m <= 1)
	{
		x = x1;
		y = y1;
		while(x <= x2)
		{	
			cout<<round(x)<<"\t \t"<<round(y)<<endl;
			putpixel(round(x),round(y),WHITE);
			delay(50);
			y = y + m;
			x += 1;
		}
	}
	
	else if(m > 1)
	{
		y = y1;
		x = x1;
		while(y <= y2)
		{
			cout<<round(x)<<"\t \t"<<round(y)<<endl;
			putpixel(round(x),round(y),WHITE);
			delay(50);
			x = x + (1/m);
			y += 1;
		}
	}
	
	else if( x2 - x1 == 0)
	{
		cout<<"The value of m is infinity";
	}

	getch();
	closegraph();
	return 0;
}
