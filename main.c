#include <stdio.h>
#include <string.h>

int main() {
    FILE *entrada_arqv = fopen("DadosEntrada.csv", "r");
    FILE *saida_arqv = fopen("SituacaoFinal.csv", "w");

    if (entrada_arqv == NULL || saida_arqv == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(saida_arqv, "Nome,Nota Média,Situação\n");

    char linha[256];
    while (fgets(linha, sizeof(linha), entrada_arqv)) {
        char nome[100];
        char telefone[20];
        char curso[100];
        float nota1, nota2;

        if (sscanf(linha, "%[^,],%[^,],%[^,],%f,%f", nome, telefone, curso, &nota1, &nota2) == 5) {
            float media = (nota1 + nota2) / 2.0;
            char situacao[20];

            if (media >= 7.0) {
                strcpy(situacao, "APROVADO");
            } else {
                strcpy(situacao, "REPROVADO");
            }


            fprintf(saida_arqv, "%s, %.2f, %s\n", nome, media, situacao);
        }
    }

    fclose(entrada_arqv);
    fclose(saida_arqv);

    printf("Dados gravados em SituacaoFinal.csv.\n");

    return 0;
}
