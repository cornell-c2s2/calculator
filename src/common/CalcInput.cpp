//========================================================================
// InputParser.cpp
//========================================================================
// Implements parsing inputs and calling correct math functions.

#include <iostream>
#include <cstring>
#include <CalcInput.h>
using namespace std;

// True if the string is a valid number, otherwise false.
// TODO: negative numbers, decimals
bool check_number(string num) {
    for (size_t i = 0; i < num.length(); i++) {
        if (!isdigit(num[i])) {
            return false;
        }
    }
    return true;
}

// Handles binary operations and prints output accordingly, or returns nothing when bad input occurs.
void bop(string bop_arr[]) {
    if (check_number(bop_arr[0]) && check_number(bop_arr[2])) {
        int inp1 = stoi(bop_arr[0]);
        int inp2 = stoi(bop_arr[2]);
        string op = bop_arr[1];
        if (op == "+") {
            int res = inp1 + inp2;
            cout << "> " << res << "\n";
        }
        else if (op == "-") {
            int res = inp1 - inp2;
            cout << "> " << res << "\n";
        }
        else if (op == "*") {
            int res = inp1 * inp2;
            cout << "> " << res << "\n";
        }
        else if (op == "/") {
            int res = inp1 / inp2;
            cout << "> " << res << "\n";
        }
        else {
            throw invalid_argument("Bad input");
        }

    }
}


string calculateInput(string input) {
    return "";
}
