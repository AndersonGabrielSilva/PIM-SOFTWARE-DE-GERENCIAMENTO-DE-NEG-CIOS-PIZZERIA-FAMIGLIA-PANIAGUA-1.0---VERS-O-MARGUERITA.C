#ifndef PIZZARIA_H_INCLUDED
#define PIZZARIA_H_INCLUDED

void MenuCliente();
void MenuPedidos();
void loginMenu ();
void verificador ();
void limparTela ();
void limparBuff();
void LinhaIgual ();
void LinhaTraco ();
void gotoxy(int x, int y);
void printfCenter(char *texto, int linha);
void pularLinha();
void limparBuff();
void pintar(int cor);
void telaInicial();
void caixaDados(int tamanho);
void coluna(int posicao);
void linha();
void pause ();
void LimparTela();
void removerPedidos();
void pesquisarPedidos();
void listarPedidos();
void  editarPedidos();
float promoDesconto(float valor);
void gravaObservacaoStrucAvaliacao();
void MenuAvaliacao();
void ListarAvaliacoes();


#endif // PIZZARIA_H_INCLUDED
