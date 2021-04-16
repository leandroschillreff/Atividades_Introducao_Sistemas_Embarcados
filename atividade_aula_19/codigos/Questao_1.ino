const int A = 1;
const int B = 2;
const int C = 3;
const int D = 4;
const int E = 5;
const int F = 6;
const int G = 7;

int tempo = 1000;

int botaoCrescente = 8;
int botaoDecrescente = 9;

void setup()
{
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);

    pinMode(botaoCrescente, INPUT);
    pinMode(botaoDecrescente, INPUT);
}

void displayDigit(int digito)
{
    //Condições segmento a
    if (digito != 1 && digito != 4)
        digitalWrite(A, HIGH);

    ///Condições segmento b
    if (digito != 5 && digito != 6)
        digitalWrite(B, HIGH);

    //Condições segmento c
    if (digito != 2)
        digitalWrite(C, HIGH);

    //Condições segmento d
    if (digito != 1 && digito != 4 && digito != 7)
        digitalWrite(D, HIGH);

    //Condições segmento e
    if (digito == 2 || digito == 6 || digito == 8 || digito == 0)
        digitalWrite(E, HIGH);

    //Condições segmento f
    if (digito != 1 && digito != 2 && digito != 3 && digito != 7)
        digitalWrite(F, HIGH);
	
    //Condições segmento g
    if (digito != 0 && digito != 1 && digito != 7)
        digitalWrite(G, HIGH);
}


void turnOff()
{
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
}

void loop()
{

    if (digitalRead(botaoCrescente) == LOW) // Se o botão for pressionado
    {
        for (int i = 0; i < 10; i++)
        {
            displayDigit(i);
            delay(1 * tempo);
            turnOff();
        }
        digitalWrite(botaoCrescente, HIGH);
    }
    if (digitalRead(botaoDecrescente) == LOW) // Se o botão for pressionado
    {
        for (int i = 9; i >= 0; i--)
        {
            displayDigit(i);
            delay(1 * tempo);
            turnOff();
        }
        digitalWrite(botaoDecrescente, HIGH);
    }
}
