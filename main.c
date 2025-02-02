#include <stdio.h>
#include "pico/stdlib.h"
#include "leds.h"
#include "buttons.h"

int main() {
    stdio_init_all();

    // Inicialização dos LEDs
    inicializar_leds();

    // Inicialização dos botões
    configurar_botao(BOTAO_A, handler_irq_gpio);
    configurar_botao(BOTAO_B, handler_irq_gpio);

    // Loop principal
    while (true) {
        piscar_led_rgb();
    }

    return 0;
}