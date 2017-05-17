/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: user
 *
 * Created on February 27, 2017, 1:19 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "BattleAnimation.h"
#include "Variable.h"
/***************************************************
 * check check just initialize world to 100x100    *
 * cs 2D array must have size for pass to function *
 ***************************************************/
FILE* save = NULL;
//start the function
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//void BattleAnimation (int *rowLoca, int *colLoca,bool *die, coin);
void PrintMenu ();
void EnemyLevelUp();
void HeroLevelUp();
void PrintDetailStatus();
void BattleAnimation ();
void Shop();
/**************************************
 * build up world structure           *
 * you can change is or add something *
 **************************************/
void BuildMap (){
    //build map
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (j == 0 || j == col - 1){
                worldMap[i][j] = '|';
            }
            else if (i == 0 || i == row - 1){
                worldMap[i][j] = '_';
            }
            else {
                worldMap[i][j] = '-';
            }
        }
    }
    worldMap[5][7] = 'S';
    return ;
}

/****************************************
 * use this function to print out world *
 * without calling nestloop again       *
 ****************************************/
void PrintMap (){
    //print map
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%c", worldMap[i][j]);
        }
        
        printf("\n");
    }
}
/************************************************
 * control panel up->w down->s left->a right->d *
 ************************************************/

void ControlPanel (int *rowLoca, int *colLoca, bool *die, int *heroHPNow, int *heroHPMax, int *coin, int *numOfHeals,int *level, int *EXP, int *levelUpEXP,
                    int *strenght, int *intellegent, int *agilible, int *luck, int *physicalDefense, int *magicDefense, int *skillPoint, int *locX, int *locY, int *enemyHPMax,
                    int *attack, int *defence, int *beanSoup){
    char dir = '1';
    while (dir != 'a'&&dir != 'w'&&dir != 's'&&dir != 'd'&&dir != 'i'){
        scanf(" %c", &dir);
        setbuf(stdin, NULL);    //clear the buffer
    }
    switch (dir){
        //up
        case 'w':
            if ((*rowLoca - 1) >= 1){
                //battle on
                if(worldMap[*rowLoca - 1][*colLoca] == '1'){
                    BattleAnimation(rowLoca, colLoca, die, enemyHPMax, coin, heroHPNow,heroHPMax,numOfHeals,EXP, level, 
                                    levelUpEXP, skillPoint, physicalDefense, attack, defence);
                }
                else if (worldMap[*rowLoca - 1][*colLoca] == 'S'){
                    Shop(coin, numOfHeals, beanSoup, strenght);
                    *rowLoca = *rowLoca + 1;
                    worldMap[*rowLoca][*colLoca] = '0';
                }
                worldMap[*rowLoca][*colLoca] = '-';
                *rowLoca = *rowLoca - 1;
                worldMap[*rowLoca][*colLoca] = '0';
            }
            
            break;
                
        //down
        case 's':
            if ((*rowLoca + 1) <= 8){
                //battle on
                if(worldMap[*rowLoca + 1][*colLoca] == '1'){
                    BattleAnimation(rowLoca, colLoca, die, enemyHPMax, coin, heroHPNow,heroHPMax,numOfHeals,EXP, level, 
                                    levelUpEXP, skillPoint, physicalDefense, attack, defence);
                }
                else if (worldMap[*rowLoca + 1][*colLoca] == 'S'){
                    Shop(coin, numOfHeals, beanSoup, strenght);
                    *rowLoca = *rowLoca - 1;
                    worldMap[*rowLoca][*colLoca] = '0';
                }
                worldMap[*rowLoca][*colLoca] = '-';
                *rowLoca = *rowLoca + 1;
                worldMap[*rowLoca][*colLoca] = '0';
            }
            break;
                
        //left
        case 'a':
            if ((*colLoca - 1) >= 1){
                //battle on
                if(worldMap[*rowLoca][*colLoca - 1] == '1'){
                    BattleAnimation(rowLoca, colLoca, die, enemyHPMax, coin, heroHPNow,heroHPMax, numOfHeals,EXP, level, 
                                    levelUpEXP, skillPoint, physicalDefense, attack, defence);
                }
                else if (worldMap[*rowLoca][*colLoca - 1] == 'S'){
                    Shop(coin, numOfHeals, beanSoup, strenght);
                    *colLoca = *colLoca + 1;
                    worldMap[*rowLoca][*colLoca] = '0';
                }
                worldMap[*rowLoca][*colLoca] = '-';
                *colLoca = *colLoca - 1;
                worldMap[*rowLoca][*colLoca] = '0';
            }
            break;
                
        //right
        case 'd':
            if ((*colLoca + 1) <= 15){
                //battle on
                if(worldMap[*rowLoca][*colLoca + 1] == '1'){
                    BattleAnimation(rowLoca, colLoca, die,enemyHPMax, coin, heroHPNow,heroHPMax,numOfHeals, EXP, level, 
                                    levelUpEXP, skillPoint, physicalDefense, attack, defence, attack, defence);
                }
                else if (worldMap[*rowLoca][*colLoca + 1] == 'S'){
                    Shop(coin, numOfHeals, beanSoup, strenght);
                    *colLoca = *colLoca - 1;
                    worldMap[*rowLoca][*colLoca] = '0';
                }
                worldMap[*rowLoca][*colLoca] = '-';
                *colLoca = *colLoca + 1;
                worldMap[*rowLoca][*colLoca] = '0';
            }    
            break;
                
        //UI interaction
        case 'i':
            PrintMenu(heroHPNow, heroHPMax, coin, numOfHeals,level, EXP, levelUpEXP, strenght, intellegent, agilible,
                     luck, physicalDefense, magicDefense, skillPoint, locX, locY, beanSoup);
            break;
        }
    
        return;
}
/***************************************************
 * function would let user to input their position *
 * and its become the born place of hero           *
 ***************************************************/
void ScanLocation (int *locX, int *locY){
    int x, y, returnScanf = 0;
    //ask user for the location
    printf("Please enter your location x and y(only number): ");
    returnScanf = scanf("%d %d", &x, &y);
    setbuf(stdin, NULL);    //clear the buffer
    while(returnScanf != 2){
        printf("Enter the X and Y number! NUMber!! NUMBER!!!!!!: ");
        returnScanf = scanf("%d %d", &x, &y);
        setbuf(stdin, NULL);    //clear the buffer
    }
    
    //we can not generate hero on the edge
    *locX = x % (row - 2) + 1;
    *locY = y % (col - 2) + 1;
    
    return;
}

/*****************************************************************
 * randonly generate enemy'1' based on location of hero and step *
 *****************************************************************/
void EnemyGenerate (int locX, int locY, int step, int *enemyPosX, int *enemyPosY){
        //generate the enemy
        int seed;
        srand(locX * step);
        *enemyPosX = rand() % (row - 2) + 1;
        srand(locY * step);
        *enemyPosY = rand() % (col - 2) + 1;
        if (*enemyPosY % 5 == 1){
        //can not replace the hero
            if (worldMap[*enemyPosX][*enemyPosY] == '0'){
            
                //FIXME to get another random place
                worldMap[*enemyPosX + 1][*enemyPosY] = '1';
            }
            else if (worldMap[*enemyPosX][*enemyPosY] == 'S'){
                worldMap[*enemyPosX][*enemyPosY + 1] == '1';
            }
            worldMap[*enemyPosX][*enemyPosY] = '1';
        }
    return;
}

/****************************************
 * function would print the hero status *
 * include HP and money                 *
 ****************************************/
void PrintStatus (int HPMax, int HPNow, int coin){
    //print the hero status
    
    printf("HP: %d / %d\n", HPNow, HPMax);
    printf("Coin: %d\n", coin);
    return;
}

/****************************
 * print the menu interface *
 * press u to exit          *
 ****************************/
void PrintMenu (int* heroHPNow, int* heroHPMax, int* coin,int* numOfHeals, int* level, int* EXP, int* levelUpEXP, 
        int* strenght, int* intellegent, int* agilible, int* luck, int *physicalDefense, int *magicDefense, int* skillPoint,
        int *locX, int *locY, int *beanSoup){
    
    char action = '1';
    while (action != 'x'){
        printf("\033c");
        printf( "************************\n"
                "* HP:%2d/%2d  * (i)Items *\n"
                "* Coin: %2d  * (k)Skill *\n"
                "* Level:%2d  * (s)Status*\n"
                "* EXP:%2d/%2d * (o)Save  *\n"
                "************************\n", *heroHPNow, *heroHPMax, *coin, *level, *EXP, *levelUpEXP);
    
        scanf(" %c", &action);
        //UI interaction
        switch(action){
            case 'i':
                printf( "**************************\n"
                        "* heal bottle(1)  x%d  h  *\n"
                        "* bean soup(2)    X%d  b  *\n"
                        "*                        *\n"
                        "*                        *\n"
                        "**************************\n"
                        "* number -> use          *\n"
                        "* letter -> info         *\n"
                        "**************************\n", *numOfHeals, *beanSoup);
                printf("what do you want to do?\n");
                scanf(" %c", &action);
                switch (action){
                    //go back
                    case 'x':
                        PrintMenu(heroHPNow, heroHPMax, coin, numOfHeals,level, EXP, levelUpEXP, strenght, intellegent, agilible, luck, 
                                    physicalDefense, magicDefense, skillPoint, locX, locY, beanSoup);
                        break;
                    
                    //heal
                    case '1':
                        if(*numOfHeals > 0){
                            *heroHPNow = *heroHPNow + 5;
                            *numOfHeals = *numOfHeals - 1;
                            if (*heroHPNow > *heroHPMax) *heroHPNow = *heroHPMax; 
                            printf("HP 5+++++++++++!");
                            scanf(" %c", &action);
                        }
                        else{
                            printf("You dont have enough bottle!");
                            scanf(" %c", &action);
                        }
                        break;
                        
                    case '2':
                        if(*beanSoup > 0){
                            *heroHPNow = *heroHPNow + 12;
                            *beanSoup = *beanSoup - 1;
                            if (*heroHPNow > *heroHPMax) *heroHPNow = *heroHPMax;
                            printf("HP 12+++++++++++!");
                            scanf(" %c", &action);
                        }
                        else {
                            printf("You dont have enough soup!");
                            scanf(" %c", &action);
                        }
                        break;
                        
                    //info of healing bottle
                    case 'h':
                        printf( "***********************\n"
                                "* not very useful     *\n"
                                "* but can heal 5 HP   *\n"
                                "***********************\n"
                                "*   press x to map    *\n"
                                "    (anykey) return   *\n"
                                "***********************\n");
                        scanf(" %c", &action);
                        break;
                    
                    //info of bean soup
                    case 'b':
                        printf( "************************\n"
                                "* can heal hero better *\n"
                                "* heal 12 HP           *\n"
                                "************************\n"
                                "*   press x to map     *\n"
                                "*   (anykey) return    *\n"
                                "************************\n");
                        scanf(" %c", &action);
                        break;
                }
            break;
                
            //open the status view
            case 's':
               PrintDetailStatus(strenght, physicalDefense, intellegent, magicDefense, luck, agilible, skillPoint);
               scanf(" %c", &action);
                //add skill point
                while (*skillPoint > 0 && (action == 'S'||action == 'A'||action == 'I'||action == 'L')){
                    switch (action){
                        //STR
                        case 'S':
                            (*strenght)++;
                            (*skillPoint)--;
                            break;
                        //INT
                        case 'I':
                            (*intellegent)++;
                            (*skillPoint)--;
                            break;
                        //LUC
                        case 'L':
                            (*luck)++;
                            (*skillPoint)--;
                            break;
                        //AGI
                        case 'A':
                            (*agilible)++;
                            (*skillPoint)--;
                            break;
                            
                            printf("\033c");
                            PrintDetailStatus(strenght, physicalDefense, intellegent, magicDefense, luck, agilible, skillPoint);
                            scanf(" %c", &action);
                    }
                    printf("\033c");
                    PrintDetailStatus(strenght, physicalDefense, intellegent, magicDefense, luck, agilible, skillPoint);
                    scanf(" %c", &action);
                }
                break;
                
            //to save the file
            case 'o' :
                //create save file
                save = fopen("/home/user/NetBeansProjects/Zero Hero2/save", "w");
                //save date
                fprintf(save, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
                        *heroHPNow,*EXP, *levelUpEXP, *level,*strenght, *intellegent, *luck, *agilible, *skillPoint,*physicalDefense, *magicDefense, *coin, *locX, *locY);
                //free the pointer
                fclose(save);
                printf("Game Saved!!!");
                break;
                
        }
    }
    
    return;
}

/********************************************
 * function to present the status of hero   *
 * update the critical and miss chance      *
 ********************************************/

void PrintDetailStatus(int *strenght,int *physicalDefense,int *intellegent,int *magicDefense,int *luck,int *agilible, int* skillPoint ){
    printf( "************************\n"
            "* STR:%2d  * PhyDF:%2d    *\n"
            "* INT:%2d  * PowDF:%2d    *\n"
            "* LUC:%2d  *             *\n"
            "* AGI:%2d  *             *\n"
            "* SKP:%2d  *             *\n"
            "************************\n", *strenght, *physicalDefense, *intellegent, *magicDefense, *luck, *agilible, *skillPoint);
    printf( "You have %2d skill point which to add?\n"
            "S->STR  I->INT  L->LUC  A->AGI\n"
            "others go back\n", *skillPoint);
                            
    return;
}

/***************************************
 * function would print out the battle *
 * animation with some interaction     * 
 ***************************************/
void BattleAnimation (int *rowLoca, int *colLoca,bool *die, int *enemyHPMax,int *coin,int *heroHPNow,int *heroHPMax,
                      int* numberOfHeals, int* EXP, int* level,int* levelUpEXP, int* skillPoint, int *physicalDefense,
                      int *attack, int *defence){
    char action = 'h';
    int enemyHPNow = *enemyHPMax;
    int damage = 0;
    
    srand(*rowLoca * *colLoca);
     //print the interval
    printf("\033c");
    //it is too long so I put into Headfile
    BattleInterval();
        
    while(!(enemyHPNow <= 0 || action == 'k')){
       
        //battle on
        printf("\033c");
        printf( "***********************************\n"
                "*   0         1      *  HP:%2d     *\n"
                "*  /|\\       /|\\     * attack:%2d  *\n"
                "*  / \\       / \\     * defence:%2d *\n"
                "***********************************\n", enemyHPNow, *attack, *defence);
    
        printf( "***************************************\n"
                "* HP: %2d / %2d * (u)Attack | (i)Items  *\n"
                "* Coin: %d     * (j)Skills | (k)Escape *\n"
                "***************************************\n", *heroHPNow, *heroHPMax, *coin);
        printf("What do you want ?\n");
        scanf(" %c", &action);
        
        //Attack commend
        if (action == 'u'){
            printf("\033c");
            printf( "***********************************\n"
                "*   0         1      *  HP:%2d     *\n"
                "*  /|\\-----> /|\\     * attack:%2d  *\n"
                "*  / \\       / \\     * defence:%2d *\n"
                "***********************************\n", enemyHPNow, *attack, *defence);
            printf( "***************************************\n"
                    "* HP: %2d / %2d * (u)Attack | (i)Items  *\n"
                    "* Coin: %d     * (j)Skills | (k)Escape *\n"
                    "***************************************\n", *heroHPNow, *heroHPMax, *coin);
            
            //battle algorithm
            //enemy suffer the damage
            enemyHPNow = enemyHPNow + *defence - (rand() % 2 + strenght);
            //cal the damage hero suffer
            damage = *attack - *physicalDefense;
            
            if(enemyHPNow > 0 && damage > 0) *heroHPNow = *heroHPNow - damage;
            sleep(1);
            //you are die!!!!
            if (*heroHPNow <= 0){
                *die = true;
                break;
            }
        }
    }
    
    if (enemyHPNow <= 0){
        //randomly dropping FIXME use fucntion
        *coin = *coin + (rand() % 3 + 1);
        *numberOfHeals = *numberOfHeals + (rand() % 3 / 2);
        *EXP = *EXP + (rand() % 4 + 2);
        //level up
        if (*EXP >= *levelUpEXP){
            HeroLevelUp(EXP, levelUpEXP, level, skillPoint, heroHPMax, heroHPNow, physicalDefense);
            EnemyLevelUp(level, enemyHPMax, attack, defence); 
        }
    }
    return ;
}
//make a function easy for reading when level up 
void HeroLevelUp (int *EXP, int *levelUpEXP, int *level, int *skillPoint, int *heroHPMax, int *heroHPNow, int *physicalDefense){
    *EXP = *EXP - *levelUpEXP;
    (*level)++;
    *levelUpEXP = *levelUpEXP + ((*level) * 2);
    //up the status
    *skillPoint = *skillPoint + 1;
    *heroHPMax = *heroHPMax + 2;
    *heroHPNow = *heroHPNow + 2;
    (*physicalDefense)++;
    return;
}

//the strenght of enemy depends on level of hero
void EnemyLevelUp(int *level, int *enemyHPMax, int *attack, int *defence){
    *enemyHPMax = *enemyHPMax + (*level);
    if((*level) % 2 == 0) (*attack)++;
    if((*level) % 3 == 0) (*defence)++;
    
    return;
}

/********************************
 * update the items in the shop *
 ********************************/
void Shop (int* coin, int* numOfHeals, int* beanSoup, int* strenght){
    char action;
    
    do{
        printf("\033c");
        printf( "********************************\n"
                "*Welcome to the shop!          *\n"
                "********************************\n"
                "* heal bottle(1)--------5 coin *\n"
                "* bean soup(2)---------10 coin *\n"
                "* attack blessing(3)---99 coin *\n"
                "* defense blessing(4)--99 coin *\n"
                "********************************");
        scanf(" %c", &action);
        switch(action){
            //purchase the heal bottle
            case '1':
                if(*coin >= 5){
                    printf("Purchase the one heal bottle!\n");
                    *coin = *coin - 5;
                    *numOfHeals = *numOfHeals + 1;
                    sleep(1);
                }
                else {
                    printf("You dont have enough money");
                    sleep(1);
                }
                    break;
                    
            //purchase the bean soup
            case '2':
                if(*coin >= 10){
                    printf("Purchase the one bean soup!\n");
                    *coin = *coin - 10;
                    *beanSoup = *beanSoup + 1;
                    sleep(1);
                }
                else {
                    printf("You dont have enough money\n");
                    sleep(1);
                }
                break;
                
             //purchase the attack blessing
            case '3':
                if(*coin >= 99){
                    printf("You gain the blessing for attack!\n");
                    *coin = *coin - 99;
                    *strenght = *strenght + 1;
                    sleep(2);
                }
                else {
                    printf("You dont have enough money\n");
                }
                break;
            
        }
    }while( action != 'x');
}
/*
 * 
 * 
 */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {
    //world map    
    int locX = 1,locY = 1;
    int step = 0;
    int enemyPosX, enemyPosY;
    bool die = false;
    char gameMode[15];
    FILE* input;
    
    //create 8*8 map
    BuildMap(worldMap, row, col);
    //open the save file
    input = fopen("/home/user/NetBeansProjects/Zero Hero2/save", "r");
    bool emptySave = false;
    char newOrOld;
    
    do{
        //opening UI
        printf("---->Zero Hero 2<----\n");
        sleep(1);
        printf("\n");
        //choose model
        printf("    ->New game<-\n    ->Load game<-\n\n");
        //remember aguement 1 is varable 2 is length 3 is stdin
        fgets(gameMode, 15, stdin);
        printf("\033c");
        //check if it is an empty slot
        if(strcmp(gameMode,"Load game\n") == 0 && input == NULL){
            printf("Empty save file!\n");
            emptySave = true;
        }
        //warning the player for losing the save file
        else if(strcmp(gameMode, "New game\n") == 0 && input != NULL){
            printf("Warning you would lose previous save! OR you would not save this slot!\n"
                    "Do you want to over the previous slot?(y/n)\n");
            scanf(" %c", &newOrOld);
            if (newOrOld == 'n') emptySave = true;
        }
    } while((strcmp(gameMode,"Load game\n") != 0 && strcmp(gameMode, "New game\n") != 0) || emptySave == true);    
    //load game
    if (strcmp(gameMode,"Load game\n") == 0){
        //load the hero
        fscanf(input, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d ",
        &heroHPNow, &EXP, &levelUpEXP, &level, &strenght, &intellegent, &luck, &agilible, &skillPoint, &physicalDefense, &magicDefense, &coin, &locX, &locY);
        //free the pointer
        fclose(input);
        printf("Game Loaded!\n");
    }
    else{
        //ask input if it is new game
        ScanLocation(&locX, &locY);
    }
    
    //place hero
    worldMap[locX][locY] = '0';
    PrintMap();
    PrintStatus(heroHPMax, heroHPNow, coin);
        
    //control UI
    for (step = 0; step > -1; step++){
        
        ControlPanel(&locX, &locY, &die,&heroHPNow, &heroHPMax, &coin, &numOfHeals,&level, &EXP, &levelUpEXP, &strenght, &intellegent, &agilible,
                        &luck, &physicalDefense, &magicDefense, &skillPoint, &locX, &locY, &enemyHPMax, &attack, &defence, &beanSoup);
        EnemyGenerate(locX, locY, step, &enemyPosX, &enemyPosY);
        
        
        printf("\033c");
        PrintMap();
        PrintStatus(heroHPMax, heroHPNow, coin);
        
        //you die!
        if(die == true){
            break;
        }
    }
    
    printf("\033c");
    printf( "HaHaHaHa\n"
            "You die !\n");
   
    return (EXIT_SUCCESS);
}

