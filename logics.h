//
// Created by krasn on 06.01.2022.
//

#include <windows.h>
#include <string.h>
#include "shoe.h"
#include "player.h"
#include "diler.h"
#include "interface.h"
#include <fstream>
#include <iostream>
#ifndef BLACKJACK_LOGICS_H
#define BLACKJACK_LOGICS_H

using namespace std;

class Game {

private:

public:


    string howIsWin(int psum, int dsum) {

        if (psum == 21) {
            return "BlackJack! Player are winner!";
        } else if (psum > 21) {
            return "Player are loser!";
        } else if (dsum == 21) {
            return "Diler are winner!";
        } else if (dsum > 21) {
            return "Diler are loser!";
        } else if (psum > dsum) {
            "Player are winner!";
        } else if (dsum > psum) {
            return "Diler are winer!";
        }

    }

    void startGame() {

        char move;
        do {
            cout << "Start game(s)\n";
            cout << "Option(o)\n";
            cout << "Exit(e)\n";
            cin >> move;
        } while (move != 's' && move != 'e');

        switch (move) {
            case 's':
                // printGame();
                break;
            case 'o':
                //printOption();
                break;
            case 'e':
                exit(0);
                break;
        }
        system("cls");


        ofstream log("D:\\Project\\BlackJack2.0\\log.txt");
       

        Drow d;
        //d.printMenu();

        Player player;
        Diler diler;
        pair<string, int> playerCard;
        pair<string, int> dilerCard;
        Shoe shoe;
        while (true) {
            log << "#####################\nStart game\n";
            bool flag = 0;//player Stand or not;
            shoe.putInShoe();
            playerCard = shoe.getCard();
            player.HIT(playerCard);
            log << "The player receives a card " << playerCard.first << " Skore: " << player.getSum() << endl;
            dilerCard = shoe.getCard();
            diler.HIT(dilerCard);
            log << "The diler receives a card " << dilerCard.first << " Skore: " << diler.getSum() << endl;
            playerCard = shoe.getCard();
            player.HIT(playerCard);
            log << "The player receives a card " << playerCard.first << " Skore: " << player.getSum() << endl;
            dilerCard = shoe.getCard();
            diler.HIT(dilerCard);
            log << "The diler receives a card " << dilerCard.first << " Skore: " << diler.getSum() << endl;
            cout << "The cards are dealt" << endl;
            d.printGame(player, diler);

            while (player.getSum() < 21 && diler.getSum() < 21) {
                char move;
                cout << "Your case\n";
                cin >> move;
                system("cls");

                //Player's move
                
                if (move == 'h') {
                    playerCard = shoe.getCard();
                    player.HIT(playerCard);
                    log << "The player receives a card " << playerCard.first << " Skore: " << player.getSum() << endl;
                    d.printGame(player, diler);
                    //player.getCards();
                }
                else if (move == 's') {
                    flag = player.STAND();
                    log << "Player SURRENDER\n";
                    while (diler.getSum() <= 16) {
                        dilerCard = shoe.getCard();
                        diler.HIT(dilerCard);
                        log << "The diler receives a card " << dilerCard.first << " Skore: " << diler.getSum() << endl;
                    }
                    d.printGame(player, diler);
                    break;
                }
                

                //Diler's move
                if (diler.getSum() <= 16 && !flag) {
                    dilerCard = shoe.getCard();
                    diler.HIT(dilerCard);
                    log << "The diler receives a card " << dilerCard.first << " Skore: " << diler.getSum() << endl;
                } else {
                    diler.STAND();
                    log << "";
                }
            } //while
            system("cls");
            d.printGame(player, diler);
            cout << howIsWin(player.getSum(), diler.getSum()) << endl;
            log << howIsWin(player.getSum(), diler.getSum()) << endl;

            do {
                cout << "Play again?\nYes(1)\nNo(0)\n";
                cin >> move;
                system("cls");
            } while (move != '1' && move != '0');
            if (move == '1') {
                log << "Play again\n";
                system("cls");
                player.setSum(0);
                player.clearCard();
                diler.setSum(0);
                diler.clearCard();
                shoe.clearShoe();
            } else {
                system("cls");
                log << "END the game\n#####################\n";
                log.close();
                break;
            }
        }


    }//startGame
}; //game

#endif //BLACKJACK_LOGICS_H
