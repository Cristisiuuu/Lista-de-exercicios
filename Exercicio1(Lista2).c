#include <stdio.h>
#include <string.h>

struct Banda {
    char nome[50];
    char musica[50];
    int integrantes;
    int ranking;
};

void CadastroBanda(struct Banda *bandas, int indice) {
    printf("Nome da banda: ");
    scanf(" %[^\n]", bandas[indice].nome);

    printf("Tipo de musica: ");
    scanf(" %[^\n]", bandas[indice].musica);

    printf("Numero de integrantes: ");
    scanf("%d", &bandas[indice].integrantes);

    printf("Posicao no ranking (1 a 5, 0 se nao estiver entre as favoritas): ");
    scanf("%d", &bandas[indice].ranking);
}

void ExibirBandasPorRanking(struct Banda *bandas, int quantidade, int rankingBusca) {
    int i;
    printf("\nBandas com ranking %d:\n", rankingBusca);
    for (i = 0; i < quantidade; i++) {
        if (bandas[i].ranking == rankingBusca) {
            printf("Banda %d:\n", i + 1);
            printf("Nome: %s\n", bandas[i].nome);
            printf("Tipo de musica: %s\n", bandas[i].musica);
            printf("Numero de integrantes: %d\n", bandas[i].integrantes);
            printf("Posicao no ranking: %d\n\n", bandas[i].ranking);
        }
    }
}

void ExibirBandasPorTipoMusica(struct Banda *bandas, int quantidade, char tipoMusicaBusca[50]) {
    int i;
    printf("\nBandas com tipo de musica '%s':\n", tipoMusicaBusca);
    for (i = 0; i < quantidade; i++) {
        if (strcmp(bandas[i].musica, tipoMusicaBusca) == 0) {
            printf("Banda %d:\n", i + 1);
            printf("Nome: %s\n", bandas[i].nome);
            printf("Tipo de musica: %s\n", bandas[i].musica);
            printf("Numero de integrantes: %d\n", bandas[i].integrantes);
            printf("Posicao no ranking: %d\n\n", bandas[i].ranking);
        }
    }
}

int BandaFavorita(struct Banda *bandas, int quantidade, char nomeBanda[50]) {
    int i;
    for (i = 0; i < quantidade; i++) {
        if (strcmp(bandas[i].nome, nomeBanda) == 0) {
            if (bandas[i].ranking != 0) {
                printf("A banda '%s' esta entre suas bandas favoritas no ranking %d.\n", nomeBanda, bandas[i].ranking);
            } else {
                printf("A banda '%s' nao esta entre suas bandas favoritas.\n", nomeBanda);
            }
            return 1; // Banda encontrada
        }
    }
    printf("A banda '%s' nao foi encontrada entre suas bandas cadastradas.\n", nomeBanda);
    return 0;
}

int main() {
    int quantidade;
    int i;
    printf("Quantas bandas deseja cadastrar? ");
    scanf("%d", &quantidade);

    // Declaração do vetor de bandas
    struct Banda bandas[quantidade];

    // Cadastro das bandas
    for (i = 0; i < quantidade; i++) {
        CadastroBanda(bandas, i);
    }

    // Solicita ao usuário um ranking para buscar
    int rankingBusca;
    printf("\nDigite o ranking para buscar (1 a 5): ");
    scanf("%d", &rankingBusca);

    // Chama a função para exibir bandas com o ranking especificado
    ExibirBandasPorRanking(bandas, quantidade, rankingBusca);

    // Solicita ao usuário um tipo de música para buscar
    char tipoMusicaBusca[50];
    printf("\nDigite o tipo de musica para buscar: ");
    scanf(" %[^\n]", tipoMusicaBusca);

    // Chama a função para exibir bandas com o tipo de música especificado
    ExibirBandasPorTipoMusica(bandas, quantidade, tipoMusicaBusca);

    // Solicita ao usuário o nome de uma banda para verificar se está entre as favoritas
    char nomeBandaBusca[50];
    printf("\nDigite o nome da banda para verificar se esta entre suas favoritas: ");
    scanf(" %[^\n]", nomeBandaBusca);

    // Chama a função para verificar se a banda está entre as favoritas
    BandaFavorita(bandas, quantidade, nomeBandaBusca);

    return 0;
}

