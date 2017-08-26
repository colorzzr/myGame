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
	void changeHpNow(int val);
	int getHpMax();
	void changeHpMax(int val);
	int getCoin();
	void changeCoin(int val);
	friend void battleAnimation(HeroStatus* heroStatus);
};

void openAnimation();

#endif