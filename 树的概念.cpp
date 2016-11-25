

typedef struct TNode *Position;
typedef Position BinTree; /* 二叉树类型 */
struct TNode{ /* 树结点定义 */
    ElementType Data; /* 结点数据 */
    BinTree Left;     /* 指向左子树 */
    BinTree Right;    /* 指向右子树 */
};

//树内的所有子树必定不相交

满二叉树：每个结点都有两个孩子。
完全二叉树：不是满二叉树，允许缺掉最右下角的结点

二叉树第i层，最多有2（i-1）次方
深度为k层的二叉树最大结点数为：2(k)次方-1（满二叉树）
叶子结点数=度为2的结点数+1

顺序存储二叉树：满二叉树或者完全二叉树
非根结点的父结点的序号为：[i/2]
结点的左孩子为：2i
结点的右孩子为：2i+1


void InOrderTraversal( BinTree BT )//中序遍历
{
    if( BT ) {
        InOrderTraversal( BT->Left );
        /* 此处假设对BT结点的访问就是打印数据 */
        printf("%d ", BT->Data); /* 假设数据为整型 */
        InOrderTraversal( BT->Right );
    }
}
 
void PreOrderTraversal( BinTree BT )//先序遍历
{
    if( BT ) { 
        printf("%d ", BT->Data );
        PreOrderTraversal( BT->Left );
        PreOrderTraversal( BT->Right );
    }
}
 
void PostOrderTraversal( BinTree BT )//后序遍历
{
    if( BT ) {
        PostOrderTraversal( BT->Left );
        PostOrderTraversal( BT->Right );
        printf("%d ", BT->Data);
    }
}
 
void LevelOrderTraversal ( BinTree BT )//层次遍历
{ 
    Queue Q; 
    BinTree T;
 
    if ( !BT ) return; /* 若是空树则直接返回 */
     
    Q = CreatQueue(); /* 创建空队列Q */
    AddQ( Q, BT );//根结点入队
    while ( !IsEmpty(Q) ) {
        T = DeleteQ( Q );
        printf("%d\n", T->Data); /* 访问取出队列的结点 */
        if ( T->Left )   AddQ( Q, T->Left );
        if ( T->Right )  AddQ( Q, T->Right );
    }
}



二叉树的非递归的中序遍历

遇到一个结点，就把它压栈，并去遍历它的左子树
当左子树遍历结束后，从栈顶弹出这个结点并访问它
然后按其右指针再去中序遍历该结点的右子树

void InOrderTraversal( BinTree BT )
{
	BinTree T=BT;
	Stack S = CreatStack( MaxSize );//创建并初始化堆栈S
	while( T || !IsEmpty(S) )//一直向左并将沿途结点压人堆栈
	{
		while(T)
		{
			Push(S,T);
			T = T->Left;
		}
	if(!IsEmpty(S))
		{
			T = Pop(S);//结点弹出堆栈
			printf( "%5d", T->Data );//(访问)打印结点
			T = T->Right;//转向右子树
		}
	}
}



二叉树的非递归的先序遍历

遇到一个结点，就把它压栈，从栈顶弹出这个结点并访问它
并去遍历它的左子树，当左子树遍历结束后，
然后按其右指针再去中序遍历该结点的右子树
void InOrderTraversal( BinTree BT )
{
	BinTree T=BT;
	Stack S = CreatStack( MaxSize );//创建并初始化堆栈S
	while( T || !IsEmpty(S) )//一直向左并将沿途结点压人堆栈
	{
		while(T)
		{
			Push(S,T);
			printf( "%5d", T->Data );//(访问)打印结点
			T = T->Left;
		}
	if(!IsEmpty(S))
		{
			T = Pop(S);//结点弹出堆栈
			T = T->Right;//转向右子树
		}
	}
}

****应用****
输出二叉树中的叶子结点
void PreOrderPrintLeaves( BinTree BT )//先序遍历
{
    if( BT ) { 
    	if( !BT->Left && !BT->Right )//检测左右子树是否都为空
        	printf("%d ", BT->Data );
        PreOrderPrintLeaves( BT->Left );
        PreOrderPrintLeaves( BT->Right );
    }
}


求二叉树的高度
H = MAX( HL, HR )+1

int PostOrderGetHeight( BinTree BT )//后序遍历
{
	int HL, HR, MaxH;
    if( BT ) {
        HL = PostOrderGetHeight( BT->Left );//求左子树的深度
        HR = PostOrderGetHeight( BT->Right );//求右子树的深度
        MaxH = ( HL>HR )?HL:HR;//取左右子树较大的深度
        return ( MaxH+1 );
    }
    else return 0;//空树深度为0
}













