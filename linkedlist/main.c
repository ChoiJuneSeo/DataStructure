#include <stdio.h>
#include <stdlib.h>

// Node 구조체
typedef struct Node
{
	int data;
	struct Node* next;
}Node;

// 노드 생성
Node* createNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// 앞에 삽입
void prependNode(Node** head, int data)
{
	Node* newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}
// 뒤에 삽입
void appendNode(Node** head, int data)
{
	Node* newNode = createNode(data);
	if (*head == NULL)		//	 list가 비어있다면 (head노드가 없음)
	{
		*head = newNode;	// newNode가 head노드
		return;
	}
	Node* lastNode = *head;
	while (lastNode->next != NULL)
	{
		lastNode = lastNode->next;
	}
	lastNode->next = newNode;
}

// 중간에 삽입

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

// 맨 앞 삭제
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

// 맨 뒤 삭제
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

// 중간 삭제(값 기준)

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

// Node 탐색
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

// Node 갯수 구하기
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

// List 출력
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
// 메모리 해제
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

// List 출력
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
		printf("노드 %d 탐색 성공\n", found->data);
	}
	else
	{
		printf("노드 탐색 실패\n");
	}

	deleteFrontNode(&head);
	deleteLastNode(&head);
	deleteNodeWithValue(&head, 10);

	printList(head);

	int cnt = cntNodes(head);
	printf("노드의 총 갯수: %d\n", cnt);

	freeList(head);


}

