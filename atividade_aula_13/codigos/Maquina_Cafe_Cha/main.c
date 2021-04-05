#include <at89x52.h>					// cont�m as defini��es do chip
#include "header.h"

#define MOEDA P3_0						// Moeda est� conectada no pino P3.0
#define BOTAO_CAFE P3_1				// Bot�o caf� est� conectado no pino P3.1
#define BOTAO_CHA P3_2				// Bot�o cha est� conectado no pino P3.2

#define CAFE P1_0							// Cafe est� conectado no pino P1.0
#define CHA P1_1							// Cha est� conectado no pino P1.1
#define COPO P1_2							// Copo est� conectado no pino P1.2


void cafe();
void cha();

void main(){
	// desliga todos os pinos P0
	P0 = 0;
	// desliga todos os pinos P3
	P3 = 0;
	
	while(1){
		cafe();
		cha();
	}

}

void cafe(){
	// Se MOEDA e BOTAO_CAFE receber n�vel alto
	if(MOEDA == 1 & BOTAO_CAFE == 1){
		COPO = 0;
		CAFE = 1;
		delay(100000);
		CAFE = 0;
		delay(100000);
		BOTAO_CAFE = 0;
		delay(100000);
		MOEDA = 0;
		delay(100000);
		COPO = 1;
	}
}

void cha(){
	// Se MOEDA e BOTAO_CHA receber n�vel alto
	if(MOEDA == 1 & BOTAO_CHA == 1){
		COPO = 0;
		CHA = 1;
		delay(100000);
		CHA = 0;
		delay(100000);
		BOTAOCHA = 0;
		delay(100000);
		MOEDA = 0;
		delay(100000);
		COPO = 1;
	}
}
