/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Copyright (c) 2026 J. Järvenpää <jarvenja@gmail.com>
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iomanip>
#include <iostream>
#include <string>
#include "hailstone.h"
using namespace std;

void appendSequence(uint64_t n, TArray& a) {
    for (a.push_back(n); n > LSB; a.push_back(n)) {
        n & 1 ? n = odd(n) : n >>= 1;
    }
}

int bitcount(uint64_t bits) {
    int set = 0;
    for (uint64_t i = LSB << 63; i; i >>= 1) {
        if (bits & i) ++set; 
    }
    return set;
}

int hsb(uint64_t bits) {
    int i = 0;
    while (bits >> i) ++i;
    return i;
}

uint64_t odd (uint64_t n) {
    if (n > MAX_N) {
        printError("Number overflow!");
        exit(1);
    }
    n += n++ << 1;
    return n;
}

void printBitRow(uint64_t n, ostream& out) {
    const int w = hsb(n);
    out << setfill(' ') << setw(64 - w);
    for (uint64_t i = LSB << (w - 1); i; i >>= 1) {
        out << ((n & i) ? SET_BIT : CLEAR_BIT);
    }
    out << GREEN0 << ' ' << bitcount(n) << ' ' << (n & LSB ? GREEN1 : GREEN0) << n << CLR << endl;
}

void printError(const char* msg) {
    cerr << RED1 << "Error: " << msg << CLR << endl;
}

void printHexSequence(uint64_t n) {
    printSequence(n, cout << hex);
}

void printOctaSequence(uint64_t n) {
    printSequence(n, cout << oct);
}

void printSequence(uint64_t n, ostream& out) {
    TArray a;
    appendSequence(n, a);
    out << GREEN0;
    for (auto e : a) out << e << " ";
    out << CLR << "\n-=- Total of " << dec << a.size() << " items. -=-\n";
}

void printSequence(uint64_t n, ostream& out, const char* delim) {
    for (out << n; n > 1; out << delim << n) {
        n & 1 ? n = odd(n) : n >>= 1;
    }
}

void printSequenceRows(uint64_t n, ostream& out) {
    for (printBitRow(n, out); n > LSB; printBitRow(n, out)) {
        n & 1 ? n = odd(n) : n >>= 1;
    }
}
