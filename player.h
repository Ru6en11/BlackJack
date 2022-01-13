//
// Created by krasn on 06.01.2022.
//

#include "stack.h"
#include <string.h>
#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

using namespace std;

class Player {

private:

    string name = "Player";
    int sum = 0; //sum of card in hand
    Stack<pair<string, int>> cardsInHand;
    int cardCount = 0;

public:

    string getName() {
        return name;
    }

    int getSum() {
        return sum;
    }
    void setSum(int s) {
        sum = s;
    }

    pair<string, int> getCard() {

        pair<string, int> card;
        card = cardsInHand.pop();
        return card;
    }

    void clearCard() {
        cardsInHand.clear();
    }

    void getCards() {
        cardsInHand.print();
    }



    void HIT(pair<string, int> card) {
        cardsInHand.push(card);
        sum += card.second;
        cardCount++;
    }

    bool STAND() {
        return 0;
    }

    bool SURRENDER() {
        return true;
    }

};

#endif //BLACKJACK_PLAYER_H
