/*
 * Porta_Leds.cpp
 *
 * Autor : Luck
 *
 * Data : 12/01/2024
*/

#include <Porta_Leds.h>

Porta_Leds::Porta_Leds()
{
 _maximo_portas = TAMANHO_UNO - 1;
 _endereco_p =(int *)malloc(TAMANHO_UNO * sizeof(int));
 _status_p =(int *)malloc(TAMANHO_UNO * sizeof(int));
 _flag = 0;
 for(int x = 0; x <= _maximo_portas; x++)
  {
   _status_portas[x] = -1;
   _endereco_portas[x] = Conf_Portas[x];
   if(_endereco_portas[x] == 1)
    {
     _quantidade_leds++;
     _status_portas[x] = _flag;
    }
   if(x == _maximo_portas)
    {
     _endereco_portas[x+1] = '\0';
     _status_portas[x+1] = '\0';
    }
  }
 _endereco_p = &_endereco_portas[0];
 _status_p = &_status_portas[0];
}

Porta_Leds::~Porta_Leds()
{
 free(_endereco_p);
 free(_status_p);
}

int Porta_Leds::set_portas()
{
 pinMode(LED_1, OUTPUT);
 pinMode(LED_2, OUTPUT);
 pinMode(LED_3, OUTPUT);
 pinMode(LED_4, OUTPUT);
}

int Porta_Leds::configura_portas(int *Flag_Portas, int Tamanho)
{
 _maximo_portas = Tamanho - 1;
 _endereco_p =(int *)realloc(_endereco_p, Tamanho * sizeof(int));
 _status_p =(int *)realloc(_status_p, Tamanho * sizeof(int));
 _flag = 0;
 for(int x = 0; x <= _maximo_portas; x++)
  {
   _status_aux[x] = -1;
   _endereco_aux[x] = *(Flag_Portas + x);
   if(_endereco_aux[x] == 1)
    {
     _quantidade_leds++;
     _status_aux[x] = _flag;
     pinMode(x, OUTPUT);
    }
   if(x == _maximo_portas)
    {
     _endereco_aux[x+1] = '\0';
     _status_aux[x+1] = '\0';
    }
  }
 _endereco_p = &_endereco_aux[0];
 _status_p = &_status_aux[0];
}

int Porta_Leds::liga(int Porta, int Tempo)
{
 _porta = Porta;
 _tempo = Tempo;
 if(_Verifica_porta())
  {
   digitalWrite(_porta, HIGH);
   delay(_tempo);
   _flag = 1;
   *(_status_p + _porta) = _flag;
   return true;
  }
 else
  return -1;
}

int Porta_Leds::desliga(int Porta, int Tempo)
{
 _porta = Porta;
 _tempo = Tempo;
 if(_Verifica_porta())
  {
   digitalWrite(_porta, LOW);
   delay(_tempo);
   _flag = 0;
   *(_status_p + _porta) = _flag;
   return true;
  }
 else
  return -1;
}

int Porta_Leds::pisca(int Porta, int Tempo)
{
 _porta = Porta;
 _tempo = Tempo;
 if(_Verifica_porta())
  {
   digitalWrite(_porta, HIGH);
   delay(_tempo);
   digitalWrite(_porta, LOW);
   delay(_tempo);
   _flag = 0;
   *(_status_p + _porta) = _flag;
   return true;
  }
 else
  return -1;
}

int Porta_Leds::inverte(int Porta, int Tempo)
{
 _porta = Porta;
 _tempo = Tempo;
 if(_Verifica_porta())
  {
   if(_Status_Porta_Leds(_porta) == 0)
    {
     digitalWrite(_porta, HIGH);
     delay(_tempo);
     _flag = 1;
     *(_status_p + _porta) = _flag;
    }
   else if(_Status_Porta_Leds(_porta) == 1)
    {
     digitalWrite(_porta, LOW);
     delay(_tempo);
     _flag = 0;
     *(_status_p + _porta) = _flag;
    }
   else
    return -1;
   return true;
  }
 else
  return -1;
}

int Porta_Leds::_Verifica_porta()
{
 if(_porta >= 0 && _porta <= _maximo_portas)
 {
  if(*(_endereco_p + _porta) == 1)
   return true;
 }
 else
  return false;
}

int Porta_Leds::_Status_Porta_Leds(int _Porta)
{
 _porta = _Porta;
 if(_Verifica_porta())
  return *(_status_p + _porta);
 else
  return -1;
}
