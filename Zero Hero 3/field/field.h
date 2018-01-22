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
	void getHeroLoc();
	bool controlPanel();

	//for printing
	void printField();
	void printSkillSet();
	void printStatusBar();
	void printHint();
	
	
	/************************************
	 * main list structure				*
	 * and it can load into sublist:	*
	 * - item (bag)						*
	 * - skill set (skill)				*
	 * - hero status (status)			*
	 * - save game (save)				*
	 *	**************************		*
	 *	* HP: 20/20 * (i)Items   *		*
	 *  * MP: 5/5   * (e)Equip   *      *
	 *	* Coin: 0   * (k)Skill   *		*
	 *	* Level: 1  * (s)Status  *		*
	 *	* EXP: 0/20 * (o)Save    *		*
	 *	**************************		*
	 ************************************/
	void openMainList();

	bool battleEngage();
	
	bool loadSaved();
	
	int getHeroLocX();
	int getHeroLocY();
	
	void changeStep(int input);
	
	char controlPanel(char input);
	
	void addThingsOnMap(int row, int col, char chara);
	
	char getMapChar(int row, int col);
	
	int getHealBottle();

	int chooseSkill();

	friend void battleReward(HeroStatus* heroStatus, Bag* bag, int step);
};
//get a prototype for main using sleep
void sleep(int s);

#endif