#!/bin/sh
#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=
#  Copyright (c) 2026 <jarvenja@gmail.com>
#=#=
okay () { # testCase
    [ $# -gt 0 ] && echo -e "\e[92m<><><><> TEST CASE ${1}: OK\e[0m"
}
#=#= Test Set
./collatz && okay Usage
./collatz b11111111111110101001101 && okay Binary
./collatz 27 && okay "Small Decimal"
./collatz 999999 && okay "Big Decimal"
./collatz 0xfff && okay Hexadecimal
