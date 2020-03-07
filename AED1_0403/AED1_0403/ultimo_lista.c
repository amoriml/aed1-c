#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int info;
	Node *prox;
};

Node* inclui_fim(Node *lista, int x);
Node* ultimo_no(Node *lista);

int main() {
	int n, valor, i;
	Node *lst = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
	    scanf("%d", &valor);
		lst = inclui_fim(lst, valor);
	}

	Node *p = ultimo_no(lst);
	if (p != NULL)
		printf("%d\n", p->info);

	return 0;
}

Node* ultimo_no(Node *lst) {
	Node *p = lst;

    if(p == NULL)
        return NULL;
        
    while(p->prox != NULL){
        p = p->prox;
    }
    return p;
}

Node* inclui_fim(Node *lista, int x) {
	Node *p = (Node*) malloc(sizeof(Node));
	if (p != NULL) {
		p->info = x;
		if (lista == NULL) {
			p->prox = NULL;
			return p;
		}
		Node *q = lista;
		while (q->prox != NULL)
			q = q->prox;
		q->prox = p;
		p->prox = NULL;
	}
	return lista;
}

