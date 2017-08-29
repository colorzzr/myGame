#include <iostream>
#include <cstdlib>

#include "heroStatus.h"

using namespace std;

HeroStatus::HeroStatus(){
	heroHPMax = 20;
	heroHPNow = 20;
	EXP = 0;
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

void HeroStatus::printStatus(){
	cout << "************************"  << endl;
    cout << "* STR:"<< STR <<"  * PhyDF:"<< physicalDefense << "    *" << endl;
    cout << "* INT:"<< INTE <<"  * MagDF:"<< magicDefense << "    *" << endl;
    cout << "* LUC:"<< LUC <<"  *  SKP:" << skillPoint << "    *" << endl;
    cout << "* AGI:"<< AGI <<"  *             *"  << endl;
    cout << "************************" << endl;
    cout << "Press any key to return" << endl;
    char temp;
    cin >> temp;
}

void HeroStatus::levelUp(){
	level++;
	EXP = EXP - levelUpEXP;
	levelUpEXP = levelUpEXP + level * level / 2;
	skillPoint = skillPoint + 2;
	heroHPMax = heroHPMax + 3;
	heroHPNow = heroHPMax;

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

int HeroStatus::getLevel(){
	return level;
}

void HeroStatus::changeLevel(int val){
	level = val;
}

int HeroStatus::getEXP(){
	return EXP;
}

void HeroStatus::increaseEXP(int val){
	EXP = EXP + val;
}

int HeroStatus::getLevelUpEXP(){
	return levelUpEXP;
}

void HeroStatus::increaseLevelUpEXP(int val){
	levelUpEXP = levelUpEXP + val;
}



