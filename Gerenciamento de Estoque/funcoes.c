#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#define QTDPRODUTOS 150
#define QTDINGREDIENTES 80
#define TAM 100


const int COLUNA = 80;
const int LINHA = 20;

const char BLACK = 219;
const char WHITE = 32;
/*----------------------------------------------------------------------------------------------------------------------*/
 typedef struct {//STRUCT DO TIPO PIZZAS
        char CsaborC [50];//ARMAZENA O SABOR DA PIZZA
        float  FprecoC;// ARMAZENA O PREÇO DA PIZZA
        int  IverificadorC;//VERIFICA SE DEVE GRAVAR OU NAO NO ARQUIVO

    } PIZZAS;
    PIZZAS sabores;
/*----------------------------------------------------------------------------------------------------------------------*/
typedef struct {//STRUCT DO TIPO BEBIDAS
        char CbebidaC [50];//ARMAZENA O SABOR DA BEBIDA
        char CtipoC [50];//ARMAZENA O TIPO DA BEBIDA
        float  FprecoBebidaC;// ARMAZENA O PRECO DA BEBIDA
        int  IverificadorC;//VERIFICA SE DEVE OU NÃO GRAVAR NO ARQUIVO

    } BEBIDAS;
    BEBIDAS bebidas;
/*----------------------------------------------------------------------------------------------------------------------*/
 typedef struct PRODUTO{//
        char produto[51];
        float pesoKg;
    }PRODUTO;
    PRODUTO produto;
/*----------------------------------------------------------------------------------------------------------------------*/

//PARTE ESCRITA POR ANDERSON GABRIEL DA SILVA
void gravarArquivosSruct (PIZZAS nomeStruct){//GRAVA UMA STRUCT EM UM ARQUIVO
        FILE *arq;
        arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroPizzas.dat", "ab");
        if (arq == NULL){

            fprintf(stderr, "Problema na criacao do arquivo\n");
            pause();
            return 1;
        }

        fwrite(&nomeStruct, sizeof(PIZZAS), 1, arq);
        //fwrite(&sabores, sizeof(pizzas),1, arq)

        fclose(arq);


}
/*----------------------------------------------------------------------------------------------------------------------*/
void pesquisarArq (PIZZAS nomeStruct){// PESQUISA UMA STRUCT DENTRO DE UM ARQUIVO
 setlocale(LC_ALL,"Potuguese");
FILE *arq;
 char CpesquisarP [50];
 int senao = 0;
    arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroPizzas.dat","rb");
    if (arq == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{
    printf ("\nDigite o nome da Pizza: ");
    fgets(CpesquisarP,sizeof (CpesquisarP),stdin);
    strupr(CpesquisarP);
    fflush(stdin);

         while (fread(&sabores,sizeof(PIZZAS),1,arq)==1){

            if (strncmp(sabores.CsaborC,CpesquisarP,4)==0){
            senao=1;
            printf ("\nSabor : %s\n", sabores.CsaborC);
            printf ("Pre%co : %.2f\n",135, sabores.FprecoC);
            LinhaTraco();
            break;
            }
        }
        if (senao == 0){

            printf("\nProduto n%co encontrado",198);

            getchar();
        }

    }
     fclose(arq);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void listarArquivoStruct(PIZZAS nomeStruct){//LISTA AS PIZZAS DO ARQUIVO

    FILE *arq;
    arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroPizzas.dat","rb");
    if (arq == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{

        while (fread(&sabores,sizeof(PIZZAS),1,arq)==1){

            printf ("\nSabor : %s\n", sabores.CsaborC);
            printf ("Pre%co : %.2f\n",135, sabores.FprecoC);
            LinhaTraco();
        }
        }

    fclose(arq);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void removerArqStruct(PIZZAS nomeStruct){//REMOVE PIZZAS DO ARQUIVO
    FILE* arq;
    FILE* temp;
    char CpesquisarP [50];
    char op;
     arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroPizzas.dat","rb");
      temp = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario.dat","wb");
     limparBuff();
    if (arq == NULL&&temp == NULL){

        printf ("Problrmas na abertura do arquivo!\n");
    }else{
        printfCenter("\t =================| REMOVER PIZZAS  |=================  \n",COLUNA);
        pularLinha();
        pularLinha();

        printf ("\nDigite o nome da Pizza: ");
        fgets(CpesquisarP,sizeof (CpesquisarP),stdin);
        strupr(CpesquisarP);
        limparBuff();

        while (fread(&sabores,sizeof(PIZZAS),1,arq)==1){

            if (strncmp(sabores.CsaborC,CpesquisarP,4)==0){

            printf ("\nSabor : %s\n", sabores.CsaborC);
            printf ("Pre%co : %.2f\n",135, sabores.FprecoC);
            LinhaTraco();

            limparBuff();
            printf ("\n Deseja remover ? [S/N]");
            scanf("%c", &op);
            limparBuff();

            }else{

            fwrite(&sabores,sizeof(PIZZAS),1,temp);//gravando os dados no arquivo temp
            }
            }
           fclose(arq);//fechar o arq
           fclose(temp);//fechar o temp
                if (op == 's'){
                    remove("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroPizzas.dat");
                    rename("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario.dat","C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroPizzas.dat");

                    LinhaTraco();
                    printf   ("\nProduto Removido\n");
                    LinhaTraco();
                    pularLinha();

                }else {
                    remove("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario.dat");
                }
}
}
/*----------------------------------------------------------------------------------------------------------------------*/
void editarArqStruct (PIZZAS nomeStruct){//EDITA PIZZAS NO ARQUIVO

    FILE* arq;
    FILE* temp;
    char CpesquisarP [50];
    char opc;
    char novoSabor [50];
    float novoPreco;
    char op;
     arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroPizzas.dat","rb");
     temp = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario.dat","wb");
    if (arq == NULL&&temp == NULL){

        printf ("Problrmas na abertura do arquivo!\n");
    }else{

        printf ("\nDigite o nome da Pizza: ");
        fgets(CpesquisarP,sizeof (CpesquisarP),stdin);
        strupr(CpesquisarP);
        fflush(stdin);

        while (fread(&sabores,sizeof(PIZZAS),1,arq)==1){

            if (strncmp(sabores.CsaborC,CpesquisarP,4)==0){

            printf ("\nSabor : %s\n", sabores.CsaborC);
            printf ("Pre%co : %.2f\n",135, sabores.FprecoC);
            LinhaTraco();
            pularLinha();

             do{
        printf ("\n1 - Alterar somente o sabor");
        printf ("\n2 - Alterar somente o pre%co",135);
        printf ("\n3 - Alterar sabor e pre%co",135);
        printf ("\n4 - Sair");

        printf ("\nEscolha a op%c%co desejada: ",135,198);
        scanf  ("%d",&opc);
        limparBuff();

            switch (opc){
            case 1:{
               printf ("\nDigite o novo sabor: ");
               fgets(novoSabor,sizeof(novoSabor),stdin);
               strupr(novoSabor);
               limparBuff();
               strcpy (sabores.CsaborC,novoSabor);
                opc = 1;
                printf("\nAlterado com sucesso");
               getchar();
              // remove(endereco);
               //rename("bin\\arquivo\\temporario.dat", endereco);
            }break;
            case 2:{
                 printf ("\nDigite o novo valor: ");
                 scanf  ("%f",&novoPreco);
                 limparBuff();

                 sabores.FprecoC = novoPreco;
                 opc = 1;
                printf("\nAlterado com sucesso");
                getchar();

            }break;
            case 3:{
                printf ("\nDigite o novo sabor: ");
                fgets(novoSabor,sizeof(novoSabor),stdin);
                strupr(novoSabor);
                limparBuff();
                printf ("\nDigite o novo valor: ");
                 scanf  ("%f",&novoPreco);
                 limparBuff();
                strcpy (sabores.CsaborC,novoSabor);
                sabores.FprecoC = novoPreco;
                opc=1;
                printf("\nAlterado com sucesso");
                getchar();

            }break;
            case 4: {
                opc = 1;
            }break;
            default: {
                printf ("\nOp%c%co inv%clida!",135,198,160);
                opc = 0;
                getchar();
            }
            }

    }while (opc!=1);

            fwrite(&sabores,sizeof(PIZZAS),1,temp);

            }else{

            fwrite(&sabores,sizeof(PIZZAS),1,temp);//gravando os dados no arquivo temp
            }

            }
           fclose(arq);//fechar o arq
           fclose(temp);//fechar o temp
          //printf ("\n Deseja remover ? [S/N]");
          op = 's';
           //scanf("%c", &op);
                if (op == 's'){
                    remove("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroPizzas.dat");
                    rename("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario.dat", "C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroPizzas.dat");
                }else {
                    remove("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario.dat");
                }



}
}
/*----------------------------------------------------------------------------------------------------------------------*/

//PARTE ESCRITA POR LUCAS SOUZA
void gravarArquivosStructBebidas (BEBIDAS nomeStruct){//GRAVAR ARQUIVO BEBIDAS
        FILE *arq;
        arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroBebidas.dat", "ab");
        if (arq == NULL){

            fprintf(stderr, "Problema na criacao do arquivo\n");
            pause();
            return 1;
        }

        fwrite(&nomeStruct, sizeof(BEBIDAS), 1, arq);

        fclose(arq);


}
/*----------------------------------------------------------------------------------------------------------------------*/
void pesquisarArqBebidas (BEBIDAS nomeStruct){//PESQUISAR ARQUIVO BEBIDAS
 setlocale(LC_ALL,"Potuguese");
FILE *arq;
 char CpesquisarP [50];
 int senao = 0;
    arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroBebidas.dat","rb");
    if (arq == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{
    printf ("\nDigite o nome da Bebida: ");
    fgets(CpesquisarP,sizeof (CpesquisarP),stdin);
    strupr(CpesquisarP);
    fflush(stdin);

         while (fread(&bebidas,sizeof(BEBIDAS),1,arq)==1){

            if (strncmp(bebidas.CbebidaC,CpesquisarP,4)==0){
            senao=1;
            printf ("\nBebida : %s\n", bebidas.CbebidaC);
            printf ("Pre%co : %.2f\n",135, bebidas.FprecoBebidaC);
            LinhaTraco();

            }
        }
        if (senao == 0){

            printf("\nProduto n%co encontrado",198);

            getchar();
        }

    }
     fclose(arq);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void listarArquivoStructBebidas(BEBIDAS nomeStruct){//LISTAR ARQUIVO BEBIDAS

    FILE *arq;
    arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroBebidas.dat","rb");
    if (arq == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{

        while (fread(&bebidas,sizeof(BEBIDAS),1,arq)==1){
            printf ("\nTipo : %s", bebidas.CtipoC);
            printf ("\nBebida : %s\n", bebidas.CbebidaC);
            printf ("Pre%co : %.2f\n",135, bebidas.FprecoBebidaC);
            LinhaTraco();
        }
        }

    fclose(arq);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void removerArqStructBebidas(BEBIDAS nomeStruct){//REMOVER ARQUIVO BEBIDAS
    FILE* arq;
    FILE* temp;
    char CpesquisarP [50];
    char op;
    int encontrou = 0;
     arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\\CadastroBebidas.dat","rb");
      temp = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario1.dat","wb");
     limparBuff();
    if (arq == NULL&&temp == NULL){

        printf ("Problrmas na abertura do arquivo!\n");
    }else{
        printfCenter("\t =================| REMOVER BEBIDAS  |=================  \n",COLUNA);
        pularLinha();
        pularLinha();


        printf ("\nDigite o nome da Bebida: ");
        fgets(CpesquisarP,sizeof (CpesquisarP),stdin);
        strupr(CpesquisarP);
        limparBuff();

        while (fread(&bebidas,sizeof(BEBIDAS),1,arq)==1){

            if (strncmp(bebidas.CbebidaC,CpesquisarP,4)==0){

            printf ("\nBebida : %s\n", bebidas.CbebidaC);
            printf ("Pre%co : %.2f\n",135, bebidas.FprecoBebidaC);
            LinhaTraco();
            encontrou = 111;
            }else{

            fwrite(&bebidas,sizeof(BEBIDAS),1,temp);//gravando os dados no arquivo temp
            }
            }
           fclose(arq);//fechar o arq
           fclose(temp);//fechar o temp
           if (encontrou==111){
           printf ("\n Deseja remover ? [S/N]");
           scanf("%c", &op);
           limparBuff();

                if (op == 's'){
                    remove("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroBebidas.dat");
                    rename("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario1.dat", "C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroBebidas.dat");

                    LinhaTraco();
                    printf   ("\nProduto Removido\n");
                    LinhaTraco();
                    pularLinha();
                }else {
                    remove(("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario1.dat"));
                }
           }
}
}
/*----------------------------------------------------------------------------------------------------------------------*/
void editarArqStructBebidas (BEBIDAS nomeStruct){//EDITAR ARQUIVO BEBIDAS

    FILE* arq;
    FILE* temp;
    char CpesquisarP [50];
    char opc;
    char novaBebida [50];
    float novoPreco;
    char op;
     arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroBebidas.dat","rb");
     temp = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario1.dat","wb");
    if (arq == NULL&&temp == NULL){

        printf ("Problrmas na abertura do arquivo!\n");
    }else{

        printf ("\nDigite o nome da Bebida: ");
        fgets(CpesquisarP,sizeof (CpesquisarP),stdin);
        strupr(CpesquisarP);
        fflush(stdin);

        while (fread(&bebidas,sizeof(BEBIDAS),1,arq)==1){

            if (strncmp(bebidas.CbebidaC,CpesquisarP,4)==0){

            printf ("\nBebida : %s\n", bebidas.CbebidaC);
            printf ("Pre%co : %.2f\n",135, bebidas.FprecoBebidaC);
            LinhaTraco();
            pularLinha();

             do{
        printf ("\n1 - Alterar somente nome");
        printf ("\n2 - Alterar somente o pre%co",135);
        printf ("\n3 - Alterar nome e pre%co",135);
        printf ("\n4 - Sair");

        printf ("\nEscolha a op%c%co desejada: ",135,198);
        scanf  ("%d",&opc);
        limparBuff();

            switch (opc){
            case 1:{
               printf ("\nDigite a nova Bebida: ");
               fgets(novaBebida,sizeof(novaBebida),stdin);
               strupr(novaBebida);
               limparBuff();
               strcpy (bebidas.CbebidaC,novaBebida);
                opc = 1;
                printf("\nAlterado com sucesso");
               getchar();
            }break;
            case 2:{
                 printf ("\nDigite o novo valor: ");
                 scanf  ("%f",&novoPreco);
                 limparBuff();

                 bebidas.FprecoBebidaC = novoPreco;
                 opc = 1;
                printf("\nAlterado com sucesso");
                getchar();

            }break;
            case 3:{
                printf ("\nDigite o novo nome: ");
                fgets(novaBebida,sizeof(novaBebida),stdin);
                strupr(novaBebida);
                limparBuff();
                printf ("\nDigite o novo valor: ");
                 scanf  ("%f",&novoPreco);
                 limparBuff();
                strcpy (bebidas.CbebidaC,novaBebida);
                bebidas.FprecoBebidaC = novoPreco;
                opc=1;
                printf("\nAlterado com sucesso");
                getchar();

            }break;
            case 4: {
                opc = 1;
            }break;
            default: {
                printf ("\nOp%c%co inv%clida!",135,198,160);
                opc = 0;
                getchar();
            }
            }

    }while (opc!=1);

            fwrite(&bebidas,sizeof(BEBIDAS),1,temp);

            }else{

            fwrite(&bebidas,sizeof(BEBIDAS),1,temp);//gravando os dados no arquivo temp
            }

            }
           fclose(arq);//fechar o arq
           fclose(temp);//fechar o temp
          op = 's';
                if (op == 's'){
                    remove("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroBebidas.dat");
                    rename("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario1.dat", "C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroBebidas.dat");
                }else {
                    remove("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario1.dat");
                }



}
}
/*----------------------------------------------------------------------------------------------------------------------*/

//PARTE ESCRITA POR ANDERSON GABRIEL DA SILVA
void gravarArquivosSructProdutos (PRODUTO nomeStruct){//GRAVA UMA STRUCT EM UM ARQUIVO
        FILE *arq;
        arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroProdutos.dat", "ab");
        if (arq == NULL){

            fprintf(stderr, "Problema na criacao do arquivo\n");
            pause();
            return 1;
        }

        fwrite(&nomeStruct, sizeof(PRODUTO), 1, arq);
        fclose(arq);


}
/*----------------------------------------------------------------------------------------------------------------------*/
void pesquisarArqProdutos (PRODUTO nomeStruct){// PESQUISA UMA STRUCT DENTRO DE UM ARQUIVO
 setlocale(LC_ALL,"Potuguese");
FILE *arq;
 char CpesquisarP [50];
 int senao = 0;
    arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroProdutos.dat","rb");
    if (arq == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{
    limparBuff();
    printf ("\nDigite do Produto: ");
    fgets(CpesquisarP,sizeof (CpesquisarP),stdin);
    strupr(CpesquisarP);
    fflush(stdin);

         while (fread(&produto,sizeof(PRODUTO),1,arq)==1){

            if (strncmp(produto.produto,CpesquisarP,4)==0){
            senao=1;
            printf ("\nMateria Prima : %s\n", produto.produto);
            printf ("\nQuantidade em estoque Kg: %.2f\n",produto.pesoKg);
            LinhaTraco();
            pularLinha();
            break;
            }
        }
        if (senao == 0){

            printf("\nProduto n%co encontrado",198);

            getchar();
        }

    }
     fclose(arq);
     pause();
}
/*----------------------------------------------------------------------------------------------------------------------*/
void listarArquivoStructProdutos(PRODUTO nomeStruct){//LISTA AS PIZZAS DO ARQUIVO

    FILE *arq;
    arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroProdutos.dat","rb");
    if (arq == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{

        while (fread(&produto,sizeof(PRODUTO),1,arq)==1){

            printf ("\nMateria Prima : %s\n", produto.produto);
            printf ("\nQuantidade em estoque Kg: %.2f\n", produto.pesoKg);
            LinhaTraco();
        }
        }

    fclose(arq);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void removerArqStructProdutos(PRODUTO nomeStruct){//REMOVE PIZZAS DO ARQUIVO
    FILE* arq;
    FILE* temp;
    char CpesquisarP [50];
    char op;
     arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroProdutos.dat","rb");
      temp = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario.dat","wb");
     limparBuff();
    if (arq == NULL&&temp == NULL){

        printf ("Problrmas na abertura do arquivo!\n");
    }else{
        printfCenter("\t =================| REMOVER PRODUTOS  |=================  \n",COLUNA);
        pularLinha();
        pularLinha();

        limparBuff();
        printf ("\nDigite do produto: ");
        fgets(CpesquisarP,sizeof (CpesquisarP),stdin);
        strupr(CpesquisarP);

        while (fread(&produto,sizeof(PRODUTO),1,arq)==1){

            if (strncmp(produto.produto,CpesquisarP,4)==0){

            printf ("\nMateria Prima : %s\n", produto.produto);
            printf ("\nQuantidade em estoque Kg %.2f\n",produto.pesoKg);
            LinhaTraco();

            printf ("\n Deseja remover ? [S/N]");
            limparBuff();
            scanf("%c", &op);
            }else{

            fwrite(&produto,sizeof(PRODUTO),1,temp);//gravando os dados no arquivo temp
            }
            }
           fclose(arq);//fechar o arq
           fclose(temp);//fechar o temp

                if (op == 's'){
                    remove("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroProdutos.dat");
                    rename("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario.dat","C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroProdutos.dat");

                    LinhaTraco();
                    printf   ("\nProduto Removido\n");
                    LinhaTraco();
                    pularLinha();
                }else {
                    remove("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario.dat");
                }
}
}
/*----------------------------------------------------------------------------------------------------------------------*/
void editarArqStructProdutos (PRODUTO nomeStruct){//EDITA PIZZAS NO ARQUIVO

    FILE* arq;
    FILE* temp;
    char CpesquisarP [50];
    char opc;
    char novoNome [50];
    float novoPeso;
    char op;
     arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroProdutos.dat","rb");
     temp = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario.dat","wb");
    if (arq == NULL&&temp == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{
        limparBuff();
        printf ("\nDigite do produto: ");
        fgets(CpesquisarP,sizeof (CpesquisarP),stdin);
        strupr(CpesquisarP);
        fflush(stdin);

        while (fread(&produto,sizeof(PRODUTO),1,arq)==1){

            if (strncmp(produto.produto,CpesquisarP,4)==0){

           printf ("\nMateria Prima : %s\n", produto.produto);
            printf ("\nQuantidade em estoque Kg : %.2f\n",produto.pesoKg);
            LinhaTraco();
            pularLinha();

             do{
        printf ("\n1 - Alterar somente o Nome");
        printf ("\n2 - Alterar somente o quantidade (Kg)",135);
        printf ("\n3 - Alterar Nome e quantidade (Kg)",135);
        printf ("\n4 - Sair");

        printf ("\nEscolha a op%c%co desejada: ",135,198);
        scanf  ("%d",&opc);
        limparBuff();

            switch (opc){
            case 1:{
               printf ("\nDigite o novo nome: ");
               fgets(novoNome,sizeof(novoNome),stdin);
               strupr(novoNome);
               limparBuff();
               strcpy (produto.produto,novoNome);
                opc = 1;
                printf("\nAlterado com sucesso");
               getchar();
            }break;
            case 2:{
                 printf ("\nDigite a nova quantidade KG: ");
                 scanf  ("%f",&novoPeso);
                 limparBuff();
                 produto.pesoKg = novoPeso;
                 opc = 1;
                printf("\nAlterado com sucesso");
                getchar();

            }break;
            case 3:{
                printf ("\nDigite o nome: ");
                fgets(novoNome,sizeof(novoNome),stdin);
                strupr(novoNome);
                limparBuff();
                printf ("\nDigite a nova quantidade: ");
                 scanf  ("%f",&novoPeso);
                 limparBuff();
                strcpy (produto.produto,novoNome);
                produto.pesoKg = novoPeso;
                opc=1;
                printf("\nAlterado com sucesso");
                getchar();

            }break;
            case 4: {
                opc = 1;
            }break;
            default: {
                printf ("\nOp%c%co inv%clida!",135,198,160);
                opc = 0;
                getchar();
            }
            }
    }while (opc!=1);

            fwrite(&produto,sizeof(PRODUTO),1,temp);

            }else{

            fwrite(&produto,sizeof(PRODUTO),1,temp);//gravando os dados no arquivo temp
            }

            }
           fclose(arq);//fechar o arq
           fclose(temp);//fechar o temp
          op = 's';
                if (op == 's'){
                    remove("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroProdutos.dat");
                    rename("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario.dat", "C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroProdutos.dat");
                }else {
                    remove("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario.dat");
                }



}
}
/*----------------------------------------------------------------------------------------------------------------------*/
void SaldoArqStructProdutos (PRODUTO nomeStruct){//EDITA PIZZAS NO ARQUIVO

    FILE* arq;
    FILE* temp;
    char CpesquisarP [50];
    char opc;
    float FqtdPesoS;
    float FnovoSaldo;
    char op;
     arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroProdutos.dat","rb");
     temp = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario.dat","wb");
    if (arq == NULL&&temp == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{
        limparBuff();
        printf ("\nDigite do produto: ");
        fgets(CpesquisarP,sizeof (CpesquisarP),stdin);
        strupr(CpesquisarP);
        fflush(stdin);

        while (fread(&produto,sizeof(PRODUTO),1,arq)==1){

            if (strncmp(produto.produto,CpesquisarP,4)==0){

           printf ("\nMateria Prima : %s\n", produto.produto);
            printf ("\nQuantidade em estoque Kg %.2f\n",produto.pesoKg);
            LinhaTraco();
            pularLinha();

             do{
        printf ("\n1 - Debitar Saldo do Estoque");
        printf ("\n2 - Acrescentar Saldo ao Estoque");
        printf ("\n3 - Sair");

        printf ("\nEscolha a op%c%co desejada: ",135,198);
        scanf  ("%d",&opc);
        limparBuff();

            switch (opc){
            case 1:{//DEBITAR QUANTIDADE DO ESTOQUE MATERIA PRIMA
               printf ("\nDigite a quantidade ha ser debitada: ");
                 scanf  ("%f",&FqtdPesoS);
                 limparBuff();
                 produto.pesoKg =  produto.pesoKg - FqtdPesoS;
                 opc = 1;
                printf("\nAlterado com sucesso");
                getchar();
            }break;
            case 2:{//ACRESCENTAR AO ESTOQUE
                 printf ("\nDigite a quantidade ha ser acrescentada: ");
                 scanf  ("%f",&FqtdPesoS);
                 limparBuff();
                 produto.pesoKg =  produto.pesoKg + FqtdPesoS;
                 opc = 1;
                 printf("\nAlterado com sucesso");
                 getchar();


            }break;
            case 3:{
                 opc = 1;
            }
            default: {
                printf ("\nOp%c%co inv%clida!",135,198,160);
                opc = 0;
                getchar();
            }
            }

    }while (opc!=1);

            fwrite(&produto,sizeof(PRODUTO),1,temp);

            }else{

            fwrite(&produto,sizeof(PRODUTO),1,temp);//gravando os dados no arquivo temp
            }

            }
           fclose(arq);//fechar o arq
           fclose(temp);//fechar o temp
          op = 's';
                if (op == 's'){
                    remove("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroProdutos.dat");
                    rename("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario.dat", "C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroProdutos.dat");
                }else {
                    remove("C:\\Gerenciamento de Estoque\\bin\\arquivos\\temporario.dat");
                }



}
}
/*----------------------------------------------------------------------------------------------------------------------*/


//FUNÇÃO ESCRITA POR ANDERSON GABRIEL DA SILVA
void loginMenu (){//LOGIN DO SISTEMA
            limparTela();
            char CnomeLoginL [81]; //strcpy(CnomeLoginL , "secreto");
            char CnomeIseridoL [81];
            char CsenhaL [81];
            char CsenhainseridaL [81];
            int CmenuL;
            int senhaCorreta;
            int x=0;

    strcpy (CnomeLoginL , "GERENCIA@PANIAGUA.COM");
    strcpy (CsenhaL , "PANIAGUA");

       do {
     LimparTela();
     pularLinha();
     pularLinha();
     pularLinha();

     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
     printf("\t\t\t%c                LOGIN                %c\n",3002,3002);
     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);

        pularLinha();
        pularLinha();
        printf ("\n\n\tLogin :");
        caixaDados(30);
        gotoxy(15,9);
        scanf ("%80s", &CnomeIseridoL);
        strupr(CnomeIseridoL);
        limparBuff();
        pularLinha();
        printf ("\n\n\tSenha :");
        caixaDados(30);

        //scanf ("%80s", &CsenhainseridaL);


        limparBuff();
        gotoxy(15,13);
        int sair =0;
        do{

        CsenhainseridaL[x] = getch();
        limparBuff();
        if (CsenhainseridaL[x]!= '\r'){

                printf ("*");
                x++;
                sair = 0;
                    }else{
                        sair = 1;
                    }

        }while (sair != 1);
        CsenhainseridaL [x] = '\0';
        strupr(CsenhainseridaL);
        pularLinha();

        limparBuff();


        if (strcmp (CnomeLoginL, CnomeIseridoL)==0 && strcmp (CsenhaL, CsenhainseridaL)==0)
        {
             LimparTela();
            printfCenter ("\n Login efetuado com sucesso\n",LINHA);
            pularLinha();
            system("PAUSE");
            senhaCorreta = 1;
          break;

        }else {
            pularLinha();
            pularLinha();
            pularLinha();

             printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
             printf("\t\t\t%c   Senha Incorreta! Tente novamente  %c\n",3002,3002);
             printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);

            getchar();
            x=0;//resetar vetor da senha.
            senhaCorreta = 0;
        }


            limparBuff();

    }while (senhaCorreta!=1);


    }
/*----------------------------------------------------------------------------------------------------------------------*/

//FUNÇÃO ESCRITA POR LUCAS SOUZA
void logoInstenso(){//LOGO DO SOFTWARE

 printf("\n\n\n\n\n\n\n\n\n\n\n\n");
 printf(" @@@  @  @@@  @@@  @@@  @@@  @  @@@ \t@@@  @@@  @   @  @  @@@  @   @  @@@ \t@@@  @@@  @   @  @  @@@ @@@  @ @  @@@\n");
 printf(" @ @  @	@    @  @    @ @  @  @ @\t@    @ @  @@ @@  @  @    @   @  @ @ \t@ @  @ @  @@  @  @  @ @ @    @ @  @ @\n");
 printf(" @@@  @   @    @   @@@  @@@  @  @@@ \t@@@  @@@  @ @ @  @  @ @  @   @  @@@ \t@@@  @@@  @ @ @  @  @@@ @ @  @ @  @@@\n");
 printf(" @    @  @    @    @    @@   @  @ @ \t@    @ @  @   @  @  @ @  @   @  @ @ \t@    @ @  @  @@  @  @ @ @ @  @ @  @ @\n");
 printf(" @    @  @@@  @@@  @@@  @ @  @  @ @ \t@    @ @  @   @  @  @@@  @@@ @  @ @ \t@    @ @  @   @  @  @ @ @@@  @@@  @ @\n");
 printf("\n\n");


 printf("\n\n");
    getchar();
    LimparTela();
}
/*----------------------------------------------------------------------------------------------------------------------*/

//PARTE ESCRITA PELO ANDERSON GABRIEL DA SILVA
void MenuPizza (){//MENU DE GERENCIAMENTO DAS PIZZAS


        int menu;
        int op;
do {
        limparTela();
        pularLinha();
        pularLinha();
        pularLinha();

     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
     printf("\t\t\t%c                PIZZA                %c\n",3002,3002);
     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);

        printf ("\n\n\n\t 1 - CADASTRAR");
        pularLinha();
        printf ("\n\t 2 - EDITAR");
        pularLinha();
        printf ("\n\t 3 - LISTAR");
        pularLinha();
        printf ("\n\t 4 - REMOVER");
        pularLinha();
        printf ("\n\t 5 - PESQUISAR");
        pularLinha();
        printf ("\n\t 6 - FINALIZAR E VOLTAR AO MENU ANTERIOR: \n\n");
        LinhaIgual();
        pularLinha();
        scanf  ("%d",&op);

        switch (op){

            case 1:{
            getchar();
            cadastroPizza();
            op = 0;


            }break;
            case 2:{

            editarPizza();



            }break;
            case 3:{

           listarPizza();
            getchar();
            op = 4;


            }break;
            case 4:{

             removerPizza();


            }break;

            case 5:{

            pesquisarPizza();
            pularLinha();
            pause();

            }break;

            case 6:{

            }
}
    }while (op!=6);

}
/*----------------------------------------------------------------------------------------------------------------------*/
void cadastroPizza(){//CADASTRA NOVOS SABADORES DE PIZZAS


    int cancelar = 0;
    int x;
    char CsaborC [50];
    float  FprecoC;
    int op;//Ultilizado para o Switch case
    int menu;
    int sair;// Ultilizado no do while




    do {
        sair = 0;
        menu = 0;
        limparTela();
        cancelar = 0;
        printfCenter("\t =================| CADASTRO DE PIZZAS  |=================  \n",COLUNA);
        pularLinha();
        pularLinha();

        printf ("\nInsira o Sabor: ");
        fgets  (CsaborC,sizeof (CsaborC), stdin);
        strupr(CsaborC);
        limparBuff();

        printf ("\nInsira o Pre%co: ",135);
        scanf  ("%f", &FprecoC);

        strcpy(sabores.CsaborC, CsaborC);
                sabores.FprecoC = FprecoC;
                sabores.IverificadorC=1;


        getchar();
        printf ("\n1- Cancelar ");
        printf ("\n2- Corrigir ");
        printf ("\n3- Adicionar outra");
        printf ("\n4- Concluir e voltar ao menu anterior:\n");
        scanf  ("%d",&menu);
        limparBuff();

    switch (menu){

            case 1:{//CANCELAR

            sabores.IverificadorC = 0;
                   sair = 1;

            }break;
            case 2:{//CORRIGIR

            sabores.IverificadorC = 0;
                    sair = 0;

            }break;
            case 3:{//Adicionar outra Pizza
                gravarArquivosSruct(sabores);
            sair = 0;
            }break;

            case 4:{//Finalizar e Sair
            gravarArquivosSruct(sabores);
            sair = 1;

            }break;

    }
    }while (sair!=1);


}
/*----------------------------------------------------------------------------------------------------------------------*/
void removerPizza(){//REMOVE AS PIZZAS JÁ CADASTRADAS
loginMenu();
limparTela();
limparBuff();
removerArqStruct(sabores);
pause();
}
/*----------------------------------------------------------------------------------------------------------------------*/
void pesquisarPizza(){//PESQUISA AS PIZZAS JÁ CADASTRADAS
    setlocale(LC_ALL,"Potuguese");
    limparTela();
    getchar();
    char CpesquisarP [50];
    printfCenter("\t =================| PESQUISA DE PIZZAS  |=================  \n",COLUNA);
    pularLinha();
    pesquisarArq(sabores);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void listarPizza(){//LISTA AS PIZZAS CADASTRADAS
    limparTela();
    printfCenter("\t =================| PIZZAS CADASTRADAS  |=================  \n",COLUNA);
    printf ("\n\n");
    listarArquivoStruct(sabores);
getchar();

            }
/*----------------------------------------------------------------------------------------------------------------------*/
void editarPizza(){//EDITA AS PIZZAS JÁ CADASTRADAS

    limparTela();
    getchar();
    char CpesquisarE [50];
    char CEditarPizzaE [50];
    float FEditarPrecoE;
    int editar,op=0;
    printfCenter("\t =================| EDITAR PIZZAS  |=================  \n",COLUNA);
    pularLinha();

    editarArqStruct(sabores);

}//
/*----------------------------------------------------------------------------------------------------------------------*/
void limparTela (){//LIMPA A TELA
              system ("cls");

}
/*----------------------------------------------------------------------------------------------------------------------*/
void printfCenter(char *texto, int linha){//CENTRALIZA A FRASE
int coluna = (COLUNA / 2) - strlen(texto);
gotoxy(coluna, linha);
printf("%s", texto);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void pularLinha(){//PULA 1 LINHA
    printf ("\n");
}
/*----------------------------------------------------------------------------------------------------------------------*/
void limparBuff(){//LIMPA O BUFF DO TECLADO

    setbuf(stdin,NULL);

}
/*----------------------------------------------------------------------------------------------------------------------*/

//PARTE ESCRITA PELO LUCAS DE SOUZA
void MenuBebidas(){//MENU DE GERENCIAMENTO DE BEBIDAS


        int menu;
        int op;
do {
        limparTela();
        pintar(240);
        pularLinha();
        pularLinha();
        pularLinha();

     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
     printf("\t\t\t%c                BEBIDAS              %c\n",3002,3002);
     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);

        printf ("\n\n\n\t 1 - CADASTRAR");
        pularLinha();
        printf ("\n\t 2 - EDITAR");
        pularLinha();
        printf ("\n\t 3 - LISTAR");
        pularLinha();
        printf ("\n\t 4 - REMOVER");
        pularLinha();
        printf ("\n\t 5 - PESQUISAR");
        pularLinha();
        printf ("\n\t 6 - FINALIZAR E VOLTAR AO MENU ANTERIOR: \n\n");
        LinhaIgual();
        pularLinha();
        scanf  ("%d",&op);

        switch (op){

            case 1:{
            getchar();
            cadastroBebidas();
            op = 0;


            }break;
            case 2:{

            editarBebidas();



            }break;
            case 3:{

           listarBebidas();
            getchar();
            op = 4;


            }break;
            case 4:{

             removerBebidas();


            }break;

            case 5:{

            pesquisarBebidas();
            pularLinha();
            pause();

            }break;

            case 6:{

            }
}
    }while (op!=6);

}
/*----------------------------------------------------------------------------------------------------------------------*/
void cadastroBebidas(){//CADASTRO DE NOVAS BEBIDAS

    pintar(240);
    int cancelar = 0;
    int x;
    char CbebidaC [50];
     char CtipoC [20];
    float  FprecoBebidaC;
    int op;//Ultilizado para o Switch case
    int menu;
    int sair;// Ultilizado no do while




    do {
        sair = 0;
        menu = 0;
        limparTela();
        cancelar = 0;
        printfCenter("\t =================| CADASTRO DE BEBIDAS  |=================  \n",COLUNA);
        pularLinha();
        pularLinha();

        printf ("\nInsira a Bebida: ");
        fgets  (CbebidaC,sizeof (CbebidaC), stdin);
        strupr(CbebidaC);
        limparBuff();

        printf ("\nInsira o Tipo da Bebida: ");
        fgets  (CtipoC,sizeof (CtipoC), stdin);
        strupr(CtipoC);
        limparBuff();

        printf ("\nInsira o Pre%co: ",135);
        scanf  ("%f", &FprecoBebidaC);

        strcpy(bebidas.CbebidaC, CbebidaC);
        strcpy(bebidas.CtipoC, CtipoC);
                bebidas.FprecoBebidaC = FprecoBebidaC;
                bebidas.IverificadorC=1;


        getchar();
        printf ("\n1- Cancelar ");
        printf ("\n2- Corrigir ");
        printf ("\n3- Adicionar outra");
        printf ("\n4- Concluir e voltar ao menu anterior:\n");
        scanf  ("%d",&menu);
        limparBuff();

    switch (menu){

            case 1:{//CANCELAR

            bebidas.IverificadorC = 0;
                   sair = 1;

            }break;
            case 2:{//CORRIGIR

            bebidas.IverificadorC = 0;
                    sair = 0;

            }break;
            case 3:{//ADICIONAR OUTRA BEBIDA
                gravarArquivosStructBebidas(bebidas);
            sair = 0;
            }break;

            case 4:{//FFINALIZAR E SAIR
            gravarArquivosStructBebidas(bebidas);
            sair = 1;

            }break;

    }
    }while (sair!=1);


}
/*----------------------------------------------------------------------------------------------------------------------*/
void removerBebidas(){//REMOVE AS BEBIDAS CADASTRADAS
loginMenu();
limparTela();
pintar(240);
limparBuff();
removerArqStructBebidas(bebidas);
pause();
}
/*----------------------------------------------------------------------------------------------------------------------*/
void pesquisarBebidas(){//PESQUISA AS BEBIDAS CADASTRADAS
    setlocale(LC_ALL,"Potuguese");
    limparTela();
    pintar(240);
    getchar();
    char CpesquisarP [50];
    printfCenter("\t =================| PESQUISA DE BEBIDAS  |=================  \n",COLUNA);
    pularLinha();
    pesquisarArqBebidas(bebidas);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void listarBebidas(){//LISTA AS BEBIDAS JÁ CADASTRADAS
    limparTela();
    pintar(240);
    printfCenter("\t =================| BEBIDAS CADASTRADAS  |=================  \n",COLUNA);
    printf ("\n\n");
    listarArquivoStructBebidas(bebidas);
getchar();

            }
/*----------------------------------------------------------------------------------------------------------------------*/
void editarBebidas(){//EDITA AS BEBIDAS CADASTRADAS
    limparTela();
    pintar(240);
    getchar();
    char CpesquisarE [50];
    char CEditarBebidasE [50];
    float FEditarPrecoE;
    int editar,op=0;
    printfCenter("\t =================| EDITAR BEBIDAS  |=================  \n",COLUNA);
    pularLinha();

    editarArqStructBebidas(bebidas);

}
/*----------------------------------------------------------------------------------------------------------------------*/

//PARTE ESCRITA PELO ANDERSON GABRIEL DA SILVA
void MenuProdutos(){//MENU DE GERENCIAMENTO DOS PRODUTOS


        int menu;
        int op;
do {
        limparTela();
        pularLinha();
        pularLinha();
        pularLinha();

     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
     printf("\t\t\t%c         CONTROLE DE ESTOQUE         %c\n",3002,3002);
     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);

        printf ("\n\n\n\t 1 - CADASTRAR PRODUTO");
        pularLinha();
        printf ("\n\t 2 - ATUALIZAR ESTOQUE");
        pularLinha();
        printf ("\n\t 3 - EDITAR PRODUTO");
        pularLinha();
        printf ("\n\t 4 - LISTAR PRODUTOS");
        pularLinha();
        printf ("\n\t 5 - PESQUISAR PRODUTOS");
        pularLinha();
        printf ("\n\t 6 - REMOVER PRODUTOS");


        pularLinha();
        printf ("\n\t 7 - FINALIZAR E VOLTAR AO MENU ANTERIOR: \n\n");
        LinhaIgual();
        pularLinha();
        limparBuff();
        scanf  ("%d",&op);

        switch (op){

            case 1:{//CADASTRAR PRODUTOS
                cadastroProduto();
            }break;
            case 2:{// ATUALIZAR SALDOS DOS PRODUTOS
               AtualizarSaldoProduto();
            }break;
            case 3:{//EDITAR PRODUTOS
               editarproduto();
            }break;
            case 4:{//LISTAR PRODUTO
                listarProdutos();
                pularLinha();
                pause();
            }break;
            case 5:{//PESQUISAR PRODUTOS
                PesquisarProdutos();
            }break;
            case 6:{//REMOVER PRODUTOS
                RemoverProduto();

            }break;
            case 7:{

            }break;

}
    }while (op!=7);

}
/*----------------------------------------------------------------------------------------------------------------------*/
void cadastroProduto(){//CADASTRA NOVOS PRODUTOS


    int cancelar = 0;
    int x;
    //int ingred;//Controla o laço while das opçoes
    char CProdutoC [50];
    float  FpesoC;
    int op;//Ultilizado para o Switch case
    int menu;
    int sair;// Ultilizado no do while




    do {
        sair = 0;
        menu = 0;
        limparTela();
        cancelar = 0;
        printfCenter("\t =================| CADASTRO DE PRODUTOS |=================  \n",COLUNA);
        pularLinha();
        pularLinha();

        limparBuff();
        printf ("\nInsira o Nome: ");
        fgets  (CProdutoC,sizeof (CProdutoC), stdin);
        strupr(CProdutoC);

        limparBuff();
        printf ("\nInsira a quantidade Kg: ");
        scanf  ("%f", &FpesoC);

        strcpy(produto.produto, CProdutoC );
                produto.pesoKg = FpesoC;

        getchar();
        printf ("\n1- Cancelar ");
        printf ("\n2- Corrigir ");
        printf ("\n3- Adicionar outra");
        printf ("\n4- Concluir e voltar ao menu anterior:\n");
        limparBuff();
        scanf  ("%d",&menu);


    switch (menu){

            case 1:{//CANCELAR
                   sair = 1;

            }break;
            case 2:{//CORRIGIR
                    sair = 0;

            }break;
            case 3:{//ADICIONA OUTRO PRODUTO
                gravarArquivosSructProdutos(produto);
            sair = 0;
            }break;

            case 4:{//FINALIZA E SAIR
                gravarArquivosSructProdutos(produto);
              sair = 1;

            }break;

    }
    }while (sair!=1);


}
/*----------------------------------------------------------------------------------------------------------------------*/
void RemoverProduto(){//REMOVE OS PRODUTOS JÁ CADASTRADOS
loginMenu();
limparTela();
limparBuff();
removerArqStructProdutos(produto);
pause();
}
/*----------------------------------------------------------------------------------------------------------------------*/
void PesquisarProdutos(){//PESQUISA OS PRODUTOS JÁ CADASTRADOS
    LimparTela();
    printfCenter("\t =================| PESQUISA DE PRODUTOS  |=================  \n",COLUNA);
    pularLinha();
    pesquisarArqProdutos(produto);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void listarProdutos(){//LISTA OS PRODUTOS CADASTRADOS
    limparTela();
    printfCenter("\t =================| PRODUTOS CADASTRADAS  |=================  \n",COLUNA);
    printf ("\n\n");
    listarArquivoStructProdutos(produto);
getchar();

            }
/*----------------------------------------------------------------------------------------------------------------------*/
void editarproduto(){//EDITA OS PRODUTOS JÁ CADASTRADOS

    limparTela();
    getchar();
    printfCenter("\t =================| EDITAR PRODUTOS  |=================  \n",COLUNA);
    pularLinha();

    editarArqStructProdutos(produto);

}
/*----------------------------------------------------------------------------------------------------------------------*/
void AtualizarSaldoProduto(){//ATUALIZA A QUANTIDADE DO SALDO DOS PRODUTOS JÁ CADASTRADOS

    limparTela();
    getchar();
    printfCenter("\t =================|ATUALIZAR PRODUTOS  |=================  \n",COLUNA);
    pularLinha();
   // loginMenu();
    SaldoArqStructProdutos(produto);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void pintar(int cor){
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, cor);
}
/*----------------------------------------------------------------------------------------------------------------------*/

//FUNÇÃO ESCRITA POR ANDERSON GABRIEL DA SILVA
void LimparTela(){
    system("cls");
}
/*----------------------------------------------------------------------------------------------------------------------*/

//LOGO PRODUZIDO POR LUCAS SOUZA
void telaInicial(){
LimparTela();
//pintar(79);
printf("\n\n\n\n\n\n");
 printf("\t\t\t\t@@@  @  @@@  @@@  @@@  @@@  @  @@@                      @   	\n");
 printf("\t\t\t\t@ @  @	 @    @   @    @ @  @  @ @                     @  @		\n");
 printf("\t\t\t\t@@@  @   @    @   @@@  @@@  @  @@@          @  @     @     @    \n");
 printf("\t\t\t\t@    @  @    @    @    @@   @  @ @       @       @  @       @   \n");
 printf("\t\t\t\t@    @  @@@  @@@  @@@  @ @  @  @ @      @       @  @ @ @ @ @ @  \n");
 printf("\t\t\t                                               @       @               \n");
 printf("\t\t\t\t@@@  @@@  @   @  @  @@@  @   @  @@@    @      @ @ @ @@           \n");
 printf("\t\t\t\t@    @ @  @@ @@  @  @    @   @  @ @    @             @           \n");
 printf("\t\t\t\t@@@  @@@  @ @ @  @  @ @  @   @  @@@     @           @            \n");
 printf("\t\t\t\t@    @ @  @   @  @  @ @  @   @  @ @       @        @             \n");
 printf("\t\t\t\t@    @ @  @   @  @  @@@  @@@ @  @ @          @  @               \n");
 printf("\n");

 printf("\t\t\t\t@@@  @@@  @   @  @  @@@ @@@  @ @  @@@\n");
 printf("\t\t\t\t@ @  @ @  @@  @  @  @ @ @    @ @  @ @\n");
 printf("\t\t\t\t@@@  @@@  @ @ @  @  @@@ @ @  @ @  @@@\n");
 printf("\t\t\t\t@    @ @  @  @@  @  @ @ @ @  @ @  @ @\n");
 printf("\t\t\t\t@    @ @  @   @  @  @ @ @@@  @@@  @ @\n");

 pularLinha();
 pularLinha();
 pularLinha();
 printf("\n\t\t\t\t\t\t\t\tProduzido por Help Tecnology %c",169);
 pularLinha();
getchar();
}


//FUNÇÃO ESCRITA POR ANDERSON GABRIEL DA SILVA
void pause (){//FUNÇÃO PAUSA O SISTEMA

    system("PAUSE");

}
/*----------------------------------------------------------------------------------------------------------------------*/
void gotoxy(int x, int y){
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
coord);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void linha(){//PRINTA NA TELA UMA LINHA
    int x=0; for(x=0;x<COLUNA;x++){    printf("%c",205);
    }
}
/*----------------------------------------------------------------------------------------------------------------------*/
void coluna(int posicao){
    int x; for(x=0;x<=LINHA;x++){    gotoxy(posicao,x);    printf("%c",186); }

}
/*----------------------------------------------------------------------------------------------------------------------*/

//FUNÇÃO ESCRITA POR ANDERSON GABRIEL DA SILVA
void caixaDados(int tamanho){//CRIA UMA SEQUENCIA DE CAIXA DE DADOS PARA SER ULTILIZADO COMO CAIXA

for (int x=0;x<tamanho;x++){
            printf("%c",BLACK);
        }
}
/*----------------------------------------------------------------------------------------------------------------------*/
void pintarTelas(){//PINTA A TELA
    pintar(240);
    printf ("\n");
}
/*----------------------------------------------------------------------------------------------------------------------*/
void LinhaIgual (){//EXIBE UMA LINHA COMPOSTA DE SINAL "="
    for (int x = 0; x<116;x++)
    {
        printf ("=");
    }

}
/*----------------------------------------------------------------------------------------------------------------------*/
void LinhaTraco (){//EXIBE UMA LINHA DE "-"

    for (int x = 0; x<80;x++)
    {
        printf ("-");
    }
}
/*----------------------------------------------------------------------------------------------------------------------*/
