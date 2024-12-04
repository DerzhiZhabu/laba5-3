#ifndef ANIMALS_H
#define ANIMALS_H
#include <string>

enum class DIRECTIONS{
    UP,
    LEFT,
    RIGHT,
    DOWN
};

enum class ANIMALS_TYPES{PREDATOR, VICTIM, ANIMAL};

class Animal{
    protected:

    ANIMALS_TYPES type = ANIMALS_TYPES::ANIMAL;

    bool is_dead = false;

    int cells_move;

    int x;
    int y;

    int k;
    int turn_counter;
    
    int age;
    int age_counter;

    std::string name;

    DIRECTIONS dir;
    int d;


    void rotate(){
        if (k == turn_counter){
            d++;
            choose_dir(d);
            turn_counter = 0;
        }
    }

    void choose_dir(int d){
        if (d == 4){
            d = 0;
        }

        this->d = d;

        switch(d){
            case(0):
                dir = DIRECTIONS::UP;
                break;
            case(1):
                dir = DIRECTIONS::RIGHT;
                break;
            case(2):
                dir = DIRECTIONS::DOWN;
                break;
            case(3):
                dir = DIRECTIONS::LEFT;
                break;
        }
    }

    void check_pos(int n, int m){
        if (y >= m) y %= m;
        if (y < 0) y += m;
        if (x >= n) x %= n;
        if (x < 0) x += n;
    }

    public:

    Animal(int x, int y, int d, int k, std::string name){
        this->name = name;

        this->x = x;
        this->y = y;

        choose_dir(d);
        this->d = d;

        this->k = k;
        turn_counter = 0;

        age_counter = 0;
    }

    ANIMALS_TYPES get_type(){
        return type;   
    }

    void aging(){
        age_counter++;
    }

    void die(){
        is_dead = true;
    }

    bool dead(){
        return is_dead;
    }

    const int pos_x(){
        return x;
    }

    const int pos_y(){
        return y;
    }

    const int get_k(){
        return k;
    }

    const int get_d(){
        return d;
    }

    const std::string get_name(){
        return name;
    }

    void is_dying(){
        if (age == age_counter){
            die();
        }
    }

    virtual bool reproduct(){
        return false;
    }

    virtual void eat(){};

    virtual void move(int n, int m){};
};


#endif
