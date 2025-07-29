#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int a=0,b=0,c=0,w=0,x=0,y=0,z=0;
    int contagem=0, teste=0;
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

        if(x==3){
            p=fopen("estoque.txt", "r");
            if(p==NULL){
                printf("\nErro ao abrir o arquivo\n\n");

            }
            printf("\n");
            printf("===============================\n");
            printf("   Estoque atual\n");
            printf("===============================\n");
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
