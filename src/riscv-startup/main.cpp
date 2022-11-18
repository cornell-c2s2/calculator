/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <stdio.h>
#include <stdlib.h>

// #include <vector>
// #include <iostream>
// void* __dso_handle;
#include <string>
#include <vector>

#include <time.h>       //include Time library (might not need)?
// #include <iostream>

void delay(int number_of_microseconds) //not actually number of seconds
{
  // Converting time into multiples of a hundred nS
  int hundred_ns = 10 * number_of_microseconds;
  
  // Storing start time
  clock_t start_time = clock();
  
  // looping till required time is not achieved
  while (clock() < start_time + hundred_ns);
  
}//end delay

int main() {
  char buffer[20] = {};
  char * buff_pointer = &buffer[0];
  size_t buff_size = 20;

  // for(size_t i = 0;)

  while(true) {
    delay(1000*100);
    std::string test = "Finally\n";
    // std::vector<char> foo{80};
    // const char[] chars = {foo[0]};
    printf("Get input: ");
    // getline(&buff_pointer, &buff_size, stdin);
    // printf(stdin);
    scanf("%19s", buffer);
    // std::getline(std::cin, test);
    // printf(test.c_str());
    // printf("PREPRINT\n");
    // printf(test.c_str());
    printf("buffer: %s", buffer);
    printf("aESTING\n");
    // std::cout << "FOO" << std::endl;
  }
}