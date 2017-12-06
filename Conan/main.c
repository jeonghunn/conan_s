// Conan.c: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "gui_splash.h"
#include "config_conan.h"

/* change this if source at other location */


# define FNAME  "tui.c"
# define FNAME  "appinfo.c"
# define FNAME  "play.c"
# define FNAME  "decision.c"


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
	{ "Data", sub1, "Data of Conan" },
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

}

void subfunc2(void)
{

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
	
	startmenu(MainMenu,"Conan - The Music Detective (Beta Version)");
	wchar_t *des = L"개발중인 버전입니다. Under Construction";


	//wchar_t *ws2 = L"동하! 동현이 하이라는뜻";
//	addwstr(ws2);


	return 0;
}
