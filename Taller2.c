#include <stdio.h>

typedef int vector[50]; //aqui se crea la definicion de vector que utilizaremos como base de nuestro programa.

int contador2=0;// Cuenta la cantidad de tramos.
int aux=0;//Dirá cuantos valores hay en total contando los elementos de todos los tramos.


void creArreglo(vector usuario, vector tramos, vector longitudes)
{
    int contador=0;//Cuenta la cantidad de valores que tiene cada tramo.
    int numero=0;//Con este reyenaremos el array usuario.
    int i=0;//Será las posiciones para recorrer el array usuario.
    int pregunta=0;// Si quiere agregar mas valores a un tramo.
    int pregunta2=0;// Si quiere agregar otro tramo.
    int l=0;


    while(pregunta2!=2)//En este ciclo se generan los distintos tramos.
    {
        while(pregunta!=2)//En este ciclo se solicita al usuario los valores para reyenar cada tramo.
        {
            pregunta2=0;

            printf("Agregue un elemento: ");
            scanf("%d", &numero);
            usuario[i]=numero;
            i++;
            contador++;
            printf("Desea agregar mas elementos? \n(1) si (2) no: ");
            scanf("%d", &pregunta);
        }

        longitudes[contador2]=contador;//Guardamos en este vector la cantidad de elementos que tiene cada tramo.
        contador2++;

        for(int n=aux; n<(aux+contador); n++)
        {
            //En este ciclo se traspasa la información que da el usuario a otro array para guardar los datos y volver a utilizar el array usuario para nuevos tramos.
            tramos[n]=usuario[l];
            l++;
        }

        aux=contador+aux;//Guardamos la ultima posición o cantidad de valores para así rellenar el vector tramos.

        printf("Desea agregar mas tramos?\n(1) si (2) no: ");
        scanf("%d", &pregunta2);

        pregunta=0;
        contador=0;
    }
}

void muestrArreglo(vector tramos, vector longitudes)
{
    printf("todos los valors ingresados por el usuario son: \n");
    for(int j=0; j<aux; j++)//imprime todos los valores ingresados por el usuario
    {
        printf(" %d \n ", tramos[j]);
    }
    for(int s=0; s<contador2; s++)//Imprime la cantidad de elementos que tiene cada tramo.
    {
        printf("\nEl tramo (%d) tiene %d elementos\n",s+1, longitudes[s]);
    }

}

int maxTramos(vector longitudes, vector tramos)
{
    //Imprime y retorna la mayor longitud de todos los arreglos.

    int tramosiguales=0;
    int maxlongitud=0;
    int tramoayuda=0;
    for(int s=0; s<contador2; s++)
    {
        if(maxlongitud<longitudes[s])
        {
            maxlongitud=longitudes[s];
            tramoayuda=s+1;
        }
    }
    for(int s=0; s<contador2; s++)
    {
        if(maxlongitud==longitudes[s])
        {
            tramosiguales++;
        }
    }

    if(tramosiguales==0)
    {
        printf("La maxima longitud de un tramo es de: %d en el tramo %d \n", maxlongitud, tramoayuda);
    }
    else
    {
        printf("La maxima longitud de un tramo es de %d en el tramo %d pero mas tramos que poseen estas mismas longitudes, se repiten %d veces\n", maxlongitud, tramoayuda,tramosiguales);
    }


    return maxlongitud;
}

void sumTramos(vector longitudes, vector tramos)
{
    //Imprime la suma de los elementos del último tramo ingresado.

    int auxsum=0;
    int sum=0;

    for(int s=0; s<contador2-1;s++)
    {
        auxsum=longitudes[s]+auxsum;
    }

    for(int s=auxsum; s<aux;s++)
    {
        if(s==aux-1)
        {
            printf("%d",tramos[s]);
        }
        if(s!=aux-1)
        {
        printf("%d + ", tramos[s]);
        }
        sum=tramos[s]+sum;
    }

    printf(" = %d",sum);

}


int main()
{

    vector tramos;// se traspasa el vector usuario aqui y se guarda.
    vector usuario;//es el array que guardara los valores ingresados por el usuario.
    vector longitudes;//guardara en cada posicion la cantidad de valores que tiene cada tramo.

    creArreglo(usuario, tramos,longitudes);
    /*lo primero que hacemos es crear todos los arreglos
    para que siempre exista porlo menos uno disponible.*/

    int opcion;
    opcion=0;

    /*El menu consta de un while que nos ayudara a volver las veces que queramos a esta
    y que podamos finalizarla cuando queramos.*/

    while(opcion != 4)
        {
            printf("\n\nmenu\n");

            printf("1. Despliega los arreglos en pantalla:\n");

            printf("2. Retorna la longitud del tramo más largo en un arreglo:\n");

            printf("3. Despliega la suma de los elementos del ultimo tramo de un arreglo:\n");

            printf("4. salir");

            printf("\nelija una opcion:\n");

            /*Las distintas opciones nos redirigen al valor guardado con anterioridad
            y posterior a eso redirigirnos al menu.*/

            scanf("%d", & opcion);
            if(opcion == 1)
                  {
                        muestrArreglo(tramos, longitudes);
                  }
            if(opcion == 2)
                  {
                        maxTramos(longitudes,tramos);
                  }
            if(opcion == 3)
                  {
                        sumTramos(longitudes, tramos);
                  }
        }


    return 0;
}

