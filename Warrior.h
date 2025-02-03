#ifndef WARRIOR_H
#define WARRIOR_H
#include <iostream>
#include "Character.h"

class Warrior: public Character {
    public:
        Warrior(std::string n){
            this -> name = n;
            this -> health = 150;
            this -> attack = 20;
            this -> defense = 15;
        }

        void specialAbilities(){
            std::cout << name << " has both a power strike doing 50 percent more damage, and shield block providing 5 more defense points" <<std::endl;
        }

        void powerStrike(Character &enemy){
            float damage = attack * 1.5;
            std::cout << "You just used powerStrike and did " << damage << " damage, and just used it on "<< enemy.name << std::endl;
            enemy.takeDamage(damage);
        }

        void shieldBlock(){
            std::cout << name << " just unleashed their shield and can now take a bit more damage" << std::endl;
            defense += 5; //temp defense boost
        }

        void equipWeapon(std::string sword){
            std::cout << name << ", you have equipped a " << sword << "!" << std::endl;
            additems(sword);
            attack += 5;
        }
};

#endif