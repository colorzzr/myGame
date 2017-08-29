#ifndef BAGINFO_H
#define BAGINFO_H

#include "../status/heroStatus.h"

class HeroStatus;
class Bag{
private:
	int coin;
	int healBottle;
	int beanSoup;
public:
	Bag();
	~Bag();
	void printBagItem(HeroStatus* heroStatus);
	int getCoin();
	void changeCoin(int val);
	void ItemUse(char name, HeroStatus* heroStatus);
	friend void battleReward(HeroStatus* heroStatus, Bag* bag);
};

#endif