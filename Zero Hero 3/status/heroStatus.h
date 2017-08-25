#ifndef HEROSTATUS_H
#define HEROSTATUS_H

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
	int getHpNow();
	int getHpMax();
	int getCoin();
};

#endif