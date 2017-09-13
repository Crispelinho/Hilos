	#include <stdio.h>
	#include <pthread.h>
	#define CHILOS 3
	int global=0;
	int k1=0;
	int k2=0;
	int k3=0;	
	int cont=0;
	int bandera=0;
	void *funcion_hilo(void*);
	void hacer_algo(int);
	int j;
	int main()
	{

		pthread_t hilos[CHILOS];
		for (int j = 0; j < CHILOS; j++)
		{	//pasarID(j);
			pthread_create(&hilos[j],NULL,funcion_hilo,(void *)j);
		}

		for (int i = 0; i < CHILOS; i++)
		{
			pthread_join(hilos[i],NULL);
		}

		return 0;
	}

	void * funcion_hilo(void *args)
	{
		//hacer_algo(global);
		//printf("%d\n",global);


		for(int k=0;k<CHILOS;k++)
		{
		while(args!=bandera){//printf("args=%d != bandera =%d",args,bandera);
		}
		  printf("Soy el hilo %d con ID: %lu \n",args,pthread_self());

		  for(int i=0;i<CHILOS;i++)
		  {
		  	if(i!=CHILOS){
		  		if ((int)args==i)
		  		{
		  		 bandera=i+1;
		  		}
		  	}
		  	if(i==CHILOS-1)
		  	{
		  		bandera=0;
		  	}
		  }
	}
}
	//void hacer_algo(int n){usleep(10000);}
	//int pasarID(int n){return n;}