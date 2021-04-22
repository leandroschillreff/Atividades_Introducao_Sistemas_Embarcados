//Declaração de portas digitais aos quais os led e a entrada digital do sensor vão estar conectados.

int pinLedBlue = 6;
int pinLedRed = 5;
int pinSensor = 3;

//Inicia o sensor em estado 0, ou seja desligado.
int iniciaSensor = 0;


int tempo = 1000;


void setup()
{
    Serial.begin(9600);

    //Declaração de que os LED's serão usados como saída.
    pinMode(pinLedRed, OUTPUT);
    pinMode(pinLedBlue, OUTPUT);
  
	//Declaração que o sensor é uma entrada;
    pinMode(pinSensor, INPUT);

    Serial.print("Detector de movimento ativado.");
    
}

void loop()
{
  
    //A cada ciclo, ele faz uma nova leitura do estado do sensor de presença
    iniciaSensor = digitalRead(pinSensor);

    Serial.print("Valor do Sensor PIR: ");

    Serial.println(iniciaSensor);

    //Verificando se ocorreu detecção de movimentos
    if (iniciaSensor == 1)
    {
        detector_movimento_on();
    }
    else
    {
        detector_movimento_off();
    }
}


void detector_movimento_on()
{ //Função para quando o sensor detectar movimento
    digitalWrite(pinLedRed, LOW);
  	delay(100);
    digitalWrite(pinLedBlue, HIGH);

}

void detector_movimento_off()
{ //Função para quando não detectar movimento
    digitalWrite(pinLedBlue, LOW);
  	delay(100);
    digitalWrite(pinLedRed, HIGH);
}