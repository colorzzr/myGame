#ifndef SKILL_H
#define SKILL_H

#include <map>
#include <cstdlib>
#include <iostream>

//
using namespace std;

enum Skill{
	strongAttack,
	recover,
	deathHit,
	divineShield
	//battleCry
};

/***********************************************
 * So the idea is the emun can not be printed  *
 * So I used one map<> to turn it into string  *
 * Then cos I need to store the what skill 	   *
 * hero learned. I used another map<> to turn  *
 * it into integer. Finally I can use int to   *
 * present skill.							   *
 ***********************************************/
 //check for using struct
class SkillPhaser{
	map<Skill, string> skill2String;
	//this is for list the skill
	map<Skill, int> skill2Int;
	map<int, Skill> int2Skill;
	/************************************
	 * it is like a heap				*
	 * 		|skill5| <-numOfSkill		*
	 *		|skill4|					*
	 *		|skill3|					*
	 *		|skill2|					*
	 *		|skill1|					*
	 *		no skill <-skillHeroHave	*
	 * once hero learned skill 			*
	 * the skillHeroHave would add 1	*
	 * so it move up and map[] can use 	*
	 * skillHeroHave to add skill1  	*
	 ************************************/
	int numOfSkill;
	int skillHeroHave;
public:
	SkillPhaser();

	/****************************************************************
	 * print the skill list hero have one by one and followed by.	*
	 * checking detail of skill	 									*
	 ****************************************************************/
	void printSkill();
	void detailOfSkill();

	void learnedSkill();

	int getSkillHeroHave();

	void battleSkillChoose();
	//friend int chooseSkill(HeroStatus* heroStatus);

	friend ostream& operator <<(ostream& saved, const SkillPhaser& skillPhaser);
	
	//remember here input operator dont need const
	friend istream& operator >>(istream& load, SkillPhaser& skillPhaser);
};

#endif

