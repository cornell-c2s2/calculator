/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <vector>

// #include <metal/machine.h>
#include <metal/machine/platform.h>

#include <metal/uart.h>

#include <time.h>       //include Time library (might not need)?
#include <RingBuffer.h>

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
  for(int i = 0; i < 6; i++) {
    delay(1000*100);
    printf("Initialization\n");
  }
  
  while(true) {
    delay(1000*1);

  }
}