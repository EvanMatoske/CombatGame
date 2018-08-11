//
//  Combat.hpp
//  Assignment3
//
//  Created by Evan Matoske on 11/6/15.
//  Copyright © 2015 Evan Matoske. All rights reserved.
//

#ifndef Combat_hpp
#define Combat_hpp
#include "Creature.hpp"
#include "TeamQueue.hpp"
#include <stdio.h>
#include "LoserStack.hpp"


Creature* Combat(Creature&, Creature&);
Creature* combat1(Creature&, Creature&);
Creature* combat2(Creature&, Creature&);
Creature* combat3(Creature&, Creature&);
Creature* combat4(Creature&, Creature&);
Creature* combat5(Creature&, Creature&);
Creature* combat6(Creature&, Creature&);
Stack getStack();
void displayStack();

#endif /* Combat_hpp */
