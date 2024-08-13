#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"

#include "hardware/gpio.h"

void led_task()
{
    stdio_init_all();
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true)
    {
        gpio_put(LED_PIN, 1);
        printf("LED ON\n");
        vTaskDelay(200);
        gpio_put(LED_PIN, 0);
        printf("LED OFF\n");
        vTaskDelay(200);
    }
}


int main()
{
    stdio_init_all();

    xTaskCreate(led_task, "LED_Task", 256, NULL, 1, NULL);
    
    vTaskStartScheduler();

    while (1)
    {
    };
}