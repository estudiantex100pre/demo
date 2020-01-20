#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arch;
    arch=fopen("archivo6.dat","rb");
    if (arch==NULL)
        exit(1);
    fseek(arch,sizeof(int),0);
    int pos=ftell(arch), t=sizeof(float), i;
    i=pos/t ;
    printf("%i El tamaño del archivo \"archivo6.dat\" es de %i bytes",i, pos);
    fclose(arch);
    system("pause") ;
    return 0;
}
