/*
 * Porta_Leds.h
 *
 * Autor : Luck
 *
 * Data : 12/01/2024
*/

#ifndef Porta_Leds_H
#define Porta_Leds_H

#include <Arduino.h>

#define TAMANHO_UNO 15
#define TAMANHO_AUX 50
#define LED_1 11
#define LED_2 10
#define LED_3 9
#define LED_4 8
#define TEMPO 500

class Porta_Leds
{
 public:
     int Conf_Portas[TAMANHO_UNO] = {0,0,0,0,0,0,0,0,1,1,1,1,0,0};
     Porta_Leds();
     ~Porta_Leds();
     int set_portas();
     int configura_portas(int *Flag_Portas, int Tamanho);
     int liga(int Porta, int Tempo);
     int desliga(int Porta, int Tempo);
     int pisca(int Porta, int Tempo);
     int inverte(int Porta, int Tempo);
 private:
     int _maximo_portas = 0;
     int _tempo = 500;
     int _quantidade_leds = 0;
     int _porta;
     int _flag = 0;
     int _endereco_portas[TAMANHO_UNO];
     int _endereco_aux[TAMANHO_AUX];
     int *_endereco_p;
     int _status_portas[TAMANHO_UNO];
     int _status_aux[TAMANHO_AUX];
     int *_status_p;
     int _Status_Porta_Leds(int _Porta);
     int _Verifica_porta();
};

#endif
