//
// Created by krasn on 06.01.2022.
//

#include "stack.h"
#include <string.h>
#ifndef BLACKJACK_DILER_H
#define BLACKJACK_DILER_H


class Diler {

private:

    string name = "Diler";
    int sum = 0;
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
        if (sum <= 16) {
            cardsInHand.push(card);
            sum += card.second;
            cardCount++;
        }
    }

    bool STAND() {
        if (sum >= 17) return true;
    }
};
#endif //BLACKJACK_DILER_H
