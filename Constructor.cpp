//
//  Constructor.cpp
//  Assignment3
//
//  Created by Evan Matoske on 11/6/15.
//  Copyright © 2015 Evan Matoske. All rights reserved.
//

#include "Creature.hpp"
/********************************************
 * Author : Evan Matoske                    *
 * Date : 11/7/2015                         *
 * Description : This file contains the     *
 * constructors for the different creatures *
 *******************************************/
 
 
Goblin::Goblin(std::string n)
{
    std::string nme;
    std::cout << "Enter Goblins name : ";
    std::cin >> nme;
    setName(nme);
    setArmor(3);
    setStrength(8);
    setType("Goblin");
    setTeamName(n);
    setScore(0);
}

Barbarian::Barbarian(std::string n)
{
    std::string nme;
    std::cout << "Enter Barbarian name : ";
    std::cin >> nme;
    setName(nme);
    setArmor(0);
    setStrength(12);
    setType("Barbarian");
    setTeamName(n);
    setScore(0);
}

ReptilePpl::ReptilePpl(std::string n)
{
    std::string nme;
    std::cout << "Enter Reptile Persons name : ";
    std::cin >> nme;
    setName(nme);
    setArmor(7);
    setStrength(18);
    setType("Reptile");
    setTeamName(n);
    setScore(0);
    
}

BlueMan::BlueMan(std::string n)
{
    std::string nme;
    std::cout << "Enter Bluemans name : ";
    std::cin >> nme;
    setName(nme);
    setArmor(3);
    setStrength(12);
    setType("BlueMan");
    setTeamName(n);
    setScore(0);
}

Shadow::Shadow(std::string n)
{
    std::string nme;
    std::cout << "Enter Shadows name : ";
    std::cin >> nme;
    setName(nme);
    setArmor(0);
    setStrength(12);
    setType("Shadow");
    setTeamName(n);
    setScore(0);
}