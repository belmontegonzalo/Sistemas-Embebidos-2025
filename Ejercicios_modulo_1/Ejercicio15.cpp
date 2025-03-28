/* Se realiza una inspecciÃ³n en una fÃ¡brica de pinturas, y se detectaron 5 infracciones. De cada infracciÃ³n se tomÃ³ nota de los siguientes datos:
- Tipo de InfracciÃ³n (1, 2, 3, Ã³ 4)
- Valor de la multa
- Gravedad de la infracciÃ³n (â€˜Lâ€™,â€˜Mâ€™, â€˜Gâ€™)
Se pide informar al final del proceso:
ï‚Ÿ Los valores totales de la multa a pagar de acuerdo al tipo de gravedad.
ï‚Ÿ La leyenda â€œClausurar fÃ¡bricaâ€ si la cantidad de infracciones 3 y 4 con gravedad â€œGâ€ sean mayor a 3.*/

#include <stdio.h>
#define INFRA_MAX 5

struct Infraccion {
    int tipo;
    int valor;
    char grav;
};

void main(void) 
{
    struct Infraccion infracciones[INFRA_MAX];
    int cantI = 0, cantG = 0;
    int valorL = 0, valorM = 0, valorG = 0;

    printf("En este programa sabra, en base a las infracciones que tiene y su gravedad, que tan mal esta su fabrica.\n");
    
    printf("\nIngrese cuantas infracciones tiene en total (maximo %d):", INFRA_MAX);
    scanf("%d", &cantI);
    
    getchar();
    
    for (int i = 0; i < cantI; i++)
    {
        printf("\nINFRACCION %d", i + 1);
        printf("\nIngrese el tipo de infraccion (1, 2, 3 o 4): ");
        scanf("%d", &infracciones[i].tipo);
        
        printf("\nIngrese el valor de la multa, sin signos: ");
        scanf("%d", &infracciones[i].valor);
        
        getchar();
        
        printf("\nIngrese la gravedad de la infraccion (L, M, G): ");
        scanf("%c", &infracciones[i].grav);
        
        if (infracciones[i].grav == 'L')
        {
            valorL = valorL + infracciones[i].valor;
        }
        else if (infracciones[i].grav == 'M')
        {
            valorM = valorM + infracciones[i].valor;
        }
        else if (infracciones[i].grav == 'G')
        {
            valorG = valorG + infracciones[i].valor;
            
            if (infracciones[i].tipo == 3 || infracciones[i].tipo == 4 && infracciones[i].grav == 'M')
            {
                cantG++;
            }
        }
    }
    
    printf("\nEl valor de multas de gravedad L es: %d", valorL);
    printf("\nEl valor de multas de gravedad M es: %d", valorM);
    printf("\nEl valor de multas de gravedad G es: %d", valorG);
    
    if (cantG > 3)
    {
        printf("\nCLAUSURAR FABRICA.");
    }
    else
    {
        printf("\nNO HACE FALTA CLAUSURAR FABRICA.");
    }
}