/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Variable.h
 * Author: user
 *
 * Created on March 2, 2017, 6:08 AM
 */

#ifndef VARIABLE_H
#define VARIABLE_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* VARIABLE_H */
//hero status
int heroHPMax = 12, heroHPNow = 12;
int EXP = 14, levelUpEXP = 15, level = 1;
int strenght = 2, intellegent = 2, luck = 2, agilible = 2, skillPoint = 1;
int physicalDefense = 2, magicDefense = 2;

//enemy status
//FIXME Add different type of enemy Armed + power
//this is normal type
int enemyHPMax = 5;
int attack = 3, defence = 1;

//item list
int coin = 0;
int numOfHeals = 1;

//world map    
int row = 10, col = 17;
char worldMap[10][17];


