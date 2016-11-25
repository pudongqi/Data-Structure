struct PolyNode
{
	int coef;	//系数
	int expon	//指数
	struct PolyNode *link;	//指向下一个结点的指针
};
typedef struct PolyNode *Polynomial;
Polynomial P1,P2;//结构指针

Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
	Polynomial front, rear,temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;/* y由front记录结果多项式链表头结点 */
	whlie(P1 && P2)//当两个多项式都有非零项待处理时
		switch(Compare(P1->expon, P2->expon))
		{
			case 1:
				Attach(P1->coef, P1->expon, &rear);
				P1 = P1->link;
				break;
			case 2:
				Attach(P2->coef, P2->expon, &rear);
				P2 = P2->link;
				break;
			case 3:
				sum = P1->coef+P2->coef;
				if(sum) Attach(sum, P1->expon, &rear);
				P1 = P1->link;
				P2 = P2->link;
				break;
		}
}
//将未处理完的另一个多项式的所有结点依次复制到结果多项式中去
for(; P1; P1=P1->link)	Attach(P1->coef, P1->expon, &rear);
for(; P2; P2=P2->link)	Attach(P2->coef, P2->expon, &rear);
rear->link = NULL;
temp = front;
front = front->link;//令front指向结果多项式第一个非零项
free(temp);//释放临时空表头结点
return front;


void Attach(int c, int e, Polynomial *pRear) //c为系数，e为指数，Polynomial为指针，所以pRear为二级指针
{
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode)); //(申请的空间的指针的类型)malloc(申请空间的大小)
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;//*pRear为一级指针
	*pRear = P;
}
int Compare(int P1, int P2)
{
	if(P1>P2)
		return 1;
	if(P1<P2)
		return -1;
	if(P1=P2)
		return 0;
}