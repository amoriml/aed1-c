#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int info;
	Node *prox;
};

Node* inclui_fim(Node *lista, int x);
void imprime_lista(Node *lista);
Node* remove_no(Node *lista, int x);

int main() {
	int n, valor, i;
	Node *lst = NULL;
	scanf("%d", &n);
	for(i=0; i < n; i++) {
		scanf("%d", &valor);
		lst = inclui_fim(lst, valor);
	}
	scanf("%d", &valor);
	lst = remove_no(lst, valor);
	imprime_lista(lst);
	free(lst);

	return 0;
}

Node* remove_no(Node *lista, int x) {
	Node *temp = lista, *ant; 
  
    if (temp != NULL && temp->info == x) { 
        return temp->prox; 
    } 
  
    while (temp != NULL && temp->info != x) { 
        ant = temp; 
        temp = temp->prox; 
    } 
    if (temp == NULL) return lista;

    ant->prox = temp->prox;
    free(temp);
	return lista;
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

void imprime_lista(Node *lista) {
	Node *p = lista;
	if (lista == NULL)
		printf("Lista vazia");
	while (p != NULL) {
		printf(" %d ", p->info);
		p = p->prox;
	}
	printf("\n");
}