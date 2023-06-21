#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


    float opcao_d(int *valor_k, int valor_n, int quantidade_digitos)
{
    int valor_potencia, valor_potencia2;

    if (valor_n > 0 && valor_n < quantidade_digitos)
    {
        valor_potencia = pow(10, (quantidade_digitos - valor_n));
        valor_potencia2 = pow(10, valor_n);

        *valor_k = (((*valor_k % valor_potencia2) * valor_potencia) + (*valor_k / valor_potencia2));

        return(1);
    }

    else
        return(0);
}

    float opcao_e(int *valor_k, int valor_n, int quantidade_digitos)
{
    int valor_potencia, valor_potencia2;

    if (valor_n > 0 && valor_n < quantidade_digitos)
    {
        valor_potencia = pow(10, (quantidade_digitos - valor_n));
        valor_potencia2 = pow(10, valor_n);

        *valor_k = (((*valor_k % valor_potencia) * valor_potencia2) + (*valor_k / valor_potencia));

        return(1);
    }

    else
        return(0);
}

    float opcao_i(int *valor_k, int valor_n, int quantidade_digitos)
{
    int valor_potencia;

    if (valor_n >= 0 && valor_n <= 9)
    {
        valor_potencia = pow(10, (quantidade_digitos - 1));

        *valor_k = (*valor_k / 10) + (valor_n * valor_potencia);

        return(1);
    }
    else
        return(0);
}


    float opcao_f(int *valor_k, int valor_n, int quantidade_digitos)
{
    int valor_potencia;

    if (valor_n >= 0 && valor_n <= 9)
    {
        valor_potencia = pow(10, (quantidade_digitos - 1));

        *valor_k = (((*valor_k % valor_potencia) * 10) + valor_n);

        return(1);
    }
    else
        return(0);
}


    int main()
{
    setlocale(LC_ALL, "Portuguese");

    int k, n, digitos_k, qntd_digitos = 2, validar_n;
    char opcao;


    printf("\nNUMERO.C\n");


    printf("\nInsira um número inteiro (entre 3 e 10 digitos): ");
    scanf("%11d", &k);

    while (k < 100 || k > 9999999999)
    {
        printf("\nERRO. Insira um valor válido (entre 3 e 10 digitos): ");
        scanf("%11d", &k);
    }

    digitos_k = k;
    while (digitos_k > 100)
    {
        qntd_digitos++;
        digitos_k = digitos_k / 10;
    }


    printf("\nOpções de operações: \nD) N faz a rotação do número à direita em n dígitos (n > 0) \nE) N faz a rotação do número à esquerda em n dígitos (n > 0) \nI) N insere o dígito n no início do número (o dígito mais à direita é perdido; 0 <= n <= 9) \nF) N insere o dígito n no fim do número (o dígito mais à esquerda é perdido; 0 <= n <= 9) \nT) Termina o programa");

    printf("\n\nInsira a opção desejada: ");
    fflush(stdin);
    scanf("%c", &opcao);


    while (opcao != 't' && opcao!= 'T')
    {
        switch (opcao)
        {
            case 'd':

                printf("\nInsira o valor de N (n > 0): ");
                scanf("%d", &n);

                validar_n = opcao_d(&k, n, qntd_digitos);

                if (validar_n == 1)
                    printf("\nK = %.3d", k);

                else
                    printf("\nERRO. Valor inválido de N.");
            break;

            case 'D':

                printf("\nInsira o valor de N (n > 0): ");
                scanf("%d", &n);

                validar_n = opcao_d(&k, n, qntd_digitos);

                if (validar_n == 1)
                    printf("\nK = %.3d", k);

                else
                    printf("\nERRO. Valor inválido de N.");
            break;

            case 'e':

                printf("\nInsira o valor de N (n > 0): ");
                scanf("%d", &n);

                validar_n = opcao_e(&k, n, qntd_digitos);

                if (validar_n == 1)
                    printf("\nK = %.3d", k);

                else
                    printf("\nERRO. Valor inválido de N.");
            break;

            case 'E':

                printf("\nInsira o valor de N (n > 0): ");
                scanf("%d", &n);

                validar_n = opcao_e(&k, n, qntd_digitos);

                if (validar_n == 1)
                    printf("\nK = %.3d", k);

                else
                    printf("\nERRO. Valor inválido de N.");
            break;

            case 'i':

                printf("\nInsira o valor de N (0 <= n <= 9): ");
                scanf("%d", &n);

                validar_n = opcao_i(&k, n, qntd_digitos);

                if (validar_n == 1)
                    printf("\nK = %.3d", k);

                else
                    printf("\nERRO. Valor inválido de N.");
            break;

            case 'I':

                printf("\nInsira o valor de N (0 <= n <= 9): ");
                scanf("%d", &n);

                validar_n = opcao_i(&k, n, qntd_digitos);

                if (validar_n == 1)
                    printf("\nK = %.3d", k);

                else
                    printf("\nERRO. Valor inválido de N.");
            break;

            case 'f':

                printf("\nInsira o valor de N (0 <= n <= 9): ");
                scanf("%d", &n);

                validar_n = opcao_f(&k, n, qntd_digitos);

                if (validar_n == 1)
                    printf("\nK = %.3d", k);

                else
                    printf("\nERRO. Valor inválido de N.");
            break;

            case 'F':

                printf("\nInsira o valor de N (0 <= n <= 9): ");
                scanf("%d", &n);

                validar_n = opcao_f(&k, n, qntd_digitos);

                if (validar_n == 1)
                    printf("\nK = %.3d", k);

                else
                    printf("\nERRO. Valor inválido de N.");
            break;


            default:
                printf("Opção Inválida.");
            break;

        }

        printf("\n\nInsira a opção desejada: ");
        fflush(stdin);
        scanf("%c", &opcao);
    }

    printf("\nPrograma Finalizado!");

    return 0;
}
