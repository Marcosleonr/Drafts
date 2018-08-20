#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <windows.h>

typedef struct elemento{
	char nom[51];
	char nac[51];
	char edad[51];
	char gen[51];
	char tel[51];
	char email[51];
}elemento;


void menu();
void Relleno(char cadena[51]);
void Mayuscula(char cadena[51]);
void Agregar(elemento e, elemento arr[101]);
int Consultar(elemento e, elemento arr[101]);
void Eliminar(elemento e, elemento arr[101]);

int pos=0;

int main(void){
	
	int num;
	char c;
	elemento arr[101];
	elemento e;
	
	while(1){
	
		system("cls");
		menu();
		scanf("%d",&num);
		system("cls");
		c = getchar();
		switch(num){
			case 1:
				printf("Nombre:\n");
					gets(e.nom);
				printf("Fecha de nacimiento (dd/mm/yyyy):\n");
					gets(e.nac);
				printf("Edad:\n");
					gets(e.edad);
				printf("Genero (M/F):\n");
					gets(e.gen);
				printf("Telefono:\n");
					gets(e.tel);
				printf("Correo:\n");
					gets(e.email);
					
				Agregar(e,arr);
			break;
			case 2:
			break;
			case 3:
				printf("Nombre:\n");
					gets(e.nom);
				Eliminar(e,arr);
			break;
			case 4:
			break;
			case 5:
				return 0;
			break;
				default:
				printf("Opcion no valida\n");	
		}
		Sleep(2300);
		system("cls");
	}
	
	
return 0;
}

void menu(){
	printf("Agenda\n");
	printf("1) Agregar contacto\n");
	printf("2) Modificar contacto\n");
	printf("3) Eliminar contacto\n");
	printf("4) Consultar contacto\n");
	printf("5) Salir\n");
}

//Elimina los caracteres vacíos de una cadena recibida
void Relleno(char cadena[51]){
	
	int aux,i;
	aux=strlen(cadena);
	cadena[aux]=',';
	
	for(i=aux+1;i<51;i++){
		cadena[i]='\0';
	}
}

void Mayuscula(char cadena[51]){
	
	int i,aux;
	aux=strlen(cadena);
	for(i=0;i<aux;i++){	
		if(cadena[i]>=97 && cadena[i]<=122){
			cadena[i]=cadena[i]-32;
		}
	}
}


void Agregar(elemento e, elemento arr[101]){
	//Limpieza de cadenas
	Relleno(e.nom);
	Relleno(e.nac);
	Relleno(e.edad);
	Relleno(e.gen);
	Relleno(e.tel);
	Relleno(e.email);
	
	//Normalización de la entrada
	Mayuscula(e.nom);
	Mayuscula(e.gen);
	Mayuscula(e.email);
	
	//Se agrega el contactp al arreglo
	if(Consultar(e,arr)==-1){
		arr[pos]=e;
		pos++;
		printf("El contacto fue agregado exitosamente\n");
	}else
		printf("El contacto ya existe en la base de datos\n");
}

void Eliminar(elemento e,elemento arr[101]){
	int res,i,tam;
	Relleno(e.nom);
	Mayuscula(e.nom);
	res=Consultar(e,arr);
	if(res==-1){
		printf("El contacto no existe en la base de datos\n");
	}else{
		totalrec = pos-res;
	}
	
}

int Consultar(elemento e, elemento arr[101]){
	int i;
	for(i=0;i<101;i++)
		if(strcmp(e.nom,arr[i].nom)==0)
			return i;
		
	return -1;
}
