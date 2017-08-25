#include <iostream>
#include <cstdlib>

#include "heroStatus.h"

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