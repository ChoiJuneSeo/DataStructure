#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int data;
	struct node* llink;
	struct node* rlink;
}node;

node* createNode(int data) 
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->llink = NULL;
	newNode->rlink = NULL;

	return newNode;

};
void insertNode(node** head, int data, int position) 
{
	node* newNode = createNode(data);
	node* temp = *head;

	if (*head == NULL)	// 빈 리스트면
	{
		*head = newNode;
	}

	if (position == 1)	// 첫 노드 삽입이면
	{
		newNode->rlink = *head;
		(*head)->llink = newNode;
		*head = newNode;
		return;
	}
	int cnt = 1;
	while (cnt < position - 1 && temp->rlink != NULL)
	{
		temp = temp->rlink;
		cnt++;
	}
	
	newNode->rlink = temp->rlink;
	if (temp->rlink != NULL)		// 마지막 노드 삽입이 아니라면
	{
		temp->rlink->llink = newNode;
	}

	newNode->llink = temp;
	temp->rlink = newNode;
	

};
void deleteNode(node** head, int key) 
{
	
	if (*head == NULL) return;		// 빈 리스트면

	node* temp = *head; 
	
	while (temp != NULL && temp->data != key)
	{
		temp = temp->rlink;
	}
	if (temp == NULL) return;	// key가 없음

	if (temp->llink != NULL)	// key가 첫번째 노드가 아님
	{
		temp->llink->rlink = temp->rlink;
	}
	else
	{
		*head = temp->rlink;
	}
	if (temp->rlink != NULL)
	{
		temp->rlink->llink = temp->llink;
	}

	free(temp);
};


void main()
{

}