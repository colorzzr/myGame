#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void clock1(){
	for(int i = 0; i < 19999999; i++);
}

int main(int argc, char const *argv[]){
	ofstream clock;
	ifstream game;
	long int second = 0;
	long int minute = 0;
	long int hour = 0;
	string checking;
	clock.open("./clock.txt");
	game.open("./game.txt");
	clock << "Waiting for Ramdon Number Generator" << endl;

	while(/*checking != "Game" &&*/ checking != "Waiting"){
		game.close();
		game.open("./game.txt");
		game >> checking;
		cout << checking << endl;
		cout << "Waiting for opening game" << endl;
		clock1();
		clock1();
		clock1();
		clock1();
		clock1();
		//clock1();
		system("clear");
	}
	clock << "Waiting for Ramdon Number Generator" << endl;
	clock1();
	clock1();
	clock1();
	clock1();
	clock1();clock1();
	clock1();
	clock1();
	clock1();
	clock1();
	while(1){
		clock.close();
		clock1();
		clock.open("./clock.txt");
		second++;
		if(second == 60){
			second = 0;
			minute++;
		}
		if(minute == 60){
			minute = 0;
			hour++;
		}

		clock << second << minute << hour << endl;
	}

	return 0;
}