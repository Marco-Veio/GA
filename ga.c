#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include "ga.h"
//angulo
double angconvert(double ang,int deg_rad){
    if(!deg_rad)
        return ang*57.295779513082320876798154814105;
    else
        return ang/57.295779513082320876798154814105;
}
//ponto
int quantp(Ponto **p){
    Ponto *currp=*p;
    int tam=0;
    for(;currp;currp=currp->next,tam++){}
    return tam;
}
void criarp(Ponto **p,float x,float y,float z){
    Ponto *prevp=*p,*newp=malloc(sizeof(Ponto));
    if(newp){
        newp->x=x;
        newp->y=y;
        newp->z=z;
        newp->next=NULL;
        if(!prevp)
            *p=newp;
        else{
            for(;prevp->next;prevp=prevp->next){}
            prevp->next=newp;
        }
    }else
        printf("Memoria insuficiente");
}
void removerp(Ponto **p,int e)
{
    Ponto *prevp,*nextp,*currp=*p;
    int i=0;
    if(e){
        for(;(i+1)<e;i++,currp=currp->next){}
        prevp=currp;
        currp=currp->next;
        nextp=currp->next;
        prevp->next=nextp;
    }else
        *p=currp->next;
    free(currp);
}
void limparp(Ponto **p){
    for(;quantp(p);removerp(p,quantp(p)-1)){}
}
void listarp(Ponto **p){
    Ponto *currp=*p;
    int i=1;
    for(;currp;currp=currp->next,i++)
        printf("Ponto %d: (%f;%f;%f)\n",i,currp->x,currp->y,currp->z);
}
void acessarp(Ponto **p,int e,float *x,float *y,float *z){
    Ponto *currp=*p;
    int i=0;
    for(;i<e;currp=currp->next,i++){}
    *x=currp->x;
    *y=currp->y;
    *z=currp->z;
}
void modificarp(Ponto **p,float x,float y,float z,int e){
    Ponto *currp=*p;
    int i=0;
    for(;i<e;currp=currp->next,i++){}
    currp->x=x;
    currp->y=y;
    currp->z=z;
}
void trocarp(Ponto **p,int e1,int e2){
    float x1,y1,z1,x2,y2,z2;
    acessarp(p,e1,&x1,&y1,&z1);
    acessarp(p,e2,&x2,&y2,&z2);
    modificarp(p,x2,y2,z2,e1);
    modificarp(p,x1,y1,z1,e2);
}
float distanciap(Ponto **p,Vetor **v,int e1,int e2){
    criarv(v,p,0,0,0,e1,e2,0);
    float ans=modulov(v,quantv(v)-1);
    removerv(v,quantv(v)-1);
    return ans;
}
void cilindricap(Ponto **p,int e,int deg_rad,float *r,double *teta,float *z){
    Ponto *currp=*p;
    int i=0;
    for(;i<e;currp=currp->next,i++){}
    *z=currp->z;
    *r=sqrt(pow(currp->x,2)+pow(currp->y,2));
    *teta=atan((currp->y)/(currp->x));
    if(currp->x<0)
        (*teta)+=180;
    if(currp->x>0 && currp->y<0)
        (*teta)+=360;
    if(!deg_rad)
        *teta=angconvert(*teta,0);
}
void esfericap(Ponto **p,int e,int deg_rad,float *ro,double *fi,double *teta){
    Ponto *currp=*p;
    int i=0;
    for(;i<e;currp=currp->next,i++){}
    *ro=sqrt(pow(currp->x,2)+pow(currp->y,2)+pow(currp->z,2));
    *fi=acos(currp->z/(*ro));
    *teta=atan((currp->y)/(currp->x));
    if(currp->x<0)
        (*teta)+=180;
    if(currp->x>0 && currp->y<0)
        (*teta)+=360;
    if(!deg_rad){
        *fi=angconvert(*fi,0);
        *teta=angconvert(*teta,0);
    }
}
//vetor
int quantv(Vetor **v){
    Vetor *currv=*v;
    int tam=0;
    for(;currv;currv=currv->next,tam++){}
    return tam;
}
void criarv(Vetor **v,Ponto **p,float a,float b,float c,int p1,int p2,int modo){
    Vetor *prevv=*v,*newv=malloc(sizeof(Vetor));
    float a1,a2,b1,b2,c1,c2;
    if(newv){
        if(modo){
            newv->a=a;
            newv->b=b;
            newv->c=c;
        }else{
            acessarp(p,p1,&a1,&b1,&c1);
            acessarp(p,p2,&a2,&b2,&c2);
            newv->a=a2-a1;
            newv->b=b2-b1;
            newv->c=c2-c1;
        }
        newv->next=NULL;
        if(!prevv)
            *v=newv;
        else{
            for(;prevv->next;prevv=prevv->next){}
            prevv->next=newv;
        }
    }else
        printf("Memoria insuficiente");
}
void removerv(Vetor **v,int e){
    Vetor *prevv,*nextv,*currv=*v;
    int i=0;
    if(e){
        for(;(i+1)<e;i++,currv=currv->next){}
        prevv=currv;
        currv=currv->next;
        nextv=currv->next;
        prevv->next=nextv;
    }else
        *v=currv->next;
    free(currv);
}
void limparv(Vetor **v){
    for(;quantv(v);removerv(v,quantv(v)-1)){}
}
void listarv(Vetor **v){
    Vetor *currv=*v;
    int i=1;
    for(;currv;currv=currv->next,i++)
        printf("Vetor %d: (%f;%f;%f)\n",i,currv->a,currv->b,currv->c);
}
void acessarv(Vetor **v,int e,float *a,float *b,float *c){
    Vetor *currv=*v;
    int i=0;
    for(;i<e;currv=currv->next,i++){}
    *a=currv->a;
    *b=currv->b;
    *c=currv->c;
}
void modificarv(Vetor **v,float a,float b,float c,int e){
    Vetor *currv=*v;
    int i=0;
    for(;i<e;currv=currv->next,i++){}
    currv->a=a;
    currv->b=b;
    currv->c=c;
}
void trocarv(Vetor **v,int e1,int e2){
    float a1,b1,c1,a2,b2,c2;
    acessarv(v,e1,&a1,&b1,&c1);
    acessarv(v,e2,&a2,&b2,&c2);
    modificarv(v,a2,b2,c2,e1);
    modificarv(v,a1,b1,c1,e2);
}
double modulov(Vetor **v,int e){
    float a,b,c;
    acessarv(v,e,&a,&b,&c);
    return sqrt(pow(a,2)+pow(b,2)+pow(c,2));
}
int paralelov(Vetor **v,int e1,int e2){
    float a,a1,a2,b,b1,b2,c,c1,c2;
    acessarv(v,e1,&a1,&b1,&c1);
    acessarv(v,e2,&a2,&b2,&c2);
    a=a1/a2;
    b=b1/b2;
    c=c1/c2;
    if(!a2)
        a=0;
    if(!b2)
        b=0;
    if(!c2)
        c=0;
    if(!a1 && !a2)
        a=b;
    if(!b1 && !b2)
        b=c;
    if(!c1 && !c2)
        c=a;
    if(!a1 && !a2 && !b1 && !b2)
        a=c;
    if(!b1 && !b2 && !c1 && !c2)
        b=a;
    if(!a1 && !a2 && !c1 && !c2)
        c=b;
    if((a1 && !a2) || (!a1 && a2) || (b1 && !b2) || (!b1 && b2) || (c1 && !c2) || (!c1 && c2))
        a=b+1;
    if(a==b && a==c)
        return 1;
    else
        return 0;
}
int ortogonalv(Vetor **v,int e1,int e2){
    if(!produtoescalarv(v,e1,e2))
        return 1;
    else
        return 0;
}
int coplanarv(Vetor **v,int e1,int e2,int e3){
    if(!produtomistov(v,e1,e2,e3))
        return 1;
    else
        return 0;
}
float produtoescalarv(Vetor **v,int e1,int e2){
    float a1,a2,b1,b2,c1,c2;
    acessarv(v,e1,&a1,&b1,&c1);
    acessarv(v,e2,&a2,&b2,&c2);
    return a1*a2+b1*b2+c1*c2;
}
void produtovetorialv(Vetor **v,int e1,int e2,float *a,float *b,float *c){
    float a1,a2,b1,b2,c1,c2;
    acessarv(v,e1,&a1,&b1,&c1);
    acessarv(v,e2,&a2,&b2,&c2);
    *a=b1*c2-c1*b2;
    *b=c1*a2-a1*c2;
    *c=a1*b2-b1*a2;
}
float produtomistov(Vetor **v,int e1,int e2,int e3){
    float a1,a2,a3,b1,b2,b3,c1,c2,c3;
    acessarv(v,e1,&a1,&b1,&c1);
    acessarv(v,e2,&a2,&b2,&c2);
    acessarv(v,e3,&a3,&b3,&c3);
    return a1*b2*c3+b1*c2*a3+c1*a2*b3-c1*b2*a3-b1*a2*c3-a1*c2*b3;
}
double angulov(Vetor **v,int e1,int e2,int deg_rad){
    double ang=acos(produtoescalarv(v,e1,e2)/(modulov(v,e1)*modulov(v,e2)));
    if(!deg_rad)
        ang=angconvert(ang,0);
    return ang;
}
void angulosdiretoresv(Vetor **v,int e,int deg_rad,double *alfa,double *beta,double *gama){
    float a,b,c;
    acessarv(v,e,&a,&b,&c);
    *alfa=acos(a/modulov(v,e));
    *beta=acos(b/modulov(v,e));
    *gama=acos(c/modulov(v,e));
    if(!deg_rad){
        *alfa=angconvert(*alfa,0);
        *beta=angconvert(*beta,0);
        *gama=angconvert(*gama,0);
    }
}
void projecaov(Vetor **v,int e1,int e2,float *a,float *b,float *c){
    float k=produtoescalarv(v,e1,e2)/produtoescalarv(v,e2,e2);
    acessarv(v,e2,a,b,c);
    (*a)*=k;
    (*b)*=k;
    (*c)*=k;
}
void unitariov(Vetor **v,int e,float *a,float *b,float *c){
    float modulo=modulov(v,e);
    acessarv(v,e,a,b,c);
    (*a)/=modulo;
    (*b)/=modulo;
    (*c)/=modulo;
}
//reta
int quantr(Reta **r){
    Reta *currr=*r;
    int tam=0;
    for(;currr;currr=currr->next,tam++){}
    return tam;
}
void criarr(Reta **r,Vetor **v,Ponto **p,float x,float y,float z,float a,float b,float c,int e1,int e2,int modo){
    Reta *prevr=*r,*newr=malloc(sizeof(Reta));
    Vetor *currv;
    Ponto *currp;
    int i;
    if(newr){
        if(modo==2){
            criarp(p,x,y,z);
            criarv(v,p,a,b,c,0,0,1);
            e2=quantp(p)-1;
            e1=quantv(v)-1;
        }
        if(modo==1){
            criarv(v,p,0,0,0,e2,e1,0);
            e1=quantv(v)-1;
        }
        for(i=0,currv=*v;i<e1;currv=currv->next,i++){}
        for(i=0,currp=*p;i<e2;currp=currp->next,i++){}
        newr->inicial=*currp;
        newr->diretor=*currv;
        newr->next=NULL;
        if(!prevr)
            *r=newr;
        else{
            for(;prevr->next;prevr=prevr->next){}
            prevr->next=newr;
        }
        if(modo){
            removerv(v,quantv(v)-1);
            if(modo==2)
                removerp(p,quantp(p)-1);
        }
    }else
        printf("Memoria insuficiente!\n");
}
void removerr(Reta **r,int e){
    Reta *prevr,*nextr,*currr=*r;
    int i=0;
    if(e){
        for(;(i+1)<e;i++,currr=currr->next){}
        prevr=currr;
        currr=currr->next;
        nextr=currr->next;
        prevr->next=nextr;
    }else
        *r=currr->next;
    free(currr);
}
void limparr(Reta **r){
    for(;quantr(r);removerr(r,quantr(r)-1)){}
}
void listarr(Reta **r){
    Reta *currr=*r;
    int i=1;
    for(;currr;currr=currr->next,i++)
        printf("Reta %d: (x,y,z)=(%f;%f;%f)+t(%f;%f;%f)\n",i,currr->inicial.x,currr->inicial.y,currr->inicial.z,currr->diretor.a,currr->diretor.b,currr->diretor.c);
}
void acessarr(Reta **r,int e,Ponto *inicial,Vetor *diretor){
    Reta *currr=*r;
    int i=0;
    for(;i<e;currr=currr->next,i++){}
    *inicial=currr->inicial;
    *diretor=currr->diretor;
}
void modificarr(Reta **r,Vetor **v,Ponto **p,int r1,int v1,int p1){
    Reta *currr=*r;
    Vetor *currv=*v;
    Ponto *currp=*p;
    int i=0;
    for(;i<r1;currr=currr->next,i++){}
    for(i=0;i<v1;currv=currv->next,i++){}
    for(i=0;i<p1;currp=currp->next,i++){}
    currr->inicial=*currp;
    currr->diretor=*currv;
}
void trocarr(Reta **r,Vetor **v,Ponto **p,int e1,int e2){
    Ponto p1,p2;
    Vetor v1,v2;
    acessarr(r,e1,&p1,&v1);
    acessarr(r,e2,&p2,&v2);
    criarp(p,p1.x,p1.y,p1.z);
    criarp(p,p2.x,p2.y,p2.z);
    criarv(v,p,v1.a,v1.b,v1.c,0,0,1);
    criarv(v,p,v2.a,v2.b,v2.c,0,0,1);
    modificarr(r,v,p,e1,quantv(v)-1,quantp(p)-1);
    modificarr(r,v,p,e2,quantv(v)-2,quantp(p)-2);
    removerp(p,quantp(p)-1);
    removerp(p,quantp(p)-1);
    removerv(v,quantv(v)-1);
    removerv(v,quantv(v)-1);
}
double angulor(Reta **r,Vetor **v,int e1,int e2,int deg_rad){
    double ang;
    Ponto p;
    Vetor v1,v2;
    acessarr(r,e1,&p,&v1);
    acessarr(r,e2,&p,&v2);
    criarv(v,0,v1.a,v1.b,v1.c,0,0,1);
    criarv(v,0,v2.a,v2.b,v2.c,0,0,1);
    ang=angulov(v,quantv(v)-1,quantv(v)-2,deg_rad);
    removerv(v,quantv(v)-1);
    removerv(v,quantv(v)-1);
    return ang;
}
int posicaorelativar(Reta **r,Vetor **v,int e1,int e2){
    Ponto p1,p2;
    Vetor v1,v2;
    acessarr(r,e1,&p1,&v1);
    acessarr(r,e2,&p2,&v2);
    criarv(v,0,v1.a,v1.b,v1.c,0,0,1);
    criarv(v,0,v2.a,v2.b,v2.c,0,0,1);
    criarv(v,0,p2.x-p1.x,p2.y-p1.y,p2.z-p1.z,0,0,1);
    int ans=coplanarv(v,quantv(v)-3,quantv(v)-2,quantv(v)-1);
    if(ans)
        ans+=paralelov(v,quantv(v)-3,quantv(v)-2);
    removerv(v,quantv(v)-1);
    removerv(v,quantv(v)-1);
    removerv(v,quantv(v)-1);
    return ans;
}
int interseccaor(Reta **r,Vetor **v,int e1,int e2,float *x,float *y,float *z){
    Ponto p1,p2;
    Vetor v1,v2;
    if(posicaorelativar(r,v,e1,e2)==1){
        acessarr(r,e1,&p1,&v1);
        acessarr(r,e2,&p2,&v2);
        if(v1.b && v2.b)
            *x=(p2.y-p1.y+(v1.b/v1.a)*p1.x-(v2.b/v2.a)*p2.x)/((v1.b/v1.a)-(v2.b/v2.a));
        else
            *x=(p2.z-p1.z+(v1.c/v1.a)*p1.x-(v2.c/v2.a)*p2.x)/((v1.c/v1.a)-(v2.c/v2.a));
        *y=p1.y+v1.b*(*x-p1.x)/v1.a;
        *z=p1.z+v1.c*(*x-p1.x)/v1.a;
    }
    return posicaorelativar(r,v,e1,e2);
}
float distanciapr(Reta **r,Vetor **v,Ponto **p,int r1,int p1){
    float a,b,c,dist;
    Vetor v1;
    Ponto p2;
    acessarr(r,r1,&p2,&v1);
    criarv(v,p,v1.a,v1.b,v1.c,0,0,1);
    criarp(p,p2.x,p2.y,p2.z);
    criarv(v,p,0,0,0,quantp(p)-1,p1,0);
    produtovetorialv(v,quantv(v)-2,quantv(v)-1,&a,&b,&c);
    criarv(v,p,a,b,c,0,0,1);
    dist=modulov(v,quantv(v)-1)/modulov(v,quantv(v)-3);
    removerp(p,quantp(p)-1);
    removerv(v,quantv(v)-1);
    removerv(v,quantv(v)-1);
    removerv(v,quantv(v)-1);
    return dist;
}
float distanciarr(Reta **r,Vetor **v,Ponto **p,int e1,int e2){
    float a,b,c,dist;
    Ponto p1,p2;
    Vetor v1,v2;
    switch(posicaorelativar(r,v,e1,e2)){
        case 0:
            acessarr(r,e1,&p1,&v1);
            acessarr(r,e2,&p2,&v2);
            criarv(v,p,v1.a,v1.b,v1.c,0,0,1);
            criarv(v,p,v2.a,v2.b,v2.c,0,0,1);
            criarp(p,p1.x,p1.y,p1.z);
            criarp(p,p2.x,p2.y,p2.z);
            criarv(v,p,0,0,0,quantp(p)-2,quantp(p)-1,0);
            produtovetorialv(v,quantv(v)-3,quantv(v)-2,&a,&b,&c);
            criarv(v,p,a,b,c,0,0,1);
            dist=abs(produtomistov(v,quantv(v)-4,quantv(v)-3,quantv(v)-2))/modulov(v,quantv(v)-1);
            removerp(p,quantp(p)-1);
            removerp(p,quantp(p)-1);
            removerv(v,quantv(v)-1);
            removerv(v,quantv(v)-1);
            removerv(v,quantv(v)-1);
            removerv(v,quantv(v)-1);
            break;
        case 1:
            return 0;
        case 2:
            acessarr(r,e1,&p1,&v1);
            criarp(p,p1.x,p1.y,p1.z);
            dist=distanciapr(r,v,p,e2,quantp(p)-1);
            removerp(p,quantp(p)-1);
    }
    return dist;
}
int pontopertenceareta(Reta **r,Vetor **v,Ponto**p,int r1,int p1){
    if(distanciapr(r,v,p,r1,p1))
        return 0;
    else
        return 1;
}
//plano
int quantpl(Plano **pl){
    Plano *currpl=*pl;
    int tam=0;
    for(;currpl;currpl=currpl->next,tam++){}
    return tam;
}
void criarpl(Plano **pl,Reta **r,Vetor **v,Ponto **p,float a,float b,float c,float d,int e1,int e2,int e3,int modo){
    Plano *prevpl=*pl,*newpl=malloc(sizeof(Plano));
    Vetor *currv,v1,v2;
    Ponto *currp,p1,p2;
    float x,y,z;
    int i,pos;
    if(newpl){
        switch(modo){
            case 0:
                acessarp(p,e2,&x,&y,&z);
                break;
            case 1:
                produtovetorialv(v,e1,e2,&a,&b,&c);
                criarv(v,p,a,b,c,0,0,1);
                acessarp(p,e3,&x,&y,&z);
                break;
            case 2:
                criarv(v,p,0,0,0,e2,e3,0);
                produtovetorialv(v,e1,quantv(v)-1,&a,&b,&c);
                criarv(v,p,a,b,c,0,0,1);
                acessarp(p,e2,&x,&y,&z);
                break;
            case 3:
                criarv(v,p,0,0,0,e1,e2,0);
                criarv(v,p,0,0,0,e1,e3,0);
                produtovetorialv(v,quantv(v)-2,quantv(v)-1,&a,&b,&c);
                criarv(v,p,a,b,c,0,0,1);
                acessarp(p,e1,&x,&y,&z);
                break;
            case 4:
                acessarr(r,e1,&p1,&v1);
                acessarr(r,e2,&p2,&v2);
                criarv(v,p,v1.a,v1.b,v1.c,0,0,1);
                criarp(p,p1.x,p1.y,p1.z);
                acessarp(p,quantp(p)-1,&x,&y,&z);
                pos=posicaorelativar(r,v,e1,e2);
                if(pos==2){
                    criarp(p,p2.x,p2.y,p2.z);
                    criarv(v,p,0,0,0,quantp(p)-2,quantp(p)-1,0);
                }else
                    criarv(v,p,v2.a,v2.b,v2.c,0,0,1);
                produtovetorialv(v,quantv(v)-2,quantv(v)-1,&a,&b,&c);
                criarv(v,p,a,b,c,0,0,1);
                break;
            case 5:
                acessarr(r,e1,&p1,&v1);
                criarp(p,p1.x,p1.y,p1.z);
                criarv(v,p,v1.a,v1.b,v1.c,0,0,1);
                criarv(v,p,0,0,0,e2,quantp(p)-1,0);
                produtovetorialv(v,quantv(v)-2,quantv(v)-1,&a,&b,&c);
                criarv(v,p,a,b,c,0,0,1);
                acessarp(p,e2,&x,&y,&z);
                break;
            case 6:
                criarv(v,p,a,b,c,0,0,1);
        }
        if(modo)
            e1=quantv(v)-1;
        for(i=0,currv=*v;i<e1;currv=currv->next,i++){}
        if(modo!=6)
            d=-(currv->a*x+currv->b*y+currv->c*z);
        newpl->normal=*currv;
        newpl->d=d;
        newpl->next=NULL;
        if(!prevpl)
            *pl=newpl;
        else{
            for(;prevpl->next;prevpl=prevpl->next){}
            prevpl->next=newpl;
        }
        switch(modo){
            case 4:
                if(pos==2)
                    removerp(p,quantp(p)-1);
            case 5:
                removerp(p,quantp(p)-1);
            case 3:
                removerv(v,quantv(v)-1);
            case 2:
                removerv(v,quantv(v)-1);
            case 6:
            case 1:
                removerv(v,quantv(v)-1);
                break;
        }
    }else
        printf("Memoria insuficiente!\n");
}
void removerpl(Plano **pl,int e){
    Plano *prevpl,*nextpl,*currpl=*pl;
    int i=0;
    if(e){
        for(;(i+1)<e;i++,currpl=currpl->next){}
        prevpl=currpl;
        currpl=currpl->next;
        nextpl=currpl->next;
        prevpl->next=nextpl;
    }else
        *pl=currpl->next;
    free(currpl);
}
void limparpl(Plano **pl){
    for(;quantpl(pl);removerpl(pl,quantpl(pl)-1)){}
}
void listarpl(Plano **pl){
    Plano *currpl=*pl;
    int i=1;
    for(;currpl;currpl=currpl->next,i++)
        printf("Plano %d: (%f)x+(%f)y+(%f)z+(%f)=0\n",i,currpl->normal.a,currpl->normal.b,currpl->normal.c,currpl->d);
}
void acessarpl(Plano **pl,int e,Vetor *normal,float *d){
    Plano *currpl=*pl;
    int i=0;
    for(;i<e;currpl=currpl->next,i++){}
    *normal=currpl->normal;
    *d=currpl->d;
}
void modificarpl(Plano **pl,Vetor **v,float d,int pl1,int v1){
    Plano *currpl=*pl;
    Vetor *currv=*v;
    int i=0;
    for(;i<pl1;currpl=currpl->next,i++){}
    for(i=0;i<v1;currv=currv->next,i++){}
    currpl->normal=*currv;
    currpl->d=d;
}
int paralelorpl(Plano **pl,Reta **r,Vetor **v,Ponto **p,int pl1,int r1){
    float d;
    Vetor normal,diretor;
    Ponto p1;
    acessarpl(pl,pl1,&normal,&d);
    acessarr(r,r1,&p1,&diretor);
    criarv(v,p,normal.a,normal.b,normal.c,0,0,1);
    criarv(v,p,diretor.a,diretor.b,diretor.c,0,0,1);
    int ans=ortogonalv(v,quantv(v)-2,quantv(v)-1);
    removerv(v,quantv(v)-1);
    removerv(v,quantv(v)-1);
    return ans;
}
int ortogonalrpl(Plano **pl,Reta **r,Vetor **v,Ponto **p,int pl1,int r1){
    float d;
    Vetor normal,diretor;
    Ponto p1;
    acessarpl(pl,pl1,&normal,&d);
    acessarr(r,r1,&p1,&diretor);
    criarv(v,p,normal.a,normal.b,normal.c,0,0,1);
    criarv(v,p,diretor.a,diretor.b,diretor.c,0,0,1);
    int ans=paralelov(v,quantv(v)-2,quantv(v)-1);
    removerv(v,quantv(v)-1);
    removerv(v,quantv(v)-1);
    return ans;
}
int paralelopl(Plano **pl,Vetor **v,Ponto **p,int e1,int e2){
    float d;
    Vetor n1,n2;
    acessarpl(pl,e1,&n1,&d);
    acessarpl(pl,e2,&n2,&d);
    criarv(v,p,n1.a,n1.b,n1.c,0,0,1);
    criarv(v,p,n2.a,n2.b,n2.c,0,0,1);
    int ans=paralelov(v,quantv(v)-2,quantv(v)-1);
    removerv(v,quantv(v)-1);
    removerv(v,quantv(v)-1);
    return ans;
}
int ortogonalpl(Plano **pl,Vetor **v,Ponto **p,int e1,int e2){
    float d;
    Vetor n1,n2;
    acessarpl(pl,e1,&n1,&d);
    acessarpl(pl,e2,&n2,&d);
    criarv(v,p,n1.a,n1.b,n1.c,0,0,1);
    criarv(v,p,n2.a,n2.b,n2.c,0,0,1);
    int ans=ortogonalv(v,quantv(v)-2,quantv(v)-1);
    removerv(v,quantv(v)-1);
    removerv(v,quantv(v)-1);
    return ans;
}
double angulorpl(Plano **pl,Reta **r,Vetor **v,Ponto **p,int pl1,int r1,int deg_rad){
    float d;
    Vetor normal,diretor;
    Ponto p1;
    acessarpl(pl,pl1,&normal,&d);
    acessarr(r,r1,&p1,&diretor);
    criarv(v,p,normal.a,normal.b,normal.c,0,0,1);
    criarv(v,p,diretor.a,diretor.b,diretor.c,0,0,1);
    double ang=asin(produtoescalarv(v,quantv(v)-2,quantv(v)-1)/(modulov(v,quantv(v)-2)*modulov(v,quantv(v)-1)));
    removerv(v,quantv(v)-1);
    removerv(v,quantv(v)-1);
    if(!deg_rad)
        ang=angconvert(ang,0);
    return ang;
}
double angulopl(Plano **pl,Vetor **v,Ponto **p,int e1,int e2,int deg_rad){
    double ang;
    float d;
    Vetor n1,n2;
    acessarpl(pl,e1,&n1,&d);
    acessarr(pl,e2,&n2,&d);
    criarv(v,0,n1.a,n1.b,n1.c,0,0,1);
    criarv(v,0,n2.a,n2.b,n2.c,0,0,1);
    ang=angulov(v,quantv(v)-1,quantv(v)-2,deg_rad);
    removerv(v,quantv(v)-1);
    removerv(v,quantv(v)-1);
    return ang;
}
int interseccaorpl(Plano **pl,Reta **r,Vetor **v,Ponto **p,int pl1,int r1,float *x,float *y,float *z){
    float d,t;
    Vetor normal,diretor;
    Ponto inicial;
    if(paralelorpl(pl,r,v,p,pl1,r1))
        if(distanciarpl(pl,r,v,p,pl1,r1))
            return 0;
        else
            return 2;
    else{
        acessarpl(pl,pl1,&normal,&d);
        acessarr(r,r1,&inicial,&diretor);
        t=-(d+normal.a*inicial.x+normal.b*inicial.y+normal.c*inicial.z)/(diretor.a*normal.a+diretor.b*normal.b+diretor.c*normal.c);
        *x=inicial.x+diretor.a*t;
        *y=inicial.y+diretor.b*t;
        *z=inicial.z+diretor.c*t;
    }
    return 1;
}
int interseccaopl(Plano **pl,Vetor **v,Ponto **p,int e1,int e2,float *a,float *b,float *c,float *x,float *y,float *z){
    float d1,d2;
    Vetor n1,n2;
    if(paralelopl(pl,v,p,e1,e2))
        if(distanciapl(pl,v,p,e1,e2))
            return 0;
        else
            return 2;
    else{
        acessarpl(pl,e1,&n1,&d1);
        acessarpl(pl,e2,&n2,&d2);
        criarv(v,0,n1.a,n1.b,n1.c,0,0,1);
        criarv(v,0,n2.a,n2.b,n2.c,0,0,1);
        produtovetorialv(v,quantv(v)-2,quantv(v)-1,a,b,c);
        *x=0;
        *y=(n2.c*d1-n1.c*d2)/(n2.b*n1.c-n1.b*n2.c);
        *z=-(d1+n1.b*(*y))/n1.c;
        removerv(v,quantv(v)-1);
        removerv(v,quantv(v)-1);
    }
    return 1;
}
float distanciappl(Plano **pl,Vetor **v,Ponto **p,int pl1,int p1){
    float dist,d,x,y,z;
    Vetor normal;
    acessarp(p,p1,&x,&y,&z);
    acessarpl(pl,pl1,&normal,&d);
    criarv(v,p,normal.a,normal.b,normal.c,0,0,1);
    dist=abs(normal.a*x+normal.b*y+normal.c*z+d)/modulov(v,quantv(v)-1);
    removerv(v,quantv(v)-1);
    return dist;
}
float distanciarpl(Plano **pl,Reta **r,Vetor **v,Ponto **p,int pl1,int r1){
    float dist;
    Vetor diretor;
    Ponto p1;
    if(paralelorpl(pl,r,v,p,pl1,r1)){
        acessarr(r,r1,&p1,&diretor);
        criarp(p,p1.x,p1.y,p1.z);
        dist=distanciappl(pl,v,p,pl1,quantp(p)-1);
        removerp(p,quantp(p)-1);
        return dist;
    }else
        return 0;
}
float distanciapl(Plano **pl,Vetor **v,Ponto **p,int e1,int e2){
    float dist,d,x,y,z;
    Vetor normal;
    acessarpl(pl,e1,&normal,&d);
    if(normal.a){
        x=-d/normal.a;
        y=0;
        z=0;
    }else{
        if(normal.b){
            x=0;
            y=-d/normal.b;
            z=0;
        }else{
            if(normal.c){
                x=0;
                y=0;
                z=-d/normal.c;
            }else{
                x=0;
                y=0;
                z=0;
            }
        }
    }
    criarp(p,x,y,z);
    dist=distanciappl(pl,v,p,e2,quantp(p)-1);
    removerp(p,quantp(p)-1);
    return dist;
}
int pontopertenceaoplano(Plano **pl,Vetor **v,Ponto**p,int pl1,int p1){
    if(distanciappl(pl,v,p,pl1,p1))
        return 0;
    else
        return 1;
}
int retapertenceaoplano(Plano **pl,Reta **r,Vetor **v,Ponto **p,int pl1,int r1){
    if(paralelorpl(pl,r,v,p,pl1,r1) && !distanciarpl(pl,r,v,p,pl1,r1))
        return 1;
    else
        return 0;
}
