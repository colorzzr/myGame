#ifndef HEROSTATUS_H
#define HEROSTATUS_H

#include "enemyStatus.h"
#include "../skill/skill.h"

//for enemyStatus is an argument of function. it need prototype
class EnemyStatus;
class Bag;
class HeroStatus{
private:
	/********************************************************
	 * strength related to the damage hero take and suffer	*
	 * and phy and magic defense and HP 					*
	 ********************************************************/
	int STR; 

	/************************************************
	 * intellengcerelated to skill damage herotake 	*
	 and the magic magicDefense 					*
	 ************************************************/
	int INTE;

	/********************************************************
	 * luck related to the physical and magic and critical 	*
	 * and the HP  											*
	 ********************************************************/
	int LUC;

	/********************************************
	 * agility related to escape and miss ratr 	*
	 ********************************************/
	int AGI;

	/********************************************
	 * heroHPMax = 15 + 0.2 * STR + 0.1 * LUC; 	*
	 ********************************************/
	int heroHPMax;
	int heroHPNow;

	/********************************
	 * heroMPMax = 2 + 0.2 * INTE;	*
	 ********************************/
	int heroMPMax;
	int heroMPNow;

	//levelUpEXP start with 20
	int EXP;
	int levelUpEXP;
	int level;
	int skillPoint;

	/********************************************************
	 * physicalDefense = STR * 0.3 + LUC * 0.2 + AGI * 0.1;	*
	 * magicDefense = STR * 0.2 + LUC * 0.3 + AGI * 0.15;	*
	 ********************************************************/
	int physicalDefense;
	int magicDefense;

	//go for building the skill area
	SkillPhaser* skillPhaser;
public:
	HeroStatus(int heroLocX, int heroLocY);
	~HeroStatus();
	void printStatus();

	//get 4 status
	int getStr();
	int getInt();
	int getAgi();
	int getLuck();
	//for Hp
	int getHeroHpNow();
	void changeHeroHpNow(int val);
	int getHeroHpMax();
	void changeHeroHpMax(int val);
	
	//for Mp
	int getHeroMpNow();
	void setHeroMpNow(int val);
	int getHeroMpMax();
	void setHeroMpMax(int val);
	
	//for level
	int getLevel();
	void changeLevel(int val);
	void levelUp();
	
	/****************************************************
	 * function is to print the skill as following:		*
	 * *****************								*
	 * *   skill1   1  *								*
	 * *   skill2   2  *								*
	 * *   skill3   3  *								*
	 * *****************								*
	 * which skill you want to check(input number)?		*
	 ****************************************************/
	void printSkill();
	/****************************************************************
	 * this function allow user the choos their skill in battle.	*
	 * and return it for calculating funciton.						*
	 ****************************************************************/
	Skill printSkillBattle();

	//for skill set
	void checkForLearningSkill();
	SkillPhaser* getSkillPhaser();
	
	//for exp
	int getEXP();
	void increaseEXP(int val);
	int getLevelUpEXP();
	void increaseLevelUpEXP(int val);
	
	//others
	void addingStatusPoint();

	/************************************************
	 * I made the battle be friend of Heroclass,	*
	 * cos I need change lot for herostatus 		*
	 ************************************************/
	friend void battleAnimationWait(HeroStatus* heroStatus, EnemyStatus* enemyStatus);
	friend void damageCalcu(HeroStatus* heroStatus, EnemyStatus* enemyStatus);
	friend void battleAnimationHit(HeroStatus* heroStatus, EnemyStatus* enemyStatus);
	friend void battleReward(HeroStatus* heroStatus, Bag* bag, int step);

	//overloading input and output opera for save
	friend ostream& operator <<(ostream& saved, const HeroStatus& heroStatus);
	//remember here input operator dont need const
	friend istream& operator >>(istream& load, HeroStatus& heroStatus);
};

void openAnimation();

#endif