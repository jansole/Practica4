#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 512

int main(){
    int a, m;
    char nomfitxer;
    int desc;
    char buf[SIZE];

    printf("Introdueix el nom del document: ");
    scanf("%s",&nomfitxer);
    if ((a=open(&nomfitxer,O_RDONLY)) == -1){
        printf("ERROR: el fitxer no existeix\n");
    }
    if ((desc = open( "copia.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU )) == -1){
        printf("ERROR: en la creació del fitxer\n");
    }
    while( (m = read(a, buf, SIZE-1)) != 0) {
        write(desc, buf, m);

        }
    
    return 0;
}
