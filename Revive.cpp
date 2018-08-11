//
//  Revive.cpp
//  Assignment 4
//
//  Created by Evan Matoske on 11/21/15.
//  Copyright © 2015 Evan Matoske. All rights reserved.
//

#include <stdio.h>
#include "Creature.hpp"

void Goblin::revive()
{
    int health = 8 - getStrength();
    setStrength((health/2) + getStrength());
}
void Barbarian::revive()
{
    int health = 12 - getStrength();
    setStrength((health/2) + getStrength());
}
void ReptilePpl::revive()
{
    int health = 18 - getStrength();
    setStrength((health/2) + getStrength());
}
void BlueMan::revive()
{
    int health = 12 - getStrength();
    setStrength((health/2) + getStrength());
}
void Shadow::revive()
{
    int health = 12 - getStrength();
    setStrength((health/2) + getStrength());
}