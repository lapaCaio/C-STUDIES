#include <stdio.h>
#include <stdlib.h>

void lb()
{ // LIMPA BUFER
    setbuf(stdin, NULL);
}
void lt()
{ // LIMPA TERMINAL
    system("cls");
    system("clear");
}
void linha()
{
    printf("\n|------------------------------------------------------------------------------------------|");
}