#include <at89x52.h>
#include <seria1232.h>

#define XTAL 12000000
#define T1_CLOCK XTAL/12
void init_sio_poll(unsigned int baud_rate){
	TR1=0; //pára Timer 1 para programá-lo.
	ET1=0; //desabilita interrupção Timer1
	TMOD &=0x0F; //Setup timer1 no modo 2
	TMOD |=0x20; //8-bit auto-reload timer.
	TH1=256-((T1_CLOCK/32)/ baud_rate); //valor da recarga
	TR1=1; //timer1 no modo ‘roda’
	SCON=0x50; //Modo 1 com 8 bits
	TI=1; //indicate TX buffer empty
	//setado pelo microcontrolador com 0 na após
	//transmissão
} 

// função imprimir cchar na porta serial
void putchar(char outChar){
	while(!TI);
	SBUF = outChar;
	TI = 0;
}

// função para esperar um determinado tempo
void delay(long int Vezes)
{
	while (Vezes--);
}

void main(){
	//sinaliza se a tecla foi pressionada e solta
	bit foiPressionado = 0;
	// inicializa com serial em 300bp/s
	init_sio_poll(300);
	// desliga todos os pinos P0
	P3 = 0;
	
	while(1){
		// sinaliza que P3.0 foi pressionado
		if(P3_0 == 1){
			foiPressionado = 1;
		}
		// Se P3.0 foi solta, vai imprimir as letras na porta serial
		if(P3_0 == 0 & foiPressionado == 1){
			delay(1000000);			// aguarda um tempo
			putchar('L');				// trasmite a letra 'L'
			delay(1000000);			// aguarda um tempo
			putchar('E');				// trasmite a letra 'E'
			delay(1000000);			// aguarda um tempo
			putchar('A');				// trasmite a letra 'A'
			delay(1000000);			// aguarda um tempo
			putchar('N');				// trasmite a letra 'N'
			delay(1000000);     // aguarda um tempo
			putchar('D');				// trasmite a letra 'D'
			delay(1000000);     // aguarda um tempo
			putchar('R');				// trasmite a letra 'R'
			delay(1000000);     // aguarda um tempo
			putchar('O');				// trasmite a letra 'O'
			delay(1000000);     // aguarda um tempo
			putchar(' ');				
			foiPressionado = 0;
		}
	}
}