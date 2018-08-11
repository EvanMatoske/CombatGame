//
//  Defense.cpp
//  Assignment3
//
//  Created by Evan Matoske on 11/6/15.
//  Copyright © 2015 Evan Matoske. All rights reserved.
//

#include <stdio.h>
#include "Creature.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

/*********************************************
 * Author : Evan Matoske                     *
 * Date : 11/7/2015                          *
 * Description : This file contains all the  *
 * defense rolls for the different creatures *
 * as well as the cloak roll for the shadow  *
 ********************************************/



int Goblin::defense()
{
    int roll1;
    
    roll1 = 1+(rand()%6);
    
    return roll1;
}

int Goblin::cloak()
{
    return 2;
}

int Barbarian::defense()
{
    
    int roll1, roll2;
    
    roll1 = 1+(rand()%6);
    roll2 = 1+(rand()%6);
    
    return roll1 + roll2;
}

int Barbarian::cloak()
{
    return 2;
}

int ReptilePpl::defense()
{
    int roll1;
    
    roll1 = 1+(rand()%6);
    
    return roll1;
}

int ReptilePpl::cloak()
{
    return 2;
}

int BlueMan::defense()
{
    int roll1, roll2, roll3;
    
    roll1 = 1+(rand()%6);
    roll2 = 1+(rand()%6);
    roll3 = 1+(rand()%6);
  
    return roll1 + roll2 + roll3;
}

int BlueMan::cloak()
{
    return 2;
}

int Shadow::defense()
{
    int roll1;
    
    roll1 = 1+(rand()%6);
    
    return roll1;
}

int Shadow::cloak()
{
    int roll;
    
    roll = 0+(rand()%2);
    return roll;
}
