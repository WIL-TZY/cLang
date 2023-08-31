#include <stdio.h>

// Headers
int depositar(int saldo);
int sacar(int saldo);

int main() {
    float saldo = 0, sair = 0, temConta = 0;
    char escolha[1], nome[10] = "";

    printf("Bem vindo(a) ao banco.\n");

    while (sair != 1) {
        printf("1 - Abrir conta\n2 - Depósito\n3 - Saque\n4 - Saldo\n5 - Sair\n\n");
        printf("Digite um número para acessar um dos menus: ");
        // O espaço extra antes do "%c" é p/ corrigir um lance chatinho do C 
        // Na hora de enviar o input, o usuário digita "enter" que é interpretado como um caractere de nova linha
        // É necessário adicionar um espaço antes do especificador de formato %c na chamada scanf()
        // Este espaço instruirá o scanf() a pular quaisquer caracteres de espaço em branco iniciais (incluindo a nova linha) antes de ler o caractere
        scanf(" %c", escolha);
        printf("\n\n");
        if (temConta != 1) { // Não tem conta
            if (escolha[0] == '5') {
                goto fim;
            }
            if (escolha[0] == '1') {
                printf("Para abrir uma conta, digite seu nome: \n");
                scanf("%s", nome);
                printf("Certo, %s. Informe agora um valor inicial de depósito para ser o seu saldo: \n", nome);
                scanf("%d", &saldo);
                temConta = 1;
            }
            else if ((escolha[0] == '2' || escolha[0] == '3' || escolha[0] == '4') && sair == 0) {
                printf("Você primeiro precisa abrir uma conta para acessar esse menu!\n\n");
            }
        }

        else { // Tem conta
            if (escolha[0] == '1') {
                printf("Você já tem uma conta! Por favor, escolha outra opção.\n");
            }
            if (escolha[0] == '2') {
                saldo = depositar(saldo);
            }

            if (escolha[0] == '3') {
                saldo = sacar(saldo);
            }

            if (escolha[0] == '4') {
                printf("Seu saldo é: R$%d,00\n\n", saldo);
            }

            // Roda depois de tentar qualquer uma das escolhas
            printf("%s, seu saldo é: R$%d,00\n\n", nome, saldo);
        }

        if (escolha[0] == '5') {
            fim:
                printf("Até a próxima! Espero encontrá-lo(a) novamente.\n");
                sair = 1;
        }

        if (escolha[0] != '1' && escolha[0] != '2' && escolha[0] != '3' && escolha[0] != '4' && escolha[0] != '5') {
            printf("Dígito inválido! Tente novamente.\n\n");
        }
    }

    return 0;
}

int depositar(int saldo) {
    int deposito;
    printf("Digite uma valor a ser depositado: ");
    scanf("%d", &deposito);
    saldo = saldo + deposito;
    return saldo;
}

int sacar(int saldo) {
    int saque;
    printf("Digite uma valor a ser sacado: ");
    scanf("%d", &saque);
    saldo = saldo - saque;
    return saldo;
}