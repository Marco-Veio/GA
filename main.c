#include <stdio.h>
#include <stdlib.h>
#include "ga.h"
#include "menu.h"

int main()
{
    Ponto *p=NULL,inicial;
    Vetor *v=NULL,diretor;
    Reta *r=NULL;
    Plano *pl=NULL;
    int next,e1,e2,e3,e4;
    float x,y,z,a,b,c,d;
    double alfa,beta,gama;
    system("color f0");
    while(1){
        system("title Pontos/Vetores/Retas/Planos");
        next=0;
        switch(menu(5,"Escolha uma opcao:","Pontos|Vetores|Retas|Planos|Sair|",0,175,174,0,12,10)){
            case -1:
            case 4: return 0;
            case 0:
                do{
                    system("title Pontos");
                    switch(menu(12,"Escolha uma opcao","Criar Ponto|Remover Ponto|Limpar Lista|Listar Pontos|Acessar Ponto|Modificar Ponto|Trocar Pontos|Distancia|Coordenada Cilindrica|Coordenada Esferica|Voltar|Sair|",0,175,174,0,12,10)){
                        case -2:
                        case 10: next=1;break;
                        case -1:
                        case 11: return 0;
                        case 0:
                            printf("Qual o valor de x? ");
                            scanf("%f",&x);
                            fflush(stdin);
                            printf("Qual o valor de y? ");
                            scanf("%f",&y);
                            fflush(stdin);
                            printf("Qual o valor de z? ");
                            scanf("%f",&z);
                            fflush(stdin);
                            criarp(&p,x,y,z);
                            printf("Ponto criado!\n");
                            system("pause");
                            break;
                        case 1:
                            if(quantp(&p)){
                                e1=menu(quantp(&p),"Qual ponto deseja remover?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                removerp(&p,e1);
                                printf("Ponto removido!\n");
                            }else
                                printf("Nao ha pontos!\n");
                            system("pause");
                            break;
                        case 2:
                            if(quantp(&p)){
                                limparp(&p);
                                printf("Lista limpa!\n");
                            }else
                                printf("Nao ha pontos!\n");
                            system("pause");
                            break;
                        case 3:
                            if(quantp(&p))
                                listarp(&p);
                            else
                                printf("Nao ha pontos!\n");
                            system("pause");
                            break;
                        case 4:
                            if(quantp(&p)){
                                e1=menu(quantp(&p),"Qual ponto deseja acessar?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                acessarp(&p,e1,&x,&y,&z);
                                printf("Seu ponto eh: (%f;%f;%f).\n",x,y,z);
                            }else
                                printf("Nao ha pontos!\n");
                            system("pause");
                            break;
                        case 5:
                            if(quantp(&p)){
                                e1=menu(quantp(&p),"Qual ponto deseja modificar?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                printf("Qual o novo valor de x? ");
                                scanf("%f",&x);
                                fflush(stdin);
                                printf("Qual o novo valor de y? ");
                                scanf("%f",&y);
                                fflush(stdin);
                                printf("Qual o novo valor de z? ");
                                scanf("%f",&z);
                                fflush(stdin);
                                modificarp(&p,x,y,z,e1);
                                printf("Ponto modificado!\n");
                            }else
                                printf("Nao ha pontos!\n");
                            system("pause");
                            break;
                        case 6:
                            if(quantp(&p)){
                                e1=menu(quantp(&p),"Qual o primeiro ponto?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantp(&p),"Qual o segundo ponto?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                trocarp(&p,e1,e2);
                                printf("Pontos trocados!\n");
                            }else
                                printf("Nao ha pontos!\n");
                            system("pause");
                            break;
                        case 7:
                            if(quantp(&p)){
                                e1=menu(quantp(&p),"Qual o primeiro ponto?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantp(&p),"Qual o segundo ponto?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                printf("A distancia entre os pontos eh: %f\n",distanciap(&p,&v,e1,e2));
                            }else
                                printf("Nao ha pontos!\n");
                            system("pause");
                            break;
                        case 8:
                            if(quantp(&p)){
                                e1=menu(quantp(&p),"Qual ponto?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(2,"Deseja receber o angulo em:","Graus|Radianos|",0,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                cilindricap(&p,e1,e2,&x,&alfa,&z);
                                printf("Seu ponto eh: (%f;%f;%f).\n",x,alfa,z);
                            }else
                                printf("Nao ha pontos!\n");
                            system("pause");
                            break;
                        case 9:
                            if(quantp(&p)){
                                e1=menu(quantp(&p),"Qual ponto?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(2,"Deseja receber os angulos em:","Graus|Radianos|",0,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                esfericap(&p,e1,e2,&x,&alfa,&beta);
                                printf("Seu ponto eh: (%f;%f;%f).\n",x,alfa,beta);
                            }else
                                printf("Nao ha pontos!\n");
                            system("pause");
                            break;
                    }
                }while(!next);
                break;
            case 1:
                do{
                    system("title Vetores");
                    switch(menu(20,"Escolha uma opcao","Criar vetor|Remover Vetor|Limpar Lista|Listar Vetores|Acessar Vetor|Modificar Vetor|Trocar Vetores|Modulo|Paralelismo|Ortogonalidade|Coplanaridade|Produto Escalar|Produto Vetorial|Produto Misto|Angulo Entre Vetores|Angulos Diretores|Projecao|Vetor Unitario|Voltar|Sair|",0,175,174,0,12,10)){
                        case -2:
                        case 18: next=1;break;
                        case -1:
                        case 19: return 0;
                        case 0:
                            e1=menu(2,"Criar vetor atraves de:","Dois pontos|Valores dos eixos|",0,175,174,0,12,10);
                            if(e1==-1)
                                return 0;
                            if(e1==-2)
                                break;
                            if(e1){
                                printf("Qual o valor de a? ");
                                scanf("%f",&a);
                                fflush(stdin);
                                printf("Qual o valor de b? ");
                                scanf("%f",&b);
                                fflush(stdin);
                                printf("Qual o valor de c? ");
                                scanf("%f",&c);
                                fflush(stdin);
                            }else{
                                if(quantp(&p)){
                                    e2=menu(quantp(&p),"Qual o primeiro ponto?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    e3=menu(quantp(&p),"Qual o segundo ponto?","",1,175,174,0,12,10);
                                    if(e3==-1)
                                        return 0;
                                    if(e3==-2)
                                        break;
                                }else{
                                    printf("Nao ha pontos!\n");
                                    system("pause");
                                    break;
                                }
                            }
                            criarv(&v,&p,a,b,c,e2,e3,e1);
                            printf("Vetor criado!\n");
                            system("pause");
                            break;
                        case 1:
                            if(quantv(&v)){
                                e1=menu(quantv(&v),"Qual vetor deseja remover?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                removerv(&v,e1);
                                printf("Vetor removido!\n");
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 2:
                            if(quantv( &v)){
                                limparv(&v);
                                printf("Lista limpa!\n");
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 3:
                            if(quantv(&v))
                                listarv(&v);
                            else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 4:
                            if(quantv(&v)){
                                e1=menu(quantv(&v),"Qual vetor deseja acessar?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                acessarv(&v,e1,&a,&b,&c);
                                printf("Seu vetor eh: (%f;%f;%f).\n",a,b,c);
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 5:
                            if(quantv(&v)){
                                e1=menu(quantv(&v),"Qual vetor deseja modificar?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                printf("Qual o novo valor de a? ");
                                scanf("%f",&a);
                                fflush(stdin);
                                printf("Qual o novo valor de b? ");
                                scanf("%f",&b);
                                fflush(stdin);
                                printf("Qual o novo valor de c? ");
                                scanf("%f",&c);
                                fflush(stdin);
                                modificarv(&v,a,b,c,e1);
                                printf("Vetor modificado!\n");
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 6:
                            if(quantv(&v)){
                                e1=menu(quantv(&v),"Qual o primeiro vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantv(&v),"Qual o segundo vetor?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                trocarv(&v,e1,e2);
                                printf("Vetores trocados!\n");
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 7:
                            if(quantv(&v)){
                                e1=menu(quantv(&v),"Qual vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                printf("O modulo do vetor eh %f!\n",modulov(&v,e1));
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 8:
                            if(quantv(&v)){
                                e1=menu(quantv(&v),"Qual o primeiro vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantv(&v),"Qual o segundo vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                if(paralelov(&v,e1,e2))
                                    printf("Esses vetores sao paralelos!\n");
                                else
                                    printf("Esses vetores nao sao paralelos!\n");
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 9:
                            if(quantv(&v)){
                                e1=menu(quantv(&v),"Qual o primeiro vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantv(&v),"Qual o segundo vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                if(ortogonalv(&v,e1,e2))
                                    printf("Esses vetores sao ortogonais!\n");
                                else
                                    printf("Esses vetores nao sao ortogonais!\n");
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 10:
                            if(quantv(&v)){
                                e1=menu(quantv(&v),"Qual o primeiro vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantv(&v),"Qual o segundo vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e3=menu(quantv(&v),"Qual o terceiro vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                if(coplanarv(&v,e1,e2,e3))
                                    printf("Os vetores sao coplanares!\n");
                                else
                                    printf("Os vetores nao sao coplanares!\n");
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 11:
                            if(quantv(&v)){
                                e1=menu(quantv(&v),"Qual o primeiro vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantv(&v),"Qual o segundo vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                printf("O produto escalar entre esses vetores eh %f!\n",produtoescalarv(&v,e1,e2));
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 12:
                            if(quantv(&v)){
                                e1=menu(quantv(&v),"Qual o primeiro vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantv(&v),"Qual o segundo vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                produtovetorialv(&v,e1,e2,&a,&b,&c);
                                printf("O produto vetorial entre esses vetores eh (%f;%f;%f).\n",a,b,c);
                                system("pause");
                                e1=menu(2,"Deseja adicionar esse vetor? ","Sim|Nao|",0,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                if(!e1){
                                    criarv(&v,&p,a,b,c,0,0,1);
                                    printf("Vetor adicionado!\n");
                                }
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 13:
                            if(quantv(&v)){
                                e1=menu(quantv(&v),"Qual o primeiro vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantv(&v),"Qual o segundo vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e3=menu(quantv(&v),"Qual o terceiro vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                printf("O produto misto entre esses vetores eh %f!\n",produtomistov(&v,e1,e2,e3));
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 14:
                            if(quantv(&v)){
                                e1=menu(2,"Deseja receber o angulo em:","Graus|Radianos|",0,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantv(&v),"Qual o primeiro vetor?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                e3=menu(quantv(&v),"Qual o segundo vetor?","",1,175,174,0,12,10);
                                if(e3==-1)
                                    return 0;
                                if(e3==-2)
                                    break;
                                printf("O angulo entre esses vetores eh %f.\n",angulov(&v,e2,e3,e1));
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 15:
                            if(quantv(&v)){
                                e1=menu(2,"Deseja receber o angulo em:","Graus|Radianos|",0,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantv(&v),"Qual vetor?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                angulosdiretoresv(&v,e2,e1,&alfa,&beta,&gama);
                                printf("Os angulos diretores sao:\nAlfa=%f\nBeta=%f\nGama=%f\n",alfa,beta,gama);
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 16:
                            if(quantv(&v)){
                                e1=menu(quantv(&v),"Projecao do vetor:","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantv(&v),"Sobre o vetor:","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                projecaov(&v,e1,e2,&a,&b,&c);
                                printf("O vetor projecao eh (%f;%f;%f).\n",a,b,c);
                                system("pause");
                                e1=menu(2,"Deseja adicionar esse vetor? ","Sim|Nao|",0,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                if(!e1){
                                    criarv(&v,&p,a,b,c,0,0,1);
                                    printf("Vetor adicionado!\n");
                                }
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                        case 17:
                            if(quantv(&v)){
                                e1=menu(quantv(&v),"Qual vetor?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                unitariov(&v,e1,&a,&b,&c);
                                printf("O vetor unitario eh (%f;%f;%f).\n",a,b,c);
                                system("pause");
                                e1=menu(2,"Deseja adicionar esse vetor? ","Sim|Nao|",0,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                if(!e1){
                                    criarv(&v,&p,a,b,c,0,0,1);
                                    printf("Vetor adicionado!\n");
                                }
                            }else
                                printf("Nao ha vetores!\n");
                            system("pause");
                            break;
                    }
                }while(!next);
                break;
            case 2:
                do{
                    system("title Retas");
                    switch(menu(15,"Escolha uma opcao:","Criar Reta|Remover Reta|Limpar Lista|Listar Retas|Acessar Reta|Modificar Reta|Trocar Retas|Angulo entre retas|Posicao Relativa Entre Retas|Interseccao|Distancia Entre Ponto e Reta|Distancia Entre Retas|Ponto Pertencente a uma Reta|Voltar|Sair|",0,175,174,0,12,10)){
                        case -2:
                        case 13: next=1;break;
                        case -1:
                        case 14: return 0;
                        case 0:
                            e1=menu(3,"Criar reta atraves de:","Vetor e Ponto|Dois pontos|Equacao Vetorial|",0,175,174,0,12,10);
                            if(e1==-1)
                                return 0;
                            if(e1==-2)
                                break;
                            if(e1!=2 && ((!e1 && quantv(&v) && quantp(&p)) || (e1 && quantp(&p)))){
                                e2=menu(quantp(&p),"Qual o ponto inicial?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                if(e1){
                                    e3=menu(quantp(&p),"Qual o segundo ponto?","",1,175,174,0,12,10);
                                    if(e3==-1)
                                        return 0;
                                    if(e3==-2)
                                        break;
                                }else{
                                    e3=menu(quantv(&v),"Qual o vetor diretor?","",1,175,174,0,12,10);
                                    if(e3==-1)
                                        return 0;
                                    if(e3==-2)
                                        break;
                                }
                            }else{
                                if(e1==2){
                                    printf("Qual o valor de x0? ");
                                    scanf("%f",&x);
                                    fflush(stdin);
                                    printf("Qual o valor de y0? ");
                                    scanf("%f",&y);
                                    fflush(stdin);
                                    printf("Qual o valor de z0? ");
                                    scanf("%f",&z);
                                    fflush(stdin);
                                    printf("Qual o valor de a? ");
                                    scanf("%f",&a);
                                    fflush(stdin);
                                    printf("Qual o valor de b? ");
                                    scanf("%f",&b);
                                    fflush(stdin);
                                    printf("Qual o valor de c? ");
                                    scanf("%f",&c);
                                    fflush(stdin);
                                }else{
                                    if(!e1 && !quantv(&v))
                                        printf("Nao ha vetores!\n");
                                    else
                                        printf("Nao ha pontos!\n");
                                        system("pause");
                                        break;
                                }
                            }
                            criarr(&r,&v,&p,x,y,z,a,b,c,e2,e3,e1);
                            printf("Reta criada!\n");
                            system("pause");
                            break;
                        case 1:
                            if(quantr(&r)){
                                e1=menu(quantr(&r),"Qual reta deseja remover?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                removerr(&r,e1);
                                printf("Reta removida!\n");
                            }else
                                printf("Nao ha retas!\n");
                            system("pause");
                            break;
                        case 2:
                            if(quantr(&r)){
                                limparr(&r);
                                printf("Lista limpa!\n");
                            }else
                                printf("Nao ha retas!\n");
                            system("pause");
                            break;
                        case 3:
                            if(quantr(&r))
                                listarr(&r);
                            else
                                printf("Nao ha retas!\n");
                            system("pause");
                            break;
                        case 4:
                            if(quantr(&r)){
                                e1=menu(quantr(&r),"Qual reta deseja acessar?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                acessarr(&r,e1,&inicial,&diretor);
                                printf("Sua reta eh: (x,y,z)=(%f;%f;%f)+t(%f;%f;%f).\n",inicial.x,inicial.y,inicial.z,diretor.a,diretor.b,diretor.c);
                            }else
                                printf("Nao ha retas!\n");
                            system("pause");
                            break;
                        case 5:
                            if(quantr(&r)){
                                if(quantp(&p) && quantv(&v)){
                                    e1=menu(quantr(&r),"Qual reta deseja modificar?","",1,175,174,0,12,10);
                                    if(e1==-1)
                                        return 0;
                                    if(e1==-2)
                                        break;
                                    e2=menu(quantp(&p),"Qual sera o novo ponto inicial?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    e3=menu(quantv(&v),"Qual sera o novo vetor diretor?","",1,175,174,0,12,10);
                                    if(e3==-1)
                                        return 0;
                                    if(e3==-2)
                                        break;
                                    modificarr(&r,&v,&p,e1,e3,e2);
                                }else{
                                    if(quantv(&v))
                                        printf("Nao ha pontos!\n");
                                    else
                                        printf("Nao ha vetores!\n");
                                }
                            }else
                                printf("Nao ha retas!\n");
                            system("pause");
                            break;
                        case 6:
                            if(quantr(&r)){
                                e1=menu(quantr(&r),"Qual a primeira reta?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantr(&r),"Qual a segunda reta?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                trocarr(&r,&v,&p,e1,e2);
                                printf("Retas trocadas!\n");
                            }else
                                printf("Nao ha retas!\n");
                            system("pause");
                            break;
                        case 7:
                            if(quantr(&r)){
                                e1=menu(2,"Deseja receber o angulo em:","Graus|Radianos|",0,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantr(&r),"Qual a primeira reta?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                e3=menu(quantr(&r),"Qual a segunda reta?","",1,175,174,0,12,10);
                                if(e3==-1)
                                    return 0;
                                if(e3==-2)
                                    break;
                                printf("O angulo entre essas retas eh %f.\n",angulor(&r,&v,e2,e3,e1));
                            }else
                                printf("Nao ha retas!\n");
                            system("pause");
                            break;
                        case 8:
                            if(quantr(&r)){
                                e1=menu(quantr(&r),"Qual a primeira reta?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantr(&r),"Qual a segunda reta?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                switch(posicaorelativar(&r,&v,e1,e2)){
                                    case 0: printf("Retas Reversas!\n"); break;
                                    case 1: printf("Retas Coplanares Concorrentes!\n"); break;
                                    case 2: printf("Retas Coplanares Paralelas!\n"); break;
                                }
                            }else
                                printf("Nao ha retas!\n");
                            system("pause");
                            break;
                        case 9:
                            if(quantr(&r)){
                                e1=menu(quantr(&r),"Qual a primeira reta?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantr(&r),"Qual a segunda reta?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                if(interseccaor(&r,&v,e1,e2,&x,&y,&z)==1){
                                    printf("O ponto de interseccao eh: (%f;%f;%f).\n",x,y,z);
                                    system("pause");
                                    e1=menu(2,"Deseja adicionar esse ponto?","Sim|Nao|",0,175,174,0,12,10);
                                    if(e1==-1)
                                        return 0;
                                    if(e1==-2)
                                        break;
                                    if(!e1){
                                        criarp(&p,x,y,z);
                                        printf("Ponto adicionado!\n");
                                    }
                                }else
                                    printf("Nao ha interseccao!\n");
                            }else
                                printf("Nao ha retas!\n");
                            system("pause");
                            break;
                        case 10:
                            if(quantr(&r)){
                                if(quantp(&p)){
                                    e1=menu(quantp(&p),"Qual o ponto?","",1,175,174,0,12,10);
                                    if(e1==-1)
                                        return 0;
                                    if(e1==-2)
                                        break;
                                    e2=menu(quantr(&r),"Qual a reta?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    printf("A distancia entre o ponto e a reta eh: %f!\n",distanciapr(&r,&v,&p,e2,e1));
                                }else
                                    printf("Nao ha pontos!\n");
                            }else
                                printf("Nao ha retas!\n");
                            system("pause");
                            break;
                        case 11:
                            if(quantr(&r)){
                                e1=menu(quantr(&r),"Qual a primeira reta?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantr(&r),"Qual a segunda reta?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                printf("A distancia entre as reta eh: %f!\n",distanciarr(&r,&v,&p,e1,e2));
                            }else
                                printf("Nao ha retas!\n");
                            system("pause");
                            break;
                        case 12:
                            if(quantr(&r)){
                                if(quantp(&p)){
                                    e1=menu(quantp(&p),"Qual o ponto?","",1,175,174,0,12,10);
                                    if(e1==-1)
                                        return 0;
                                    if(e1==-2)
                                        break;
                                    e2=menu(quantr(&r),"Qual a reta?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    if(pontopertenceareta(&r,&v,&p,e2,e1))
                                        printf("O ponto pertence a reta!\n");
                                    else
                                        printf("O ponto nao pertence a reta!\n");
                                }else
                                    printf("Nao ha pontos!\n");
                            }else
                                printf("Nao ha retas!\n");
                            system("pause");
                            break;
                    }
                }while(!next);
                break;
            case 3:
                do{
                    system("title Planos");
                    e1=0;e2=0;e3=0;e4=0;
                    switch(menu(21,"Escolha uma opcao:","Criar Plano|Remover Plano|Limpar Lista|Listar Planos|Acessar Plano|Modificar Plano|Paralelismo Entre Reta e Plano|Ortogonalidade Entre Reta e Plano|Paralelismo Entre Planos|Ortogonalidade Entre Planos|Angulo Entre Reta e Plano|Angulo Entre Planos|Interseccao de Reta e Plano|Interseccao de 2 Planos|Distancia Entre Ponto e Plano|Distancia Entre Reta e Plano|Distancia Entre Planos|Ponto Pertencente a um Plano|Reta Pertencente a um Plano|Voltar|Sair|",0,175,174,0,12,10)){
                        case -2:
                        case 19: next=1;break;
                        case -1:
                        case 20: return 0;
                        case 0:
                            e1=menu(7,"Criar plano atraves de:","Vetor Normal e Ponto|2 Vetores Base e Ponto|Vetor Base e 2 Pontos|3 Pontos|2 Retas|Reta e Ponto|Equacao|",0,175,174,0,12,10);
                            switch(e1){
                                case -1: return 0;
                                case -2: break;
                                case 0:
                                    if(!quantv(&v)){
                                        printf("Nao ha vetores!\n");
                                        system("pause");
                                        e1=-2;
                                        break;
                                    }
                                    if(!quantp(&p)){
                                        printf("Nao ha pontos!\n");
                                        system("pause");
                                        e1=-2;
                                        break;
                                    }
                                    e2=menu(quantv(&v),"Qual o vetor normal?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    e3=menu(quantp(&p),"Qual o ponto pertencente?","",1,175,174,0,12,10);
                                    if(e3==-1)
                                        return 0;
                                    break;
                                case 1:
                                    if(!quantv(&v)){
                                        printf("Nao ha vetores!\n");
                                        system("pause");
                                        e1=-2;
                                        break;
                                    }
                                    if(!quantp(&p)){
                                        printf("Nao ha pontos!\n");
                                        system("pause");
                                        e1=-2;
                                        break;
                                    }
                                    e2=menu(quantv(&v),"Qual o primeiro vetor base?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    e3=menu(quantv(&v),"Qual o segundo vetor base?","",1,175,174,0,12,10);
                                    if(e3==-1)
                                        return 0;
                                    if(e3==-2)
                                        break;
                                    e4=menu(quantp(&p),"Qual o ponto pertencente?","",1,175,174,0,12,10);
                                    if(e4==-1)
                                        return 0;
                                    break;
                                case 2:
                                    if(!quantv(&v)){
                                        printf("Nao ha vetores!\n");
                                        system("pause");
                                        e1=-2;
                                        break;
                                    }
                                    if(!quantp(&p)){
                                        printf("Nao ha pontos!\n");
                                        system("pause");
                                        e1=-2;
                                        break;
                                    }
                                    e2=menu(quantv(&v),"Qual o  vetor base?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    e3=menu(quantp(&p),"Qual o primeiro ponto pertencente?","",1,175,174,0,12,10);
                                    if(e3==-1)
                                        return 0;
                                    if(e3==-2)
                                        break;
                                    e4=menu(quantp(&p),"Qual o segundo ponto pertencente?","",1,175,174,0,12,10);
                                    if(e4==-1)
                                        return 0;
                                    break;
                                case 3:
                                    if(!quantp(&p)){
                                        printf("Nao ha pontos!\n");
                                        system("pause");
                                        e1=-2;
                                        break;
                                    }
                                    e2=menu(quantp(&p),"Qual o primeiro ponto pertencente?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    e3=menu(quantp(&p),"Qual o segundo ponto pertencente?","",1,175,174,0,12,10);
                                    if(e3==-1)
                                        return 0;
                                    if(e3==-2)
                                        break;
                                    e4=menu(quantp(&p),"Qual o terceiro ponto pertencente?","",1,175,174,0,12,10);
                                    if(e4==-1)
                                        return 0;
                                    break;
                                case 4:
                                    if(!quantr(&r)){
                                        printf("Nao ha retas!\n");
                                        system("pause");
                                        e1=-2;
                                        break;
                                    }
                                    e2=menu(quantr(&r),"Qual a primeira reta pertencente?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    e3=menu(quantr(&r),"Qual a segunda reta pertencente?","",1,175,174,0,12,10);
                                    if(e3==-1)
                                        return 0;
                                    break;
                                case 5:
                                    if(!quantr(&r)){
                                        printf("Nao ha retas!\n");
                                        system("pause");
                                        e1=-2;
                                        break;
                                    }
                                    if(!quantp(&p)){
                                        printf("Nao ha pontos!\n");
                                        system("pause");
                                        e1=-2;
                                        break;
                                    }
                                    e2=menu(quantr(&r),"Qual a reta pertencente?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    e3=menu(quantp(&p),"Qual o ponto pertencente?","",1,175,174,0,12,10);
                                    if(e3==-1)
                                        return 0;
                                    break;
                                case 6:
                                    printf("Qual o valor de a?\n");
                                    scanf("%f",&a);
                                    fflush(stdin);
                                    printf("Qual o valor de b?\n");
                                    scanf("%f",&b);
                                    fflush(stdin);
                                    printf("Qual o valor de c?\n");
                                    scanf("%f",&c);
                                    fflush(stdin);
                                    printf("Qual o valor de d?\n");
                                    scanf("%f",&d);
                                    fflush(stdin);
                            }
                            if(e1!=-2 && e2!=-2 && e3!=-2 && e4!=-2){
                                criarpl(&pl,&r,&v,&p,a,b,c,d,e2,e3,e4,e1);
                                printf("Plano criado!\n");
                                system("pause");
                            }
                            break;
                        case 1:
                            if(quantpl(&pl)){
                                e1=menu(quantpl(&pl),"Qual plano deseja remover?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                removerpl(&pl,e1);
                                printf("Plano removido!\n");
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 2:
                            if(quantpl(&pl)){
                                limparpl(&pl);
                                printf("Lista limpa!\n");
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 3:
                            if(quantpl(&pl))
                                listarpl(&pl);
                            else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 4:
                            if(quantpl(&pl)){
                                e1=menu(quantpl(&pl),"Qual plano deseja acessar?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                acessarpl(&pl,e1,&diretor,&d);
                                printf("Seu plano eh: (%f)x+(%f)y+(%f)z+(%f).\n",diretor.a,diretor.b,diretor.c,d);
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 5:
                            if(quantpl(&pl)){
                                if(quantv(&v)){
                                    e1=menu(quantpl(&pl),"Qual plano deseja modificar?","",1,175,174,0,12,10);
                                    if(e1==-1)
                                        return 0;
                                    if(e1==-2)
                                        break;
                                    e2=menu(quantv(&v),"Qual sera o novo vetor normal?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    printf("Qual o valor de d?\n");
                                    scanf("%f",&d);
                                    fflush(stdin);
                                    modificarpl(&pl,&v,d,e1,e2);
                                }else
                                    printf("Nao ha vetores!\n");
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 6:
                            if(quantpl(&pl)){
                                if(quantr(&r)){
                                    e1=menu(quantpl(&pl),"Qual o plano?","",1,175,174,0,12,10);
                                    if(e1==-1)
                                        return 0;
                                    if(e1==-2)
                                        break;
                                    e2=menu(quantr(&r),"Qual a reta?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    if(paralelorpl(&pl,&r,&v,&p,e1,e2))
                                        printf("Sao paralelos!\n");
                                    else
                                        printf("Nao sao paralelos!\n");
                                }else
                                    printf("Nao ha retas!\n");
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 7:
                            if(quantpl(&pl)){
                                if(quantr(&r)){
                                    e1=menu(quantpl(&pl),"Qual o plano?","",1,175,174,0,12,10);
                                    if(e1==-1)
                                        return 0;
                                    if(e1==-2)
                                        break;
                                    e2=menu(quantr(&r),"Qual a reta?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    if(ortogonalrpl(&pl,&r,&v,&p,e1,e2))
                                        printf("Sao ortogonais!\n");
                                    else
                                        printf("Nao sao ortogonais!\n");
                                }else
                                    printf("Nao ha retas!\n");
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 8:
                            if(quantpl(&pl)){
                                e1=menu(quantpl(&pl),"Qual o primeiro plano?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantpl(&pl),"Qual o segundo plano?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                if(paralelopl(&pl,&v,&p,e1,e2))
                                    printf("Sao paraleloss!\n");
                                else
                                    printf("Nao sao paralelos!\n");
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 9:
                            if(quantpl(&pl)){
                                e1=menu(quantpl(&pl),"Qual o primeiro plano?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantpl(&pl),"Qual o segundo plano?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                if(ortogonalpl(&pl,&v,&p,e1,e2))
                                    printf("Sao ortogonais!\n");
                                else
                                    printf("Nao sao ortogonais!\n");
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 10:
                            if(quantpl(&pl)){
                                if(quantr(&r)){
                                    e1=menu(2,"Deseja receber o angulo em:","Graus|Radianos|",0,175,174,0,12,10);
                                    if(e1==-1)
                                        return 0;
                                    if(e1==-2)
                                        break;
                                    e2=menu(quantpl(&pl),"Qual o plano?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    e3=menu(quantr(&r),"Qual a reta?","",1,175,174,0,12,10);
                                    if(e3==-1)
                                        return 0;
                                    if(e3==-2)
                                        break;
                                    printf("O angulo entre o plano e a reta eh %f.\n",angulorpl(&pl,&r,&v,&p,e2,e3,e1));
                                }else
                                    printf("Nao ha retas!\n");
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 11:
                            if(quantpl(&pl)){
                                e1=menu(2,"Deseja receber o angulo em:","Graus|Radianos|",0,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantpl(&pl),"Qual o primeiro plano?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                e3=menu(quantpl(&pl),"Qual o segundo plano?","",1,175,174,0,12,10);
                                if(e3==-1)
                                    return 0;
                                if(e3==-2)
                                    break;
                                printf("O angulo entre esses planos eh %f.\n",angulopl(&pl,&v,&p,e2,e3,e1));
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 12:
                            if(quantpl(&pl)){
                                if(quantr(&r)){
                                    e1=menu(quantpl(&pl),"Qual o plano?","",1,175,174,0,12,10);
                                    if(e1==-1)
                                        return 0;
                                    if(e1==-2)
                                        break;
                                    e2=menu(quantr(&r),"Qual a reta?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    if(interseccaorpl(&pl,&r,&v,&p,e1,e2,&x,&y,&z)==1){
                                        printf("A interseccao da reta e do plano eh: (%f;%f;%f)!\n",x,y,z);
                                        system("pause");
                                        e1=menu(2,"Deseja adicionar esse ponto? ","Sim|Nao|",0,175,174,0,12,10);
                                        if(e1==-1)
                                            return 0;
                                        if(e1==-2)
                                            break;
                                        if(!e1){
                                            criarp(&p,x,y,z);
                                            printf("Ponto adicionado!\n");
                                        }
                                    }else
                                        if(interseccaorpl(&pl,&r,&v,&p,e1,e2,&x,&y,&z))
                                            printf("Reta pertence ao plano!\n");
                                        else
                                            printf("Nao ha interseccao!\n");
                                }else
                                    printf("Nao ha retas!\n");
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 13:
                            if(quantpl(&pl)){
                                e1=menu(quantpl(&pl),"Qual o primeiro plano?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantpl(&pl),"Qual o segundo plano?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                if(interseccaopl(&pl,&v,&p,e1,e2,&a,&b,&c,&x,&y,&z)==1){
                                    printf("A interseccao dos planos eh: (x,y,z)=(%f;%f;%f)+t(%f;%f;%f)!\n",x,y,z,a,b,c);
                                    system("pause");
                                    e1=menu(2,"Deseja adicionar essa reta? ","Sim|Nao|",0,175,174,0,12,10);
                                    if(e1==-1)
                                        return 0;
                                    if(e1==-2)
                                        break;
                                    if(!e1){
                                        criarr(&r,&v,&p,x,y,z,a,b,c,0,0,2);
                                        printf("Reta adicionada!\n");
                                    }
                                }else
                                    if(interseccaopl(&pl,&v,&p,e1,e2,&a,&b,&c,&x,&y,&z))
                                        printf("Planos iguais!\n");
                                    else
                                        printf("Nao ha interseccao!\n");
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 14:
                            if(quantpl(&pl)){
                                if(quantp(&p)){
                                    e1=menu(quantp(&p),"Qual o ponto?","",1,175,174,0,12,10);
                                    if(e1==-1)
                                        return 0;
                                    if(e1==-2)
                                        break;
                                    e2=menu(quantpl(&pl),"Qual o plano?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    printf("A distancia entre o ponto e o plano eh: %f!\n",distanciappl(&pl,&v,&p,e2,e1));
                                }else
                                    printf("Nao ha pontos!\n");
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 15:
                            if(quantpl(&pl)){
                                if(quantr(&r)){
                                    e1=menu(quantr(&r),"Qual a reta?","",1,175,174,0,12,10);
                                    if(e1==-1)
                                        return 0;
                                    if(e1==-2)
                                        break;
                                    e2=menu(quantpl(&pl),"Qual o plano?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    printf("A distancia entre a reta e o plano eh: %f!\n",distanciarpl(&pl,&r,&v,&p,e2,e1));
                                }else
                                    printf("Nao ha retas!\n");
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 16:
                            if(quantpl(&pl)){
                                e1=menu(quantpl(&pl),"Qual o primeiro plano?","",1,175,174,0,12,10);
                                if(e1==-1)
                                    return 0;
                                if(e1==-2)
                                    break;
                                e2=menu(quantpl(&pl),"Qual o segundo plano?","",1,175,174,0,12,10);
                                if(e2==-1)
                                    return 0;
                                if(e2==-2)
                                    break;
                                printf("A distancia entre os planos eh: %f!\n",distanciapl(&pl,&v,&p,e2,e1));
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 17:
                            if(quantpl(&pl)){
                                if(quantp(&p)){
                                    e1=menu(quantp(&p),"Qual o ponto?","",1,175,174,0,12,10);
                                    if(e1==-1)
                                        return 0;
                                    if(e1==-2)
                                        break;
                                    e2=menu(quantpl(&pl),"Qual o plano?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    if(pontopertenceaoplano(&pl,&v,&p,e2,e1))
                                        printf("O ponto pertence ao plano!\n");
                                    else
                                        printf("O ponto nao pertence ao plano!\n");
                                }else
                                    printf("Nao ha pontos!\n");
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                        case 18:
                            if(quantpl(&pl)){
                                if(quantr(&r)){
                                    e1=menu(quantr(&r),"Qual a reta?","",1,175,174,0,12,10);
                                    if(e1==-1)
                                        return 0;
                                    if(e1==-2)
                                        break;
                                    e2=menu(quantpl(&pl),"Qual o plano?","",1,175,174,0,12,10);
                                    if(e2==-1)
                                        return 0;
                                    if(e2==-2)
                                        break;
                                    if(retapertenceaoplano(&pl,&r,&v,&p,e2,e1))
                                        printf("A reta pertence ao plano!\n");
                                    else
                                        printf("A reta nao pertence ao plano!\n");
                                }else
                                    printf("Nao ha retas!\n");
                            }else
                                printf("Nao ha planos!\n");
                            system("pause");
                            break;
                    }
                }while(!next);
        }
    }
}
