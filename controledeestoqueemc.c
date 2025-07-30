#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEM 100
#define ARQUIVO "estoque.txt"
#define TEMP "temp.txt"

int main(){
    int a=0,b=0,c=0,w=0,x=0,y=0,z=0;
    int contagem=0, teste=0, quanti=0, numeroa=0;
    char s[99];
    char t[99];
    char caractere;
    FILE *p, *temp;
    for(a=0; a<256; a++){
        printf("===============================\n");
        printf("   Controle de Estoque\n");
        printf("===============================\n");
        printf("Selecione uma opcao:\n");
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Estoque\n");
        printf("4. Sair\n");
        printf("Opcao: ");

        if(scanf("%d", &x)!=1){
            while(getchar()!= '\n');
        printf("\nOpcao invalida! Tente novamente.\n\n");
        continue;
        }

        if(x<1 || x>4){
            printf("\nOpcao invalida! Tente novamente.\n\n");
        }

        if(x==1){
            printf("\nDigite o nome do item: ");
            scanf("%s", s);
            printf("Digite a quantidade: ");
            scanf("%d", &y);

            p=fopen("estoque.txt", "a");
            fprintf(p, "%s\n", s);
            fprintf(p, "%d\n", y);
            fclose(p);

            printf("Item adicionado com sucesso!\n\n");
            for(b=0; b<256; b++){
                    printf("Deseja realizar outra operacao? (s/n):");
                    scanf(" %c", &caractere);
        if(caractere=='s' || caractere=='S'){
            printf("\n\n\n");
            break;
        }
        if(caractere=='n' || caractere=='N'){
            printf("Obrigado por usar o Controle de Estoques! Ate a proxima.\n");
            a=256;
            break;
        }
        printf("Respota invalida. Por favor, digite 's' para sim ou 'n' para nao\n\n");
        }
        }

        if(x==2){




    char nomeItem[MAX_ITEM];
    int qtdRemover;
    int encontrado = 0;

    printf("Digite o nome do item: ");
    scanf(" %[^\n]", nomeItem);

    printf("Digite a quantidade a ser removida: ");
    scanf("%d", &qtdRemover);

    FILE *arquivo = fopen(ARQUIVO, "r");
    FILE *temp = fopen(TEMP, "w");

    if (!arquivo || !temp) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    char linhaItem[MAX_ITEM];
    char linhaQtd[20];

    while (fgets(linhaItem, sizeof(linhaItem), arquivo) && fgets(linhaQtd, sizeof(linhaQtd), arquivo)) {
        // Remover '\n' do final da linha do item
        linhaItem[strcspn(linhaItem, "\n")] = '\0';

        int qtd = atoi(linhaQtd);

        if (strcmp(linhaItem, nomeItem) == 0) {
            encontrado = 1;

            if (qtdRemover <= qtd) {
                int novaQtd = qtd - qtdRemover;
                if (novaQtd > 0) {
                    fprintf(temp, "%s\n%d\n", linhaItem, novaQtd);
                    printf("Quantidade atualizada com sucesso!\n");
                } else {
                    printf("Item removido do estoque.\n");
                    // não escreve no novo arquivo, item removido
                }
            } else {
                fprintf(temp, "%s\n%d\n", linhaItem, qtd); // mantém no novo arquivo
                printf("Estoque insuficiente. Quantidade disponivel: %d\n", qtd);
            }
        } else {
            // Copia o item e a quantidade como estão
            fprintf(temp, "%s\n%d\n", linhaItem, qtd);
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (!encontrado) {
        printf("Item nao encontrado.\n");
        remove(TEMP);
    } else {
        remove(ARQUIVO);
        rename(TEMP, ARQUIVO);
    }

    return 0;
}
        if(x==3){
            p=fopen("estoque.txt", "r");
            if(p==NULL){
                printf("\nErro ao abrir o arquivo\n\n");
            }
            printf("\n");
            printf("===============================\n");
            printf("   Estoque atual\n");
            printf("===============================\n");
            fseek(p, 0, SEEK_END);
                 if (ftell(p) == 0) {
                 printf("O estoque esta vazio\n");
                 break;
                 }
                 rewind(p);

            while(feof(p)==0){
                fgets(t, 99, p);
                if(t[0]=='\0'){
                    break;
                }
                if(contagem%2==0){
                    printf("Nome: %s", t);
                }else{
                    printf("Quantidade: %s", t);
                }
                contagem=contagem+1;
                t[0]='\0';
            }
            fclose(p);
            printf("\n");
            break;
        }

        if(x==4){
            printf("\nObrigado por usar o Controle de Estoques! Ate a proxima.\n");
            break;
        }
    }
}