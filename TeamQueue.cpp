//
//  main.cpp
//  Assignment 4
//
//  Created by Evan Matoske on 11/20/15.
//  Copyright © 2015 Evan Matoske. All rights reserved.
//

#include <iostream>
#include "TeamQueue.hpp"



TeamQueue::TeamQueue()
{
    head = NULL;
    score = 0;
}
void TeamQueue::add(Creature *type)
{
    if (head == NULL)
    {
        head = new NodeList;
        head->creature = type;
        head->next = NULL;
    }
    else
    {
        NodeList *nodeptr;
        
        
        temp = new NodeList;
        temp->creature = type;
        temp->next = NULL;
        temp->prev = NULL;
        
        nodeptr = head;
        while (nodeptr->next != NULL)
        {
            nodeptr = nodeptr->next;
        }
        tail = nodeptr->next = temp;
        
    }
};

void TeamQueue::displayList()
{
    NodeList *nodeptr = head;
    if (head == NULL)
        std::cout << "Team " << teamname << " is empty" << std::endl;
    
    else while (nodeptr)
    {
        std::cout << "Team Name : " << teamname << std::endl;
        std::cout << "Creature type : " << nodeptr->creature->getType() << "  " << std::endl;
        std::cout << "Name : " << nodeptr->creature->getName() << "  " << std::endl;
        std::cout << "Strenght : " << nodeptr->creature->getStrength() << "  " << std::endl;
        std::cout << "Armor : " << nodeptr->creature->getArmor() << "  " << std::endl;
        std::cout << "Score : " << nodeptr->creature->getScore() << "  " << std::endl;
        std::cout << std::endl;
        nodeptr = nodeptr->next;
    }
};
/*
Creature TeamQueue::remove()
{
    NodeList *nodeptr;
    nodeptr = head;
    head = head->next;
    return *nodeptr->creature;
    
};
*/

int TeamQueue::queueSize()
{
    int nodeCount = 0;
    NodeList *nodeptr;
    nodeptr = head;
    while (nodeptr)
    {
        nodeCount++;
        nodeptr = nodeptr->next;
    }
    
    return nodeCount;
    
    
};
void TeamQueue::setTeamName(std::string x)
{
    teamname = x;
}
std::string TeamQueue::getTeamName()
{
    return teamname;
}


Creature* TeamQueue::getCreature()
{
    NodeList *nodeptr;
    nodeptr = head;
 
    head = head->next;
    return nodeptr->creature;
    
}

    
    
