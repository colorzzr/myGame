#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>


#include "field/field.h"

using namespace std;

//user to choose the New game or Load game
void gameOption(Field* map){
	cout << "    - New game(N)    " << endl;
	cout << "    - Continue(C)    " << endl;
	char command = 'a';
	cin >> command;
	//load game
	if(command == 'C' || command == 'c'){
		 if(map->loadSaved() == false) {
		 	cout << "You dont have saved slot! " << endl;
		 	map->getHeroLoc();
		 }
	}
	//starting game
	else if (command == 'N' || command == 'n') map->getHeroLoc();
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
}

void youDie(){
	system("clear");
	cout << "...\n" << endl;
	sleep(1);
	cout << ".....\n" << endl;
	sleep(1);
	cout << ".........\n" << endl;
	sleep(1);
	cout << "HAHAHAHAH......\n" << endl;
	sleep(1);
	cout << "That is the end. I think...." << endl;
}

void movingTraining (char target, Field* map){
	char command;
	while (command != target) {
		cout << "Please enter the '"<< target <<"' and press 'enter' for moving up" << endl;
		cin >> command;
		map->controlPanel(command);
		map->printField();
		map->changeStep(0);
	}
}

void battleTraining (Field* map, int heroLocX, int heroLocY){
	while (map->getMapChar(heroLocX, heroLocY) != 0){
		map->printField();
		cout << "Well done! now let us engage in battle" << endl;
		cout << "Moving to enemy(1)" << endl;
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
	cout << "Do you want skip tutouial?" << endl;
	while(command != 'y' && command != 'n'){
	cin >> command;
	}	
	//skip tut
	if(command == 'y') return;
	

	map->printField();
	cout << "Hello hero! Welcome to the Digital world!" << endl;
	cout << "I am the guidance, Color !" << endl;
	cout << "Let me introduce the basic command" << endl;
	//moving training
	movingTraining('w', map);
	movingTraining('s', map);
	movingTraining('a', map);
	movingTraining('d', map);
	map->changeStep(0);
	//now tut for battle
	map->addEnemy(heroLocX, heroLocY + 1);
	system("clear");
	battleTraining(map, heroLocX, heroLocY);
	cin >> command;
}

int main(int argc, char** argv){
	greeting();
	Field* map = new Field;
	bool finished = false;
	gameOption(map);
	tutouial(map);
	while(finished != true){
		map->printField();
		map->printStatusBar();
		finished = map->controlPanel();
		system("clear");
	}   	

	youDie();
	return 0;
}
