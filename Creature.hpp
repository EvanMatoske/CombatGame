//
//  Creature.hpp
//  Assignment3
//
//  Created by Evan Matoske on 11/6/15.
//  Copyright © 2015 Evan Matoske. All rights reserved.
//

#ifndef Creature_hpp
#define Creature_hpp

#include <stdio.h>
#include <string>
#include <iostream>
class Creature
{
    
public:
    virtual int attack() = 0;
    virtual int defense() = 0;
    virtual int applyDamage(int) = 0;
    virtual void setStrength(int) = 0;
    virtual void setArmor(int) = 0;
    virtual int getStrength() = 0;
    virtual int getArmor() = 0;
    virtual void setType(std::string) = 0;
    virtual std::string getType() = 0;
    virtual int cloak() = 0;
    virtual void setAchilles(int) = 0;
    virtual int getAchilles() = 0;
    virtual void setName(std::string) = 0;
    virtual std::string getName() = 0;
    virtual void revive() = 0;
    virtual std::string getTeamName()= 0;
    virtual void setTeamName(std::string) = 0;
    virtual void setScore(double) = 0;
    virtual void addScore(double) = 0;
    virtual double getScore() = 0;
    
    
private:
    int Armor;
    int Strength;
    int Achilles;
    std::string type;
    std::string name;
    std::string TeamName;
    double Score;
};

class Goblin : public Creature
{
  
public:
    int attack();
    int defense();
    Goblin(std::string);
    int applyDamage(int);
    void setStrength(int);
    void setArmor(int);
    void setAchilles(int);
    int getStrength();
    int getArmor();
    int getAchilles();
    void setType(std::string);
    std::string getType();
    int cloak();
    void setName(std::string);
    std::string getName();
    void revive();
    std::string getTeamName();
    void setTeamName(std::string);
    void setScore(double);
    void addScore(double);
    double getScore();
    
    
private:
    int Armor;
    int Strength;
    int Achilles;
    std::string type;
    std::string name;
    std::string teamName;
    double Score;
};

class Barbarian : public Creature
{
public:
    int attack();
    int defense();
    Barbarian(std::string);
    int applyDamage(int);
    void setStrength(int);
    void setArmor(int);
    void setAchilles(int);
    int getStrength();
    int getArmor();
    int getAchilles();
    void setType(std::string);
    std::string getType();
    int cloak();
    void setName(std::string);
    std::string getName();
    void revive();
    std::string getTeamName();
    void setTeamName(std::string);
    void setScore(double);
    double getScore();
    void addScore(double);
    
private:
    int Armor;
    int Strength;
    int Achilles;
    std::string type;
    std::string name;
    std::string teamName;
    double Score;
};

class ReptilePpl : public Creature
{
public:
    int attack();
    int defense();
    ReptilePpl(std::string);
    int applyDamage(int);
    void setStrength(int);
    void setArmor(int);
    void setAchilles(int);
    int getStrength();
    int getArmor();
    int getAchilles();
    void setType(std::string);
    std::string getType();
    int cloak();
    void setName(std::string);
    std::string getName();
    void revive();
    std::string getTeamName();
    void setTeamName(std::string);
    void setScore(double);
    double getScore();
    void addScore(double);
    
private:
    int Armor;
    int Strength;
    int Achilles;
    std::string type;
    std::string name;
    std::string teamName;
    double Score;
};

class BlueMan :public Creature
{
public:
    int attack();
    int defense();
    BlueMan(std::string);
    int applyDamage(int);
    void setStrength(int);
    void setArmor(int);
    void setAchilles(int);
    int getStrength();
    int getArmor();
    int getAchilles();
    void setType(std::string);
    std::string getType();
    int cloak();
    void setName(std::string);
    std::string getName();
    void revive();
    std::string getTeamName();
    void setTeamName(std::string);
    void setScore(double);
    double getScore();
    void addScore(double);
    
private:
    int Armor;
    int Strength;
    int Achilles;
    std::string type;
    std::string name;
    std::string teamName;
    double Score;
};

class Shadow : public Creature
{
public:
    int attack();
    int defense();
    int cloak();
    Shadow(std::string);
    int applyDamage(int);
    void setStrength(int);
    void setArmor(int);
    void setAchilles(int);
    int getStrength();
    int getArmor();
    int getAchilles();
    void setType(std::string);
    std::string getType();
    void setName(std::string);
    std::string getName();
    void revive();
    std::string getTeamName();
    void setTeamName(std::string);
    void setScore(double);
    double getScore();
    void addScore(double);
    
private:
    int Armor;
    int Strength;
    int Achilles;
    std::string type;
    std::string name;
    std::string teamName;
    double Score;
};
#endif /* Creature_hpp */
