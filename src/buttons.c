#include "leds.h"
#include "buttons.h"

volatile int numero_atual = 0; // Número atual exibido
volatile uint32_t ultimo_tempo_a = 0;
volatile uint32_t ultimo_tempo_b = 0;

void configurar_botao(uint gpio, void (*callback)(uint, uint32_t)) {
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_IN);
    gpio_pull_up(gpio);
    gpio_set_irq_enabled_with_callback(gpio, GPIO_IRQ_EDGE_FALL, true, callback);
}

void handler_irq_gpio(uint gpio, uint32_t eventos) {
    uint32_t tempo_atual = to_us_since_boot(get_absolute_time());
    volatile uint32_t *ultimo_tempo = (gpio == BOTAO_A) ? (volatile uint32_t *)&ultimo_tempo_a : (volatile uint32_t *)&ultimo_tempo_b;

    if (tempo_atual - *ultimo_tempo > 400000) {
        *ultimo_tempo = tempo_atual;
        numero_atual = (gpio == BOTAO_A) ? (numero_atual + 1) % 10 : (numero_atual - 1 + 10) % 10;
        exibir_numero(numero_atual);
    }
}