//用一个数组实现两个堆栈，最大限度地利用数组空间

#define MaxSize<存储数据元素的最大个数>
struct DStack
{
	ElementType Data[MaxSize];
	int Top1;/*堆栈1的栈顶指针*/
	int Top2/*堆栈2的栈顶指针*/
}S;
S.Top1 = -1;
S.Top2 = MaxSize;
/* Top1+Top2 = MaxSize  是错的 */

void Push( struct DStack *S, ElementType item, int Tag )
{	/* Tag作为区分两个堆栈的标志，取值为1和2*/
	if( S->Top2 - S->Top1 ==1 )
	{	 /*堆栈满*/
		cout<<"堆栈满"<<endl;
		return;
	}
	if( Tag ==1 )/*对第一个堆栈操作*/
		S->Data[ ++(S->Top1) ] = item;
	else		/*对第二个堆栈操作*/
		S->Data[ --(S->Top2) ] = item;
}

ElementType Pop( struct DStack *S, int Tag )
{	/*Tag作为区分两个堆栈的标志，取值为1和2*/
	if (Tag ==1 )
	{
		if (S->Top1 == -1)
		{
			cout<<"堆栈1空"<<endl;	return NULL;
		}
		else retuen S->Data[ (S->Top1)-- ];
	}
	else
	{
		if ( S->Top2 == MaxSize )
		{
			cout<<"堆栈2空"<<endl;	return NULL;
		}
		else return S->Data[ (S->Top2)++ ];
	}
}