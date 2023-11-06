#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#define MAXIMO 30

// Global que armazena o tempo atual
struct tm *localTime;

// -------- Cabeçalhos -------- //
void limpaBuffer();
void limpaTela();
void adicionaQuebra();
void exibirMenu();

// --------- Structs ---------- //
typedef struct {
    int id;
    char nome[MAXIMO];
    char funcao[MAXIMO];
} Pessoa;

typedef struct {
    int idTarefa;
    char nome[MAXIMO];
    char responsavel[MAXIMO]; // Nome da pessoa responsável
    int progresso;   // Progresso da tarefa em porcentagem (inicialmente 0%)
} Tarefa;

int main() {
    setlocale(LC_ALL,"Portuguese_Brazil");
    
    /* ------------------ Variáveis de data & hora ------------------ */
    // A variável currentTime armazena a hora atual do relógio do sistema
    // Declarada como uma constante pois não há intenções de mudá-la, é uma boa prática
    const time_t currentTime = time(NULL);

    // Ponteiro para struct tm - para facilitar a manipulação de componentes de data e hora
    localTime = localtime(&currentTime);
    
    /*----------------------- Outras variáveis ---------------------- */
    int opcao = -1, sOuN = 0;
    char nomeProjeto[MAXIMO] = "Meu Projeto 01";
    char novoNome[MAXIMO];

    // Inicializando instâncias das structs
    Pessoa pessoa[MAXIMO]; 
    Tarefa tarefas[MAXIMO]; 

    int qtdIntegrantes = 0, qtdIntegrantesAnterior = 0, novosIntegrantes = 0, integrante = 0;
    int qtdTarefas = 0;

    /* ----------------------- LOOP PRINCIPAL ----------------------- */
    while(opcao != 0) { 
        exibirMenu();

        // Usuário escolhe uma opção
        scanf("%d", &opcao);
        limpaBuffer();

        // Limpa a tela quando uma opção é selecionada
        limpaTela(); 
        
        // FUNÇÃO 1: Editar o nome do projeto
        if (opcao == 1) {
            printf("Nome Atual do Projeto: %s\n\n", nomeProjeto);
            printf("Inserir novo nome? 1-Sim 2-Nao\n");
            scanf("%d", &sOuN);
            limpaBuffer();
            limpaTela();
            
            // Subtela "Sim" / "Não"
            if(sOuN == 1) {
                printf("Digite o novo nome do Projeto:\n");

                // Usuário escolhe um nome pro projeto
                fgets(novoNome, sizeof(novoNome), stdin);
                novoNome[strcspn(novoNome, "\n")] = '\0';  // Remove o '\n' adicionado na hora do "Enter"

                // Adiciona o novo nome do projeto
                strcpy(nomeProjeto, novoNome);

                limpaTela();
            } else if(sOuN == 0){
                limpaTela();
            }
        }
        
        // FUNÇÃO 2: Adicionar integrantes
        if(opcao == 2) {
            printf("Quantos Integrantes Deseja Adicionar? ");
            scanf("%d", &novosIntegrantes);

            // Armazena o número anterior de integrantes
            qtdIntegrantesAnterior = qtdIntegrantes;

            // Adiciona novos integrantes a quantidade total de integrantes
            qtdIntegrantes = qtdIntegrantes + novosIntegrantes;

            // Reseta a variável
            novosIntegrantes = 0;
            
            limpaBuffer();
            limpaTela();

            //printf("Quantidade de integrantes: %d\n", qtdIntegrantes); // DEBUG

            for(integrante = qtdIntegrantesAnterior; integrante < qtdIntegrantes; integrante++){
                printf("Digite o nome do integrante %d:\n", integrante);
                fgets(pessoa[integrante].nome, sizeof(pessoa[integrante].nome), stdin);
                pessoa[integrante].nome[strcspn(pessoa[integrante].nome, "\n")] = '\0';  // Remove o '\n' adicionado na hora do "Enter"
                adicionaQuebra();
                printf("Digite a funcao do integrante %d:\n", integrante);
                fgets(pessoa[integrante].funcao, sizeof(pessoa[integrante].funcao), stdin);
                pessoa[integrante].funcao[strcspn(pessoa[integrante].funcao, "\n")] = '\0';  // Remove o '\n' adicionado na hora do "Enter"
                adicionaQuebra();
                pessoa[integrante].id = integrante;
                limpaTela();
            }
        }

        // FUNÇÃO 3: Remover integrantes
        int idExclusao; // Número do cara que vai ser excluido
        char valorNulo[5] = "Null";
        sOuN = 1;
        if(opcao == 3){
            while(sOuN == 1){ 
                // Validar a entrada para idExclusao verificando se scanf retorna 1 (indica que um inteiro foi lido com sucesso)
                printf("Digite o numero do integrante a ser removido: ");
                if (scanf("%d", &idExclusao) != 1) {
                    printf("Entrada inválida. Digite um número válido.\n");
                    limpaBuffer();
                    continue;
                }

                // Verificar se idExclusao está dentro do intervalo válido de integrantes (0 a qtdIntegrantes - 1). 
                if (idExclusao < 0 || idExclusao >= qtdIntegrantes) {
                    printf("Integrante não encontrado. Digite um número válido.\n");
                    limpaBuffer();
                    continue;
                }   

                for(integrante = 0; integrante < qtdIntegrantes; integrante++){
                    if(idExclusao == pessoa[integrante].id){
                        strcpy(pessoa[integrante].nome, valorNulo);
                        strcpy(pessoa[integrante].funcao, valorNulo);
                    }
                }
                
                limpaTela();
                printf("Integrante Removido. Deseja remover mais algum? 1-Sim 2-Nao\n");
                if (scanf("%d", &sOuN) != 1) {
                    // Ao pedir ao usuário para escolher, validar novamente a entrada para garantir que seja ou 1 ou 2
                    printf("Entrada inválida. Digite 1 para continuar ou 2 para sair.\n");
                    limpaBuffer();
                    continue;
                }
                limpaTela();
            }
        }

        // FUNÇÃO 4: Visualizar integrantes
        if(opcao == 4) {
            adicionaQuebra();
            //printf("Quantidade de integrantes: %d\n", qtdIntegrantes); // DEBUG

            printf("Numero   |     Nome              |          Funcao\n");
            for (int integrante = 0; integrante < qtdIntegrantes; integrante++) {
                if (strcmp(pessoa[integrante].nome, valorNulo) != 0) {
                    printf("%-7d  |  %-19s  |  %-23s\n", pessoa[integrante].id, pessoa[integrante].nome, pessoa[integrante].funcao);  
                }          
            }

            // Voltar para o menu principal
            int voltar = 1;
            printf("\nDigite 0 para voltar: ");
            scanf("%d", &voltar);
            limpaBuffer();
            limpaTela();
        }

        // FUNÇÃO 5: Adicionar tarefa
        if (opcao == 5) {
            // Tarefa
            printf("Digite o nome da tarefa: ");
            fgets(tarefas[qtdTarefas].nome, sizeof(tarefas[qtdTarefas].nome), stdin);
            tarefas[qtdTarefas].nome[strcspn(tarefas[qtdTarefas].nome, "\n")] = '\0';  // Remove o '\n' adicionado na hora do "Enter"

            int inserindoIntegrante = 1;
            while(inserindoIntegrante) {
                // Responsável pela tarefa
                printf("Digite o nome do responsavel pela tarefa: ");
                fgets(tarefas[qtdTarefas].responsavel, sizeof(tarefas[qtdTarefas].responsavel), stdin);
                tarefas[qtdTarefas].responsavel[strcspn(tarefas[qtdTarefas].responsavel, "\n")] = '\0';  // Remove o '\n' adicionado na hora do "Enter"

                int responsavelID = -1;
                for (int i = 0; i < qtdIntegrantes; i++) {
                    if (strcmp(pessoa[i].nome, tarefas[qtdTarefas].responsavel) == 0) {
                        responsavelID = i;
                        break;
                    }
                }
                
                // Responsável não foi encontrando
                if (responsavelID == -1) {
                    printf("Integrante nao encontrado, digite outro responsavel.\n");
                    limpaTela();
                    continue;
                } else {
                    // Tarefa adicionada com o ID do responsável encontrado
                    tarefas[qtdTarefas].progresso = 0;
                    tarefas[qtdTarefas].idTarefa = qtdTarefas;
                    qtdTarefas++;
                    printf("Tarefa adicionada com sucesso.\n");
                    break;
                }
            }
        }

        // FUNÇÃO 8: Visualizar andamento do projeto
        if (opcao == 8) {
            printf("Visualizar Andamento do Projeto:\n\n");
            printf("Numero   |     Nome da Tarefa              |     Responsavel         |     Progresso\n");
            adicionaQuebra();
            for (int tarefa = 0; tarefa < qtdTarefas; tarefa++) {
                if (strcmp(tarefas[tarefa].nome, valorNulo) != 0) {
                    printf("%-8d |  %-30s |  %-23s |  %d%%\n", tarefas[tarefa].idTarefa, tarefas[tarefa].nome, tarefas[tarefa].responsavel, tarefas[tarefa].progresso);
                }   
            }

            // Voltar para o menu principal
            int voltar = 1;
            printf("\nDigite 0 para voltar: ");
            scanf("%d", &voltar);
            limpaBuffer();
            limpaTela();
        }
        // FIM DO LOOP PRINCIPAL
    } 
    // ------------------ FIM DO PROGRAMA ------------------ //
    adicionaQuebra();
    printf("\nPrograma Encerrado.\n");

    return 0;
}

void limpaBuffer() {
    while (getchar() != '\n');
}

void limpaTela() {
    // Código ANSI para limpar a tela
    printf("\033[H\033[J");
}

void adicionaQuebra() {
    printf("\n");
}

void exibirMenu() {
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
        printf("#             5-Adicionar Tarefas                                                                       #\n");
        printf("#             6-Remover Tarefa                                                                          #\n");
        printf("#             7-Editar Tarefa                                                                           #\n");
        printf("#             8-Visualizar Andamento da Tarefa                                                          #\n");
        printf("#                                                                                                       #\n");
        printf("#             0-Sair                                                                                    #\n");
        printf("#                                                                                                       #\n");
        printf("#                                                 Brasilia, %02d/%02d/20%02d                                  #\n", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year - 100);
        printf("#                                                                                                       #\n");
        printf("#                                                                Desenvolvedores: Miguel, Anael         #\n");
        printf("#########################################################################################################\n");
}

