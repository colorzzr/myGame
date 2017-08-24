#ifndef FEILD_H
#define FEILD_H

#include "../status/heroStatus.h"

class Field{
private:
	char map[10][10];
	int heroLocX;
	int heroLocY;
	HeroStatus* heroStatus;
public:
	Field();
	~Field();
	void printField();
	void getHeroLoc();
};

#endif