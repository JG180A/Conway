
//Compiler optimierung = -Oirs


#include <c64.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define P_SCREEN0 ((unsigned char *)0x2000)
#define P_COLOR0  ((unsigned char *)0x0400)

#define P_SCREEN1 ((unsigned char *)0x6000)
#define P_COLOR1  ((unsigned char *)0x4400)

//HighRes Mode 300x200px
#define XMAX 40
#define YMAX 25
#define BOXSIZE 3
#define ROUNDS 1

//void printSpielfeld(int spielfeld[][YMAX]);

//static const char array[XMAX][YMAX] 
static int spielfeld[XMAX][YMAX] = {
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
};

static int spielfeld[XMAX][YMAX];
static int temp[XMAX][YMAX];

int main(void)
{
	clock_t       t;
	unsigned long sec;
	unsigned      sec10;
	unsigned long fps;
	unsigned      fps10;
	unsigned char background;
	unsigned char text;

	char x;
	char y;
	char lebende;
	char xl, xr, yo, yu;
	unsigned char round = 0;

	t = clock();
	clrscr();
	background = bgcolor(COLOR_BLACK);
	text = textcolor(COLOR_WHITE);
	for (y = 0; y < YMAX; y++) {
		for (x = 0; x < XMAX; x++) {
			revers(spielfeld[x][y]);
			cputcxy(x, y, 32);
		}
	}
	//	signal (int sig, __sigfunc func);


	while (round < ROUNDS && !kbhit()) {
		for (y = 0; y < YMAX; y++) {
			for (x = 0; x < XMAX; x++) {

				xl = x - 1;
				xr = x + 1;
				yo = y - 1;
				yu = y + 1;
				if (x == 0) {
					xl = XMAX - 1;
				}
				else if (x == XMAX - 1) {
					xr = 0;
				}
				if (y == 0) {
					yo = YMAX - 1;
				}
				else if (y == YMAX - 1) {
					yu = 0;
				}
				lebende = 0;
				lebende += spielfeld[xl][yo];
				lebende += spielfeld[x][yo];
				lebende += spielfeld[xr][yo];
				lebende += spielfeld[xl][y];
				lebende += spielfeld[xr][y];
				lebende += spielfeld[xl][yu];
				lebende += spielfeld[x][yu];
				lebende += spielfeld[xr][yu];

				switch (lebende)
				{
				case 2:
					temp[x][y] = spielfeld[x][y];
					break;
				case 3:
					temp[x][y] = 1;
					break;
				default:
					temp[x][y] = 0;
					break;
				}
			}// for x
		}// for y

		memcpy(spielfeld, temp, XMAX * YMAX * 2);

		round++;
		for (y = 0; y < YMAX; y++) {
			for (x = 0; x < XMAX; x++) {
				revers(spielfeld[x][y]);
				cputcxy(x, y, 32);
			}
		}
	}
	t = clock() - t;

	/* Reset screen colors */
	bgcolor(background);
	textcolor(text);
	clrscr();

	/* Calculate stats */
	sec = (t * 10) / CLK_TCK;
	sec10 = sec % 10;
	sec /= 10;
	fps = (round * (CLK_TCK * 10)) / t;
	fps10 = fps % 10;
	fps /= 10;

	/* Output stats */
	gotoxy(0, 0); cprintf("time  : %lu.%us", sec, sec10);
	gotoxy(0, 1); cprintf("frames: %lu", round);
	gotoxy(0, 2); cprintf("fps   : %lu.%u", fps, fps10);

	/* Wait for a key, then end */
	cputsxy(0, 4, "Press any key when done...");
	(void)cgetc();

	/* Done */
	return EXIT_SUCCESS;
}










