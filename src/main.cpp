#include <iostream>
#include <array>
#include <cmath>
#include <algorithm>
#include <cstdint>
#include <system_error>
#include <thread>
#include <unordered_map>
#include <bits/stdc++.h> 
#include <ios>
#include "uci_handler.h"
#include "evaluation.h"

std::string getConsoleLine() {
     // as a precaution add this lines
    std::cin.clear();
    std::cin.ignore( std::numeric_limits<std::streamsize>::max() );

    std::string str;
    std::getline( std::cin, str );
    return str;
}

void inputLoop () {
    std::string uciInput;
    while (true) {
        std::getline(std::cin, uciInput);
        handleInput(uciInput);
    }
}

int main () {
    // Improves Speed
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::unordered_map<std::string,int> coordsTable = {
        {"a8", 0},
        {"b8", 1},
        {"c8", 2},
        {"d8", 3},
        {"e8", 4},
        {"f8", 5},
        {"g8", 6},
        {"h8", 7}
    };

    std::cout << "BTBT Chess Bot 1.0.0-dev-20231104 by King" << std::endl;

    std::thread loopThread(inputLoop);

    loopThread.join();
    
}