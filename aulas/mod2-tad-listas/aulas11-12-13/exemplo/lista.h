typedef char elem;
typedef struct no No;
typedef struct lista Lista;

Lista* cria();
void inserir(Lista*,elem*,int*);
void finaliza(Lista*);
int tamanho(Lista*);
int esta_na_lista(Lista*,elem*);
void imprimir(Lista*);
//deixar a fun��o "eliminar" para o fim, pois � mais complexa
void eliminar(Lista*,elem*,int*);
