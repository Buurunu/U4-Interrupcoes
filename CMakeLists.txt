# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==

# Verifica o sistema operacional para definir a variável USERHOME
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})  # Para sistemas Windows
else()
    set(USERHOME $ENV{HOME})  # Para sistemas baseados em Unix (Linux, macOS, etc.)
endif()

# Define versões do SDK, toolchain e picoVscode
set(sdkVersion 2.1.0)  # Versão do SDK do Raspberry Pi Pico
set(toolchainVersion 13_3_Rel1)  # Versão do toolchain utilizado
set(picotoolVersion 2.1.0)  # Versão do picotool (ferramenta de upload para o Pico)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)  # Caminho para o arquivo de configuração do VSCode

# Se o arquivo pico-vscode.cmake existir, inclui o mesmo
if (EXISTS ${picoVscode})
    include(${picoVscode})  # Inclui o arquivo de configuração do picoVscode
endif()

# ====================================================================================

# Define a versão mínima do CMake para o projeto
cmake_minimum_required(VERSION 3.13)

# Define os padrões para o compilador C e C++
set(CMAKE_C_STANDARD 11)  # Define o padrão C para o projeto como C11
set(CMAKE_CXX_STANDARD 17)  # Define o padrão C++ para o projeto como C++17

# Gera o arquivo de comandos de compilação para facilitar a depuração
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define o tipo de placa como 'pico_w' (Raspberry Pi Pico com suporte a Wi-Fi)
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Inclui o arquivo de inicialização do SDK do Raspberry Pi Pico
include(pico_sdk_import.cmake)

# Define o nome do projeto
project(main C CXX ASM)

# Inicializa o SDK do Raspberry Pi Pico
pico_sdk_init()



# Define o executável que será gerado
add_executable(main
    main.c
    src/leds.c
    src/buttons.c
)

target_include_directories(main PUBLIC include)

# Define o nome e a versão do programa
pico_set_program_name(main "U4-INTERRUPCOES")  # Nome do programa
pico_set_program_version(main "0.1")  # Versão do programa

# Cria um diretório para arquivos gerados
file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/generated)

# Gera um arquivo de cabeçalho para o PIO (Programmable I/O) a partir do arquivo ws2812.pio
pico_generate_pio_header(main ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

# Adiciona os arquivos de código-fonte do projeto
target_sources(main PRIVATE main.c)

# Vincula as bibliotecas necessárias
target_link_libraries(main pico_stdlib hardware_gpio hardware_pio hardware_timer hardware_clocks)

# Gera arquivos extras para o projeto, como binários e outras saídas
pico_add_extra_outputs(main)
