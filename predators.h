#ifndef PREDATORS_H
#define PREDATORS_H

#include "animals.h"
#include <string>

class Predator: public Animal{
    public:

    Predator(int x, int y, int d, int k, std::string name): Animal(x, y, d, k, name){
        type = ANIMALS_TYPES::PREDATOR;
        age = 30;
        cells_move = 2;
        satiety = 0;
    }

    bool reproduct(){
        bool res = satiety >= 2;

        if (res) satiety -= 0;

        return res;
    }

    void eat() {
        satiety++;
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

    private:

    int satiety;
};

#endif