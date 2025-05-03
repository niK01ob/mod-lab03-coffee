#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <algorithm>
#include <chrono>
#include <iostream>
// Copyright 2022 UNN-IASR

#include <string>
#include <vector>

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 public:
    Automata() {
        cash = 0;
        state = OFF;
        menu = { "Americano", "Cappucino", "Espresso", "Latte" };
        prices = { 30, 50, 70, 90 };
    }

    void on();
    void off();
    void coin(int money);
    void getMenu();
    STATES getState();
    void choice(std::string drink);
    void cancel();
    int getCash();
    void change();

 private:
    void check(std::string drink);
    void cook();
    void finish();

    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;
};
#endif  // INCLUDE_AUTOMATA_H_
