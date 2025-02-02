# 🛠️ Projeto com BitDogLab e RP2040: Interrupções e Controle de LEDs  

## 📜 Descrição do Projeto  

Este projeto foi desenvolvido para consolidar os conceitos relacionados ao uso de interrupções em microcontroladores utilizando a placa de desenvolvimento **BitDogLab** com o **RP2040**. A aplicação funcional manipula LEDs comuns e endereçáveis WS2812 e trata entradas de botões com debouncing via software.  

## 🎯 Objetivos  

- **Compreender** e aplicar interrupções em microcontroladores.  
- **Implementar debouncing** para botões via software.  
- **Manipular LEDs** comuns e LEDs WS2812, representando números na matriz.  
- **Utilizar resistores** de pull-up internos para botões.  
- **Integrar hardware** e software em uma aplicação funcional.  

---

## 🚀 Componentes Utilizados  

- **Placa BitDogLab com microcontrolador RP2040**  
- **Matriz 5x5 de LEDs WS2812** (conectada à GPIO 7)  
- **LED RGB** (pinos conectados às GPIOs 11, 12 e 13)  
- **Botão A** (conectado à GPIO 5)  
- **Botão B** (conectado à GPIO 6)  

---

## ⚡ Funcionalidades  

1. **LED RGB:** Pisca continuamente 5 vezes por segundo.  
2. **Botão A:** Incrementa o número exibido na matriz de LEDs.  
3. **Botão B:** Decrementa o número exibido na matriz de LEDs.  
4. **Matriz WS2812:** Exibe números de 0 a 9 com formato digital fixo ou visual criativo.  

---

## 📂 Estrutura do Repositório  

```plaintext
interrupcao/
├── src/                      # Código-fonte principal
│   ├── leds.c                 # Funções para controle dos LEDs
│   └── buttons.c              # Funções para tratamento dos botões
├── include/                   # Arquivos de cabeçalho
│   ├── leds.h                 # Declarações para LEDs
│   └── buttons.h              # Declarações para botões
├── main.c                     # Código principal do projeto
├── cMakeLists.txt             # Configurações de compilação do projeto
└── ws2812.pio                 # Código para comunicação com LEDs WS2812
└── README.md                  # Documentação do projeto
```

## 🛠️ Dependências

- **CMake** - Gerador de builds 
- **Ninja** - Ferramenta de build rápida 
- **Python 3** - Interpretador Python

#### Download das Dependências caso não possua:
1. [**Cmake**](https://cmake.org/download/)
2. [**Ninja**](https://github.com/ninja-build/ninja/releases)
3. [**Python3**](https://www.python.org/downloads/)

## 🔧 Instalação
###   Adicionar Ninja, CMake e Python ao Path do Sistema  

Para que os comandos **Ninja**, **CMake** e **Python** sejam reconhecidos em qualquer terminal, siga estas etapas:  

1. **Abra as Configurações do Sistema:**  
   - Clique com o botão direito no botão **Iniciar** e selecione **Configurações**.  
   - Vá em **Sistema → Sobre → Configurações Avançadas do Sistema** (no lado direito).  

2. **Acesse as Variáveis de Ambiente:**  
   - Na aba **Avançado**, clique em **Variáveis de Ambiente**.  
   - Na seção **Variáveis do Sistema**, localize a variável `Path` e clique em **Editar**.  

3. **Adicione os Caminhos dos Programas:**  

   - **Ninja:**  
     Clique em **Novo** e insira o caminho onde você extraiu o `ninja.exe`. Exemplo:  
     ```
     C:\Users\SeuUsuario\Downloads\ninja-win
     ```  

   - **CMake:**  
     Clique em **Novo** e adicione o diretório `bin` do CMake. Exemplo:  
     ```
     C:\Program Files\CMake\bin
     ```  

   - **Python:**  
     Clique em **Novo** e adicione o diretório onde o Python foi instalado. Exemplo:  
     ```
     C:\Python39\
     ```  

4. **Salve as Alterações:**  
   - Clique em **OK** em todas as janelas para salvar as configurações.  

5. **Verifique as Instalações:**  

   Abra o terminal e digite os seguintes comandos para garantir que estão configurados corretamente:  

   ```bash
   ninja --version
   cmake --version
   python --version


## 🖱️ Como executar

### Abra o terminal e siga os passos abaixo:


1. Clone este repositório:

   ```bash
   git clone https://github.com/Buurunu/U4-Interrupcoes.git
   ```
2. Importe o projeto pela extensão do **Rasquery Pi Pico Project**

3. Acesse o diretório do projeto:

   ```bash
   cd U4-interrupcoes
   ```

3. Instale a pasta **build**

   ```bash
    mkdir build
   ```

4. Acesse o diretório **build**

   ```bash
   cd build
   ```
5. Compile o projeto com CMake e Ninja:
   ```bash
   cmake -G "Ninja" ..
   ```   
6. Execute a compilação:
   ```bash
   ninja
   ```   
## 💻 Video demonstrativo: 
**https://youtu.be/9TA_CENymRM**
 








