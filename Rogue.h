#ifndef ROGUE_H
#define ROGUE_H
#include "Character.h"

class Rogue: public Character{
    public:
        bool Firstturn = true;
        bool poisoned = false;
        int poisonTurns = 0;


        Rogue(std::string n){
            this -> name = n;
            this -> health = 120;
            this -> attack = 25;
            this -> defense = 10;
            this -> speed = 18;
            this -> dodge = false;
            this -> maxhealth = 90;
        }

        void Backstab(Character &enemy){
            if(Firstturn == false){
                std::cout << "can't use that move right now, that can only be used at your first move" << std::endl;
                return;
            }
            Firstturn = false;
            
            if(enemy.speed <= speed && Firstturn == true){
                int damage = attack * 2; 
                std::cout << name << " has successfully pulled off Back Stab, and have dealth 2x damage!" << std::endl;
                enemy.takeDamage(damage);
            }
            else{
                std::cout << "Ahh too slow, you gotta get faster pal" << std::endl;
            }

        }

        // implement a doging chance where its speed and a random number from 1 to a 100 and if the speed is greater or equal you can dodge and if smaller, then you get damage. 


        // need to fix the implementation bc rn since its set to false right away it does nothing
        void evasiveManeuver(){
            std::cout << name << " quickly evades, making it harder to hit for one turn!" << std::endl;
            dodge = true;  // ✅ Enable dodge
            dodgeTurns = 1;  // ✅ Set dodge to last for 1 turn
        }


        void criticalHit(Character &enemy){
            int critical = 1 + rand() % 100; //will give me a random num from 1 - 100

            if(critical <= 25){
                int damage = attack * 3;
                enemy.takeDamage(damage);
                std::cout << enemy.name << " got too cocky, and didn't see that coming he just took " << damage <<" damage" << std::endl;
            }
            else{
                std::cout << name << " got too cocky, and has damaged himself" << std::endl;
                health -= 5;
            }
            Firstturn = false;
        }

        void basicAttack(Character &enemy){
            std::cout << "Thats a good punch" << std::endl;
            enemy.takeDamage(attack);
            Firstturn = false;
        }

        void applyPoison(){
            poisoned = true;
            poisonTurns = 3;  // ✅ Poison lasts for 3 turns
        }

        void takeDamage(float enemyattack){
            if (poisoned) {
                std::cout << name << " takes 5 poison damage!" << std::endl;
                health -= 5;
                poisonTurns--;
                if (poisonTurns == 0) {
                    poisoned = false;
                    std::cout << name << " is no longer poisoned!" << std::endl;
                }
            }
        }



};

#endif