#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Exercí­cio 3: Cadastro de Alunos
Crie uma struct Aluno com campos como nome, idade e notas. 
Permita ao usuário cadastrar vários alunos e armazená-los em um array. 
Em seguida, permita que o usuário pesquise um aluno pelo nome e exiba suas informações.
*/

typedef struct{
    char nome[50];
    float notas[50];
    int idade;
    int indiceNotas;
} pessoa;

pessoa adicionarAluno();
//pessoa buscarAluno(int indiceAlunos, pessoa alunos);
void limpaBuffer();
void enter();

int main(){

    setlocale(LC_ALL,"portuguese");

    pessoa alunos[10];
    int opcao, indiceAlunos = 0;
    pessoa alunoEncontrado;
    pessoa alunoProcurado;
    char flagEncontrado = 1;

    while(opcao != 3){
        printf("1 - Adicionar aluno \n");
        printf("2 - Buscar aluno \n");
        printf("3 - sair \n");

        printf("Digite uma opcao: ");
        scanf("%i", &opcao);
        limpaBuffer();

        if(opcao == 1){
            char sOuN = 's';
            
            while(sOuN == 's'){
                alunos[indiceAlunos] = adicionarAluno();

                printf("Deseja adicionar outro aluno? ");
                sOuN = getchar();
                limpaBuffer();

                indiceAlunos++;
            }
        } else if(opcao == 2){
            printf("Digite o nome do aluno procurado: ");
            fgets(alunoProcurado.nome, sizeof(alunoProcurado.nome), stdin);

            for(int i = 0; i < indiceAlunos; i++){
                if(strcmp(alunoProcurado.nome, alunos[i].nome) == 0){
                    printf("Aluno encotrado!\n");
                    alunoEncontrado = alunos[i];
                    flagEncontrado = 0;
                }    
            }

            if(flagEncontrado == 1){
                printf("Aluno não encontrado! \n");
                enter();
            } else {
                enter();
                printf("Nome do aluno %s", alunoEncontrado.nome);
                printf("Idade do aluno %i\n", alunoEncontrado.idade);
                
                for(int i = 0; i < alunoEncontrado.indiceNotas; i++){
                    printf("Aluno nota %d: %.2f\n", i + 1, alunoEncontrado.notas[i]);
                }
            }
        }
    }
}


pessoa adicionarAluno(){
    pessoa aluno;
    char sOuN = 's';
    aluno.indiceNotas = 0;

    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);

    printf("Digite a idade do aluno: ");
    scanf("%i", &aluno.idade);
    limpaBuffer();

    while(sOuN != 'n'){
        printf("Digite uma nota do aluno: ");
        scanf("%f", &aluno.notas[aluno.indiceNotas]);
        limpaBuffer();

        aluno.indiceNotas++;

        printf("Você deseja adicionar mais notas? ");
        sOuN = getchar();
        limpaBuffer();
    }

    return aluno;
}

/*pessoa buscarAluno(int indiceAlunos, pessoa alunos){
    pessoa alunoEncontrado;
    pessoa alunoProcurado;

    printf("Digite o aluno a ser procurado: ");
    fgets(alunoProcurado.nome, sizeof(alunoProcurado.nome), stdin);

    for(int i = 0; i < indiceAlunos; i++){
        if(strcmp(alunoProcurado.nome, alunos[i].nome));
    }

    return alunoEncontrado;
}*/

void limpaBuffer(){
    while(getchar() != '\n');
}

void enter(){
    printf("Digite ENTER para continuar!");
    getchar();
}