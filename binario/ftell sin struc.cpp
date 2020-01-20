#include<stdio.h>
#include <stdlib.h>
void crear()
{
    FILE *arch;
    arch=fopen("archivo6.dat","wb");
    if (arch==NULL)
        exit(1);
    int valor1=3700;
    fwrite(&valor1, sizeof(int), 1, arch);
    int pos=ftell(arch);
    printf("Posicion del puntero de archivo luego grabar un entero:%i\n", pos);
    int valor2=20;
    fwrite(&valor2, sizeof(int), 1, arch);
    pos=ftell(arch);
    printf("Posicion del puntero de archivo luego grabar un entero:%i\n", pos);
    int valor3=1530;
    fwrite(&valor3, sizeof(int), 1, arch);
    pos=ftell(arch);
    printf("Posicion del puntero de archivo luego grabar un entero:%i\n", pos);
    fclose(arch);
}

void imprimir()
{
    FILE *arch;
    arch=fopen("archivo6.dat","rb");
    if (arch==NULL)
        exit(1);
    printf("Todos los datos almacenados en el archivo.\n");
    int x;
    int pos, t=sizeof(int), i;
    fread(&x, sizeof(int), 1, arch);
    while(!feof(arch))
    {
        pos=ftell(arch);
        i=pos/t ;
        printf("%i dato leido %i y posicion del puntero de archivo %i\n",i,x,pos);
        fread(&x, sizeof(int), 1, arch);
    }
    fclose(arch);
}

int main()
{
    crear();
    imprimir();
    system("pause") ;
    return 0;
}
