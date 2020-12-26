#ifndef GA_H_INCLUDED
#define GA_H_INCLUDED
//structs
typedef struct Ponto{
    float x,y,z;
    struct Ponto *next;
}Ponto;
typedef struct Vetor{
    float a,b,c;
    struct Vetor *next;
}Vetor;
typedef struct Reta{
    Ponto inicial;
    Vetor diretor;
    struct Reta *next;
}Reta;
typedef struct Plano{
    Vetor normal;
    float d;
    struct Plano *next;
}Plano;
//angulo
double angconvert(double ang,int rad_deg);
//ponto
int quantp(Ponto **p);
void criarp(Ponto **p,float x,float y,float z);
void removerp(Ponto **p,int e);
void limparp(Ponto **p);
void listarp(Ponto **p);
void acessarp(Ponto **p,int e,float *x,float *y,float *z);
void modificarp(Ponto **p,float x,float y,float z,int e);
void trocarp(Ponto **p,int e1,int e2);
float distanciap(Ponto **p,Vetor **v,int e1,int e2);
void cilindricap(Ponto **p,int e,int deg_rad,float *r,double *teta,float *z);
void esfericap(Ponto **p,int e,int deg_rad,float *ro,double *fi,double *teta);
//vetor
int quantv(Vetor **v);
void criarv(Vetor **v,Ponto **p,float a,float b,float c,int p1,int p2,int modo);
void removerv(Vetor **v,int e);
void limparv(Vetor **v);
void listarv(Vetor **v);
void acessarv(Vetor **v,int e,float *a,float *b,float *c);
void modificarv(Vetor **v,float a,float b,float c,int e);
void trocarv(Vetor **v,int e1,int e2);
double modulov(Vetor **v,int e);
int paralelov(Vetor **v,int e1,int e2);
int ortogonalv(Vetor **v,int e1,int e2);
int coplanarv(Vetor **v,int e1,int e2,int e3);
float produtoescalarv(Vetor **v,int e1,int e2);
void produtovetorialv(Vetor **v,int e1,int e2,float *a,float *b,float *c);
float produtomistov(Vetor **v,int e1,int e2,int e3);
double angulov(Vetor **v,int e1,int e2,int deg_rad);
void angulosdiretoresv(Vetor **v,int e,int deg_rad,double *alfa,double *beta,double *gama);
void projecaov(Vetor **v,int e1,int e2,float *x,float *y,float *z);
void unitariov(Vetor **v,int e,float *x,float *y,float *z);
//reta
int quantr(Reta **r);
void criarr(Reta **r,Vetor **v,Ponto **p,float x,float y,float z,float a,float b,float c,int e1,int e2,int modo);
void removerr(Reta **r,int e);
void limparr(Reta **r);
void listarr(Reta **r);
void acessarr(Reta **r,int e,Ponto *inicial,Vetor *diretor);
void modificarr(Reta **r,Vetor **v,Ponto **p,int r1,int v1,int p1);
void trocarr(Reta **r,Vetor **v,Ponto **p,int e1,int e2);
double angulor(Reta **r,Vetor **v,int e1,int e2,int deg_rad);
int posicaorelativar(Reta **r,Vetor **v,int e1,int e2);
int interseccaor(Reta **r,Vetor **v,int e1,int e2,float *x,float *y,float *z);
float distanciapr(Reta **r,Vetor **v,Ponto **p,int r1,int p1);
float distanciarr(Reta **r,Vetor **v,Ponto **p,int e1,int e2);
int pontopertenceareta(Reta **r,Vetor **v,Ponto**p,int r1,int p1);
//plano
int quantpl(Plano **pl);
void criarpl(Plano **pl,Reta **r,Vetor **v,Ponto **p,float a,float b,float c,float d,int e1,int e2,int e3,int modo);
void removerpl(Plano **pl,int e);
void limparpl(Plano **pl);
void listarpl(Plano **pl);
void acessarpl(Plano **pl,int e,Vetor *normal,float *d);
void modificarpl(Plano **pl,Vetor **v,float d,int pl1,int v1);
int paralelorpl(Plano **pl,Reta **r,Vetor **v,Ponto **p,int pl1,int r1);
int ortogonalrpl(Plano **pl,Reta **r,Vetor **v,Ponto **p,int pl1,int r1);
int paralelopl(Plano **pl,Vetor **v,Ponto **p,int e1,int e2);
int ortogonalpl(Plano **pl,Vetor **v,Ponto **p,int e1,int e2);
double angulorpl(Plano **pl,Reta **r,Vetor **v,Ponto **p,int pl1,int r1,int deg_rad);
double angulopl(Plano **pl,Vetor **v,Ponto **p,int e1,int e2,int deg_rad);
int interseccaorpl(Plano **pl,Reta **r,Vetor **v,Ponto **p,int pl1,int r1,float *x,float *y,float *z);
int interseccaopl(Plano **pl,Vetor **v,Ponto **p,int e1,int e2,float *a,float *b,float *c,float *x,float *y,float *z);
float distanciappl(Plano **pl,Vetor **v,Ponto **p,int pl1,int p1);
float distanciarpl(Plano **pl,Reta **r,Vetor **v,Ponto **p,int pl1,int r1);
float distanciapl(Plano **pl,Vetor **v,Ponto **p,int e1,int e2);
int pontopertenceaoplano(Plano **pl,Vetor **v,Ponto**p,int pl1,int p1);
int retapertenceaoplano(Plano **pl,Reta **r,Vetor **v,Ponto **p,int pl1,int r1);

#endif // GA_H_INCLUDED
