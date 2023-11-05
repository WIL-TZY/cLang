#include <stdio.h>
#include <string.h>

void limpaBuffer();

int main() {
    int opcao = 0;

    char nomes[10][50];
    float notas[10][50];
    float medias[10];
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
            char sOuN = 's';
            int indiceNotas = 0;
            float accNotas = 0;
            printf("Informe seu nome: ");
            fgets(nomes[indiceAlunos], sizeof(nomes[indiceAlunos]), stdin);
            while(sOuN == 's'){
                printf("Informe uma nota: ");
                scanf("%f", &notas[indiceAlunos][indiceNotas]);
                limpaBuffer();
                printf("Deseja informar outra nota? (s ou n)");
                sOuN = getchar();
                accNotas += notas[indiceAlunos][indiceNotas];
                indiceNotas++;
            }
            medias[indiceAlunos] = accNotas / indiceNotas;
            indiceAlunos++;
        }

        if(opcao == 2){
            char nomeParaBusca[50];
            int indiceEncontrado = -1;
            printf("Informe o nome para busca: ");
            fgets(nomeParaBusca, sizeof(nomeParaBusca), stdin);

            for(int i = 0; i < indiceAlunos; i++){
                if(strcmp(nomeParaBusca, nomes[i]) == 0){
                    indiceEncontrado = i;
                }
            }

            if(indiceEncontrado != -1){
                printf("Média = %f para aluno %s\n", medias[indiceEncontrado], nomes[indiceEncontrado]);
            } else {
                printf("Aluno não encontrado\n");
            }
        
            printf("Digite ENTER para continuar");
            getchar();

        }
    }

    return 0;
}

void limpaBuffer() {
    while(getchar() != '\n');
}