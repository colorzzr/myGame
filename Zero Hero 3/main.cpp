#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>


#include "field/field.h"

using namespace std;

//user to choose the New game or Load game
void gameOption(Field* map){
	cout << "    - New game    " << endl;
	cout << "    - Continue    " << endl;
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

int main(int argc, char** argv){
	greeting();

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
