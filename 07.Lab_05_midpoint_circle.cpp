#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void draw_cirle(int h, int k, int x, int y)
{
	putpixel(h+x, k+y, WHITE);
	putpixel(h-x, k+y, WHITE);
	putpixel(h+x, k-y, WHITE);
	putpixel(h-x, k-y, WHITE);
	putpixel(h+y, k+x, WHITE);
	putpixel(h-y, k+x, WHITE);
	putpixel(h+y, k-x, WHITE);
	putpixel(h-y, k-x, WHITE);
	
}
void midpoint_circle(int h, int k, int r)
{
	int x = 0, y = r, p = 1 - r;
	while(x<=y)
	{
		draw_cirle(h,k,x,y);
		delay(50);
		if (p<0)
		{
			p = p + (2*x )+ 3;
		}
		else
		{
			p = p + 2*(x-y)+5;
			y--;
		}
		x++;
	}
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	initwindow(900,900);
	cout<<"Bismillah"<<endl;
	int h,k,r,x,y;
	outtextxy(350,10,"Lab - 05");  
	
	int x_max = getmaxx(), y_max = getmaxy();
	
	cout<<x_max<<"\t"<<y_max<<endl;
	
	rectangle(0,0,x_max,y_max);
	
	line(0,y_max/2,x_max,y_max/2);
	line(x_max/2,0,x_max/2,y_max);
	
	h = x_max/2 + 100;
	k = y_max/2 - 100;
	r = 40;
	midpoint_circle(h,k,r);
	getch();
	closegraph();
	return 0;
}
