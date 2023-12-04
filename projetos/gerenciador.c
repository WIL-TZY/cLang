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

typedef struct {
    int id;
    char nome[MAXIMO];
    char funcao[MAXIMO];
    int removido;
} Pessoa;

enum OpcoesMenu {
    EDITAR_NOME_PROJETO = 1,
    ADICIONAR_INTEGRANTE,
    REMOVER_INTEGRANTE,
    VISUALIZAR_INTEGRANTES,
    ADICIONAR_TAREFA,
    REMOVER_TAREFA,
    EDITAR_TAREFA,
    VISUALIZAR_ANDAMENTO_PROJETO,
    SAIR = 0
};

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
    while(opcao != SAIR) { 
        exibirMenu();

        // Usuário escolhe uma opção
        scanf("%d", &opcao);
        limpaBuffer();

        // Limpa a tela quando uma opção é selecionada
        limpaTela(); 
        
        // FUNÇÃO 1: Editar o nome do projeto
        if (opcao == EDITAR_NOME_PROJETO) {
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
        if(opcao == ADICIONAR_INTEGRANTE) {
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
        if(opcao == REMOVER_INTEGRANTE){
            while(sOuN == 1){ 
                // Validar a entrada para idExclusao verificando se scanf retorna 1 (indica que um inteiro foi lido com sucesso)
                printf("Digite o numero do integrante a ser removido: ");
                if (scanf("%d", &idExclusao) != 1) {
                    printf("Entrada invalida. Digite um numero valido.\n");
                    limpaBuffer();
                    continue;
                }

                // Verificar se idExclusao está dentro do intervalo válido de integrantes (0 a qtdIntegrantes - 1). 
                if (idExclusao < 0 || idExclusao >= qtdIntegrantes) {
                    printf("Integrante nao encontrado. Digite um numero valido.\n");
                    limpaBuffer();
                    continue;
                }   

                for(integrante = 0; integrante < qtdIntegrantes; integrante++){
                    if(idExclusao == pessoa[integrante].id){
                        pessoa[integrante].removido = 1;
                    }
                }
                
                limpaTela();
                printf("Integrante Removido. Deseja remover mais algum? 1-Sim 2-Nao\n");
                if (scanf("%d", &sOuN) != 1) {
                    // Ao pedir ao usuário para escolher, validar novamente a entrada para garantir que seja ou 1 ou 2
                    printf("Entrada invalida. Digite 1 para continuar ou 2 para sair.\n");
                    limpaBuffer();
                    continue;
                }
                limpaTela();
            }
        }

        // FUNÇÃO 4: Visualizar integrantes
        if(opcao == VISUALIZAR_INTEGRANTES) {
            adicionaQuebra();
            //printf("Quantidade de integrantes: %d\n", qtdIntegrantes); // DEBUG

            int novoID = 0;
            printf("Numero   |     Nome              |          Funcao\n");
            for (int integrante = 0; integrante < qtdIntegrantes; integrante++) {
                if (!pessoa[integrante].removido) {
                    pessoa[integrante].id = novoID;
                    printf("%-7d  |  %-19s  |  %-23s\n", pessoa[integrante].id, pessoa[integrante].nome, pessoa[integrante].funcao);    
                    novoID++;        
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
        if (opcao == ADICIONAR_TAREFA) {
            while(1) {
                if (qtdTarefas < MAXIMO) {
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
                            if (strcmp(pessoa[i].nome, tarefas[qtdTarefas].responsavel) == 0 && !pessoa[i].removido) {
                                responsavelID = i;
                                break;
                            }
                        }
                        
                        // Responsável não foi encontrando ou foi removido
                        if (responsavelID == -1) {
                            printf("Integrante nao encontrado, digite outro responsavel.\n");
                            
                            sOuN = 0;
                            // Perguntar se o usuário quer adicionar outra tarefa
                            printf("Deseja tentar novamente? 1-Sim 2-Nao\n");
                            scanf("%d", &sOuN);
                            limpaBuffer();

                            if (sOuN == 1) {
                                // Volta pro loop de adicionar integrante
                                limpaTela();
                                continue;
                            }
                            else {
                                limpaTela();
                                break;
                            }
                            
                        } else {
                            // Tarefa adicionada com o ID do responsável encontrado
                            tarefas[qtdTarefas].progresso = 0;
                            tarefas[qtdTarefas].idTarefa = qtdTarefas;
                            qtdTarefas++;
                            printf("Tarefa adicionada com sucesso.\n");
                            inserindoIntegrante = 0;
                        }
                    }

                    sOuN = 0;
                    // Perguntar se o usuário quer adicionar outra tarefa
                    printf("Deseja adicionar outra tarefa? 1-Sim 2-Nao\n");
                    scanf("%d", &sOuN);
                    limpaBuffer();

                    if (sOuN != 1) {
                        // Sai do loop de adicionar tarefas
                        break;
                    }
                }
                else {
                    printf("Limite maximo de tarefas atingido.\n");
                    break;
                }
            }
        }

    // FUNÇÃO 6: Remover tarefa
    if (opcao == REMOVER_TAREFA) {
        int numeroTarefa;
        printf("Digite o numero da tarefa que deseja remover: ");
        scanf("%d", &numeroTarefa);
        limpaBuffer();

        // Verificar se o número da tarefa é válido
        if (numeroTarefa >= 0 && numeroTarefa < qtdTarefas) {
            // Remover a tarefa e reorganizar os números das tarefas
            for (int i = numeroTarefa; i < qtdTarefas - 1; i++) {
                tarefas[i] = tarefas[i + 1];
                tarefas[i].idTarefa = i;
            }
            qtdTarefas--;

            printf("Tarefa removida com sucesso.\n");
        } else {
            printf("Numero de tarefa invalido.\n");
        }

        limpaTela();
    }

    // FUNÇÃO 7: Editar tarefa
    if (opcao == EDITAR_TAREFA) {
        int numeroTarefa;
        printf("Digite o numero da tarefa que deseja editar: ");
        scanf("%d", &numeroTarefa);
        limpaBuffer();

        // Verificar se o número da tarefa é válido
        if (numeroTarefa >= 0 && numeroTarefa < qtdTarefas) {
            printf("Digite o nome da tarefa: ");
            fgets(tarefas[numeroTarefa].nome, sizeof(tarefas[numeroTarefa].nome), stdin);
            tarefas[numeroTarefa].nome[strcspn(tarefas[numeroTarefa].nome, "\n")] = '\0';

            printf("Digite o nome do responsavel: ");
            fgets(tarefas[numeroTarefa].responsavel, sizeof(tarefas[numeroTarefa].responsavel), stdin);
            tarefas[numeroTarefa].responsavel[strcspn(tarefas[numeroTarefa].responsavel, "\n")] = '\0';

            printf("Digite o progresso atual [%%]: ");
            scanf("%d", &tarefas[numeroTarefa].progresso);
            limpaBuffer();

            // Verificar se o responsável é um integrante válido
            int responsavelID = -1;
            for (int i = 0; i < qtdIntegrantes; i++) {
                if (strcmp(pessoa[i].nome, tarefas[numeroTarefa].responsavel) == 0) {
                    responsavelID = i;
                    break;
                }
            }

            if (responsavelID == -1) {
                printf("Integrante nao encontrado, digite outro.\n");
            } else {
                printf("Tarefa editada com sucesso.\n");
            }
        } else {
            printf("Numero de tarefa invalido.\n");
        }

        limpaTela();
    }

        // FUNÇÃO 8: Visualizar andamento do projeto
        if (opcao == VISUALIZAR_ANDAMENTO_PROJETO) {
            printf("Visualizar Andamento do Projeto:\n\n");
            printf("Numero   |     Nome da Tarefa              |     Responsavel          |     Progresso\n");
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
    // while (getchar() != '\n');
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
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

