//
// Created by krasn on 06.01.2022.
//

#include <iostream>
#include <string.h>
#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H


using namespace std;

class Deck {

private:

    static const int sizeDeck = 52;
    //card(name, value)
    pair<string, int> cards[sizeDeck] = {
            make_pair("|Diamonds 2|", 2), make_pair("|Diamonds 3|", 3), make_pair("|Diamonds 4|", 4), make_pair("|Diamonds 5|", 5), make_pair("|Diamonds 6|", 6), make_pair("|Diamonds 7|", 7),  make_pair("|Diamonds 8|", 8), make_pair("|Diamonds 9|", 9), make_pair("|Diamonds 10|", 10), make_pair("|Diamonds Jack|", 10), make_pair("|Diamonds Queen|", 10), make_pair("|Diamonds King|", 10), make_pair("|Diamonds Ace|", 11),
            make_pair("|Hearts 2|", 2), make_pair("|Hearts 3|", 3), make_pair("|Hearts 4|", 4), make_pair("|Hearts 5|", 5), make_pair("|Hearts 6|", 6), make_pair("|Hearts 7|", 7), make_pair("|Hearts 8|", 8), make_pair("|Hearts 9|", 9), make_pair("|Hearts 10|", 10), make_pair("|Hearts Jack|", 10), make_pair("|Hearts Queen|", 10), make_pair("|Hearts King|", 10), make_pair("|Hearts Ace|", 11), 
            make_pair("|Spades 2|", 2), make_pair("|Spades 3|", 3), make_pair("|Spades 4|", 4), make_pair("|Spades 5|", 5), make_pair("|Spades 6|", 6), make_pair("|Spades 7|", 7), make_pair("|Spades 8|", 8), make_pair("|Spades 9|", 9), make_pair("|Spades 10|", 10), make_pair("|Spades Jack|", 10), make_pair("|Spades Queen|", 10), make_pair("|Spades King|", 10), make_pair("|Spades Ace|", 11),
            make_pair("|Clubs 2|", 2), make_pair("|Clubs 3|", 3), make_pair("|Clubs 4|", 4), make_pair("|Clubs 5|", 5), make_pair("|Clubs 6|", 6), make_pair("|Clubs 7|", 7), make_pair("|Clubs 8|", 8), make_pair("|Clubs 9|", 9), make_pair("|Clubs 10|", 10), make_pair("|Clubs Jack|", 10), make_pair("|Clubs Queen|", 10), make_pair("|Clubs King|", 10), make_pair("|Clubs Ace|", 11)
    };

public:

    int getSizeDeck() {
        return sizeDeck;
    }

    pair<string, int>* getCards() {
        return cards;
    }

    void shuffle() {

        srand(time(NULL));
        for (size_t i = 0; i < sizeDeck; ++i) {
            swap(cards[i], cards[rand() % sizeDeck]);

        }
    }


    void printDeck() {
        for (int i = 0; i < sizeDeck; ++i) {
            cout << cards[i].first << " " << cards[i].second << endl;
        }
    }

};

#endif //BLACKJACK_DECK_H
