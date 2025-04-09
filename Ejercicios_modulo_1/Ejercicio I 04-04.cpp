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
}; // MATRIZ RECORDATA DE DATOS DEL ARCHIVO CSV, de modo ilustrativo y demopstrar el funcionamiento del programa.

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
} // Consigo el sensor de la matriz con mayor value

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
} // Consigo el sensor de la matriz con menor value

void get_range_value(Sensor sensores[], int tipo, int rango[2]) {
    bool primero = true;
    for (int i = 0; i < 15; i++) {
        if (sensores[i].value_type == tipo) {
            if (primero) {
                rango[0] = sensores[i].value; // menor
                rango[1] = sensores[i].value; // mayor
            } else {
                if (sensores[i].value < rango[0]) {
                    rango[0] = sensores[i].value;
                }
                if (sensores[i].value > rango[1]) {
                    rango[1] = sensores[i].value;
                }
            }
        }
    }
}

float get_average_value(Sensor sensores[]) {
    int valuePlus = 0;
    
    for(int i = 0; i < 15; i++) {
            valuePlus = valuePlus + sensores[i].value;
    }
    return (float)valuePlus/15;
} // Sumo todos los values de todos los sensores y hago un promedio

Sensor find_sensor_by_id(Sensor sensores[], int buscadoID) { 
    for (int i = 0; i < 15; i++) {
        if (sensores[i].sensor_id == buscadoID) {
            return sensores[i];
        }
    }
    return { -1, 0, 0, 0 }; // En caso de que no se haya encontrado un sensor con el ID ingresado, envio un sensor vacio. Y luego lo chequeo en la version MAIN.
    
} // Busco ID y lo mando al main, donde sera mandado a get_sensor_information

void get_sensor_information(Sensor sensor) {
    printf("---------------------------------------------------\n");
    printf("Los valores del sensor solicitado son:\n");
    printf("ID: %d\n", sensor.sensor_id);
     
     // CHEQUEO QUE TIPO DE VALUE ES
    if (sensor.value_type == flow) {
        printf("Tipo de valor: Flow\n");
    }
    else if (sensor.value_type == level) {
        printf("Tipo de valor: Level\n");
    }
    else if (sensor.value_type == temperature) {
        printf("Tipo de valor: Temperature\n");
    }
    else {
        printf("Tipo de valor: Pressure\n");
    }
    
    printf("Timestamp: %d\n", sensor.timestamp);
    printf("Valor: %d\n", sensor.value);
} // Recibo los datos del ID leido en find_sensor_by_id y los muestro

int main(void) {
    int filas = (sizeof(datos)/sizeof(datos[0]));
    int columnas = (sizeof(datos[0])/sizeof(datos[0][0]));
    struct Sensor sensores[15];
    
    // CREO LOS VECTORES
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
    
    printf("¿Desea encontrar un sensor especifico en base a su ID?\n1) Si \n2) No\n");
    scanf("%d", &decision);
    
    // TODAS LAS FUNCIONES DE ENCONTRAR SENSOR POR ID
    if (decision == 1) {
        printf("Ingrese el valor del ID: ");
        scanf("%d", &buscadoID);
        
        Sensor encontrado = find_sensor_by_id(sensores, buscadoID);

        if (encontrado.sensor_id != -1) { // En caso de encontrar un sensor.
            get_sensor_information(encontrado);
        } else { // En caso de NO encontrar un sensor.
            printf("No se encontró ningún sensor con el ID %d.\n", buscadoID);
        }
        
        printf("---------------------------------------------------\n");
        decision = 0;
    }
    
    // TODAS LAS FUNCIONES DE GET_RANGE_VALUE (crisis)
    printf("¿Desea encontrar el valor maximo y minimo de un tipo de sensor en particular?\n1) Si \n2) No\n");
    scanf("%d", &decision);
    
    if (decision == 1) {
        printf("Indique que tipo:");
        printf("\n1) Flow\n2) Level\n3) Temperature\n4) Pressure\n");
    scanf("%d", &tipo);

    int rango[2];
    get_range_value(sensores, tipo, rango);
    printf("---------------------------------------------------\n");
    printf("El rango de valores para el tipo de sensor %d es: \n", tipo);
    printf("Valor mínimo: %d\n", rango[0]);
    printf("Valor máximo: %d\n", rango[1]);
    }

    // Mando a calcular todas las funciones de mayor, menor y promedio y las imprimo
    int mayorValue = get_highest_value(sensores);
    int menorValue = get_lowest_value(sensores);
    float prom = get_average_value(sensores);
    
    printf("---------------------------------------------------\n");
    printf("El mayor valor de value entre todos los sensores es %d", mayorValue);
    printf("\nEl menor valor de value entre todos los sensores es %d", menorValue);
    printf("\nEl promedio de todos los values entre todos los sensores es %.2f", prom);
}