#include"exptree.h"

using namespace std;

void InitExprTreeNode(ExprTreeNode *root, char elem, struct ExprTreeNode *leftPtr, struct ExprTreeNode *rightPtr)
{
	if( root != NULL )
	{
		root->dataltem = elem;
		root->left = leftPtr;
		root->right = rightPtr;
	}
}//初始化内部结点

void InitExprTree( ExprTreeNode *root )
{
	if( root != NULL )
	{
		root->dataltem = 0;
		root->left = NULL;
		root->right = NULL;
	}
	else
		return;
	
}//初始化头结点

void DeExprTree( ExprTreeNode *root )
{
	if (root == NULL)
		return ;
	else
		DeExprTree( root->right );
		DeExprTree( root->left );
		free( root );
		root = NULL;
}

void Build( ExprTreeNode *root )
{
	//按先序输入二叉树中的结点的值
	char number;
	cin>>number;//输入的结点的数据值
		if( root!= NULL )
		{
			cout<<"ERROR"<<endl;
			exit(0);
			if( number>='0' && number<='9')
			{
				root->dataltem = number;
				root->left = NULL;//递归构造左子树
				root->right = NULL;//递归构造右子树
			}
			else
			{
				root->dataltem = number;
				struct ExprTreeNode *left = new ExprTreeNode;
				struct ExprTreeNode *right = new ExprTreeNode;
				root->left = left;
				root->right = right;
				Build(root->left);
				Build(root->right);
			}
		}
}

void Expression( ExprTreeNode *root )
{//中序遍历
	if( root!=NULL )
	{
		cout<<"(";
		Expression( root->left );
		cout<<root->dataltem;
		Expression( root->right );
		cout<<")";
	}
}

int evaitems[100];
int evatop = 0;
void evaSub(ExprTreeNode *root) {
    if (root) {
        evaitems[evatop] = root->dataltem;
        evatop++;
        evaSub(root->left);
        evaSub(root->right);
    }
}
float evaluate(ExprTreeNode *root) {
    evaSub(root);
    char items[100];
    float operands[100];
    int itop = 0;
    int otop = 0;
    for (int i=0; i<evatop; i++) {
        operands[otop] = float(evaitems[i]);
        otop++;
    }

    while(otop!=1) {
        for(int j=0; j<otop; j++) {
            if(operands[j]<'0'&&operands[j+1]>='0'&&operands[j+2]>='0') {

                float result;
                switch (char(operands[j])) {
                    case '+': result = operands[j+1] + operands[j+2] - 96.0; break;
                    case '-': result = operands[j+1] - operands[j+2]; break;
                    case '*': result = (operands[j+1]-48.0)*(operands[j+2]-48.0); break;
                    case '/': result = (operands[j+1]-48.0)/(operands[j+2]-48.0); break;
                }

                operands[j] = result+48;
                for(int k=j+1; k<otop-2; k++) {
                    operands[k] = operands[k+2];
                }
                otop-=2;
            }

        }
    }
    return float(operands[0]-48);
}


int copyitems[100];
int copytop = 0;
void copySub(ExprTreeNode *root) {
    if (root) {
        copyitems[copytop] = root->dataltem;
        copytop++;
        copySub(root->left);
        copySub(root->right);
    }
}
void buildcopy(ExprTreeNode *root) {
    int user_input = copyitems[0];

    for(int i=0; i<copytop-1; i++) {
        copyitems[i] = copyitems[i+1];
    }
    copytop-=1;

    if (user_input>='0'&&user_input<='9') {
        root->dataItem = char(user_input);
        root->left = NULL;
        root->right = NULL;
    } else {
        root->dataItem = char(user_input);
        struct ExprTreeNode *left = new ExprTreeNode;
        struct ExprTreeNode *right = new ExprTreeNode;
        root->left = left;
        root->right = right;
        buildcopy(root->left);
        buildcopy(root->right);

    }
}
ExprTreeNode * ExprTreeCopy(ExprTreeNode *T) {
    copySub(T);
    struct ExprTreeNode *newcopy = new struct ExprTreeNode;
    buildcopy(newcopy);
    return newcopy;
}

void commute(ExprTreeNode *root) {
    if (root) {
        struct ExprTreeNode *tmp;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        commute(root->left);
        commute(root->right);
    }
}
void Clear( ExprTreeNode *root )
{//先序遍历
	if( root!=NULL )
	{
		root->dataltem = NULL;
		Clear( root->left );
		Clear( root->right );
	}
}

void ShowSub( ExprTreeNode *root, ExprTreeNode *p, int level)
{
	if( p != NULL )
	{
		ShowSub( p->left );
		cout<<p->dataltem;
		ShowSub( p->right );
	}
}

