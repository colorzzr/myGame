#include <iostream>
#include <cstdlib>

#include "enemyStatus.h"

using namespace std;
//initial status enemy would be stronger as level up
EnemyStatus::EnemyStatus(){
	enemyHPMax = 5;
	enemyHPNow = enemyHPMax;
	attack = 3;
	defence = 1;
}

EnemyStatus::~EnemyStatus(){

}

void EnemyStatus::enemyLvUp(){
	return;
}

int EnemyStatus::getEnemyHpMax(){
	return enemyHPMax;
}

int EnemyStatus::getEnemyHpNow(){
	return enemyHPNow;
}

void EnemyStatus::setEnemyHpNow(int input){
	enemyHPNow = input;
}

void EnemyStatus::resetEnemyHp(){
	enemyHPNow = enemyHPMax;
}