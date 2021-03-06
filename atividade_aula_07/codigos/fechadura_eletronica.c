#include <stdio.h>
#include <stdlib.h>

// função para imprimir o estado atual e o caractere informado pelo usuario
void Debug(char input, char state)
{
    printf("Input: %c - State: %c\n", input, state);
}

void Set_bolt()
{
    char State = 'A';
    char input;

    while (1)
    {
        scanf("\n%c", &input);

        Debug(input, State);

        switch (State)
        {
        case 'A':
            switch (input)
            {
            case '4':
                State = 'B';
                // Set_bolt(LOCK);
                break;
            default:
                State = 'A';
                printf("Senha incorreta, digite novamente a senha!\n");
                // Set_bolt(LOCK);
                break;
            }
            break;
        case 'B':
            switch (input)
            {
            case '9':
                State = 'C';
                // Set_bolt(LOCK);
                break;
            default:
                State = 'A';
                printf("Senha incorreta, digite novamente a senha!\n");
                // Set_bolt(LOCK);
                break;
            }
            break;
        case 'C':
            switch (input)
            {
            case '1':
                State = 'D';
                printf("Fechadura destravada!\n");
                // Set_bolt(UNLOCK);
                break;
            default:
                State = 'A';
                printf("Senha incorreta, digite novamente a senha!\n");
                // Set_bolt();
                break;
            }
            break;
        case 'D':
            switch (input)
            {
            case '#':
                State = 'A';
                printf("Fechadura travada!\n");
                break;

            default:
                State = 'D';
                printf("Fechadura continua destravada!\n");
                break;
            }
        }
    }
}

int main()
{
    Set_bolt();
    return 0;
}