#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#define X 300
struct char00 {
  int hp;
  int dmg;
  int classe;
	int critchance;
	char classenome[X];
	char passive[X];
  char nome[X];
};
typedef struct char00 char00;
struct enemy00 {
    int hp;
    int dmg;
    char nome[X];
};
typedef struct enemy00 enemy;
struct bag {
    int potion = 0;
    int fenix = 0;
};
typedef struct bag bag;
void header(char00* c){
    char* asciiArt[] = {
        "  _____ _____ _      _               _____   _____    ____  ______    _____ _____  ______       _______ _____ ____  _   _",
        " |  __ \\_   _| |    | |        /\\   |  __ \\ / ____|  / __ \\|  ____|  / ____|  __ \\|  ____|   /\\|__   __|_   _/ __ \\| \\ | |",
        " | |__) || | | |    | |       /  \\  | |__) | (___   | |  | | |__    | |    | |__) | |__     /  \\  | |    | || |  | |  \\| |",
        " |  ___/ | | | |    | |      / /\\ \\ |  _  / \\___ \\  | |  | |  __|   | |    |  _  /|  __|   / /\\ \\ | |    | || |  | | . ` |",
        " | |    _| |_| |____| |____ / ____ \\| | \\ \\ ____) | | |__| | |      | |____| | \\ \\| |____ / ____ \\ |   _| || |__| | |\\  |",
        " |_|   |_____|______|______/_/    \\_\\_|  \\_\\_____/   \\____/|_|       \\_____|_|  \\_\\______/_/    \\_\\_|  |_____|\\____/|_| \\_|"
    };
    int numLines = sizeof(asciiArt) / sizeof(asciiArt[0]);

    for (int i = 0; i < numLines; i++) {
        printf("     %s\n", asciiArt[i]);
    }
	printf("\n                                               Pressione qualquer tecla para iniciar o jogo");
	while (!kbhit()){
  }
  getch();
	system("cls");
	printf("Digite o nome do seu personagem: ");
	scanf("%[^\n]",c->nome);
}
void victory(){
	printf("|----------------------------------------|\n");
	printf(" Parabens, você chegou ao final do jogo.\n");
	printf("|----------------------------------------|\n");
}
void statusP(char00* c, enemy* e){
    printf("|---TURNO----------------------------|\n");
    printf(" Jogador: %s\n", c->nome);
		printf(" Vida: %d\n", c->hp);
    printf("\n");
    printf(" Inimigo: %s\n", e->nome);
    printf(" Vida: %d\n", e->hp);
}
int action(){
    int x;
    printf("\n");
    printf(" [1] - ATACAR\n");
    printf(" [2] - BOLSA DE ITENS\n");
    printf("\n|------------------------------------|\n");
		printf("\n Selecione uma ação: ");
		scanf("%d", &x);
    fflush(stdin);
    return x;
}
void resul(char00* c, enemy* e){
    if (c->hp <= 0) {
				system("color 4");
				printf("|---------------------|\n");
				printf("  VOCÊ FOI DERROTADO\n");
				printf("|---------------------|\n");
        Sleep(3000);
        exit;
    } else if (e->hp <= 0) {
        system("color 1");
				printf("|------------------|\n");
				printf(" INIMIGO DERROTADO\n");
				printf("|------------------|\n");
        Sleep(3000);
        system("cls");
    }
}
void status(char00* c) {
    if (c->classe == 1) {
        c->hp = 750;
        c->dmg = 275;
        c->critchance = 0;
        strcpy(c->classenome, "Guerreiro");
    } else if (c->classe == 2) {
        c->hp = 450;
        c->dmg = 170;
        c->critchance = 50;
        strcpy(c->classenome, "Arqueiro");
    } else if (c->classe == 3) {
        c->hp = 400;
        c->dmg = 150;
        c->critchance = 70;
      	strcpy(c->classenome, "Assassino");
    } else if (c->classe == 4) {
        c->hp = 385;
        c->dmg = 300;
				c->critchance = 20;	
				strcpy(c->classenome, "Mago");		
    } else if (c->classe == 5) {
        c->hp = 320;
        c->dmg = 225;
        c->critchance = 30;
        strcpy(c->classenome, "Sacerdote");
    }
}
void desc (char00* c){
	switch(c->classe){
		case 1:
			strcpy(c->passive, " Passiva - Força Bruta.\n O jogador n�o tem a possibilidade de causar dano critico.\n Mas é recompensado com alto número de pontos de vida e dano.\n");
			printf("%s", c->passive);
			break;
		case 2:
			strcpy(c->passive, " Passiva - Força da Natureza.\n Devido a sua liga��o com a natureza\n possui uma número maior de pontos de vida.\n");
			printf("%s", c->passive);
			break;
		case 3:
			strcpy(c->passive, " Passiva - Ataque surpresa\n Devido ao seu estilo de combate\n possui um baixo n�mero de pontos de vida.\n");
			printf("%s", c->passive);
			break;
		case 4:
			strcpy(c->passive, " Passiva - Poder Arcano.\n Devido ao seu controle de magia\n possui um dano elevado em troca de\n um número baixo de pontos de vida.\n");
			printf("%s", c->passive);
			break;
		case 5:
			strcpy(c->passive, " Passiva - Benção Divina.\n Atraves da sua liga��o com a luz\n possui regeneração de pontos de vida constante a cada round.\n");
			printf("%s", c->passive);
			break;
	}
}
void classes(char00* c){
	int resp = 0;
	do{
		system("cls");
    printf("|---CLASSES----------|\n");
		printf(" [1]Guerreiro\n");
    printf(" [2]Arqueiro\n");
    printf(" [3]Assassino\n");
    printf(" [4]Mago\n");
    printf(" [5]Sacerdote\n");
		printf("|--------------------|\n");
		printf("\nEscolha a sua classe: ");
    scanf("%d", &c->classe);
    status(c);
		system("cls");
		printf("|---ATRIBUTOS-----------------------------------------------|\n");
		printf(" Nome - %s\n",c->nome);
		printf(" Classe - %s\n", c->classenome);
		printf(" Pontos de vida - %d\n", c->hp);
		printf(" Dano - %d\n", c->dmg);
		printf(" Chance Critica - %d%%\n",c->critchance);
		desc(c);
		printf("|-----------------------------------------------------------|\n");
		printf("\nDeseja realmente escolher esta classe?\n");
		printf("[1] - SIM | [2] N�O: ");
		scanf("%d", &resp);
		
	} while (resp != 1);
}
void inimigo_1(enemy* e){
    e->hp = 500;
    e->dmg = 35;
    strcpy(e->nome,"Goblin");
}
void inimigo_2(enemy* e){
    e->hp = 750;
    e->dmg = 80;
   	strcpy(e->nome,"Tenente Orc");  	
}
void inimigo_3(enemy* e){
    e->hp = 1800;
    e->dmg = 100;
    strcpy(e->nome,"General de Elite Lilith");
}
void cura(char00* c, bag* b, int maxHP, int *acaoBemSucedida,enemy* e){
	int x, opc,escolha,emaxhp;
  printf("|---BOLSA DE ITENS-------------|\n");
  if (b->potion > 0){
		printf("[1] Po��o\n");	
	}
	if (b->fenix > 0){
		printf("[2] Fenix Dawn\n");	
	}
	if (b->fenix == 0 && b->potion == 0){
		printf(" Bolsa de itens vazia\n");
		printf("|------------------------------|\n");
		opc = 3;
	}
	if (b->fenix > 0 || b->potion > 0){
	  printf("|------------------------------|\n");
		printf("Qual item de cura deseja usar?\n");
		printf(" ");
	  scanf("%d", &opc);
	  system("cls");
	}
    switch (opc) {
        case 1:
            system("cls");
            if (b->potion == 0) {
                printf("Voc� n�o tem nenhum item de cura no momento.\n");
                Sleep(3000);
                system("cls");
            } else if (c->hp < maxHP) {
                printf("PO��ES - %d.\n", b->potion);
                printf("Quantos deseja usar agora?: ");
                scanf("%d", &x);
                int healAmount = x * 85;
                b->potion = b->potion - x;
                int remainingHeal = maxHP - c->hp;
                if (healAmount > remainingHeal) {
                    healAmount = remainingHeal;
                }
                c->hp += healAmount;
                system("color 2");
								printf("|--------------------------|\n");
								printf("  Sua vida foi restaurada!\n");
                printf("  Sua vida agora � de %d .\n", c->hp);
								printf("|--------------------------|\n");
								Sleep(3000);
                *acaoBemSucedida = 1;
                system("cls");
            } else if (c->hp == maxHP) {
                printf("Voc� j� tem o maximo de vida.");
                Sleep(3000);
                system("cls");
            }
            break;
        case 2:
            system("cls");
            if (b->fenix == 0) {
                printf("Voc� n�o tem nenhuma F�nix Dawn no momento.");
                Sleep(2000);
                *acaoBemSucedida = 1;
                system("cls");
            } else if (c->hp > 0 && c->hp <= maxHP) {
                printf("Onde voc� deseja usar o item?\n");
                printf("[1] - Si mesmo\n");
                printf("[2] - Inimigo\n");
                printf(" ");
                scanf("%d", &escolha);
                system("cls");
                if (escolha == 1 && c->hp < maxHP) {
                    system("color 2");
										printf("|---------------------------------|\n");
										printf(" Sua vida foi restaurada ao maximo\n");
                    printf(" Sua vida agora � de %d.\n", maxHP);
                    printf("|---------------------------------|\n");
										c->hp = maxHP;
                    b->fenix = b->fenix - 1; 
										Sleep(3000); 
                    *acaoBemSucedida = 1;
                } else if (escolha == 1 && c->hp == maxHP) {
                		printf("Voc� j� possui o maximo de pontos de vida.");
                		Sleep(3000);
            		} else if (escolha == 2 && c->hp > 0) {
                    e -> hp -= e -> hp;
              	}
            }
            break;
          case 3:
						printf("Presione qualquer tecla para voltar ao jogo\n");
    				while (!kbhit()) {
    				}
    				getch();
          	break;
        default:
            printf("Op��o inv�lida.");
            Sleep(2000);
            break;
    }
    if (!acaoBemSucedida) {
        printf("Voc� n�o pode executar essa a��o agora.\n");
        Sleep(2000);
    }
}
void dmg(enemy* e, char00* c, int *acaoBemSucedida){
	srand(time(NULL));	
	float roll = rand() % 100 + 1; 	
	if (c->critchance >=  100 - roll ){
		system("color 4");
		e->hp -= c->dmg*2;
		printf("|---JOGADOR------------------|\n");
		printf("        DANO CRITICO!\n");
		printf("    O seu dano foi dobrado\n");
		printf("   Voc� causou %d de dano.\n", c->dmg*2);
		printf("|----------------------------|\n");
		Sleep(3000);
		system("cls");
		*acaoBemSucedida = 1;
	} else if (c->critchance <=  100 - roll ){
		system("color 7");
		e->hp -= c->dmg;
		printf("|---JOGADOR--------------------------|\n");
		printf("  Voc� causou %d de dano no inimigo.\n", c->dmg);
		printf("|------------------------------------|\n");
		Sleep(3000);
		system("cls");
		*acaoBemSucedida = 1;	
	}
}
void enemydmg(enemy* e, char00* c, int *acaoBemSucedida){
	system("color 7");
	if (e->hp > 0 && *acaoBemSucedida == 1){
		c->hp -= e->dmg;
		printf("|---INIMIGO---------------------|\n");
		printf("   O inimigo causou %d de dano\n", e->dmg);
		printf("|-------------------------------|\n");
		Sleep(3000);
	} else if (e->hp > 0 && *acaoBemSucedida == 0){
		printf("|---A��O INVALIDA------------------------|\n");
		printf("   A��o n�o completa, continue o round.");
		printf("|----------------------------------------|\n");
	}
}
void liferegen(char00* c, int maxHP){
	if(c->classe == 5){
		int missinghealth = maxHP - c->hp;
  	int healAmount = 20;
		if (healAmount <= missinghealth) {
  		system("color 2");
			c->hp += 20;
  		printf("|---BEN��O DIVINA------------|\n");
			printf("  Voc� regenera 20 de vida\n");
			printf("|----------------------------|\n");
  		Sleep(3000);
  	}	
	}
}
void batalha(char00* c, enemy* e, bag* b){
		int opcao;
    int maxHP = c->hp;
		int acaoBemSucedida = 0;
		while (c->hp > 0 && e->hp > 0){
				system("color 7");
				statusP(c, e);
        opcao = action();
				acaoBemSucedida = 0;
        switch (opcao){
            case 1:
                system("cls");
								dmg(e, c, &acaoBemSucedida);
								acaoBemSucedida = 1;
                break;
            case 2:
                system("cls");
                cura(c, b, maxHP,&acaoBemSucedida,e);
                break;
            default:
                system("cls");
								printf("Op��o inv�lida.\n");
                Sleep(3000);
                break;
        }
    system("cls");
		enemydmg(e,c, &acaoBemSucedida);
    system("cls");
		liferegen(c, maxHP);
    system("cls");
    };
    resul(c, e);
}
void anuncio1(char00* c, enemy* e, bag* b){
	if(e -> hp <= 0 && c -> hp > 0){
	if (c -> classe == 4 || c-> classe == 5){
  	system("color 6");
		b -> potion += 2;
		printf("|-------------------SAQUE---------------------|\n");
		printf("| Voc� foi recompensado com 2 poções de cura! |\n");
		printf("|---------------------------------------------| \n");
	} else {
		b -> potion += 1;	
		system("color 6");
		printf("|-------------------SAQUE--------------------|\n");
		printf("| Voc� foi recompensado com 1 poção de cura! |\n");
		printf("|--------------------------------------------| \n");
	}
	Sleep(3000);
	system("cls");
	} else {
	batalha(c,e,b);
	} 
	system("color 7");
}
void anuncio2(char00* c, enemy* e, bag* b){
	if(e -> hp <= 0 && c -> hp > 0){
		system("color 6");
		printf("|-------------------SAQUE----------------------|\n");
		printf("   Voc� foi recompensado com 1 po��o de cura!\n");
		printf("   Voc� foi recompensado com 1 Phoenix Dawn !\n");
		printf("|----------------------------------------------| \n");
		b -> potion += 2;
		b -> fenix = 1;
		Sleep(3000);
		system("cls");	
	} else {
		batalha(c,e,b);	
	}
}
int main(){
  setlocale(LC_ALL,"Portuguese");	
	char00 personagem;
  enemy inimigo;
  bag bolsa;
	header(&personagem);
  classes(&personagem);
  inimigo_1(&inimigo);
  system("cls");
  batalha(&personagem, &inimigo, &bolsa);
  anuncio1(&personagem, &inimigo, &bolsa);
  system("cls");
  status(&personagem);
  inimigo_2(&inimigo);
  batalha(&personagem, &inimigo, &bolsa);
  anuncio2(&personagem,&inimigo, &bolsa);
  system("cls");
  status(&personagem);
	inimigo_3(&inimigo);
  batalha(&personagem, &inimigo, &bolsa);
  victory();
  return 0;
}
