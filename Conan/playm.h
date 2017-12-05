/*
 * playm.h
 *
 *  Created on: 2017. 12. 6.
 *      Author: craftingmod
 */

#ifndef PLAYM_H_
#define PLAYM_H_

void playm_createSystem(FMOD_SYSTEM **);
void playm_playSound(FMOD_SYSTEM *,FMOD_SOUND **,char [200], int);
void playm_stopSound(FMOD_SOUND *);
void playm_destorySystem(FMOD_SYSTEM *);

#endif /* PLAYM_H_ */
