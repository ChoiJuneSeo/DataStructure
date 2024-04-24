#include <stdio.h>
#include <stdlib.h>

// 구조체 이름 바꾸는게 좋을 듯.
typedef struct binarytreeNode
{
	int data;
	struct binarytreeNode* lchild;
	struct binarytreeNode* rchild;
}node;

node* createBTN()
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = 0;
	newNode->lchild = NULL;
	newNode->rchild = NULL;
	return newNode;
};
void setNodeData(node* node, int data)
{
	node->data = data;
};
void removeSubTree(node* node)
{
	if (node == NULL) return;
	removeSubTree(node->lchild);
	removeSubTree(node->rchild);
	free(node);
};
void setLeftSubTree(node* parent,node* lchild)
{
	if (parent->lchild != NULL)
	{
		removeSubTree(parent->lchild);
	}
	parent->lchild = lchild;
};
void setRightSubTree(node* parent,node* rchild)
{
	if (parent->rchild != NULL)
	{
		removeSubTree(parent->rchild);
	}
	parent->rchild = rchild;
};

int getNodeData(node* node)
{
	return node->data;
}


void main()
{
	node* root = createBTN(); 
	node* leftNode = createBTN(); 
	node* rightNode = createBTN(); 
	node* leftLeftNode = createBTN();


	setNodeData(root, 1);
	setNodeData(leftNode, 2);
	setNodeData(rightNode, 3);
	setNodeData(leftLeftNode, 4);

	setLeftSubTree(root, leftNode);
	setRightSubTree(root, rightNode);
	setLeftSubTree(leftNode, leftLeftNode);

	printf("%d\n", getNodeData(root));
	printf("%d\n", getNodeData(root->lchild));
	printf("%d\n", getNodeData(root->rchild));
	printf("%d\n", getNodeData(root->lchild->lchild));

}