#include <stdio.h>

int main() {
    int saldo = 1000;
    char escolha = ''; 
    printf("Bem vindo(a) ao banco.\n Digite um caracter só para ir para algum dos menus.\n(Se não tiver conta, digite 'n' para criar uma.)\n\n");
    printf("MENU:\n ## ABRIR CONTA: 'n' ou 'N' ##)\n## DEPÓSITO: 'd' ou 'D' ##\n ## SAQUE: 's' ou 'S'\n");
    scanf("%s", escolha);
    if (escolha == 'n') {
        char[10] nome = "";
        printf("Para abrir uma conta, digite seu nome: \n");
        scanf("%s", nome);
        printf("Certo, %s. Informe agora um valor inicial de depósito para ser o seu saldo: \n", );
        printf("Olá, %s. Você está em sua conta. Seu saldo: %d.\n", nome, saldo);
        
    };

}