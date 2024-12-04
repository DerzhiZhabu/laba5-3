#ifndef VICTIMS_H
#define VICTIMS_H

#include "animals.h"
#include <string>

class Victim: public Animal{
    public:

    Victim(int x, int y, int d, int k, std::string name): Animal(x, y, d, k, name){
        type = ANIMALS_TYPES::VICTIM;
        age = 12;
        cells_move = 1;
    }

    bool reproduct(){
        return age_counter == 5 || age_counter == 10;
    }

    void move(int n, int m){
        switch(dir){
            case(DIRECTIONS::UP):
                y -= cells_move;
                break;
            case(DIRECTIONS::DOWN):
                y += cells_move;
                break;
            case(DIRECTIONS::LEFT):
                x -= cells_move;
                break;
            case(DIRECTIONS::RIGHT):
                x += cells_move;
                break;
        }

        turn_counter++;

        rotate();

        check_pos(n, m);
    }

};

#endif