#ifndef MANE_H
#define MANE_H
#include <iostream>
#include "Character.h"

class Mane: public Character{
    public:
        int Mana;

    Mane(std::string n, int Mana){
        this -> name = n;
        this -> health = 90;
        this -> attack = 30;
        this -> defense = 5;
        this -> Mana = Mana; //Mana Points allows the Mane to cast spells.
    }

    void fireBall(Character &enemy){
        if(Mana < 10){
            std::cout << "You cannot cast a fireball you only have " << Mana << " mp, you need atleast 10mp" << std::endl;
            return;
        }

        if(Mana >= 10){
            float damage = 50;
            Mana -= 10;
            enemy.takeDamage(damage);
        }
    }

    void arcaneShield(){
        if(Mana < 5){
            std::cout << "You cannot cast an Arcane Shielf you only have " << Mana << " mp, you need atleast 5mp" << std::endl;
            return;
        }

        if(Mana >= 5){
            defense += 10;
            Mana -= 5;
            std::cout << "You have successfully activated the arcaneShield" << std::endl;
        }
    }
};

#endif