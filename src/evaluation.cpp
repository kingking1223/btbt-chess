#include "evaluation.h"
#include <boost/multiprecision/gmp.hpp>
#include <bit>

unsigned long long blackQueen = 0;  // 0010  2
unsigned long long blackRook = 0;   // 0011  3
unsigned long long blackBishop = 0; // 0100  4
unsigned long long blackKnight = 0; // 0101  5
unsigned long long blackPawn = 0;   // 0110  6
unsigned long long whiteQueen = 0;  // 1010  10
unsigned long long whiteRook = 0;   // 1011  11 
unsigned long long whiteBishop = 0; // 1100  12
unsigned long long whiteKnight = 0; // 1101  13
unsigned long long whitePawn = 0;   // 1110  14

void seperateBoard(boost::multiprecision::mpz_int board) {
    for (int i = 0; i < 64; i++) {
        unsigned long long chunk = ((board >> (252 - (4 * i))) & 0b1111).convert_to<unsigned long long>(); // Extract a chunk
        unsigned long long bitShift = (1ULL << (63 - i));
        if (chunk == 0b0010) blackQueen |= bitShift; // Set the ith bit to 1
        if (chunk == 0b0011) blackRook |= bitShift;
        if (chunk == 0b0100) blackBishop |= bitShift;
        if (chunk == 0b0101) blackKnight |= bitShift;
        if (chunk == 0b0110) blackPawn |= bitShift;
        if (chunk == 0b1010) whiteQueen |= bitShift;
        if (chunk == 0b1011) whiteRook |= bitShift;
        if (chunk == 0b1100) whiteBishop |= bitShift;
        if (chunk == 0b1101) whiteKnight |= bitShift;
        if (chunk == 0b1110) whitePawn |= bitShift;
    }
}

float eval(boost::multiprecision::mpz_int board) {
    seperateBoard(board);
    int materialDiff = (9 * std::popcount(whiteQueen) + 5 * std::popcount(whiteRook) + 3.5 * std::popcount(whiteBishop) + 3 * std::popcount(whiteKnight)+ std::popcount(whitePawn)) - 
                       (9 * std::popcount(blackQueen) + 5 * std::popcount(blackRook) + 3.5 * std::popcount(blackBishop) + 3 * std::popcount(blackKnight)+ std::popcount(blackPawn));
    return materialDiff;
}