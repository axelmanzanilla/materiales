#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

#define arriba 72
#define abajo 80
#define enter 13
#define pi 3.141592654
int n, opcion;
long double L, A, E, D, Pa, P[50], delta[50], sigma[50], dtotal;

void menu();
void final();
void climax();
void OcultarCursor();
void MostrarCursor();
void cuadro(int, int);
void gotoxy(int, int);
void guardar(int, int);
void segmentos(int, int);
void cuadrop(int, int, int, int);

int main(){
	Pa = 0;
	dtotal = 0;
	opcion = 0;
	OcultarCursor();
	menu();
	return 0;
}

void menu(){
	int tecla;
	bool rep = true;
	system("cls");
	cuadro(60,11);
	gotoxy(8,4); printf("Este programa sirve para calcular la deformaci%cn y",162);
	gotoxy(8,5); printf("esfuerzo de varias varas.");
	gotoxy(8,7); printf("%cQu%c sistema va a utilizar?",168,130);
	gotoxy(11,8); printf("Sistema Internacional");
	gotoxy(11,9); printf("Sistema Ingl%cs",130);
	while(rep){
		gotoxy(9,8); printf(" ");
		gotoxy(9,9); printf(" ");
		gotoxy(9,8 + opcion); printf(">");
		tecla = getch();
		switch(tecla){
		case arriba:
			opcion--;
			if(opcion<0) opcion = 1;
			break;
		case abajo:
			opcion++;
			if(opcion>1) opcion = 0;
			break;
		case enter:
			rep = false;
		}
	}
	MostrarCursor();
	gotoxy(8,11); printf("%cCu%cntos segmentos tiene la vara?",168,160);
	gotoxy(42,11); cin>>n;
	if(n>0){
		climax();
	}else main();
}

void climax(){
	for(int i=1;i<=n;i++){
		system("cls");
		cuadro(60,11);
		segmentos(n,i);
		guardar(i, opcion);	
	}
	final();
}

void final(){
	OcultarCursor();
	bool r = true;
	int m, tecla, op=0;
	system("cls");
	cuadro(60,n + 6);
	gotoxy(19,3); cout<<"Deformacion";
	gotoxy(34,3); cout<<"Esfuerzo";
	for(int i=0;i<n;i++){
		gotoxy(7,5+i); cout<<"Seccion "<<i+1;
		gotoxy(19,5+i); cout<<1000*delta[i]<<" mm.";
		gotoxy(34,5+i); cout<<sigma[i]/1000<<" MPa.";
	}
	gotoxy(7,7+n); cout<<"Deformacion Total:";
	gotoxy(27,7+n); cout<<1000*dtotal<<" mm.";
	gotoxy(5,10+n); cout<<"Que desea hacer?";
	gotoxy(8,11+n); cout<<"Reescribir algun dato";
	gotoxy(8,12+n); cout<<"Ir al Menu";
	gotoxy(8,13+n); cout<<"Salir";
	do{
		gotoxy(6,11+n); cout<<" ";
		gotoxy(6,12+n); cout<<" ";
		gotoxy(6,13+n); cout<<" ";
		gotoxy(6,11+n+op); cout<<">";
		tecla = getch();
		switch(tecla){
		case arriba:
			op--;
			if(op<0) op = 2;
			break;
		case abajo:
			op++;
			if(op>2) op = 0;
			break;
		case enter:
			r = false;
		}
	}while(r);
	switch(op){
	case 0:
		MostrarCursor();
		gotoxy(5,15+n); cout<<"Cual parte quiere volver a escribir?  ";
		cin>>m;
		if(m>0 && m<=n){
			Pa-=P[m-1];
			dtotal-=delta[m-1];
			system("cls");
			cuadro(60,11);
			segmentos(n,m);
			guardar(m,opcion);
		}
		final();
		break;
	case 1:
		main();
		break;
	case 2:
		cout<<" ";
	}
}

void segmentos(int N, int p){
	int largo, alto, inicio;
	switch(N){
	case 1:
		largo = 45;
		inicio = 6;
		alto = 3;
		break;
	case 2:
		largo = 28;
		inicio = 5;
		alto = 5;
		break;
	case 3:
		largo = 19;
		inicio = 5;
		alto = 5;
		break;
	case 4:
		largo = 14;
		inicio = 4;
		alto = 7;
		break;
	case 5:
		largo = 11;
		inicio = 3;
		alto = 9;
		break;
	default:
		gotoxy(25,7); cout<<"Imagen no disponible"<<endl;
	}
	if(n<=5){
		for(int i=0; i<N; i++){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cuadrop(largo, alto - (2*i),4+(largo*i),inicio+i);
		}
		p = N - p;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cuadrop(largo, alto - (2*p),4+(largo*p),inicio+p);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
}

void cuadro(int largo, int alto) {
	int inicio[] = { 4,2 };
	/**************************************************************/
	gotoxy(inicio[0], inicio[1]); printf("%c", 201);
	gotoxy(inicio[0] + largo, inicio[1]); printf("%c", 187);
	gotoxy(inicio[0], inicio[1] + alto); printf("%c", 200);
	gotoxy(inicio[0] + largo, inicio[1] + alto); printf("%c", 188);
	for (int i = 1; i < alto; i++) {
		gotoxy(inicio[0], inicio[1] + i); printf("%c", 186);
		gotoxy(inicio[0] + largo, inicio[1] + i); printf("%c", 186);
	}
	for (int i = 1; i < largo; i++) {
		gotoxy(inicio[0] + i, inicio[1]); printf("%c", 205);
		gotoxy(inicio[0] + i, inicio[1] + alto); printf("%c", 205);
	}
}

void cuadrop(int largo, int alto, int x, int y) {
	gotoxy(x, y); printf("%c", 195);
	gotoxy(x + largo, y); printf("%c", 191);
	gotoxy(x, y + alto); printf("%c", 195);
	gotoxy(x + largo, y + alto); printf("%c", 217);
	for (int i = 1; i < alto; i++) {
		gotoxy(x, y + i); printf("%c", 179);
		gotoxy(x + largo, y + i); printf("%c", 179);
	}
	for (int i = 1; i < largo; i++) {
		gotoxy(x + i, y); printf("%c", 196);
		gotoxy(x + i, y + alto); printf("%c", 196);
	}
}

void gotoxy(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void guardar(int I, int O){
	I--;
	if(I==1){
		gotoxy(15,14); cout<<"Escriba la fuerza positiva si va hacia la derecha";
	}
	gotoxy(5,14); cout<<"Parte "<<I+1;
	gotoxy(5,16); cout<<"Ingrese la torsion";
	gotoxy(5,17); cout<<"Ingrese el largo";
	gotoxy(5,18); cout<<"Ingrese el diametro";
	gotoxy(5,19); cout<<"Modulo de elast.";
	switch(O){
	case 0:
		gotoxy(23,16); cout<<"(N*m): ";
		gotoxy(22,17); cout<<"(m): ";
		gotoxy(25,18); cout<<"(mm): ";
		gotoxy(22,19); cout<<"(GPa): ";
		break;
	case 1:
		gotoxy(23,16); cout<<"(lb*in): ";
		gotoxy(22,17); cout<<"(in): ";
		gotoxy(25,18); cout<<"(in): ";
		gotoxy(22,19); cout<<"(Ksi): ";
		break;
	default:
		cout<<" ";
	}
	gotoxy(32,16); cin>>P[I];
	gotoxy(32,17); cin>>L;
	again1:
	gotoxy(32,18); cin>>D;
	if(D<=0) goto again1;
	again2:
	gotoxy(32,19); cin>>E;
	if(E<=0) goto again2;	
	//Conversion
	if(O==0){
		D/=1000;
		E*=1000000000;
	}else {
		E*=1000;
	}
	
	Pa += P[I];
	A= (pi*D*D)/(4);
	delta[I] = (Pa*L)/(A*E);
	sigma[I] = P[I]/A;
	dtotal += delta[I];
}

void OcultarCursor() {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &cci);
}

void MostrarCursor() {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = TRUE;
	SetConsoleCursorInfo(hCon, &cci);
}
