#include <stdio.h>
#include <stdlib.h>

typedef struct binarytreeNode
{
	int data;
	struct binarytreeNode* lchild;
	struct binarytreeNode* rchild;
}bt;

bt* createBTN()
{
	bt* newNode = (bt*)malloc(sizeof(bt));
	newNode->data = 0;
	newNode->lchild = NULL;
	newNode->rchild = NULL;
	return newNode;
};
void setNodeData(bt* n, int data)
{
	n->data = data;
};
void removeSubTree(bt* n)
{
	if (n == NULL) return;
	removeSubTree(n->lchild);
	removeSubTree(n->rchild);
	free(n);
};
void setLeftSubTree(bt* parent,bt* lchild)
{
	if (parent->lchild != NULL)
	{
		removeSubTree(parent->lchild);
	}
	parent->lchild = lchild;
};
void setRightSubTree(bt* parent,bt* rchild)
{
	if (parent->rchild != NULL)
	{
		removeSubTree(parent->rchild);
	}
	parent->rchild = rchild;
};

int getNodeData(bt* n)
{
	return n->data;
}

// ÀüÀ§ Å½»ö		p-> l -> r
void preorderTraversal(bt* n)
{
	if (n == NULL) return;
	printf("%d ", n->data);
	preorderTraversal(n->lchild);
	preorderTraversal(n->rchild);
};
// ÁßÀ§ Å½»ö		l -> p -> r
void inorderTraversal(bt* n)
{
	if (n == NULL) return;
	inorderTraversal(n->lchild);
	printf("%d ", n->data);
	inorderTraversal(n->rchild);
};
// ÈÄÀ§ Å½»ö		l -> r -> p
void postorderTraversal(bt* n)
{
	if (n == NULL) return;
	postorderTraversal(n->lchild);
	postorderTraversal(n->rchild);
	printf("%d ", n->data);
};


void main()
{
	bt* root = createBTN(); 
	bt* leftNode = createBTN(); 
	bt* rightNode = createBTN(); 
	bt* leftLeftNode = createBTN();


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


	printf("\n==================\n"); 
	preorderTraversal(root); 
	printf("\n==================\n"); 
	inorderTraversal(root); 
	printf("\n==================\n"); 
	postorderTraversal(root); 
	removeSubTree(root); 
}