#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>


#include "rlutil.h"
#include "field/field.h"
//#include "extraFunction.h"

using namespace std;

void tutouial (Field* map);

//user to choose the New game or Load game
void gameOption(Field* map){
	cout << "    - New game(N)    " << endl;
	cout << "    - Continue(C)    " << endl;
	char command;
	do{
		cin >> command;
		cin.ignore(1000, '\n');
	}
	while(command != 'C' && command != 'c' && command != 'N' && command != 'n');
	
	//load game
	if(command == 'C' || command == 'c'){
		 if(map->loadSaved() == false) {
		 	cout << "You dont have saved slot! " << endl;
		 	map->getHeroLoc();
		 	tutouial(map);
		 }
	}
	//starting game
	else if (command == 'N' || command == 'n') {
		map->getHeroLoc();
		tutouial(map);
	}
    system("clear");
}

//greeting of game
void greeting(){
	system("clear");
	//print the greeting
	cout << "----------Zero Hero 3----------\n" << endl;
	cout << "Press enter to continue\n" << endl;
	while(1){
		if(cin.get() == '\n'){
			break;
		}
	}
	cin.ignore(1000, '\n');
}

void youDie(){
	system("clear");

	rlutil::setColor(4);
	cout << "...\n" << endl;
	sleep(1);
	cout << ".....\n" << endl;
	sleep(1);
	cout << ".........\n" << endl;
	sleep(1);
	cout << "HAHAHAHAH......\n" << endl;
	sleep(1);
	cout << "That is the end. I think...." << endl;
	rlutil::resetColor();
}

//ask user to move up down left right once
void movingTraining (char target, Field* map){
	char command;
	while (command != target) {
		cout << "Please enter the '"<< target <<"' and press 'enter' for moving up." << endl;
		cin >> command;
		cin.ignore(1000, '\n');
		if(command != target) continue;
		map->controlPanel(command);
		map->printField();
		map->changeStep(0);
	}
}

//fucntion for user to engane the battle
void battleTraining (Field* map, int heroLocX, int heroLocY){
	while (map->getMapChar (heroLocX, heroLocY + 1) != '0'){
		map->printField();
		cout << "Well done! now let us engage in battle." << endl;
		cout << "Moving to enemy(1)" << endl;
		map->controlPanel();
		map->changeStep(0);
	}
}

//guide user into bag and use healBottle
void itemUseTrain(Field* map){
	//char command;
	int bottleInBag = map->getHealBottle();
	while (map->getHealBottle() != (bottleInBag - 1)){
		map->printField();
		cout << "Ok now, you are hurted after battle" << endl;
		cout << "Press 'i' go to main list then press 'i' go to item bag." << endl;
		cout << "Press 'h' for checking infomation of healBottle and Use it!." << endl; 
		map->controlPanel();
		map->changeStep(0);

	}
}

//for teaching beginner
void tutouial (Field* map){
	char command;
	int heroLocX, heroLocY;
	heroLocX = map->getHeroLocX();
	heroLocY = map->getHeroLocY();
	//ask user to choose skip
	while(command != 'y' && command != 'n'){
		cout << "Do you want skip tutouial?" << endl;
		cin >> command;
		cin.ignore(1000, '\n');
	}	
	//skip tut
	if(command == 'y') return;
	
	//add guide on the left-top conner
	map->addThingsOnMap(0, 0, 'g');
	map->printField();
	cout << "Hello hero! Welcome to the Digital world!" << endl;
	cout << "I am the guidance, Color !" << endl;
	cout << "Let me introduce the basic command." << endl;
	//moving training
	movingTraining('w', map);
	movingTraining('s', map);
	movingTraining('a', map);
	movingTraining('d', map);
	map->changeStep(0);
	//now tut for battle
	map->addThingsOnMap(heroLocX, heroLocY + 1, '1');
	system("clear");
	battleTraining(map, heroLocX, heroLocY);
	itemUseTrain(map);
	cout << "Congratulations! Now you can explore the world." << endl;
	map->addThingsOnMap(0, 0, '-');
	sleep(1);
	
}

void loadingRamdonNumber(int& seed){
	ofstream game;
	ifstream clock;
	string checking;

	game.open("./game.txt");
	clock.open("./clock.txt");
	game << "Waiting for Ramdon Number Generator" << endl;

	while(checking != "Waiting"){
		clock.close();
		clock.open("./clock.txt");
		sleep(1);
		cout << "Waiting for Ramdon Number Generator" << endl;
		clock >> checking;
		cout << checking << endl;
	}
	game.close();
	game.open("./game.txt");
	clock.close();
	clock.open("./clock.txt");
	game << "Game Started!" << endl;
	sleep(1);
	greeting();
	clock >> seed;
	//cout << checking << endl;
}

int main (int argc, char** argv){
	int seed = 0;
	//loadingRamdonNumber(seed);
	//cout << seed << endl;
	Field* map = new Field;
	bool finished = false;
	gameOption(map);
	while(finished != true){
		map->printField();
		map->printStatusBar();
		finished = map->controlPanel();
		system("clear");
	}   	

	youDie();
	return 0;
}
