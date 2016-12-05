完全搜索二叉树用数组

#include<stdlib.h>
int main()
{
	……
	qsort( A, N, sizeof(单个元素的大小), compare );
	A:待排序序列的收元素的位置
	N:待排序序列的总长度
	compare:比较两个元素的大小,自己根据情况来实现
	……
}

//输入序列存在数组A,从小到大排序。
//ALeft数组最左边元素的下标
//ARight数组最右边元素的下标
//TRoot结果树根结点的位置

 void solve( int ALeft, int ARight, int TRoot)
 {
 	//初始调用 solve(0, N-1, 0)
 	n = ARight - ALeft+1;//元素的总个数
 	if( n==0 )
 		return;
 	else
 		L = GetLeftLength(n);//计算出n个结点的树的左子树有多少个结点
 	T[TRoot] = A[ ALeft+L ];
 	LeftTRoot = TRoot*2+1;
 	RightTRoot = LeftTRoot +1;
 	solve( ALeft, ALeft-1, LeftTRoot);
 	solve( ALeft+L+1, ARight, RightTRoot);
 }



