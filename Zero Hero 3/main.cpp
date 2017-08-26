#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>


#include "field/field.h"

using namespace std;


int main(int argc, char** argv){
	
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
	cout << "HAHAHAHAH......" << endl;
	sleep(1);
	system("clear");
	cout << "That is the end. I think...." << endl;
   	
   	

	return 0;
}
