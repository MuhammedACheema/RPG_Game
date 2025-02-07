#include <iostream>
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"

void battle(Character &player, Character &enemy) {
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
        else if (choice == 2) {
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

int main() {
    srand(time(0)); // Random seed

    std::cout << "Welcome to the RPG Game!\nChoose your class:\n";
    std::cout << "[1] Warrior\n";
    std::cout << "[2] Mage\n";
    std::cout << "[3] Rogue\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    Character *player;
    if (choice == 1) {
        player = new Warrior("Warrior", 30);
    } else if (choice == 2) {
        player = new Mage("Mage", 100);
    } else if (choice == 3) {
        player = new Rogue("Rogue");
    } else {
        std::cout << "Invalid choice, defaulting to Warrior.\n";
        player = new Warrior("Warrior", 30);
    }

    // Create an enemy to test battle system
    Character enemy("Goblin", 80, 15, 5, 7, 80);

    // Start the battle
    battle(*player, enemy);

    delete player;
    return 0;
}
