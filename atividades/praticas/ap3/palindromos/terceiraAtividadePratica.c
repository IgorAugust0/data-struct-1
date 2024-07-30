#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de dados do nó
struct node {
    char letter;
    struct node* next;
};

// Definição da struct da fila
struct _queue {
    struct node* first;
    struct node* last;
};

// Definição do tipo Fila (queue)
typedef struct _queue* Queue;
// Cabeçalhos das funções da lista
Queue create_queue();
int enqueue(Queue, char);
int dequeue(Queue, char*);
int is_queue_empty(Queue);


// Definição do tipo Pilha (stack)
typedef struct node* Stack;
// Cabeçalhos das funções da pilha
Stack create_stack();
int is_stack_empty(Stack);
int push(Stack*, char);
int pop(Stack*, char*);

int main()
{
    int flag = 1;
    char aux, aux2;
    Queue str_queue = create_queue(); // criar lista
    Stack str_stack = create_stack(); // criar pilha

    while((aux = getchar()) != '\n'){
        // Adiciona à lista e à pilha, se o caractere não for um espaço
        if (aux != ' '){
            enqueue(str_queue, aux);
            push(&str_stack, aux);
        }
    }

    // A lista vai representar a frase/palavra normal
    // A pilha, por sua vez, vai representar a frase/palavra invertida, dado que as últimas letras adicionadas serão as primeiras.
    while(is_stack_empty(str_stack) == 0){
        dequeue(str_queue, &aux);
        pop(&str_stack, &aux2);

        // O programa vai comparar letra por letra
        if (aux != aux2){
            flag = 0;
            break;
        }
    }

    // Responde se é ou não palíndromo
    printf("%d\n", flag);

    return 0;
}

// FUNÇÔES DA LISTA

// Função para criar a lista
Queue create_queue() {
    Queue q = (Queue) malloc(sizeof(struct _queue));
    if(q != NULL) {
        q->first = NULL;
        q->last = NULL;
    }
    return q;
}

// Função para verificar se a lista está vazia ou não
int is_queue_empty(Queue q) {
    if (q->first == NULL)
        return 1;
    return 0;
}

// Função enqueue que insere um caractere na fila
int enqueue(Queue q, char elem) {
    struct node* n = (struct node*) malloc(sizeof(struct node));
    if(n == NULL)
        return 0;
    n->letter = elem;
    if(is_queue_empty(q)) {
        q->first = n;
        n->next = NULL;
    } else {
        (q->last)->next = n;
    }
    q->last = n;
    return 1;
}

// Função dequeue que desenfileira e retorna o primeiro caractere na variável da fila
int dequeue(Queue q, char *elem) {
    if(is_queue_empty(q))
        return 0;
    struct node* aux = q->first;
    *elem = aux->letter;
    if(q->first == q->last){
        q->first = NULL;
        q->last = NULL;
    }
    q->first = aux->next;
    free(aux);
    return 1;
}

// FUNÇÔES DA PILHA

// Função para criar a pilha
Stack create_stack() {
    return NULL;
}

// Função para verificar se a pilha está vazia ou não
int is_stack_empty(Stack s) {
    if (s == NULL)
        return 1;
    return 0;
}

// Função push que insere um caractere na pilha
int push(Stack* s, char elem) {
    Stack new_node = (Stack) malloc(sizeof(struct node));
    if(new_node == NULL)
        return 0;

    new_node->letter = elem;
    new_node->next = *s;
    *s = new_node;

    return 1;
}

// Função pop que desempilha e retorna o caractere no topo da pilha
int pop(Stack* s, char* elem) {
    if(is_stack_empty(*s))
        return 0;

    Stack aux = *s;
    *elem = aux->letter;
    *s = aux->next;

    free(aux);
    return 1;
}