#ifndef ENEMYSTATUS_H
#define ENEMYSTATUS_H

#include "heroStatus.h"
//for HeroStatus is an argument of function. it need prototype
class HeroStatus;
class EnemyStatus{
private:
	int enemyHPMax;
	int attack;
	int defence;
public:
	EnemyStatus();
	~EnemyStatus();
	void enemyLvUp();
	int getEnemyHpMax();
	friend void battleAnimationWait(HeroStatus* heroStatus, EnemyStatus* enemyStatus, int enemyHpNow);
	friend int damageCalcu(HeroStatus* heroStatus, EnemyStatus* enemyStatus,int enemyHpNow);
	friend void battleAnimationHit(HeroStatus* heroStatus, EnemyStatus* enemyStatus, int enemyHpNow);
};



#endif
