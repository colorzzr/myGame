#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <time.h>

#include "field/field.h"

using namespace std;


void sleep(int s) 
{ 
    for(int i = 0; i < s * 1000000000; i++); 
} 

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

	}

	system("clear");
	cout << "HAHAHAHAH......" << endl;
	sleep(1);
	system("clear");
	cout << "That is the end. I think...." << endl;
   	
   	

	return 0;
}
