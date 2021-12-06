#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct produto{
    int computador;
    int monitor;
    int teclado;
    int mouse;
    int roteador;
} Produto;

typedef struct cupons{
	int qnt_computador;
	int qnt_monitor;
	int qnt_teclado;
	int qnt_mouse;
	int qnt_roteador;
} Cupons;

typedef struct cliente{
    char nome[100];
    int telefone;
    long int cpf;
} Cliente;

//Faz o registro do cadastro de clientes.
void cadastro(Cliente P[]){
    setbuf(stdin,NULL);
    printf("Nome:\n");
    fgets(P->nome, 150, stdin);
    printf("Telefone:\n");
    scanf("%d", &P->telefone);
    printf("CPF:\n");
    scanf("%d", &P->cpf);
//Cria arquivo txt
    FILE *file;
//Abre o arquivo em modo de "alteração".
	file = fopen("informatica.txt", "a");
//Salva os dados recebidos acima no arquivo txt.
	fprintf(file,"Nome: %s Telefone: %d CPF: %d\n",P->nome, P->telefone, P->cpf);

	fclose(file);
}

//Exibe os registros de clientes que já foram cadastrados.
void mostraCliente(Cliente P[]){
//Abre o arquivo em modo de leitura (read)
     FILE *file = fopen("informatica.txt", "r");
//Realiza a leitura de cada caractere
     char c;
     c = fgetc(file);
//Enquanto não chegar no fim do arquivo, funcao termina de receber todos os caracteres
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(file);
    }

    fclose(file);
}

//Exibe estoque de produtos dependendo das vendas e reposicoes
void mostraEstoque(int *qtd_cpu, int *qtd_mon, int*qtd_tec, int *qtd_mou, int *qtd_rot){
    printf("--Computador -> %d Unidade(s)\n", *qtd_cpu);
	printf("--Monitor    -> %d Unidade(s)\n", *qtd_mon);
	printf("--Teclado    -> %d Unidade(s)\n", *qtd_tec);
	printf("--mouse      -> %d Unidade(s)\n", *qtd_mou);
	printf("--Roteador   -> %d Unidade(s)\n", *qtd_rot);
}

//Registra venda, subtrai na quantidade do estoque e soma na quantidade de vendas.
//Quando é a quantidade a ser comprada de um produto é superior a 10, exibe um aviso de estoque disponível
void registraVenda(Produto T[], Cupons, int *vendas, int *qtd_cpu, int *qtd_mon, int *qtd_tec, int *qtd_mou, int *qtd_rot, int *venda_cpu, int *venda_mon, int *venda_tec, int *venda_mou, int *venda_rot){
	int prod, qtd, preco, cpu=0, mon=0, tec=0, mou=0, rot=0;
    T->computador = 10;
    T->monitor    = 10;
    T->teclado    = 10;
    T->mouse      = 10;
    T->roteador   = 10;

	while (prod != 10){
	printf("\n1- Computador");
    printf("\n2- Monitor");
    printf("\n3- Teclado");
    printf("\n4- Mouse");
    printf("\n5- Roteador");
    printf("\n10- Sair\n");
    printf("\nPor favor, digite o número do produto.\n");
    printf("\nPara finalizar a venda, digite 10.\n");
    scanf("%d", &prod);

    qtd = 0;

    if(prod == 1){
        printf("\nPor favor, digite a quantidade.\n");
    	scanf("%d", &qtd);
    	if(qtd > *qtd_cpu){
    		printf("Estoque Insuficiente!\n");
		}	else{
				T->computador -= qtd;
		    	cpu = qtd;
		    	*qtd_cpu -= qtd;
		    	*venda_cpu = qtd;
		}
	}else
	if(prod == 2){
	    printf("\nPor favor, digite a quantidade.\n");
    	scanf("%d", &qtd);
    	if(qtd > *qtd_mon){
    		printf("Estoque Insuficiente!\n");
		}	else{
				T->monitor -= qtd;
		    	mon = qtd;
		    	*qtd_mon -= qtd;
		    	*venda_mon = qtd;
		}
	}else
	if(prod == 3){
	    printf("\nPor favor, digite a quantidade.\n");
    	scanf("%d", &qtd);
    	if(qtd > *qtd_tec){
    		printf("Estoque Insuficiente!\n");
		}	else{
				T->teclado -= qtd;
		    	tec = qtd;
		    	*qtd_tec -= qtd;
		    	*venda_tec = qtd;
		}
	}else
	if(prod == 4){
	    printf("\nPor favor, digite a quantidade.\n");
    	scanf("%d", &qtd);
    	if(qtd > *qtd_mou){
    		printf("Estoque Insuficiente!\n");
		}	else{
				T->mouse -= qtd;
		    	mou = qtd;
		    	*qtd_mou -= qtd;
		    	*venda_mou = qtd;
		}
	}else
	if(prod == 5){
	    printf("\nPor favor, digite a quantidade.\n");
    	scanf("%d", &qtd);
    	if(qtd > *qtd_rot){
    		printf("Estoque Insuficiente!\n");
		}	else{
				T->roteador -= qtd;
		    	rot = qtd;
		    	*qtd_rot -= qtd;
		    	*venda_rot = qtd;
		}
	}else if(prod > 5 && prod < 10){
		printf(" Produto Inválido! \n");
	}


	preco = cpu * 2000 + mon * 500 + tec * 300 + mou * 200 + rot * 50;

	}
	printf("\n-------------------------------\n");
	printf("Computador ->  QTD:%d   VALOR:%d \n", cpu, 2000 * cpu);
	printf("Monitor    ->  QTD:%d    VALOR:%d \n", mon, 500 * mon);
	printf("Teclado    ->  QTD:%d    VALOR:%d \n", tec, 300 * tec);
	printf("Mouse      ->  QTD:%d    VALOR:%d \n", mou, 200 * mou);
	printf("Roteador   ->  QTD:%d    VALOR:%d \n", rot, 50 * rot);
	printf("O valor total da compra é de R$: %d", preco);
	printf("\n-------------------------------\n");
	
	Cupom[]->qnt_computador = cpu;
	Cupom[]->qnt_monitor = mon;
	Cupom[]->qnt_teclado = tec;
	Cupom[]->qnt_mouse = mou;
	Cupom[]->qnt_roteador = rot;

	*vendas += 1;

}

//Exibe a quantidade de vendas realizadas
void quantidadeDeVendas(int *vendas){
	printf("\n-------------------------------\n");
	printf("\nNúmero de Vendas: %d\n", *vendas);
	printf("\n-------------------------------\n");
}

void vendasProdutos(int *venda_cpu, int *venda_mon, int *venda_tec, int *venda_mou, int *venda_rot){
	printf("--Computador -> %d--\n", *venda_cpu);
	printf("--Monitor    -> %d--\n", *venda_mon);
	printf("--Teclado    -> %d--\n", *venda_tec);
	printf("--Mouse      -> %d--\n", *venda_mou);
	printf("--Roteador   -> %d--\n", *venda_rot);
		
}

//Exibe os produtos disponiveis para venda e o preço dos produtos
void listaProdutos(){

	printf("--Computador -> R$2000,00--\n");
	printf("--Monitor    -> R$ 500,00--\n");
	printf("--Teclado    -> R$ 300,00--\n");
	printf("--Mouse      -> R$ 200,00--\n");
	printf("--Roteador   -> R$  50,00--\n");
}

void mostraCupom(Cupom){
	
}


//Repoe o estoque dos produtos acrescentando uma nova quantidade em Estoque
void reporEstoque(int *qtd_cpu, int *qtd_mon, int *qtd_tec, int *qtd_mou, int *qtd_rot){

	int i, j;

	printf("Oque você deseja Repor?\n");
	printf("\n1-Computador");
	printf("\n2-Monitor");
	printf("\n3-Teclado");
	printf("\n4-Mouse");
	printf("\n5-Roteador\n");

	scanf("%d", &i);

	if(i == 1){
		printf("Quantos computadores deseja adicionar ao estoque?\n");
		scanf("%d", &j);
		*qtd_cpu += j;
	}
	if(i == 2){
		printf("Quantos monitores deseja adicionar ao estoque?\n");
		scanf("%d", &j);
		*qtd_mon += j;
	}
	if(i == 3){
		printf("Quantos teclados deseja adicionar ao estoque?\n");
		scanf("%d", &j);
		*qtd_tec += j;
	}
	if(i == 4){
		printf("Quantos mouses deseja adicionar ao estoque?\n");
		scanf("%d", &j);
		*qtd_mou += j;
	}
	if(i == 5){
		printf("Quantos roteadores deseja adicionar ao estoque?\n");
		scanf("%d", &j);
		*qtd_rot += j;
	}
}



void menu(){
    setlocale(LC_ALL,"");
    int opcao;
    int vendas = 0;
    int qtd_cpu = 10, qtd_mon = 10, qtd_tec = 10, qtd_mou = 10, qtd_rot = 10;
    int venda_cpu = 0, venda_mon = 0, venda_tec = 0, venda_mou = 0, venda_rot = 0;
    int cupom [15];
    struct cliente P[30];
    struct produto T[5];

    while(1){
        printf("\nBem vindo ao Sistema de vendas da Informa1000");
        printf("\n1- Cadastrar Cliente");
        printf("\n2- Listar Clientes");
        printf("\n3- Exibir Estoque");
        printf("\n4- Registrar Venda");
        printf("\n5- Listar Produtos");
        printf("\n6- Exibir quantidade de vendas");
        printf("\n7- Repor Estoque");
        printf("\n8- Mostrar vendas");
        printf("\n9- Sair ");
        printf("\nDigite opção: ");
        scanf(" %d", &opcao);

        if(opcao == 1) cadastro(P);
        if(opcao == 2) mostraCliente(P);
        if(opcao == 3) mostraEstoque(&qtd_cpu, &qtd_mon, &qtd_tec, &qtd_mou, &qtd_rot);
        if(opcao == 4) registraVenda(T,Cupons, &vendas, &qtd_cpu, &qtd_mon, &qtd_tec, &qtd_mou, &qtd_rot, &venda_cpu, &venda_mon, &venda_tec, &venda_mou, &venda_rot);
        if(opcao == 5) listaProdutos();
        if(opcao == 6) quantidadeDeVendas(&vendas);
        if(opcao == 7) reporEstoque(&qtd_cpu, &qtd_mon, &qtd_tec, &qtd_mou, &qtd_rot);
        if(opcao == 8) vendasProdutos(&venda_cpu, &venda_mon, &venda_tec, &venda_mou, &venda_rot);
        if(opcao == 9) break;
    }
}


int main(){
    menu();
}
