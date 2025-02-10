#ifndef MAGE_H
#define MAGE_H
#include <iostream>
#include "Character.h"

class Mage: public Character{
    public:
        int Mana;

    Mage(std::string n, int Mana){
        this -> name = n;
        this -> health = 90;
        this -> attack = 10;
        this -> defense = 5;
        this -> Mana = 15; //Mana Points allows the Mage to cast spells.
        this -> speed = 12;
        this -> dodge = false;
        this -> maxhealth = 90;
        
    }

    void fireBall(Character &enemy){
        if(Mana < 10){
            std::cout << "You cannot cast a fireball you only have " << Mana << " mp, you need atleast 10mp" << std::endl;
            return;
        }

        else{
            float damage = 50;
            Mana -= 10;
            std::cout << name << " casts Fireball! It deals " << damage << " damage to " << enemy.name << "!" << std::endl;
            enemy.takeDamage(damage);
        }
    }

    void arcaneShield(){
        if(Mana < 5){
            std::cout << "You cannot cast an Arcane Shield you only have " << Mana << " mp, you need atleast 5mp" << std::endl;
            return;
        }

        else {
            defense += 10;
            Mana -= 5;
            std::cout << "You have successfully activated the Arcane Shield! Defense increased by 10!" << std::endl;
        }
    }

    void regenerateMana() {
        Mana += 3;
        if (Mana > 100) Mana = 100; // Prevent exceeding max mana
        std::cout << name << " regenerates 3 Mana. Current MP: " << Mana << std::endl;
    }

    void basicAttack(Character &enemy){
            std::cout << name << " seems to be lacking mp, thank god for this lightning bolt it deals " << attack << " damage to " << enemy.name << "!" << std::endl;
            enemy.takeDamage(attack);
    }

    void heal() {
        const int healAmount = 30;
        const int manaCost = 12;

        if (Mana < manaCost) {
            std::cout << "You cannot cast Heal! You only have " << Mana << " MP, but need at least " << manaCost << " MP." << std::endl;
            return;
        }

        // Prevent overhealing
        if (health == maxhealth) {  // Assuming max HP is 90 for a Mage
            std::cout << name << " is already at full health! Heal was not cast." << std::endl;
            return;
        }

        // Ensure health does not exceed max HP
        if (health + healAmount > maxhealth) {
            health = maxhealth; // Set health to max HP instead of exceeding it
        } else {
            health += healAmount;
        }

        Mana -= manaCost;
        std::cout << name << " successfully cast Heal! HP restored by " << healAmount << ". Current HP: " << health << std::endl;
    }
};

#endif