#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include "Mage.h"
#include "Character.h"
#include "Warrior.h"
#include "Rogue.h"

class Battle{
    public:

        static bool startBattle(Character &player, Character &enemy){
            bool win;
            std::cout << "\nA wild " << enemy.name << " appears! Prepare for battle!\n" << std::endl;

            while (player.health > 0 && enemy.health > 0) {
                // Player Turn
                std::cout << "\nYour Turn! Choose an action:\n";
                std::cout << "[1] Basic Attack\n";
                std::cout << "[2] Special Ability\n";
                std::cout << "[3] Defend\n";
                std::cout << "[4] Check Stats\n";
                std::cout << "[5] Use Item\n";
                std::cout << "Enter your choice: ";
                int choice;
                std::cin >> choice;

                if (choice == 1) {
                    player.attackenemy(enemy);
                    if(player.name == "Mage"){
                        dynamic_cast<Mage&>(player).regenerateMana();
                    }
                    else if(player.name == "Warrior"){
                        dynamic_cast<Warrior&>(player).regainStamina();
                    }
                } 
                else if (choice == 2) { //edit this so that you can choose the attack type
                    if (player.name == "Warrior") {
                        int warrior_special;
                        std::cout << "pick your special attack" << std::endl;
                        dynamic_cast<Warrior&>(player).specialAbilities();
                        std::cout << "[1] Power Strike\n";
                        std::cout << "[2] Shield Block\n";
                        std::cout << "Enter your choice: ";
                        std::cin >> warrior_special;
                        dynamic_cast<Warrior&>(player).regainStamina();

                        if(warrior_special == 1){
                            dynamic_cast<Warrior&>(player).shieldBlock();
                        }
                        else if(warrior_special == 2){
                            dynamic_cast<Warrior&>(player).powerStrike(enemy);
                        }
                    } else if (player.name == "Mage") {
                        int mage_special;
                        std::cout << "pick your special attack" << std::endl;
                        std::cout << "[1] Arcane Shield\n";
                        std::cout << "[2] Fire Ball\n";
                        std::cout << "[3] Heal\n";
                        std::cout << "Enter your choice: ";
                        std::cin >> mage_special;
                        dynamic_cast<Mage&>(player).regenerateMana();

                        if(mage_special == 1){
                            dynamic_cast<Mage&>(player).arcaneShield();
                        }
                        else if(mage_special == 2){
                            dynamic_cast<Mage&>(player).fireBall(enemy);
                        }
                        else if(mage_special == 3){
                            dynamic_cast<Mage&>(player).heal();
                        }

                    } else if (player.name == "Rogue") {
                        dynamic_cast<Rogue&>(player).Backstab(enemy);
                        int rogue_special;
                        std::cout << "pick your special attack" << std::endl;
                        std::cout << "[1] Critical Hit\n";
                        std::cout << "[2] Speedy Punch\n";
                        std::cout << "[3] Evasive Maneuver\n";
                        std::cout << "Enter your choice: ";
                        std::cin >> rogue_special;

                        if(rogue_special == 1){
                            dynamic_cast<Rogue&>(player).criticalHit(enemy);
                        }
                        else if(rogue_special == 2){
                            dynamic_cast<Rogue&>(player).speedyPunch(enemy);
                        }
                        else if(rogue_special == 3){
                            dynamic_cast<Rogue&>(player).evasiveManeuver();
                        }
                    }
                } 
                else if (choice == 3) {
                    std::cout << player.name << " raises their guard, reducing incoming damage!" << std::endl;
                    player.defense += 3;
                } 
                else if (choice == 4) {
                    std::cout << "\n--- " << player.name << "'s Stats ---\n";
                    std::cout << "Health: " << player.health << "/" << player.maxhealth << std::endl;
                    std::cout << "Attack: " << player.attack << std::endl;
                    std::cout << "Defense: " << player.defense << std::endl;
                    std::cout << "Speed: " << player.speed << std::endl;
                    if(player.name == "Warrior"){
                        std::cout << "Stamina: " << dynamic_cast<Warrior&>(player).stamina << std::endl;
                    }

                    else if(player.name == "Mage"){
                        std::cout << "Mana: " << dynamic_cast<Mage&>(player).Mana << std::endl;
                    }

                    continue;  // Skip enemy turn if checking stats
                }
                else if (choice == 5) { // Use an item
                    std::cout << "Your Inventory:\n";
                    player.showInventory();
                    std::cout << "Enter item name to use: ";
                    std::string itemName;
                    std::cin >> itemName;
                    player.useitems(itemName);
                }


                // Check if enemy is defeated
                if (enemy.health <= 0) {
                    std::cout << enemy.name << " has been defeated! You win!\n";
                    win = true;
                    player.gainXP(50);
                    break;
                }

                // Enemy Turn
                std::cout << "\n" << enemy.name << "'s Turn!\n";
                int enemyChoice = rand() % 2;
                if (enemyChoice == 0) {
                    std::cout << enemy.name << " attacks!\n";
                    player.takeDamage(enemy.attack);
                } else {
                    std::cout << enemy.name << " defends, increasing their defense!\n";
                    enemy.defense += 2;
                }

                // Check if player is defeated
                if (player.health <= 0) {
                    std::cout << "You have been defeated! Game Over.\n";
                    win = false;
                    
                    break;
                }
            }

            return win;
        }

        void generateEnemy();

        void dungeonMode(Character &player) {
            int battles = 5;  // Fight 5 enemies in a row

            while (battles > 0) {
                Character enemy = generateEnemy();  // ✅ Generate a random enemy
                bool result = startBattle(player, enemy);  // ✅ Store battle result

                if (!result) {  // ✅ If the player loses
                    std::cout << "Game Over! " << player.name << " was defeated by " << enemy.name << ".\n";
                    return;  // ✅ Exit dungeon mode
                } 
                else {  // ✅ If the player wins
                    std::cout << "Good job! " << player.name << " defeated " << enemy.name << "!\n";
                }

                battles -= 1;  // ✅ Reduce remaining battles
            }

            std::cout << "Congratulations! " << player.name << " has completed the dungeon!\n";
        }



};


#endif