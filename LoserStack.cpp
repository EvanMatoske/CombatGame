//
//  LoserStack.cpp
//  Assignment 4
//
//  Created by Evan Matoske on 11/21/15.
//  Copyright © 2015 Evan Matoske. All rights reserved.
//

#include "LoserStack.hpp"


void Stack::add(Creature *type)
{
    if (head == NULL)
    {
        head = new NodeList;
        head->creature = type;
        head->next = NULL;
        
        
    }
    else
    {
        temp = new NodeList;
        temp->creature = type;
        temp->next = head;
        head = temp;
    }
};

void Stack::displayList()
{
    NodeList *nodeptr = head;
    if (head == NULL)
        std::cout << "Team empty";
    
    else while (nodeptr)
    {
        std::cout << "Team Name : " << nodeptr->creature->getTeamName() << std::endl;
        std::cout << "Creature type : " << nodeptr->creature->getType() << "  " << std::endl;
        std::cout << "Name : " << nodeptr->creature->getName() << "  " << std::endl;
        std::cout << "Strenght : " << nodeptr->creature->getStrength() << "  " << std::endl;
        std::cout << "Armor : " << nodeptr->creature->getArmor() << "  " << std::endl;
        std::cout << "Score : " << nodeptr->creature->getScore() << "  " << std::endl;
        std::cout << std::endl;
        nodeptr = nodeptr->next;
    };
}
int Stack::stackSize()
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
}
Creature* Stack::remove()
{
    NodeList *nodeptr;
    nodeptr = head;
    head = head->next;
    return nodeptr->creature;
    
}
Creature* Stack::remove2()
{
    
    NodeList *nodeptr;
    nodeptr = head;
    head = head->next;
    return nodeptr->next->creature;
}
