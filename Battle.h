#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include "Mage.h"
#include "Character.h"
#include "Warrior.h"
#include "Rogue.h"

class Battle{
    public:
        static void startBattle(Character &player, Character &enemy){
            std::cout << "\nA wild " << enemy.name << " appears! Prepare for battle!\n" << std::endl;

            while (player.health > 0 && enemy.health > 0) {
                // Player Turn
                std::cout << "\nYour Turn! Choose an action:\n";
                std::cout << "[1] Basic Attack\n";
                std::cout << "[2] Special Ability\n";
                std::cout << "[3] Defend\n";
                std::cout << "[4] Check Stats\n";
                std::cout << "Enter your choice: ";
                int choice;
                std::cin >> choice;

                if (choice == 1) {
                    player.attackenemy(enemy);
                } 
                else if (choice == 2) { //edit this so that you can choose the attack type
                    if (player.name == "Warrior") {
                        dynamic_cast<Warrior&>(player).powerStrike(enemy);
                    } else if (player.name == "Mage") {
                        dynamic_cast<Mage&>(player).fireBall(enemy);
                    } else if (player.name == "Rogue") {
                        dynamic_cast<Rogue&>(player).Backstab(enemy);
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
                    continue;  // Skip enemy turn if checking stats
                }

                // Check if enemy is defeated
                if (enemy.health <= 0) {
                    std::cout << enemy.name << " has been defeated! You win!\n";
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
                    break;
                }
            }
        }
};


#endif