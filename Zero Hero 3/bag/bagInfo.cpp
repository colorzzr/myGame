#include <iostream>
#include "bagInfo.h"

using namespace std;

Bag::Bag(){
	coin = 0;
	healBottle = 2;
	beanSoup = 1;
}

void Bag::ItemUse(char name){
	char command;
	if(name == 'h' || name == 'H'){
		cout << "***********************" << endl;
        cout << "* not very useful     *" << endl;
        cout << "* but can heal 5 HP   *" << endl;
        cout << "***********************" << endl;
        cout << "Do you want use it ? (Y/N)" << endl;
        cin >> command;
	}
}

void Bag::printBagItem(){
	while(1){
		cout << "**************************" << endl;
		if(healBottle > 0) cout << "* Heal bottle x "<< healBottle <<"        *" << endl;
		if (beanSoup > 0) cout << "* Bean soup x " << beanSoup << "          *" << endl;
    	cout << "*                        *" << endl;
    	cout << "**************************" << endl;
    	cout << "Press 'q' to go back" << endl;
    	char usedItemName;
    	cin >> usedItemName;
    	if (usedItemName == 'q') break;
	}
}

int Bag::getCoin(){
	return coin;
}

void Bag::changeCoin(int val){
	coin = val;
}