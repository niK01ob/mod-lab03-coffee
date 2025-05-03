#include "Automata.h"

#include <iostream>
#include <string>

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        getState();
    }
    else {
        std::cout << "Already working" << std::endl;
    }
}

void Automata::off() {
    if (state == WAIT) {
        change();
        state = OFF;
        getState();
    }
    else {
        if (state != OFF) {
            std::cout << "Wait, machine working now" << std::endl;
        }
    }
}

void Automata::coin(int money) {
    if (state == WAIT || state == ACCEPT) {
        cash += money;
        state = ACCEPT;
        getState();
    }
    else {
        std::cout << "Incorrect action" << std::endl;
    }
}

void Automata::getMenu() {
    for (int i = 0; i < menu.size(); ++i) {
        std::cout << menu[i] << " " << prices[i] << std::endl;
    }
}

STATES Automata::getState() {
    std::cout << state << std::endl;
    return state;
}

void Automata::choice(std::string drink) {
    if (state == ACCEPT) {
        if (find(menu.begin(), menu.end(), drink) == menu.end()) {
            std::cout << "Drink not from menu" << std::endl;
            cancel();
        }
        else {
            state = CHECK;
            getState();
            check(drink);
        }
    }
}

void Automata::cancel() {
    if (state != OFF) {
        state = WAIT;
    }
}

int Automata::getCash() {
    return cash;
}

void Automata::change() {
    if (state == WAIT) {
        if (cash > 0) {
            std::cout << "Change: " << cash << std::endl;
            cash = 0;
        }
    }
}

void Automata::check(std::string drink) {
    if (state == CHECK) {
        auto it = find(menu.begin(), menu.end(), drink);
        int idx = distance(menu.begin(), it);
        int priceOfCoffee = prices[idx];
        if (cash < priceOfCoffee) {
            std::cout << "Cash is so small" << std::endl;
            cancel();
        }
        else {
            cash -= priceOfCoffee;
            cook();
        }
    }
    else {
        std::cout << "Ivalid state" << std::endl;
    }
}

void Automata::cook() {
    std::cout << "Prepared" << std::endl;
    auto start = std::chrono::steady_clock::now();
    auto duration = std::chrono::seconds(5);
    auto printingState = std::chrono::seconds(2);
    state = COOK;
    while (std::chrono::steady_clock::now() - start < duration) {
        if (std::chrono::steady_clock::now() - start == printingState) getState();
    }
    std::cout << "Done!" << std::endl;
    finish();
}

void Automata::finish() {
    state = WAIT;
    getState();
}
