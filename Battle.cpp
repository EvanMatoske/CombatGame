//
//  main.cpp
//  Assignment3
//
//  Created by Evan Matoske on 11/6/15.
//  Copyright © 2015 Evan Matoske. All rights reserved.
//

#include <iostream>
#include "Creature.hpp"
#include "Combat.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>
#include "TeamQueue.hpp"
//#include "LoserStack.hpp"


int main()
{
    int teamSize;
    int choice;
    std::string teamname;
    std::string teamname2;
    
    std::cout << "How big would you like the teams? " << std::endl;
    std::cin >> teamSize;
    
    //TeamQueue Team1;
    
    std::cout << "Enter team name : " << std::endl;
    

    std::cin >> teamname;
    //std::getline(std::cin, teamname);
    TeamQueue Team1;
    Team1.setTeamName(teamname);
    
    
    
    for (int i = 0; i < teamSize; i++)
    {
        
        std::cout << "Enter 1 to add Goblin " << std::endl;
        std::cout << "Enter 2 to add Barbarian " << std::endl;
        std::cout << "Enter 3 to add BlueMan " << std::endl;
        std::cout << "Enter 4 to add ReptilePerson " << std::endl;
        std::cout << "Enter 5 to add Shadow " << std::endl;
        std::cin >> choice;
        while (choice < 1 || choice > 5)
        {
            std::cout << "Please enter a number in between 1-5 " << std::endl;
            std::cin >> choice;
        }
        if (choice == 1)
            Team1.add(new Goblin(teamname));
        else if (choice == 2)
            Team1.add(new Barbarian(teamname));
        else if (choice == 3)
            Team1.add(new BlueMan(teamname));
        else if (choice == 4)
            Team1.add(new ReptilePpl(teamname));
        else if (choice == 5)
            Team1.add(new Shadow(teamname));
        std::cout << std::endl;
    }
    
    
    TeamQueue Team2;
    std::cout << "Enter team 2 name " << std::endl;
    std::cin >> teamname2;
    Team2.setTeamName(teamname2);
    
    for (int i = 0; i < teamSize; i++)
    {
        
        std::cout << "Enter 1 to add Goblin " << std::endl;
        std::cout << "Enter 2 to add Barbarian " << std::endl;
        std::cout << "Enter 3 to add BlueMan " << std::endl;
        std::cout << "Enter 4 to add ReptilePerson " << std::endl;
        std::cout << "Enter 5 to add Shadow " << std::endl;
        std::cin >> choice;
        while (choice < 1 || choice > 5)
        {
            std::cout << "Please enter a number in between 1-5 " << std::endl;
            std::cin >> choice;
        }
        if (choice == 1)
            Team2.add(new Goblin(teamname2));
        else if (choice == 2)
            Team2.add(new Barbarian(teamname2));
        else if (choice == 3)
            Team2.add(new BlueMan(teamname2));
        else if (choice == 4)
            Team2.add(new ReptilePpl(teamname2));
        else if (choice == 5)
            Team2.add(new Shadow(teamname2));
        std::cout << std::endl;
    }
    
 
    do
    {
        Creature *temp;
        temp = Combat(*Team1.getCreature(), *Team2.getCreature());
        if (temp->getTeamName() == Team1.getTeamName())
            {
                Team1.add(temp);
                Team1.score++;
            }
        else
            {
                Team2.add(temp);
                Team2.score++;
            }
    
    } while ((Team1.queueSize() != 0) && (Team2.queueSize() != 0));
    
    std::cout << std::endl;
    Team1.displayList();
    std::cout << "Team 1 score : " << Team1.score << std::endl;
    std::cout << std::endl;
    
    Team2.displayList();
    std::cout << "Team 2 score : " << Team2.score << std::endl;
    std::cout << std::endl;
    
    if (Team1.score > Team2.score)
        std::cout << "Team " << Team1.getTeamName() << " Won! " << std::endl << std::endl;
    
    else
        std::cout << "Team " << Team2.getTeamName() << " Won! " << std::endl;
    std::cout << std::endl;
    
    if (Team1.queueSize() > 1)
    {
        do{
        Combat(*Team1.getCreature(), *Team1.getCreature());
        } while (Team1.queueSize() > 1);
    }
    else if (Team2.queueSize() > 1)
    {
        do{
            Combat(*Team2.getCreature(), *Team2.getCreature());
        } while (Team2.queueSize() > 1);
    }

    std::cout << std::endl <<  "LOSER LIST" << std::endl;
    getStack().displayList();
    
    std::cout << "The 3 winners are : " << std::endl;
    
    if (Team1.queueSize() == 1)
        std::cout << "First Place : " << Team1.getCreature()->getName() << " From Team : " << Team1.getTeamName()<< std::endl;
    
    else if (Team2.queueSize() == 1)
        std::cout << "First Place : " << Team2.getCreature()->getName() << " From Team : " << Team2.getTeamName()<< std::endl;
    
    else if (( Team1.queueSize() == 0) && (Team2.queueSize() == 0))
    {
        Creature *temp;
        temp = getStack().remove();
        
        std::cout << "First Place : " << temp->getName() << std::endl;
    }
    
    Creature *temp;
    temp = getStack().remove();
    std::cout << "Second Place : " << temp->getName() << std::endl;
    
    Creature *temp2;
    temp2 = getStack().remove2();
    
    std::cout << "Third Place : " << temp2->getName() << std::endl;
    
    
    
    
    
    
    //TeamQueue Winner;
    
    
    
    //std::vector<Creature> Winners;
    /*
    while (Team1.queueSize() != 0)
        Winner.add(Team1.getCreature());
    while (Team2.queueSize() != 0)
        Winner.add(Team2.getCreature());
    while (getStack().stackSize() != 0)
        Winner.add(getStack().remove());
    */
    
    
    return 0;
}
