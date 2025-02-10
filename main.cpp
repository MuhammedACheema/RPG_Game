#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Battle.h"

void displayMenu() {
    std::cout << "Welcome to the RPG Game!\n";
    std::cout << "Choose your class:\n";
    std::cout << "[1] Warrior\n";
    std::cout << "[2] Mage\n";
    std::cout << "[3] Rogue\n";
    std::cout << "Enter your choice: ";
}

Character* createEnemy() {
    int enemyType = rand() % 3;  // Random enemy selection
    if (enemyType == 0) {
        return new Character("Goblin", 80, 12, 5, 7, 80);
    } else if (enemyType == 1) {
        return new Character("Orc", 100, 15, 8, 6, 100);
    } else {
        return new Character("Dark Knight", 120, 18, 10, 5, 120);
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    displayMenu();
    
    int choice;
    std::cin >> choice;

    Character* player;
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

    // Generate a random enemy
    Character* enemy = createEnemy();

    // Start the battle
    Battle::startBattle(*player, *enemy);

    // Cleanup allocated memory
    delete player;
    delete enemy;

    return 0;
}
