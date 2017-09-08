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
    cout << "* LUC:"<< LUC <<"  * SKP:" << skillPoint << "    *" << endl;
    cout << "* AGI:"<< AGI <<"  *             *"  << endl;
    cout << "************************" << endl;
    cout << "Press any key to return" << endl;
    char temp;
    cin >> temp;
}


void HeroStatus::addingStatusPoint(){
	//add for status point 
	cout << skillPoint << "skillPoint left" << endl;
	cout << "Press S for STR, I for INTE, A for AGI, L for LUC" << endl;
	char command = 'a';
	while(command != 'S' && command != 'I' && command != 'A' && command && 'L'){
		cin >> command;
	}
	if(command == 'S') {
		STR++;
		skillPoint--;	
	}
	else if(command == 'I'){
		INTE++;
		skillPoint--;
	}
	else if(command == 'A'){
		AGI++;
		skillPoint--;
	}
	else if (command == 'L'){
		LUC++;
		skillPoint--;
	}
	
	//refresh
	physicalDefense = STR * 0.6 + LUC * 0.2 + AGI * 0.1;
	magicDefense = STR * 0.2 + LUC * 0.6 + AGI * 0.15;
}

void HeroStatus::levelUp(){
	level++;
	EXP = EXP - levelUpEXP;
	levelUpEXP = levelUpEXP + level * level / 2;
	skillPoint = skillPoint + 2;
	heroHPMax = heroHPMax + 3;
	heroHPNow = heroHPMax;
	while(skillPoint != 0){
		addingStatusPoint();
	}
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

//overloading the << operator for saved option
ostream& operator <<(ostream& saved, const HeroStatus& heroStatus){
	saved << heroStatus.heroHPMax << endl;
	saved << heroStatus.heroHPNow << endl;
	saved << heroStatus.EXP << endl;
	saved << heroStatus.levelUpEXP << endl;
	saved << heroStatus.level << endl;
	saved << heroStatus.STR << endl; 
	saved << heroStatus.INTE << endl;
	saved << heroStatus.LUC << endl;
	saved << heroStatus.AGI << endl;
	saved << heroStatus.skillPoint << endl;
	saved << heroStatus.physicalDefense << endl;
	saved << heroStatus.magicDefense << endl;
}

istream& operator >>(istream& load, HeroStatus& heroStatus){
	load >> (heroStatus.heroHPMax);
	load >> (heroStatus.heroHPNow);
	load >> (heroStatus.EXP);
	load >> (heroStatus.levelUpEXP);
	load >> (heroStatus.level);
	load >> (heroStatus.STR); 
	load >> (heroStatus.INTE);
	load >> (heroStatus.LUC);
	load >> (heroStatus.AGI);
	load >> (heroStatus.skillPoint);
	load >> (heroStatus.physicalDefense);
	load >> (heroStatus.magicDefense);
	return load;
}
