/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <stdio.h>
#include <stdlib.h>

// #include <vector>
// #include <iostream>
// void* __dso_handle;

// #include <metal/machine.h>
#include <metal/machine/platform.h>

// #include <metal/lock.h>
// #include <metal/uart.h>
// #include <metal/interrupt.h>
// #include <metal/clock.h>
// #include <metal/led.h>
#include <metal/tty.h>

#include <time.h>       //include Time library (might not need)?
// #include <iostream>
// #include <RingBuffer.h>
#define BUFF_SIZE 32

void delay(int number_of_microseconds) //not actually number of seconds
{
  // Converting time into multiples of a hundred nS
  int hundred_ns = 10 * number_of_microseconds;
  
  // Storing start time
  clock_t start_time = clock();
  
  // looping till required time is not achieved
  while (clock() < start_time + hundred_ns);
  
}//end delay

char get_char() {
  volatile uint32_t *reg = (volatile uint32_t *)(METAL_SIFIVE_UART0_0_BASE_ADDRESS + METAL_SIFIVE_UART0_RXDATA);
  uint32_t regval = *reg;
  char regval_c = (char)regval;

  return regval_c;
}

void read_line(char * buffer, size_t n) {

  // int i = 0;
  // char buffer[1024];
  size_t size = 0;

  while( true ) {
    // printf("size: %u\n", size);
    if( size >= n) {
      break;
    }

    char c = get_char();
    if (c != 0 ) {
      printf("Got char: %c", c);
      buffer[size] = c;
      size++;
    }

    if (c == '\n'){
      break;
    }
  }
}


// void return_foo(std::string& ref) {
//   // ref = "asdf";
// }

int main() {
  char buffer[20] = {};
  // char * buff_pointer = &buffer[0];
  // size_t buff_size = 20;

  // for(size_t i = 0;)
  for(int i = 0; i < 6; i++) {
    delay(1000*100);
    printf("Initialization\n");

    #ifdef __METAL_DT_STDOUT_UART_HANDLE
    printf("stdoutdef\n");
    #endif

    #ifdef FOOBAR
    printf(FOOBAR);
    #endif
  }
  
  while(true) {
    delay(1000*1);
    char line_buf[BUFF_SIZE];
    read_line(line_buf, BUFF_SIZE);
    printf("%s", line_buf);
    fflush(stdout);
  
    // printf("aESTING\n");
    // std::cout << "FOO" << std::endl;
  }
}