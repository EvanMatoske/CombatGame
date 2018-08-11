//
//  ApplyDamage.cpp
//  Assignment3
//
//  Created by Evan Matoske on 11/6/15.
//  Copyright © 2015 Evan Matoske. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Creature.hpp"

/****************************************
 * Author : Evan Matoske                *
 * Date : 11/7/2015                     *
 * Description : This File contains all *
 * the functions for applying damage to *
 * the creatures.                       *
 ***************************************/


int Goblin::applyDamage(int d)
{
    int damage, newStrength;
    
    damage = d - getArmor();
    if (damage < 0)
        damage = 0;
    
    /*if (damage < 0)
    {
        std::cout << "There was no damage assessed to the Goblin" << std::endl;
        damage = 0;
    }
    */
    
    newStrength = getStrength() - damage;
    if (newStrength < 0)
        setStrength(0);
    else setStrength(newStrength);
    
    if ( Strength <= 0)
    {
        std::cout << "The Goblin has died " << std::endl;
        return 0;
    }
    
    
    else return 1;
}

int Barbarian::applyDamage(int d)
{
    int damage, newStrength;
    
    damage = d - getArmor();
    if (damage < 0)
        damage = 0;
    /*
    if (damage <= 0)
    {
        std::cout << "There was no damage assessed to the Barbarian" << std::endl;
        damage = 0;
    }
    */
    newStrength = getStrength() - damage;
    if (newStrength < 0)
        setStrength(0);
    else setStrength(newStrength);
    
    if ( Strength <= 0)
    {
        std::cout << "The Barbarian has died " << std::endl;
        return 0;
    }
    
    else return 1;
}

int ReptilePpl::applyDamage(int d)
{
    int damage, newStrength;
    
    damage = d - getArmor();
    
    if (damage < 0)
        damage = 0;
    
    
    newStrength = getStrength() - damage;
    if (newStrength < 0)
        setStrength(0);
    else setStrength(newStrength);
    
    if ( Strength <= 0)
    {
        std::cout << "The Reptile person has died " << std::endl;
        return 0;
    }
    else return 1;
}

int BlueMan::applyDamage(int d)
{
    int damage, newStrength;
    
    damage = d - getArmor();
    if (damage < 0)
        damage = 0;
    
    /*
    if (damage < 0)
    {
        std::cout << "There was no damage assessed to the Blue man" << std::endl;
        damage = 0;
    }
    */
    
    newStrength = getStrength() - damage;
    if ( newStrength < 0)
        setStrength(0);
    else setStrength(newStrength);
    
    if ( Strength <= 0)
    {
        std::cout << "The Blue man has died " << std::endl;
        return 0;
    }
    
    
    else return 1;
}

int Shadow::applyDamage(int d)
{
    int damage, newStrength;
    
    
    damage = d - getArmor();
    if (damage < 0)
        damage = 0;
  
    
    newStrength = getStrength() - damage;
    if (newStrength < 0)
        setStrength(0);
    else setStrength(newStrength);
    
    if ( Strength <= 0)
    {
        std::cout << "The Shadow has died " << std::endl;
        return 0;
    }
    
    
    else return 1;
}










