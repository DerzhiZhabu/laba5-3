#include <string>
#include <iostream>
#include "predators.h"
#include "victims.h"
#include "list.h"

using namespace std;

class Game{
    private:

    int n;
    int m;
    int t;

    List<Animal*> animals;

    bool same_pos(Animal* first, Animal* second){
        return first->pos_x() == second->pos_x() && first->pos_y() == second->pos_y();
    }

    void move(){
        for(int i = 0; i < animals.length; i++){
            if(!animals[i]->dead()) animals[i]->move(n, m);
        }
    }

    void eat(){

        for(int i = 0; i < animals.length; i++){
            if (animals[i]->get_type() == ANIMALS_TYPES::PREDATOR && !animals[i]->dead()){
                for(int j = 0; j < animals.length; j++){
                    if (animals[j]->get_type() == ANIMALS_TYPES::VICTIM && same_pos(animals[i], animals[j]) && !animals[j]->dead()){
                        animals[i]->eat();
                        animals[j]->die();
                    }
                }
            }
        }
    }

    void age(){
        for(int i = 0; i < animals.length; i++){
            if (!animals[i]->dead()){
                animals[i]->aging();
            }
        }
    }

    void create_copy(Animal* to_copy){
        Animal* new_animal;

        int x = to_copy->pos_x();
        int y = to_copy->pos_y();
        int k = to_copy->get_k();
        int d = to_copy->get_d();
        string name = to_copy->get_name();

        if (to_copy->get_type() == ANIMALS_TYPES::PREDATOR) new_animal = new Predator(x, y, d, k, name);
        else new_animal = new Victim(x, y, d, k, name);

        animals.push(new_animal);
    }

    void reproduct(){
        for(int i = 0; i < animals.length; i++){
            if (!animals[i]->dead()){
                if (animals[i]->get_type() == ANIMALS_TYPES::PREDATOR){
                    while(animals[i]->reproduct()){
                        create_copy(animals[i]);
                    }
                }
                else{
                    if (animals[i]->reproduct()) create_copy(animals[i]);
                }
            }
        }
    }

    void dying(){
        for(int i = 0; i < animals.length; i++){
            if (!animals[i]->dead()){
                animals[i]->is_dying();
            }
        }
    }

    public:

    Game(int n, int m, int t){
        this->n = n;
        this->m = m;
        this->t = t;
    }

    void play(){
        while (t > 0){
            print();
            t--;
            move();
            eat();
            age();
            reproduct();
            dying();
        }

        print();
    }

    void gen_predators(int count){
        while (count > 0){
            count--;
            int x, y, d, k;

            cin >> x;
            cin >> y;
            cin >> d;
            cin >> k;

            Animal* new_animal = new Predator(x, y, d, k, "Wolf");

            animals.push(new_animal);
        }
    }

    void gen_victims(int count){
        while (count > 0){
            count--;
            int x, y, d, k;

            cin >> x;
            cin >> y;
            cin >> d;
            cin >> k;

            Animal* new_animal = new Victim(x, y, d, k, "Rabbit");
            
            animals.push(new_animal);
        }
    }

    void print(){
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int counter = 0;
                for(int k = 0; k < animals.length; k++){
                    if (animals[k]->pos_x() == j && animals[k]->pos_y() == i && !animals[k]->dead()){
                        if (animals[k]->get_type() == ANIMALS_TYPES::PREDATOR) counter -= 1;
                        if (animals[k]->get_type() == ANIMALS_TYPES::VICTIM) counter += 1;
                    }
                }
                if (counter == 0) cout << '*';
                else cout << counter;
            }
            cout << endl;
        }

        cout << endl;
    }

};

int main(){
    int n, m, t, p, v;

    cin >> n;
    cin >> m;
    cin >> t;

    Game game(n, m, t);

    cin >> p;
    cin >> v;

    game.gen_predators(p);
    game.gen_victims(v);
    game.play();

}