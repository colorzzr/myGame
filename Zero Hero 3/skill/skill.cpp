#include <iostream>
	
#include "skill.h"
#include <map>

using namespace std;

SkillPhaser::SkillPhaser(){
	//0 indicate hero has no skill
	skillHeroHave = 0;
	//starting at 0
	numOfSkill = 1;

	//strongAttack
	int2Skill[1] = strongAttack;
	skill2Int[strongAttack] = 1;
	skill2String[strongAttack] = "strongAttack";
	numOfSkill++;
	
	//recover
	int2Skill[2] = recover;
	skill2Int[recover] = 2;
	skill2String[recover] = "recover";
	numOfSkill++;

	//deathHit
	int2Skill[3] = deathHit;
	skill2Int[deathHit] = 3;
	skill2String[deathHit] = "deathHit";
	numOfSkill++;

	//divineShield
	int2Skill[4] = divineShield;
	skill2Int[divineShield] = 4;
	skill2String[divineShield] = "divineShield";
	numOfSkill++;



}

/****************************************************
 * function is to print the skill as following:		*
 * *****************								*
 * *   skill1   1  *								*
 * *   skill2   2  *								*
 * *   skill3   3  *								*
 * *****************								*
 * which skill you want to check(input number)?
 ****************************************************/
void SkillPhaser::printSkill(){
	cout << "**********************" << endl;
	cout << "* Skill List         *" << endl;
	for(int i = 1; i <= skillHeroHave; i++){
		cout << "*   -" << skill2String[int2Skill[i]] << " "<< i <<"  *" << endl;
	}
	cout << "**********************" << endl;
}

void SkillPhaser::detailOfSkill(){
	//ask user to check skill
	int cmd = 99;
	cout << "which skill you want to check?(input number '0' to exit)" << endl;
	//to avoid reading detail when hero dont have
	while(cmd > skillHeroHave){
		cin >> cmd;
	}
	switch(cmd){
		//just kick out the loop
		case 0:
		system("clear");
		break;

		//case 1: strong attack
		case 1:
		cout << "*********************" << endl;
		cout << "* strongAttack:     *" << endl;
		cout << "* Cost: 1 Mp        *" << endl;
		cout << "*********************" << endl;
		cout << "* Damage: 3 + STR   *" << endl;
		cout << "*********************" << endl;
		cout << "Press any key to return" << endl;
		cin >> cmd;
		system("clear");
		break;

		//case 2: recover
		case 2:
		cout << "*********************" << endl;
		cout << "* recover:          *" << endl;
		cout << "* Cost: 2 Mp        *" << endl;
		cout << "*********************" << endl;
		cout << "* Heal: 5 Hp        *" << endl;
		cout << "*********************" << endl;
		cout << "Press any key to return" << endl;
		cin >> cmd;
		system("clear");
		break;

		//case 3: death hit
		case 3:
		cout << "*********************" << endl;
		cout << "* deathHit:         *" << endl;
		cout << "* Cost: 1 Mp + 3 Hp *" << endl;
		cout << "*********************" << endl;
		cout << "* Damage : 6 + STR  *" << endl;
		cout << "*********************" << endl;
		cout << "Press any key to return" << endl;
		cin >> cmd;
		system("clear");
		break;

		//case 4: divine shield
		case 4:
		cout << "*********************" << endl;
		cout << "* divineShield:     *" << endl;
		cout << "* Cost: 2 Mp        *" << endl;
		cout << "*********************" << endl;
		cout << "* immute any Damage *" << endl;
		cout << "*********************" << endl;
		cout << "Press any key to return" << endl;
		cin >> cmd;
		system("clear");
		break;
	}
}

void SkillPhaser::learnedSkill(){
	skillHeroHave++;
}