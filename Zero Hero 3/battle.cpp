#include <iostream>
#include <cstdlib>

#include "./status/heroStatus.h"
#include "./status/enemyStatus.h"
#include "./bag/bagInfo.h"
#include "./extraFunction.h"

using namespace std;

void sleep(int s) ;
void battleAnimationWait(HeroStatus* heroStatus, EnemyStatus* enemyStatus, int enemyHpNow){
	cout << "************************************" << endl;
   	cout << "*   0         1      * Hp: " << enemyHpNow << "/" << enemyStatus->enemyHPMax << "     *" << endl;
    cout << "*  /|\\       /|\\     * attack: " << enemyStatus->attack << "   *" << endl;
    cout << "*  / \\       / \\     * defence: " << enemyStatus->defence << "  *" << endl;
	cout << "***************************************" << endl;
	cout << "* HP: " << heroStatus->heroHPNow << " / " << heroStatus->heroHPMax << " * (a)Attack | (i)Items  *" << endl;
	//change coin to another status later
    cout << "* Coin: change!   * (s)Skills | (e)Escape *" << endl;
    cout << "***************************************" << endl;
}

void battleAnimationHit(HeroStatus* heroStatus, EnemyStatus* enemyStatus, int enemyHpNow){
    system("clear");
    cout << "************************************" << endl;
    cout << "*   0         1      * Hp: " << enemyHpNow << "/" << enemyStatus->enemyHPMax << "     *" << endl;
    cout << "*  /|\\------>/|\\     * attack: " << enemyStatus->attack << "   *" << endl;
    cout << "*  / \\       / \\     * defence: " << enemyStatus->defence << "  *" << endl;
    cout << "***************************************" << endl;
    cout << "* HP: " << heroStatus->heroHPNow << " / " << heroStatus->heroHPMax << " * (a)Attack | (i)Items  *" << endl;
    //change coin to another status later
    cout << "* Coin: change!   * (s)Skills | (e)Escape *" << endl;
    cout << "***************************************" << endl;
    sleep(1);
    system("clear");
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

int damageCalcu(HeroStatus* heroStatus, EnemyStatus* enemyStatus, int enemyHpNow){
    
    srand(heroStatus->heroHPMax * heroStatus-> heroHPNow);
    //simply strength - defence and some flucuate
    enemyHpNow = enemyHpNow - (heroStatus->STR - enemyStatus->defence + (rand() % 3 - 1));
    //here default hero attack first
    if (enemyHpNow > 0) {
        //simply strength - defence and some flucuate
        heroStatus->heroHPNow = heroStatus->heroHPNow - (heroStatus->physicalDefense + (rand() % 2 - 1));
    }
    return enemyHpNow;
}

void battleReward(HeroStatus* heroStatus, Bag* bag){
    srand(heroStatus->getHeroHpNow() + heroStatus->getEXP());
    heroStatus->increaseEXP(rand() % 4 + 2);
    srand(heroStatus->getHeroHpNow() + heroStatus->getEXP());
    bag->changeCoin(rand() % 4 + 1); 
}