#ifndef TREE_EXPTREE_H
#define TREE_EXPTREE_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

#define MAX 100 
#define TRUE  1
#define FALSE 0
#define OK    1
#define ERROR 0
#define INFEASIBLE -1

struct ExprTreeNode
{
	char dataltem;
	struct ExprTreeNode *left, *right;
};

void InitExprTreeNode(ExprTreeNode *root, char elem, struct ExprTreeNode *leftPtr, struct ExprTreeNode *rightPtr);
void InitExprTree( ExprTreeNode *root );
void DeExprTree( ExprTreeNode *root );
void Build( ExprTreeNode *root );
void Expression( ExprTreeNode *root );
float Evaluate( ExprTreeNode *root );
void Clear( ExprTreeNode *root );
void ShowStructure( ExprTreeNode *root );
void ShowSub( ExprTreeNode *root);
void evaSub(ExprTreeNode *root);
ExprTreeNode * ExprTreeCopy(ExprTreeNode *T);
void commute(ExprTreeNode *root);
#endif 
