#include "pico/stdlib.h"
#include "inc/rgb.h"

#define RED    0
#define YELLOW 1
#define GREEN  2
#define TRAFFIC_LIGHT_LED_INTENSITY 40

static void set_traffic_light_color(uint8_t color, const rgb_t *pins);

int main()
{
    rgb_t pins = {.red=13, .green=11, .blue=12};
    rgb_init(&pins);
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