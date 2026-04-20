#include <stdio.h>

// Nombre: Alex Llerena | Fecha: 19/4/2026

int main (int argc, char *argv[]) {
    float Estudiantes[5][3][3];
    int opc = 0;
    do {
        printf("\n     ----------Menu----------\n");
        printf("1.- Ingresar Estudiantes.\n");
        printf("2.- Promedio por estudiante.\n");
        printf("3.- Promedio por asignatura.\n");
        printf("4.- Calificacion mas alta por estudiante.\n");
        printf("5.- Calificacion mas alta por asignatura.\n");
        printf("6.- Estudiantes aprobados.\n");
        printf("7.- Salir.\n");
        printf(">> ");
        scanf("%d", &opc);

        switch (opc) {

            case 1:

                for (int i = 0; i < 5; i++)
                {
                    printf("\n--------------------\n");
                    printf("\nEstudiante %d.\n", i + 1);
                    for (int j = 0; j < 3; j ++)
                    {
                        printf("\nAsignatura %d.\n", j + 1);
                        for (int k = 0; k < 3 ; k++) {
                            printf("\nNota %d: ", k + 1);
                            scanf("%f", &Estudiantes[i][j][k]);
                            if (Estudiantes[i][j][k] < 0 || Estudiantes[i][j][k] > 10)
                            {
                                do {
                                    printf("\nIngrese una nota valida: ");
                                    scanf("%f", &Estudiantes[i][j][k]);
                                } while(Estudiantes[i][j][k] > 10 || Estudiantes[i][j][k] < 0);
                            }
                        }
                    }
                }
                break;

            case 2:

                for(int i = 0; i < 5; i ++)
                {
                    float sum = 0;
                    for (int j = 0; j < 3; j ++)
                    {
                        for (int k = 0; k < 3; k ++)
                        {
                            sum += Estudiantes[i][j][k];
                        }
                    }
                    float prom = sum / 9; 
                    printf("Promedio del estudiante %d: %.2f\n", i + 1, prom);
                }
                break;

            case 3:

                for (int j = 0; j < 3; j ++)
                {
                    float suma = 0;
                    for (int i = 0; i < 5; i++) {
                        for (int k = 0; k < 3; k ++)
                        {
                            suma += Estudiantes[i][j][k];
                        }
                    }
                    float prom = suma / 15;
                    printf("Promedio asignatura %d: %.2f\n", j + 1, prom);
                }
                break;

            case 4:

                for (int i = 0; i < 5; i ++)
                {
                    float mayor = Estudiantes[i][0][0];
                    float menor = Estudiantes[i][0][0];
                    for (int j = 0; j < 3; j ++)
                    {
                        for (int k = 0; k < 3; k ++)
                        {
                            if (mayor < Estudiantes[i][j][k])
                            {
                                mayor = Estudiantes[i][j][k];
                            }

                            if (menor > Estudiantes[i][j][k])
                            {
                                menor = Estudiantes[i][j][k];
                            }
                        }
                    }
                    printf("Estudiante %d\n", i + 1);
                    printf("Nota mayor: %.2f\n", mayor);
                    printf("Nota menor: %.2f\n", menor);
                }

                break;

            case 5: 
                for(int j = 0; j < 3; j ++)
                {
                    float mayor = Estudiantes[0][j][0];
                    float menor = Estudiantes[0][j][0];
                    for (int i = 0; i < 5; i ++)
                    {
                        for (int k = 0; k < 3; k ++)
                        {
                            if (mayor < Estudiantes[i][j][k])
                            {
                                mayor = Estudiantes[i][j][k];
                            }

                            if (menor > Estudiantes[i][j][k])
                            {
                                menor = Estudiantes[i][j][k];
                            }
                        }
                    }
                    printf("Asignatura %d\n", j + 1);
                    printf("Nota mayor: %.2f\n", mayor);
                    printf("Nota menor: %.2f\n", menor);
                }
                break;
        
            case 6: 

                for(int j = 0; j < 3; j ++)
                {                
                    int cont = 0;
                    int contr = 0;
                    for (int i = 0; i < 5; i ++)
                    {
                        float sum = 0;
                        for (int k = 0; k < 3; k ++)
                        {
                            sum += Estudiantes[i][j][k];
                        }
                        float prom = sum / 3;
                        if (prom >= 6){
                            cont ++;
                        }
                        else {
                            contr ++;
                        }
                    }
                    printf("\n----------------------------------------------\n");
                    printf("Asignatura %d: %d estudiantes aprobaron.\n", j + 1, cont);
                    printf("Asignatura %d: %d estudiantes desaprobaron.\n", j + 1, contr);
                }

                break;

            case 7:
                printf("Saliendo.....\n");
                break;

            default:
                printf("\nIngrese una opcion correcta.\n");
                break;
        }

    } while(opc != 7);
    return 0;
}
