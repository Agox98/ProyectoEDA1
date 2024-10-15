#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datos
	{
		short ID;
		char nombre[30];
		char cargo;
		float salario;
	};

void personal_datos(struct datos**empleados);

int main(void) {
	
	struct datos *personal= NULL; //Para manejar los datos del personal
	struct datos*empleados[4]; 
	personal_datos(empleados);//llama a la función
	
	printf("sizeof(struct datos) = %zu\n",sizeof(struct datos));//Imprime el tamaño de la estructura
	
	for (int i = 0; i < 4; i++) //Bulce que recorre los datos de los empleados
		{
			printf("\nEmpleado: %d\n", i + 1);
			printf("Nombre: %s\n", empleados[i]->nombre);
			printf("Cargo: %c\n", empleados[i]->cargo);
			printf("ID: %d\n", empleados[i]->ID);
			printf("Salario: %.2f\n", empleados[i]->salario);
		}
	
	for (int i = 0; i < 4; i++) 
	{
		free(empleados[i]);
	}
	/*
	if (personal != NULL) 
	{
	free(personal);
	personal = NULL;
	}
	*/
	
	return 0;
	
}
void personal_datos(struct datos**empleados)
{
	for(short i=0; i<4; i++)
	{
		empleados[i]=(struct datos*)malloc(sizeof(struct datos));//Asignamos espacio 
		
		if(empleados[i]==NULL)
		{
			printf("Error al asignar memoria.\n");
			exit(1);
		}	
	}
	strcpy_s(empleados[0]->nombre, _countof(empleados[0]->nombre) , "Juan Perez");
	//"strcpy" Copia el string"
	// Usar para mas seguridad "strcpy_s"
	empleados[0]->cargo = 'A';
	empleados[0]->ID = 1001;
	empleados[0]->salario = 2500.50;
	
	strcpy(empleados[1]->nombre, "Ana Gomez");
	empleados[1]->cargo = 'B';
	empleados[1]->ID = 1002;
	empleados[1]->salario = 3000.75;
	
	strcpy(empleados[2]->nombre, "Carlos Sanchez");
	empleados[2]->cargo = 'C';
	empleados[2]->ID = 1003;
	empleados[2]->salario = 2800.60;
	
	strcpy(empleados[3]->nombre, "Maria Lopez");
	empleados[3]->cargo = 'D';
	empleados[3]->ID = 1004;
	empleados[3]->salario = 3200.85;
	
}
