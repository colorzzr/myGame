#ifndef SKILL_H
#define SKILL_H


enum Skill{
	strongAttack,
	recover
};

//use linkList to store the skill
struct SkillNode{
	Skill skillName;
	SkillNode* next;

};

#endif

/*
void SkillNode::skillInfo(){
	if(skillName == strongAttack) cout << "hhhhh" << endl;
}*/