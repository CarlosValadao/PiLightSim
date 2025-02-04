#include "pico/stdlib.h"
#include "inc/rgb.h"

#define TRAFFIC_LIGHT_LED_INTENSITY 1

static volatile uint8_t traffic_light_color = RED;

static void set_traffic_light_color(uint8_t color, const rgb_t *pins);
bool repeating_timer_callback(struct repeating_timer *timer);


int main()
{
    rgb_t pins = {.red=13, .green=11, .blue=12};
    rgb_init(&pins);

    struct repeating_timer timer;    
    add_repeating_timer_ms(3000, repeating_timer_callback, &pins, &timer);
    while(true);
}

static void set_traffic_light_color(uint8_t color, const rgb_t *pins)
{
    switch(color)
    {
        case RED:
            rgb_turn_off_green(pins);
            rgb_turn_off_blue(pins);
            rgb_turn_on_red(pins, TRAFFIC_LIGHT_LED_INTENSITY);
            break;
        case YELLOW:
            rgb_turn_off_red(pins);
            rgb_turn_on_yellow(pins, TRAFFIC_LIGHT_LED_INTENSITY);
            break;
        case GREEN:
            rgb_turn_off_yellow(pins);
            rgb_turn_on_green(pins, TRAFFIC_LIGHT_LED_INTENSITY);
            break;
    } // There is no possible default value
}

bool repeating_timer_callback(struct repeating_timer *timer)
{
    rgb_t *rgb_pins = (rgb_t*) timer->user_data;
    set_traffic_light_color(traffic_light_color, rgb_pins);
    traffic_light_color = (traffic_light_color + 1) % 3;
    return true;
}