// OBS: sizeof() pega a string até o \0, strlen() pega somente a quantidade de caracteres
// Portando, em um char[10], sizeof() devolve 10, enquanto que strlen() devolve 9
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float notas[2];
    int idade; 
    int qtdNotas;
} pessoa;

// Headers
void limpaBuffer();
pessoa obterDados();
void exercicio1();
void exercicio2();
void exercicio3();
void exercicio4();

int main() {
    
    //exercicio1();
    //exercicio2();
    exercicio3();
    //exercicio4();
   
}

 void exercicio1() {
    // Exercicio1 - Calculadora simples

    printf("#######################\n");
    printf("# Exercicio 1 #\n");
    printf("#######################\n");

    char operador;
    int operando1, operando2;
    float resultado = 0.0;

    printf("Digite o primeiro número: ");
    scanf("%d", &operando1);

    printf("Digite o segundo número: ");
    scanf("%d", &operando2);
    limpaBuffer();

    printf("\n\n");
    
    printf("Agora digite uma das operações ( + - * / ): ");
    operador = getchar();

    limpaBuffer();

    // Verifica qual foi a operação selecionada
    if (operador == '+') {
        resultado = operando1 + operando2;
    }

    else if(operador == '-') {
        resultado = operando1 - operando2;	
    }

    else if (operador == '/'){
        resultado = operando1 / operando2;	
    }
    else if (operador == '*') {
        resultado = operando1 * operando2;
    }	

    printf("\n\n");
    
    printf("Resultado:\n\n");
    printf("%d %c %d = %.2f", operando1, operador, operando2, resultado);
    
    printf("\n\n");
}

void exercicio2() {
    // Exercicio2 - Contagem de vogais
/*
    Contar o número de vogais em uma frase.
*/
    printf("#######################\n");
    printf("# Exercicio 2 #\n");
    printf("#######################\n");

    char frase[50];
    char vogais[50] = "aeiouAEIOU";
    int contador;
    printf("Escreva a frase desejada: \n");

    // Equivalente ao scanf para strings
    fgets(frase, sizeof(frase), stdin);
    
    for (int i = 0; i < strlen(frase); i++) {
        for (int j = 0; j < strlen(vogais); j++) {
            contador++;
        }
    }
    printf("\n\n");
    printf("Número de vogais: %d\n", contador);

}

void exercicio3() {
    // Exercicio3 - Cadastro de alunos
/*
    Crie uma estrutura Aluno, com campos como nome, idade e notas. 
    Permita ao usuário cadastrar vários alunos e armazená-los em um array.
    Em seguida, permita que o usuário pesquise um aluno pelo nome e exiba suas informações.
*/

    pessoa alunos[10];
    char opcao = 'f';
    int indiceAlunos = 0;
    int indiceNotas = 0;

    opcao = getchar();

    while (opcao != 'c') {
        //limpaBuffer();

        printf("Digite uma opção: \n");
        printf("a - cadastrar aluno\n");
        printf("b - buscar aluno\n");
        printf("c - sair\n");
        opcao = getchar();
        limpaBuffer();

        if (opcao == 'a') {
            alunos[indiceAlunos] = obterDados();

            //indiceAlunos++;
        }

        if (opcao == 'b') {
            int indice = -1; 
            char busca[50];
            printf("Escreva o nome para ser buscado: \n");
            fgets(busca, sizeof(busca), stdin);

            for (int i = 0; i < indiceAlunos; i++) {
                int buscaIgualANome = !strcmp(busca, alunos[i].nome);
                // Se a string for igual... A função strcmp() retornará 0 
                // O que torna a condição falsa
                // Portanto, para fazer entrar na condição, inverte seu valor com a negação (!)
                // Poderia também fazer a condição dessa forma: (strcmp(busca, alunos[i].nome) == 0)
                if (buscaIgualANome) {
                    // Encontrou o aluno (ativa a flag)
                    indice = i;
                }
                if (indice != -1) {
                    printf("O aluno %s tem %i anos.\n", alunos[indice].nome, alunos[indice].idade);
                    for (int j = 0; j < alunos[i].qtdNotas; j++) {
                       printf("\n%.2f - (nota %i)\n", alunos[indice].notas[j], j + 1);
                    }
                }
                else {
                    printf("Aluno não encontrado!");
                }
            }
        }
    }
}

void limpaBuffer(){
    while(getchar() != '\n');
}

pessoa obterDados() {
    pessoa aluno;
    aluno.qtdNotas = 0;
    char sOuN = 's';
    printf("Escreva o nome do aluno: \n");
    // Adiciona à variável nome (alunos[indiceAlunos].nome) o que foi adicionado ao buffer de entrada
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    printf("Digite a idade do aluno: \n");
    scanf("%i", &aluno.idade);
    limpaBuffer();

    while(sOuN == 's') {
        printf("Digite a nota do aluno: ");
        scanf("%f", &aluno.notas[aluno.qtdNotas]);
        limpaBuffer();

        printf("Deseja digitar mais notas? (s ou n)");
        sOuN = getchar();
        aluno.qtdNotas++;
    }

    return aluno;
}

void exercicio4() {

}