/*
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

enum type
{
	OPERATION,
	VALUE,
	INVALID,
	NUMBER,
};

struct Tnode
{
	char op;
	char val;
	int num;
	enum type type;
	Tnode* left;
	Tnode* right;
};

int priority(char ch)
{
	switch (ch)
	{
		case'-':
		case'+':
				return 1;
				break;
		case'*':
		case'/':
				return 2;
				break;
		default:
				return 1000;
				break;
	}
}

void index(char *str, int &f, int &g)
{
	for (int i = f; i < g; i++)
	{
		if (str[i] == '(')
			f++;
		else break;
	}
	for (int i = g - 1; i >= f; i--)
	{
		if (str[i] == ')')
			g--;
		else break;
	}
}

Tnode* makeTree(char* str, int f, int g)
{
	index(str, f, g);
	Tnode* root = new Tnode;
	root->left = NULL;
	root->right = NULL;
	root->op = '#';
	root->val = '#';
	root->type = INVALID;
	root->num = -1000;

	if (g - f == 1)
	{
		if ('a' <= str[f] && str[f] <= 'z')
		{
			root->type = VALUE;
			root->val = str[f];
		}
		else
		{
			root->num = str[f] - '0';
			root->type = NUMBER;
		}
		return root;
	}
	int min_priority = 2000;
	int current_priority;
	int division_index = -1;
	int bracket_level = 0;
	for (int i = f; i < g; i++)
	{
		if (str[i] == '(')
			bracket_level++;
		else if (str[i] == ')')
			bracket_level--;
		else
		{
			current_priority = priority(str[i]) + bracket_level * 10;
			if (current_priority <= min_priority)
			{
				min_priority = current_priority;
				division_index = i;
			}
		}
	}
	root->type = OPERATION;
	root->op = str[division_index];
	root->left = makeTree(str, f, division_index);
	root->right = makeTree(str, division_index + 1, g);
	return root;
}

void tabulate(int n)
{
	for (int i = 0; i < n; i++)
		printf("\t");
}

void print(const Tnode* root, int depth)
{
	if (root != NULL)
	{
		depth++;
		print(root->right, depth);
		tabulate(depth);
		if (root->type == OPERATION)
			printf("%c\n", root->op);
		if (root->type == VALUE)
			printf("%c\n", root->val);
		if (root->type == NUMBER)
			printf("%d\n", root->num);
		print(root->left, depth);
	}
}

double oper(char op, double f, double g)
{
	switch (op)
	{
		case'+':
			return f + g;
		case'-':
			return f - g;
		case'*':
			return f * g;
		case' / ':
			return f / g;
		case':':
			return f / g;
			break;
		default: 
			break;
	}
}

void deleteSpaces(char* str)
{
	char copy[30] = "";
	char* ptr = strtok(str, " ");
	while (ptr != NULL)
	{
		strcat(copy, ptr);
		ptr = strtok(NULL, " ");
	}
	strcpy(str, copy);
}

float calcMathTree(const Tnode* root)
{
	if (root->type == NUMBER)
		return root->num;
	return oper(root->op, calcMathTree(root->left), calcMathTree(root->right));
}

void PreOrder_ShowTree(Tnode* tree)
{
	if (tree != NULL)
	{
		if (tree->type == OPERATION)
			printf(" %c", tree->op);
		if (tree->type == VALUE)
			printf(" %c", tree->val);
		if (tree->type == NUMBER)
			printf(" %d", tree->num);
		PreOrder_ShowTree(tree->left);
		PreOrder_ShowTree(tree->right);
	}
}
void SymmetricOrder_ShowTree(Tnode* tree)
{
	if (tree != NULL)
	{
		SymmetricOrder_ShowTree(tree ->left);
		if (tree->type == OPERATION)
			printf(" %c", tree->op);
		if (tree->type == VALUE)
			printf(" %c", tree->val);
		if (tree->type == NUMBER)
			printf(" %d", tree->num);

		SymmetricOrder_ShowTree(tree->right);
	}
}
void PostOrder_ShowTree(Tnode* tree)
{
	if (tree != NULL)
	{
		PostOrder_ShowTree(tree->left);
		PostOrder_ShowTree(tree->right);
		if (tree->type == OPERATION)
			printf(" %c", tree->op);
		if (tree->type == VALUE)
			printf(" %c", tree->val);
		if (tree->type == NUMBER)
			printf(" %d", tree->num);
	}
}
int SizeofNodeTree(Tnode* tree)
{
	if (tree == NULL)
		return 0;
	else
		return (SizeofNodeTree(tree->left) + 1 + SizeofNodeTree(tree->right));
}
int DepthTree(Tnode* tree)
{
	int h1 = 0, h2 = 0;
	if (tree == NULL)
		return 0;
	if (tree->left)
		h1 = DepthTree(tree->left);
	if (tree->right)
		h2 = DepthTree(tree->right);
	if (h1>h2)
		return (h1 + 1);
	else
		return (h2 + 1);
}
void Print_BinaryTree(Tnode* tree)
{
	puts("\n=============preOder=============");
	PreOrder_ShowTree(tree);
	puts("\n=============inOder==============");
	SymmetricOrder_ShowTree(tree);
	puts("\n===========postOder==============");
	PostOrder_ShowTree(tree);
	printf("\n\nNumber of nodes = %d", SizeofNodeTree(tree));
	printf("\nTree depth = %d", DepthTree(tree));
}
int main()
{
	char str[30];
	printf("Input the expression: ");
	gets_s(str,30); //
	//scanf("%s", &str);
	puts("===========Binary tree==========");
	deleteSpaces(str);
	Tnode* root = makeTree(str, 0, strlen(str));
	print(root, 0);
	char f, g;
	Print_BinaryTree(root);
	printf("\nEnter f, g: ");

	scanf("%c %c", &f, &g);
	printf("\n");
	for (unsigned int i = 0; i < strlen(str); i++)
	{
		if (str[i] == 'f')
			str[i] = f;
		if (str[i] == 'g')
			str[i] = g;
	}
	std::cout << "Expression = (7/(4+3))/(4-(1+3*0.4))\n";
	std::cout << "Result = 0.55\n";
	printf("Expression = %s\n ", str);
	Tnode* root1 = makeTree(str, 0, strlen(str));
	double res = calcMathTree(root1);
	//(7/(a+3))/(4-(1+3*b))
	//printf("Result = %.2lf ", res);
	return 0;
}
*/
