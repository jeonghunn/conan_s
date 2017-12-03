#pragma once

void    PlayMode(int);
void    PlayResult(int);
void    PlayGiveUp(int);
void startPlay(int);
void initPlay(void);
void AnswerYes(void);
void AnswerMaybeYes(void);
void AnswerUnknown(void);
void AnswerMaybeNot(void);
void AnswerNo(void);
int getRandInt(int, int);
int TAGS_COUNT;
int TAGS_MAX_COUNT;
int MUSIC_COUNT;
int PLAY_STATUS; // 0: startplay 1:  playing 2: result 3: give up
int QUESTION_SRL; //질문 넘버
int QUESTION_TRY_COUNT; //지금까지 한 질문 횟수
int Point[];
int SELECTED_ANSWER;