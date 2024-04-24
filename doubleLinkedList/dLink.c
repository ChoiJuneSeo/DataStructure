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

	if (*head == NULL)	// �� ����Ʈ��
	{
		*head = newNode;
	}

	if (position == 1)	// ù ��� �����̸�
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
	if (temp->rlink != NULL)		// ������ ��� ������ �ƴ϶��
	{
		temp->rlink->llink = newNode;
	}

	newNode->llink = temp;
	temp->rlink = newNode;
	

};
void deleteNode(node** head, int key) 
{
	
	if (*head == NULL) return;		// �� ����Ʈ��

	node* temp = *head; 
	
	while (temp != NULL && temp->data != key)
	{
		temp = temp->rlink;
	}
	if (temp == NULL) return;	// key�� ����

	if (temp->llink != NULL)	// key�� ù��° ��尡 �ƴ�
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