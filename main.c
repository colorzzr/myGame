/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: user
 *
 * Created on January 16, 2017, 8:44 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*three line(///) is testing command
 *two line(//) is the //
 */
int main(int argc, char** argv) {
    //defining the world
    char worldMap[50]="|-------|\n|-------|\n|-------|\n";
    char edge1[20]="|_______|\n";
    ///char edge2[20]="|\n|\n|\n";
    
    //defining the variables
    char dir;
    int worldBlock,enemyBlock;
    int step,seed,score = 0;
    int link;
    
    printf("Zero hero\n"
            "Detail for operating:\n"
            "You h  ave 20 step\n"
            "Kill enemy(1) gain 1 step\n"
            "\'w\'-up \'s\'-down \'a\'-left \'d\'-right\n"
            "Level1 is 0 points and each moving costs 1 step\n"
            "Level2 is 50 points and each moving costs 2 steps\n"
            "Level3 is 100 points and each moving costs 3 steps\n"
            "Now reach 120 points!!!\n");
    
    
    //locations of hero
    printf("Your location: ");
    scanf("%d",&worldBlock);
    
    
    //condition of location  
    worldBlock=worldBlock%25;
    
    if (worldBlock%10==0||worldBlock%17==0||worldBlock==0){
        worldBlock=worldBlock+1;
    }
    else if (worldBlock%8==0||worldBlock%18==0||worldBlock%28==0){
        worldBlock=worldBlock-1;
    }
    else if ((worldBlock%9==0)||(worldBlock%19==0)||worldBlock%29==0){
        
            worldBlock=worldBlock-2;
        
    }
    
    //place hero and print world
    worldMap[worldBlock]='0';
    printf("%s%s%s",edge1,worldMap,edge1);
    
   
    
    //moving command
    for(step=0;step<20;step=step+1){
    ///worldMap[2]='5';
      
        scanf(" %c",&dir);
        printf("\033c");
        
    //location of enemy
    seed=worldBlock*step;
    srand(seed);
    enemyBlock=rand()%25;
    
    
    //location sort out add10
    if (enemyBlock%10==0||enemyBlock%20==0||enemyBlock==0){
        enemyBlock=enemyBlock+1;
    }
    else if (enemyBlock%8==0||enemyBlock%18==0||enemyBlock==28){
        enemyBlock=enemyBlock-1;
    }
    else if(enemyBlock%9==0||enemyBlock%19==0|enemyBlock%29==0){
        enemyBlock=enemyBlock-2;
    }
    worldMap[enemyBlock]='1';
    
    
    //moving direction
    switch (dir){
        //left
        case 'a':
            if(worldMap[worldBlock-1]=='|'){
            
            }
            else{
                if(worldMap[worldBlock-1]=='1'){
                    //gain life when kill enemy
                    step = step - 2; 
                    /*//lose life when touch enemy
                     step=step+1;
                     */
                    //score mode
                    score=score+1;
                    
                }
                worldMap[worldBlock]='-';
                worldBlock=worldBlock-1;
                worldMap[worldBlock]='0';
            }
            
            break; 
        
            //right
        case 'd':
            if (worldMap[worldBlock+1]=='|'){
            
            }
            else{
                if(worldMap[worldBlock+1]=='1'){
                    //gain life when kill enemy
                    step=step-2; 
                    /*//lose life when touch enemy
                     step=step+1;
                     */
                    //score mode
                    score=score+1;
                    
                }
                worldMap[worldBlock]='-';
                worldBlock=worldBlock+1;
                worldMap[worldBlock]='0';
            }
            break;
            
            //up
        case 'w':
            if ((worldBlock-10)<0){
            
            }
            else{
                if(worldMap[worldBlock-10]=='1'){
                    //gain life when kill enemy
                    step=step-2; 
                    /*//lose life when touch enemy
                     step=step+1;
                     */
                    //score mode
                    score=score+1;
                    
                    
                }
                worldMap[worldBlock]='-';
                worldBlock=worldBlock-10;
                worldMap[worldBlock]='0';
                
            }
            break;
            
        //down    
        case 's':
            if ((worldBlock+10)>29){
                
            }
            else{
                if(worldMap[worldBlock+10]=='1'){
                    //gain life when kill enemy
                    step=step-2; 
                    
                    //score mode
                    score=score+1;
                    
                     
                }
                worldMap[worldBlock]='-';
                worldBlock=worldBlock+10;
                worldMap[worldBlock]='0';
            }
            break;
        
        //cheating code
        case 'c':
            step=step-101;
            printf("Show me the money\n ");
            break;
            
        
        default:
            step = step - 1;
            break;
    }
    
    //refreshing the world  
    //system("clear");
    //system("clear");//fiXME21342
    printf("%s%s%s\n",edge1,worldMap,edge1);
    printf("step left: %d\n",19-step);
    printf("score: %d\n",score);
    
    if (score==50){
        link = step;
        step = 20;
    }
    }
    step = link;
   
    
    
    
    //Level2
    printf("\033c"); 
    printf("Level 2\n");
    printf("%s%s%s\n",edge1,worldMap,edge1);
    printf("step left: %d\n",19-step);
    printf("score: %d\n",score);
    
    
    for(step = link + 2;step < 20;step = step + 2){
        scanf(" %c",&dir);
        printf("\033c");
        
    //location of enemy
    seed = worldBlock * step;
    srand(seed);
    enemyBlock = rand() % 25;
    
    
    //location sort out add10
    if (enemyBlock % 10 == 0 || enemyBlock % 20 == 0 || enemyBlock == 0){
        enemyBlock = enemyBlock + 1;
    }
    else if (enemyBlock % 8 == 0 || enemyBlock % 18 == 0 || enemyBlock % 28 == 0){
        enemyBlock = enemyBlock - 1;
    }
    else if(enemyBlock % 9 == 0 || enemyBlock % 19 == 0 || enemyBlock%29 == 0){
        enemyBlock=enemyBlock-2;
    }
    worldMap[enemyBlock] = '1';
    
    
    //moving direction
    switch (dir){
        //left
        case 'a':
            if(worldMap[worldBlock-1] == '|'){

            }
            else{
                if(worldMap[worldBlock-1] == '1'){
                    //gain life when kill enemy
                    step = step - 3; 
                    
                    //score mode
                    score = score + 1;
                    
                }
                worldMap[worldBlock] = '-';
                worldBlock = worldBlock-1;
                worldMap[worldBlock] = '0';
            }
            
            break; 
        
            //right
        case 'd':
            if (worldMap[worldBlock+1] == '|'){

            }
            else{
                if(worldMap[worldBlock+1] == '1'){
                    //gain life when kill enemy
                    step = step - 3;
                    
                    //score mode
                    score = score + 1;
                    
                }
                worldMap[worldBlock] = '-';
                worldBlock = worldBlock + 1;
                worldMap[worldBlock] = '0';
            }
            break;
            
            //up
        case 'w':
            if ((worldBlock - 10) < 0){
                
            }
            else{
                if(worldMap[worldBlock-10] == '1'){
                    //gain life when kill enemy
                    step = step - 3; 
                    
                    //score mode
                    score = score + 1;
                    
                    
                }
                worldMap[worldBlock] = '-';
                worldBlock = worldBlock - 10;
                worldMap[worldBlock] = '0';
                
            }
            break;
            
        //down    
        case 's':
            if ((worldBlock + 10) > 29){
 
            }
            else{
                if(worldMap[worldBlock + 10] == '1'){
                    //gain life when kill enemy
                    step = step - 3; 
                   
                    //score mode
                    score = score + 1;
                    
                     
                }
                worldMap[worldBlock]='-';
                worldBlock=worldBlock+10;
                worldMap[worldBlock]='0';
            }
            break;
           
            
        //cheating code
        case 'c':
            step=step-101;
            printf("Show me the money\n");
            break;
            
            
        default:
            step=step - 1;

            break;
    }
    
    //refreshing the world  
    
    printf("%s%s%s\n",edge1,worldMap,edge1);
    printf("step left: %d\n",19-step);
    printf("score: %d\n",score);

    
    if (score == 100){
        link = step;
        step = 20;
    }
    }
    step = link;
    
    
    
    
    //Level 3
    printf("\033c");
    printf("Level 3\n"
            "gaining 5 steps");
    printf("%s%s%s\n",edge1,worldMap,edge1);
    printf("step left: %d\n",19-step);
    printf("score: %d\n",score);
    
    
    for(step = link - 2;step < 20;step = step + 3){
    ///worldMap[2]='5';
        
        scanf(" %c",&dir);
        printf("\033c");
        
    //location of enemy
    seed=worldBlock*step;
    srand(seed);
    enemyBlock=rand()%25;
    ///printf("enemyBlock:%d",enemyBlock);
    
    
    //location sort out add10
    if (enemyBlock%10==0||enemyBlock%20==0||enemyBlock==0){
        enemyBlock=enemyBlock+1;
    }
    else if (enemyBlock%8==0||enemyBlock%18==0||enemyBlock==28){
        enemyBlock=enemyBlock-1;
    }
    else if(enemyBlock%9==0||enemyBlock%19==0|enemyBlock%29==0){
        enemyBlock=enemyBlock-2;
    }
    worldMap[enemyBlock]='1';
    
    
    //moving direction
    switch (dir){
        //left
        case 'a':
            if(worldMap[worldBlock-1]=='|'){
            
            }
            else{
                if(worldMap[worldBlock-1]=='1'){
                    //gain life when kill enemy
                    step=step-4; 
                    ///lose life when touch enemy
                    ///step=step+1;
                    
                    //score mode
                    score=score+1;
                    
                }
                worldMap[worldBlock]='-';
                worldBlock=worldBlock-1;
                worldMap[worldBlock]='0';
            }
            
            break; 
        
            //right
        case 'd':
            if (worldMap[worldBlock+1]=='|'){
            
            }
            else{
                if(worldMap[worldBlock+1]=='1'){
                    //gain life when kill enemy
                    step=step-4; 
                    ///lose life when touch enemy
                    ///step=step+1;
                    
                    //score mode
                    score=score+1;
                    
                }
                worldMap[worldBlock]='-';
                worldBlock=worldBlock+1;
                worldMap[worldBlock]='0';
            }
            break;
            
            //up
        case 'w':
            if ((worldBlock-10)<0){
            
            }
            else{
                if(worldMap[worldBlock-10]=='1'){
                    //gain life when kill enemy
                    step=step-4; 
                    ///lose life when touch enemy
                    ///step=step+1;
                    
                    //score mode
                    score=score+1;
                    
                    
                }
                worldMap[worldBlock]='-';
                worldBlock=worldBlock-10;
                worldMap[worldBlock]='0';
                
            }
            break;
            
        //down    
        case 's':
            if ((worldBlock+10)>29){
                
            }
            else{
                if(worldMap[worldBlock+10]=='1'){
                    //gain life when kill enemy
                    step=step-4; 
                    ///lose life when touch enemy
                    ///step=step+1;
                    
                    //score mode
                    score=score+1;
                    
                     
                }
                worldMap[worldBlock]='-';
                worldBlock=worldBlock+10;
                worldMap[worldBlock]='0';
            }
            break;
        
        
        //cheating code
        case 'c':
            step=step-101;
            printf("Show me the money\n");
            break;
        
            
        default:
            step=step - 1;
            
            break;
    }
    
    //refreshing the world  
    //system("clear");
    //system("clear");//fiXME21342
    printf("%s%s%s\n",edge1,worldMap,edge1);
    printf("step left: %d\n",19-step);
    printf("score: %d\n",score);
    if (score==120){
        printf("Victory!");
        return 0;
    }
    }
    
    //Bad End
    if (score != 120){
    printf( "\033c"
            "GameOver\n"
            "Total score:%d",score);
    }
    return (EXIT_SUCCESS);
}

