#include <iostream>
#include <string>
using namespace std;

struct Persona {
    string NyA;
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
}

void filter_by_studies(Persona p) {
    printf("\n%s", p.NyA.c_str());
}

int main() {
    Familia familia[2];
    Persona integrante;
    
    // familia 1
    integrante = {"Ricardo Lopez", 'M', 'U', 'C', 47};
    familia[0].integrantes[0] = integrante;

    integrante = {"Ana Maria Lopez", 'F', 'T', 'C', 45};
    familia[0].integrantes[1] = integrante;

    integrante = {"Miguel Lopez", 'M', 'S', 'I', 17};
    familia[0].integrantes[2] = integrante;

    integrante = {"Juana Lopez", 'F', 'P', 'I', 8};
    familia[0].integrantes[3] = integrante;

    // familia 2
    integrante = {"Jorge Dominguez", 'M', 'U', 'C', 54};
    familia[1].integrantes[0] = integrante;

    integrante = {"Sofia Hernandez", 'F', 'U', 'C', 50};
    familia[1].integrantes[1] = integrante;

    integrante = {"Matias Hernandez Dominguez", 'M', 'U', 'I', 21};
    familia[1].integrantes[2] = integrante;

    integrante = {"Tobias Hernandez Dominguez", 'M', 'U', 'C', 26};
    familia[1].integrantes[3] = integrante;



    int dec1;
    printf("¿Desea saber los datos de algun integrante de una familia especifica?\n1) Si\n2) No\n");
    scanf("%d", &dec1);

    if (dec1 == 1) {
        int fam, inte;
        printf("Ingrese la familia:");
        scanf("%d", &fam);
        printf("Ingrese el integrante:"); 
        scanf("%d", &inte);
        
        print_information(familia[fam].integrantes[inte]);
    }
    
    printf("¿Desea recibir un listado con las pérsonas que llegaron a cierto estudio?\n1) Si\n2) No\n");
    scanf("%d", &dec1);
    
    if (dec1 == 1) {
        int est;
        printf("Ingrese que estudio solicita:\n1) Primario\n2) Secundario\n3)Terciario\n4) Universidad\n5) Nulo\n");
        scanf("%d", &est);
        
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
        printf("Los nombres de las personas que alcanzaron con los estudios solicitados son:\n");
            
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 4; j++) {
                if (familia[j].integrantes[i].EA == estado) {
                    string nombre = familia[j].integrantes[i].NyA;
                    filter_by_studies(familia[i].integrantes[j]);
                }
            }
        }
    }
}
