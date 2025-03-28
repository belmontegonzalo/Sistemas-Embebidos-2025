// Dados 50 nÃºmeros enteros, informar el promedio de los mayores que 100 y la suma de los menores que â€“10.

#include <stdio.h>
int prom1 = 0, suma = 0, cant;
int num[5];
float promedio;

void main(void) 
{
    printf("Hola! Tendras que ingresar 5 numeros enteros de tu preferencia, sin un rango determinado.\n");
    for(int i=0; i < 5; i++) 
    {
        printf("\n Numero %d:",i+1);
        scanf("%d", &num[i]);
    }
    
    for (int i=0; i < 5; i++) 
    {
        if (num[i] > 100) 
        {
            prom1 = prom1 + num[i];
            cant++;
        }
        
        if (num[i] < -10) 
        {
            suma = suma + num[i];
        }
    }
    
    if (suma == 0) 
    {
        printf("\nNo hay valores menores a -10");
    }
    else
    {
        printf("\nLa suma de los numeros menores a -10 es %d", suma);
    }
        
    if (prom1 == 0) 
    {
        printf("\nNo hay valores mayores a 100 ");
    }
    else 
    {
        promedio = (float)prom1 / cant;
        printf("\nEl promedio de los numeros mayores a 100 es: %.2f", promedio);
            
    }
}