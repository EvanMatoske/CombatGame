//
//  Creature.cpp
//  Assignment3
//
//  Created by Evan Matoske on 11/6/15.
//  Copyright © 2015 Evan Matoske. All rights reserved.
//

#include "Creature.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
/************************************************
 * Author : Evan Matoske                        *
 * Date : 11/7/2015                             *
 * Description : This file contain all          *
 * the attack rolls for the different creatures *
 ***********************************************/

int Goblin::attack()
{
    
    int roll1, roll2;

    roll1 = 1+(rand()%6);
    roll2 = 1+(rand()%6);
    
    return roll1 + roll2;
    
}

int Barbarian::attack()
{
    
    int roll1, roll2;
    
    roll1 = 1+(rand()%6);
    roll2 = 1+(rand()%6);
    if(Achilles == 0)
        return (roll1/2) + (roll2/2);
    return roll1 + roll2;

}

int ReptilePpl::attack()
{
    
    int roll1, roll2, roll3;
    
    roll1 = 1+(rand()%6);
    roll2 = 1+(rand()%6);
    roll3 = 1+(rand()%6);
    if (Achilles == 0)
        return (roll1/2) + (roll2/2) + (roll3/2);
   
    else return roll1 + roll2 + roll3;
}

int BlueMan::attack()
{
    
    int roll1, roll2;
    
    roll1 = 1+(rand()%10);
    roll2 = 1+(rand()%10);
    if(Achilles == 0)
        return (roll1/2) + (roll2/2);
    return roll1 + roll2;

}

int Shadow::attack()
{

    int roll1, roll2;
    
    roll1 = 1+(rand()%10);
    roll2 = 1+(rand()%10);
    if( Achilles == 0)
        return (roll1/2) + (roll2/2);
    return roll1 + roll2;
    
}



