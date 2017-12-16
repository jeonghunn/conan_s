// Conan.c: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


/* change this if source at other location */


# define FNAME  "tui.c"
# define FNAME  "appinfo.c"
# define FNAME  "play.c"
# define FNAME  "decision.c"





int WaitForUser(void);
int SubWinTest(WINDOW *);
int BouncingBalls(WINDOW *);
void trap(int);





/* Funny messages for the scroller */

char *messages[] =
{
	"Hello from the Land Down Under",
	"The Land of crocs, and a big Red Rock",
	"Where the sunflower runs along the highways",
	"The dusty red roads lead one to loneliness",
	"Blue sky in the morning and",
	"Freezing nights and twinkling stars",
	NULL
};

int WaitForUser(void)
{
	chtype ch;

	nodelay(stdscr, TRUE);
	halfdelay(50);

	ch = getch();

	nodelay(stdscr, FALSE);
	nocbreak();     /* Reset the halfdelay() value */
	cbreak();

	return (ch == '\033') ? ch : 0;
}

int SubWinTest(WINDOW *win)
{
	WINDOW *swin1, *swin2, *swin3;
	int w, h, sw, sh, bx, by;

	wattrset(win, 0);
	getmaxyx(win, h, w);
	getbegyx(win, by, bx);

	sw = w / 3;
	sh = h / 3;

	if ((swin1 = derwin(win, sh, sw, 3, 5)) == NULL)
		return 1;
	if ((swin2 = subwin(win, sh, sw, by + 4, bx + 8)) == NULL)
		return 1;
	if ((swin3 = subwin(win, sh, sw, by + 5, bx + 11)) == NULL)
		return 1;

	init_pair(8, COLOR_RED, COLOR_BLUE);
	wbkgd(swin1, COLOR_PAIR(8));
	werase(swin1);
	mvwaddstr(swin1, 0, 3, "Sub-window 1");
	wrefresh(swin1);

	init_pair(9, COLOR_CYAN, COLOR_MAGENTA);
	wbkgd(swin2, COLOR_PAIR(9));
	werase(swin2);
	mvwaddstr(swin2, 0, 3, "Sub-window 2");
	wrefresh(swin2);

	init_pair(10, COLOR_YELLOW, COLOR_GREEN);
	wbkgd(swin3, COLOR_PAIR(10));
	werase(swin3);
	mvwaddstr(swin3, 0, 3, "Sub-window 3");
	wrefresh(swin3);

	delwin(swin1);
	delwin(swin2);
	delwin(swin3);
	WaitForUser();

	return 0;
}

int BouncingBalls(WINDOW *win)
{
	chtype c1, c2, c3, ball1, ball2, ball3;
	int w, h, x1, y1, xd1, yd1, x2, y2, xd2, yd2, x3, y3, xd3, yd3, c;

	curs_set(0);

	wbkgd(win, COLOR_PAIR(1));
	wrefresh(win);
	wattrset(win, 0);

	init_pair(11, COLOR_RED, COLOR_GREEN);
	init_pair(12, COLOR_BLUE, COLOR_RED);
	init_pair(13, COLOR_YELLOW, COLOR_WHITE);

	ball1 = 'O' | COLOR_PAIR(11);
	ball2 = '*' | COLOR_PAIR(12);
	ball3 = '@' | COLOR_PAIR(13);

	getmaxyx(win, h, w);

	x1 = 2 + rand() % (w - 4);
	y1 = 2 + rand() % (h - 4);
	x2 = 2 + rand() % (w - 4);
	y2 = 2 + rand() % (h - 4);
	x3 = 2 + rand() % (w - 4);
	y3 = 2 + rand() % (h - 4);

	xd1 = 1;
	yd1 = 1;
	xd2 = 1;
	yd2 = -1;
	xd3 = -1;
	yd3 = 1;

	nodelay(stdscr, TRUE);

	while ((c = getch()) == ERR)
	{
		x1 += xd1;
		if (x1 <= 1 || x1 >= w - 2)
			xd1 *= -1;

		y1 += yd1;
		if (y1 <= 1 || y1 >= h - 2)
			yd1 *= -1;

		x2 += xd2;
		if (x2 <= 1 || x2 >= w - 2)
			xd2 *= -1;

		y2 += yd2;
		if (y2 <= 1 || y2 >= h - 2)
			yd2 *= -1;

		x3 += xd3;
		if (x3 <= 1 || x3 >= w - 2)
			xd3 *= -1;

		y3 += yd3;
		if (y3 <= 1 || y3 >= h - 2)
			yd3 *= -1;

		c1 = mvwinch(win, y1, x1);
		c2 = mvwinch(win, y2, x2);
		c3 = mvwinch(win, y3, x3);

		mvwaddch(win, y1, x1, ball1);
		mvwaddch(win, y2, x2, ball2);
		mvwaddch(win, y3, x3, ball3);

		wmove(win, 0, 0);
		wrefresh(win);

		mvwaddch(win, y1, x1, c1);
		mvwaddch(win, y2, x2, c2);
		mvwaddch(win, y3, x3, c3);

		napms(150);
	}

	nodelay(stdscr, FALSE);
	ungetch(c);
	return 0;
}

/* Trap interrupt */

void trap(int sig)
{
	if (sig == SIGINT)
	{
		endwin();

		exit(0);
	}
}
void splash() {
	char Logo[][30] =
	{
		"   ###            #   ",
		"  #   #  #    #  ##   ",
		" #     #  #  #  # #   ",
		" #     #   ##     #   ",
		" #     #   ##     #   ",
		"  #   #   #  #    #   ",
		"   ###   #    # ##### ",
		""
	};
	char* titlero = "       Conan - The Music Defective         ";

	

	WINDOW *win;
	chtype  ch;
	int width, height, x, y, i;

	initscr();

	start_color();

	cbreak();
	noecho();

	curs_set(0);

	noecho();

	/* refresh stdscr so that reading from it will not cause it to
	overwrite the other windows that are being created */

	refresh();

	/* Create a drawing window */

	width = 48;
	height = 15;

	win = newwin(height, width, (LINES - height) / 2, (COLS - width) / 2);

	if (win == NULL)
	{
		endwin();

		return;
	}

	while (1) {
		werase(win);
		wrefresh(win);


		/* Draw RED bounding box */

		wattrset(win, COLOR_PAIR(7));
		box(win, ' ', ' ');
		wrefresh(win);

		/* Display Australia map */

		wattrset(win, A_BOLD);
		i = 0;

		napms(250);
		while (*Logo[i])
		{
			mvwaddstr(win, i + 3, 13, Logo[i]);
			wrefresh(win);
			napms(100);
			++i;
		}

		napms(1100);
		init_pair(5, COLOR_BLACK, COLOR_WHITE);
		wattrset(win, COLOR_PAIR(5) | A_BLINK);
		mvwaddstr(win, height - 2, 3,
			titlero);
		//mvaddstr(win, height -3, 4, appversion);
		wrefresh(win);
		while (1) {
			if (WaitForUser() >= 0) {
				break;
			}
		}
		break;
	}
	

	endwin();
}


/**************************** strings entry box ***************************/

void address(void)
{
	char *fieldname[6] =
	{
		"Name", "Street", "City", "State", "지역", (char *)0
	};

	char *fieldbuf[5];
	WINDOW *wbody = bodywin();
	int i, field = 50;

	for (i = 0; i < 5; i++)
		fieldbuf[i] = calloc(1, field + 1);

	if (getstrings(fieldname, fieldbuf, field) != KEY_ESC)
	{
		for (i = 0; fieldname[i]; i++)
			wprintw(wbody, "%10s : %s\n",
				fieldname[i], fieldbuf[i]);

		wrefresh(wbody);
	}

	for (i = 0; i < 5; i++)
		free(fieldbuf[i]);
}


/**************************** string entry box ****************************/

char *getfname(char *desc, char *fname, int field)
{
	char *fieldname[2];
	char *fieldbuf[1];

	fieldname[0] = desc;
	fieldname[1] = 0;
	fieldbuf[0] = fname;

	return (getstrings(fieldname, fieldbuf, field) == KEY_ESC) ? NULL : fname;
}

/**************************** a very simple file browser ******************/

void showfile(char *fname)
{
	int i, bh = bodylen();
	FILE *fp;
	char buf[MAXSTRLEN];
	bool ateof = FALSE;

	statusmsg("FileBrowser: Hit key to continue, Q to quit");

	if ((fp = fopen_s(&fp ,fname, "r")) != NULL)   /* file available? */
	{
		while (!ateof)
		{
			clsbody();

			for (i = 0; i < bh - 1 && !ateof; i++)
			{
				buf[0] = '\0';
				fgets(buf, MAXSTRLEN, fp);

				if (strlen(buf))
					bodymsg(buf);
				else
					ateof = TRUE;
			}

			switch (waitforkey())
			{
			case 'Q':
			case 'q':
			case 0x1b:
				ateof = TRUE;
			}
		}

		fclose(fp);
	}
	else
	{
		sprintf_s(buf, sizeof(buf),"ERROR: file '%s' not found", fname);
		errormsg(buf);
	}
}

/***************************** forward declarations ***********************/


void sub0(void), sub1(void), sub2(void), sub3(void);
void func1(void), func2(void);
void subfunc1(void), subfunc2(void);
void subsub(void);


/***************************** menus initialization ***********************/

menu MainMenu[] =
{
	{ "Home", mainScreen, "Main Menu" },
	{ "Play", sub0, "Play Conan" },
	{ "AppInfo", sub3, "Conan Application Information" },
	{ "", (FUNC)0, "" }   /* always add this as the last item! */
};

menu SubMenu0[] =
{
	{ "Play", initPlay, "Play Conan" },
	{ "Exit", DoExit, "Terminate program" },
	{ "", (FUNC)0, "" }
};

menu SubMenu1[] =
{
	{ "OneBeep", func1, "Sound one beep" },
	{ "TwoBeeps", func2, "Sound two beeps" },
	{ "ResultPage", PlayResult, "ResultPage" },
	{ "GiveupPage", PlayGiveUp, "GiveupPage" },
	{ "", (FUNC)0, "" }
};

menu SubMenu2[] =
{
	{ "Browse", subfunc1, "Source file lister" },
	{ "Input", subfunc2, "Interactive file lister" },
	{ "Address", AppInfo, "Get address data" },
	{ "", (FUNC)0, "" }
};

menu SubMenu3[] =
{
	{ "About Conan", AppInfo, "Application Information" },
	{ "About Team 0x1", AboutTeam, "Team Information" },
	{ "", (FUNC)0, "" }
};

/***************************** main menu functions ************************/

void sub0(void)
{
	domenu(SubMenu0);
}

void sub1(void)
{
	domenu(SubMenu1);
}

void sub2(void)
{
	domenu(SubMenu2);
}

void sub3(void)
{
	domenu(SubMenu3);
}

/***************************** submenu1 functions *************************/

void func1(void)
{
	beep();
	
	wchar_t *ws2 = L"개발중인 버전입니다......";
	bodymsg(ws2);
}

void func2(void)
{
	beep();
	bodymsg("Two beeps! ");
	beep();
}

/***************************** submenu2 functions *************************/

void subfunc1(void)
{
	showfile(FNAME);
}

void subfunc2(void)
{
	char fname[MAXSTRLEN];

	strcpy_s(fname, sizeof(fname), FNAME);
	if (getfname("File to browse:", fname, 50))
		showfile(fname);
}

/***************************** submenu3 functions *************************/

void subsub(void)
{
	domenu(SubMenu2);
}


/***************************** start main menu  ***************************/

int main(int argc, char **argv)
{
	//setlocale(LC_ALL, "Korean");
	
	splash();
	//printf("%s", aa);
	
	startmenu(MainMenu,"Conan - The Music Detective");
	wchar_t *des = L"개발중인 버전입니다. Under Construction";


	//wchar_t *ws2 = L"동하! 동현이 하이라는뜻";
//	addwstr(ws2);


	return 0;
}
