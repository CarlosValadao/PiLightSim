#include "pico/stdlib.h"  // Biblioteca para o Raspberry Pi Pico
#include "inc/rgb.h"      // Biblioteca personalizada para controlar LEDs RGB

// Define a intensidade dos LEDs do semáforo (valor fixo de 1)
#define TRAFFIC_LIGHT_LED_INTENSITY 1

#define LED_RED_PIN   13
#define LED_GREEN_PIN 11
#define LED_BLUE_PIN  12

// Variável que armazena a cor atual do semáforo, começando com a cor vermelha
static volatile uint8_t traffic_light_color = RED;

// Declaração da função que define a cor do semáforo
static void set_traffic_light_color(uint8_t color, const rgb_t *pins);

// Declaração da função de callback para o temporizador repetitivo
bool repeating_timer_callback(struct repeating_timer *timer);

int main()
{
    // Configuração dos pinos do LED RGB (assumindo pinos 13, 11, 12 para Red, Green, Blue, respectivamente)
    rgb_t pins = {.red=LED_RED_PIN, .green=LED_GREEN_PIN, .blue=LED_BLUE_PIN};
    
    // Inicializa os LEDs com os pinos fornecidos
    rgb_init(&pins);

    // Declaração da estrutura do temporizador repetitivo
    struct repeating_timer timer;

    // Cria um temporizador repetitivo que chama o callback a cada 3000ms (3 segundos)
    // O parâmetro 'pins' é passado para o callback através de 'user_data'
    add_repeating_timer_ms(3000, repeating_timer_callback, &pins, &timer);
    
    // Loop infinito - o temporizador continua a chamar o callback em segundo plano
    while(true);
}

// Função que define a cor do semáforo com base no valor 'color'
static void set_traffic_light_color(uint8_t color, const rgb_t *pins)
{
    // A função recebe 'color' que pode ser RED, YELLOW ou GREEN, e 'pins' que contém os pinos dos LEDs
    switch(color)
    {
        case RED:
            // Apaga os LEDs verde e azul e acende o LED vermelho com a intensidade definida
            rgb_turn_off_green(pins);
            rgb_turn_off_blue(pins);
            rgb_turn_on_red(pins, TRAFFIC_LIGHT_LED_INTENSITY);
            break;
        case YELLOW:
            // Apaga o LED vermelho e acende o LED amarelo com a intensidade definida
            rgb_turn_off_red(pins);
            rgb_turn_on_yellow(pins, TRAFFIC_LIGHT_LED_INTENSITY);
            break;
        case GREEN:
            // Apaga o LED amarelo e acende o LED verde com a intensidade definida
            rgb_turn_off_yellow(pins);
            rgb_turn_on_green(pins, TRAFFIC_LIGHT_LED_INTENSITY);
            break;
    } // Nenhuma ação é feita para valores que não sejam RED, YELLOW ou GREEN
}

// Função de callback chamada pelo temporizador repetitivo
bool repeating_timer_callback(struct repeating_timer *timer)
{
    // Obtém os pinos dos LEDs a partir dos dados do temporizador (user_data)
    rgb_t *rgb_pins = (rgb_t*) timer->user_data;

    // Define a cor do semáforo de acordo com o valor atual de 'traffic_light_color'
    set_traffic_light_color(traffic_light_color, rgb_pins);

    // Atualiza a cor do semáforo para a próxima cor (ciclo RED -> YELLOW -> GREEN)
    // O valor de 'traffic_light_color' é atualizado em um ciclo de 3 cores usando o operador módulo (%)
    traffic_light_color = (traffic_light_color + 1) % 3;

    // Retorna 'true' para manter o temporizador repetitivo funcionando
    return true;
}
