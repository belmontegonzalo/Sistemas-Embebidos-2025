#include <stdio.h>
#include <iostream>
using namespace std;

int flow = 1;
int level= 2;
int temperature = 3;
int pressure = 4;

int buscadoID, decision, tipo;

struct Sensor {
    int sensor_id, timestamp, value_type, value;
};

int datos[15][4] = {
    {28,1313009355,flow,426},
    {65,1120382229,level,555},
    {72,1675846041,temperature,592},
    {44,1433302985,flow,352},
    {99,1397135423,pressure,244},
    {16,1718956004,flow,766},
    {65,1158080786,pressure,393},
    {61,1519616381,temperature,810},
    {53,1279897396,temperature,646},
    {49,1457307382,pressure,306},
    {62,1168069122,pressure,494},
    {12,1077476341,flow,975},
    {23,1668685029,pressure,880},
    {74,1421875280,level,862},
    {23,1464026904,flow,352}
};

int get_highest_value(Sensor sensores[]) {
    int mayorValue;
    
    for(int i = 0; i < 15; i++) {
        if (i==0) {
            mayorValue = sensores[0].value;
        }
        if (sensores[i].value > mayorValue) {
            mayorValue = sensores[i].value;
        }
    }
    return mayorValue;
}

int get_lowest_value(Sensor sensores[]) {
    int menorValue;
    
    for(int i = 0; i < 15; i++) {
        if (i==0) {
            menorValue = sensores[0].value;
        }
        if (sensores[i].value < menorValue) {
            menorValue = sensores[i].value;
        }
    }
    return menorValue;
}

float get_average_value(Sensor sensores[]) {
    int valuePlus = 0;
    
    for(int i = 0; i < 15; i++) {
            valuePlus = valuePlus + sensores[i].value;
    }
    return (float)valuePlus/15;
}

void find_sensor_by_id(Sensor sensores[], int buscadoID) {
    bool encontrado_existe = false;
    printf("---------------------------------------------------\n");
    
    for (int i = 0; i < 15; i++) {
        if (sensores[i].sensor_id == buscadoID) {
            printf("Los valores del sensor solicitado son lo siguientes:\n");
            printf("ID: %d\n", sensores[i].sensor_id);
            printf("Timestamp: %d\n", sensores[i].timestamp);
            
            if (datos[i][2] == flow) {
                printf("Tipo de valor: Flow\n");
            }
            else if (datos[i][2] == level) {
                printf("Tipo de valor: Level\n");
            }
            else if (datos[i][2] == temperature) {
                printf("Tipo de valor: Temperature\n");
            }
            else {
                printf("Tipo de valor: Pressure\n");
            }
            
            printf("Valor: %d\n", sensores[i].value);
            encontrado_existe = true;
        }
    }
    
    if (encontrado_existe == false) {
    printf("No se encontró un sensor con el ID %d.\n", buscadoID);
    }
}

int main(void) {
    int filas = (sizeof(datos)/sizeof(datos[0]));
    int columnas = (sizeof(datos[0])/sizeof(datos[0][0]));
    struct Sensor sensores[15];
    
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (j==0) {
                sensores[i].sensor_id = datos[i][0];
            }
            if (j==1) {
                sensores[i].timestamp = datos[i][1];
            }
            if (j==2) {
                sensores[i].value_type = datos[i][2];
            }
            if (j==3) {
                sensores[i].value = datos[i][3];
            }
        }
    }
    
    /*printf("Ingrese el tipo de sensor para obtener el rango de valores:\n");
    printf("1) Flow\n2) Level\n3) Temperature\n4) Pressure\n");
    scanf("%d", &tipo);
    get_range_value();
    decision = 0;*/
    
    printf("¿Desea encontrar un sensor especifico en base a su ID?\n1) Si \n2) No\n");
    scanf("%d", &decision);
    if (decision == 1) {
        printf("Ingrese el valor del ID: ");
        scanf("%d", &buscadoID);
        find_sensor_by_id(sensores, buscadoID);
    }

    int mayorValue = get_highest_value(sensores);
    int menorValue = get_lowest_value(sensores);
    float prom = get_average_value(sensores);
    
    printf("---------------------------------------------------\n");
    printf("El mayor valor de value entre todos los sensores es %d", mayorValue);
    printf("\nEl menor valor de value entre todos los sensores es %d", menorValue);
    printf("\nEl promedio de todos los values entre todos los sensores es %.2f", prom);
}