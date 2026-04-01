#include <stdio.h>
#include <string.h>

// Nombre: Alex Llerena, Fecha: 25/3/2026

int main ()
{
    int opcion, unidades, stock, resta, cantidad;
    char ID [20];
    char nombre[50];
    float precio, totalventa, ganancias, descuento;

    opcion = 0;
	stock = 0;
	precio = 0;
	unidades = 0;
	resta = 0;
	totalventa = 0;
	ganancias = 0;

    while(opcion != 6)
    {
        printf("\n          _________MENU__________\n");
        printf("\n1.- Ingresar los datos del producto.");
        printf("\n2.- Vender unidades del producto.");
        printf("\n3.- Reabastecer el producto.");
        printf("\n4.- Informacion del producto.");
        printf("\n5.- Ganancias obtenidas.");
        printf("\n6.- Salir del programa.");
        printf("\nIngrese la opcion a realizar: ");
        scanf("%i", &opcion);

        switch (opcion)
        {

            case 1:

                printf("\nIngrese el ID del producto: ");
                scanf(" %s", ID);

                printf("\nIngrese el nombre del producto: ");
                scanf(" %[^\n]", nombre);

                printf("\nIngrese el stock del producto: ");
                scanf("%i", &stock);

                if (stock < 0)
                {
                    while (stock < 0)
                    {
                        printf("\nEl stock no puede contener un numero negativo, porfavor ingrese un numero posible: ");
                        scanf("%i", &stock);
                    }
                    
                }

                printf("\nIngrese el precio del producto: ");
                scanf("%f", &precio);

                if (precio < 0)
                {
                    while (precio < 0)
                    {
                        printf("\nEl precio no puede ser negativo, porfavor ingrese un precio posible: ");
                        scanf("%f", &precio);
                    }
                }

                break;

            case 2:

                printf("\nIngrese el descuento que se quiere aplicar: ");
                scanf("%f", &descuento);

                if ( descuento < 0)
                {
                    while (descuento < 0)
                    {
                        printf("\nEl descuento no puede ser un numero negativo, porfavor ingrese un descuento posible: ");
                        scanf("%f", &descuento);
                    }
                }

                printf("\nIngrese las unidades que desea vender al consumidor: ");
                scanf("%i", &unidades);

                if (unidades > stock)
                {
                    printf("\nSin stock suficiente.");
                }
                else
                {
                    resta = stock - unidades;
                    totalventa = (unidades * precio) * (1 - descuento / 100);
					stock = stock - unidades;

                    printf("\nCantidad vendida: %i", unidades);
                    printf("\nTotal a cobrar: %.2f", totalventa);

                    ganancias = ganancias + totalventa;
                }

                break;

            case 3:
                printf("\nIngrese la cantidad del producto nuevo: ");
                scanf("%i", &cantidad);

                stock = stock + cantidad;

                break;

            case 4:
                
                printf("\nID: %s", ID);
                printf("\nNOMBRE: %s", nombre);
                printf("\nSTOCK: %i", stock);
                printf("\nPRECIO: %.2f", precio);

                break;

            case 5:
                
                printf("\nGanancias obtenidas: %.2f", ganancias);

                break;

            case 6:

                printf("\nFinalizando sistema...");

                break;

            default:
                
                printf("\nIngrese una opcion existente.\n");

                break;
        }

    }
    
    return 0;
}