/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Copyright (c) 2026 J. Järvenpää <jarvenja@gmail.com>
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>
#include "hailstone.h"
using namespace std;
int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout
            << GREEN1 << "<><><> Collatz conjecture calculator <><><>\n"
            << GREEN0 << "Prints a Hailstone sequence from given number n\nUsage: "
            << argv[0] << " [ b1101 | 007 | 1234 | 0xffff ]\n" 
            << "<> Copyright (c) 2026 J. Järvenpää <jarvenja@gmail.com>" << CLR << endl;
    } else if (argc == 2) {
        uint64_t n = 0;
        int base = 0;
        char* pEnd = 0;
        const char* p = argv[1];
        if (*p == 'b') { // bin
            while(*++p == '0'); // eat ur padding                     
            n = strtoull(p, &pEnd, base = 2);
            if (n == 0) printError("Invalid binary number!");
            else printSequenceRows(n, cout);            
        } else if (*p == '0') { // hex or octa
            if (p[1] == 'x') {
                n = strtoull(p, &pEnd, base = 16);
                printHexSequence(n);
            } else { // also single zero is assumed octal
                n = strtoull(p, &pEnd, base = 8);
                printOctaSequence(n);
            } 
        } else { // assume decimal
            n = strtoull(p, &pEnd, 0);
            if (n == 0) printError("Invalid decimal number!");
            else printSequence(n, cout);            
        }
    } else printError("Too many arguments!");
    return 0;
}
