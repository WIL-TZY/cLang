#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

// -------- Cabeçalhos -------- //
void limpaBuffer();
void limpaTela();

// --------- Structs ---------- //
typedef struct {
    int num;
    char nome[20];
    char funcao[20];
} Pessoa;

int main() {
    setlocale(LC_ALL,"Portuguese_Brazil");
    
    /* ------------------ Variáveis de data & hora ------------------ */
    // A variável currentTime armazena a hora atual do relógio do sistema
    // Declarada como uma constante pois não há intenções de mudá-la, é uma boa prática
    const time_t currentTime = time(NULL);

    // Ponteiro para struct tm - para facilitar a manipulação de componentes de data e hora
    struct tm *localTime = localtime(&currentTime);
    
    /*----------------------- Outras variáveis ---------------------- */
    int opcao = -1, sOuN = 0;
    char nomeProjeto[50] = "Meu Projeto 01";
    char novoNome[50];

    // Criando duas structs do tipo "Pessoa"
    Pessoa pessoa[2];
    // Contador
    int qtdPessoas;

    /* ----------------------- LOOP PRINCIPAL ----------------------- */
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
        limpaBuffer();
        limpaTela();
        

        if (opcao == 1){
            printf("Nome Atual do Projeto: %s\n\n", nomeProjeto);
            printf("Inserir novo nome? 1-Sim 2-Nao\n");
            scanf("%d", &sOuN);
            limpaBuffer();
            if(sOuN == 1){
                printf("Digite o novo nome do Projeto:\n");
                // scanf("%s", nomeProjeto);
                fgets(nomeProjeto, sizeof(nomeProjeto), stdin);
                // strcpy(nomeProjeto, novoNome);
                limpaTela();
            } else if(sOuN != 1){
                limpaTela();
            }
        }

        if(opcao == 2){
            printf("Quantos Integrantes Deseja Adicionar?\t");
            scanf("%d", &qtdPessoas);
            limpaBuffer();
            limpaTela();
            for(int k = 0; k < qtdPessoas; k++){

            printf("Digite o nome do integrante: %d\n\n", k);
            fgets(pessoa[k].nome, sizeof(pessoa[k].nome), stdin);

            printf("Digite a funcao do integrante %d\n\n", k);
            fgets(pessoa[k].funcao, sizeof(pessoa[k].funcao), stdin);

            pessoa[k].num = k;
            limpaTela();
            }
        }

        if(opcao == 4){
            printf("Numero\t\tNome\t\tFuncao\t\n");
            for(int n = 0; n < qtdPessoas; n++){
                printf("%d | nome: %s", pessoa[n].num, pessoa[n].nome);
                printf("  | funcao: %s\n\n", pessoa[n].funcao);
                //printf("%d\t %s%s", pessoa[n].num, pessoa[n].nome, pessoa[n].funcao);
            
            }
            int voltar = 1;
            printf("\nDigite 0 para voltar: ");
            scanf("%d", &voltar);
            limpaBuffer();
            limpaTela();
        }
        
    int pot; // Número do cara que vai ser excluido
        char valorNulo[5] = "Null";
        int xot = 1;
        if(opcao == 3){
        while(xot == 1){ 
            printf("Digite o numero do integrante a ser removido: ");
            scanf("%d", &pot);
            limpaBuffer();
            for(int k = 0; k < qtdPessoas; k++){
                if(pot == pessoa[k].num){
                    strcpy(pessoa[k].nome, valorNulo);
                    strcpy(pessoa[k].funcao, valorNulo);

                }
            }
            limpaTela();
            printf("Integrante Removido. Deseja remover mais algum? 1-Sim 2-Nao\n");
            scanf("%d",&xot);
            limpaTela();
        }
        }
    }
    printf("\nPrograma Encerrado.\n");
}

void limpaBuffer() {
    while (getchar() != '\n');
}

void limpaTela() {
    system("cls");
}
