#include<stdio.h>
#include<math.h>
#include<windows.h>



typedef struct{
	int nivel;
	float hogares;
	float ingresos;
	float promedio;
	float desviacion;
	float varianza;
}Registro;

int menu();
void imprimirInfo(Registro *datos[4], int n);
float promedio(Registro *datos[4], int segm);
float varianza(Registro *datos[4], int segm);
float desviacionSTD(Registro *datos[4], int segm);
float ingresoPerCapita(Registro *datos[4], int segm, int nivel);
float mediana(Registro *datos[4], int anio);
float varianzaAnual(Registro *datos[4], int anio);
float desviacionAnual(Registro *datos[4], int anio);
void comparacion(Registro *datos[4]);
void agregarDatos(Registro *datos[4]);

main(){
	/*Inicializacion de los registros*/
		/*Mas de 2500 habitantes*/
		/*2010*/
	Registro mas_diez[10] = {{1,1332829,6831} , {2,1824907,11753} , {3,2103946,15656} , {4,2327144,19643} ,
	                        {5,2398969,24017} , {6,2548615,29058} , {7,2612044,35611} , {8,2639985,45146} , 
	                        {9,2686183,61168} , {10,0,0} };
		/*2012*/
	Registro mas_doce[10] = {{1,1493334, 7239} , {2,1854314,11867} , {3,2170623,15733} , {4,2416120,19521},
							 {5,2462153,23921}, {6,2673989,28863} , {7,2815853,35565} , {8,2811864,44913},
							 {9,2957767,61079}, {10,0,0} };

		/*Menos de 2500*/
		/*2010*/                        
	Registro menos_diez[10]={{1,1622848,6470}, {2,1130770,11543}, {3,851731,15499} , {4,628533,19674} ,
	                        {5,556708,23782} , {6,407062,29065} , {7,343633,35562} , {8,315692,44613} , 
	                        {9,269494,60775} , {10,0,0} };

		/*2012*/
	Registro menos_doce[10]= {{1,1662603,6780} , {2,1301623,11689} , {3,985314,15737} , {4,739817,19489} ,
	                        {5,693784,23891} , {6,481948,28858} , {7,340084,35614} , {8,344073,44322} , 
	                        {9,198170,60032} , {10,0,0} };
	/*Asignamos las direcciones de memoria en un arreglo*/
	Registro *datos[4];
	datos[0] = mas_diez;
	datos[1] = mas_doce;
	datos[2] = menos_diez;
	datos[3] = menos_doce;
/*---------------------------------------------------------------------------------------------*/
/*delaracion de variables utiles*/
	int num;
	int opc; 
	int nivel;
	
	float medianAnual, varAnual, desvAnual;
	
/*-------------------------------------------------------------------------------------------*/
	printf(" Bienvenido, este programa realiza operaciones con los\n");
	printf(" ingresos promedio de los hogares mexicanos entre 2010 y\n");
	printf(" 2012\n\n");
	
	do{
		opc = menu();
		switch(opc){
			case 1:
				do{
					printf("\nSeleccione el segmento cuyo promedio de ingreso desea, segun su numero de inciso\n");
					printf("Poblados con mas de 2,500 habitantes\n");
					printf(" 0) A%co 2010    1) A%co 2012\n", 164,164);
					printf("Poblados con menos de 2,500\n");
					printf(" 2) A%co 2010    3) A%co 2012\n>: ", 164,164);
					scanf("%d", &num);	
					if(num < 0 || num > 3)
						printf("Opcion no valida, intente de nuevo.\n");
				}while(num < 0 || num > 3);
				
				datos[num]->promedio = promedio(datos, num);
				printf("El promedio de ingreso del segmento seleccionado es de %.2f\n", datos[num]->promedio);
				system("pause");
				break;
			case 2:
				do{
					printf("\nSeleccione el segmento cuya varianza desea obtener, segun su numero de inciso\n");
					printf("Poblados con mas de 2,500 habitantes\n");
					printf(" 0) A%co 2010    1) A%co 2012\n", 164,164);
					printf("Poblados con menos de 2,500\n");
					printf(" 2) A%co 2010    3) A%co 2012\n>: ", 164,164);
					scanf("%d", &num);	
					if(num < 0 || num > 3)
						printf("Opcion no valida, intente de nuevo.\n");
				}while(num < 0 || num > 3);
				
				datos[num]->varianza = varianza(datos, num);
				printf("La varianza del segmento seleccionado es de %.2f\n", datos[num]->varianza);
				system("pause");
				break;
			case 3:
				do{
					printf("\nSeleccione el segmento cuya desviacion estandar desea obtener, segun su numero de inciso\n");
					printf("Poblados con mas de 2,500 habitantes\n");
					printf(" 0) A%co 2010    1) A%co 2012\n", 164,164);
					printf("Poblados con menos de 2,500\n");
					printf(" 2) A%co 2010    3) A%co 2012\n>: ", 164,164);
					scanf("%d", &num);	
					if(num < 0 || num > 3)
						printf("Opcion no valida, intente de nuevo.\n");
				}while(num < 0 || num > 3);
				
				datos[num]->desviacion = desviacionSTD(datos, num);
				printf("La desviacion del segmento seleccionado es de %.2f\n", datos[num]->desviacion);
				system("pause");
				break;
			case 4:
				do{
					printf("\nSeleccione el segmento cuyo ingreso Per Capita desea obtener, segun su numero de inciso\n");
					printf("Poblados con mas de 2,500 habitantes\n");
					printf(" 0) A%co 2010    1) A%co 2012\n", 164,164);
					printf("Poblados con menos de 2,500\n");
					printf(" 2) A%co 2010    3) A%co 2012\n>: ", 164,164);
					scanf("%d", &num);	
					if(num < 0 || num > 3)
						printf("Opcion no valida, intente de nuevo.\n");
				}while(num < 0 || num > 3);
					printf("Seleccione el nivel de ingreso deseado\n>: ");
					scanf("%d", &nivel);
				
				printf("El ingreso Per Capita del segmento elegido es %.2f\n", ingresoPerCapita(datos, num, nivel));
				system("pause");
				break;
			case 5:
				//[5]Agregar datos a algun nivel de ingreso
				agregarDatos(datos);
				system("pause");
				break;
			case 6:
				//[6] Obtener mediana, varianza y desviacion estandar
				do{
					printf("\nSeleccione un a%co para ver su mediana, varianza y desviacion estandar segun su inciso\n" , 164);
					printf("\t1) 2010\t2) 2012\n>: ");
					scanf("%d", &num);
					if(num < 1 || num > 2)
						printf("Opcion no valida, intente de nuevo.\n");
				}while(num < 1 || num > 2);
				medianAnual = mediana(datos, num);
				varAnual = varianzaAnual(datos, num);
				desvAnual = desviacionAnual(datos, num);
				
				printf("Los datos correspondientes al a%co seleccionado son:\n", 164);
				printf(" Mediana: %.0f\n Varianza: %.1f\n Desviacion estandar: %.1f\n", medianAnual, varAnual, desvAnual);
				system("pause");
				break;
			case 7:
				comparacion(datos);
				system("pause");
				break;
			case 8:
				imprimirInfo(datos, 4);
				system("pause");
				break;
			case 9:
				break;
			default:
				printf("Opcion invalida, por favor intente de nuevo\n\n");
				break;			
		}
		
		system("cls");
	}while(opc != 9);
	printf("Gracias por usar el programa, hasta luego\n");
	return 0;

	}


int menu(){
	int opcion;
	
	printf("Seleccione una opcion\n");
	printf("[1] Calcular media por a%co y segmento poblacional\n", 164);	//Listo
	printf("[2] Calcular varianza por a%co y segmento poblacional\n",164);	//Listo
	printf("[3] Calcular desviacion estandar por a%co y segmento poblacional\n",164); //Listo
	printf("[4] Ingreso per capita\n"); //Listo
	printf("[5] Agregar datos\n"); 	//Listo
	printf("[6] Obtener Mediana, Varianza y Desviacion std por a%co\n",164); //Listo
	printf("[7] Comparar Mediana, Varianza y Desviacion std por a%co\n",164); //Listo
	printf("[8] Imprimir toda la informacion\n");	//Listo
	printf("[9] Salir\n");	//Listo
	printf("Que opcion desea elegir?\n>: ");
	scanf("%d", &opcion);
	
	return opcion;
	
}

void imprimirInfo(Registro *datos[4], int n){
	int i,j;
	Registro *pAux;
	
	/*--------------------Ingresos---------------------*/
	printf("Tabla de ingresos\n");
	printf("| Nivel | Mas de 2500 hab   | Menos de 2500 hab |\n");
	printf("|       |  2010   |   2012  |  2010   |   2012  |\n");
	printf("+-------+---------+---------+---------+---------+\n");

	for(j = 0; j < 10; j++){
		printf("| %3d   ", j+1);
		for(i = 0; i < n; i++){
			pAux = datos[i]; // Ejemplo: pAux = datos[0] = mas_diez
			printf("| %7.0f " , pAux[j].ingresos);
		}
		if(i == 4)
			printf("|\n");
	}
	/*--------------------Hogares---------------------*/
	printf("\nTabla de hogares\n");
	printf("| Nivel | Mas de 2500 hab   | Menos de 2500 hab |\n");
	printf("|       |  2010   |   2012  |  2010   |   2012  |\n");
	printf("+-------+---------+---------+---------+---------+\n");
	
	for(j = 0; j < 10; j++){
		printf("| %3d   ", j+1);
		for(i = 0; i < n; i++){
			pAux = datos[i];
			printf("| %7.0f " , pAux[j].hogares);
		}
		if(i == 4)
			printf("|\n");
	}
	
	/*----------------------Promedios-----------------------*/
	printf("\nTabla de Promedios\n");
	printf("| Mas de 2500 hab   | Menos de 2500 hab |\n");
	printf("|  2010   |   2012  |  2010   |   2012  |\n");
	printf("+---------+---------+---------+---------+\n");

	for (i = 0; i < 4; i++){
		printf("| %7.0f ", promedio(datos, i));
	}
	printf("|\n");
	/*-----------------------Varianzas---------------------*/
	printf("\nTabla de varianzas\n");
	printf("|    Mas de 2500 hab    |   Menos de 2500 hab   |\n");
	printf("|    2010   |    2012   |   2010    |    2012   |\n");
	printf("+-----------+-----------+-----------+-----------+\n");

	for (i = 0; i < 4; i++){
		printf("| %8.0f ", varianza(datos, i));
	}
	printf("|\n");
	
	/*---------------------Desviaciones---------------------*/
	printf("\nTabla de desviaciones estandar\n");
	printf("| Mas de 2500 hab   | Menos de 2500 hab |\n");
	printf("|  2010   |   2012  |  2010   |   2012  |\n");
	printf("+---------+---------+---------+---------+\n");

	for (i = 0; i < 4; i++){
		printf("| %7.0f ", desviacionSTD(datos, i));
	}
	printf("|\n");
	
}

float promedio(Registro *datos[4], int segm){	
	Registro *pAux;
	int cont=0;
	int i;
	float suma = 0;
	pAux = datos[segm];
	
	for(i = 0; i < 10; i++){
		if(pAux[i].ingresos != 0)	//Checamos si una celda esta vacia
			cont++;
		suma += pAux[i].ingresos;	
	}
	
	return (suma/cont);
}

float varianza(Registro *datos[4], int segm){
	Registro *pAux;
	float cont = 0;
	int i;
	float suma = 0;
	float prom = promedio(datos, segm);
	float numero;
	pAux = datos[segm];
	
	for(i = 0; i < 10; i++){
		if(pAux[i].ingresos != 0){	//Checamos si alguna celda esta vacia
			cont++;
			numero = pAux[i].ingresos - prom;
			suma += pow(numero, 2);
		}
	}
	return (suma/cont);
 }
 
float desviacionSTD(Registro *datos[4], int segm){
 	float var = varianza(datos, segm);
 	float raiz = sqrt(var);
 	return raiz;
 }
 
float ingresoPerCapita(Registro *datos[4], int segm, int nivel){
 	Registro *pAux;
 	float capita;
 	pAux = datos[segm];
 	capita = pAux[nivel].ingresos / 4; // El inegi define una familia como ~ 4 personas
 	
	
	return(capita);	
 }


 float mediana(Registro *datos[4], int anio){
 	float ingresos[20]; //Aqui almacenaremos todos los ingresos de un anho
 	float temp;
 	float median;
 	int i, c = 0;
 	int cambios;
 	int posicion;
 	Registro *segmentoA;
 	Registro *segmentoB;
 	
 	if(anio == 1){//La opcion de 2010 es 1, 2012 es 2
 		segmentoA = datos[0];
 		segmentoB = datos[2];
	}else{
		segmentoA = datos[1];
 		segmentoB = datos[3];
	}
	/*ciclo para llenar los datos de el arreglo de 20 datos*/
	for(i = 0; i < 10; i++){
		ingresos[i] = segmentoA[i].ingresos;
		if(ingresos[i] == 0)
			c++;
	}
	for(i = 10; i < 20; i++){
		ingresos[i] = segmentoB[i].ingresos;
		if(ingresos[i] == 0)
			c++;
	}
	/*Procedemos a hacer un Bubble Sort*/
	while(1){
		cambios = 0;
		for(i = 1; i < 20; i++){
			if(ingresos[i] < ingresos[i-1]){
				temp = ingresos[i];
				ingresos[i] = ingresos[i-1];
				ingresos[i-1] = temp;
				cambios = 1;
			}
		}
		if(cambios == 0)
			break;
	}

	if((20-c) % 2 == 0){
		posicion = ((20-c)/2)+c;//Obtenemos uno de los valores del medio
		median = (ingresos[posicion]+ingresos[posicion-1])/2;
	}else{
		posicion = (20-c)/2 + c;
		median = ingresos[posicion];
	}

	return median;
 }

float varianzaAnual(Registro *datos[4], int anio){
	float ingresos[20], promedio, suma = 0;
	float varianza;
	int contador = 0;
	int i;
	Registro *segmentoA;
 	Registro *segmentoB;
	
	if(anio == 1){//La opcion de 2010 es 1, 2012 es 2
 		segmentoA = datos[0];
 		segmentoB = datos[2];
	}else{
		segmentoA = datos[1];
 		segmentoB = datos[3];
	}
/*ciclo para llenar los datos de el arreglo de 20 datos*/
	for(i = 0; i < 10; i++){
		ingresos[i] = segmentoA[i].ingresos;
		
	}
	for(i = 10; i < 20; i++){
		ingresos[i] = segmentoB[i].ingresos;
		
	}

	/* Sacamos el promedio */
	for(i = 0; i < 20; i++){
		suma += ingresos[i];
		if(ingresos[i] != 0)
			contador++;
	}

	promedio = suma/contador;
	suma = 0;
	for(i = 0; i < 20; i++){
		if(ingresos[i] != 0){
			suma += pow(ingresos[i] - promedio, 2);
		}
	}
	varianza = suma/contador;

	return (varianza);

}

float desviacionAnual(Registro *datos[4], int anio){
	float varianza = varianzaAnual(datos, anio);

	return(sqrt(varianza));
}

void comparacion(Registro * datos[4]){
	printf("Comparacion de datos entre 2010 y 2012\n\n");
	printf("             |     2010    |     2012    |\n");
	printf("-------------+-------------+-------------+\n");
	printf("   Mediana   |  %7.0f    |   %7.0f   |\n", mediana(datos, 1), mediana(datos,2));
	printf("   Varianza  | %.1f | %.1f |\n", varianzaAnual(datos, 1) , varianza(datos, 2));
	printf("  Desviacion | %10.1f  | %10.1f  |\n", desviacionAnual(datos, 1), desviacionAnual(datos, 2));
}

void agregarDatos(Registro *datos[4]){
	Registro *pAux;
	int i;
	int num;
	
	printf("De momento, solo es posible a%cadir datos en el nivel 10 de ingreso\n", 164);
	printf("Los segmentos disponibles para a%cadir informacion son:\n", 164);
	printf(" Poblados con mas de 2500 hab.\n");
	/*Checamos cuales estan disponibles, y los mostramos*/
	for(i = 0; i < 4; i++){
		if(i % 2 == 0)
			num = 2010;
		else
			num = 2012;
		if(i == 2)
			printf(" Poblados con menos de 2500 hab.\n");
		pAux = datos[i];
		if(pAux[9].ingresos == 0)
			printf("   %d) %d\n", i, num);
	}
	
	
	do{
		printf("Seleccione el segmento que desea modificar, en base a su inciso\n>: ");
		scanf("%d", &num);
		if(num < 0 || num > 3)
			printf("NO VALIDO, REINTENTE\n");
	}while(num < 0 || num > 3);
	
	pAux = datos[num];
	
	printf("Ingrese la cantidad de hogares en el segmento\n>: ");
	scanf("%f", &pAux[9].hogares);
	
	printf("Ingrese los ingresos del segmento\n>: ");
	scanf("%f", &pAux[9].ingresos);
	
	
}