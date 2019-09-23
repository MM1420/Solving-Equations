

#include <graphics.h>
#include <conio.h>
#define MAXX 640
#define MAXY 480

float scrx(float, float, float);
float scry(float, float, float);

float scrx(float xbeg, float x, float xend)
{
	return ((x-xbeg)/(xend-xbeg)*MAXX);
}

float scry(float ybeg, float y, float yend)
{
	return (MAXY-(y-ybeg)/(yend-ybeg)*MAXY);
}

void graphfunc(float xbeg, float ybeg, float xend, float yend, float a, float b, float c)
{
	int drv=VGA, mode=VGAHI;
	float x,y;
	initgraph(&drv,&mode,NULL);

	setcolor(4);
	line(0,scry(ybeg,0,yend),MAXX,scry(ybeg,0,yend));
	line(scrx(xbeg,0,xend),0,scrx(xbeg,0,xend),MAXY);

	setcolor(15);
	moveto(0,scry(ybeg,a*xbeg*xbeg+b*xbeg+c,yend));
	for(x=xbeg;x<=xend;x+=(xend-xbeg)/MAXX)
	{
		y=a*x*x+b*x+c;
		lineto(scrx(xbeg,x,xend),scry(ybeg,y,yend));
	}
	getch();
	closegraph();
}

int main()
{
    graphfunc(-100,-20,100,150,1,5,30);
}

