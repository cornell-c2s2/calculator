/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <stdio.h>
#include <stdlib.h>

// #include <vector>
// #include <iostream>
// void* __dso_handle;
#include <string>
#include <vector>
#include <cstring>

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

class HiFiveUart {
  char buffer[1024];
 
  public:
  HiFiveUart();
  char get_char();
  char * get_line();
};

HiFiveUart::HiFiveUart() {};

char HiFiveUart::get_char() {
  volatile uint32_t *reg = (volatile uint32_t *)(METAL_SIFIVE_UART0_0_BASE_ADDRESS + METAL_SIFIVE_UART0_RXDATA);
  uint32_t regval = *reg;
  char regval_c = (char)regval;

  return regval_c;
}

char * HiFiveUart::get_line() {

  int i = 0;
  for( size_t size = 0; size < 1024; size++ ) {
    // printf("size: %u\n", size);
    char c = get_char();
    // buffer[size] = c;
  }
  
  // while( true ) {
  //   printf("size: %u\n", size);
  //   if ( size == 1024 ) {
  //     break;
  //   }

  //   // char c = '0';    
    char c = get_char();

  //   if ( c != 0 ) {
  //     buffer[size] = c;
  //     size++;
  //   }

  //   if ( c == '\n' ) {
  //     break;
  //   }
  // }

  char * ret = "asdf";
  return ret;

  // char * line_buf = (char*) malloc( size * sizeof(char) );
  // std::memcpy(line_buf, &buffer, size);

  // return line_buf;
};

// void return_foo(std::string& ref) {
//   // ref = "asdf";
// }

int main() {
  char buffer[20] = {};
  char * buff_pointer = &buffer[0];
  size_t buff_size = 20;

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

  HiFiveUart uart = HiFiveUart();
  
  while(true) {
    delay(1000*1);
    // std::string test = "Finally\n";
    // std::vector<char> foo{80};
    // const char[] chars = {foo[0]};
    // printf("Got input: ");
    // getline(&buff_pointer, &buff_size, stdin);
    // printf(stdin);
    // scanf("%19s", buffer);

    // int read_int = 0;
    // if( metal_tty_getc(&read_int) == 0) {
    //   buffer[0] = (char)(read_int);
    //   buffer[1] = 0x00;

    // } else {
    //   buffer[0] = 0x00;
    //   // break;
    // }

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
    // std::string line = return_foo();
    // std::string line = "foo";
    char * line = uart.get_line();
    // char * line = "uart";
    printf("%s", line);
    fflush(stdout);
  
    // printf("aESTING\n");
    // std::cout << "FOO" << std::endl;
  }
}