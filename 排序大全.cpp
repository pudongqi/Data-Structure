默认从小到大排序
稳定性：任意两个相等的数据，排序前后的相对位置不发生改变。
没有一种排序是任何情况下都表现最好的。

void Swap( ElementType *a, ElementType *b )
{
     ElementType t = *a; *a = *b; *b = t;
}



冒泡排序（BubbleSort）的基本概念是：依次比较相邻的两个数，将小数放在前面，大数放在后面。
即在第一趟：首先比较第1个和第2个数，将小数放前，大数放后。然后比较第2个数和第3个数，将小数放前，大数放后，如此继续，
直至比较最后两个数，将小数放前，大数放后。至此第一趟结束，将最大的数放到了最后。
在第二趟：仍从第一对数开始比较（因为可能由于第2个数和第3个数的交换，使得第1个数不再小于第2个数），将小数放前，大数放后，一直比较到倒数第二个数（倒数第一的位置上已经是最大的），
第二趟结束，在倒数第二的位置上得到一个新的最大数（其实在整个数列中是第二大的数）。如此下去，重复以上过程，直至最终完成排序。
void BubbleSort( ElementType A[], int N )
{/* 冒泡排序 */
	for( p=N-1; p>=0; p--)
	{
		int flag = 0;
		for( i=0; i<p; i++)//一趟冒泡
		{
			if( A[i] > A[i+1] )
			{
				Swap( A[i], A[i+1] );
				flag = 1;
			}
		}
		if( flag==0 )
			break;
	}	
}
最好情况:顺序T=O(N)
最坏情况:逆序T=O(N*N)
稳定的





插入排序的基本思想是每步将一个待排序的记录按其排序码值的大小，插到前面已经排好的文件中的适当位置，直到全部插入完为止。
插入排序方法主要有直接插入排序和希尔排序。

直接插入排序具体算法描述如下：
    1. 从第一个元素开始，该元素可以认为已经被排序
　　2. 取出下一个元素，在已经排序的元素序列中从后向前扫描
　　3. 如果该元素（已排序）大于新元素，将该元素移到下一位置
　　4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
　　5. 将新元素插入到下一位置中
　　6. 重复步骤2
void InsertionSort( ElementType A[], int N )
{ /* 插入排序 */
     int P, i;
     ElementType Tmp;
      
     for ( P=1; P<N; P++ ) {
         Tmp = A[P]; /* 取出未排序序列中的第一个元素*/
         for ( i=P; i>0 && A[i-1]>Tmp; i-- )
             A[i] = A[i-1]; /*依次与已排序序列中元素比较并右移*/
         A[i] = Tmp; /* 放进合适的位置 */
     }
}
-最好情况:顺序T=O(N)
-最坏情况:逆序T=O(N*N)
-稳定的
-交换两个相邻元素正好消去一个逆序对
-任何仅以交换相邻两元素来排序的算法，其平均时间复杂度为O(N*N)



希尔(Shell)排序的基本思想是：先取一个小于n的整数d1作为第一个增量把文件的全部记录分成d1个组。
所有距离为d1的倍数的记录放在同一个组中。先在各组内进行直接插入排序；
然后，取得第二个增量d2<d1重复上述的分组和排序，直至所取的增量di=1，即所有记录放在同一组中进行直接插入排序为止。
该方法实质上是一种分组插入方法。
一般取d1=n/2，di+1=di/2。如果结果为偶数，则加1，保证di为奇数。



希尔(Shell)排序
void ShellSort( ElementType A[], int N )
{ /* 希尔排序 */
     int D, P, i;
     ElementType Tmp;
 		for ( D=N/2; D>0; D/=2 )
	{
    	 for ( P=1; P<N; P++ ) 
    	 {
      	   		Tmp = A[P]; /* 取出未排序序列中的第一个元素*/
       	  		for ( i=P; i>0 && A[i-1]>Tmp; i-- )
         	    A[i] = A[i-1]; /*依次与已排序序列中元素比较并右移*/
         		A[i] = Tmp; /* 放进合适的位置 */
     	}
	}    
}






堆的定义：n个关键字序列Kl，K2，…，Kn称为(Heap)，当且仅当该序列满足如下性质(简称为堆性质)：
　　(1) ki≤K2i 且 ki≤K2i+1
    或(2)Ki≥K2i 且 ki≥K2i+1(1≤i≤ n)
    若将此序列所存储的向量R[1..n]看作是一棵完全二叉树的存储结构，则堆实质上是满足如下性质的完全二叉树：
    树中任一非叶结点的关键字均不大于(或不小于)其左右孩子(若存在)结点的关键字。
    根结点(堆顶)的关键字是堆里所有结点关键字中最小者，称为小根堆；根结点的关键字是堆里所有结点关键字中最大者，称为大根堆。
   
    用大根堆排序的基本思想如下：
　　1、先将初始文件R[1..n]建成一个大根堆,此堆为初始的无序区
　　2、再将关键字最大的记录R[1](即堆顶)和无序区的最后一个记录R[n]交换，由此得到新的无序区R[1..n-1]和有序区R[n]，且满足R[1..n-1].keys≤R[n].key
　　3、由于交换后新的根R[1]可能违反堆性质，故应将当前无序区R[1..n-1]调整为堆。
   然后再次将R[1..n-1]中关键字最大的记录R[1]和该区间的最后一个记录R[n-1]交换，由此得到新的无序区R[1..n-2]和有序区R[n-1..n]，且仍满足关系R[1..n-2].keys≤R[n-1..n].keys，同样要将R[1..n-2]调整为堆。
　　……
　　直到无序区只有一个元素为止。  
void PercDown( ElementType A[], int p, int N )
{ 
  /* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    ElementType X;
 
    X = A[p]; /* 取出根结点存放的值 */
    for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
        Child = Parent * 2 + 1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;  /* Child指向左右子结点的较大者 */
        if( X >= A[Child] ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            A[Parent] = A[Child];
    }
    A[Parent] = X;
}
 
void HeapSort( ElementType A[], int N ) 
{ /* 堆排序 */
     int i;
       
     for ( i=N/2-1; i>=0; i-- )/* 建立最大堆 */
         PercDown( A, i, N );
      
     for ( i=N-1; i>0; i-- ) {
         /* 删除最大堆顶 */
         Swap( &A[0], &A[i] ); 
         PercDown( A, 0, i );
     }
}
平均比较次数为：O( N*log N )






归并排序是将两个或两个以上的有序子表合并成一个新的有序表。
初始时，把含有n个结点的待排序序列看作由n个长度都为1的有序子表组成，将它们依次两两归并得到长度为2的若干有序子表，再对它们两两合并。
直到得到长度为n的有序表，排序结束。
    归并操作的工作原理如下：
　　1、申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
　　2、设定两个指针，最初位置分别为两个已经排序序列的起始位置
　　3、比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
　　4、重复步骤3直到某一指针达到序列尾
　　5、将另一序列剩下的所有元素直接复制到合并序列尾
/* 归并排序 - 循环实现 */
/* 这里Merge函数在递归版本中给出 */
/* length = 当前有序子列的长度*/
void Merge_pass( ElementType A[], ElementType TmpA[], int N, int length )
//ElementType A[]为待排序的数组。ElementType TmpA[]为临时存放的数组
{ /* 两两归并相邻有序子列 */
     int i, j; 
     for ( i=0; i <= N-2*length; i += 2*length )
         Merge( A, TmpA, i, i+length, i+2*length-1 );
     if ( i+length < N ) /* 归并最后2个子列*/
         Merge( A, TmpA, i, i+length, N-1);
     else /* 最后只剩1个子列*/
         for ( j = i; j < N; j++ ) TmpA[j] = A[j];
}
 
void Merge_Sort( ElementType A[], int N )
{ 
     int length; 
     ElementType *TmpA;
      
     length = 1; /* 初始化子序列长度*/
     TmpA = malloc( N * sizeof( ElementType ) );
     if ( TmpA != NULL ) {
          while( length < N ) {
              Merge_pass( A, TmpA, N, length );
              length *= 2;
              Merge_pass( TmpA, A, N, length );
              length *= 2;
          }
          free( TmpA );
     }
     else printf( "空间不足" );
}
是稳定的




快速排序采用了一种分治的策略，通常称其为分治法，其基本思想是：将原问题分解为若干个规模更小但结构与原问题相似的子问题。
递归地解这些子问题，然后将这些子问题的解组合为原问题的解。
    快速排序的具体过程如下：
    第一步，在待排序的n个记录中任取一个记录，以该记录的排序码为准，将所有记录分成两组，第1组各记录的排序码都小于等于该排序码，第2组各记录的排序码都大于该排序码，并把该记录排在这两组中间。
    第二步，采用同样的方法，对左边的组和右边的组进行排序，直到所有记录都排到相应的位置为止。
/* 快速排序 */
ElementType Median3( ElementType A[], int Left, int Right )//int Left 是头, int Right 是尾
{ 
    int Center = (Left+Right) / 2;//中间的位置
    if ( A[Left] > A[Center] )
        Swap( &A[Left], &A[Center] );
    if ( A[Left] > A[Right] )
        Swap( &A[Left], &A[Right] );
    if ( A[Center] > A[Right] )
        Swap( &A[Center], &A[Right] );
    /* 此时A[Left] <= A[Center] <= A[Right] */
    Swap( &A[Center], &A[Right-1] ); /* 将基准Pivot藏到右边*/
    /* 只需要考虑A[Left+1] … A[Right-2] */
    return  A[Right-1];  /* 返回基准Pivot */
}
 
void Qsort( ElementType A[], int Left, int Right )//int Left 是头, int Right 是尾
{ /* 核心递归函数 */ 
     int Pivot, Cutoff, Low, High;
       
     if ( Cutoff <= Right-Left ) { /* 如果序列元素充分多，进入快排 */
          Pivot = Median3( A, Left, Right ); /* 选基准 */ 
          Low = Left; High = Right-1;
          while (1) { /*将序列中比基准小的移到基准左边，大的移到右边*/
               while ( A[++Low] < Pivot ) ;
               while ( A[--High] > Pivot ) ;
               if ( Low < High ) Swap( &A[Low], &A[High] );
               else break;
          }
          Swap( &A[Low], &A[Right-1] );   /* 将基准换到正确的位置 */ 
          Qsort( A, Left, Low-1 );    /* 递归解决左边 */ 
          Qsort( A, Low+1, Right );   /* 递归解决右边 */  
     }
     else InsertionSort( A+Left, Right-Left+1 ); /* 元素太少，用简单排序 */ 
}
 
void QuickSort( ElementType A[], int N )
{ /* 统一接口 */
     Qsort( A, 0, N-1 );
}








 
/* 假设元素最多有MaxDigit个关键字，基数全是同样的Radix */
#define MaxDigit 4
#define Radix 10
 
/* 桶元素结点 */
typedef struct Node *PtrToNode;
struct Node {
    int key;
    PtrToNode next;
};
 
/* 桶头结点 */
struct HeadNode {
    PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];
  
int GetDigit ( int X, int D )
{ /* 默认次位D=1, 主位D<=MaxDigit */
    int d, i;
     
    for (i=1; i<=D; i++) {
        d = X % Radix;
        X /= Radix;
    }
    return d;
}



 设单关键字的每个分量的取值范围均是C0<=Kj<=Crd-1(0<=j<=rd),可能的取值个数rd称为基数．基数的选择和关键字的分解因关键字的类型而异．
(1)若关键字是十进制整数，则按个、十等位进行分解，基数rd=10,C0=0,C9=9,d为最长整数的位数．
(2)若关键字是小写的英文字符串，则rd=26,C0='a',C25='z',d为最长字符串的长度．
基数排序的基本思想是：从低位到高位依次对待排序的关键码进行分配和收集，经过d趟分配和收集，就可以得到一个有序序列．
基数排序从低位到高位进行，使得最后一次计数排序完成后，数组有序。其原理在于对于待排序的数据，整体权重未知的情况下，先按权重小的因子排序，然后按权重大的因子排序。
例如比较时间，先按日排序，再按月排序，最后按年排序，仅需排序三次。但是如果先排序高位就没这么简单了。

我的理解是：基数排序算法中，数据可分解为d个因子，每个因子对排序结果都有影响（即权重），先按权重小的因子进行排序，后按权重大的因子进行排序，所有因子排序完即得结果。
如时间可分解为三个因子：日、月、年，先按日对时间排序，再按月对时间排序，最后按年对时间进行排序，即可。注意：每一趟按因子进行的排序都必须是稳定的！
void LSDRadixSort( ElementType A[], int N )
{ /* 基数排序 - 次位优先 */
     int D, Di, i;
     Bucket B;
     PtrToNode tmp, p, List = NULL; 
      
     for (i=0; i<Radix; i++) /* 初始化每个桶为空链表 */
         B[i].head = B[i].tail = NULL;
     for (i=0; i<N; i++) { /* 将原始序列逆序存入初始链表List */
         tmp = (PtrToNode)malloc(sizeof(struct Node));
         tmp->key = A[i];
         tmp->next = List;
         List = tmp;
     }
     /* 下面开始排序 */ 
     for (D=1; D<=MaxDigit; D++) { /* 对数据的每一位循环处理 */
         /* 下面是分配的过程 */
         p = List;
         while (p) {
             Di = GetDigit(p->key, D); /* 获得当前元素的当前位数字 */
             /* 从List中摘除 */
             tmp = p; p = p->next;
             /* 插入B[Di]号桶尾 */
             tmp->next = NULL;
             if (B[Di].head == NULL)
                 B[Di].head = B[Di].tail = tmp;
             else {
                 B[Di].tail->next = tmp;
                 B[Di].tail = tmp;
             }
         }
         /* 下面是收集的过程 */
         List = NULL; 
         for (Di=Radix-1; Di>=0; Di--) { /* 将每个桶的元素顺序收集入List */
             if (B[Di].head) { /* 如果桶不为空 */
                 /* 整桶插入List表头 */
                 B[Di].tail->next = List;
                 List = B[Di].head;
                 B[Di].head = B[Di].tail = NULL; /* 清空桶 */
             }
         }
     }
     /* 将List倒入A[]并释放空间 */
     for (i=0; i<N; i++) {
        tmp = List;
        List = List->next;
        A[i] = tmp->key;
        free(tmp);
     } 
}


/* 基数排序 - 主位优先 */
 
/* 假设元素最多有MaxDigit个关键字，基数全是同样的Radix */
 
#define MaxDigit 4
#define Radix 10
 
/* 桶元素结点 */
typedef struct Node *PtrToNode;
struct Node{
    int key;
    PtrToNode next;
};
 
/* 桶头结点 */
struct HeadNode {
    PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];
  
int GetDigit ( int X, int D )
{ /* 默认次位D=1, 主位D<=MaxDigit */
    int d, i;
     
    for (i=1; i<=D; i++) {
        d = X%Radix;
        X /= Radix;
    }
    return d;
}
 
void MSD( ElementType A[], int L, int R, int D )
{ /* 核心递归函数: 对A[L]...A[R]的第D位数进行排序 */
     int Di, i, j;
     Bucket B;
     PtrToNode tmp, p, List = NULL; 
     if (D==0) return; /* 递归终止条件 */
      
     for (i=0; i<Radix; i++) /* 初始化每个桶为空链表 */
         B[i].head = B[i].tail = NULL;
     for (i=L; i<=R; i++) { /* 将原始序列逆序存入初始链表List */
         tmp = (PtrToNode)malloc(sizeof(struct Node));
         tmp->key = A[i];
         tmp->next = List;
         List = tmp;
     }
     /* 下面是分配的过程 */
     p = List;
     while (p) {
         Di = GetDigit(p->key, D); /* 获得当前元素的当前位数字 */
         /* 从List中摘除 */
         tmp = p; p = p->next;
         /* 插入B[Di]号桶 */
         if (B[Di].head == NULL) B[Di].tail = tmp;
         tmp->next = B[Di].head;
         B[Di].head = tmp;
     }
     /* 下面是收集的过程 */
     i = j = L; /* i, j记录当前要处理的A[]的左右端下标 */
     for (Di=0; Di<Radix; Di++) { /* 对于每个桶 */
         if (B[Di].head) { /* 将非空的桶整桶倒入A[], 递归排序 */
             p = B[Di].head;
             while (p) {
                 tmp = p;
                 p = p->next;
                 A[j++] = tmp->key;
                 free(tmp);
             }
             /* 递归对该桶数据排序, 位数减1 */
             MSD(A, i, j-1, D-1);
             i = j; /* 为下一个桶对应的A[]左端 */
         } 
     } 
}
 
void MSDRadixSort( ElementType A[], int N )
{ /* 统一接口 */
    MSD(A, 0, N-1, MaxDigit); 
}