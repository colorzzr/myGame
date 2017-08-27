#include <iostream>
#include <cstdlib>

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
	enemyStatus = new EnemyStatus;
	step = 0;
}

Field::~Field(){
	delete heroStatus;
}


void Field::generateEnemy(){
	srand(heroLocX * step);
	int enemyX = rand() % 10;
	srand(heroLocY * step);
	int enemyY = rand() % 10;
	srand(heroLocY * heroLocX * step);
	//make probabilaty to 1/5
	if(rand() % 5 == 1){
		if(enemyX != heroLocX && enemyY != heroLocY){
			map[enemyX][enemyY] = '1';
		}
		else{
			map[enemyX + 1][enemyY] = '1';
		}
	}
}

//to print the whole world
void Field::printField(){
	cout << "▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁" << endl;
	for(int i = 0; i < 10; i++){
		cout << "╏";
		for (int j = 0; j < 10; j++){
			cout << " " << map[i][j];
		}
		cout << "╏" << endl;
	}
	cout << "━━━━━━━━━━━━━━━━━━━━━━" << endl;
	generateEnemy();
	step++;
}

void Field::printHint(){
	cout << "**********************" << endl;
	cout << "* Hit i for item bar *" << endl;
	cout << "**********************" << endl;
}

void Field::printStatusBar(){
	cout << "Hp:" << heroStatus->getHpNow() << "/" << heroStatus->getHpMax() << endl;
	cout << "Coin:" << heroStatus->getCoin() << endl;
	cout << "Hint H(capital!!!) for hint" << endl;
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

//note here more battle animation is inside the battle.cpp
bool Field::battleEngage(){
	bool finished = false;
	bool youDie = false;
	char command;
	openAnimation();
	battleAnimation(heroStatus, enemyStatus);
	while(finished != true){
		cin >> command;
		if(command == 'e') break;
	}
                    

	return youDie;
}



bool Field::controlPanel(){
    char command;
    int youDie = false;
    cin >> command;
    system("clear");
    if(command == 'w') {
    	if(heroLocX > 0){
    		//engage battle
    		if(map[heroLocX - 1][heroLocY] == '1') youDie = battleEngage(); 
    		map[heroLocX][heroLocY] = '-';
    		heroLocX--;
    		map[heroLocX][heroLocY] = '0';   		
    	}
    }
    else if(command == 's') {
    	if(heroLocX < 9){
    		if(map[heroLocX + 1][heroLocY] == '1') youDie = battleEngage(); 
    		map[heroLocX][heroLocY] = '-';
    		heroLocX++;
    		map[heroLocX][heroLocY] = '0';
    	}
    }
    else if(command == 'a') {
    	if(heroLocY > 0){
    		if(map[heroLocX][heroLocY - 1] == '1') youDie = battleEngage(); 
    		map[heroLocX][heroLocY] = '-';
    		heroLocY--;
    		map[heroLocX][heroLocY] = '0';
    	}
    }
    else if(command == 'd') {
    	if(heroLocY < 9){
    		if(map[heroLocX][heroLocY + 1] == '1') youDie = battleEngage(); 
    		map[heroLocX][heroLocY] = '-';
    		heroLocY++;
    		map[heroLocX][heroLocY] = '0';
    	}
    }
    else if(command == 'H'){
    	printHint();
    }
    return youDie;
}