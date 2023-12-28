#ifndef EVALUATION_H
#define EVALUATION_H
#include <boost/multiprecision/gmp.hpp>

void zobristHash();
boost::multiprecision::mpz_int eval(boost::multiprecision::mpz_int board);

#endif