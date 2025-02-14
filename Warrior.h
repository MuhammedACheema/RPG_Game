#ifndef WARRIOR_H
#define WARRIOR_H
#include <iostream>
#include "Character.h"

class Warrior: public Character {
    public:
        int stamina;

        Warrior(std::string n, int stamina){
            this -> name = n;
            this -> health = 150;
            this -> attack = 20;
            this -> defense = 15;
            this -> speed = 10;
            this -> dodge = false;
            this -> maxhealth = 150;
            this -> stamina = stamina;
        }

        void specialAbilities(){
            std::cout << name << " has both a power strike doing 50 percent more damage, and shield block providing 5 more defense points" <<std::endl;
        }

        void strike(Character &enemy){
            if(stamina == 0){
                std::cout << "you don't have any stamina, please wait for stamina to recharge" << std::endl;
            }
            else{
                std::cout << "You just used powerStrike and did " << attack << " damage, and just used it on "<< enemy.name << std::endl;
                enemy.takeDamage(attack);
                stamina -= 1;
            }
        }

        void powerStrike(Character &enemy){
            if (stamina < 10 & stamina > 1){
                std::cout << "you do not have enough stamina, but you just did a regular strike" << std::endl;
                strike(enemy);
            }
            else if(stamina == 0){
                std::cout << "you don't have any stamina, please wait for stamina to recharge" << std::endl;
            }
            else{
                float damage = attack * 1.5;
                std::cout << "You just used powerStrike and did " << damage << " damage, and just used it on "<< enemy.name << std::endl;
                enemy.takeDamage(damage);
                
                stamina -= 10;
            }
        }

        void shieldBlock(){
            std::cout << name << " just unleashed their shield and can now take a bit more damage" << std::endl;
            defense += 5; //temp defense boost
        }

        void equipWeapon(Item &sword){
            std::cout << name << ", you have equipped a " << sword.name << "!" << std::endl;
            if (std::find(inventory.begin(), inventory.end(), sword) == inventory.end()) {
                additems(sword.name, sword.type, sword.effect);
            } else {
                std::cout << sword.name << " is in the vector." << std::endl;
            }
        }

        void regainStamina() {
            stamina += 5;
            if (stamina > 30) stamina = 30; // Prevent exceeding max mana
            std::cout << name << " regenerates 5 Stamina. Current Stamina: " << stamina << std::endl;
        }
};

#endif