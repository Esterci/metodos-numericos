#include <stdio.h>
#include <math.h>

float float_fatorial(int x)
{
    float fat = 1;
    if (x == 0)
        return 1;
    for (int i = 1; i <= x; i++)
        fat *= i;
    return fat;
}

// Calculo da aproximação da exponencial
float float_aprox_exp(float x, int ordem)
{
    float a, soma;
    soma = 0;
    a = x; // variavel auxiliar para calculo do somatorio
    if (a < 0)
        a *= -1;
    for (int i = 0; i < ordem; i++)
        soma += pow(a, i) / float_fatorial(i);

    if (x < 0) // caso o expoente for negativo
        return 1 / soma;
    return soma;
}

double double_fatorial(int x)
{
    double fat = 1;
    if (x == 0)
        return 1;
    for (int i = 1; i <= x; i++)
        fat *= i;
    return fat;
}

// Calculo da aproximação da exponencial
double double_aprox_exp(float x, int ordem)
{
    double a, soma;
    soma = 0;
    a = x; // variavel auxiliar para calculo do somatorio
    if (a < 0)
        a *= -1;
    for (int i = 0; i < ordem; i++)
        soma += pow(a, i) / double_fatorial(i);

    if (x < 0) // caso o expoente for negativo
        return 1 / soma;
    return soma;
}

long double fatorial(int x)
{
    long double fat = 1;
    if (x == 0)
        return 1;
    for (int i = 1; i <= x; i++)
        fat *= i;
    return fat;
}

// Calculo da aproximação da exponencial
long double aprox_exp(float x, int ordem)
{
    long double a, soma;
    soma = 0;
    a = x; // variavel auxiliar para calculo do somatorio
    if (a < 0)
        a *= -1;
    for (int i = 0; i < ordem; i++)
        soma += pow(a, i) / fatorial(i);

    if (x < 0) // caso o expoente for negativo
        return 1 / soma;
    return soma;
}

int main()
{
    FILE *fpt;
    float expoente[8] = {-20, -10, -2, -1, 1, 2, 10, 20};
    int ordem[5] = {100, 50, 30, 25, 10};
    long double e_real;

    e_real = exp(expoente[8]);

    // Salva resultados na tabela

    fpt = fopen("expoente_result.csv", "w+");

    fprintf(fpt, "Tipo, Expoente, Ordem, Valor aproximado, Erro Absoluto, Erro Relativo\n");

    //  Salva resultados na tabela float
    printf("Salvando resultados p/ float\n");

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fprintf(
                fpt,
                "float, %.1f, %d, %f, %f, %f\n",
                expoente[i],
                ordem[j],
                float_aprox_exp(expoente[i], ordem[j]),
                (float)(e_real - float_aprox_exp(expoente[i], ordem[j])),
                (float)((e_real - float_aprox_exp(expoente[i], ordem[j])) / float_aprox_exp(expoente[i], ordem[j])));
        }
    }

    //  Salva resultados na tabela double
    printf("Salvando resultados p/ double\n");

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fprintf(
                fpt,
                "double, %.1f, %d, %lf, %lf, %lf\n",
                expoente[i],
                ordem[j],
                double_aprox_exp(expoente[i], ordem[j]),
                (double)(e_real - double_aprox_exp(expoente[i], ordem[j])),
                (double)((e_real - double_aprox_exp(expoente[i], ordem[j])) / double_aprox_exp(expoente[i], ordem[j])));
        }
    }

    //  Salva resultados na tabela long double
    printf("Salvando resultados p/ long double\n");

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fprintf(
                fpt,
                "long double, %.1f, %d, %.15Lf, %.15Lf, %.15Lf\n",
                expoente[i],
                ordem[j],
                aprox_exp(expoente[i], ordem[j]),
                (long double)(e_real - aprox_exp(expoente[i], ordem[j])),
                (long double)((e_real - aprox_exp(expoente[i], ordem[j])) / aprox_exp(expoente[i], ordem[j])));
        }
    }

    fclose(fpt);

    return 0;
}