#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <vector>
#include <random>

struct Item {
    std::string name;   // "Health Potion"
    std::string type;   // "Potion"
    int effect;         // 30 (heals 30 HP)
};

class Character{
    public:
        std::string name;
        float health;
        float attack;
        float defense;
        int level;
        int XP;
        std::vector <Item> inventory;
        int speed;
        bool dodge;
        int maxhealth;
        int dodgeTurns;

        // ✅ Make the class polymorphic by adding a virtual destructor
        virtual ~Character() {}  // 👈 This makes `Character` polymorphic

        Character(){
            name = "unknown";
            health = 100;
            attack = 10;
            defense = 5;
            level = 1;
            XP = 0;
            speed = 5;
            dodge = false;
            maxhealth = 100;
            dodgeTurns = 0;
        }

        Character(std::string name, float health, float attack, float defense, int speed, int maxhealth){
            this -> name = name;
            this -> health = health;
            this -> attack = attack;
            this -> defense = defense;
            this -> speed = speed;
            this -> maxhealth = maxhealth;
            level = 1;
            XP = 0;
            dodge = false;
            dodgeTurns = 0;
        }

        void levelup(){
            while(XP >= 100){
                level += 1; // gain a level 
                XP -= 100; //will lower the xp properly 

                maxhealth += 10;
                health = maxhealth;
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
            if (dodge) {
                std::cout << name << " dodged the attack!" << std::endl;
                dodgeTurns--;  // ✅ Reduce dodge duration
                if (dodgeTurns == 0) {
                    dodge = false;  // ✅ Remove dodge after the turn
                    std::cout << name << " is no longer dodging!" << std::endl;
                }
                return;  // ✅ Avoid taking damage
            }

            float damage = enemyattack - defense;
            if (damage < 1) damage = 1;
            health -= damage;
            std::cout << name << " took " << damage << " damage! Remaining HP: " << health << std::endl;
        }


        void attackenemy(Character &enemy){
            std::cout << name << "attacks" << enemy.name << std::endl;
            enemy.takeDamage(attack);
        }

        void additems(Item item){
            inventory.push_back(item);
            std::cout << "Added " << item.name << " to inventory!" << std::endl;
        }

        void useitems(std::string item){
            for(int i = 0; i < inventory.size(); i++){
                if(inventory[i].name == item){
                    if(inventory[i].type == "potion"){
                        health += inventory[i].effect;
                        if (health > maxhealth) health = maxhealth;  // Prevent overhealing
                        std::cout << name << " used " << item << "! Restored " << inventory[i].effect << " HP.\n";
                    }
                }
                else if(inventory[i].name == item){
                    if(inventory[i].type == "weapon"){
                        attack += inventory[i].effect;
                        std::cout << name << " equipped " << item << "! Attack increased by " << inventory[i].effect << ".\n";
                }
                inventory.erase(inventory.begin() + i);  // Remove item if used
                return;
                }
            }
            std::cout << "Item not found in inventory!\n";
        }

        void showInventory() {
            std::cout << name << "'s Inventory:\n";

            if (inventory.empty()) { 
                std::cout << "Inventory is empty.\n";
                return;
            }

            for (const auto& item : inventory) {
                std::cout << "- " << item.name << " (" << item.type << ") → Effect: " << item.effect << "\n";
            }
        }


         // implement a doging chance where its speed and a random number from 1 to a 100 and if the speed is greater or equal you can dodge and if smaller, then you get damage. 
        void dodgeAttack(){
            int dodge_chance = 1 + rand() % 100;
            if(dodge_chance <= speed){
                dodge = true;
                int damage = 0;
                std::cout << name << " has successfully dodged the attack" << std::endl;
            }
        }
};


#endif

