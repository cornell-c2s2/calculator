/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <stdio.h>
#include <stdlib.h>

// #include <vector>
// #include <iostream>
// void* __dso_handle;
#include <string>
#include <vector>

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
  for(int i = 0; i < 5; i++) {
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
    delay(1000*10);
    // std::string test = "Finally\n";
    // std::vector<char> foo{80};
    // const char[] chars = {foo[0]};
    printf("Got input: ");
    // getline(&buff_pointer, &buff_size, stdin);
    // printf(stdin);
    // scanf("%19s", buffer);

    int read_int = 0;
    if( metal_tty_getc(&read_int) == 0) {
      buffer[0] = (char)(read_int);
      buffer[1] = 0x00;

    } else {
      buffer[0] = 0x00;
      // break;
    }

    // volatile uint32_t *reg = (volatile uint32_t *)(METAL_SIFIVE_UART0_0_BASE_ADDRESS + METAL_SIFIVE_UART0_RXDATA);
    // uint32_t regval = *reg;
    // if (!(regval & (1<<31))){
    //   buffer[0] = (char)((regval) & 0xff);
    //   buffer[1] = 0x00;

    // } else {
    //   buffer[0] = 0x00;
    //   // break;
    // }

    // std::getline(std::cin, test);
    // printf(test.c_str());
    // printf("PREPRINT\n");
    // printf(test.c_str());
    printf("%s\n", buffer);
    // printf("aESTING\n");
    // std::cout << "FOO" << std::endl;
  }
}