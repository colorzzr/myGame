#include <iostream>
#include <cstdlib>
#include "bagInfo.h"


using namespace std;
class HeroStatus;

Bag::Bag(){
	coin = 0;
	healBottle = 2;
	beanSoup = 1;
}

Bag::~Bag(){

}

//function to ask use whether thwy want use item
void Bag::ItemUse(char name, HeroStatus* heroStatus){
	char command;
	while(1){
		if(name == 'h' || name == 'H'){
			cout << "***********************" << endl;
        	cout << "* not very useful     *" << endl;
    	    cout << "* but can heal 5 HP   *" << endl;
	        cout << "***********************" << endl;
        	cout << "Do you want use it ? (Y/N)" << endl;
        	cin >> command;
        	if (command == 'Y' || command == 'y'){
        		//make sure user cannot use even they dont have bottle
        		if(healBottle <= 0) cout << "You dont have enough bottle!" << endl;
        		else{
        			healBottle--;
        			//cannot exceed the max
        			if((heroStatus->getHeroHpNow() + 5) > heroStatus->getHeroHpMax()) 
        				heroStatus->changeHeroHpNow(heroStatus->getHeroHpMax());
        			else heroStatus->changeHeroHpNow(heroStatus->getHeroHpNow() + 5);
        			cout << "HP 5+++++++++++++++++" << endl;
        		}
        		break;
        	}
        	else if (command == 'N' || command == 'n') break;
		}
		else if(name == 'b' || name == 'B'){
			cout << "***********************" << endl;
        	cout << "* Can heal hero better*" << endl;
    	    cout << "* Restore 12 HP        *" << endl;
	        cout << "***********************" << endl;
        	cout << "Do you want use it ? (Y/N)" << endl;
        	cin >> command;
        	if (command == 'Y' || command == 'y'){
        		//make sure user cannot use even they dont have bottle
        		if(beanSoup <= 0) cout << "You dont have enough soup!" << endl;
        		else{
        			beanSoup--;
        			//cannot exceed the max
        			if((heroStatus->getHeroHpNow() + 12) > heroStatus->getHeroHpMax()) 
        				heroStatus->changeHeroHpNow(heroStatus->getHeroHpMax());
        			else heroStatus->changeHeroHpNow(heroStatus->getHeroHpNow() + 12);
        			cout << "HP 12+++++++++++++++++" << endl;
        		}
        		break;
        	}
        	else if (command == 'N' || command == 'n') break;
		}
		else break;
	}
	//wo zhen de hao xihuan ta weishenm yaozhem duiwo
	//ta zhen de shi yijin ni le ma
	system("clear");
}

//function print all item inside bag and give option to check info
void Bag::printBagItem(HeroStatus* heroStatus){
	while(1){
		cout << "**************************" << endl;
		if(healBottle > 0) cout << "* Heal bottle x "<< healBottle <<"        *" << endl;
		if (beanSoup > 0) cout << "* Bean soup x " << beanSoup << "          *" << endl;
    	cout << "*                        *" << endl;
    	cout << "**************************" << endl;
    	cout << "Press 'q' to go back" << endl;
    	char usedItemName = 'a';
    	cin >> usedItemName;
    	if (usedItemName == 'q') break;
    	else if (usedItemName != 'a') ItemUse(usedItemName, heroStatus);
	}
}

int Bag::getCoin(){
	return coin;
}

void Bag::changeCoin(int val){
	coin = coin + val;
}

void Bag::changeHealBottle(){
	healBottle++;
}

void Bag::changeBeanSoup(){
	beanSoup++;
}

ostream& operator <<(ostream& saved, const Bag& bag){
	saved << bag.coin << endl;
	saved << bag.healBottle << endl;
	saved << bag.beanSoup << endl;
}

istream& operator >>(istream& load, Bag& bag){
	load >> bag.coin;
    load >> bag.healBottle;
    load >> bag.beanSoup;
}