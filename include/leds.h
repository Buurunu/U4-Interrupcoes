#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "ws2812.pio.h"

#define LED_RGB_G 11
#define LED_RGB_B 12
#define LED_RGB_R 13
#define WS2812_PIN 7 
#define NUM_LEDS 25 
#define IS_RGBW false 

extern bool numeros[10][NUM_LEDS];

uint32_t cor_u32(uint8_t r, uint8_t g, uint8_t b);
void enviar_pixel(uint32_t pixel_grb);
uint32_t ajustar_brilho(uint8_t r, uint8_t g, uint8_t b, float fator);
void exibir_numero(int numero);
void piscar_led_rgb();
void inicializar_leds();

#endif // LEDS_H