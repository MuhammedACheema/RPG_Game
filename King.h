#ifndef KING_H
#define KING_H
#include <iostream>
#include "Character.h"

class King: public Character{
    public:

        bool swap = true;
        int stamina;

        King(std::string n, int stamina){
            this -> name = n;
            this -> health = 300;
            this -> attack = 40;
            this -> defense = 25;
            this -> speed = 8;
            this -> dodge = false;
            this -> maxhealth = 300;
            this -> stamina = stamina;
        }

        void regainStamina() {
            stamina += 5;
            if (stamina > 40) stamina = 40; // Prevent exceeding max stamina
            std::cout << name << " regenerates 5 Stamina. Current Stamina: " << stamina << std::endl;
        }
        
        void royalSlam(Character &enemy){
            if(stamina >= 20){
                int damage = attack * 2;
                stamina -= 20;
                std::cout << "The King is done playing games! " << enemy.name << "takes " << damage << std::endl;
                enemy.takeDamage(damage);
            }

            else{
                std::cout << "not enough stamina you only have " << stamina << "stamina\n";
                return;
            }
        }

        void royalDecree(Character &enemy){
            if(health < 50 && enemy.health > health && stamina >= 10 && swap == true){
                float temp = enemy.health;
                enemy.health = health;
                health = temp;
                stamina -= 10;
                swap = false;
                std::cout << "You dare battle the king, he has now decreed we swap health, and let me use your health your health is now " << enemy.health << "hp and the king now has " << health << "hp\n";
            }

            else{
                std::cout << "The king has failed to use Royal Decree" <<std::endl;
                return;
            }
        }

        void displayKing(){
            std::cout << "You are now challenging the king, you will now face his wrath, he has two special abilities \n";
            std::cout << "[1] RoyalSlam – A devastating blow (2x ATK) but costs 20 Stamina. \n";
            std::cout << "[2] RoyalDecree – Swap health with your opponent if below 50 HP. Costs 10 Stamina. One-time use.\n";
        }
};

#endif