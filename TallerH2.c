//Cristhian Carpio
//2016214160
//Sistemas Operativos
//Grupo: 3

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

struct Datos{
    	int idluz;
	double tiempo;
	int estado;
	int salir;
}ptr;


int *mensaje;
int *time1;
int sw;
int CHILOS=0;

void * funcion_hilo(void *arg){
	
	int ID = (int)arg;//Convierte el parametro de tipo void a int

	while(ptr.salir==1){

		while((ID!=ptr.idluz || sw==0 ) && ptr.salir!=0){}
			if(ptr.salir == 0) break;
			printf("\nCliente %d\n",ID);
			printf("Mi ID es %lu\n",pthread_self());
			usleep(ptr.tiempo);
			printf("Luz [%d]: Mi tiempo de ejecucion fue %lf \n",ID,ptr.tiempo);
			if(ptr.estado==0)
			{
			printf("Mi estado es apagado\n");
			}
			else
			{
			printf("Mi estado es encendido\n");
			}
			ptr.idluz = -1;
			sw = 0;
	}
	pthread_exit(NULL);
	return NULL;
}

int main(){
    	printf("Iniciando servidor...\n");
	int a=1;
	while(a==1)
	{
    	printf("Ingrese el numero de hilos:\n");
	scanf("%d",&CHILOS);	
	if(CHILOS<=0) a=1;
	else a=0;
	}

	a=1;
	//Inicializa el vector de hilos
	pthread_t hilos[CHILOS];
	mensaje=(int*)malloc(sizeof(int)*CHILOS);//Inicializa vector de tamano n hilos
	time1=(int*)malloc(sizeof(int)*CHILOS);

	for(int z = 0; z < CHILOS; z++){
		mensaje[z]=0;
		time1[z]=0;
	}
	ptr.salir=1;
	sw = 0;
	ptr.idluz =-1;
	for (int j = 1; j <= CHILOS; j++){
		pthread_create(&hilos[j],NULL,funcion_hilo,(void *)j);
	}
	while(ptr.salir==1){
		while(a==1)
			{
			printf("Ingrese la luz a modificar\n");
			scanf("%d",&ptr.idluz);	
			if(ptr.idluz<=0 || ptr.idluz>CHILOS) a=1;
			else a=0;
			}
		a=1;
		printf("Ingrese en que estado quiere la luz (1)Encendido o (0)Apagado\n");
		scanf("%d",&ptr.estado);
		mensaje[ptr.idluz]=ptr.estado;
		printf("Ingrese el tiempo(us):\n");
		scanf("%lf",&ptr.tiempo);
		time1[ptr.idluz]=ptr.tiempo;
		sw=1;
		while(sw==1){}	
		printf("\nDesea continuar (1) si desea salir(0):\n");
		scanf("%d",&ptr.salir);

    	}
		printf("\n                     Resumen\n");
	for(int k = 1; k <= CHILOS; k++){
		printf("\n_________________________________________________\n");		
		printf("\nSoy la luz %d,",k);
		if(mensaje[k]==0)
		{
		printf(" mi estado es apagado\n");
		}
		else
		{
		printf(" mi estado es encendido\n");
		}
		printf("\nMi ultimo tiempo de ejecucion fue de %d segundos\n",time1[k]);
		printf("\n_________________________________________________\n");		
	}
	printf("\nFin del proceso...\n");
	
	for (int i = 1; i <= CHILOS; i++){
		pthread_join(hilos[i],NULL);
	}
	
	return 0;
}
