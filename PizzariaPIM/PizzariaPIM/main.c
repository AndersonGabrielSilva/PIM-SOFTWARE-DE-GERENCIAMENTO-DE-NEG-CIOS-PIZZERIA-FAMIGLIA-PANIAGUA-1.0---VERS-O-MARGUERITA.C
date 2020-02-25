#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pizzaria.h"

typedef struct {//STRUCT DO TIPO PEDIDOS
         char CclienteP [50];
         long long int LLIcpfP;
         char CpizzasP[50];
         char CbebidasP [50];
         char CPromocapP [4];
         int  IpromocaoP;
         int  IqtdPizzasP;
         int  IqtdbebidasP;
         float FtotalP,FprecoPizzaP,FprecoBebidaP;
         float FvalordescontoP;
         int  IverificadorC;

    } PEDIDOS;
    PEDIDOS pedidosrela;

void RelatorioPedidos(){
    LimparTela();
    char nome[50];
    int quantidade;
    float preco;
    FILE *arq;
    FILE *arqRelat;

    arq = fopen("C:\\PizzariaPIM\\bin\\arquivos\\CadastroPedidos.dat","rb");


    if (arq == NULL&&arqRelat == NULL){

        fprintf (stderr, "Problemas na abertura do arquivo!\n");
        pause();
        return 1;

    } else{
            arqRelat = fopen("C:\\PizzariaPIM\\bin\\arquivos\\CadastroPedidos.csv","w");
            fclose(arqRelat);

            while (fread(&pedidosrela,sizeof(PEDIDOS),1,arq)==1){
                arqRelat = fopen("C:\\PizzariaPIM\\bin\\arquivos\\CadastroPedidos.csv","a");
                strcpy(nome, pedidosrela.CpizzasP);
                quantidade = pedidosrela.IqtdPizzasP;
                preco = pedidosrela.FprecoPizzaP;
                fprintf (arqRelat, "%d;%.2f;%s",quantidade,preco, nome);

        }
        fclose(arqRelat);
    }
        fclose(arq);
}
int main()
{

const int COLUNA = 80;
const int LINHA = 20;

     pintar(79);

        int op;
        limparTela();
        telaInicial();
        pintarTela();
        //loginMenu();


do {

        limparTela();
        logoTopo();
        pularLinha();

        printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);//3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
        printf("\t\t\t%c           MENU ATENDIMENTO          %c\n",3002,3002);
        printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);

        printf("\n\n");

        printf  ("\n\t 1 -  CADASTRO DE CLIENTES");
        printf  ("\n\n\t 2 -  PEDIDOS");
        printf  ("\n\n\t 3 -  AVALIACAO DO CLIENTE");
        printf  ("\n\n\nDIGITE A OPCAO DESEJADA:\t\t\t\t\tSAIR [S/N]\n");
        pularLinha();
        LinhaIgual();
        limparBuff();
        scanf   ("%c",&op);

//FUNÇÃO ABAIXO PARA PODER ULTILIZAR TANTO NUMEROS QUANTO CARACTERES NO SWITCH CASE
        if (op == 49){// 49 == 1
            op = 1;
                }else if (op ==50){// 50 ==2
                    op = 2;
                        }else if (op ==51){ //51 ==3
                            op = 3;
                                }else if (op == 83|| op == 115){ //83 == S e 115 == s
                                            op = 4;
                                                }else if (op == 78 || op == 110){ //78 == N e 110 == n
                                                    op= 5;
                                                    }else {

                                                        printfCenter ("Opcao Invalida", LINHA);
                                                        pularLinha();
                                                        LinhaTraco();
                                                        pularLinha();

                                                        pause();
                                                    }


        switch (op)
        {
            case 1:{//1 == 49
            MenuCliente();
            }break;
            case 2:{//2==50
            MenuPedidos();

            }break;
            case 3:{//3=51
            MenuAvaliacao();
            }break;
            case 4:{//4==52
            limparTela();
            RelatorioPedidos();
            printfCenter("Programa finalizado!",LINHA);
            pularLinha();
            getchar();
            pause();
            exit(0);

            }break;
            case 5 :{

            }break;
        }

}while (op != 78 || op != 110);
    return 0;
}
