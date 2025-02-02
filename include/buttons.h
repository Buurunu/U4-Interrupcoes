#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdint.h>
#include "pico/stdlib.h"

#define BOTAO_A 5
#define BOTAO_B 6

extern volatile int numero_atual;
extern volatile uint32_t ultimo_tempo_a;
extern volatile uint32_t ultimo_tempo_b;

void configurar_botao(uint gpio, void (*callback)(uint, uint32_t));
void handler_irq_gpio(uint gpio, uint32_t eventos);

#endif // BUTTONS_H