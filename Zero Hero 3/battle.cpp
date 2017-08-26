#include <iostream>
#include <cstdlib>

#include "./status/heroStatus.h"
#include "./extraFunction.h"

using namespace std;

void sleep(int s) ;
void battleAnimation(HeroStatus* heroStatus){
	cout << "***********************************" << endl;
   	cout << "*   0         1      *" << endl;
    cout << "*  /|\\       /|\\     * attack:" << endl;
    cout << "*  / \\       / \\     * defence" << endl;
	cout << "***********************************" << endl;
	cout << "* HP: " << heroStatus->heroHPNow << " / " << heroStatus->heroHPMax << " * (a)Attack | (i)Items  *" << endl;
	//change coin to another status later
    cout << "* Coin: " << heroStatus->coin << "     * (s)Skills | (e)Escape *" << endl;
    cout << "***************************************" << endl;
}

void openAnimation(){
	cout << "♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥" << endl;
    cout << "♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥" << endl;
    cout << "♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥" << endl;
    cout << "♥♥ ***      *   ********** *   ****  * ♥♥" << endl;
    cout << "♥♥ *  *    * *    *    *   *   *     * ♥♥" << endl;
    cout << "♥♥ * **   *   *   *    *   *   ****  * ♥♥" << endl;
    cout << "♥♥ *   * *******  *    *   *   *       ♥♥" << endl;
    cout << "♥♥ ****  *     *  *    *   *** ****  * ♥♥" << endl;
    cout << "♥♥ ----------------------------------- ♥♥" << endl;
    cout << "♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥" << endl;
    cout << "♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥" << endl;
    cout << "♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥" << endl;
    sleep(1);
    system("clear");
}

