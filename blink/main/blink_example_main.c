#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"


void app_main(void)
{
    gpio_reset_pin(25);
    gpio_reset_pin(26);
    gpio_reset_pin(27);
    
    gpio_set_direction(25, GPIO_MODE_OUTPUT);
    gpio_set_direction(26, GPIO_MODE_OUTPUT);
    gpio_set_direction(27, GPIO_MODE_OUTPUT);


    union OneByteUnion {
        unsigned char all_bits;
        struct {
            bool bit1 : 1; 
            bool bit2 : 1;
            bool bit3 : 1;
            bool bit4 : 1;
            bool bit5 : 1;
            bool bit6 : 1;
            bool bit7 : 1;
            bool bit8 : 1;

        } bits;
    };

     union OneByteUnion d;

    while (1) {
        d.all_bits = 0xff;
        gpio_set_level(25, d.bits.bit1);
        gpio_set_level(26, d.bits.bit2);
        gpio_set_level(27, d.bits.bit3);
        printf("LED ON\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        d.all_bits = 0x11;
        gpio_set_level(25, d.bits.bit1);
        gpio_set_level(26, d.bits.bit2);
        gpio_set_level(27, d.bits.bit3);
        printf("LED OFF\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
