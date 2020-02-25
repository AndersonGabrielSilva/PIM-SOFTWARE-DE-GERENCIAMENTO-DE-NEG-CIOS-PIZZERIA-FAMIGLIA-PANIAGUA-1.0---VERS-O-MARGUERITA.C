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

float promoDesconto(float valor);

 typedef struct {//STRUCT DO TIPO CLIENTES
        char CclienteC [50];
        char CpaisC [50];
        char CestadoC [50];
        char CcidadeC [50];
        char CbairroC [50];
        char CruaC [50];
        long long int LLIcpfC;
        int  Inumero_casaC;
        int  IdddC;
        int  ItelefoneC;
        int  IverificadorC;
        int  IdiaC;
        int  ImesC;
        int  IanoC;

    } CLIENTES;
    CLIENTES clientes;

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
    PEDIDOS pedidosnovos;

   typedef struct {//STRUCT DO TIPO PIZZAS
        char CsaborC [50];
        float  FprecoC;
        int  IverificadorC;

    } PIZZAS;
    PIZZAS sabores;

    typedef struct {//STRUCT DO TIPO BEBIDAS
        char CbebidaC [50];//ARMAZENA O SABOR DA BEBIDA
        char CtipoC [50];//ARMAZENA O TIPO DA BEBIDA
        float  FprecoBebidaC;// ARMAZENA O PRECO DA BEBIDA
        int  IverificadorC;//VERIFICA SE DEVE OU NÃƒO GRAVAR
    }BEBIDAS;
    BEBIDAS bebidas;

    typedef struct {//STRUCT DO TIPO AVALIAÇÃO
        char CavaliacaoC [10];
        char CobservacaoC [250];
        int  IverificadorC;

    } AVALIACAO;
    AVALIACAO avaliacao;

void gravarArquivosStructClientes (CLIENTES nomeStruct){//GRAVA UMA STRUCT EM UM ARQUIVO
        FILE *arq;
        arq = fopen("C:\\PizzariaPIM\\bin\\arquivos\\CadastroClientes.dat", "ab");
        if (arq == NULL){

            fprintf(stderr, "Problema na criacao do arquivo\n");
            pause();
            return 1;
        }

        fwrite(&nomeStruct, sizeof(CLIENTES), 1, arq);

        fclose(arq);


}
/*----------------------------------------------------------------------------------------------------------------------*/
int pesquisarArqClientes ( CLIENTES nomeStruct){// PESQUISA UMA STRUCT DENTRO DE UM ARQUIVO////PESQUISAR ARQUIVO CLIENTES
 setlocale(LC_ALL,"Potuguese");
FILE *arq;
 long long int LLIpesquisarC;
 int senao = 0;// CONTROLA SE O CLIENTE EXISTE OU NÃO
    arq = fopen("C:\\PizzariaPIM\\bin\\arquivos\\CadastroClientes.dat","rb");
    if (arq == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{
    printf ("\nDigite o CPF do Cliente: ");
    scanf("%lld", &LLIpesquisarC);

    fflush(stdin);

         while (fread(&clientes,sizeof(CLIENTES),1,arq)==1){

            if (clientes.LLIcpfC == LLIpesquisarC){
            senao=1;
			LinhaTraco();
            printf ("\nCliente: %s\n", clientes.CclienteC);
            printf ("\n\tCPF: %lld\n", clientes.LLIcpfC);
            pularLinha();
            printf ("\tEndere%co completo: \n",135);
            printf (" \t%c Pais: %s \t%c Estado: %s \t%c Cidade: %s", 175, clientes.CpaisC, 175, clientes.CestadoC, 175, clientes.CcidadeC);
            printf (" \t%c Bairro: %s \t%c Rua: %s \t%c Numero: %d\n", 175, clientes.CbairroC, 175,  clientes.CruaC, 175, clientes.Inumero_casaC);
            printf ("\n\tTelefone: (%d)\t", clientes.IdddC);
            printf ("%d\n", clientes.ItelefoneC);
            printf ("\n\tData de nascimento: %d/%d/%d\n",clientes.IdiaC, clientes.ImesC, clientes.IanoC);
            LinhaTraco();
            break;
            }
        }
        if (senao == 0){

            printf("\nCliente n%co encontrado",198);

            getchar();
        }

    }
     fclose(arq);
     return (clientes.CclienteC);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void listarArquivoStructClientes(CLIENTES nomeStruct){//LISTAR ARQUIVO CLIENTES

    FILE *arq;
    arq = fopen("C:\\PizzariaPIM\\bin\\arquivos\\CadastroClientes.dat","rb");//C:\PizzariaPIM\bin\arquivos
    if (arq == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{

        while (fread(&clientes,sizeof(CLIENTES),1,arq)==1){

            printf ("\nCliente: %s\n", clientes.CclienteC);
            printf ("\n\tCPF: %lld\n", clientes.LLIcpfC);
            pularLinha();
            printf ("\tEndere%co completo: \n",135);
            printf (" \t%c Pais: %s \t%c Estado: %s \t%c Cidade: %s", 175, clientes.CpaisC, 175, clientes.CestadoC, 175, clientes.CcidadeC);
            printf (" \t%c Bairro: %s \t%c Rua: %s \t%c Numero: %d\n", 175, clientes.CbairroC, 175,  clientes.CruaC, 175, clientes.Inumero_casaC);
            printf ("\n\tTelefone: (%d)\t", clientes.IdddC);
            printf ("%d\n", clientes.ItelefoneC);
			printf ("\n\tData de nascimento: %d/%d/%d\n",clientes.IdiaC, clientes.ImesC, clientes.IanoC);
            LinhaTraco();
        }
    }
    fclose(arq);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void removerArqStructClientes(CLIENTES nomeStruct){//REMOVER ARQUIVO CLIENTES
    FILE* arq;
    FILE* temp;
    long long int LLIpesquisarC;//CPF DE BUSCA INSERIDO PELO USURARIO
    int senao = 0;// CONTROLA SE O CLIENTE EXISTE OU NÃO
    char op;
     arq = fopen("C:\\PizzariaPIM\\bin\\arquivos\\CadastroClientes.dat","rb");
      temp = fopen("C:\\PizzariaPIM\\bin\\arquivos\\temporario.dat","wb");
     limparBuff();
    if (arq == NULL&&temp == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{
        limparBuff();
        printf ("\nDigite o CPF do Cliente: ");
        scanf("%lld", &LLIpesquisarC);
        limparBuff();


        while (fread(&clientes,sizeof(CLIENTES),1,arq)==1){

            if (clientes.LLIcpfC == LLIpesquisarC){
            senao = 1;
            printf ("\nCliente: %s\n", clientes.CclienteC);
            printf ("\n\tCPF: %lld\n", clientes.LLIcpfC);
            printf ("\tEndere%co completo: \n",135);
            printf (" \t%c Pais: %s \t%c Estado: %s \t%c Cidade: %s", 175, clientes.CpaisC, 175, clientes.CestadoC, 175, clientes.CcidadeC);
            printf (" \t%c Bairro: %s \t%c Rua: %s \t%c Numero: %d\n", 175, clientes.CbairroC, 175,  clientes.CruaC, 175, clientes.Inumero_casaC);
            printf ("\n\tTelefone: (%d)\t", clientes.IdddC);
            printf ("%d\n", clientes.ItelefoneC);
			printf ("\n\tData de nascimento: %d/%d/%d\n",clientes.IdiaC, clientes.ImesC, clientes.IanoC);
            LinhaTraco();
            getchar();
            pularLinha();
            }else{


            fwrite(&clientes,sizeof(CLIENTES),1,temp);//gravando os dados no arquivo temp

            }
            }
           fclose(arq);//fechar o arq
           fclose(temp);//fechar o temp

           if (senao == 1){
           printf ("\n Deseja remover ? [S/N]");
           scanf("%c", &op);
           limparBuff();
                if (op == 's'){
                    remove("C:\\PizzariaPIM\\bin\\arquivos\\CadastroClientes.dat");
                    rename("C:\\PizzariaPIM\\bin\\arquivos\\temporario.dat", "C:\\PizzariaPIM\\bin\\arquivos\\CadastroClientes.dat");

                    LinhaTraco();
                    printf   ("\nProduto Removido\n");
                    LinhaTraco();
                    pularLinha();
                    pause();
                }else {
                    remove(("C:\\PizzariaPIM\\bin\\arquivos\\temporario.dat"));
                }
           }else {

            printf("\nCliente nao encontrado \n");
            pause();
           }
}
}
/*----------------------------------------------------------------------------------------------------------------------*/
void editarArqStructClientes (CLIENTES nomeStruct){//EDITAR ARQUIVO CLIENTES

    FILE* arq;
    FILE* temp;
    long long int LLIpesquisarC;
    char opc;
    char novoCliente [50];
    char novoPais [50];
    char novoEstado [50];
    char novoCidade [50];
    char novoBairro [50];
    char novoRua [50];
    int novoDDD;
    int novoTelefone;
    int novoNumeroCasa;
    int novoDia;
    int novoAno;
    int novoMes;
    char op;
     arq = fopen("C:\\PizzariaPIM\\bin\\arquivos\\CadastroClientes.dat","rb");
     temp = fopen("C:\\PizzariaPIM\\bin\\arquivos\\temporario.dat","wb");
    if (arq == NULL&&temp == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{

        printf ("\nDigite o CPF do Cliente: ");
        scanf("%lld", &LLIpesquisarC);
        limparBuff();
        fflush(stdin);

        while (fread(&clientes,sizeof(CLIENTES),1,arq)==1){

            if (clientes.LLIcpfC == LLIpesquisarC){

            printf ("\nCliente: %s\n", clientes.CclienteC);
            printf ("\n\tCPF: %lld\n", clientes.LLIcpfC);
            pularLinha();
			printf ("\tEndere%co completo: \n",135);
			pularLinha();
            printf (" \t%c Pais: %s \t%c Estado: %s \t%c Cidade: %s", 175, clientes.CpaisC, 175, clientes.CestadoC, 175, clientes.CcidadeC);
            printf (" \t%c Bairro: %s \t%c Rua: %s \t%c Numero: %d\n", 175, clientes.CbairroC, 175,  clientes.CruaC, 175, clientes.Inumero_casaC);
            printf ("\n\tTelefone: (%d)\t", clientes.IdddC);
            printf ("%d\n", clientes.ItelefoneC);
			printf ("\n\tData de nascimento: %d/%d/%d\n",clientes.IdiaC, clientes.ImesC, clientes.IanoC);
            LinhaTraco();
            pularLinha();

             do{
        printf ("\n1 - Alterar somente o Nome");
		printf ("\n2 - Alterar somente o Pais");
        printf ("\n3 - Alterar somente o Estado");
        printf ("\n4 - Alterar somente a Cidade");
        printf ("\n5 - Alterar somente o Bairro");
        printf ("\n6 - Alterar somente a Rua");
        printf ("\n7 - Alterar somente o Numero");
        printf ("\n8 - Alterar somente o DDD");
        printf ("\n9 - Alterar somente o Telefone");
        printf ("\n10 - Alterar somente o Data de nascimento");
        printf ("\n11 - Alterar somente o Mes de nascimento");
        printf ("\n12 - Alterar somente o Ano de nascimento");
        printf ("\n13 - Tudo");
        printf ("\n14 - Sair");

        printf ("\nEscolha a op%c%co desejada: ",135,198);
        scanf  ("%d",&opc);
        limparBuff();

            switch (opc){
            case 1:{
               printf ("\nDigite o novo Nome: ");
               fgets(novoCliente,sizeof(novoCliente),stdin);
               strupr(novoCliente);
               limparBuff();
               strcpy (clientes.CclienteC,novoCliente);
                opc = 1;
                printf("\nAlterado com sucesso");
               getchar();

            }break;

			case 2:{
               printf ("\nDigite o novo Pais: ");
               fgets(novoPais,sizeof(novoPais),stdin);
               strupr(novoPais);
               limparBuff();
               strcpy (clientes.CpaisC,novoPais);
                opc = 1;
                printf("\nAlterado com sucesso");
               getchar();

            }break;

			case 3:{
               printf ("\nDigite o novo Estado: ");
               fgets(novoEstado,sizeof(novoEstado),stdin);
               strupr(novoEstado);
               limparBuff();
               strcpy (clientes.CestadoC,novoEstado);
                opc = 1;
                printf("\nAlterado com sucesso");
               getchar();

            }break;

			case 4:{
               printf ("\nDigite a nova Cidade: ");
               fgets(novoCidade,sizeof(novoCidade),stdin);
               strupr(novoCidade);
               limparBuff();
               strcpy (clientes.CcidadeC,novoCidade);
                opc = 1;
                printf("\nAlterado com sucesso");
               getchar();

            }break;

			case 5:{
               printf ("\nDigite o novo Bairro: ");
               fgets(novoBairro,sizeof(novoBairro),stdin);
               strupr(novoBairro);
               limparBuff();
               strcpy (clientes.CbairroC,novoBairro);
                opc = 1;
                printf("\nAlterado com sucesso");
               getchar();

            }break;

			case 6:{
               printf ("\nDigite a nova Rua: ");
               fgets(novoRua,sizeof(novoRua),stdin);
               strupr(novoRua);
               limparBuff();
               strcpy (clientes.CruaC,novoRua);
                opc = 1;
                printf("\nAlterado com sucesso");
               getchar();

            }break;

			case 7:{
                 printf ("\nDigite o novo Numero da casa: ");
                 scanf  ("%d",&novoNumeroCasa);
                 limparBuff();

                 clientes.Inumero_casaC = novoNumeroCasa;
                 opc = 1;
                printf("\nAlterado com sucesso");
                getchar();

            }break;

			case 8:{
                 printf ("\nDigite o novo DDD: ");
                 scanf  ("%d",&novoDDD);
                 limparBuff();

                 clientes.IdddC = novoDDD;
                 opc = 1;
                printf("\nAlterado com sucesso");
                getchar();

            }break;

            case 9:{
                 printf ("\nDigite o novo Telefone: ");
                 scanf  ("%d",&novoTelefone);
                 limparBuff();

                 clientes.ItelefoneC = novoTelefone;
                 opc = 1;
                printf("\nAlterado com sucesso");
                getchar();

            }break;

			case 10:{
                 printf ("\nDigite o novo Dia: ");
                 scanf  ("%d",&novoDia);
                 limparBuff();

                 clientes.IdiaC = novoDia;
                 opc = 1;
                printf("\nAlterado com sucesso");
                getchar();

            }break;

			case 11:{
                 printf ("\nDigite o novo Mes: ");
                 scanf  ("%d",&novoMes);
                 limparBuff();

                 clientes.ImesC = novoMes;
                 opc = 1;
                printf("\nAlterado com sucesso");
                getchar();

            }break;

			case 12:{
                 printf ("\nDigite o novo Ano: ");
                 scanf  ("%d",&novoAno);
                 limparBuff();

                 clientes.IanoC = novoAno;
                 opc = 1;
                printf("\nAlterado com sucesso");
                getchar();

            }break;



            case 13:{
			//INFORMANDO NOVO Cliente
				limparTela();
                printf ("\nDigite o novo Nome: ");
                fgets(novoCliente,sizeof(novoCliente),stdin);
                strupr(novoCliente);
                limparBuff();

				printf ("\nDigite o novo Pais: ");
               fgets(novoPais,sizeof(novoPais),stdin);
               strupr(novoPais);
               limparBuff();

			   printf ("\nDigite o novo Estado: ");
               fgets(novoEstado,sizeof(novoEstado),stdin);
               strupr(novoEstado);
               limparBuff();


			   printf ("\nDigite a nova Cidade: ");
               fgets(novoCidade,sizeof(novoCidade),stdin);
               strupr(novoCidade);
               limparBuff();

			   printf ("\nDigite o novo Bairro: ");
               fgets(novoBairro,sizeof(novoBairro),stdin);
               strupr(novoBairro);
               limparBuff();

			   printf ("\nDigite a nova Rua: ");
               fgets(novoRua,sizeof(novoRua),stdin);
               strupr(novoRua);
               limparBuff();

			   printf ("\nDigite o novo Numero da casa: ");
                 scanf  ("%d",&novoNumeroCasa);
                 limparBuff();

			   printf ("\nDigite o novo DDD: ");
                 scanf  ("%d",&novoDDD);
                 limparBuff();

               printf ("\nDigite o novo Telefone: ");
                 scanf  ("%d",&novoTelefone);
                 limparBuff();

			   printf ("\nDigite o novo Dia: ");
                 scanf  ("%d",&novoDia);
                 limparBuff();

               printf ("\nDigite o novo Mes: ");
                 scanf  ("%d",&novoMes);
                 limparBuff();

			   printf ("\nDigite o novo Ano: ");
                 scanf  ("%d",&novoAno);
                 limparBuff();

				 //ALTERANDO TODOS OS VALORES

                strcpy (clientes.CclienteC,novoCliente);
				strcpy (clientes.CpaisC,novoPais);
				strcpy (clientes.CestadoC,novoEstado);
				strcpy (clientes.CcidadeC,novoCidade);
				strcpy (clientes.CbairroC,novoBairro);
				strcpy (clientes.CruaC,novoRua);

				clientes.Inumero_casaC = novoNumeroCasa;
				clientes.IdddC = novoDDD;
				clientes.ItelefoneC = novoTelefone;
				clientes.IdiaC = novoDia;
				clientes.ImesC = novoMes;
				clientes.IanoC = novoAno;

                opc=1;
                printf("\nAlterado com sucesso");
                getchar();

            }break;
            case 14: {
                opc = 1;
            }break;
            default: {
                printf ("\nOp%c%co inv%clida!",135,198,160);
                opc = 0;
                getchar();
            }
            }
    }while (opc!=1);

            fwrite(&clientes,sizeof(CLIENTES),1,temp);

            }else{

            printf  ("\nCliente não encontrado");
            fwrite(&clientes,sizeof(CLIENTES),1,temp);//gravando os dados no arquivo temp

            }

            }
           fclose(arq);//fechar o arq
           fclose(temp);//fechar o temp
          op = 's';
                if (op == 's'){
                    remove("C:\\PizzariaPIM\\bin\\arquivos\\CadastroClientes.dat");
                    rename("C:\\PizzariaPIM\\bin\\arquivos\\temporario.dat", "C:\\PizzariaPIM\\bin\\arquivos\\CadastroClientes.dat");
                }else {
                    remove("C:\\PizzariaPIM\\bin\\arquivos\\temporario.dat");
                }



}
}
/*----------------------------------------------------------------------------------------------------------------------*/
void gravarArquivosStructPedidos (PEDIDOS nomeStruct){//GRAVA UMA STRUCT EM UM ARQUIVO
        FILE *arq;
        arq = fopen("C:\\PizzariaPIM\\bin\\arquivos\\CadastroPedidos.dat", "ab");
        if (arq == NULL){

            fprintf(stderr, "Problema na criacao do arquivo\n");
            pause();
            return 1;
        }

        fwrite(&pedidosnovos, sizeof(PEDIDOS), 1, arq);

        fclose(arq);


}
/*----------------------------------------------------------------------------------------------------------------------*/
void removerArqStructPedidos(PEDIDOS nomeStruct){//REMOVER ARQUIVO PEDIDOS
    FILE* arq;
    FILE* temp;
    long long int LLIpesquisarcpfC;
    char op;
    int encontrado=0;

     arq = fopen("C:\\PizzariaPIM\\bin\\arquivos\\CadastroPedidos.dat","rb");
      temp = fopen("C:\\PizzariaPIM\\bin\\arquivos\\temporario.dat","wb");
     limparBuff();
    if (arq == NULL&&temp == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{
         pularLinha();
         printfCenter("\t =================| REMOVER PEDIDOS |=================  \n",COLUNA);
         printf ("\n\n");

         printf ("\nDigite o CPF do Cliente: ");
         scanf("%lld", &LLIpesquisarcpfC);
         limparBuff();

        while (fread(&nomeStruct,sizeof(PEDIDOS),1,arq)==1){

            if (nomeStruct.LLIcpfP == LLIpesquisarcpfC){
            encontrado = 1;
            printf ("\nCliente: %s\n", nomeStruct.CclienteP);

                printf ("\nPizzas: %s\n", nomeStruct.CpizzasP);
                printf("\nQuantidade de Pizzas: %d",nomeStruct.IqtdPizzasP);
                printf ("\nBebidas: %s\n", nomeStruct.CbebidasP);
                printf("\nQuantidade de Bebidas: %d\n",nomeStruct.IqtdbebidasP);

                LinhaIgual();
                printf("\nVALOR: %.2f",nomeStruct.FtotalP+nomeStruct.FvalordescontoP);
                printf("\nDESCONTO: %.2f",nomeStruct.FvalordescontoP);
                printf("\nTOTAL: %.2f",nomeStruct.FtotalP);
                pularLinha();
                LinhaIgual();
            pularLinha();
            }else{

            fwrite(&nomeStruct,sizeof(PEDIDOS),1,temp);//gravando os dados no arquivo temp
            }
            }
           fclose(arq);//fechar o arq
           fclose(temp);//fechar o temp

           if (encontrado!=0){
           printf ("\n Deseja remover ? [S/N]");
           scanf("%c", &op);
           limparBuff();
                if (op == 's' || op == 'S'){
                    remove("C:\\PizzariaPIM\\bin\\arquivos\\CadastroPedidos.dat");
                    rename("C:\\PizzariaPIM\\bin\\arquivos\\temporario.dat", "C:\\PizzariaPIM\\bin\\arquivos\\CadastroPedidos.dat");

                        LinhaTraco();
                        printf   ("\nProduto Removido\n");
                        LinhaTraco();
                        pularLinha();
                        pause();
                }else {
                    remove(("C:\\PizzariaPIM\\bin\\arquivos\\temporario.dat"));
                }
}else {
    LinhaTraco();
    printf("\nPedido nao encontado!\n");
    LinhaTraco();
    pularLinha();
    pause();
}
}
}
/*----------------------------------------------------------------------------------------------------------------------*/
void listarArquivoStructPedidos(PEDIDOS nomeStruct){// LISTAR ARQUIVO PEDIDOS
    LimparTela();
    FILE *arq;
    arq = fopen("C:\\PizzariaPIM\\bin\\arquivos\\CadastroPedidos.dat","rb");
    if (arq == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{
         pularLinha();
         printfCenter("\t =================| PEDIDOS CADASTRADOS  |=================  \n",COLUNA);
         printf ("\n\n");

        while (fread(&pedidosnovos,sizeof(PEDIDOS),1,arq)==1){

                printf ("\nCliente: %s \t", pedidosnovos.CclienteP);
                printf ("\nCPF: %lld\n", pedidosnovos.LLIcpfP);
                printf ("\nPizzas: %s\tPreco: %.2f", pedidosnovos.CpizzasP,pedidosnovos.FprecoPizzaP);
                printf("\nQuantidade de Pizzas: %d", pedidosnovos.IqtdPizzasP);
                printf ("\n\nBebidas: %s\tPreco: %.2f", pedidosnovos.CbebidasP,pedidosnovos.FprecoBebidaP);
                printf("\nQuantidade de Bebidas: %d", pedidosnovos.IqtdbebidasP);
                pularLinha();
                printf("\nPROMOCAO: %s TIPO: %d%%",pedidosnovos.CPromocapP,pedidosnovos.IpromocaoP);
                pularLinha();

                LinhaIgual();
                printf("\nVALOR: %.2f",pedidosnovos.FtotalP+pedidosnovos.FvalordescontoP);
                printf("\nDESCONTO: %.2f",pedidosnovos.FvalordescontoP);
                printf("\nTOTAL: %.2f",pedidosnovos.FtotalP);
                pularLinha();
                LinhaIgual();
                pularLinha();
                pularLinha();
        }
        pause();
    }
    fclose(arq);
}

/*----------------------------------------------------------------------------------------------------------------------*/
int pesquisarArqPedidos (){// PESQUISA UMA STRUCT DENTRO DE UM ARQUIVO
 setlocale(LC_ALL,"Potuguese");
FILE *arq;
 long long int LLIpesquisarC;
 int senao = 0;
 int verqtdpedidos;// VARIAVEL VERIFICA A QUANTIDADE DE PEDIDOS DO MESMO CLIENTE
 float valorTotal;
 float valorTotaldesconto;
    arq = fopen("C:\\PizzariaPIM\\bin\\arquivos\\CadastroPedidos.dat","rb");
    if (arq == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{
    printf ("\nDigite o CPF do Cliente: ");
    scanf("%lld", &LLIpesquisarC);
    fflush(stdin);
    valorTotal=0;
    valorTotaldesconto=0;
    verqtdpedidos=0;
         while (fread(&pedidosnovos,sizeof(PEDIDOS),1,arq)==1){

            if (pedidosnovos.LLIcpfP == LLIpesquisarC){
            senao=1;
            pularLinha();

                printf ("\nCliente: %s \t", pedidosnovos.CclienteP);
                printf ("\nCPF: %lld\n", pedidosnovos.LLIcpfP);
                pularLinha();
                printf ("\nPizzas: %sPreco: %.2f", pedidosnovos.CpizzasP,pedidosnovos.FprecoPizzaP);
                printf("\nQuantidade de Pizzas: %d", pedidosnovos.IqtdPizzasP);
                printf ("\n\nBebidas: %s Preco: %.2f", pedidosnovos.CbebidasP,pedidosnovos.FprecoBebidaP);
                printf("\nQuantidade de Bebidas: %d", pedidosnovos.IqtdbebidasP);
                pularLinha();
                printf("\nPROMOCAO: %s TIPO: %d%%",pedidosnovos.CPromocapP,pedidosnovos.IpromocaoP);
                pularLinha();

                LinhaIgual();
                printf("\nVALOR: %.2f",pedidosnovos.FtotalP+pedidosnovos.FvalordescontoP);
                printf("\nDESCONTO: %.2f",pedidosnovos.FvalordescontoP);
                printf("\nTOTAL: %.2f",pedidosnovos.FtotalP);
                pularLinha();
                LinhaIgual();
                valorTotal = valorTotal+pedidosnovos.FtotalP;
                valorTotaldesconto = valorTotaldesconto+pedidosnovos.FvalordescontoP;
                verqtdpedidos++;

            }
        }

        if (senao == 0){

            printf("\nPedido n%co encontrado",198);

            getchar();
        }else if(verqtdpedidos>1) {
            pularLinha();

            printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
            printf("\n\t\t\t%c  VALOR TOTAL DESCONTOS: %.2f        %c",3002,valorTotaldesconto,3002);
            printf("\n\t\t\t%c  VALOR TOTAL PEDIDOS: %.2f         %c",3002,valorTotal,3002);
            printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);
            pularLinha();

        }

    }
     fclose(arq);
     return (clientes.CclienteC);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void gravarArquivosStructAvaliacao (AVALIACAO nomeStruct){//GRAVA UMA STRUCT EM UM ARQUIVO
        FILE *arq;
        arq = fopen("C:\\PizzariaPIM\\bin\\arquivos\\Avaliacao.dat", "ab");
        if (arq == NULL){

            fprintf(stderr, "Problema na criacao do arquivo\n");
            pause();
            return 1;
        }

        fwrite(&nomeStruct, sizeof(nomeStruct), 1, arq);

        fclose(arq);


}
/*----------------------------------------------------------------------------------------------------------------------*/
void gravaObservacaoStrucAvaliacao (){//ARMAZENA A OBSERVAÇÃO DA AVALIACAO
    limparBuff();
            printf("\nObservacao: ");
                fgets  (avaliacao.CobservacaoC,sizeof (avaliacao.CobservacaoC), stdin);
                strupr(avaliacao.CobservacaoC);
                limparBuff();
}
/*----------------------------------------------------------------------------------------------------------------------*/
void MenuCliente(){//Menu de Gerenciamento dos Clientes


        int menu;
        int op;
do {
        limparTela();
        pintar(240);
        pularLinha();
        pularLinha();
        pularLinha();

     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
     printf("\t\t\t%c               CLIENTES              %c\n",3002,3002);
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
            cadastroClientes();
            op = 0;


            }break;
            case 2:{

            editarClientes();



            }break;
            case 3:{

           listarClientes();
            getchar();
            op = 4;


            }break;
            case 4:{

             removerClientes();


            }break;

            case 5:{

            pesquisarClientes();
            pularLinha();
            pause();

            }break;

            case 6:{
            limparBuff();
            }
}
    }while (op!=6);

}
/*----------------------------------------------------------------------------------------------------------------------*/
void cadastroClientes(){//Cadastra novos Clientes


    int cancelar = 0;
    int x;
    char CclienteC [50];
    char CcpfC [12];
    long long int LLIcpfC;
    char CpaisC [50];
    char CestadoC [50];
    char CcidadeC [50];
    char CbairroC [50];
    char CruaC [50];
    int  Inumero_casaC;
    int  IdddC;
    int  ItelefoneC;
    int  IdiaC;
    int  ImesC;
    int  IanoC;
    int op;//Ultilizado para o Switch case
    int menu;
    int sair;// Ultilizado no do while

    pintar(240);


    do {
        sair = 0;
        menu = 0;
        limparTela();
        cancelar = 0;
        printfCenter("\t =================| CADASTRO DE CLIENTES  |=================  \n",COLUNA);
        pularLinha();
        pularLinha();

        limparBuff();
        printf ("\nInsira o Nome do Cliente: ");
        fgets  (CclienteC,sizeof (CclienteC), stdin);
        strupr(CclienteC);
        limparBuff();


        printf ("\nInsira o CPF do Cliente: ");
        scanf("%lld", &LLIcpfC);//
        limparBuff();

		printf ("\nInsira o Endere%co Completo: ",135);

		printf ("\n\tPais: ");
        fgets  (CpaisC,sizeof (CpaisC), stdin);
        strupr(CpaisC);
        limparBuff();

		printf ("\n\tEstado: ");
        fgets  (CestadoC,sizeof (CestadoC), stdin);
        strupr(CestadoC);
        limparBuff();

		printf ("\n\tCidade: ");
        fgets  (CcidadeC,sizeof (CcidadeC), stdin);
        strupr(CcidadeC);
        limparBuff();

		printf ("\n\tBairro: ");
        fgets  (CbairroC,sizeof (CbairroC), stdin);
        strupr(CbairroC);
        limparBuff();

		printf ("\n\tRua: ");
        fgets  (CruaC,sizeof (CruaC), stdin);
        strupr(CruaC);
        limparBuff();

        printf ("\n\tNumero: ");
        scanf  ("%d", &Inumero_casaC);
        limparBuff();

		printf ("\nInsira o DDD: ");
        scanf  ("%d", &IdddC);
        limparBuff();

		printf ("\nInsira o Telefone: ");
        scanf  ("%d", &ItelefoneC);
        limparBuff();

		printf ("\nInsira a data de nascimento: ");
		printf ("\n\tDia: ");
        scanf  ("%d", &IdiaC);
        limparBuff();
		printf ("\tMes: ");
        scanf  ("%d", &ImesC);
        limparBuff();
		printf ("\tAno: ");
        scanf  ("%d", &IanoC);


        strcpy(clientes.CclienteC, CclienteC);
       // strcpy(clientes.CcpfC, CcpfC);
        strcpy(clientes.CpaisC, CpaisC);
        strcpy(clientes.CestadoC, CestadoC);
        strcpy(clientes.CcidadeC, CcidadeC);
        strcpy(clientes.CbairroC, CbairroC);
        strcpy(clientes.CruaC, CruaC);

                clientes.LLIcpfC = LLIcpfC;
                clientes.Inumero_casaC = Inumero_casaC;
                clientes.IdddC = IdddC;
                clientes.ItelefoneC = ItelefoneC;
                clientes.IdiaC = IdiaC;
                clientes.ImesC = ImesC;
                clientes.IanoC = IanoC;
                clientes.IverificadorC=1;



        getchar();
        printf ("\n1- Cancelar ");
        printf ("\n2- Corrigir ");
        printf ("\n3- Adicionar outra");
        printf ("\n4- Concluir e voltar ao menu anterior:\n");
        scanf  ("%d",&menu);
        limparBuff();

    switch (menu){

            case 1:{//CANCELAR

            clientes.IverificadorC = 0;
                   sair = 1;

            }break;
            case 2:{//CORRIGIR

            clientes.IverificadorC = 0;
                    sair = 0;

            }break;
            case 3:{//Adicionar outro Cliente
                gravarArquivosStructClientes(clientes);
            sair = 0;
            }break;

            case 4:{//Finalizar e Sair
            gravarArquivosStructClientes(clientes);
            sair = 1;

            }break;

    }
    }while (sair!=1);


}
/*----------------------------------------------------------------------------------------------------------------------*/
void removerClientes(){//Remove os clientes Cadastrados
    loginMenu();
    limparTela();
    getchar();
    printfCenter("\t =================| REMOVER CLIENTES  |=================  \n",COLUNA);
    pularLinha();
    limparBuff();
    removerArqStructClientes(clientes);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void pesquisarClientes(){//Pesquisa os clientes

    limparTela();
    getchar();
    printfCenter("\t =================| PESQUISA DE CLIENTES  |=================  \n",COLUNA);
    pularLinha();
    pesquisarArqClientes(clientes);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void listarClientes(){//Lista os clientes Cadastrados
    limparTela();
    printfCenter("\t =================| CLIENTES CADASTRADOS  |=================  \n",COLUNA);
    printf ("\n\n");
    listarArquivoStructClientes(clientes);
getchar();

            }
/*----------------------------------------------------------------------------------------------------------------------*/
void editarClientes(){

    limparTela();
    getchar();
    char CpesquisarE [50];
    char CEditarClientesE [50];
    float FEditarTelefoneE;
    int editar,op=0;
    printfCenter("\t =================| EDITAR CLIENTES  |=================  \n",COLUNA);
    pularLinha();

    editarArqStructClientes(clientes);

}

void MenuPedidos(){//Menu de Gerenciamento dos Clientes


        int menu;
        int op;
do {
        limparTela();
        pintar(240);
        pularLinha();
        pularLinha();
        pularLinha();

     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
     printf("\t\t\t%c         CONTROLE DE PEDIDOS         %c\n",3002,3002);
     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);

        printf ("\n\n\n\t 1 - CADASTRAR PEDIDO");
        pularLinha();
        printf ("\n\t 2 - LISTAR PEDIDOS");
        pularLinha();
        printf ("\n\t 3 - REMOVER PEDIDOS");
        pularLinha();
        printf ("\n\t 4 - PESQUISAR PEDIDOS");
        pularLinha();
        printf ("\n\t 5 - FINALIZAR E VOLTAR AO MENU ANTERIOR: \n\n");
        LinhaIgual();
        pularLinha();
        scanf  ("%d",&op);

        switch (op){

            case 1:{
            getchar();
            cadastroPedidos();
            op = 0;


            }break;
            case 2:{
            listarPedidos();
            getchar();
            op = 4;


            }break;
            case 3:{

            removerPedidos();


            }break;
            case 4:{
            pesquisarPedidos();
            pularLinha();
            pause();


            }break;

            case 5:{
            limparBuff();


            };
}
    }while (op!=5);

}
/*----------------------------------------------------------------------------------------------------------------------*/
void cadastroPedidos(){//Cadastra novos Clientes


    char CclienteP [50];
    char CPizzasP [50],CbebidasP [50];
    char opc;//CONTROLA A OPÇAO NO BLOCO DAS BEBIDAS
    long long int LLIcpfP;//
    float FprecoPizzas,FprecoBebidasP,FtotalPizzaP,FtotalBebidasP;
    int IqtdPizzasP,IqtdBebidasP;// ARMAZENA A QUANTIDADE DE BEBIDAS E PIZZAS POR PEDIDO
    int existente;// VARIAVEL USADA PARA VERIFICAR SE O CLIENTE ESTA CADASTRADO
    int permisaoCPF;// VARIAVEL USADA PARA VERIFICAR SE O CLIENTE ESTA CADASTRADO
    int op;//ULTILIZADO NO SWITCH CASE PARA ESCOLHA DO MENU
    int menu;// ULTILIZADO NO SWITCH CASE PARA ESCOLHA DO MENU
    int sair;// ULTILIZADO NO WHILE PARA CONTROLE DO LAÇO
    int opAvaliacao = 0;// ULTILIZADO PARA OPCAO DE AVALIACAO


    pintar(240);

        permisaoCPF = 777;// LIBERA O BLOCO DE CADASTRO DE CLIENTES
    do {

        sair = 0;
        menu = 0;
        limparTela();
        printfCenter("\t =================| CADASTRO DE PEDIDOS  |=================  \n",COLUNA);
        pularLinha();
        pularLinha();

 do{
        if (permisaoCPF == 777) {
        FILE *arq;
        printf("\nInsira o CPF do cliente: ");
        scanf("%lld", &LLIcpfP);

        arq = fopen("C:\\PizzariaPIM\\bin\\arquivos\\CadastroClientes.dat","rb");
            if (arq == NULL){

                printf ("Problemas na abertura do arquivo!\n");
            }else{

            while (fread(&clientes,sizeof(CLIENTES),1,arq)==1){

                if (clientes.LLIcpfC == LLIcpfP){
                    pedidosnovos.LLIcpfP  = clientes.LLIcpfC;
                    strcpy(pedidosnovos.CclienteP,clientes.CclienteC);
                    existente = 1;
                }
            }
            }
        if(existente!=1) {// CASO O CLIENTE NÃO ESTEJA CADASTRADO
                    char opcl;
                    printf("\nCliente nao cadastrado!\n");
                    pause();
                    pularLinha();
                    pularLinha();
                    limparBuff();
                    printf("\nDeseja adicionar agora? [S/N]");
                    scanf("%c",&opcl);
                    printf("\n %d ", opcl);

                    if (opcl=='S'){

                        opcl = 's';
                    }

                    if (opcl == 's'){
                         cadastroClientes();// FUNÇÃO PARA CADASTRO DE CLIENTES
                         LinhaTraco();
                         printf("\n \t\t\tCliente Cadastrado!!!");
                         LinhaTraco();
                         LimparTela();
                         printfCenter("\t =================| CADASTRO DE PEDIDOS  |=================  \n",COLUNA);
                         pularLinha();
                         pularLinha();
                         existente = 0;
                         permisaoCPF = 777;
                         fclose(arq);
                     }else {
                         menu = 1;
                     }
        }
            fclose(arq);
        }
        }while (existente!=1);

        if (existente = 1) {

        do {//VERIFICA O SABOR DA PIZZA E REALIZA O PEDIDO
            limparBuff();
            printf("\nCliente: %sCPF:%lld\n",pedidosnovos.CclienteP,pedidosnovos.LLIcpfP);
            printf ("\nInsira o Sabor da Pizza: ");
            fgets  (CPizzasP,sizeof (CPizzasP), stdin);
            strupr(CPizzasP);
            limparBuff();

            FILE *arq;
            arq = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroPizzas.dat","rb");

                if (arq == NULL){// VERIFICA SE O ARQUIVO EXISTE

                    printf ("Problemas na abertura do arquivo!\n");
                }else{

                    while (fread(&sabores,sizeof(PIZZAS),1,arq)==1){

                        if (strncmp(sabores.CsaborC ,CPizzasP,5)==0){
                            strcpy(CPizzasP,sabores.CsaborC);
                            FprecoPizzas = sabores.FprecoC;
                            existente = 10;
                        }
                    }
                }
        if(existente!=10) {
                    int opcl;
                    LinhaTraco();
                    pularLinha();
                    printf("\n\t\t\t\tPizza nao cadastrada!\n");
                    pularLinha();
                    LinhaTraco();
                    pularLinha();
                    pularLinha();
                    pause();
                    existente = 5;
        }else {
            printf("\nSabor:%sPreco: %.2f", CPizzasP,FprecoPizzas);
            pularLinha();
            existente = 10;
        }
        fclose(arq);
        }while (existente!=10);

        strcpy (pedidosnovos.CpizzasP, CPizzasP); //PASSA O SABOR PARA A ESTRUTURA DE PEDIDOS

        pedidosnovos.FprecoPizzaP = FprecoPizzas;//ARMAZENA O VALOR UNITARIO DA PIZZA

        printf ("\nQuantidade: ");//135
        scanf("%d", &IqtdPizzasP);
        limparBuff();
        pedidosnovos.IqtdPizzasP=IqtdPizzasP;// ARMAZENA A QUANTIDADE DE PIZZAS DO MESMO SABOR

        FtotalPizzaP = (IqtdPizzasP*FprecoPizzas);// REALIZA A SOMA DO PREÇO PELA QUANTIDADE DAS PIZZAS

        printf("\nInserir Bebida? [S/N]  ");// PERGUNTA SE DESEJA ADICIONAR BEBIDA OU NÃO
        scanf("%c",&opc);
        limparBuff();
        if (opc == 83|| opc == 115){ //83 == S e 115 == s


           do {
            limparBuff();
            printf("\nInsira a Bebida: ");
            fgets  (CbebidasP,sizeof (CbebidasP), stdin);
            strupr(CbebidasP);

            FILE *arqBebidas;
            arqBebidas = fopen("C:\\Gerenciamento de Estoque\\bin\\arquivos\\CadastroBebidas.dat","rb");

                if (arqBebidas == NULL){// VERIFICA SE O ARQUIVO EXISTE
                    printf ("Problemas na abertura do arquivo!\n");
                }else{
                while (fread(&bebidas,sizeof(BEBIDAS),1,arqBebidas)==1){

                    if ((strncmp(bebidas.CbebidaC ,CbebidasP,5)==0)){
                        strcpy(CbebidasP,bebidas.CbebidaC);
                        FprecoBebidasP = bebidas.FprecoBebidaC;
                        existente = 1;
                    }
                }
                }
        if(existente!=1) {
            int opcl;
            LinhaTraco();
            pularLinha();
            printf("\n\t\t\t\tBebida nao cadastrada!\n");
            pularLinha();
            LinhaTraco();
            pularLinha();
            pularLinha();
            pause();
            existente = 0;
        }else {
            printf("\nBebida:%s Preco: %.2f", CbebidasP,FprecoBebidasP);
            pularLinha();
            existente = 1;
        }
        fclose(arqBebidas);
        }while (existente!=1);

        strcpy (pedidosnovos.CbebidasP, CbebidasP);
        pedidosnovos.FprecoBebidaP = FprecoBebidasP;

        limparBuff();
        printf("\nQuantidade: ");
        scanf("%d",&IqtdBebidasP);
        pedidosnovos.IqtdbebidasP = IqtdBebidasP;
        FtotalBebidasP = (IqtdBebidasP*FprecoBebidasP);

        limparBuff();

        }else {
           strcpy(pedidosnovos.CbebidasP, "NENHUMA  ");
           FtotalBebidasP = 0;
           pedidosnovos.IqtdbebidasP = 0;
           pedidosnovos.FprecoBebidaP = 0;

        }
        pedidosnovos.IverificadorC=1;

        limparBuff();
        int desc=0;//VARIAVEL PARA ESCOLHA DA PROMOÇÃO
        float auxdes;//ULTILIZADA PARA AUXILIAR NA PROMOÇÃO
        printf("\nDeseja adiconar desconto?[S/N]");
        scanf("%c",&desc);

        if (desc == 83|| desc == 115){ //83 == S e 115 == s

             auxdes = (FtotalPizzaP+FtotalBebidasP);// ARMAZENA O VALOR TOTAL DO PEDIDO
             pedidosnovos.FtotalP = promoDesconto(auxdes);// ARMAZENA O VALOR TOTAL DO PEDIDO
             strcpy(pedidosnovos.CPromocapP,"SIM");

        }else{
            strcpy(pedidosnovos.CPromocapP,"NAO");
            pedidosnovos.FtotalP = (FtotalPizzaP+FtotalBebidasP);// ARMAZENA O VALOR TOTAL DO PEDIDO
            pedidosnovos.FvalordescontoP = 0;
            pedidosnovos.IpromocaoP = 0;
        }
        limparBuff();
        printf("\nAvaliar Atentimento? [S/N]\n ");
        scanf("%c",&opAvaliacao);

        if (opAvaliacao == 83|| opAvaliacao == 115){ //83 == S e 115 == s

        int opcAvaliacao;
        LinhaTraco();
        printf("\n\t\tAvaliacao do Atendimento ");
        pularLinha();
        limparBuff();
        printf("\n 0 - RUIM \t 1 - BOM \t 2 - EXCELENTE\n ");
        scanf("%d",&opcAvaliacao);

        switch (opcAvaliacao){
            case 0:{
                strcpy(avaliacao.CavaliacaoC, "RUIM");

            }break;
            case 1:{
                strcpy(avaliacao.CavaliacaoC, "BOM");

            }break;
            case 2:{
                strcpy(avaliacao.CavaliacaoC, "EXCELENTE");

            }break;
            default: {
                printf("\nOpcao Invalida");
            }
        }

            gravaObservacaoStrucAvaliacao();
        }

        limparBuff();
        menu = 0;
        printf ("\n1- Cancelar ");
        printf ("\n2- Corrigir ");
        printf ("\n3- Adicionar outra pizza para o mesmo Cliente?");
        printf ("\n4- Adicionar outro pedido para outro Cliente? ");
        printf ("\n5- Concluir e voltar ao menu anterior:\n");
        scanf  ("%d",&menu);
        limparBuff();
}
    switch (menu){

            case 1:{//CANCELAR

            pedidosnovos.IverificadorC = 0;
                   sair = 1;

            }break;
            case 2:{//CORRIGIR

            pedidosnovos.IverificadorC = 0;
                    sair = 0;

            }break;
            case 3:{//ADICIONAR OUTRA PIZZA OU PEDIDO PARA O MESMO CLIENTE
                gravarArquivosStructPedidos(pedidosnovos);
                gravarArquivosStructAvaliacao(avaliacao);
                existente = 1;
            sair = 0;
            permisaoCPF = 0000;
            }break;

            case 4:{//ADICIONAR OUTRO PEDIDO PARA CLIENTE DIFERENTE
            gravarArquivosStructPedidos(pedidosnovos);
            gravarArquivosStructAvaliacao(avaliacao);
            sair = 0;
            existente = 777;
            permisaoCPF = 777;

            }break;

            case 5:{//FINALIZAR E SAIR
            gravarArquivosStructPedidos(pedidosnovos);
            gravarArquivosStructAvaliacao(avaliacao);
            sair = 1;

            }break;
    }
    }while (sair!=1);

}
/*----------------------------------------------------------------------------------------------------------------------*/
void removerPedidos(){//REMOVE OS CLIENTES CADASTRADOS
loginMenu();
limparTela();
limparBuff();
removerArqStructPedidos(pedidosnovos);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void pesquisarPedidos(){//PESQUISAR PEDIDOS
    setlocale(LC_ALL,"Potuguese");
    limparTela();
    getchar();
    printfCenter("\t =================| PESQUISA DE PEDIDOS  |=================  \n",COLUNA);
    pularLinha();
    pesquisarArqPedidos(pedidosnovos);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void listarPedidos(){//LISTAR OS PEDIDOS CADASTRADOS
    limparTela();
    printfCenter("\t =================| PEDIDOS CADASTRADOS  |=================  \n",COLUNA);
    printf ("\n\n");
    listarArquivoStructPedidos(pedidosnovos);
getchar();

            }
/*----------------------------------------------------------------------------------------------------------------------*/
void MenuAvaliacao(){
        int menu;
        int op;
do {
        limparTela();
        pintar(240);
        pularLinha();
        pularLinha();
        pularLinha();

     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
     printf("\t\t\t%c       AVALIACAO DO ATEDIMENTO       %c\n",3002,3002);
     printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);

        printf ("\n\n\n\t 1 - LISTAR TODAS AVALIACOES ");
        pularLinha();
        printf ("\n\t 2 - LISTAR AVALIACOES POR CATEGORIA");
        pularLinha();
        printf ("\n\t 3 - FINALIZAR E VOLTAR AO MENU ANTERIOR: \n\n");
        LinhaIgual();
        pularLinha();
        scanf  ("%d",&op);

        switch (op){

            case 1:{
            limparBuff();
            ListarAvaliacoes();
            op = 0;


            }break;
            case 2:{

            ListarAvaliacoesCategoria();

            }break;
            case 3:{
            op = 3;


            }break;

}
    }while (op!=3);

}
/*----------------------------------------------------------------------------------------------------------------------*/
void ListarAvaliacoes(){
    limparTela();
    printfCenter("\t =================| AVALIACOES |=================  \n",COLUNA);
    printf ("\n\n");

     FILE *arq;
    arq = fopen("C:\\PizzariaPIM\\bin\\arquivos\\Avaliacao.dat","rb");
    if (arq == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{

          while (fread(&avaliacao,sizeof(AVALIACAO),1,arq)==1){

            printf("\nAvaliacao: %s\n",avaliacao.CavaliacaoC);
            printf("\nObservacao:\n->>%s",avaliacao.CobservacaoC);
            pularLinha();
            LinhaTraco();
            pularLinha();
          }
        pause();

}
}
/*----------------------------------------------------------------------------------------------------------------------*/
void ListarAvaliacoesCategoria(){
    int opavali;// OPCAO DE AVALIACOES
    int contarAvaliacoes;// CONTAGEM DAS AVALIAÇOES
    limparTela();
    printfCenter("\t =================| AVALIACOES POR CATEGORIA |=================  \n",COLUNA);
    printf ("\n\n");

     FILE *arq;
    arq = fopen("C:\\PizzariaPIM\\bin\\arquivos\\Avaliacao.dat","rb");
    if (arq == NULL){

        printf ("Problemas na abertura do arquivo!\n");
    }else{

        contarAvaliacoes = 0;
        printf("\n   ESCOLHA UMA CATEGORIA:");
        printf ("\n\n\n\t 1 - RUIM ");
        pularLinha();
        printf ("\n\t 2 - BOAS");
        pularLinha();
        printf ("\n\t 3 - EXCELENTE");
        pularLinha();
        printf ("\n\t 4 - VOLTAR AO MENU ANTERIOR: \n\n");
        LinhaIgual();
        pularLinha();
        limparBuff();
        scanf  ("%d",&opavali);

        switch(opavali){
            case 1:{
                    limparTela();
                    printfCenter("\t =================| AVALIACOES RUINS |=================  \n",COLUNA);

                      while (fread(&avaliacao,sizeof(AVALIACAO),1,arq)==1){
                        if ((strcmp(avaliacao.CavaliacaoC, "RUIM"))==0){
                        printf("\nAvaliacao: %s\t",avaliacao.CavaliacaoC);
                        printf("Observacao:\n->>%s",avaliacao.CobservacaoC);
                        pularLinha();
                        LinhaTraco();
                        contarAvaliacoes++;
                        }
                      }
            pularLinha();
            pularLinha();
            pularLinha();
            printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
            printf("\n\t\t\t%c          AVALIACOES RUINS: %d        %c",3002,contarAvaliacoes,3002);
            printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);
            pularLinha();

            }break;

            case 2:{
                    limparTela();
                    printfCenter("\t =================| AVALIACOES BOAS |=================  \n",COLUNA);

                       while (fread(&avaliacao,sizeof(AVALIACAO),1,arq)==1){
                        if ((strcmp(avaliacao.CavaliacaoC, "BOM"))==0){
                        printf("\nAvaliacao: %s\t",avaliacao.CavaliacaoC);
                        printf("Observacao:\n->>%s",avaliacao.CobservacaoC);
                        pularLinha();
                        LinhaTraco();
                        contarAvaliacoes++;
                        }
                      }
             pularLinha();
            pularLinha();
            pularLinha();
            printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
            printf("\n\t\t\t%c          AVALIACOES BOAS: %d         %c",3002,contarAvaliacoes,3002);
            printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);
            pularLinha();

            }break;

            case 3:{
                    limparTela();
                    printfCenter("\t =================| AVALIACOES EXCELENTES |=================  \n",COLUNA);

                        while (fread(&avaliacao,sizeof(AVALIACAO),1,arq)==1){
                        if ((strcmp(avaliacao.CavaliacaoC, "EXCELENTE"))==0){
                        printf("\nAvaliacao: %s\t",avaliacao.CavaliacaoC);
                        printf("Observacao:\n->>%s",avaliacao.CobservacaoC);
                        pularLinha();
                        LinhaTraco();
                        contarAvaliacoes++;
                        }
                        }
            pularLinha();
            pularLinha();
            pularLinha();
            printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
            printf("\n\t\t\t%c       AVALIACOES EXCELENTES: %d      %c",3002,contarAvaliacoes,3002);
            printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);
            pularLinha();

            }break;

            case 4:{

            }break;

            default:{
                        LinhaTraco();
                        printfCenter("Opcao Invalida!!!",LINHA);
                        pularLinha();
                        pularLinha();
                        LinhaTraco();
                        pularLinha();
                        pause();
            }
            }
            }
        pularLinha();
        pause();

}



/*----------------------------------------------------------------------------------------------------------------------*/
void limparBuff(){

    setbuf(stdin,NULL);

}
/*----------------------------------------------------------------------------------------------------------------------*/
void loginMenu (){
            limparTela();
            char CnomeLoginL [81]; //strcpy(CnomeLoginL , "secreto");
            char CnomeIseridoL [81];
            char CsenhaL [81];//
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

        limparBuff();//LIMPA O BUFF DO TECLADO
        gotoxy(15,13);// DETERMINA AONDE O CURSOR IRÁ SE POSICIONAR
        int sair =0;//PERMITE SAIR DO LAÇO WHILE
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


        if (strcmp (CnomeLoginL, CnomeIseridoL)==0 & strcmp (CsenhaL, CsenhainseridaL)==0)
        {
             LimparTela();
            printfCenter("\n Login efetuado com sucesso\n",LINHA);
            pularLinha();
            system("PAUSE");
            senhaCorreta = 1;
          //break;

        }else {
            pularLinha();
            pularLinha();
            pularLinha();

             printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",3017,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3003);
             printf("\t\t\t%c   Senha Incorreta! Tente novamente  %c\n",3002,3002);
             printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3016,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3021,3004);

             senhaCorreta = 0;
            getchar();
            x=0;//resetar vetor da senha.

        }

            limparBuff();

    }while (senhaCorreta!=1);


    }
/*----------------------------------------------------------------------------------------------------------------------*/
void LinhaAsterisco (){
    for (int x = 0; x<80;x++)
    {
        printf ("*");
    }
}
/*----------------------------------------------------------------------------------------------------------------------*/
void limparTela (){
              system ("cls");

}
/*----------------------------------------------------------------------------------------------------------------------*/
void LinhaTraco (){//Exibe na tela tracos "-"
    for (int x = 0; x<80;x++)
    {
        printf ("-");
    }
}
/*----------------------------------------------------------------------------------------------------------------------*/
void LinhaIgual (){//Exibe o sinal de igual "="
    for (int x = 0; x<80;x++)
    {
        printf ("=");
    }
}
/*----------------------------------------------------------------------------------------------------------------------*/
void printfCenter(char *texto, int linha){//Centraliza o texto na Tela
int coluna = (COLUNA / 2) - strlen(texto);
gotoxy(coluna, linha);
printf("%s", texto);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void pularLinha(){//Pula 1 linha
    printf ("\n");
}
/*----------------------------------------------------------------------------------------------------------------------*/
void pintar(int cor){
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, cor);
}
/*----------------------------------------------------------------------------------------------------------------------*/
void telaInicial(){

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
/*----------------------------------------------------------------------------------------------------------------------*/
void LimparTela(){
    system("cls");
}
/*----------------------------------------------------------------------------------------------------------------------*/
void pause (){

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
void linha(){
    int x=0; for(x=0;x<COLUNA;x++){    printf("%c",205);
    }
}
/*----------------------------------------------------------------------------------------------------------------------*/
void coluna(int posicao){
    int x; for(x=0;x<=LINHA;x++){    gotoxy(posicao,x);    printf("%c",186); }

}
/*----------------------------------------------------------------------------------------------------------------------*/
void caixaDados(int tamanho){

for (int x=0;x<tamanho;x++){
            printf("%c",BLACK);
        }
}

float promoDesconto(float valor){
    float result;
    float aux,porcentagem;
    int opP;
    int porcentagem_Informada;
    do{

    limparBuff();
    LinhaTraco();
    printf("\nEscolha o Desconto");
    printf("\n1 - 10%% OFF");
    printf("\n2 - 20%% OFF");
    printf("\n3 - 40%% OFF");
    printf("\n4 - Informe o Desconto\n");
    printf("\n5 - Cancelar  Desconto\n");
    LinhaTraco();
    scanf("%d",&opP);

    switch (opP){
        case 1:{// CALCULO DE 10% OFF
            result = valor*0.9;
            pedidosnovos.IpromocaoP = 10;
            pedidosnovos.FvalordescontoP = valor*0.1;
        }break;
        case 2:{// CALCULO DE 20% OFF
            result = valor*0.8;
            pedidosnovos.IpromocaoP = 20;
            pedidosnovos.FvalordescontoP = valor*0.2;
        }break;
        case 3:{// CALCULO DE 40% OFF
            result = (valor*0.6);
            pedidosnovos.IpromocaoP = 40;
            pedidosnovos.FvalordescontoP = valor*0.4;
        }break;
        case 4:{
            limparBuff();
            printf("\nInforme quantos %% de desconto: ");
            scanf("%d",&porcentagem_Informada);
            aux = (valor/100)*porcentagem_Informada;
            pedidosnovos.IpromocaoP = porcentagem_Informada;
            pedidosnovos.FvalordescontoP = aux;
            result = valor-aux;

        }break;
        case 5:{// NAO REALIZA A FUNÇÃO
            result = valor;
        }break;
        default:{
            printf("\nOpcao invalida");
            result = 0;
        }
    }
}while (result==0);

return result;
}

void pintarTela(){

    pintar(240);
    printf ("\n");
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
