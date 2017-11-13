#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include <time.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{

	int num,cont,div,otro,resta,aux,sum=0;
	num=atoi(argv[1]);
	int         status, rank_actual, tamano_de_procesadores;	/* Valor de retorno, id, cant */
    MPI_Status  rec_stat;           	/* Status object              */
    int         fuente, destino;       	/* fuente, destino            */
    double      prom;
    int         numeros[2];  	/* mensaje                    */

    MPI_Init(&argc, &argv);                    /* Inicio de MPI */
    MPI_Comm_size(MPI_COMM_WORLD, &tamano_de_procesadores);      /* numero de procesos */
    MPI_Comm_rank(MPI_COMM_WORLD, &rank_actual);   /* rango de procesos  */

if(num>1){
	if(rank_actual==0)
	{
		div=num/(tamano_de_procesadores-1);
		otro=div*(tamano_de_procesadores-1);
		resta=num-otro;
		aux=div+resta;

		for(int i=1;i<tamano_de_procesadores;i++)
		{
			if(i==1)
			{
				numeros[0]=sum+1;
				sum=sum+aux;
				numeros[1]=sum;
			}
			else
			{
				numeros[0]=sum+1;
				sum=sum+div;
				numeros[1]=sum;
			}
			status = MPI_Send(numeros, 2, MPI_INT, i, 0, MPI_COMM_WORLD);
		}
	}
	else
	{
		status = MPI_Recv(numeros, 2, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &rec_stat);

		for(int p=numeros[0]; p<=numeros[1];p++)
		{
			cont=0;
			for(int j=2;j<=p;j++)
			{
				if(p%j==0)
				{
					cont++;
				}
			}
				if(cont==1)
				{
					cout<<p<<"  ";
				}
		}
	}
}
else
{
	cout<<"no existen numeros primos :(!";
}

	MPI_Finalize();
    return 0;
}