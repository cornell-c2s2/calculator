
//------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------
// Valid inputs: Basic math (+, -, *, /), Constructing matrices
// Formatting: no spacing between digits (ex: "12" can't be typed as "1 2")
// Will print nothing if input is bad

#include <iostream>
#include <cstring>
#include "InputParser.cpp"
using namespace std;

int main() {
  bool badInput = false;
  bool quit = false;

  cout << "Enter your input below:" << endl;

  while (!badInput && !quit) {
    cout << "> "; // Enter calculation
    string input;
    getline(cin, input);
    cout << "\n";
    char arr[input.length() + 1];
    strcpy(arr, input.c_str());
    char* tokens = strtok(arr, " ");

    string bop_arr[3];

    int idx = 0; // keeps track of which token we're on
    while (tokens != NULL) {
      if (strcmp(tokens, "quit") == 0) {
        quit = true;
      }
      if (idx < 3) {
        bop_arr[idx] = tokens;
      }
      tokens = strtok(NULL, " ");
      idx++;
    }

    bop(bop_arr);
    
  }
  return 0;
}