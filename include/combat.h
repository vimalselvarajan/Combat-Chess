#pragma once

#include "../include/piece.h"
#include "../include/Game.h"
#include <iostream>
#include <iomanip>

class Combat {
private:
    Piece* attacker;
    Piece* defender;
    Display* display;
    Game* game;
    int turnCounter = 1;

    bool attemptAttack(Piece* attacker, Piece* defender) {
        int hitChance = rand() % 100;
        if (hitChance < attacker->getAcc()) {
            defender->takeDamage(attacker->getAtk());
            return true;
        }
        return false;
    }

public:
    Combat(Piece* attacker, Piece* defender, Display* display, Game* game) 
        : attacker(attacker), defender(defender), display(display), game(game) {}

    int startCombat() {
        std::cout << "------------------------------------\n";
        std::cout << "         Combat initiated!          \n";
        std::cout << "------------------------------------\n";
        
        std::cin.ignore();
        // combat loop
        while (attacker->getHp() > 0 && defender->getHp() > 0) {
            
            display->displayStats(attacker, defender, turnCounter);

            std::cout << colorToString(attacker->getColor()) << " " << pieceToString(attacker->getType()) << "'s turn! Press Enter to attack...";
            std::cin.ignore();

            if (attemptAttack(attacker, defender)) {
                std::cout << " > " << colorToString(attacker->getColor()) << " " << pieceToString(attacker->getType()) << "'s attack hits!\n";
            } else {
                std::cout << " > " << colorToString(attacker->getColor()) << " " << pieceToString(attacker->getType()) << " swings and misses!\n";
            }

            std::cout << "\n";

            if (defender->getHp() <= 0) break;

            std::swap(attacker, defender); // swap roles for next round
            turnCounter++; // inc turn counter
        }

        // end combat loop, display results


        if (turnCounter % 2 != 0) {
            if (attacker->getHp() <= 0) {
                std::cout << pieceToString(attacker->getType()) << " has been defeated!\n";
                delete attacker;
                return 1;
            } else {
                std::cout << pieceToString(defender->getType()) << " has been defeated!\n";
                delete defender;
                return 0;
            }
        }
        else {
            if (attacker->getHp() <= 0) {
                std::cout << pieceToString(attacker->getType()) << " has been defeated!\n";
                delete attacker;
                return 0;
            } else {
                std::cout << pieceToString(defender->getType()) << " has been defeated!\n";
                delete defender;
                return 1;
            }
        }
        return -1;

        // ADD PRINT STATS HERE

        /* 
         check if king died 
         ------------------
         takeDamage() ensures if HP goes below 0, it's set to 0
         therefore when ui.cpp checks black and white king HP in Game.cpp
         this check is handled
        */ 
    }
};
