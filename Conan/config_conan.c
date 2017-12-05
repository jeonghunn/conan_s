#include <wchar.h>
#include "config_conan.h"

#ifdef ALT_X
    #define _help_str "Use arrow keys and Enter to select (Alt-X to quit) - Created by Junghoon Lee, 2017"
#else
    #define _help_str "Use arrow keys and Enter to select"
#endif

#define NO_PSEUDO_JH 0

#ifdef DEBUG
   # define _PSEUDO_JHRUNNING !NO_PSEUDO_JH
#else
# define _PSEUDO_JHRUNNING 0
#endif


// Memory drain, so what?
char *help_str = _help_str;
long PSEUDO_JHRUNNING = _PSEUDO_JHRUNNING;
wchar_t mainscreen_str[][300] = {
		L"  ______                        \n",
		L" / _____)                       \n",
		L"| /       ___  ____    ____ ____  \n",
		L"| |      / _ \\ |  _ \\ / _  |  _ \\ \n",
		L"| \\\\____ | | | | | | ( ( | | | | |\n",
		L" \\______)\\___/ |_| |_|\\_||_|_| |_|\n\n",
		L"\'어... 그 노래 제목이 뭐였더라...\' 내가 지금 흥얼거리고 있는 노래가 궁금할 때\n\n",
		L" 0.11 패치 변경 내역\n",
		L"======================================\n",
		L"틀린 대답일시 이어서 플레이 가능\n",
		L"\n\n",
		L" 찾아낼 수 있는 음악\n",
		L"======================================\n",
		L"10개의 샘플 음악\n",
		L"\n\n",
		L" 코난 - 노래 찾는 탐정은 음악의 고유한 특징을 질문, 추정하여 찾고자 하는 음악이 무엇인지 알아냅니다.\n",
		L" 기존에는 음원을 재생해야 찾을 수 있었지만, Conan은 머리속에서 재생되는 음악을 찾습니다. 지금 플레이해보세요.",
		L"" // don't remove as it is end.
};
char music_intro[] = "title.mp3";
char music_playing[] = "main.mp3";
const wchar_t *appversion = L"0.14.1206";
