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
	friend void battleAnimation(HeroStatus* heroStatus, EnemyStatus* enemyStatus);
};



#endif
