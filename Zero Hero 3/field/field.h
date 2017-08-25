#ifndef FEILD_H
#define FEILD_H

#include "../status/heroStatus.h"

class Field{
private:
	char map[10][10];
	//hero location
	int heroLocX;
	int heroLocY;
	//step is not meaningful but to make random location of enemy
	int step;
	HeroStatus* heroStatus;
public:
	Field();
	~Field();
	void printField();
	void getHeroLoc();
	void controlPanel();
	void printStatusBar();
	void printHint();
};

#endif