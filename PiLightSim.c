#include "pico/stdlib.h"
#include "inc/rgb.h"

#define RED    0
#define YELLOW 1
#define GREEN  2

static void set_traffic_light_color(uint8_t color);

int main()
{
    rgb_t pins = {.red=13, .green=11, .blue=12};
    rgb_init(&pins);
    while(true);
}

static void set_traffic_light_color(uint8_t color)
{
    switch(color)
    {
        case RED:
            break;
        case YELLOW:
            break;
        case GREEN:
            break;
    } // There is no possible default value
    // TO DO
}