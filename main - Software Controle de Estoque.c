#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "funcoes.h"


int main()
{
    const int COLUNA = 80;
    const int LINHA = 20;

    pintar(79);

    LimparTela();

     telaInicial();
     pintarTelas();

    loginMenu ();
    int op = 0;
    int topo;

    do {
    //limparTela();
    topo = 0;

    limparTela();
    logoTopo();

pularLinha();
     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);//3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
     printf("\t\t\t%c      GERENCIAMENTO DE ESTOQUE       %c\n",3002,3002);
     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);

    pularLinha();
    pularLinha();
    printf  ("\n\t1 -  PIZZAS");
    printf  ("\n\n\t2 -  BEBIDAS");
    printf  ("\n\n\t3 -  CONTROLE DE ESTOQUE");
    printf  ("\n\n\n\tDIGITE A OP%c%cO DESEJADA:\t\t\t\t\tSAIR [S/N]\n\n",128,199);//128,199
    LinhaIgual();
    printf("====");
    pularLinha();
    limparBuff();
    scanf   ("%c",&op);

    // Função abaixo para poder ultilizar tanto numeros quanto caracteres no switch case
        if (op == 49){// 49 == 1
            op = 1;
                }else if (op ==50){// 50 ==2
                    op = 2;
                        }else if (op ==51){ //51 ==3
                            op = 3;
                                }else if (op ==52){ //52==4
                                    op = 4;
                                        }else if (op == 83|| op == 115){ //83 == S e 115 == s
                                            op = 5;
                                                }else if (op == 78 || op == 110){ //78 == N e 110 == n
                                                    op = 6;
                                                    }else {


                                                        pularLinha();
                                                        printf("\t\t\t\tOpcao Invalida!!!\n");
                                                        pularLinha();
                                                        LinhaTraco();
                                                        printf("----");
                                                        printf ("\n");
                                                        pause();
                                                        topo = 1; //volta para o topo e exibe o menu de novo

                                                    }


        switch (op)
        {
            case 1:{//1 == 49
            MenuPizza();
            topo = 1;

            }break;
            case 2:{//2==50
            MenuBebidas();
            topo = 1;
            limparBuff();
            break;

            }break;
            case 3:{//3=51
            MenuProdutos();

            }break;
            case 4:{//4==52

            }break;
            case 5 :{
            limparTela();
            printfCenter("Programa finalizado!",LINHA);
            pularLinha();
            pause();
            exit(0);

            }break;
            case 6:{

            topo = 1;

            }break;

        }


 }while (op != 78 || op != 110);
    return 0;
}

void logoTopo(){
    printf("\n\n");
 printf(" @@@  @  @@@  @@@  @@@  @@@  @  @@@ \t@@@  @@@  @   @  @  @@@  @   @  @@@ \t@@@  @@@  @   @  @  @@@ @@@  @ @  @@@\n");
 printf(" @ @  @    @    @  @    @ @  @  @ @\t@    @ @  @@ @@  @  @    @   @  @ @ \t@ @  @ @  @@  @  @  @ @ @    @ @  @ @\n");
 printf(" @@@  @   @    @   @@@  @@@  @  @@@ \t@@@  @@@  @ @ @  @  @ @  @   @  @@@ \t@@@  @@@  @ @ @  @  @@@ @ @  @ @  @@@\n");
 printf(" @    @  @    @    @    @@   @  @ @ \t@    @ @  @   @  @  @ @  @   @  @ @ \t@    @ @  @  @@  @  @ @ @ @  @ @  @ @\n");
 printf(" @    @  @@@  @@@  @@@  @ @  @  @ @ \t@    @ @  @   @  @  @@@  @@@ @  @ @ \t@    @ @  @   @  @  @ @ @@@  @@@  @ @\n");
 printf("\n\n");
}
