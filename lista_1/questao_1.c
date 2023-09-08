#include <stdio.h>
#include <float.h>

int main() {
    FILE *fpt;
    int n_float = 0, n_double = 0, n_long = 0;
    float a = 1;
    float b = 1;
    double c = 1;
    double d = 1;
    long double e = 1;
    long double f = 1;
    
    // Investiga quantas iterações são necessárias para
    // ocorrer cancelamento 

    while (a + b != a) {
        b /= 2;
        n_float++;
    }
    while (c + d != c) {
        d /= 2;
        n_double++;
    }
    while (e + f != e) {
        f /= 2;
        n_long++;
    }    

    printf("Salvando resultados...\n");

    // Salva resultados na tabela
    
    fpt = fopen("mantissa_result.csv", "w+");
    
    fprintf(fpt,"Tipo, Calculado, Biblioteca\n");
    fprintf(fpt,"float, %d, %d\n",n_float,FLT_MANT_DIG);
    fprintf(fpt,"double, %d, %d\n",n_double,DBL_MANT_DIG);
    fprintf(fpt,"long, %d, %d\n",n_long,LDBL_MANT_DIG);

    return 0;
}