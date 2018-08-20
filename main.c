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
elemento Datos();
int Consultar(elemento e, elemento arr[101]);
void Imprimir(char cadena[51]);

void Agregar(elemento arr[101]);
void Modificar(elemento arr[101]);
void Eliminar(elemento arr[101]);
void Buscar(elemento arr[101]);


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
				Agregar(arr);
			break;
			case 2:
				Modificar(arr);
			break;
			case 3:
				Eliminar(arr);
			break;
			case 4:
				Buscar(arr);
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
	
	for(i=aux+1;i<51;i++)
		cadena[i]='\0';
	
}

void Mayuscula(char cadena[51]){
	
	int i,aux;
	aux=strlen(cadena);
	for(i=0;i<aux;i++){	
		if(cadena[i]>=97 && cadena[i]<=122)
			cadena[i]=cadena[i]-32;
		
	}
}

elemento Datos(){

	elemento e;
	
	printf("Nombre:\n");
		gets(e.nom);
	printf("Fecha de nacimiento (dd/mm/yyyy):\n");
		gets(e.nac);
	printf("Edad:\n");
		gets(e.edad);
	printf("Sexo (M/F):\n");
		gets(e.gen);
	printf("Telefono:\n");
		gets(e.tel);
	printf("Correo:\n");
		gets(e.email);	

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
	
	return e;
}

void Imprimir(char cadena[51]){
	int tam,i;
	tam=strlen(cadena)-1;
	for(i=0;i<tam;i++)
		printf("%c",cadena[i]);
	
	printf("\n");
}

void Agregar(elemento arr[101]){
	
	elemento e;
	
	e=Datos();
	
	//Se agrega el contacto al arreglo
	if(Consultar(e,arr)==-1){
		arr[pos]=e;
		pos++;
		printf("El contacto fue agregado exitosamente\n");
	}else
		printf("El contacto ya existe en la base de datos\n");
}

void Modificar(elemento arr[101]){

	int res;
	elemento e;
	
	printf("Nombre:\n");
		gets(e.nom);
	
	Relleno(e.nom);
	Mayuscula(e.nom);
	
	res=Consultar(e,arr);
	
	if(res==-1)
		printf("El contacto no existe en la base de datos\n");
	else{
		system("cls");
		printf("Ingresa nuevos datos\n");
		arr[res]=Datos();
		printf("El contacto fue modificado exitosamente\n");
	}
	
}

void Eliminar(elemento arr[101]){

	int res,acum,i;
	elemento e;
	
	printf("Nombre:\n");
		gets(e.nom);
	
	Relleno(e.nom);
	Mayuscula(e.nom);
	
	res=Consultar(e,arr);
	if(res==-1)
		printf("El contacto no existe en la base de datos\n");
	else{
	
		acum=pos-res;
		for(i=res;i<=acum;i++)
			arr[i]=arr[i+1];
		
		for(i=0;i<51;i++)
			arr[pos].nom[i]='\0';	
	
		pos--;
		printf("El contacto fue eliminado exitosamente\n");
	}
	
}

void Buscar(elemento arr[101]){
	
	int res;
	char c;
	elemento e;
		
	printf("Nombre:\n");
		gets(e.nom);
	
	Relleno(e.nom);
	Mayuscula(e.nom);
	
	res = Consultar(e,arr);
	
	if(res==-1) 
		printf("El contacto no existe en la base de datos\n");
	else{
		printf("Nombre:\n");
			Imprimir(arr[res].nom);
		printf("Nacimiento:\n");
			Imprimir(arr[res].nac);
		printf("Edad:\n");
			Imprimir(arr[res].edad);
		printf("Sexo:\n");
			Imprimir(arr[res].gen);
		printf("Telefono:\n");
			Imprimir(arr[res].tel);
		printf("Correo:\n");
			Imprimir(arr[res].email);
		printf("Pulse enter para continuar ");
		c=getchar();
	}
	
}

int Consultar(elemento e, elemento arr[101]){
	int i;
	for(i=0;i<101;i++)
		if(strcmp(e.nom,arr[i].nom)==0)
			return i;
		
	return -1;
}
