#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

void limpabuffer();

int main(){
    time_t currentTime;
    struct tm *localTime;

    currentTime = time(NULL);
   
    localTime = localtime(&currentTime);

    int opcao = -1, sounNO = 0;
    char nomeprojeto[50] = "Meu Projeto 01";
    char nvnome[50];

    typedef struct{
        int num;
        char nome[20];
        char funcao[20];
    } people;

    people pessoa[2];
    int qntdp;

    setlocale(LC_ALL,"Portuguese_Brazil");

    while(opcao != 0){ 
    printf("#########################################################################################################\n");
    printf("#                                                                                                       #\n");
    printf("#             Gerenciador de Projetos - UnDF                                                            #\n");
    printf("#                                                                                                       #\n");
    printf("#             Digite a opcao desejada:                                                                  #\n");
    printf("#                                                                                                       #\n");
    printf("#             1-Editar Nome do Projeto                                                                  #\n");
    printf("#             2-Adicionar Integrante                                                                    #\n");
    printf("#             3-Remover Integrante                                                                      #\n");
    printf("#             4-Visualizar Integrantes                                                                  #\n");
    printf("#             5-Adcionar Tarefas                                                                        #\n");
    printf("#             6-Remover Tarefa                                                                          #\n");
    printf("#             7-Editar Tarefa                                                                           #\n");
    printf("#             8-Visualizar Andamento da Tarefa                                                          #\n");
    printf("#                                                                                                       #\n");
    printf("#             0-Sair                                                                                    #\n");
    printf("#                                                                                                       #\n");
    printf("#                                                 Brasilia, %02d/%02d/20%02d                                  #\n", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year - 100);
    printf("#                                                                                                       #\n");
    printf("#                                                                Desenvolvedores: Miguel                #\n");
    printf("#########################################################################################################\n");
    scanf("%d", &opcao);
    limpabuffer();
    system("cls");
    

    if (opcao == 1){
        printf("Nome Atual do Projeto: %s\n\n", nomeprojeto);
        printf("Inserir novo nome? 1-Sim 2-Nao\n");
        scanf("%d", &sounNO);
        limpabuffer();
        if(sounNO == 1){
            printf("Digite o novo nome do Projeto:\n");
            // scanf("%s", nomeprojeto);
            fgets(nomeprojeto, sizeof(nomeprojeto), stdin);
            // strcpy(nomeprojeto, nvnome);
            system("cls");
        } else if(sounNO != 1){
            system("cls");
            }
    }

    if(opcao == 2){
        printf("Quantos Integrantes Deseja Adicionar?\t");
        scanf("%d", &qntdp);
        limpabuffer();
        system("cls");
        for(int k = 0; k < qntdp; k++){

           printf("Digite o nome do integrante: %d\n\n", k);
           fgets(pessoa[k].nome, sizeof(pessoa[k].nome), stdin);

           printf("Digite a funcao do integrante %d\n\n", k);
           fgets(pessoa[k].funcao, sizeof(pessoa[k].funcao), stdin);

           pessoa[k].num = k;
           system("cls");
        }
    }

    if(opcao == 4){
        printf("Numero\t\tNome\t\tFuncao\t\n");
        for(int n = 0; n < qntdp; n++){
            printf("%d | nome: %s", pessoa[n].num, pessoa[n].nome);
            printf("  | funcao: %s\n\n", pessoa[n].funcao);
            //printf("%d\t %s%s", pessoa[n].num, pessoa[n].nome, pessoa[n].funcao);
           
        }
        int voltar = 1;
        printf("\nDigite 0 para voltar:");
        scanf("%d", &voltar);
        limpabuffer();
        system("cls");
    }
    
   int pot; // numero do cara que vai ser excluido
    char valnul[5] = "Null";
    int xot = 1;
    if(opcao == 3){
       while(xot == 1){ 
        printf("Digite o numero do integrante que remover: ");
        scanf("%d", &pot);
        limpabuffer();
        for(int k = 0; k < qntdp; k++){
            if(pot == pessoa[k].num){
                strcpy(pessoa[k].nome, valnul);
                strcpy(pessoa[k].funcao, valnul);

            }
        }
        system("cls");
        printf("Integrante Removido. Deseja remover mais algum? 1-sim 2-nao\n");
        scanf("%d",&xot);
        system("cls");
    }
    }

}
}

void limpabuffer(){
    while (getchar() != '\n');
}