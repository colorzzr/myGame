#ifndef ENEMYSTATUS_H
#define ENEMYSTATUS_H

using namespace std;

#include "heroStatus.h"
//for HeroStatus is an argument of function. it need prototype
class HeroStatus;
class EnemyStatus{
private:
	int enemyHPMax;
	int enemyHPNow;
	int attack;
	int defence;
public:
	EnemyStatus();
	~EnemyStatus();
	void enemyLvUp();
	int getEnemyHpMax();
	int getEnemyHpNow();
	void setEnemyHpNow(int input);
	//function would reset the hp to max
	void resetEnemyHp();
	friend void battleAnimationWait(HeroStatus* heroStatus, EnemyStatus* enemyStatus);
	friend void damageCalcu(HeroStatus* heroStatus, EnemyStatus* enemyStatus);
	friend void battleAnimationHit(HeroStatus* heroStatus, EnemyStatus* enemyStatus);
};



#endif
