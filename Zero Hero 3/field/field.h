#ifndef FEILD_H
#define FEILD_H

#include <fstream>
#include <iostream>

#include "../status/heroStatus.h"
#include "../status/enemyStatus.h"
#include "../bag/bagInfo.h"

using namespace std;

class Field{
private:
	char map[10][10];
	//hero location
	int heroLocX;
	int heroLocY;
	//step is not meaningful but to make random location of enemy
	int step;
	HeroStatus* heroStatus;
	EnemyStatus* enemyStatus;
	Bag* bag;
public:
	Field();
	~Field();
	void generateEnemy();
	void printField();
	void getHeroLoc();
	bool controlPanel();
	void printStatusBar();
	void printHint();
	void openMainList();
	bool battleEngage();
	friend void battleReward(HeroStatus* heroStatus, Bag* bag, int step);
};
//get a prototype for main using sleep
void sleep(int s);

#endif