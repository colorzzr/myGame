#include <iostream>
#include <cstdlib>

#include "./status/heroStatus.h"
#include "./status/enemyStatus.h"
#include "./skill/skill.h"
#include "./bag/bagInfo.h"
#include "./extraFunction.h"
#include "rlutil.h"

using namespace std;

void sleep(int s) ;
void battleAnimationWait(HeroStatus* heroStatus, EnemyStatus* enemyStatus){
	cout << "************************************" << endl;
   	cout << "*   0         1      * Hp: " << enemyStatus->enemyHPNow << "/" << enemyStatus->enemyHPMax << "     *" << endl;
    cout << "*  /|\\       /|\\     * attack: " << enemyStatus->attack << "   *" << endl;
    cout << "*  / \\       / \\     * defence: " << enemyStatus->defence << "  *" << endl;
	cout << "***************************************" << endl;
	cout << "* HP: " << heroStatus->heroHPNow << " / " << heroStatus->heroHPMax << " * (a)Attack | (i)Items  *" << endl;
	//change coin to another status later
    cout << "* MP: "<< heroStatus->heroMPNow << " / " << heroStatus->heroMPMax << "   * (s)Skills | (e)Escape *" << endl;
    cout << "***************************************" << endl;
}

void battleAnimationHit(HeroStatus* heroStatus, EnemyStatus* enemyStatus){
    system("clear");
    cout << "************************************" << endl;
    cout << "*   0         1      * Hp: " << enemyStatus->enemyHPNow << "/" << enemyStatus->enemyHPMax << "     *" << endl;
    cout << "*  /|\\";
    //change the color of hit '------>'

    rlutil::setColor(4);
    cout << "------>";
    rlutil::resetColor();

    cout <<"/|\\     * attack: " << enemyStatus->attack << "   *" << endl;
    cout << "*  / \\       / \\     * defence: " << enemyStatus->defence << "  *" << endl;
    cout << "***************************************" << endl;
    cout << "* HP: " << heroStatus->heroHPNow << " / " << heroStatus->heroHPMax << " * (a)Attack | (i)Items  *" << endl;
    //change coin to another status later
    cout << "* MP: "<< heroStatus->heroMPNow << " / " << heroStatus->heroMPMax << "   * (s)Skills | (e)Escape *" << endl;
    cout << "***************************************" << endl;
    sleep(1);
    system("clear");
}

void openAnimation(){
	cout << "♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥" << endl;
    cout << "♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥" << endl;
    cout << "♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥" << endl;
    cout << "♥♥ ***      *   ********** *   ****  ♥♥" << endl;
    cout << "♥♥ *  *    * *    *    *   *   *     ♥♥" << endl;
    cout << "♥♥ * **   *   *   *    *   *   ****  ♥♥" << endl;
    cout << "♥♥ *   * *******  *    *   *   *     ♥♥" << endl;
    cout << "♥♥ ****  *     *  *    *   *** ****  ♥♥" << endl;
    cout << "♥♥ --------------------------------- ♥♥" << endl;
    cout << "♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥" << endl;
    cout << "♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥" << endl;
    cout << "♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥" << endl;
    sleep(1);
    system("clear");

}

void damageCalcu(HeroStatus* heroStatus, EnemyStatus* enemyStatus){
    
    srand(heroStatus->heroHPMax * heroStatus-> heroHPNow);
    //simply strength - defence and some flucuate
    enemyStatus->enemyHPNow = enemyStatus->enemyHPNow - (heroStatus->STR - enemyStatus->defence + (rand() % 3 - 1));
    //here default hero attack first
    if (enemyStatus->enemyHPNow > 0) {
        //simply strength - defence and some flucuate
        heroStatus->heroHPNow = heroStatus->heroHPNow - (heroStatus->physicalDefense + (rand() % 2 - 1));
    }
    //return enemyStatus->enemyHPNow;
}

void battleReward(HeroStatus* heroStatus, Bag* bag, int step){
    srand(heroStatus->getHeroHpNow() + heroStatus->getEXP());
    heroStatus->increaseEXP(rand() % 4 + 2);
    srand(heroStatus->getHeroHpNow() + heroStatus->getEXP());
    bag->changeCoin(rand() % 4 + 1); 
    //for item drop
    srand(bag->getCoin() * step);
    if(rand() % 5 == 2) bag->changeHealBottle();
    srand(step * (bag->getCoin() + 2));
    if(rand() % 9 == 3) bag->changeBeanSoup();
}

