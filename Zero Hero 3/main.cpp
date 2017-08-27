#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>


#include "field/field.h"

using namespace std;


int main(int argc, char** argv){
	system("clear");
	//print the greeting
	cout << "----------Zero Hero 3----------\n" << endl;
	cout << "Press enter to continue\n" << endl;
	while(1){
		if(cin.get() == '\n'){
			break;
		}
	}

	Field* map = new Field;
	bool finished = false;

	//starting game
	map->getHeroLoc();
    system("clear");
	while(finished != true){
		map->printField();
		map->printStatusBar();
		finished = map->controlPanel();
		system("clear");
	}

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
   	
   	

	return 0;
}
