#include <stdio.h>
#include <stdlib.h>

// Node ����ü
typedef struct Node
{
	int data;
	struct Node* next;
}Node;

// ��� ����
Node* createNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// �տ� ����
void prependNode(Node** head, int data)
{
	Node* newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}
// �ڿ� ����
void appendNode(Node** head, int data)
{
	Node* newNode = createNode(data);
	if (*head == NULL)		//	 list�� ����ִٸ� (head��尡 ����)
	{
		*head = newNode;	// newNode�� head���
		return;
	}
	Node* lastNode = *head;
	while (lastNode->next != NULL)
	{
		lastNode = lastNode->next;
	}
	lastNode->next = newNode;
}

// �߰��� ����

void insertNodeAtIndex(Node** head, int data, int index)
{

	if (index == 0)
	{
		prependNode(head, data);
	}
	Node* newNode = createNode(data);
	Node* temp = *head;
	for (int i = 0; i < index - 1 && temp != NULL; ++i)
	{
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("error!\n");
		free(newNode);
		return;
	}
	newNode->next = temp->next;
	temp->next = newNode;

}

// �� �� ����
void deleteFrontNode(Node** head)
{
	if (*head == NULL)
	{
		printf("empty\n");
		return;
	}

	Node* target = *head;
	*head = target->next;
	free(target);
}

// �� �� ����
void deleteLastNode(Node** head)
{
	if (*head == NULL) return;
	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		return;
	}

	Node* temp = *head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
}

// �߰� ����(�� ����)

void deleteNodeWithValue(Node** head, int value)
{
	if (*head == NULL) return;
	if ((*head)->data == value)
	{
		Node* temp = *head;
		*head = temp->next;
		free(temp);
		return;
	}

	Node* temp = *head;
	while (temp->next->data != value && temp->next != NULL)
	{
		temp = temp->next;
	}
	if (temp->next == NULL) return;

	Node* temp2 = temp->next->next;
	free(temp->next);
	temp->next = temp2;

}

// Node Ž��
Node* search(Node* head, int value)
{
	Node* temp = head;
	while (temp != NULL)
	{
		if (temp->data == value) return temp;
		temp = temp->next;
	}
	return NULL;
}

// Node ���� ���ϱ�
int cntNodes(Node* head)
{
	Node* temp = head;
	int cnt = 0;
	while (temp != NULL)
	{
		cnt++;
		temp = temp->next;
	}
	return cnt;
}

// List ���
void printList(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}
// �޸� ����
void freeList(Node* head)
{
	Node* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

// List ���
// void printList(Node* head)
// {
// 	while (head != NULL)
// 	{
// 		printf("%d ->", head->data);
// 		head = head->next;
// 	}
// 	printf("NULL\n");
// }

void main()
{
	Node* head = NULL;

	prependNode(&head, 3);
	prependNode(&head, 2);
	prependNode(&head, 1);

	appendNode(&head, 4);
	appendNode(&head, 5);
	
	insertNodeAtIndex(&head, 10, 2);

	printList(head);

	Node* found = search(head, 10);
	if (found != NULL)
	{
		printf("��� %d Ž�� ����\n", found->data);
	}
	else
	{
		printf("��� Ž�� ����\n");
	}

	deleteFrontNode(&head);
	deleteLastNode(&head);
	deleteNodeWithValue(&head, 10);

	printList(head);

	int cnt = cntNodes(head);
	printf("����� �� ����: %d\n", cnt);

	freeList(head);


}

