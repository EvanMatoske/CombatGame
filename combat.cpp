//
//  Combat.cpp
//  Assignment3
//
//  Created by Evan Matoske on 11/6/15.
//  Copyright © 2015 Evan Matoske. All rights reserved.
//
#include "Creature.hpp"
#include "Combat.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
/*****************************************
 * Author : Evan Matoske                 *
 * Date : 11/7/2015                      *
 * Description : This file contains the  *
 * different combat scenarios that could *
 * take place with the different special *
 * abilities.                            *
 ****************************************/
//void Combat(TeamQueue a, TeamQueue b)
Stack LoserStack;    


Creature* Combat(Creature &a, Creature &b)
{
    
    /*************Combat1******************/
    //Shadow vs Shadow
    
    if ( a.getType() == "Shadow" && b.getType() == "Shadow")
        return combat1(a,b);
    
    
    /*************Combat2*******************/
    //Shadow vs Non Shadow and Non Goblin
    //Non Shadow and Non Goblin vs Shadow
    else if (a.getType() == "Shadow" && (b.getType() != "Shadow" && b.getType() != "Goblin"))
        return combat2(a,b);
    else if ((a.getType() != "Shadow" && a.getType() != "Goblin") && (b.getType() == "Shadow"))
        return combat2(a, b);
    
    /*************Combat3*********************/
    //Shadow vs Goblin
    //Goblin vs Shadow
    else if (a.getType() == "Shadow" && b.getType() == "Goblin")
        return combat3(a, b);
    else if (a.getType() == "Goblin" && b.getType() == "Shadow")
        return combat3(a, b);
    
    /*************Combat4********************/
    //Goblin vs Goblin
    else if (a.getType() == "Goblin" && b.getType() == "Goblin")
        return combat4(a,b);
    
    /******************Combat5*******************/
    //Non Goblin and Non Shadow vs Non Goblin and Non Shadow
    else if((a.getType() != "Goblin") && (a.getType() != "Shadow") && (b.getType() != "Goblin") && (b.getType() != "Shadow"))
        return combat5(a,b);
    
    
    /******************Combat6********************/
    //Goblin vs Non Goblin and Non Shadow
    //Non Goblin and Non Shadow vs Goblin
    else if (a.getType() == "Goblin" && (b.getType() != "Goblin")&&(b.getType() != "Shadow"))
        return combat6(a,b);
    else  ((a.getType() != "Goblin" && a.getType() != "Shadow") && b.getType() == "Goblin");
        return combat6(a, b);
    
    
}

/*Shadow vs Shadow*/
Creature* combat1(Creature&a, Creature&b)
{
    int cloak1, cloak2, attack1, attack2, defense1, defense2, damage1, damage2;
    srand(time(0));
    
    std::cout << "Creature 1 : " << a.getType() << " Team : " << a.getTeamName() << std::endl;
    std::cout << "Creature 2 : " << b.getType() << " Team : " << b.getTeamName() << std::endl;
    std::cout << "Creature 1 strength : " << a.getStrength() <<  std::endl;
    std::cout << "Creature 1 armor : " << a.getArmor() << std::endl;
    std::cout << "Creature 2 strength : " << b.getStrength() <<  std::endl;
    std::cout << "Creature 2 armor : " << b.getArmor() << std::endl;
    std::cout << std::endl;
    do{
    cloak1 = a.cloak();
    cloak2 = b.cloak();
    
    if (cloak1 == 0 && cloak2 == 0)
        std::cout << "Both used invisibility cloak no damage" << std::endl;
    
    else if (cloak1 == 1 && cloak2 == 0)
    {
        std::cout << "Creature 2 used invisibilty cloak no damage for him" << std::endl;
        
        attack1 = b.attack();
        defense1 = a.defense();
        
        //std::cout << "Creature 2 attack : " << attack1 << std::endl;
        //std::cout << "Creature 1 defense : " << defense1 << std::endl;
        
        
        damage1 = attack1 - defense1;
        
        a.applyDamage(damage1);
        //std::cout << "Shadow 1 new strength " << a.getStrength() << std::endl;
    }
    else if (cloak1 == 0 && cloak2 == 1)
    {
        //std::cout << "Creature 1 used invisibilty cloak no damage for him" << std::endl;
        attack1 = a.attack();
        defense1 = b.defense();
        
        //std::cout << "Creature 1 attack : " << attack1 << std::endl;
        //std::cout << "Creature 2 defense : " << defense1 << std::endl;
        
        damage1 = attack1 - defense1;
        b.applyDamage(damage1);
        //std::cout << " Shadow 2 new strength " << b.getStrength() << std::endl;
    }
    else if (cloak1 == 1 && cloak2 ==1)
    {
        //std::cout << "Neither used cloak both attack " << std::endl;
        
        attack1 = a.attack();
        defense1 = b.defense();
        
        //std::cout << " Shadow 1 attack : " << attack1 << std::endl;
        //std::cout << " Shadow 2 defense : " << defense1 << std::endl;
        
        
        attack2 = b.attack();
        defense2 = a.defense();
        
        //std::cout << " Shadow 2 attack : " << attack2 << std::endl;
        //std::cout << " Shadow 1 defense : " << defense2 << std::endl;
        
        damage1 = attack1 - defense1;
        damage2 = attack2 - defense2;
        
        b.applyDamage(damage1);
        a.applyDamage(damage2);
        
        //std::cout << " Shadow 1 new strength " << a.getStrength() << std::endl;
        //std::cout << " Shadow 2 new strength " << b.getStrength() << std::endl;
    }
    }while((a.getStrength() != 0) && (b.getStrength() != 0));
        
    if (a.getStrength() != 0)
    {
        LoserStack.add(&b);
        a.addScore(1);
        a.revive();
        std::cout << "Winning Creature : " << a.getType() << std::endl;
        std::cout << "Winning team : " << a.getTeamName() << std::endl;
        std::cout << std::endl;
        return &a;
    }
    else
    {
        LoserStack.add(&a);
        b.addScore(1);
        b.revive();
        std::cout << "Winning Creature : " << b.getType() << std::endl;
        std::cout << "Winning team : " << b.getTeamName() << std::endl;
        std::cout << std::endl;
        return &b;
    }
    
}

/*Shadow vs non shadow and non goblin*/
/*non shadow and non goblin vs Shadow*/
 Creature* combat2(Creature&a, Creature&b)
{
    int cloak1, attack1, attack2, defense1, defense2, damage1, damage2;
    srand(time(0));
    
    std::cout << "Creature 1 : " << a.getType() << " Team : " << a.getTeamName() << std::endl;
    std::cout << "Creature 2 : " << b.getType() << " Team : " << b.getTeamName() << std::endl;
    std::cout << "Creature 1 strength : " << a.getStrength() <<  std::endl;
    std::cout << "Creature 1 armor : " << a.getArmor() << std::endl;
    std::cout << "Creature 2 strength : " << b.getStrength() <<  std::endl;
    std::cout << "Creature 2 armor : " << b.getArmor() << std::endl;
    std::cout << std::endl;
    if (a.getType()== "Shadow")
    {
        do{
    
        cloak1 = a.cloak();
    
        if (cloak1 == 0)
        {
            //std::cout << "Shadow used invisibility cloak no damage for him" << std::endl;
            attack1 = a.attack();
            defense1 = b.defense();
            //std::cout << "Shadow attack : " << attack1 << std::endl;
            //std::cout << b.getType() << " defense : " << defense1 << std::endl;
        
            damage1 = attack1 - defense1;
            b.applyDamage(damage1);
            //std::cout << b.getType() << " new strength : " << b.getStrength() << std::endl;
            
        }
        else if (cloak1 == 1)
        {
            //std::cout << "Cloak didnt work" << std::endl;
            attack1 = a.attack();
            defense1 = b.defense();
            damage1 = attack1 - defense1;
            
            //std::cout << a.getType() << " Attack : " << attack1 << std::endl;
            //std::cout << b.getType() << " Defense : " << defense1 << std::endl;
        
            attack2 = b.attack();
            defense2 = a.defense();
            damage2 = attack2 - defense2;
            
            //std::cout << b.getType() << " Attack : " << attack2 << std::endl;
            //std::cout << a.getType() << " Defense : " << defense2 << std::endl;
    
            b.applyDamage(damage1);
            a.applyDamage(damage2);
            
            //std::cout << a.getType() << " new strength : " << a.getStrength() << std::endl;
            //std::cout << b.getType() << " new strength : " << b.getStrength() << std::endl;
            
            
        }
        
    } while ((a.getStrength() != 0) && (b.getStrength() != 0));
        
}
    
    else if (b.getType() == "Shadow")
    {
        do{
        cloak1 = b.cloak();
        if (cloak1 == 0)
        {
            //std::cout << "Shadow used invisibility cloak no damage for him" << std::endl;
            attack1 = b.attack();
            defense1 = a.defense();
            
            //std::cout << "Shadow attack : " << attack1 << std::endl;
            //std::cout << a.getType() << " defense : " << defense1 << std::endl;
            
            damage1 = attack1 - defense1;
            a.applyDamage(damage1);
            
            //std::cout << a.getType() << " New strength : " << a.getStrength() << std::endl;
        }
        else if (cloak1 == 1)
        {
            //std::cout << "Cloak didnt work" << std::endl;
            attack1 = a.attack();
            defense1 = b.defense();
            damage1 = attack1 - defense1;
            
            //std::cout << a.getType() << " Attack : " << attack1 << std::endl;
            //std::cout << b.getType() << " Defense : " << defense1 << std::endl;
            
            
            attack2 = b.attack();
            defense2 = a.defense();
            damage2 = attack2 - defense2;
            
            //std::cout << b.getType() << " Attack : " << attack2 << std::endl;
            //std::cout << a.getType() << " Defense : " << defense2 << std::endl;
            
            b.applyDamage(damage1);
            a.applyDamage(damage2);
            
            //std::cout << a.getType() << " new strength : " << a.getStrength() << std::endl;
            //std::cout << b.getType() << " new strength : " << b.getStrength() << std::endl;
        }
            
    }while ((a.getStrength() != 0) && (b.getStrength() != 0));
    
}
    if (a.getStrength() != 0)
    {
        LoserStack.add(&b);
        a.addScore(2);
        b.addScore(-1);
        a.revive();
        std::cout << "Winning Creature : " << a.getType() << std::endl;
        std::cout << "Winning team : " << a.getTeamName() << std::endl;
        std::cout << std::endl;
        return &a;
    }
    else
    {
        LoserStack.add(&a);
        b.addScore(2);
        a.addScore(-1);
        b.revive();
        std::cout << "Winning Creature : " << b.getType() << std::endl;
        std::cout << "Winning team : " << b.getTeamName() << std::endl;
        std::cout << std::endl;
        return &b;
    }
    
    
}


/*Shadow vs Goblin*/
/*Goblin vs Shadow*/
Creature* combat3(Creature&a, Creature&b)
{
    int cloak, attack1, attack2, defense1, defense2, damage1, damage2;
    srand(time(0));
    
    std::cout << "Creature 1 : " << a.getType() << " Team : " << a.getTeamName() << std::endl;
    std::cout << "Creature 2 : " << b.getType() << " Team : " << b.getTeamName() << std::endl;
    std::cout << "Creature 1 strength : " << a.getStrength() <<  std::endl;
    std::cout << "Creature 1 armor : " << a.getArmor() << std::endl;
    std::cout << "Creature 2 strength : " << b.getStrength() <<  std::endl;
    std::cout << "Creature 2 armor : " << b.getArmor() << std::endl;
    std::cout << std::endl;
    
    
    if (a.getType() == "Shadow" && b.getType() == "Goblin")
    {
        do{
        cloak = a.cloak();
        if (cloak == 0)
        {
            //std::cout << "Shadow used invisibility cloak no damage for him" << std::endl;
            attack1 = a.attack();
            defense1 = b.defense();
        
            //std::cout << a.getType() << " Attack : " << attack1 << std::endl;
            //std::cout << b.getType() << " Defense : " << defense1 << std::endl;
            
            damage1 = attack1 - defense1;
            b.applyDamage(damage1);
            //std::cout << b.getType() << " new strength : " << b.getStrength() << std::endl;
            
        }
        else if (cloak == 1)
        {
            //std::cout << "Cloak didnt work " << std::endl;
            attack1 = a.attack();
            defense1 = b.defense();
            damage1 = attack1 = defense1;
            
            //std::cout << a.getType() << "Attack : " << attack1 << std::endl;
            //std::cout << b.getType() << "Defense : " << defense1 << std::endl;
            
            attack2 = b.attack();
        
            if (attack2 == 12)
            {
                a.setAchilles(0);
                //std::cout << a.getType() << " Achilles was cut " << std::endl;
            }
        
            defense2 = a.defense();
            damage2 = attack2 - defense2;
            
            //std::cout << b.getType() << " Attack : " << attack2 << std::endl;
            //std::cout << a.getType() << " Defense : " << defense2 << std::endl;
            
            b.applyDamage(damage1);
            a.applyDamage(damage2);
            
            //std::cout << a.getType() << " new strength : " << a.getStrength() << std::endl;
            //std::cout << b.getType() << " new strength : " << b.getStrength() << std::endl;
        }
            
        }while ((a.getStrength() != 0) && (b.getStrength() != 0));
    
    }
    else if (a.getType() == "Goblin" && b.getType() == "Shadow")
    {
        do{
        cloak = b.cloak();
        if (cloak == 0)
        {
            //std::cout << "Shadow used invisibility cloak no damage for him " << std::endl;
            attack1 = b.attack();
            defense1 = a.defense();
            
            //std::cout << "Shadow attack : " << attack1 << std::endl;
            //std::cout << a.getType() << " defense : " << defense1 << std::endl;
            
            
            damage1 = attack1 - defense1;
            a.applyDamage(damage1);
            
            //std::cout << a.getType() << " New strength : " << a.getStrength() << std::endl;
        }
        else if (cloak == 1)
        {
            
            //std::cout << "Cloak didnt work "<< std::endl;
            attack1 = a.attack();
            defense1 = b.defense();
            damage1 = attack1 - defense1;
            
            //std::cout << a.getType() << " Attack : " << attack1 << std::endl;
            //std::cout << b.getType() << " Defense : " << defense1 << std::endl;
            
            attack2 = b.attack();
            
            if (attack1 == 12)
            {
                b.setAchilles(0);
                //std::cout << "Achilles was cut " << std::endl;
            }
            
            defense2 = a.defense();
            damage2 = attack2 - defense2;
            
            //std::cout << b.getType() << " Attack : " << attack2 << std::endl;
            //std::cout << a.getType() << " Defense : " << defense2 << std::endl;
            
            b.applyDamage(damage1);
            a.applyDamage(damage2);
            
            //std::cout << a.getType() << " new strength : " << a.getStrength() << std::endl;
            //std::cout << b.getType() << " new strength : " << b.getStrength() << std::endl;
            
            
        }
            
    }while ((a.getStrength() != 0) && (b.getStrength() != 0));
    
}
    if (a.getStrength() != 0)
    {
        LoserStack.add(&b);
        a.addScore(3);
        b.addScore(-1);
        a.revive();
        std::cout << "Winning Creature : " << a.getType() << std::endl;
        std::cout << "Winning team : " << a.getTeamName() << std::endl;
        std::cout << std::endl;
        return &a;
    }
    else
    {
        LoserStack.add(&a);
        b.addScore(3);
        a.addScore(-1);
        b.revive();
        std::cout << "Winning Creature : " << b.getType() << std::endl;
        std::cout << "Winning team : " << b.getTeamName() << std::endl;
        std::cout << std::endl;
        return &b;
    }
    
}


/*Goblin vs Goblin*/
Creature* combat4(Creature&a, Creature&b)
{
    int damage1, damage2, attack1, attack2, defense1, defense2;
    
    std::cout << "Creature 1 : " << a.getType() << " Team : " << a.getTeamName() << std::endl;
    std::cout << "Creature 2 : " << b.getType() << " Team : " << b.getTeamName() << std::endl;
    std::cout << "Creature 1 strength : " << a.getStrength() <<  std::endl;
    std::cout << "Creature 1 armor : " << a.getArmor() << std::endl;
    std::cout << "Creature 2 strength : " << b.getStrength() <<  std::endl;
    std::cout << "Creature 2 armor : " << b.getArmor() << std::endl;
    std::cout << std::endl;
    
    do{
    attack1 = a.attack();
    defense1 = b.defense();
    damage1 = attack1 - defense1;
    
    //std::cout << a.getType() << "Attack : " << attack1 << std::endl;
    //std::cout << b.getType() << "Defense : " << defense1 << std::endl;
    
    if (damage1 < 0)
        damage1 = 0;
    
    if (b.getStrength() > 0)
    {
        attack2 = b.attack();
        defense2 = a.defense();
        
        //std::cout << b.getType() << "Attack : " << attack2 << std::endl;
        //std::cout << a.getType() << "Defense : " << defense2 << std::endl;
        
        damage2 = attack2 - defense2;
        
        if (damage2 < 0)
            damage2 = 0;
    }
    else if (b.getStrength() < 0)
        std::cout << b.getType() << " Died ";
    
    b.applyDamage(damage1);
    a.applyDamage(damage2);
    
    //std::cout << a.getType() << " new strength : " << a.getStrength() << std::endl;
    //std::cout << b.getType() << " new strength : " << b.getStrength() << std::endl;
    
        
    }while((a.getStrength() != 0) && (b.getStrength() != 0));
        
        
    if (a.getStrength() != 0)
    {
        LoserStack.add(&b);
        a.revive();
        a.addScore(4);
        b.addScore(-1);
        std::cout << "Winning Creature : " << a.getType() << std::endl;
        std::cout << "Winning team : " << a.getTeamName() << std::endl;
        std::cout << std::endl;
        return &a;
    }
    else
    {
        LoserStack.add(&a);
        b.addScore(4);
        a.addScore(-1);
        b.revive();
        std::cout << "Winning Creature : " << b.getType() << std::endl;
        std::cout << "Winning team : " << b.getTeamName() << std::endl;
        std::cout << std::endl;
        return &b;
    }

}


/*Non goblin non Shadow vs non goblin non Shadow*/
Creature* combat5(Creature&a, Creature&b)
{
    int damage1, damage2, attack1, attack2, defense1, defense2;
    
    std::cout << "Creature 1 : " << a.getType() << " Team : " << a.getTeamName() << std::endl;
    std::cout << "Creature 2 : " << b.getType() << " Team : " << b.getTeamName() << std::endl;
    std::cout << "Creature 1 strength : " << a.getStrength() <<  std::endl;
    std::cout << "Creature 1 armor : " << a.getArmor() << std::endl;
    std::cout << "Creature 2 strength : " << b.getStrength() <<  std::endl;
    std::cout << "Creature 2 armor : " << b.getArmor() << std::endl;
    std::cout << std::endl;
    
    do{
    attack1 = a.attack();
    defense1 = b.defense();
    
    //std::cout << a.getType() << " Attack : " << attack1 << std::endl;
    //std::cout << b.getType() << " Defense : " << defense1 << std::endl;
    
    damage1 = attack1 - defense1;
    if (damage1 < 0)
        damage1 = 0;
    
    if (b.getStrength() > 0)
    {
        attack2 = b.attack();
        defense2 = a.defense();
        
        //std::cout << b.getType() << " Attack : " << attack2 << std::endl;
        //std::cout << a.getType() << " Defense : " << defense2 << std::endl;
        
        
        damage2 = attack2 - defense2;
        
        if (damage2 < 0)
            damage2 = 0;
    }
    
    else if (b.getStrength() < 0)
        std::cout << b.getType() << "Died ";
    
    b.applyDamage(damage1);
    a.applyDamage(damage2);
    //std::cout << a.getType() << " new strength : " << a.getStrength() << std::endl;
    //std::cout << b.getType() << " new strength : " << b.getStrength() << std::endl;
    
        
    }while ((a.getStrength() != 0) && (b.getStrength() != 0));
    
    
    if (a.getStrength() != 0)
    {
        LoserStack.add(&b);
        a.addScore(3);
        b.addScore(-1);
        a.revive();
        std::cout << "Winning Creature : " << a.getType() << std::endl;
        std::cout << "Winning team : " << a.getTeamName() << std::endl;
        std::cout << std::endl;
        return &a;
    }
    else
    {
        LoserStack.add(&a);
        b.addScore(3);
        a.addScore(-1);
        b.revive();
        std::cout << "Winning Creature : " << b.getType() << std::endl;
        std::cout << "Winning team : " << b.getTeamName() << std::endl;
        std::cout << std::endl;
        return &b;
    }
    
}

//Goblin vs Non Goblin and Non Shadow
//Non Goblin and Non Shadow vs Goblin
Creature* combat6(Creature&a, Creature&b)
{
    int damage1, damage2, attack1, attack2, defense1, defense2;
    srand(time(0));
    
    std::cout << "Creature 1 : " << a.getType() << " Team : " << a.getTeamName() << std::endl;
    std::cout << "Creature 2 : " << b.getType() << " Team : " << b.getTeamName() << std::endl;
    std::cout << "Creature 1 strength : " << a.getStrength() <<  std::endl;
    std::cout << "Creature 1 armor : " << a.getArmor() << std::endl;
    std::cout << "Creature 2 strength : " << b.getStrength() <<  std::endl;
    std::cout << "Creature 2 armor : " << b.getArmor() << std::endl;
    std::cout<< std::endl;
    
    
    if (a.getType() == "Goblin")
    {
        
        do {
        attack1 = a.attack();
        defense1 = b.defense();
        
        if (attack1 == 12)
        {
            //std::cout << "Achilles was cut " << std::endl;
            b.setAchilles(0);
        }
        //std::cout << a.getType() << " Attack : " << attack1 << std::endl;
        //std::cout << b.getType() << " Defense : " << defense1 << std::endl;
        std::cout << std::endl;
        damage1 = attack1 - defense1;
        if (damage1 < 0)
            damage1 = 0;
        
        if (b.getStrength() > 0)
        {
            attack2 = b.attack();
            defense2 = a.defense();
            damage2 = attack2 - defense2;
            
            //std::cout << b.getType() << " Attack : " << attack2 << std::endl;
            //std::cout << a.getType() << " Defense : " << defense2 << std::endl;
            
            if (damage2 < 0)
                damage2 = 0;
            
        }
        else std::cout << b.getType() << " Died " << std::endl;
        
        b.applyDamage(damage1);
        a.applyDamage(damage2);
        
        //std::cout << std::endl;
        //std::cout << a.getType() << " new strength : " << a.getStrength() << std::endl;
        //std::cout << b.getType() << " new strength : " << b.getStrength() << std::endl;
        //std::cout << std::endl;
            
        }while ((a.getStrength() != 0) && (b.getStrength() != 0));
            
      
        
      
        
    
}
    
    else if (b.getType() == "Goblin")
    {
        do{
   
        attack1 = a.attack();
        
        defense1 = b.defense();
        damage1 = attack1 - defense1;
        
        //std::cout << a.getType() << " Attack : " << attack1 << std::endl;
        //std::cout << b.getType() << " Defense : " << defense1 << std::endl;
        
        
        if (damage1 < 0)
            damage1 = 0;
        
        if (b.getStrength() > 0)
        {
            attack2 = b.attack();
            defense2 = a.defense();
            
            
            //std::cout << b.getType() << " Attack : " << attack2 << std::endl;
            //std::cout << a.getType() << " Defense : " << defense2 << std::endl;
            
            if (attack2 == 12)
            {
                //std::cout << "Achilles was cut " <<std::endl;
                a.setAchilles(0);
            }
            
            damage2 = attack2 - defense2;
            
            if (damage2 < 0)
                damage2 = 0;
            
        }
        else std::cout << b.getType() << "Died " << std::endl;
        
        
        b.applyDamage(damage1);
        a.applyDamage(damage2);
        //std::cout << a.getType() << " new strength : " << a.getStrength() << std::endl;
        //std::cout << b.getType() << " new strength : " << b.getStrength() << std::endl;
        
        }while ((a.getStrength() != 0) && (b.getStrength() != 0));
        

        
        
        
    }
    if (a.getStrength() != 0)
    {
        LoserStack.add(&b);
        a.addScore(3);
        b.addScore(-1);
        a.revive();
        std::cout << "Winning Creature : " << a.getType() << std::endl;
        std::cout << "Winning team : " << a.getTeamName() << std::endl;
        std::cout << std::endl;
        return &a;
    }
    else
    {
        LoserStack.add(&a);
        b.addScore(3);
        a.addScore(-1);
        b.revive();
        std::cout << "Winning Creature : " << b.getType() << std::endl;
        std::cout << "Winning team : " << b.getTeamName() << std::endl;
        std::cout << std::endl;
        return &b;
    }
}

Stack getStack()
{
    return LoserStack;
}

