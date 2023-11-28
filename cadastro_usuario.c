// Implemente um algoritmo que:

// Inclua até 1000 usuários;
// Edite um usuário;
// Exclua um usuário;
// Busque um usuário pelo e-mail;
// Imprima todos os usuários cadastrados;

// Obrigatório uso de struct, vetor e função.

// Obrigatório uso de switch case com char para escolha da opção desejada.

// ATENÇÃO: (1) NA CRIAÇÃO DE NOMES DE IDENTIFICADORES; (2) NOS TEXTOS DE INTERAÇÃO COM USUÁRIOS – ENTRADA E SAÍDA; (3) NA ORGANIZAÇÃO DO CÓDIGO.

// Dados do usuário:

// Id (int) => preenchido automaticamente por números randômicos e não podem ser repetir.
// Nome completo (string)
// Email (string) => validação do campo: verificar se o caractere "@" aparece
// Sexo (string) => validação do campo: aceitar somente as palavras Feminino, Masculino e Indiferente.
// Endereço (string)
// Altura (double) => validação do campo: aceitar valores entre 1 e 2 m.
// Vacina (int) => validação de 1 para sim e 0 para não
// Individual

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define USUARIOS 1000

typedef struct
{
    int id;
    char nome[50];
    char email[50];
    char sexo;
    char endereco[100];
    double altura;
    int vacina;
} Usuario;

// Function prototypes
void clearInputBuffer();
int validarEmail(const char email[]);
void cadastrar(Usuario usuarios[], int *totalCadastros);
void imprimir(const Usuario usuarios[], int totalCadastrados);
void buscarEmail(const Usuario usuarios[], int totalCadastros, const char email[]);
void editar(Usuario usuarios[], int totalCadastrados, int id);
void excluir(Usuario usuarios[], int *totalCadastrados, int id);

int main()
{
    srand((unsigned int)time(NULL));

    Usuario usuarios[USUARIOS];
    int totalCadastros = 0;

    char opcao;

    do
    {
        printf("\nOpcoes\n");
        printf("1: Cadastrar\n");
        printf("2: Imprimir\n");
        printf("3: Buscar pelo E-mail\n");
        printf("4: Editar\n");
        printf("5: Excluir\n");
        printf("0: Sair\n");

        printf("Escolha a opcao desejada: ");
        scanf(" %c", &opcao);

        switch (opcao)
        {
        case '1':
            cadastrar(usuarios, &totalCadastros);
            break;
        case '2':
            imprimir(usuarios, totalCadastros);
            break;
        case '3':
            printf("Informe o e-mail a ser buscado: ");
            char buscaEmail[50];
            scanf(" %s", buscaEmail);
            buscarEmail(usuarios, totalCadastros, buscaEmail);
            break;
        case '4':
            printf("Informe o ID do usuário a ser editado: ");
            int idEditar;
            scanf("%d", &idEditar);
            editar(usuarios, totalCadastros, idEditar);
            break;
        case '5':
            printf("Informe o ID do usuário a ser excluído: ");
            int idExcluir;
            scanf("%d", &idExcluir);
            excluir(usuarios, &totalCadastros, idExcluir);
            break;
        case '0':
            printf("Saiu do Programa\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente\n");
        }
    } while (opcao != '0');

    return 0;
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int validarEmail(const char email[])
{
    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
        {
            printf("E-mail validado\n");
            return 1;
        }
    }

    printf("E-mail inválido! Tente novamente\n");
    return 0;
}

void cadastrar(Usuario usuarios[], int *totalCadastros)
{
    if (*totalCadastros >= USUARIOS)
    {
        printf("Limite de usuários atingido.\n");
        return;
    }

    usuarios[*totalCadastros].id = rand() % 1000 + 1;

    printf("Informe o nome: ");
    clearInputBuffer();
    fgets(usuarios[*totalCadastros].nome, sizeof(usuarios[*totalCadastros].nome), stdin);
    usuarios[*totalCadastros].nome[strcspn(usuarios[*totalCadastros].nome, "\n")] = '\0';

    while (!validarEmail(usuarios[*totalCadastros].email))
    {
        printf("Informe o e-mail:");
        fgets(usuarios[*totalCadastros].email, sizeof(usuarios[*totalCadastros].email), stdin);
        usuarios[*totalCadastros].email[strcspn(usuarios[*totalCadastros].email, "\n")] = '\0';
    }

    printf("Informe o gênero (M, F ou I): ");
    scanf(" %c", &usuarios[*totalCadastros].sexo);

    printf("Informe o endereço:");
    clearInputBuffer();
    fgets(usuarios[*totalCadastros].endereco, sizeof(usuarios[*totalCadastros].endereco), stdin);
    usuarios[*totalCadastros].endereco[strcspn(usuarios[*totalCadastros].endereco, "\n")] = '\0';

    printf("Informe a altura: ");
    scanf("%lf", &usuarios[*totalCadastros].altura);

    printf("Informe se tomou a vacina (1 para sim, 0 para não): ");
    scanf("%d", &usuarios[*totalCadastros].vacina);

    (*totalCadastros)++;
}

void imprimir(const Usuario usuarios[], int totalCadastrados)
{
    if (totalCadastrados == 0)
    {
        printf("Cadastro de usuários vazio\n");
        return;
    }

    printf("\nLista de Usuarios\n");
    for (int i = 0; i < totalCadastrados; i++)
    {
        printf("ID: %d\n", usuarios[i].id);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Email: %s\n", usuarios[i].email);
        printf("Sexo: %c\n", usuarios[i].sexo);
        printf("Endereço: %s\n", usuarios[i].endereco);
        printf("Altura: %.2lf metros\n", usuarios[i].altura);
        printf("Vacina: %s\n", usuarios[i].vacina ? "Tomou" : "Não tomou");
        printf("\n");
    }
}

void buscarEmail(const Usuario usuarios[], int totalCadastros, const char email[])
{
    if (totalCadastros == 0)
    {
        printf("Cadastro de usuarios vazio\n");
        return;
    }

    int encontrado = 0;

    for (int i = 0; i < totalCadastros; i++)
    {
        if (strcmp(usuarios[i].email, email) == 0)
        {
            printf("Usuario Encontrado:\n");
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %c\n", usuarios[i].sexo);
            printf("Endereço: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf metros\n", usuarios[i].altura);
            printf("Vacina: %s\n", usuarios[i].vacina ? "Tomou" : "Não tomou");
            printf("\n");

            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Usuário com o e-mail %s não encontrado.\n", email);
    }
}

void editar(Usuario usuarios[], int totalCadastrados, int id)
{
    printf("Editando usuário ID %d\n", id);

    for (int i = 0; i < totalCadastrados; i++)
    {
        if (usuarios[i].id == id)
        {
            int opcao;

            do
            {
                printf("\nEscolha a opção que deseja editar\n");
                printf("1: Nome\n");
                printf("2: E-mail\n");
                printf("3: Sexo\n");
                printf("4: Endereço\n");
                printf("5: Altura\n");
                printf("6: Vacina\n");
                printf("7: Alterar cadastro inteiro\n");
                printf("0: Sair\n");
                printf("Opção:");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    printf("Informe o novo nome:");
                    clearInputBuffer();
                    fgets(usuarios[i].nome, sizeof(usuarios[i].nome), stdin);
                    usuarios[i].nome[strcspn(usuarios[i].nome, "\n")] = '\0';
                    break;
                case 2:
                    printf("Informe o novo e-mail (ou '0' para sair): ");
                    clearInputBuffer();
                    fgets(usuarios[i].email, sizeof(usuarios[i].email), stdin);
                    usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';
                    if (strcmp(usuarios[i].email, "0") == 0)
                    {
                        break; // Sair da edição de e-mail
                    }
                    while (!validarEmail(usuarios[i].email))
                    {
                        printf("Informe o novo e-mail (ou '0' para sair): ");
                        fgets(usuarios[i].email, sizeof(usuarios[i].email), stdin);
                        usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';
                        if (strcmp(usuarios[i].email, "0") == 0)
                        {
                            break; // Sair da edição de e-mail
                        }
                    }
                    break;
                case 3:
                    printf("Informe o novo sexo (M/F): ");
                    clearInputBuffer();
                    scanf(" %c", &usuarios[i].sexo);
                    break;
                case 4:
                    printf("Informe o novo endereço:");
                    clearInputBuffer();
                    fgets(usuarios[i].endereco, sizeof(usuarios[i].endereco), stdin);
                    usuarios[i].endereco[strcspn(usuarios[i].endereco, "\n")] = '\0';
                    break;
                case 5:
                    printf("Informe a nova altura:");
                    scanf("%lf", &usuarios[i].altura);
                    break;
                case 6:
                    printf("Informe se tomou a vacina (1 para sim, 0 para não): ");
                    scanf("%d", &usuarios[i].vacina);
                    break;
                case 7:
                    printf("\nEditando cadastro inteiro do Usuário ID %d\n", id);
                    cadastrar(usuarios, &totalCadastrados);
                    return;
                case 0:
                    printf("Saindo da edição.\n");
                    break;
                default:
                    printf("Opção inválida! Tente novamente.\n");
                }
            } while (opcao != 0);

            printf("Cadastro atualizado com sucesso!\n");
            return;
        }
    }

    printf("Usuário ID %d não encontrado!\n", id);
}

void excluir(Usuario usuarios[], int *totalCadastrados, int id)
{
    if (*totalCadastrados == 0)
    {
        printf("Cadastro de usuarios vazio\n");
        return;
    }

    for (int i = 0; i < *totalCadastrados; i++)
    {
        if (usuarios[i].id == id)
        {
            for (int j = i; j < *totalCadastrados - 1; j++)
            {
                usuarios[j] = usuarios[j + 1];
            }
            (*totalCadastrados)--;
            printf("Usuário ID %d excluído com sucesso!\n", id);
            return;
        }
    }

    printf("Usuário ID %d não encontrado!\n", id);
}
