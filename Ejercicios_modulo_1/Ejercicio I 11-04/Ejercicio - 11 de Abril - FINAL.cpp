#include <iostream>
#include <string>
using namespace std;

struct Persona {
    string NyA;
    string ubi;
    char tipoUBI;
    char gen;
    char EA;
    char ind;
    int edad;
};

struct Familia {
    Persona integrantes[4];
};

void print_information(Persona p) {
    printf("----------------------------------\n");
    printf("Nombre completo: %s\n", p.NyA.c_str());
    printf("Genero: %c\n", p.gen);
    printf("Estudios alcanzados: %c\n", p.EA);
    printf("Estado de estudios: %c\n", p.ind);
    printf("Edad: %d\n", p.edad);
    printf("----------------------------------\n");
}

void filter_by_studies(Persona p) {
    printf("\n%s", p.NyA.c_str());
}

void filter_by_home_type(Familia familias[], char tipoVivienda) {
    printf("----------------------------------");
    printf("\nPersonas que viven en tipo de vivienda %c:\n", tipoVivienda);
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            if (familias[i].integrantes[j].tipoUBI == tipoVivienda) {
                printf("Nombre: %s | Dirección: %s | Familia: %d\n", familias[i].integrantes[j].NyA.c_str(), familias[i].integrantes[j].ubi.c_str(), i);
            }
        }
    }
}

void filter_by_age_greater_than(Persona p) {
    printf("\n%s | %d", p.NyA.c_str(), p.edad);
}

void find_family_with_most_university_graduates(int fam1, int fam2) {
    if (fam1 > fam2) {
        printf("La familia con mas graduados de la universidad es la 1, con %d graduados!", fam1);
    }
    if (fam2 > fam1) {
        printf("La familia con mas graduados de la universidad es la 2, con %d graduados!", fam2);
    }
    if (fam2 == fam1) {
        printf("Ambas familias tienen la misma cantidad de graduados de la universidad! Estos siendo %d", fam1);
    }
}

int main() {
    Familia familia[2];
    Persona integrante;
    
    // ----------------------------------------------------------------------------
    //                      DECLARACION MASIVA DE FAMILIAS.
    
    // familia 1
    integrante = {"Ricardo Lopez", "Avenida Caseros 444", 'D', 'M', 'U', 'C', 47};
    familia[0].integrantes[0] = integrante;

    integrante = {"Ana Maria Lopez", "Avenida Caseros 444", 'D', 'F', 'T', 'C', 45};
    familia[0].integrantes[1] = integrante;

    integrante = {"Miguel Lopez", "Avenida Caseros 444", 'D', 'M', 'S', 'I', 17};
    familia[0].integrantes[2] = integrante;

    integrante = {"Juana Lopez", "Avenida Caseros 444", 'D', 'F', 'P', 'I', 8};
    familia[0].integrantes[3] = integrante;

    // familia 2
    integrante = {"Jorge Dominguez", "Avenida 9 de Julio 1920", 'C', 'M', 'U', 'C', 54};
    familia[1].integrantes[0] = integrante;

    integrante = {"Sofia Hernandez", "Avenida 9 de Julio 1920", 'C', 'F', 'U', 'C', 50};
    familia[1].integrantes[1] = integrante;

    integrante = {"Matias Hernandez Dominguez", "Avenida 9 de Julio 1920", 'C', 'M', 'U', 'I', 21};
    familia[1].integrantes[2] = integrante;

    integrante = {"Tobias Hernandez Dominguez", "Avenida 9 de Julio 1920", 'C', 'M', 'N', 'I', 26};
    familia[1].integrantes[3] = integrante;

    // ----------------------------------------------------------------------------
    //                  TODAS LAS FUNCIONES A DESARROLAR
    int dec1;
    printf("¿Desea saber los datos de algun integrante de una familia especifica?\n1) Si\n2) No\n");
    scanf("%d", &dec1);
    
    //              print_information
    if (dec1 == 1) {
        int fam, inte;
        printf("Ingrese la familia:");
        scanf("%d", &fam);
        printf("Ingrese el integrante:"); 
        scanf("%d", &inte);
        
        print_information(familia[fam].integrantes[inte]);
        dec1 = 0;
    }
    
    printf("\n¿Desea recibir un listado con las personas que llegaron a cierto estudio?\n1) Si\n2) No\n");
    scanf("%d", &dec1);
    
    //              filter_by_studies
    if (dec1 == 1) {
        int est;
        printf("Ingrese que estudio solicita:\n1) Primario\n2) Secundario\n3) Terciario\n4) Universidad\n5) Nulo\n");
        scanf("%d", &est);
        dec1 = 0;
        char estado;
        
        if(est == 1) {
            estado = 'P';
        }
        if(est == 2) {
            estado = 'S';
        }
        if(est == 3) {
            estado = 'T';
        }
        if(est == 4) {
            estado = 'U';
        }
        
        printf("----------------------------------\n");
        printf("Los nombres de las personas que alcanzaron con los estudios solicitados son:");
            
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                if (familia[i].integrantes[j].EA == estado) {
                    filter_by_studies(familia[i].integrantes[j]);
                }
            }
        }
        printf("\n----------------------------------\n");
    }
    
    
    printf("\n¿Desea recibir un listado con las personas que viven en un tipo de vivienda especifico?\n1) Si\n2) No\n");
    scanf("%d", &dec1);
    
    //              filter_by_home_type
    if (dec1 == 1) {
        char tipo;
        dec1 = 0;
        printf("Ingrese el tipo de vivienda:\nD) Departamento\nC) Casa\n");
        scanf(" %c", &tipo); 
        
        filter_by_home_type(familia, tipo);
        printf("----------------------------------\n");
    }
    
    printf("\n¿Desea recibir un listado con las personas que superen cierta edad inclusive?\n1) Si\n2) No\n");
    scanf("%d", &dec1);
    
    //              filter_by_age_greater_than
    if (dec1 == 1) {
        int edadM;
        dec1 = 0;
        printf("Ingrese la edad que solicita en adelante:");
        scanf("%d", &edadM);
            
        printf("----------------------------------\n");
        printf("Los nombres de las personas que superan esa edad y/o tienen esa edad son:\n");
            
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                if (familia[i].integrantes[j].edad >= edadM) {
                    filter_by_age_greater_than(familia[i].integrantes[j]);
                }
            }
        }
        printf("\n----------------------------------");
    }
    
    printf("\n\n¿Desea recibir un listado con la familia que tenga mas graduados de la universidad?\n1) Si\n2) No\n");
    scanf("%d", &dec1);
    
    //              find_family_with_most_university_graduates
    if (dec1 == 1) {
        int fam1 = 0, fam2 = 0;
        dec1 = 0;

        printf("----------------------------------\n");
            
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                if (familia[i].integrantes[j].EA == 'U' && familia[i].integrantes[j].ind == 'C') {
                    if(i == 0) { 
                        fam1++;
                    }
                    else {
                        fam2++;
                    }
                }
            }
        }
        find_family_with_most_university_graduates(fam1, fam2);
    }
    
    
    //                      FUNCIONES VARIAS (a - f)
    
    printf("\n\n        -------------------------------------------------------------------------------\n");
    
    printf("\nLas personas que completaron el primario son:\n");    // A
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            if (familia[i].integrantes[j].ind == 'C') {
                if (familia[i].integrantes[j].EA == 'P' || familia[i].integrantes[j].EA == 'S' || familia[i].integrantes[j].EA == 'T' || familia[i].integrantes[j].EA == 'U') {
                    printf(" %s | Familia %d", familia[i].integrantes[j].NyA.c_str(), i);
                    printf("\n");
                }
            }
        }
    }
    
    printf("----------------------------------\n");
    
    int ana = 0, tot = 0;                                           // B
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            tot++;
            
            if (familia[i].integrantes[j].edad > 10 && familia[i].integrantes[j].EA == 'N') {
                ana++;
            }
        }
    }
    printf("El porcentaje total de personas analfabetas es: %.1f%%\n", ((float)ana / tot) * 100);
    
    printf("----------------------------------\n");
    
    int famTD1 = 0, famTD2 = 0;                                     // C
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            if (familia[i].integrantes[j].tipoUBI == 'D' && familia[i].integrantes[j].EA == 'T') {
                if (i == 0) {
                    famTD1++;
                }
                else {
                    famTD2++;
                }
            }
        }
    }
    
    if(famTD1 < famTD2) {
        printf("La familia con mayor integrantes con estudios de mayor alcanze TERCIARIO y vive en DEPARTAMENTO es la que vive en %s. Esta misma siendo la familia 2.\n", familia[1].integrantes[1].ubi.c_str());
    }
    if(famTD2 < famTD1) {
        printf("La familia con mayor integrantes con estudios de mayor alcanze TERCIARIO y vive en DEPARTAMENTO es la que vive en %s. Esta misma siendo la familia 1.\n", familia[0].integrantes[1].ubi.c_str());
    }
    
    printf("----------------------------------\n");
    
    int edTOT1 = 0, edTOT2 = 0;                                     // D
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            edTOT1 = edTOT1 + familia[0].integrantes[j].edad;
            edTOT2 = edTOT2 + familia[1].integrantes[j].edad;
        }
    }
    printf("El promedio de edad de la familia 1 es: %.2f\n", (float)edTOT1/8);
    printf("El promedio de edad de la familia 2 es: %.2f\n", (float)edTOT2/8);
    
    printf("----------------------------------\n");                 // E
    
    int PI = 0, SI = 0, TI = 0, UI = 0, NUL = 0; // Se llama null pq si le agregaba otra L me tomaba una funcion, pero representa aquellos que no tienen educacion.
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            if (familia[i].integrantes[j].ind == 'I') {
                if (familia[i].integrantes[j].EA == 'P') {
                    PI++;
                }
                if (familia[i].integrantes[j].EA == 'S') {
                    SI++;
                }
                if (familia[i].integrantes[j].EA == 'T') {
                    TI++;
                }
                if (familia[i].integrantes[j].EA == 'U') {
                    UI++;
                }
            }
            
            if (familia[i].integrantes[j].EA == 'N') {
                NUL++;
            }
        }
    }
    
    printf("La cantidad de personas con educaciones incompletas de cada tipo son:\nPrimario: %d\nSecundario: %d\nTerciario: %d\nUniversitario: %d\nSIN FORMACION: %d\n", PI, SI, TI, UI, NUL);
    
    printf("----------------------------------\n");
    
    int totF = 0, totM = 0;                                       // F
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            if (familia[i].integrantes[j].gen == 'F') {
                totF++;
            }
            if (familia[i].integrantes[j].gen == 'M') {
                totM++;
            }
        }
    }
    
    printf("El porcentaje total de mujeres encuestadas fue de un %.1f%%\nEl porcentaje total de hombres encuestados fue de un %.1f%%\n", (float)totF / 8 * 100, (float)totM / 8 * 100);

}  