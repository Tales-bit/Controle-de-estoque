#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int a,b,c,w,x,y,z;
    char s[99];
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
            fprintf(p, "\n%s", s);
            fprintf(p, "\n%d", y);
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
            char procura[99];
            printf("\nDigite o nome do item: ");
            scanf("%s", procura);
            printf("Digite a quantidade a ser removida: ");
            scanf("%d", &z);

            p=fopen("estoque.txt", "r");
            int num;
            if(p==NULL){
                printf("Erro");
             }else{
                 while(feof(p)==0){
                        char pro[99];
                        fgets(pro, 99, p);
                        strtok(pro, "\n");
                        if(strcmp(procura, pro)==0){
                                fscanf(p, "%d", &num);
                                fclose(p);
                                printf("Sucesso %d", num);
                                break;
                        }

                 }
                 if(z==num){
                    printf("Deletado");
char buffer[256];
char lineToRemove[256];
strcpy(lineToRemove, procura);

// Open original file in read mode
p = fopen("estoque.txt", "r");
// Open a temporary file in write mode
temp = fopen("temp.txt", "w");

while (fgets(buffer, sizeof(buffer), p) != NULL) {
    // Remove newline character from buffer
    strtok(buffer, "\n");
    // Compare and write non-matching lines
    if (strcmp(buffer, lineToRemove) != 0) {
        fprintf(temp, "%s\n", buffer);
    }
}
fclose(p);
fclose(temp);
                 }

                 if(z>num){
                    printf("Estoque insuficiente");
                 }
                 if(z<num){
                    num=num-z;
                 }






                 printf("\n");
                 fclose(p);
                 fclose(temp);
                 break;
             }
        }

        if(x==3){
            printf("\n===============================\n");
            printf("       Estoque Atual\n");
            printf("===============================\n");

             p=fopen("estoque.txt", "r");
             if(p==NULL){
                printf("Erro");
             }else{
                 while(feof(p)==0){
                        char est[99];
                        fgets(est, 99, p);
                        printf("%s", est);

                 }
                 printf("\n");
                 fclose(p);
                 break;
             }
        }

        if(x==4){
            printf("\nObrigado por usar o Controle de Estoques! Ate a proxima.\n");
            break;
        }
    }
}
