#include <iostream>
#include <cstdlib>

#include "heroStatus.h"

using namespace std;

HeroStatus::HeroStatus(){
	heroHPMax = 20;
	heroHPNow = 6;
	EXP = 0;
	coin = 0;
	levelUpEXP = 20;
	level = 1;
	STR = 5; 
	INTE = 5;
	LUC = 5;
	AGI = 5;
	skillPoint = 0;
	physicalDefense = STR * 0.6 + LUC * 0.2 + AGI * 0.1;
	magicDefense = STR * 0.2 + LUC * 0.6 + AGI * 0.15;
}

HeroStatus::~HeroStatus(){
	
}

int HeroStatus::getHeroHpNow(){
	return heroHPNow;
}

void HeroStatus::changeHeroHpNow(int val){
	heroHPNow = val;
}

int HeroStatus::getHeroHpMax(){
	return heroHPMax;
}

void HeroStatus::changeHeroHpMax(int val){
	heroHPMax = val;
}

int HeroStatus::getCoin(){
	return coin;
}

void HeroStatus::changeCoin(int val){
	coin = val;
}




