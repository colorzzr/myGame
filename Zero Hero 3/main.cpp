#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <curses.h>

#include "field/field.h"

using namespace std;

void controlPanel(){
	char command = getch();
	cout << command << endl;

}

int main(int argc, char** argv){
	//print the greeting
	/*cout << "----------Zero Hero 3----------" << endl;
	cout << "Press enter to continue" << endl;
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
		controlPanel();
	}*/
	initscr();					//screen clear here
    cbreak();					//change to cbreak mode
    noecho();					//control whether characters typed by the user are echoed by getch(here is no enter)
    scrollok(stdscr, TRUE);		//enable or disable scrolling on a window.
    //nodelay(stdscr, false);		//enable or disable waiting for user input during read but it with enter
    while (true) {
        if (getch() == 'g') {
            printw("You pressed G\n");
        }
        napms(500);
        printw("Running\n");
    }
	

	return 0;
}
