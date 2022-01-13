//
// Created by krasn on 06.01.2022.
//

#include "deck.h"
#include "stack.h"
#ifndef BLACKJACK_SHOE_H
#define BLACKJACK_SHOE_H

class Shoe {

private:

    Stack<pair<string, int>> shoe;
    Deck d;
    int size = d.getSizeDeck();
    pair<string, int>* cards = d.getCards();

public:

    void putInShoe() {
        d.shuffle();
        for (int i = 0; i < size; ++i) {
            shoe.push(cards[i]);
        }
    }

    void clearShoe() {
        shoe.clear();
    }


    pair<string, int> getCard() {
        pair<string, int> tmp = shoe.pop();
        return tmp;
    }

};

#endif //BLACKJACK_SHOE_H
