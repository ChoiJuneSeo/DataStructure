#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int data;
	struct node* link;
}node;

node* createNode(int data) 
{
	node* newNode = (node*)malloc(sizeof(node));
	
	newNode->data = data;
	newNode->link = NULL;
	return newNode;

};
void insertNode(node** head,int data)
{
	node* newNode = createNode(data);
	if (*head == NULL)
	{
		*head = newNode;
		newNode->link = newNode;
		return;
	}
	node* temp = *head;
	while (temp->link != *head)
	{
		temp = temp->link;
	}
	temp->link = newNode;
	newNode->link = *head;
	// *head = newNode;	이러면 맨 앞에
};
void insertAtPosition(node** head, int data, int position) 
{
	node* newNode = createNode(data);

	if (*head == NULL)
	{
		*head = newNode;
		newNode->link = newNode;
		return;
	}
	
	node* temp = *head;

	if (position == 1)
	{
		while (temp->link != *head)
		{
			temp->link = newNode;
		}
		newNode->link = *head;
		*head = newNode;
		return;
	}
	
	for (int i = 1; i < position - 1 && temp->link != *head; ++i)
	{
		temp = temp->link;
	}
	newNode->link = temp->link;
	temp->link = newNode;
};
void deleteNode(node** head,int key)
{
	if (*head == NULL) return;
	node* temp = *head;
	node* prev = NULL;

	while (temp->data != key)
	{
		prev = temp;
		temp = temp->link;
		if (temp == *head) return;
	}

	if (temp->link == temp)
	{
		*head = NULL;
	}
	else
	{
		if (temp == *head)
		{
			*head = (*head)->link;
		}
		prev->link = temp->link;
	}
	free(temp);

};
// 첫번째 노드에 있는 key값을 찾을 시 오류


void main()
{
	node* head = NULL;
	insertNode(&head, 10);
	insertNode(&head, 20);
	insertNode(&head, 30);
	deleteNode(&head, 10);

}
