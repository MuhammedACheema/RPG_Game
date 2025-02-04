#ifndef ROGUE_H
#define ROGUE_H
#include "Character.h"

class Rogue: public Character{
    public:
        bool Firstturn = true;
        Rogue(std::string n){
            this -> name = n;
            this -> health = 120;
            this -> attack = 25;
            this -> defense = 10;
            this -> speed = 18;
        }

        void Backstab(Character &enemy){
            if(enemy.speed <= speed && Firstturn == true){
                int damage = attack * 2; 
                std::cout << name << " has successfully pulled off Back Stab, and have dealth 2x damage!" << std::endl;
                enemy.takeDamage(damage);
                Firstturn = false;
            }

            else{
                std::cout << "Ahh too slow, you gotta get faster pal" << std::endl;
                enemy.takeDamage(attack);
            }
        }

        // implement a doging chance where its speed and a random number from 1 to a 100 and if the speed is greater or equal you can dodge and if smaller, then you get damage. 

        // void evasiveManeuver(Rogue &self){
        //     std::cout << "stuff are getting a bit tough out here, lets get out of here real quick" <<std::endl;
        //     Firstturn = false;
        //     self.takeDamage(0);
        // }
};

#endif