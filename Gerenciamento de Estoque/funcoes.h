#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

void telaInicial();
void pause ();
void loginMenu ();
void MenuPizza ();
void verificador ();
void listarPizza();
void cadastroPizza();
void removerPizza();
void pesquisarPizza();
void MenuBebidas();
void cadastroBebidas();
void removerBebidas();
void pesquisarBebidas();
void listarBebidas();
void editarBebidas();
void limparTela ();
void LinhaIgual ();
void LinhaTraco ();
void gotoxy(int x, int y);
void printfCenter(char *texto, int linha);
void pularLinha();
void limparBuff();
void editarPizza();
void logoInstenso();
void pintar(int cor);
void linha();
void coluna(int posicao);
void caixaDados(int tamanho);
void MenuProdutos();
void cadastroProduto();
void RemoverProduto();
void PesquisarProdutos();
void listarProdutos();
void editarproduto();
void AtualizarSaldoProduto();
void logoTopo();
void gravarArquivosSruct (struct PIZZAS nomeStruct, char* endereco);
void listarArquivoStruct(struct PIZZAS nomeStruct, char* endereco);
void pesquisarArq (struct PIZZAS nomeStruct, char* endereco);
void removerArqStruct(struct PIZZAS nomeStruct, char* endereco);
void editarArqStruct (struct PIZZAS nomeStruct, char* endereco);
void enderecos();
void pintarTelas();
void MenuProdutos();

#endif // FUNCOES_H_INCLUDED
