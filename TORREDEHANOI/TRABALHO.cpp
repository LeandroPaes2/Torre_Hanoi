#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio2.h>
#include<windows.h>
#include <Math.h>

#include "pilha.h"

/*
	Implementar a simulação automática das Torres de Hanói utilizando Pilhas Múltiplas
	[cheq]Implementar a simulação manual, operada pelo Usuário, com as devidas validações.

	[OK] 3 pilha
	[OK]3 a 10 disco, o usuario escolhe
	[OK] começa inteiro de forma ordenada na torre 1
	
	objetivo passar de forma organizada pra torre 3
	nao pode colocar maior em cima de menor
*/


void inserir (TpDisco &p1, int tam){
	while( tam > 0 && !cheia(p1.topo)){
		p1.disc[++p1.topo] = tam;
		tam --;
	}
}



void moldura(int CI, int LI, int CF, int LF, int CorTxt, int CorFundo){
	
	int i;
	textcolor(CorTxt);
	textbackground(CorFundo);
	
	gotoxy(CI,LI); printf("%c", 201);
	gotoxy(CI,LF); printf("%c", 200);
	gotoxy(CF,LI); printf("%c", 187);
	gotoxy(CF,LF); printf("%c", 188);
	
	for(i = CI+1; i < CF; i++){
		gotoxy(i, LI); printf("%c",205);
		gotoxy(i, LF); printf("%c", 205);
	}
	
	for(i = LI+1; i < LF; i++){
		gotoxy(CI, i); printf("%c",186);
		gotoxy(CF, i); printf("%c", 186);
	}
	
	textcolor(7);
	textbackground(0);
}

char pegarPilha(void){

	moldura(1,1,120,30,0,7);
    gotoxy(3,25);
	printf("[A] Pilha 1");
	gotoxy(3,26);
    printf("[B] Pilha 2");
    gotoxy(3,27);
    printf("[C] Pilha 3");
    gotoxy(3,28);
    printf("Opcao: ");
    
    return toupper(getche());
}



int JOGAR (TpDisco &p1, TpDisco &p2, TpDisco &p3, int tam){
	
	int movimento = 0;
	char op1, op2;
	do{
		clrscr();
		
		exibe(p1,p2,p3);
		gotoxy(3,24);
		textcolor(6);
		printf("Pegar elemento");
		textcolor(7);

		op1 = pegarPilha();
		
		
		switch (op1){
			
			case 'A': 
				if(!vazia(p1.topo)){
					gotoxy(3,24);
					textcolor(2);
					printf("Inserir elemento");
					textcolor(7);
					op2 = pegarPilha();
					textcolor(4);
					switch (op2){
						case 'A': 
							gotoxy(20,28);
							printf("Inserido no mesmo lugar");
							getch();
							break;
							
						case 'B':
							if(elementotopo(p1) < elementotopo(p2) || vazia(p2.topo))
							{
								insere(p2, retira(p1));
								movimento++;
							}
								
							else
							{
								gotoxy(20,28);
								printf("Movimento invalido!");
								getch();
							}
								
							break;
							
						case 'C':
							if(elementotopo(p1) < elementotopo(p3) || vazia(p3.topo))
							{
								insere(p3, retira(p1));
								movimento++;
							}
							else
							{
								gotoxy(20,28);
								printf("Movimento invalido!");
								getch();
							}
								
							break;
					}	
					textcolor(7);
				}
				break;
				
			case 'B':
				if(!vazia(p2.topo)){
					gotoxy(3,24);
					textcolor(2);
					printf("Inserir elemento");
					textcolor(7);
					op2 = pegarPilha();
					textcolor(4);
					switch (op2){
						case 'A': 
							if(elementotopo(p2) < elementotopo(p1) || vazia(p1.topo))
							{
								insere(p1, retira(p2));
								movimento++;
							}
							else
							{
								gotoxy(20,28);
								printf("Movimento invalido!");
								getch();
							}
								
							break;
							
						case 'B':
							gotoxy(20,28);
							printf("Inserido no mesmo lugar");
							getch();
							break;
							
						case 'C':
							if(elementotopo(p2) < elementotopo(p3) || vazia(p3.topo))
							{
								insere(p3, retira(p2));
								movimento++;
							}
							else
							{
								gotoxy(20,28);
								printf("Movimento invalido!");
								getch();
							}
								
							break;
					}
					textcolor(7);	
				}
				break;
				
			case 'C':
				if(!vazia(p3.topo)){
					gotoxy(3,24);
					textcolor(2);
					printf("Inserir elemento");
					textcolor(7);
					op2 = pegarPilha();
					textcolor(4);
					switch (op2){
						case 'A': 
							if(elementotopo(p3) < elementotopo(p1) || vazia(p1.topo))
							{
								insere(p1, retira(p3));
								movimento++;
							}
							else
							{
								gotoxy(20,28);
								printf("Movimento invalido!");
								getch();
							}
								
							break;
							
						case 'B':
							if(elementotopo(p3) < elementotopo(p2) || vazia(p2.topo))
							{
								insere(p2, retira(p3));
								movimento++;
							}
							else
							{
								gotoxy(20,28);
								printf("Movimento inválido!");
								getch();
							}
								
							break;
							
						case 'C':
							gotoxy(20,28);
							printf("Inserido no mesmo lugar");
							getch();
							break;
					}	
					textcolor(7);
				}	
				break;
		}		
	}while(p3.topo != tam - 1);
	clrscr();
	moldura(1,1,120,30,0,7);

	exibe(p1,p2,p3);

	gotoxy(26,28);
	textcolor(14);
	printf("!!!!!!!!!!!!!!!!!!!!!!PARABENS IHUUUUUU!!!!!!!!!!!!!!!!!!!!!!!!!!");
	textcolor(7);
	gotoxy(3, 25);
    printf("Total de Movimentos: %d", movimento);
	getch();
	inicializa(p1);
	inicializa(p2);
	inicializa(p3);
}

void Automatica(TpDisco &p1, TpDisco &p2, TpDisco &p3, int tam)
{
    int movimentos = pow(2, tam) - 1;
    int origem, destino, i;

    for (i = 1; i <= movimentos; i++)
    {
        

		if (tam % 2 == 0)
        {
            if (i % 3 == 1) 
            {
            	origem = 1; 
				destino = 2;
            }
            else if (i % 3 == 2) 
            {
            	origem = 1; 
				destino = 3; 
            }
            else
            {
				origem = 2; 
				destino = 3; 
			}
        }
        else
        {
            if (i % 3 == 1) 
			{ 
				origem = 1; 
				destino = 3; 
			}
            else if (i % 3 == 2) 
			{ 
				origem = 1; 
				destino = 2; 
			}
            else 
			{ 
				origem = 2; 
				destino = 3; 
			}
        }

        
        if (origem == 1 && destino == 2)
        {
            if (!vazia(p1.topo) && (vazia(p2.topo) || elementotopo(p1) < elementotopo(p2)))
                insere(p2, retira(p1));
            else
                insere(p1, retira(p2));
        }
        else if (origem == 1 && destino == 3)
        {
            if (!vazia(p1.topo) && (vazia(p3.topo) || elementotopo(p1) < elementotopo(p3)))
                insere(p3, retira(p1));
            else
                insere(p1, retira(p3));
        }
        else if (origem == 2 && destino == 3)
        {
            if (!vazia(p2.topo) && (vazia(p3.topo) || elementotopo(p2) < elementotopo(p3)))
                insere(p3, retira(p2));
            else
                insere(p2, retira(p3));
        }
        else if (origem == 2 && destino == 1)
        {
            if (!vazia(p2.topo) && (vazia(p1.topo) || elementotopo(p2) < elementotopo(p1)))
                insere(p1, retira(p2));
            else
                insere(p2, retira(p1));
        }
        else if (origem == 3 && destino == 1)
        {
            if (!vazia(p3.topo) && (vazia(p1.topo) || elementotopo(p3) < elementotopo(p1)))
                insere(p1, retira(p3));
            else
                insere(p3, retira(p1));
        }
        else if (origem == 3 && destino == 2)
        {
            if (!vazia(p3.topo) && (vazia(p2.topo) || elementotopo(p3) < elementotopo(p2)))
                insere(p2, retira(p3));
            else
                insere(p3, retira(p2));
        }

        clrscr();
        moldura(1,1,120,30,0,7);
        exibe(p1, p2, p3);
        Sleep(500);
    }

    gotoxy(3, 25);
    printf("Total de Movimentos: %d", movimentos);
    getch();
    inicializa(p1);
	inicializa(p2);
	inicializa(p3);
}

void desenho(int num, int y, int x)
{
	if(num == 1)
	{
		gotoxy(x,y);
		printf("_");
		gotoxy(x-1,y+1);
		printf("|_|");
	}
	else if(num == 2)
	{
		gotoxy(x,y);
		printf("___");
		gotoxy(x-1,y+1);
		printf("|___|");
	}
	else if(num == 3)
	{
		gotoxy(x,y);
		printf("_____");
		gotoxy(x-1,y+1);
		printf("|_____|");
	}
	else if(num == 4)
	{
		gotoxy(x,y);
		printf("_______");
		gotoxy(x-1,y+1);
		printf("|_______|");
	}
	else if(num == 5)
	{
		gotoxy(x,y);
		printf("_________");
		gotoxy(x-1,y+1);
		printf("|_________|");
	}
	else if(num == 6)
	{
		gotoxy(x,y);
		printf("___________");
		gotoxy(x-1,y+1);
		printf("|___________|");
	}
	else if(num == 7)
	{
		gotoxy(x,y);
		printf("_____________");
		gotoxy(x-1,y+1);
		printf("|_____________|");
	}
	else if(num == 8)
	{
		gotoxy(x,y);
		printf("_______________");
		gotoxy(x-1,y+1);
		printf("|_______________|");
	}
	else if(num == 9)
	{
		gotoxy(x,y);
		printf("_________________");
		gotoxy(x-1,y+1);
		printf("|_________________|");
	}
	else if(num == 10)
	{
		gotoxy(x,y);
		printf("___________________");
		gotoxy(x-1,y+1);
		printf("|___________________|");
	}
}






char menu(void){

    clrscr();
	moldura(1,1,120,30,0,7);
	gotoxy(3,3);
	printf("Escolha a quantidade de discos:");
	gotoxy(3,4);
    printf("[A] 3 discos");
    gotoxy(3,5);
    printf("[B] 4 discos");
    gotoxy(3,6);
	printf("[C] 5 discos");
	gotoxy(3,7);
    printf("[D] 6 discos");
    gotoxy(3,8);
    printf("[E] 7 discos");
    gotoxy(3,9);
    printf("[F] 8 discos");
    gotoxy(3,10);
    printf("[G] 9 discos");
    gotoxy(3,11);
    printf("[H] 10 discos");
    gotoxy(3,12);
    printf("Opcao: ");
    return toupper(getche());
}

char Modo(void){
	
	clrscr();
	moldura(1,1,120,30,0,7);
	gotoxy(3,3);
	printf("Escolha o Modo do jogo:");
	gotoxy(3,4);
    printf("[A] Manual");
    gotoxy(3,5);
    printf("[B] Automatica");
    gotoxy(3,6);
    printf("Opcao: ");
	return toupper(getch());
}

int main(void){

	TpDisco p1, p2, p3;
	char op1, op2;
	int tam;
	
	inicializa(p1);
	inicializa(p2);
	inicializa(p3);

	
	do{
		op1 = menu();
		switch (op1){
			case 'A' : tam = 3;
					inserir(p1, tam);
					op2 = Modo();
					switch(op2){
						case 'A':	JOGAR(p1, p2, p3, tam);
							break;
						case 'B':	Automatica(p1, p2, p3, tam);
							break;
					}
				break;
			case 'B' : tam = 4;
					inserir(p1, tam);
					op2 = Modo();
					switch(op2){
						case 'A':	JOGAR(p1, p2, p3, tam);
							break;
						case 'B':	Automatica(p1, p2, p3, tam);
							break;
					}
				break;
			case 'C' : tam = 5;
					inserir(p1, tam);
					op2 = Modo();
					switch(op2){
						case 'A':	JOGAR(p1, p2, p3, tam);
							break;
						case 'B':	Automatica(p1, p2, p3, tam);
							break;
					}
				break;
			case 'D' : tam = 6;
					inserir(p1, tam);
					op2 = Modo();
					switch(op2){
						case 'A':	JOGAR(p1, p2, p3, tam);
							break;
						case 'B':	Automatica(p1, p2, p3, tam);
							break;
					}
				break;
			case 'E' : tam = 7;
					inserir(p1, tam);
					op2 = Modo();
					switch(op2){
						case 'A':	JOGAR(p1, p2, p3, tam);
							break;
						case 'B':	Automatica(p1, p2, p3, tam);
							break;
					}
				break;
			case 'F' : tam = 8;
					inserir(p1, tam);
					op2 = Modo();
					switch(op2){
						case 'A':	JOGAR(p1, p2, p3, tam);
							break;
						case 'B':	Automatica(p1, p2, p3, tam);
							break;
					}
				break;
			case 'G' : tam = 9;
					inserir(p1, tam);
					op2 = Modo();
					switch(op2){
						case 'A':	JOGAR(p1, p2, p3, tam);
							break;
						case 'B':	Automatica(p1, p2, p3, tam);
							break;
					}
				break;
			case 'H' : tam = 10;
					inserir(p1, tam);
					op2 = Modo();
					switch(op2){
						case 'A':	JOGAR(p1, p2, p3, tam);
							break;
						case 'B':	Automatica(p1, p2, p3, tam);
							break;
					}
				break;
		}

		
	}while(op1!=27);
	
	return 0;
}






