#ifndef HEROSTATUS_H
#define HEROSTATUS_H

#include "enemyStatus.h"

//for enemyStatus is an argument of function. it need prototype
class EnemyStatus;
class HeroStatus{
private:
	int heroHPMax;
	int heroHPNow;
	int EXP;
	int coin;
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
	int getHeroHpNow();
	void changeHeroHpNow(int val);
	int getHeroHpMax();
	void changeHeroHpMax(int val);
	int getCoin();
	void changeCoin(int val);
	friend void battleAnimationWait(HeroStatus* heroStatus, EnemyStatus* enemyStatus, int enemyHpNow);
	friend int damageCalcu(HeroStatus* heroStatus, EnemyStatus* enemyStatus, int enemyHpNow);
	friend void battleAnimationHit(HeroStatus* heroStatus, EnemyStatus* enemyStatus, int enemyHpNow);
};

void openAnimation();

#endif