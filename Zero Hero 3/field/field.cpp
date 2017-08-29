#include <iostream>
#include <cstdlib>
#include <stdio.h>

#include "field.h"


using namespace std;



Field::Field(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			map[i][j] = '-';
		}
	}
	//initial for all
	heroStatus = new HeroStatus;
	enemyStatus = new EnemyStatus;
	bag = new Bag;
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
	if(rand() % 2 == 1){
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
	cout << "***********************" << endl;
	cout << "* Hit i for main list *" << endl;
	cout << "***********************" << endl;
}

void Field::printStatusBar(){
	cout << "Hp:" << heroStatus->getHeroHpNow() << "/" << heroStatus->getHeroHpMax() << endl;
	cout << "Coin:" << bag->getCoin() << endl;
	cout << "Hint H(capital!!!) for hint" << endl;
}

void Field::getHeroLoc(){
	int number;
	do{
		cout << "please enter the location X and Y" << endl;
		number = scanf("%d%d", &heroLocX, &heroLocY);
		//clear the buffer
		setbuf(stdin, NULL);
	}while(number != 2);
	heroLocX = heroLocX % 10;
	heroLocY = heroLocY % 10;
	map[heroLocX][heroLocY] = '0';
}

//note here more battle animation is inside the battle.cpp
bool Field::battleEngage(){
	bool youDie = false;
	int enemyHpNow = enemyStatus->getEnemyHpMax();
	char command;
	openAnimation();
	while(1){
		battleAnimationWait(heroStatus, enemyStatus, enemyHpNow);
		cin >> command;
		//escape
		if(command == 'e') break;
		//attack
		else if(command == 'a'){
			battleAnimationHit(heroStatus,enemyStatus,enemyHpNow);
			enemyHpNow = damageCalcu(heroStatus, enemyStatus, enemyHpNow);
			if (enemyHpNow <= 0) {
				battleReward(heroStatus, bag);
				break;
			}
			//hero die
			if (heroStatus->getHeroHpNow() <= 0){
				youDie = true;
				break;
			}
		}
	}
                    

	return youDie;
}

/************************************
 * main list structure				*
 * and it can load into sublist:	*
 * - item (bag)						*
 * - skill set (skill)				*
 * - hero status (status)			*
 * - save game (save)				*
 *	**************************		*
 *	* HP: 20/20 * (i)Items   *		*
 *	* Coin: 0   * (k)Skill   *		*
 *	* Level: 1  * (s)Status  *		*
 *	* EXP: 0/20 * (o)Save    *		*
 *	**************************		*
 ************************************/
void Field::openMainList(){
	while(true){
		cout << "**************************" << endl;
    	cout << "* HP: " << heroStatus->getHeroHpNow() << "/" << heroStatus->getHeroHpMax() << "  * (i)Items   *" << endl;
    	cout << "* Coin: " << bag->getCoin() << "   * (k)Skill   *" << endl;
    	cout << "* Level: " << heroStatus->getLevel() << "  * (s)Status  *" << endl;
    	cout << "* EXP: "<< heroStatus->getEXP() << "/" << heroStatus->getLevelUpEXP() << " * (o)Save    *" << endl;
    	cout << "**************************" << endl;
    	cout << "Press 'q' to go back" << endl;
    
    	char command;
		cin >> command;
		if(command == 'q') break;
		else if(command == 'i'){
			//because of fear, we want to be stronger
			//because of fear, we know our bottom line
			bag->printBagItem(heroStatus);
		}
		else if(command == 'k'){

		}
		else if (command == 's'){
			heroStatus->printStatus();
			system("clear");
		}
		else if (command == 'o'){

		}
	}
}



bool Field::controlPanel(){
    char command;
    int youDie = false;
    do{
    cin >> command;
    }while(command != 'w' && command != 's'&& command != 'a'&& command != 'd'&& command != 'i'&& command != 'H');
    system("clear");

    //for moving
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
    //open the package
    else if(command == 'i'){
    	openMainList();
    }
    //open hint
    else if(command == 'H'){
    	printHint();
    }

    return youDie;
}