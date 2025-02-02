#include "leds.h"

bool numeros[10][NUM_LEDS] = { 
    // Número 0
    { 
        0, 1, 1, 1, 0,
        0, 1, 0, 1, 0,
        0, 1, 0, 1, 0,
        0, 1, 0, 1, 0,
        0, 1, 1, 1, 0
    },
    // Número 1
    { 
        0, 1, 1, 1, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 1, 1, 0, 0,
        0, 0, 1, 0, 0
    },
    // Número 2
    { 
        0, 1, 1, 1, 0,
        0, 1, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 1, 1, 1, 0
    },
    // Número 3
    { 
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 1, 1, 1, 0
    },
    // Número 4
    { 
        0, 1, 0, 0, 0,
        0, 0, 0, 1, 0,
        0, 1, 1, 1, 0,
        0, 1, 0, 1, 0,
        0, 1, 0, 1, 0
    },
    // Número 5
    { 
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 1, 1, 1, 0,
        0, 1, 0, 0, 0,
        0, 1, 1, 1, 0
    },
    // Número 6
    { 
        0, 1, 1, 1, 0,
        0, 1, 0, 1, 0,
        0, 1, 1, 1, 0,
        0, 1, 0, 0, 0,
        0, 1, 1, 1, 0
    },
    // Número 7
    { 
        0, 1, 0, 0, 0,
        0, 0, 0, 1, 0,
        0, 1, 0, 0, 0,
        0, 1, 0, 1, 0,
        0, 1, 1, 1, 0
    },
    // Número 8
    { 
        0, 1, 1, 1, 0,
        0, 1, 0, 1, 0,
        0, 1, 1, 1, 0,
        0, 1, 0, 1, 0,
        0, 1, 1, 1, 0
    },
    // Número 9
    { 
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 1, 1, 1, 0,
        0, 1, 0, 1, 0,
        0, 1, 1, 1, 0
    } 
};

uint32_t cor_u32(uint8_t r, uint8_t g, uint8_t b) {
    return ((uint32_t)(r) << 8) | ((uint32_t)(g) << 16) | (uint32_t)(b); 
}

void enviar_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u); 
}

uint32_t ajustar_brilho(uint8_t r, uint8_t g, uint8_t b, float fator) {
    return cor_u32(
        (uint8_t)(r * fator > 255 ? 255 : r * fator), 
        (uint8_t)(g * fator > 255 ? 255 : g * fator), 
        (uint8_t)(b * fator > 255 ? 255 : b * fator)
    );
}

void exibir_numero(int numero) {
    uint32_t cor;

    // Definindo a cor com base no número
    switch (numero) {
        case 0:
            cor = ajustar_brilho(0, 0, 255, 0.1);  // Azul
            break;
        case 1:
            cor = ajustar_brilho(255, 0, 0, 0.1);  // Vermelho
            break;
        case 2:
            cor = ajustar_brilho(0, 255, 0, 0.1);  // Verde
            break;
        case 3:
            cor = ajustar_brilho(255, 255, 0, 0.1);  // Amarelo
            break;
        case 4:
            cor = ajustar_brilho(0, 255, 255, 0.1);  // Ciano
            break;
        case 5:
            cor = ajustar_brilho(255, 0, 255, 0.1);  // Magenta
            break;
        case 6:
            cor = ajustar_brilho(255, 255, 255, 0.1);  // Branco
            break;
        case 7:
            cor = ajustar_brilho(128, 128, 0, 0.1);  // Oliva
            break;
        case 8:
            cor = ajustar_brilho(128, 0, 128, 0.1);  // Roxo
            break;
        case 9:
            cor = ajustar_brilho(0, 128, 128, 0.1);  // Azul-claro
            break;
        default:
            cor = 0;  // Se o número não for válido, desliga o LED
            break;
    }

    // Exibe o número na matriz de LEDs
    for (int i = 0; i < NUM_LEDS; i++) {
        enviar_pixel(numeros[numero][i] ? cor : 0);
    }
}

void piscar_led_rgb() {
    gpio_put(LED_RGB_R, 0); // Vermelho
    gpio_put(LED_RGB_G, 1); // Verde
    gpio_put(LED_RGB_B, 0); // Azul
    sleep_ms(100);
    // Desliga o LED RGB
    gpio_put(LED_RGB_R, 0);
    gpio_put(LED_RGB_G, 0);
    gpio_put(LED_RGB_B, 0);
    sleep_ms(100);
}

void inicializar_leds() {
    gpio_init(LED_RGB_R);
    gpio_set_dir(LED_RGB_R, GPIO_OUT);
    gpio_init(LED_RGB_G);
    gpio_set_dir(LED_RGB_G, GPIO_OUT);
    gpio_init(LED_RGB_B);
    gpio_set_dir(LED_RGB_B, GPIO_OUT);
    gpio_put(LED_RGB_R, 0); // Desliga o componente vermelho
    gpio_put(LED_RGB_G, 0); // Desliga o componente verde
    gpio_put(LED_RGB_B, 1); // Liga o componente azul

    PIO pio = pio0; 
    int sm = 0; 
    uint offset = pio_add_program(pio, &ws2812_program); 
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW); 
}