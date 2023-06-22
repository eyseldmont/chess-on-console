#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
void restart(),cambio(),yes(),no();
int height,width,x,y,valor,tiempo;
char choice;
int heightChange,widthChange,posChangeX,posChangeY;
///posChangeY = 3+((heightChange-1)*2);
///posChangeX = (widthChange-1)*4;

void pos(int px,int py)
{
    COORD coord;
    coord.X = px;
    coord.Y = py;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main()
{

    srand(time(NULL));
    printf("Indica el alto de la matriz: ");
    scanf("%i",&height);
    printf("Indica el ancho de la matriz: ");
    scanf("%i",&width);
    int matrix[height][width];

    for(int i = 0;i<height;i++)
    {
        for(int j = 0;j<width;j++)
        {
            matrix[i][j] =25+rand()%(75-25+1);
        }
    }
    tiempo = 5;
    show:
    x=3;
    y=3;
    pos(0,0);
    printf("Indica el alto de la matriz: %i",height);
    pos(0,1);
    printf("Indica el ancho de la matriz: %i",width);
    for(int i = 0;i<height;i++)///Generar valores iniciales
    {
        for(int j = 0;j<width;j++)
        {
            pos(x,y);
            printf("%i",matrix[i][j]);
            Sleep(tiempo);
            x=x+4;
        }
        x=3;
        y=y+2;
    }
    tiempo = 0;
    ask:
    printf("\n\nQuieres cambiar un valor de la matriz? Y=Si  N=No");
    choice = getch();

    if(choice=='y' || choice == 'Y')
    {
        askHeight:
        printf("\nDe que columna?");
        scanf("%i",&heightChange);

        if(heightChange >= 1  && heightChange<=width)
        {

            printf("\nDe que fila?");
            scanf("%i",&widthChange);
            if(widthChange >= 1  && widthChange<=height)
            {
                printf("\nQue valor quieres poner?");
                scanf("%i",&valor);
                matrix[widthChange-1][heightChange-1] = valor;
                system("cls");

                goto show;
            }
            else
            {
                printf("\nEsa fila no existe");
                system("pause>null");
                system("cls");
                goto show;
            }
        }
        else
        {
            printf("\nEsa columna no existe");
            system("pause>null");
            system("cls");
            goto show;
        }
    }
    else if (choice == 'n' || choice == 'N' )
    {
        printf("\nAdios\n");
        system("exit");
    }
    else
    {
        printf("\n\nOpcion no valida!!!!");
        system("pause>null");
        system("cls");
        goto show;
    }

}
