#include "UART.h"
#include <assert.h>

int main() {
  UART serial_port = UART();
  assert(serial_port.port == 0);
  serial_port.connect();
}