#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <vector>

class Character{
    public:
        std::string name;
        float health;
        float attack;
        float defense;
        int level;
        int XP;
        std::vector <std::string> inventory;
        int speed;


        Character(){
            name = "unknown";
            health = 100;
            attack = 10;
            defense = 5;
            level = 1;
            XP = 0;
            speed = 5;
        }

        Character(std::string name, float health, float attack, float defense, int speed){
            this -> name = name;
            this -> health = health;
            this -> attack = attack;
            this -> defense = defense;
            this -> speed = speed;
            level = 1;
            XP = 0;
        }

        void levelup(){
            while(XP >= 100){
                level += 1; // gain a level 
                XP -= 100; //will lower the xp properly 

                health += 10; 
                defense += 2;
                attack += 5;
                speed += 1;
                std:: cout << "Congrats you leveled up you are now level: " << level << std::endl;
            }
        }

        void gainXP(int amount){
            XP += amount;
            levelup(); //auto call it in case they gain enough xp to level up
        }

        void takeDamage(float enemyattack){
            float damage = enemyattack - defense;
            if (damage < 0){
                damage = 1;
            }

            health = health - damage;

            std::cout << name << "took " << damage << "damage, you have a remaining hp of " << health << std::endl;

            if(health <= 0 ){
                std::cout << name << "has been defeated!" << std::endl;
            }
            
        }

        void attackenemy(Character &enemy){
            std::cout << name << "attacks" << enemy.name << std::endl;
            takeDamage(attack);
        }

        void additems(std::string items){
            inventory.push_back(items);
        }

        void showInventory(){
            std::cout << name << "'s Inventory:\n"; //will tell you which chatacters inventory it is

            if (inventory.empty()) { 
                std::cout << "Inventory is empty.\n";
                return;
            }

            for (int i = 0; i < inventory.size(); i++){
                std::cout << "-" <<  inventory[i] << std::endl;
            }
        }
};


#endif

