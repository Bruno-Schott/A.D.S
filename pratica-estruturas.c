#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100
#define TAM_STRING 100

struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel;
};

struct Emprestimo {  
    int indiceLivro;
    char nomeUsuario[TAM_STRING];
};

void limparBufferEntrada() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;  

    biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));
    emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro: Falha ao alocar memoria. \n");
        return 1;
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    do {
        printf("\n===================\n");
        printf("  Biblioteca parte 2\n");
        printf("===================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Realizar emprestimo\n");
        printf("4 - Listar emprestimos\n");
        printf("0 - Sair\n");
        printf("===================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1: {
                printf("\n--- Cadastro de Novo Livro ---\n");
                if (totalLivros < MAX_LIVROS) {
                    printf("Digite o nome do Livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);
                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';

                    printf("Digite o autor: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';

                    printf("Digite a editora: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                    printf("Digite a edicao: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBufferEntrada();

                    biblioteca[totalLivros].disponivel = 1;  

                    printf("\nLivro cadastrado com sucesso!\n");
                    totalLivros++;
                } else {
                    printf("\nErro: Limite maximo de livros atingido!\n");
                }
                break;
            }

            case 2: {
                printf("\n--- Lista de Todos os Livros ---\n");
                if (totalLivros == 0) {
                    printf("Nenhum livro cadastrado.\n");
                } else {
                    for (int i = 0; i < totalLivros; i++) {
                        printf("\nLivro %d:\n", i + 1);
                        printf("  Nome: %s\n", biblioteca[i].nome);
                        printf("  Autor: %s\n", biblioteca[i].autor);
                        printf("  Editora: %s\n", biblioteca[i].editora);
                        printf("  Edicao: %d\n", biblioteca[i].edicao);
                        printf("  Disponivel: %s\n", biblioteca[i].disponivel ? "Sim" : "Nao");
                    }
                }
                break;
            }

            case 3: {
                printf("\n--- Realizar Emprestimo ---\n");
                if (totalLivros == 0) {
                    printf("Nenhum livro cadastrado para emprestimo.\n");
                    break;
                }

                if (totalEmprestimos >= MAX_EMPRESTIMOS) {
                    printf("Limite maximo de emprestimos atingido!\n");
                    break;
                }

                // Listar livros disponíveis
                printf("Livros disponiveis:\n");
                int livrosDisponiveis = 0;
                for (int i = 0; i < totalLivros; i++) {
                    if (biblioteca[i].disponivel) {
                        printf("%d - %s (%s)\n", i + 1, biblioteca[i].nome, biblioteca[i].autor);
                        livrosDisponiveis++;
                    }
                }

                if (livrosDisponiveis == 0) {
                    printf("Nenhum livro disponivel no momento.\n");
                    break;
                }

                int escolhaLivro;
                printf("\nEscolha o numero do livro: ");
                scanf("%d", &escolhaLivro);
                limparBufferEntrada();

                if (escolhaLivro < 1 || escolhaLivro > totalLivros) {
                    printf("Numero de livro invalido!\n");
                    break;
                }

                int indiceLivro = escolhaLivro - 1;
                if (!biblioteca[indiceLivro].disponivel) {
                    printf("Este livro ja esta emprestado!\n");
                    break;
                }

                printf("Digite o nome do usuario: ");
                fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario, "\n")] = '\0';

                emprestimos[totalEmprestimos].indiceLivro = indiceLivro;
                biblioteca[indiceLivro].disponivel = 0;  

                printf("\nEmprestimo realizado com sucesso!\n");
                totalEmprestimos++;
                break;
            }

            case 4: {
                printf("\n--- Lista de Emprestimos ---\n");
                if (totalEmprestimos == 0) {
                    printf("Nenhum emprestimo realizado.\n");
                } else {
                    for (int i = 0; i < totalEmprestimos; i++) {
                        int indiceLivro = emprestimos[i].indiceLivro;
                        printf("\nEmprestimo %d:\n", i + 1);
                        printf("  Livro: %s\n", biblioteca[indiceLivro].nome);
                        printf("  Autor: %s\n", biblioteca[indiceLivro].autor);
                        printf("  Usuario: %s\n", emprestimos[i].nomeUsuario);
                    }
                }
                break;
            }

            case 0: {
                printf("\nSaindo do sistema...\n");
                break;
            }

            default: {
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
            }
        }

    } while (opcao != 0);


    free(biblioteca);
    free(emprestimos);

    return 0;
}
