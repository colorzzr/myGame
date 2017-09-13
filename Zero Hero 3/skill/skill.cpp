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
	skill2String[strongAttack] = "strongAttack";
	numOfSkill++;
	
	//recover
	int2Skill[2] = recover;
	skill2String[recover] = "recover";
	numOfSkill++;

	//deathHit
	int2Skill[3] = deathHit;
	skill2String[deathHit] = "deathHit";
	numOfSkill++;

	//divineShield
	int2Skill[4] = divineShield;
	skill2String[divineShield] = "divineShield";
	numOfSkill++;



}

void SkillPhaser::printPhaser(){
	for(int i = 1; i <= skillHeroHave; i++){
		cout << skill2String[int2Skill[i]] << endl;
	}
}

void SkillPhaser::learnedSkill(){
	skillHeroHave++;
}