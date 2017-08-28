#include <iostream>
#include "bagInfo.h"

using namespace std;

Bag::Bag(){
	coin = 0;
	healBottle = 2;
	beanSoup = 0;
}

void Bag::printBagItem(){
	cout << "**************************" << endl;

    cout << "*                        *" << endl;
    cout << "**************************" << endl;
    char command;
    cin >> command;
}

int Bag::getCoin(){
	return coin;
}

void Bag::changeCoin(int val){
	coin = val;
}