#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���Ľڵ�͸��ڵ� 
typedef struct _htNode
{
	char symbol;
	struct _htNode *left, *right;
}htNode;

typedef struct _htTree
{
	htNode * root;
}htTree;

//���кͶ��еĽڵ� 
typedef struct _queueNode
{   
	htNode * val;
	unsigned int weight;
	struct _queueNode *next;
}queueNode;

typedef struct _pQueue
{
	unsigned int size;
	queueNode *first;
}pQueue;

//���������ڵ� 
typedef struct _hlNode
{
	char symbol;
	char *code;
	struct _hlNode *next;
}hlNode;

typedef struct _hlTable
{
	hlNode *first;
	hlNode *last;
}hlTable;


//��ʼ������
void initPQueue(pQueue **queue)
{
	(*queue) = (pQueue *)malloc(sizeof(pQueue));
	(*queue)->first = NULL;
	(*queue)->size = 0;
}

//������ 
void addPQueue(pQueue **queue, htNode * val, unsigned int weight)
{
	if ((*queue)->size == 200)
	{
		printf("\nQueue is full\n");
		return;
	}
	//������нڵ�
	queueNode *aux = (queueNode *)malloc(sizeof(queueNode));
	aux->weight = weight;
	aux->val = val;

	if ((*queue)->size == 0 || (*queue)->first == NULL)
	{
		aux->next = NULL;
		(*queue)->first = aux;
		(*queue)->size = 1;
		return;
	}
	else
	{
		if (weight <= (*queue)->first->weight)
		{
			aux->next = (*queue)->first;
			(*queue)->first = aux;
			(*queue)->size++;
			return;
		}
		else
		{
			queueNode * iterator = (*queue)->first;
			while (iterator->next != NULL)
			{
				if (weight <= iterator->next->weight)
				{
					aux->next = iterator->next;
					iterator->next = aux;
					(*queue)->size++;
					return;
				}
				iterator = iterator->next;
			}
			if (iterator->next == NULL)
			{
				aux->next = NULL;
				iterator->next = aux;
				(*queue)->size++;
				return;
			}
		}
	}
}


htNode * getPQueue(pQueue **queue)
{
	htNode * returnValue;
	if ((*queue)->size > 0)
	{
		returnValue = (*queue)->first->val;
		(*queue)->first = (*queue)->first->next;
		(*queue)->size--;

		return returnValue;
	}
	else
	{
		printf("\nQueue is empty.\n");
		return 0;
	}
}



htTree * buildTree(char *input)
{
	int pro[200];
	for (int i = 0; i < 200; i++)
	{
		pro[i] = 0;
	}
	for (int j = 0; input[j] != '\0'; j++)
	{
		pro[(char)input[j]]++;
	}
	//pQueue���е�ͷָ��
	pQueue * huffmanQueue;
	initPQueue(&huffmanQueue);

	//������
	for (int k = 0; k < 200; k++)
	{
		if (pro[k] != 0)
		{
			//����һ�����Ľڵ�
			htNode *aux = (htNode *)malloc(sizeof(htNode));
			aux->left = NULL;
			aux->right = NULL;
			aux->symbol = (char)k;
			//�����ֱ�Ϊ ���еĵ�ַ��������Ľڵ㣬�Լ����ֵĴ���
			addPQueue(&huffmanQueue, aux, pro[k]);
		}
	}
	//���ɹ�������
	while (huffmanQueue->size != 1)
	{
		int weight = huffmanQueue->first->weight;
		weight +=  huffmanQueue->first->next->weight;
		htNode *left = getPQueue(&huffmanQueue);
		htNode *right = getPQueue(&huffmanQueue);

		htNode *newNode = (htNode *)malloc(sizeof(htNode));
		newNode->left = left;
		newNode->right = right;

		addPQueue(&huffmanQueue, newNode, weight);
	}
	htTree *tree = (htTree *)malloc(sizeof(htTree));
	tree->root = getPQueue(&huffmanQueue);
	return tree;
}


void traverseTree(htNode *treeNode, hlTable **table, int k, char code[256])
{
	if (treeNode->left == NULL &&treeNode->right == NULL)
	{
		code[k] = '\0';
		hlNode *aux = (hlNode *)malloc(sizeof(hlNode));
		aux->code=(char *)malloc(sizeof(char)*(strlen(code) + 1));
		
		strcpy(aux->code, code);
		
		aux->symbol = treeNode->symbol;
		aux->next = NULL;
		if ((*table)->first == NULL)
		{
			(*table)->first = aux;
			(*table)->last = aux;
		}
		else
		{
			(*table)->last->next = aux;
			(*table)->last = aux;
		}
	}
	if (treeNode->left != NULL)
	{
		code[k] = '0';
		traverseTree(treeNode->left, table, k + 1, code);
	}
	if (treeNode->right != NULL)
	{
		code[k] = '1';
		traverseTree(treeNode->right, table, k + 1, code);
	}
}



hlTable * buildTable(htTree * huffmanTree)
{
	hlTable * table = (hlTable *)malloc(sizeof(hlTable));
	table->first = NULL;
	table->last = NULL;

	char code[200];
	//k������һ���ͼ�һ
	int k = 0;
	
	//�����������ĸ��ڵ㣬������table,Ŀǰλ�ڵڼ��㣬����ַ���
	traverseTree(huffmanTree->root, &table, k, code);
	return table;
}

void text_to_code(hlTable *table,char *text)
{
	hlNode *traversal;
	printf("Encoding......\nInput string:\n%s\nEncoding string:\n",text);
	for (int i = 0; text[i] != '\0';i++)
	{
		traversal = table->first;
		while (traversal->symbol != text[i])
			traversal = traversal->next;
		printf("%s", traversal->code);
	}
	printf("\n");
}
void code_to_text(htTree *tree,char *code)
{
	htNode *traversal = tree->root;
	printf("\n\nDecoding.....\n\nInput string:\n%s\nDecoded sring:\n", code);
	for (int i = 0; code[i] != '\0';i++)
	{
		if (traversal->left == NULL&&traversal->right == NULL)
		{
			printf("%c", traversal->symbol);
			traversal = tree->root;
		}
		if (code[i] == '1')
			traversal = traversal->right;
		if (code[i] == '0')
			traversal = traversal->left;
		if (code[i] != '0'&&code[i] != '1')
		{
			printf("The input string is not coded correvtly!\n");
			return;
		}
	}
	if (traversal->left == NULL&&traversal->right == NULL)
	{
		printf("%c", traversal->symbol);
	}
}

int main()
{
	htTree *codeTree = buildTree("arfhrtfhsgdf");
	hlTable *codeTable = buildTable(codeTree);
	text_to_code(codeTable, "arfhrtfhsgdf");
	code_to_text(codeTree, "01011110001111100100011010110011110");
	return 0;
}
