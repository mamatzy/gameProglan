#include <graphics.h>

int main()
{
	int gd = DETECT, gm;

	initgraph(&gd, &gm, "");

	// Persegi
	//hor 1
	line(150, 150, 450, 150);
	//hor 2
	line(150, 200, 450, 200);
	//ver 1
	line(450, 150, 450, 200);
	//ver 2
	line(150, 150, 150, 200);

    // sayap belakang kiri
	line(150, 150, 150, 100);
	line(150, 100, 200, 150);

	// sayap depan kanan
	line(350, 150, 350, 50);
	line(350, 50, 400, 150);

	// sayap belakang kanan
	line(150, 150, 150, 100);
	line(150, 100, 200, 150);

	getch();

	closegraph();
}
