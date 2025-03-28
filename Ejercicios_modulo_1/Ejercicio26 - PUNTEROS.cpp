/*Un buque de carga traslada 100 contenedores a tres diferentes puertos del pais.
Los puertos se identifican con los nÃºmeros 1, 2 y 3.
De cada contenedor que el buque traslade se registran los siguientes datos:

- Identificacion del contenedor
- Peso del contenedor en kg
- Puerto de arribo(un valor de 1 a 3).

Se pide calcular e informar:
1) El peso total que el buque debe trasladar
2) La identificacion del contenedor de mayor peso
3) La cantidad de contenedores que debe trasladar a cada puerto*/

// EJERCICIO 26 REHECHO CON FUNCIONES

#include <stdio.h>

struct Contenedor { // STRUCT
    int identificacion;
    int peso;
    int puerto;
};

int pesoT = 0, mayorP = 0, contP = 0;
int cant1 = 0, cant2 = 0, cant3 = 0;
// Declaro variables!

void preguntas(Contenedor *contenedorvacio) {
    printf("\nIngrese la identificacion del contenedor: (1, 2 o 3):");
    scanf("%d", &contenedorvacio->identificacion);
    
    printf("\nIngrese el peso del contenedor en KG: ");
    scanf("%d", &contenedorvacio->peso); 
    
    printf("\nIngrese el puerto de arribo del contenedor (1, 2 o 3): ");
    scanf("%d", &contenedorvacio->puerto);
}

int main(void) {
    printf("En este programa podras ingresar los datos de los 5 contenedores de carga que se transladan a tres diferentes puertos del pais.");
    printf("\nSe te pedira ingresar los datos necesarios para sacar un calculo general.");
    
    struct Contenedor contenedores[5];
    
    for(int i=0; i<5; i++) {
        
        printf("\n\n    CONTENEDOR %d", i+1); // Enumero los contenedores
                
        preguntas(&contenedores[i]);
        
        pesoT = pesoT + contenedores[i].peso;
        
        if (contenedores[i].peso > mayorP) // Actualizo entre se vuelve mas pesado 
        {
            mayorP = contenedores[i].peso;
            contP = contenedores[i].identificacion;
        }
        
        if(contenedores[i].puerto == 1) // Guardo cuantas al puerto 1
        {
            cant1++;
        } 
        else if(contenedores[i].puerto == 2) // Guardo cuantas al puerto 233
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