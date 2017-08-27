#include <iostream>
#include <cstdlib>

#include "enemyStatus.h"

using namespace std;
//initial status enemy would be stronger as level up
EnemyStatus::EnemyStatus(){
	enemyHPMax = 5;
	attack = 3;
	defence = 1;
}

EnemyStatus::~EnemyStatus(){

}

void EnemyStatus::enemyLvUp(){
	return;
}
