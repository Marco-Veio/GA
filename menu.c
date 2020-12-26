#include <stdio.h>
#include <stdlib.h>
#include "rlutil.h"

int menu(int tam,char frase[],char opcoes[],int frasenum,char simbolo1,char simbolo2,int cor_padrao,int cor_selecionada,int cor_simbolos){
    setCursorVisibility(0);
    int i,j,e=0;
    char escolha[tam][2],mov;
    do{
        system("cls");
        for (i=0;i<tam;i++){
            escolha[i][0]=' ';
            escolha[i][1]=' ';
        }
        escolha[e][0]=simbolo1;
        escolha[e][1]=simbolo2;
        setColor(cor_padrao);
        printf("%s\n",frase);
        if(!frasenum){
            for(i=0,j=0;opcoes[i]!=0;i++,j++){
                setColor(cor_simbolos);
                printf("%c ",escolha[j][0]);
                if(escolha[j][0]!=' ')
                    setColor(cor_selecionada);
                else
                    setColor(cor_padrao);
                for(;opcoes[i]!='|';i++)
                    printf("%c",opcoes[i]);
                setColor(cor_simbolos);
                printf(" %c \n",escolha[j][1]);
            }
        }else{
            for(i=0;i<tam;i++){
                setColor(cor_simbolos);
                printf("%c ",escolha[i][0]);
                if(escolha[i][0]!=' ')
                    setColor(cor_selecionada);
                else
                    setColor(cor_padrao);
                printf("%d ",i+1);
                setColor(cor_simbolos);
                printf("%c\n",escolha[i][1]);
            }
        }
        setColor(cor_padrao);
        do{
            do{
                mov=getch();
            }while(mov!=-32 && mov!='w' && mov!='s' && mov!=13 && mov!=27 && mov!=8 &&(mov<'1' && mov>tam+48));
            if(mov==-32)
                mov=getch();
        }while(mov!='H' && mov!='P' && mov!='w' && mov!='s' && mov!=13 && mov!=27 && mov!=8 &&(mov<'1' && mov>tam+48));
        if(tam<10 && mov>='1' && mov<=tam+48)
            e=mov-49;
        switch(mov){
            case 'w':
            case 'H':if(e>0) e--;else e=tam-1;break;
            case 's':
            case 'P':if(e<tam-1) e++;else e=0;break;
            case 27:return -1;break;
            case 8:return -2;break;
        }
    }while(mov!=13);
    system("cls");
    return e;
}
