#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//树的节点和根节点 
typedef struct _htNode
{
	char symbol;
	struct _htNode *left, *right;
}htNode;

typedef struct _htTree
{
	htNode * root;
}htTree;

//队列和队列的节点 
typedef struct _queueNode
{   
	htNode * val;
	int weight;
	struct _queueNode *next;
}queueNode;

typedef struct _pQueue
{
	  int size;
	queueNode *first;
}pQueue;

//链表和链表节点 
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


//初始化队列
void initPQueue(pQueue **queue)
{
	(*queue) = (pQueue *)malloc(sizeof(pQueue));
	(*queue)->first = NULL;
	(*queue)->size = 0;
}

//填充队列 
void addPQueue(pQueue **queue, htNode * val,   int weight)
{
	if ((*queue)->size == 200)
	{
		printf("\nQueue is full\n");
		return;
	}
	//分配队列节点
	queueNode *new_node = (queueNode *)malloc(sizeof(queueNode));
	new_node->weight = weight;
	new_node->val = val;

	if ((*queue)->size == 0 || (*queue)->first == NULL)
	{
		new_node->next = NULL;
		(*queue)->first = new_node;
		(*queue)->size = 1;
		return;
	}
	else
	{
		if (weight <= (*queue)->first->weight)
		{
			new_node->next = (*queue)->first;
			(*queue)->first = new_node;
			(*queue)->size++;
			return;
		}
		else
		{
			queueNode * temp_node = (*queue)->first;
			while (temp_node->next != NULL)
			{
				if (weight <= temp_node->next->weight)
				{
					new_node->next = temp_node->next;
					temp_node->next = new_node;
					(*queue)->size++;
					return;
				}
				temp_node = temp_node->next;
			}
			if (temp_node->next == NULL)
			{
				new_node->next = NULL;
				temp_node->next = new_node;
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
	//pQueue队列的头指针
	pQueue * huffmanQueue;
	initPQueue(&huffmanQueue);

	//填充队列
	for (int k = 0; k < 200; k++)
	{
		if (pro[k] != 0)
		{
			//分配一个树的节点
			htNode *new_tree_node = (htNode *)malloc(sizeof(htNode));
			new_tree_node->left = NULL;
			new_tree_node->right = NULL;
			new_tree_node->symbol = (char)k;
			//参数分别为 队列的地址，待插入的节点，以及出现的次数
			addPQueue(&huffmanQueue, new_tree_node, pro[k]);
		}
	}
	//生成哈夫曼树
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


void runTree(htNode *treeNode, hlTable **table, int k, char code[256])
{
	if (treeNode->left == NULL &&treeNode->right == NULL)
	{
		code[k] = '\0';
		hlNode *new_node = (hlNode *)malloc(sizeof(hlNode));
		new_node->code=(char *)malloc(sizeof(char)*(strlen(code) + 1));
		
		strcpy(new_node->code, code);
		
		new_node->symbol = treeNode->symbol;
		new_node->next = NULL;
		if ((*table)->first == NULL)
		{
			(*table)->first = new_node;
			(*table)->last = new_node;
		}
		else
		{
			(*table)->last->next = new_node;
			(*table)->last = new_node;
		}
	}
	if (treeNode->left != NULL)
	{
		code[k] = '0';
		runTree(treeNode->left, table, k + 1, code);
	}
	if (treeNode->right != NULL)
	{
		code[k] = '1';
		runTree(treeNode->right, table, k + 1, code);
	}
}



hlTable * buildTable(htTree * huffmanTree)
{
	hlTable * table = (hlTable *)malloc(sizeof(hlTable));
	table->first = NULL;
	table->last = NULL;

	char code[200];
	//k往下走一级就加一
	int k = 0;
	
	//传进哈夫曼的根节点，待填充的table,目前位于第几层，添加字符串
	runTree(huffmanTree->root, &table, k, code);
	return table;
}

void text_to_code(hlTable *table,char *text)
{
	hlNode *runNode;
	printf("编码结果为： ");
	for (int i = 0; text[i] != '\0';i++)
	{
		runNode = table->first;
		while (runNode->symbol != text[i])
			runNode = runNode->next;
		printf("%s", runNode->code);
	}
	printf("\n");
}
void code_to_text(htTree *tree,char *code)
{
	htNode *runNode = tree->root;
	printf("解码结果为：   ");
	for (int i = 0; code[i] != '\0';i++)
	{
		if (runNode->left == NULL&&runNode->right == NULL)
		{
			printf("%c", runNode->symbol);
			runNode = tree->root;
		}
		if (code[i] == '1')
			runNode = runNode->right;
		if (code[i] == '0')
			runNode = runNode->left;
		if (code[i] != '0'&&code[i] != '1')
		{
			printf("The input string is not coded correvtly!\n");
			return;
		}
	}
	if (runNode->left == NULL&&runNode->right == NULL)
	{
		printf("%c", runNode->symbol);
	}
}
char text[1000];
void read()
{
	FILE *fp;
	fp=fopen("ha.txt", "r");
	
	if (fp == NULL)
	{
		printf("Failure to open ha.txt!\n");
	}
	else
	{
			fscanf(fp,"%s",text);	
	}
	fclose(fp);
}

int main()
{
	read();
	printf("此哈夫曼编码表根据'ha.text'生成\n"); 
	
	htTree *codeTree = buildTree(text);
	hlTable *codeTable = buildTable(codeTree);
	char text_input[1000];
	char code[1000];
	
	
	printf("请输入要编码的文本:\n");
	scanf("%s",text_input);
	text_to_code(codeTable,text_input );
	printf("请输入要解码的文本:\n");
	scanf("%s",code);
	code_to_text(codeTree, code);
	return 0;
}
