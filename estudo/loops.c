#include <stdio.h>

int main() {

    // Testando variável indefinida
    int x;
    printf("A variável x é indeterminada. Seu valor nessa runtime é: %d\n", x);

    /*
    Loops são construções essenciais em programação que permitem executar um bloco de código repetidamente. 
    Em C, você tem várias estruturas de loop, incluindo for, while e do...while.
    */

    // FOR LOOP
    /*
    Estrutura: for (inicialização; condição; incremento) { }

    Inicialização: Esta parte é executada apenas uma vez no início do loop. Normalmente inicializa uma variável de controle de loop.

    Condição: é uma expressão booleana que determina se o loop deve continuar. O loop é executado enquanto esta condição for verdadeira.

    Incremento: Após cada iteração, esta parte é executada. Geralmente modifica a variável de controle do loop.
    */
    for (int i = 0; i < 5; i++) { 
        // Código a ser repetido
        printf("Iteração N° %d\n", i);
    }

    // WHILE LOOP
    /*
    Estrutura: while (condição) { }
    O loop while é usado quando você não sabe logo de primeira quantas vezes o loop deve ser executado. 
    Depende de uma condição para decidir se continua ou sai.
    */
    int x = 1;
    while (x <= 5) {
        // Código a ser repetido
        printf("x = %d\n", x);
        x++;
    }

    // DO... WHILE LOOP
    // Estrutura: do { } while (condição);
    // O loop do...while é semelhante ao loop while, mas garante que o corpo do loop seja executado pelo menos uma vez porque a condição é verificada após o corpo do loop.
    int x = 1;
    do {
        // Código a ser repetido
        printf("x = %d\n", x);
        x++;
    } while (x <= 5);


    // Controladores de LOOP
    /* 
    Em C, você tem diversas instruções de controle que permitem controlar o fluxo de loops:

    break: encerra o loop prematuramente e transfere o controle para a instrução seguinte ao loop.
    continue: ignora a iteração atual e passa para a próxima iteração do loop.
    goto: permite que você pule para uma instrução rotulada em seu código. Deve ser usado com cautela, pois pode tornar o código menos legível e mais difícil de manter.
    */

    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            break; // Pula fora do loop quando i for igual a 5
        }
    }

    for (int i = 0; i < 5; i++) {
    if (i == 2) {
        continue; // Salta pra fora da iteração se i for igual a 2
    }
    printf("i = %d\n", i);

    for (int i = 0; i < 5; i++) {
        if (i == 3) {
            goto endLoop; // Salta para o rótulo
        }
    }
    endLoop:

    // O uso de goto é frequentemente desencorajado em favor de construções de fluxo de controle mais estruturadas, como if, for e while.

}
    // LOOPS INFINITOS
    /*
    Loops infinitos são loops que são executados indefinidamente até que alguma ação externa os interrompa. 
    Como a intervenção de um usuário ou o encerramento do programa.
    Em C, você pode criar loops infinitos usando várias construções de loop.
    */

    int saida = 0;
    // Loop infinito usando FOR
    for (;;) {
    // Código que roda infinitamente
    saida = 1;
        if (saida == 1) {
            // Você pode sair deste loop usando uma instrução break quando uma determinada condição for atendida
            break;
        }
    }

    // Loop infinito usando WHILE
    while (1) {
        // Descomenta o 'break' p/ ver o loop infinito
        break;
    }

    return 0;
}