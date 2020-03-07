#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int info;
	Node *prox;
};

Node* inclui_inicio(Node *lista, int k);
int comprimento_lista(Node *lista);

int main() {
	int valor;
	Node *lst = NULL;
	scanf("%d", &valor);
	while (valor != -1) {
		lst = inclui_inicio(lst, valor);
		scanf("%d", &valor);
	}
	printf("%d\n", comprimento_lista(lst));

	return 0;
}

int comprimento_lista(Node *lista) {
	int cont = 0;
    Node *p = lista;
    
    if(p == NULL){
        return 0;
    }
    
    while(p != NULL){
        p = p->prox;
        cont ++;
    }
    return cont;
}

Node* inclui_inicio(Node *lista, int x) {
	Node *p = (Node*) malloc(sizeof(Node));
	if (p != NULL) {
		p->info = x;
		p->prox = lista;
	}
	return p;
}
