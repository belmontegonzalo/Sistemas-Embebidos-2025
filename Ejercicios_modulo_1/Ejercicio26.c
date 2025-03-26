/*Un buque de carga traslada 100 contenedores a tres diferentes puertos del país.
Los puertos se identifican con los números 1, 2 y 3.
De cada contenedor que el buque traslade se registran los siguientes datos:

- Identificación del contenedor
- Peso del contenedor en kg
- Puerto de arribo(un valor de 1 a 3).

Se pide calcular e informar:
1) El peso total que el buque debe trasladar
2) La identificación del contenedor de mayor peso
3) La cantidad de contenedores que debe trasladar a cada puerto*/

#include <stdio.h>

struct Contenedor { // STRUCT.
    int identificacion;
    int peso;
    int puerto;
};

struct Contenedor contenedor; // LLamo todas las variables del Struct y las pongo bajo el nombre contenedor.

int pesoT = 0, mayorP = 0, contP = 0;
int cant1 = 0, cant2 = 0, cant3 = 0;
// Declaro variables!

void main(void) 
{
    printf("En este programa podras ingresar los datos de los 5 contenedores de carga que se transladan a tres diferentes puertos del pais.");
    printf("\nSe te pedira ingresar los datos necesarios para sacar un calculo general.");
    
    for(int i=0; i<5; i++)
    {
        printf("\n\n    CONTENEDOR %d", i+1); // Enumero los contenedores
        
        printf("\nIngrese la identificacion del contenedor (1, 2 o 3): ");
        scanf("%d", &contenedor.identificacion);
        
        while (contenedor.identificacion != 1 && contenedor.identificacion != 2 && contenedor.identificacion != 3) // Valido lo ingresado
        {
            printf("Lo ingresado es incorrecto, intente nuevamente.");
            printf("\nIngrese la identificacion del contenedor (1, 2 o 3): ");
            scanf("%d", &contenedor.identificacion);
        }
        
        printf("\nIngrese la el peso del contenedor en KG (sin letras): ");
        scanf("%d", &contenedor.peso); 
        
        while (contenedor.peso <= 0) {
            printf("Lo ingresado es incorrecto, intente nuevamente.");
            printf("\nPeso (kg, debe ser mayor que 0): ");
            scanf("%d", &contenedor.peso);
        }
        // No le hice validacion de si es un digito porque no se como hacer para chequear si es un digito o no en C... perdon-
        
        printf("\nIngrese el puerto de arribo del contenedor (1, 2 o 3): ");
        scanf("%d", &contenedor.puerto);
        
        while (contenedor.puerto != 1 && contenedor.puerto != 2 && contenedor.puerto != 3) // Valido lo ingresado
        {
            printf("Lo ingresado es incorrecto, intente nuevamente.");
            printf("\nIngrese el puerto de arribo del contenedor (1, 2 o 3): ");
            scanf("%d", &contenedor.puerto);
        }
        
        pesoT = pesoT + contenedor.peso;
        
        if (contenedor.peso > mayorP) // Actualizo entre se vuelve mas pesado 
        {
            mayorP = contenedor.peso;
            contP = contenedor.identificacion;
        }
        
        if(contenedor.puerto == 1) // Guardo cuantas al puerto 1
        {
            cant1++;
        } 
        else if(contenedor.puerto == 2) // Guardo cuantas al perto 2
        {
            cant2++;
        }
        else // Guardo cuantas al puerto 3
        {
            cant3++;
        }
    }
    
    printf("\nGracias por haber ingresado todos los datos!");
    
    printf("\nEl peso total que el buque debe transladar es de %dkg", pesoT);
    printf("\nEl contenedor de mas peso lleva una identificacion de %d", contP);
    printf("\nSe deben transladar un total de contenedores a:\nPuerto 1: %d\nPuerto 2: %d\nPuerto 3: %d", cant1, cant2, cant3);
    
    printf("\nGracias por confiar en este programa! :D");
}
