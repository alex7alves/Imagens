
/*
    Este programa tem por finalidade piscar um led
    na  Intel Edison board

    Autor : Alex Alves
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mraa.h"

void VerificarGPIO(mraa_gpio_context gp);
void Etapas(mraa_result_t status,int etapa);

int main(int argc, char** argv){

   mraa_gpio_context led_1;
   mraa_result_t status;
   // Inicializar o gpio  -> IO2
   led_1 = mraa_gpio_init(2);
   VerificarGPIO(led_1);

   // Setando GPIO para saida
   status = mraa_gpio_dir(led_1, MRAA_GPIO_OUT);
   Etapas(status,1);

   while(1) {
      status = mraa_gpio_write(led_1, 1);
      Etapas(status,2);
      sleep(1);
      status = mraa_gpio_write(led_1, 0);
      Etapas(status,3);
      sleep(1);  
   }
   return 0;
}


void VerificarGPIO(mraa_gpio_context gp)
{
   if (gp == NULL) {
      printf("Falha ao inicializar o GPIO\n");
      mraa_deinit();
      exit(1);
   }

}

void Etapas(mraa_result_t status,int etapa)
{
   if (status != MRAA_SUCCESS) {
      printf("Erro na etapa %d \n",etapa);
      exit(1);
   }

}
