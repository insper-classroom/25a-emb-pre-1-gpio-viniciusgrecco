#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_RED = 28;
const int BTN_GREEN = 26;
const int LED_RED = 4;
const int LED_GREEN = 6;

int main() {
  stdio_init_all();
  gpio_init(BTN_RED);
  gpio_set_dir(BTN_RED, GPIO_IN);
  gpio_pull_up(BTN_RED);
  gpio_init(BTN_GREEN);
  gpio_set_dir(BTN_GREEN, GPIO_IN);
  gpio_pull_up(BTN_GREEN);

  gpio_init(LED_RED);
  gpio_set_dir(LED_RED, GPIO_OUT);
  gpio_init(LED_GREEN);
  gpio_set_dir(LED_GREEN, GPIO_OUT);

  while (true) {
    if (!gpio_get(BTN_RED)) {
      int red = gpio_get(LED_RED);
      printf("%d",red);
      if (red == 0){
        gpio_put(LED_RED, 1);
      } else {
        gpio_put(LED_RED,0);
      }
      while (!gpio_get(BTN_RED)) {
      };
    };

    if (!gpio_get(BTN_GREEN)) {
      int green = gpio_get(LED_GREEN);
      printf("%d",green);
      if (green == 0){
        gpio_put(LED_GREEN, 1);
      } else {
        gpio_put(LED_GREEN,0);
      }
      while (!gpio_get(BTN_GREEN)) {
      };
    };
  }
}
