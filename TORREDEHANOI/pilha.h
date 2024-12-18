// PaILHAS MULTIPLAS SOCORRO

#define MAXPILHA 10

struct TpDisco{
    int topo;
    int disc[MAXPILHA];
};



void inicializa(TpDisco &p){
    p.topo = -1;  
}

int retira(TpDisco &p){
    return p.disc[p.topo--];
}

int elementotopo(TpDisco p){
    return p.disc[p.topo];
}

int cheia(int topo){
    return topo == MAXPILHA -1;
}

int vazia(int topo){
    return topo == -1;
}
void desenho(int num, int y, int x);

int exibe(TpDisco p1, TpDisco p2, TpDisco p3){
	int y = 3, x = 14;
	
	gotoxy(14,2);
	printf("P1");
	while( !vazia(p1.topo) )
	{
		desenho(retira(p1), y, x);
		x--;
		y+=2;
	}
	
	y = 3;
	x = 50;
	gotoxy(50,2);
	printf("P2");
	while( !vazia(p2.topo) )
	{
		desenho(retira(p2), y, x);
		x--;
		y+=2;
	}
	
	y = 3;
	x = 86;
	gotoxy(86,2);
	printf("P3");
	while( !vazia(p3.topo) )
	{
		desenho(retira(p3), y, x);

		x--;
		y+=2;
	}
	
		
}

void insere (TpDisco &p, int elem){
	p.disc[++p.topo] = elem;
}

