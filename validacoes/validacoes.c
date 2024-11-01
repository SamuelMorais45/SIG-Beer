#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int validarFormatoCPF(const char *cpf) {
 
    if (strlen(cpf) != 14) return 0;
    for (int i = 0; i < 14; i++) {
        if ((i == 3 || i == 7) && cpf[i] != '.') return 0;    
        if (i == 11 && cpf[i] != '-') return 0;               
        if ((i != 3 && i != 7 && i != 11) && !isdigit(cpf[i])) return 0; 
    }
   
    return 1;
}


int validarDigitosCPF(const char *cpf) {
    int soma = 0, resto;
    int numeros[11];
   
    
    int j = 0;
    for (int i = 0; i < 14; i++) {
        if (isdigit(cpf[i])) {
            numeros[j] = cpf[i] - '0';
            j++;
        }
    }

   
    for (int i = 0; i < 9; i++) {
        soma += numeros[i] * (10 - i);
    }
    resto = (soma * 10) % 11;
    if (resto == 10) resto = 0;
    if (resto != numeros[9]) return 0;

 
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += numeros[i] * (11 - i);
    }
    resto = (soma * 10) % 11;
    if (resto == 10) resto = 0;
    if (resto != numeros[10]) return 0;

    return 1;
}

int validarCPF(const char *cpf) {
    if (!validarFormatoCPF(cpf)) {
        printf("Formato de CPF inválido.\n");
        return 0;
    }
   
    if (!validarDigitosCPF(cpf)) {
        printf("Dígitos verificadores inválidos.\n");
        return 0;
    }
   
    return 1;
}




int ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int validarData(const char *data) {
    int dia, mes, ano;
    if (sscanf(data, "%2d/%2d/%4d", &dia, &mes, &ano) != 3) {
        return 0;  
    }
    if (mes < 1 || mes > 12) {
        return 0;  
    }
    int diasNoMes;
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            diasNoMes = 31;  
            break;
        case 4: case 6: case 9: case 11:
            diasNoMes = 30;  
            break;
        case 2:
            diasNoMes = ehBissexto(ano) ? 29 : 28;  
            break;
        default:
            return 0;  
    }
    if (dia < 1 || dia > diasNoMes) {
        return 0;  
    }
    return 1;  
}