#ifndef QUEST_H
#define QUEST_H

#include <iostream>
#include "Mage.h"
#include "Character.h"
#include "Warrior.h"
#include "Rogue.h"
#include "Battle.h"

// else {
//     return new Character("Dark Knight", 120, 18, 10, 5, 120);
// }

class Quest: public Battle{
    public:
        int battle_counter = 5;
        Item *reward;
        bool complete = false;


        void trackProgress(Character &player){
            while(battle_counter > 0){
                Character* enemy = generateEnemy();  // ✅ Generate a random enemy
                bool result = startBattle(player, *enemy);  // ✅ Store battle result

                if(result == false){
                    std::cout << "Game Over! " << player.name << " was defeated by " << enemy->name << ".\n";
                    delete enemy;
                    return;  // ✅ Exit dungeon mode
                } 
                else {  // ✅ If the player wins
                    std::cout << "Good job! " << player.name << " defeated " << enemy->name << "!\n";
                    delete enemy;
                }

                battle_counter -= 1;  // ✅ Reduce remaining battles
            }

            if(battle_counter == 1){
                Character Dark = Character ("Dark Knight", 200, 18, 10, 5, 200);
                std::cout << "Congrats you have made it to the boss around prepare to fight the dark knight" << std::endl;
                bool result = startBattle(player, Dark);  // ✅ Store battle result

                if(result == false){
                    std::cout << "Game Over! " << player.name << " was defeated by " << Dark.name << ".\n";
                    return;  // ✅ Exit Quest
                } 
                else {  // ✅ If the player wins
                    std::cout << "Good job! " << player.name << " defeated " << Dark.name << "!\n";
                }

                battle_counter -= 1;  // ✅ Reduce remaining battles
            }

            // provide a reward
            }

};

#endif