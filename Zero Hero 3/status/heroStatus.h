#ifndef HEROSTATUS_H
#define HEROSTATUS_H

#include "enemyStatus.h"

//for enemyStatus is an argument of function. it need prototype
class EnemyStatus;
class Bag;
class HeroStatus{
private:
	int heroHPMax;
	int heroHPNow;
	int heroMPMax;
	int heroMPNow;
	int EXP;
	int levelUpEXP;
	int level;
	int STR; 
	int INTE;
	int LUC;
	int AGI;
	int skillPoint;
	int physicalDefense;
	int magicDefense;
public:
	HeroStatus();
	~HeroStatus();
	void printStatus();
	//for Hp
	int getHeroHpNow();
	void changeHeroHpNow(int val);
	int getHeroHpMax();
	void changeHeroHpMax(int val);
	//for Mp
	int getHeroMpNow();
	void changeHeroMpNow(int val);
	int getHeroMpMax();
	void changeHeroMpMax(int val);
	//for level
	int getLevel();
	void changeLevel(int val);
	void levelUp();
	//for exp
	int getEXP();
	void increaseEXP(int val);
	int getLevelUpEXP();
	void increaseLevelUpEXP(int val);
	//others
	void addingStatusPoint();
	friend void battleAnimationWait(HeroStatus* heroStatus, EnemyStatus* enemyStatus, int enemyHpNow);
	friend int damageCalcu(HeroStatus* heroStatus, EnemyStatus* enemyStatus, int enemyHpNow);
	friend void battleAnimationHit(HeroStatus* heroStatus, EnemyStatus* enemyStatus, int enemyHpNow);
	friend void battleReward(HeroStatus* heroStatus, Bag* bag, int step);
	friend ostream& operator <<(ostream& saved, const HeroStatus& heroStatus);
	//remember here input operator dont need const
	friend istream& operator >>(istream& load, HeroStatus& heroStatus);
};

void openAnimation();

#endif