#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int A, B, suma, resta, producto, opcion;

    printf("Hola!\n");
    printf("Este programa te va a pedir dos numeros enteros, A y B.\n");
    printf("Despues te voy a mostrar la suma, la resta (en el orden que vos elijas) y el producto.\n");

    printf("Por favor, ingresa el numero A: ");
    scanf("%d", &A);

    printf("Gracias. Ahora ingresa el numero B: ");
    scanf("%d", &B);

    suma = A + B;

    printf("\n¿En que orden queres que te muestre la resta?\n");
    printf("1) A - B\n");
    printf("2) B - A\n");
    printf("Elegi­ 1 o 2: ");
    scanf("%d", &opcion);

    if (opcion == 1) 
    {
        resta = A - B;
    } else 
    {
        resta = B - A;
    }

    producto = A * B;

    printf("\nListo. Estos son los resultados:\n\n");
    printf("La suma de A + B es: %d\n", suma);
    printf("La resta es: %d\n", resta);
    printf("El producto es: %d\n", producto);

    printf("\nGracias por usar el programa. n");
}