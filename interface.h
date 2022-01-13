//
// Created by krasn on 06.01.2022.
//

#include <iostream>
#include "player.h"
#include "diler.h"
#ifndef BLACKJACK_INTERFACE_H
#define BLACKJACK_INTERFACE_H

class Drow {

public:

    

    void printGame(Player &p, Diler &d) {
        cout <<"###############################" << endl;
        cout << "skore: " << d.getSum() << endl;
        cout <<"          Diler                " << endl;
        d.getCards(); cout << endl;
        cout <<"                               " << endl;
        cout <<"                               " << endl;
        cout <<"                               " << endl;
        cout <<"                               " << endl;
        cout <<"                               " << endl;
        p.getCards(); cout << endl;
        cout <<"           You                 " << endl;
        cout <<"skore: " << p.getSum()<<endl;
        cout <<"###############################" << endl;

    }
};

#endif //BLACKJACK_INTERFACE_H
