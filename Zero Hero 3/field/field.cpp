#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <fstream>

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
	bag = new Bag(step);
	step = 0;
}

Field::~Field(){
	delete heroStatus;
}


//randomly generate enemy base step on map
void Field::generateEnemy(){
	srand(heroLocX * step);
	int enemyX = rand() % 10;
	srand(heroLocY * step);
	int enemyY = rand() % 10;
	srand(heroLocY * heroLocX * step);
	//make probabilaty to 1/5
	if(rand() % 2 == 1 && step > 3){
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

//for user to check the hint or operation
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
				battleReward(heroStatus, bag, step);
				cout << "You win !" << endl;
				break;
			}
			//hero die
			if (heroStatus->getHeroHpNow() <= 0){
				youDie = true;
				break;
			}
		}
		else if(command == 's'){
			heroStatus->printSkill();
		}
	}
         
    //hero level up           
	if(heroStatus->getEXP() >= heroStatus->getLevelUpEXP()){
		cout << "Level Up !!!" << endl;
		 heroStatus->levelUp();
	}
	sleep(1);
	return youDie;
}

void Field::printSkillSet(){
	heroStatus->printSkill();
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
 *  * MP: 5/5   * (e)Equip   *      *
 *	* Coin: 0   * (k)Skill   *		*
 *	* Level: 1  * (s)Status  *		*
 *	* EXP: 0/20 * (o)Save    *		*
 *	**************************		*
 ************************************/
void Field::openMainList(){
	while(true){
		cout << "**************************" << endl;
    	cout << "* HP: " << heroStatus->getHeroHpNow() << "/" << heroStatus->getHeroHpMax() << "  * (i)Items   *" << endl;
    	cout << "* MP: "<< heroStatus->getHeroMpNow() << " / " << heroStatus->getHeroMpMax() << "  * (e)equip   *" << endl;
    	cout << "* Coin: " << bag->getCoin() << "   * (k)Skill   *" << endl;
    	cout << "* Level: " << heroStatus->getLevel() << "  * (s)Status  *" << endl;
    	cout << "* EXP: "<< heroStatus->getEXP() << "/" << heroStatus->getLevelUpEXP() << " * (o)Save    *" << endl;
    	cout << "**************************" << endl;
    	cout << "Press 'q' to go back" << endl;
    	if(step < 2) cout << "Press 'i' and enter to check your items" << endl;
    
    	char command;
		cin >> command;
		if(command == 'q') break;
		else if(command == 'i'){
			//because of fear, we want to be stronger
			//because of fear, we know our bottom line
			bag->printBagItem(heroStatus);
		}
		else if(command == 'k'){
			printSkillSet();

		}
		else if (command == 's'){
			heroStatus->printStatus();
			system("clear");
		}
		//for ouput the variable
		else if (command == 'o'){
			ofstream saved;
			saved.open("saved");
			//save field info
			for(int i = 0; i < 10; i++){
				for (int j = 0; j < 10; j++){
					if(map[i][j] == '1') saved << i << " " << j << endl;
				}
			}
			saved << 10 << " " << 10 << endl;
			saved << heroLocX << " " << heroLocY << endl;
			//save heroStatus and bag info
			saved << (*heroStatus);
			saved << (*bag);
			system("clear");
			cout << "saved!!" << endl;
			sleep(1);
			system("clear");
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

//below is overload for tut
char Field::controlPanel(char input){
    char command = input;
    int youDie = false;
    while(command != 'w' && command != 's'&& command != 'a'&& command != 'd'&& command != 'i'&& command != 'H'){
    	cin >> command;
    };
    
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

    return command;
}


bool Field::loadSaved(){
	ifstream load;
	int col, row;
	load.open("saved");
	if(load.is_open() == false) return false;
	else{
		//load map
		do{
			load >> row >> col;
			map[row][col] = '1';
		}while(row != 10);
		load >> heroLocX >> heroLocY;
		map[heroLocX][heroLocY] = '0';
		//load the heroStatus and it is a pointer
		load >> (*heroStatus);
		load >> (*bag);
		return true;
	}

}

int Field::getHeroLocX(){
		return heroLocX;
}

int Field::getHeroLocY(){
	return heroLocY;
}

//this function is just for tutourial to control steps
void Field::changeStep(int input){
	step = input;
}

//for edit the map
void Field::addThingsOnMap(int row, int col, char chara){
	map[row][col] = chara;
}

//check the map
char Field::getMapChar(int row, int col){
	return map[row][col];
}

//check the healBottle inside bag
int Field::getHealBottle(){
	return bag->getHealBottle();
}