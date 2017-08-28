#ifndef BAGINFO_H
#define BAGINFO_H

class Bag{
private:
	int coin;
	int healBottle;
	int beanSoup;
public:
	Bag();
	~Bag();
	void printBagItem();
	int getCoin();
	void changeCoin(int val);
	void ItemUse(char name);
};

#endif