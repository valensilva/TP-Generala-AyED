
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define CANTJUGADORES 5

struct datosArchivo{
	int idJugada;
	char nombre[20];
	int fecha;
	int puntaje;
};
struct nodo{
	datosArchivo info;
	nodo* sgte;
};

void inicializarMatrizJugadores(int matrizJugadores[12][CANTJUGADORES], int cantJugadores);
void imprimeMatrizPuntajes(int matrizJugadores[12][CANTJUGADORES],int cantJugadores, int Jugador);
void inicializarVectorPuntos(int vectorPuntos[], int cantJugadores);
void puntuacion(int v[], int Jugador, int cantTiradas, int acumGeneraladoble, int matrizJugadores[12][CANTJUGADORES], int vectorPuntos[]);
void ordenar(int v[]);
void tirar(int v[]);
void sumaPuntaje(int vectorPuntos[], int cantJugadores, datosArchivo datos[]);
void dadosIndividuales(int &puntos, int &pos, int v[5]);
void imprimirRanking();

int generala (int v[]);
int poker (int v[]);
int full (int v[]);
int escalera(int v[]);
int random();
nodo* insertarOrdenado(nodo* &lista, datosArchivo datos);



int main(){
	int cantJugadores=0, acum=0, cantTiradas=0, seguirTirando=0, v[5], puntaje=0, g=0, acumGeneraladoble=0, Jugador=0, limite;
	
	srand(time(NULL));
	cout << "JUEGO DE LA GENERELA" << endl;
	cout << "Ingrese cantidad de jugadores: " << endl;
	cin >> cantJugadores;
	datosArchivo datos[cantJugadores];	
	for (int i=0;i<cantJugadores;i++){
		cout << "Ingrese los nombres de los jugadores en orden: ";
		cin >> datos[i].nombre;
		cout << "Ingrese fecha en formato AAAAMMDD: ";
		cin >> datos[i].fecha;
		cout << "Ingrese id del juego: ";
		cin >> datos[i].idJugada;
	}

	int matrizJugadores[12][CANTJUGADORES];
	int vectorPuntos[cantJugadores];
	inicializarMatrizJugadores( matrizJugadores, cantJugadores);
	inicializarVectorPuntos(vectorPuntos, cantJugadores);
	limite = 11*cantJugadores;
	while (acum < limite && matrizJugadores[11][Jugador]!=200){
		seguirTirando = 1;
		cantTiradas = 1;
		cout << "Jugador "<< Jugador + 1 <<endl;
		while (seguirTirando == 1) {
			
		
			if (cantTiradas == 3){
				cantTiradas++;
		    	tirar(v);
			    g=generala(v);
		    if (g==50){
		    	acumGeneraladoble++;
					  }	
				cout << "Ya no puede seguir tirando."<<endl;
				seguirTirando = 0;
			}
			else{
				cantTiradas++;
		    	tirar(v);
			    g=generala(v);
		    if (g==50){
		    	acumGeneraladoble++;
					  }	   
			cout << " Si quiere seguir tirando presione 1, sino presione 0."<< endl;
			cin >> seguirTirando;
				
			}
		
			
			}
		
		puntuacion(v, Jugador, cantTiradas, acumGeneraladoble, matrizJugadores, vectorPuntos);
		
		imprimeMatrizPuntajes(matrizJugadores,cantJugadores, Jugador);
		acum++;
		if (Jugador >= cantJugadores-1)
		Jugador=0;
		else Jugador++;	
	
	
	}
	
		
			if (matrizJugadores[11][Jugador-1]==200){
		
		cout << "Gano el jugador " << Jugador << " por generala servida."<<endl;
			}
	else {
		sumaPuntaje(vectorPuntos, cantJugadores, datos);
	}
    
    	imprimirRanking();
    
    
return 0;	

}

void inicializarMatrizJugadores(int matrizJugadores[12][CANTJUGADORES], int cantJugadores){
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < cantJugadores; j++){
            matrizJugadores[i][j] = 0;
        }
    }
}
void inicializarVectorPuntos(int vectorPuntos[], int cantJugadores){
	for (int i=0;i<cantJugadores;i++){
		vectorPuntos[i]=0;
	}
}
void ordenar(int v[5])
{
    int imin;
    int j;
    int aux;
 
    for (int i = 0; i < 5; i++) {
        imin = i;
        for(j=i+1;j<5;j++) {
            if (v[j]<v[imin])
            imin=j;
        }
        aux = v[i];
        v[i] = v[imin];
        v[imin] = aux;
    }
}

 int random() {
 
 return rand() % 6 + 1;

}
void imprimeMatrizPuntajes(int matrizJugadores[12][CANTJUGADORES],int cantJugadores, int Jugador){
    int i,j;
    cout << "                ";
    for(j = 0; j < cantJugadores; j++){
        cout << "Jugador "<< j+1 << "     ";
    }
    cout <<endl;
    for(i = 0; i < 11; i++){
        if(i < 6){
            cout << i + 1 << ":                  ";
        } else if(i == 6){
            cout << "Escalera:           ";
        } else if(i == 7){
            cout << "Full:               ";
        } else if(i == 8){
            cout << "Poker:              ";
        } else if(i == 9){
            cout << "Generala:           ";
        } else if(i == 10){
            cout << "Generala doble:     ";
        }
        for(j = 0; j < cantJugadores; j++){
            cout << matrizJugadores[i][j] << "           ";
        }
        cout <<endl;
    }
}
 
void tirar(int v[5])
{
	for (int i = 0; i < 5; i++){
		v[i] = random();
	}
        
        ordenar(v);
        cout <<"Su tirada es: ";
        for (int i = 0; i < 5; i++){
        	cout << v[i];
		}
		cout << " " << endl;
        
}




int generala (int v[5]){
	int a,i;
	for (i=0;i<5;i++){
		if (v[0] != v[i])
		 a = 0;
		else
		 a = 50; 
	}
	
	return a;
}
int poker( int v[5])
{
    int a1, a2 = 0, cant1 = 1, cant2 = 0, a;
 
    a1 = v[0];
    for (int i = 1; i < 5; i++)
    {
        if (a1 == v[i])
            cant1++;
        else if (a2 == 0)
        {
            a2 = v[i];
            cant2++;
        }
        else if (a2 == v[i])
            cant2++;
    }
 
   if (cant1 == 4 || cant2 == 4){
   	a=35;
   }
   else a=0;
   return a;
}

int full( int v[5]) {
    int a, b = 0, cant1 = 1, cant2 = 0, c = 35;
 
    a = v[0];
    for (int i = 1; i < 5; i++)
    {
        if (a == v[i])
            cant1++;
        else if (b == 0)
        {
            b = v[i];
            cant2++;
        }
        else if (b == v[i])
            cant2++;
    }
     if((cant1 == 3 && cant2 == 2) || (cant2 == 3 && cant1 == 2)){
     	return c;
	 }
	 else return 0;
     
}

int escalera (int v[]){
	int a,i;
	if (v[0]==1 || v[0]==2 || (v[0]==3 && v[4]==1)){
		for (i=1;i<5;i++){
			if (v[i]==(v[i-1])+1)
				  a++;
		}
	}
	
	if (a>=3)
	 a=25;
	else 
		a=0;
	
	return a;
}

void puntuacion(int v[], int Jugador,  int cantTiradas, int acumGeneraladoble, int matrizJugadores[12][CANTJUGADORES], int vectorPuntos[]){
	int i, vector[6]={0,0,0,0,0,0}, puntos, a, b, puntos1;
	if ((cantTiradas-1)==1 ){
		if (generala(v) == 50 && matrizJugadores[11][Jugador]==0){			
			matrizJugadores[11][Jugador]=200;
			puntos1=200;
		}
		else if (poker(v) == 45 && matrizJugadores[8][Jugador]==0){			
			matrizJugadores[8][Jugador]=45;
			puntos1=45;
		}
		else if (full(v) == 35 && matrizJugadores[7][Jugador]==0){		
			matrizJugadores[7][Jugador]=35;
			puntos1=35;
		}
		else if (escalera(v) == 25 && matrizJugadores[6][Jugador]==0){
			matrizJugadores[6][Jugador]=25; 
			puntos1=25;
		}	
		else {
				for (i=0;i<5;i++){
					if (matrizJugadores[i][Jugador]==0){
						if (v[i]==1)
						vector[0]+=1;
					else if (v[i]==2)
						vector[1]+=2;
					else if (v[i]==3)
						vector[2]+=3;
					else if (v[i]==4)
						vector[3]+=4;
					else if (v[i]==5)
						vector[4]+=5;
					else if (v[i]==6)
						vector[5]+=6;
					}
					
				}
						puntos=vector[0];
				for (i=0;i<6;i++){
					if (vector[i]>puntos && matrizJugadores[i][Jugador]==0){
						puntos=vector[i];
						a=i;
						
					}					
				}
				matrizJugadores[a][Jugador]=puntos;
				puntos1=puntos;
		} 
	}
	else {
		if (acumGeneraladoble == 2 && matrizJugadores[10][Jugador]==0){

			matrizJugadores[10][Jugador]==100;
			puntos1=100;
		}
		else if (generala(v) == 50 && matrizJugadores[9][Jugador]==0){

			matrizJugadores[9][Jugador]==50;
			puntos1=50;
		}
		else if (poker(v) == 45 && matrizJugadores[8][Jugador]==0){

			matrizJugadores[8][Jugador]==40;
			puntos1=40;
		}
		else if (full(v) == 35 && matrizJugadores[7][Jugador]==0){

			matrizJugadores[7][Jugador]==30;
			puntos1=30;
		}
		else if (escalera(v) == 25 && matrizJugadores[6][Jugador]==0){

			matrizJugadores[6][Jugador]==20;
			puntos1=20;
		}	
		else {
				for (i=0;i<5;i++){
					if (v[i]==1 && matrizJugadores[0][Jugador]==0)
						vector[0]+=1;
					else if (v[i]==2 && matrizJugadores[1][Jugador]==0)
						vector[1]+=2;
					else if (v[i]==3 && matrizJugadores[2][Jugador]==0)
						vector[2]+=3;
					else if (v[i]==4 && matrizJugadores[3][Jugador]==0)
						vector[3]+=4;
					else if (v[i]==5 && matrizJugadores[4][Jugador]==0)
						vector[4]+=5;
					else if (v[i]==6 && matrizJugadores[5][Jugador]==0)
						vector[5]+=6;
				}
						puntos=vector[0];
				for (i=0;i<6;i++){
					if (vector[i]>puntos && matrizJugadores[i][Jugador]==0){
							puntos=vector[i];
							b=i;
					}					
				}	
				matrizJugadores[b][Jugador]=puntos;
				puntos1=puntos;
		} 
	}
		
	vectorPuntos[Jugador]+=puntos1;	
		
}		
	
void sumaPuntaje(int vectorPuntos[], int cantJugadores, datosArchivo datos[]){
		int posMax, Max, i;
		for (i = 0; i < cantJugadores; i++){
		cout << "Puntuaciones del jugador "<<i+1<<" "<<vectorPuntos[i]<<endl;
		}
		Max = vectorPuntos[0];
		posMax=0;
		for (i = 1;i <= cantJugadores; i++){ //busca el ganador
			if ( vectorPuntos[i]>Max){
				Max = vectorPuntos[i];
				posMax = i;
			}
			
		}
		
		cout << "El ganador es el jugador " << posMax + 1<< endl;
		
		FILE* f = fopen("jugadores.dat","wb+");
    	if(f == NULL){
        	cout << "No se pudo abrir para escritura el archivo jugadores.dat" << endl;
        return;
   		}
   			 cout << "Escritura de datos en archivo jugadores.dat:" << endl;
   		 	for(i = 0; i < cantJugadores; i++){
        		fwrite(&datos[i],sizeof(datosArchivo),1,f);
   		 }
   			 fclose(f);
   			 cout << "Fin de escritura de datos en archivo jugadores.dat:" << endl;
		
		
}

nodo* insertarOrdenado(nodo* &lista, datosArchivo datos){
	nodo* p= new nodo;
	p->info.idJugada = datos.idJugada;
	p->info.nombre[20] = datos.nombre[20];
	p->info.fecha = datos.fecha;
	p->info.puntaje = datos.puntaje;
	
	if (lista == NULL || datos.puntaje > lista -> info.puntaje){
		p->sgte=lista;
		lista=p;
	}
	else {
		nodo* q=lista;
		while (q->sgte != NULL && datos.puntaje > q->sgte->info.puntaje)
			q=p->sgte;
		p->sgte= q->sgte;
		q->sgte=p;
	}

}
void imprimirRanking(){
    FILE* archivo = fopen ("jugadores.dat", "rb");
    int leido, i, fecha, dia, mes, anio, resto;
    datosArchivo datos;
    nodo *lista, *p;
    lista = NULL;

    if(archivo == NULL){
        cout << "No se pudo abrir para lectura el archivo jugadores.dat" << endl;
        return;
    }
    cout << "Lectura de archivo jugadores.dat:" << endl;
    leido = fread(&datos,1,sizeof(datosArchivo),archivo);
    while(leido != 0){
        leido = fread(&datos,1,sizeof(datosArchivo),archivo);
        insertarOrdenado(lista,datos);
    }
    fclose(archivo);

    p = lista;
	i = 0;
    cout << "\n\nRanking de los 3 mejores jugadores: "<< endl;
	while(p != NULL && i < 3){
        fecha =  p -> info.fecha ;
        dia = fecha % 100;
        resto = fecha / 100;
        mes = resto % 100;
        resto = resto / 100;
        anio = resto;
        cout << "Jugador: " <<  p -> info.nombre<< ", id jugada " <<  p -> info.idJugada << ", fecha " <<  dia << "/" << mes << "/" << anio << ", puntaje " <<  p -> info.puntaje << endl;
		p = p -> sgte;
		i++;
	}
}

