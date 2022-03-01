#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

// Defining region codes
 int inside = 0; // 0000
 int Left = 1; // 0001
 int Right = 2; // 0010
 int Bottom = 4; // 0100
 int Top = 8; // 1000

 int x_max = 2;
 int y_max = 6;
 int x_min = -3;
 int y_min = 1;
 
// Function to compute region code for a point(x, y)
int region_code(double x, double y)
{
	// initialized as being inside
	int code = inside;

	if (x < x_min) // to the left of rectangle
		code |= Left;
	else if (x > x_max) // to the right of rectangle
		code |= Right;
	if (y < y_min) // below the rectangle
		code |= Bottom;
	else if (y > y_max) // above the rectangle
		code |= Top;
	cout<<code<<endl;
	return code;
}

// Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)
void Sutherland_Clip(double x1, double y1, double x2, double y2)
{
	// Compute region codes for P1, P2
	int code1 = region_code(x1, y1);
	int code2 = region_code(x2, y2);

	bool flag = false;

	while (true)
	{
		if ((code1|code2)== 0) //Visible line
		{
			flag = true;
			break;
		}
		else if (code1 & code2) //InVisible line
		{
			//printf("InVisible line,");
			break;
		}
		else //Clipping candidate
		{
			int code_out;
			double x, y,m=(y2-y1)/(x2-x1);

			// At least one endpoint is outside the
			// rectangle, pick it.
			if (code1 != 0)
				code_out = code1;
			else
				code_out = code2;

			// Find intersection point;
			if (code_out & Top) // point is above the clip rectangle
			{
				x = x1 +(y_max - y1) /m;
				y = y_max;
			}
			else if (code_out & Bottom) // point is below the rectangle
			{
				x = x1 + (y_min - y1)/m;
				y = y_min;
			}
			else if (code_out & Right)// point is to the right of rectangle
			{
				y = y1 +m*(x_max - x1);
				x = x_max;
			}
			else if (code_out & Left)//point is to the left of rectangle
			{
				y = y1 + m*(x_min - x1);
				x = x_min;
			}

			// Now intersection point x, y is found
			// We replace point outside rectangle
			if (code_out == code1)
			{
				x1 = x;
				y1 = y;
				code1 = region_code(x1, y1);
			}
			else
			{
				x2 = x;
				y2 = y;
				code2 = region_code(x2, y2);
			}
		}
	}
	if (flag)
	{
		cout << "line is visible from " << x1 << ", "
			<< y1 << " to " << x2 << ", " << y2 << endl;
	}
	else
		cout << "The Line is invisible:" << endl;
}


int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	initwindow(900,900);
	cout<<"Bismillah"<<endl;
	int x1, x2, y1, y2;
	outtextxy(350,10,"Lab - 07");  
	
	int x_max = getmaxx(), y_max = getmaxy();
	
	cout<<x_max<<"\t"<<y_max<<endl;
	
	rectangle(0,0,x_max,y_max);
	
	line(0,y_max/2,x_max,y_max/2);
	line(x_max/2,0,x_max/2,y_max);
	
//	Draw rectangle wrt user coordinate
	
//	x1, y1, x2, y2
	Sutherland_Clip(-4, 2, -1,7);
	
	getch();
	closegraph();
	return 0;
}
