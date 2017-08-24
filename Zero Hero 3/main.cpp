#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>

#include "field/field.h"

using namespace std;

int main(int argc, char** argv){
	//print the greeting
	cout << "----------Zero Hero 3----------" << endl;
	cout << "press enter to continue" << endl;
	while(1){
		if(cin.get() == '\n'){
			break;
		}
	}
	system("clear");
	Field* map = new Field;
	bool finished = false;

	//starting game
	map->getHeroLoc();
	while(finished != true){
		map->printField();
	}

	return 0;
}