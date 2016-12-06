/* 广义表 */

/*-------------------- 广义表的存储结构 --------------------*/
typedef enum { ATOM=0; LIST=1 }ElemTag;
			//ATOM(=0)标志原子,LIST(=1)标志子表
typedef struct GLNode
{
	ElemTag tag;//公共部分,用于区分原子结点和表结点。
	union{
		AtomType data;//data是原子结点的值域,AtomType由用户定义。
		struct{ struct GLNode *hp, *tp }ptr;
		//ptr是表结点的指针域,ptr.hp和ptr.tp分别指向表头和表尾。
	};
}*GList;

/*-------------------- 广义表的遍历 --------------------*/
void OutputGList( GList LS )
{
	if( !LS )	cout<<"()";//输出空表
	else
	{
		if( LS->tag==ATOM )	cout<<LS->data;//输出单原子
		else
		{
			cout<<"(";//输出广义表的左括弧。
			p=LS;
			while( p )
			{
				OutputGList( p->ptr.hp )//输出第i项数据元素。
				p = p->ptr.tp;
				if( p )	cout<<","//表尾不空时输出逗号
			}
			cout<<")";//输出广义表的右括弧。
		}
	}
}