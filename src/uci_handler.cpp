#include "uci_handler.h"
#include "evaluation.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <boost/multiprecision/gmp.hpp>

// Board Representation:
// PPPPPPPPCCCCM + 256 bits of piece data
// For piece id, see evaluation.cpp
// P = valid file to be en passanted
// Most Significant = a rank, Least Significant = h rank

// C = castling rights
// Order from MSD to LSD:
// wk, wq, bk, bq

// M = side to move
// 0 = white, 1 = black

// 0000000011110 0011010101000010000101000101001101100110011001100110011001100110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001110111011101110111011101110111010111101110010101001110011011011

// uint8_t startpos[32] = {"00110101", "01000010", "00010100", "01010011", "01100110", "01100110", "01100110", "01100110", "00000000", "00000000", "00000000", "00000000", "00000000", "00000000", "00000000", "00000000", "00000000", "00000000", "00000000", "00000000", "00000000", "00000000", "00000000", "00000000", "11101110", "11101110", "11101110", "11101110", "10111101", "11001010", "10011100", "11011011"};
// boost::multiprecision::mpz_int boardtest;
// mpz_init(boardtest);
// mpz_import(boardtest, sizeof(startpos), 1, sizeof(startpos[0]), 0, 0, startpos);



std::string getNthWord(const std::string& str, int n) {
    std::stringstream ss(str); // Step 1: Split the string into words
    std::vector<std::string> words;
    std::string word;
    while (ss >> word) {
        words.push_back(word); // Store the words in a vector
    }
    if (n <= words.size()) { // Check if the position is valid
        return words[n]; // Step 3: Return the word at the position specified by the integer
    }
    return ""; // Return an empty string if the position is not valid
}

void handleInput(std::string input) {
    std::string firstWord = getNthWord(input, 0);
    //                                 <||>
    std::string startpos = "00000000111100011010101000010000101000101001101100110011001100110011001100110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001110111011101110111011101110111010111101110010101001110011011011";
    boost::multiprecision::mpz_int boardtest;
    mpz_set_str(boardtest.backend().data(), startpos.c_str(), 2);
        
    if (firstWord == "uci") {
        std::cout << "id name BTBT Chess Bot\nid author King\nuciok" << std::endl;
    } else if (firstWord == "isready") {
        std::cout << "readyok" << std::endl;
    } else if (firstWord == "ucinewgame") {
        // TODO: Implement newgame logic
    } else if (firstWord == "debug") {
        if (getNthWord(input, 1) == "true") {
            // TODO: Add an extern debug bool
        } else if (getNthWord(input, 1) == "false") {
            // TODO: Add an extern debug tool
        } else {
            std::cout << "Unknown argument: " << getNthWord(input, 1) << std::endl;
        }
    } else if (firstWord == "quit") {
        exit(0);
    } else if (firstWord == "test") {
        std::cout << eval(boardtest) << std::endl;
    } else {
        std::cout << "Unknown command: " << firstWord << std::endl;
    }
}