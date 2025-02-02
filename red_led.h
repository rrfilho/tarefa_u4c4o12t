#include "pico/stdlib.h"

const uint RED_LED = 13;
const uint BLINKS = 5;

void red_led_init() {
    gpio_init(RED_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);
}

void red_led_blink() {
    bool status = false;
    for(int i = 0; i < 2*BLINKS; i++) {
        status = !status;
        gpio_put(RED_LED, status);
        sleep_ms(100);
    }
}