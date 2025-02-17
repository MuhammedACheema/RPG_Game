#ifndef QUEST_H
#define QUEST_H

#include <iostream>
#include "Mage.h"
#include "Character.h"
#include "Warrior.h"
#include "Rogue.h"
#include "Battle.h"


class Quest: public Battle{
    public:
        int battle_counter = 6;
        Item reward = {"Sword of Conquerers", "weapon", 15};
        bool complete = false;
        Character Dark = Character ("Dark Knight", 200, 18, 10, 5, 200);


        void trackProgress(Character &player){
            if (complete) {
                std::cout << "You have already completed this quest.\n";
                return;
            }            
            std::cout << "Quest Started: Defeat 5 enemies, then face the " << Dark.name << ".\n";
            while(battle_counter > 1){
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
                std::cout << "There are " << battle_counter << "'s remaining\n";
            }

            if(battle_counter == 1){
                std::cout << "Congrats you have made it to the boss round! Prepare to fight " << Dark.name << "!" << std::endl;
                std::cout << Dark.name << " Stats -> HP: " << Dark.health << " | ATK: " << Dark.attack << " | DEF: " << Dark.defense << " | SPD: " << Dark.speed << std::endl;

                bool result = startBattle(player, Dark);  // ✅ Store battle result

                if(result == false){
                    std::cout << "Game Over! " << player.name << " was defeated by " << Dark.name << ".\n";
                    return;  // ✅ Exit Quest
                } 
                else {  // ✅ If the player wins
                    std::cout << "Good job! " << player.name << " defeated " << Dark.name << "!\n";
                    complete = true;
                }
                battle_counter -= 1;  // ✅ Reduce remaining battles
            }
            if(complete){
                std::cout << "Congrats " << player.name << ", you have completed Quest Mode and defeated the " << Dark.name << "! We are in your debt.\n";
                player.additems(reward);
                std::cout << "You received: " << reward.name << " (" << reward.type << ", +" << reward.effect << ")" << std::endl;
                battle_counter = 6;
            }
        }

        void displayQuestStatus() {
            if (complete) {
                std::cout << "Quest Status: Completed\n";
            } else {
                std::cout << "Quest Status: In Progress - Battles Remaining: " << battle_counter << std::endl;
            }
        }
        

};

#endif