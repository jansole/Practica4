#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 512
 
int main(){

    char buf[SIZE];
    int m, a;
    char nomfitxer;

    printf("Introdueix el nom del document: ");
    scanf("%s",&nomfitxer);
    if ((a=open(&nomfitxer,O_RDONLY)) == -1){
        printf("ERROR: el fitxer no existeix\n");
    }
    else {
        while( (m = read(a, buf, SIZE-1)) != 0) {
            buf[m]='\0';
            printf("%s",buf);
        }
    }
    return 0;
}
