#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    float notas[50];
    float media;
} pessoa;

void limpaBuffer();

pessoa obterDadosAluno();

void obterMedia(pessoa aluno);

int main(){
    int opcao = 0;

    pessoa alunos[10];

    int indiceAlunos = 0;

    while(opcao != 3){
        printf("#######################\n");
        printf("# Sistema educacional #\n");
        printf("#######################\n");
        printf("1 - Adicionar um aluno\n");
        printf("2 - Calcular média de notas de um aluno\n");
        printf("3 - Sair\n\n");
        printf("Informe sua opção: ");
        scanf("%d", &opcao);

        limpaBuffer();

        if(opcao == 1){
            alunos[indiceAlunos] = obterDadosAluno();
            indiceAlunos++;
        }

        if(opcao == 2){
            char nomeParaBusca[50];
            int indiceEncontrado = -1;
            printf("Informe o nome para busca: ");
            fgets(nomeParaBusca, sizeof(nomeParaBusca), stdin);

            for(int i = 0; i < indiceAlunos; i++){
                if(strcmp(nomeParaBusca, alunos[i].nome) == 0){
                    obterMedia(alunos[i]);
                }
            }

        }
    }
}

void limpaBuffer(){
    while(getchar() != '\n');
}

pessoa obterDadosAluno(){
    pessoa aluno;
    char sOuN = 's';
    int indiceNotas = 0;
    float accNotas = 0;
    printf("Informe seu nome: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    while(sOuN == 's'){
        printf("Informe uma nota: ");
        scanf("%f", &aluno.notas[indiceNotas]);
        limpaBuffer();
        printf("Deseja informar outra nota? (s ou n)");
        sOuN = getchar();
        accNotas += aluno.notas[indiceNotas];
        indiceNotas++;
    }
    aluno.media = accNotas / indiceNotas;

    return aluno;
}

void obterMedia(pessoa aluno){
    printf("Média = %f para aluno %s\n", aluno.media, aluno.nome);
    printf("Digite ENTER para continuar");
    getchar();
}