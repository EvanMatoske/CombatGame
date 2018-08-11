//
//  LoserStack.hpp
//  Assignment 4
//
//  Created by Evan Matoske on 11/21/15.
//  Copyright © 2015 Evan Matoske. All rights reserved.
//

#ifndef LoserStack_hpp
#define LoserStack_hpp

#include <stdio.h>
#include <iostream>
#include "Creature.hpp"


class Stack
{
    
protected:
    struct NodeList
    {
        Creature *creature;
        NodeList *next;
    };
    NodeList *head;
    NodeList *temp;
public:
    Stack ()
    {
        head = NULL;
    }
    void add(Creature*);
    Creature* remove();
    
    Creature* remove2();
    void displayList();
    int stackSize();
};

#endif /* LoserStack_hpp */
