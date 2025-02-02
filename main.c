#include <stdio.h>
#include "pico/stdlib.h"
#include "led_matrix.h"
#include "buttons.h"
#include "red_led.h"

volatile uint counter = 0;

void increment() {
    counter = (counter + 1)%10;
    led_matrix_draw(counter);
}

void decrement() {
    counter = (counter - 1)%-10;
    led_matrix_draw(counter);
}

void init() {
    stdio_init_all();
    led_matrix_init();
    buttons_init(increment, decrement);
    red_led_init();
}

int main() {
    init();
    led_matrix_draw(counter);
    while (true) {
        red_led_blink();
    }
}