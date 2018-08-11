//
//  TeamQueue.h
//  Assignment 4
//
//  Created by Evan Matoske on 11/20/15.
//  Copyright © 2015 Evan Matoske. All rights reserved.
//

#ifndef TeamQueue_h
#define TeamQueue_h
#include "Creature.hpp"
//#include "Combat.hpp"
#include <string>

class TeamQueue
{
    
protected:
    struct NodeList
    {
        Creature *creature;
        NodeList *next;
        NodeList *prev;
    };
    NodeList *head;
    NodeList *next;
    NodeList *temp;
    std::string teamname;
public:
    TeamQueue ();
    void add(Creature *type);
   // Creature remove();
    void displayList();
    int queueSize();
    Creature* getCreature();
    NodeList *tail;
    void battle();
    void setTeamName(std::string);
    std::string getTeamName();
    int score;

};






#endif /* TeamQueue_h */
