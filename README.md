# tarefa_u4c4o12t
Repositório da tarefa U4C4O12T da capacitação embarcatech.

Este projeto tem por objetivo apresentar os conceitos de interrupção e o funcionamento da matriz de leds WS2812 atráves das máquinas de estados (PIO) presentes na placa RaspberryPi Pico W.

O projeto está dividido em 4 partes principais:

### pio_matrix, led_matrix e numbers_frames
Módulos responsáveis por operar a matriz de leds WS2812. 

pio_matrix.h programa a máquina de estados (PIO) responsável por implementar o protocolo de comunicação serial.

led_matrix.h cria uma API para comunicação com o WS2812, expondo a função led_matrix_draw(uint number), onde "number" é o número (de 0 a 9) que deve ser exibido na matriz de leds. Está função também garante que as linhas que estão invertidas sejam reoorientadas, desta forma a montagem das imagens é simplificada (caso contrário o desenvolvedor precisaria espelhar o posicionamento dos pixels nas linhas invertidas). 

numbers_frames.h define a representação dos números a serem exibidos na matriz de leds. Os números estão representandos em hexadecimal (AA9900 por exemplo), em uma matriz tridimensional de 10x25x6.

### red_led
red_led.h é responsável por controlar o led vermelho e expõe a função red_led_blink() que faz o led piscar 5 vezes por segundo.

### buttons
buttons.h é reponsável por iniciarlizar os butões A e B, e recebe como parâmetros as funções que devem ser chamadas quando os respectivos botões forem acionados.

### main
main.h é responsável por importar todos os módulos supracitados e inicializá-los. Ao chamar o inicializador dos botões, os métodos increment() e decrement() são passados como callback para as interrupções geradas por A e B, respectivamente. increment() e decrement(), incrementam e decrementam, respecitavamente, a variável "counter" e exibem o valor de "counter" na matriz de leds.

Por fim, o loop infinito dentro de main() executa a função red_led_blink(), garantindo que o led vermelho pisque 5 vezes a cada segundo.