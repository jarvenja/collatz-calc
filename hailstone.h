#ifndef HAILSTONE_H
#define HAILSTONE_H
#include <stdint.h>
#include <climits>
#include <vector>
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Functions for calculating hailstone sequence
 * 
 * Copyright (c) 2026 J. Järvenpää <jarvenja@gmail.com>
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
const char
    *const BLUE0="\033[0;34m",
    *const BLUE1="\033[1;34m",
    *const CLEAR_BIT="\033[0;32m0",
    *const CLR="\033[0m",
    *const FOLLOWS= " → ",
    *const GREEN0="\033[0;32m",
    *const GREEN1="\033[1;32m",
    *const RED0="\033[0;31m",
    *const RED1="\033[1;31m",
    *const SET_BIT="\033[1;32m1";
const u_int64_t
    LSB = 1UL,
    MAX_N = ULLONG_MAX / 3;
typedef std::vector<uint64_t> TArray;
void appendSequence(uint64_t, TArray&);
int bitcount(uint64_t);
int hsb(uint64_t bits);
uint64_t odd(uint64_t);
void printBitRow(uint64_t, std::ostream&);
void printError(const char* msg);
void printHexSequence(uint64_t n);
void printOctaSequence(uint64_t n);
void printSequence(uint64_t, std::ostream&);
void printSequenceRows(uint64_t, std::ostream&);
#endif // HAILSTONE_H
