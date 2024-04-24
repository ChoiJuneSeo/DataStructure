#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node;


node* createNode(int data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
};

void prependNode(node** head, int data) 
{
	node* newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
};
void appendNode(node** head, int data)
{
	node* newNode = createNode(data); 

	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	node* temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;

};
void insertIndex(node** head, int data,int index)
{
	if (index == 0)
	{
		prependNode(head, data);
	}

	node* newNode = createNode(data);
	node* temp = *head;
	for (int i = 0; i < index-1 && temp != NULL; ++i)
	{
		temp = temp->next;
	}
	if (temp == NULL)
	{
		free(newNode);
		return;
	}
	newNode->next = temp->next;
	temp->next = newNode;
};
void deleteFront(node** head) 
{
	if (*head == NULL) return;

	node* temp = *head;
	*head = temp->next;
	free(temp);
};


void deleteLast(node** head) 
{
	if (*head == NULL) return;
	
	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		return;
	}

	node* temp = *head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
};
void deleteByValue(node** head, int value)
{
	if (*head == NULL) return;				// �� ����Ʈ��
	if ((*head)->data == value)				// ù ��° �����͸� ������ ��
	{
		node* target = *head;
		*head = target->next;
		free(target);
		return;
	}

	node* preTarget = *head;
	while (preTarget->next->data != value && preTarget->next !=NULL)
	{
		preTarget = preTarget->next;
	}
	if (preTarget->next == NULL) return;		// ������ ����� ����

	node* target = preTarget->next;
	preTarget->next = target->next;
	free(target);


};
node* search(node* head, int value) 
{
	node* temp = head;
	while (temp != NULL)
	{
		if (temp->data == value) return temp;
		temp = temp->next;
	}
	return NULL;
};
void freeList(node* head)
{
	node* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
};
int cntNode(node* head)
{
	int cnt = 0;
	node* temp = head;
	while (temp != NULL)
	{
		cnt++;
		temp = temp->next;
	}
	return cnt; 
}


void printList(node* head) 
{
	while (head != NULL)
	{
		printf("%d ->", head->data);
		head = head->next;
	}
	printf("NULL\n");
}


void main()
{
	node* head = NULL;
	
	prependNode(&head, 3); 
	prependNode(&head, 2); 
	prependNode(&head, 1); 

	appendNode(&head, 4); 
	appendNode(&head, 5); 

	insertIndex(&head, 10, 2); 

	printList(head); 
    
	node* found = search(head, 10);
	if (found != NULL)
	{
		printf("��� %d Ž�� ����\n", found->data); 
	}
	else
	{
		printf("��� Ž�� ����\n");
	}
    
	deleteFront(&head);  
	deleteLast(&head); 
	deleteByValue(&head, 10);   
    
	printList(head); 
	 
	int cnt = cntNode(head); 
	printf("����� �� ����: %d\n", cnt); 
    
	freeList(head); 

}