#include <iostream>
#include "field.h"

using namespace std;

Field::Field(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			map[i][j] = '-';
		}
	}
	//initial for the hero status
	heroStatus = new HeroStatus;
}

Field::~Field(){
	delete heroStatus;
}


//to print the whole world
void Field::printField(){
	cout <<"━━━━━━━━━━━━━━━━━━━━━━" << endl;
	for(int i = 0; i < 10; i++){
		cout << "╏"; 
		for (int j = 0; j < 10; j++){
			cout << " " << map[i][j];
		}
		cout << "╏" << endl;
	}
	cout <<"━━━━━━━━━━━━━━━━━━━━━━" << endl;
}

void Field::getHeroLoc(){
	do{
		cout << "please enter the location X and Y" << endl;
		cin >> heroLocX >> heroLocY;
	}while(heroLocX < 0 && heroLocY < 0);
	heroLocX = heroLocX % 10;
	heroLocY = heroLocY % 10;
	map[heroLocX][heroLocY] = '0';
}