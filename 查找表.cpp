/* 查找表--静态查找表 */

/*-------------------- 顺序查找 --------------------*/
int Search_Seq( SSTable ST, KeyType kval )
{
	//在顺序表ST中顺序查找其关键字等于kval的数据元素
	//若找到,则函数值为元素在表中的位置,否则为0;
	ST.elem[0].key = kval;//设置哨兵
	for( i=ST.length; St.elem[i].key != kval; --i );//从后往前查找
		return i;//找不到时,i为0;
}


/*-------------------- 折半查找 --------------------*/
int Search_Bin( SSTable ST, KeyType kval )
{
	//在有序表ST中折半查找其关键字等于kval的数据元素
	//若找到,则函数值为该元素在表中的位置,否则为0
	int low = 1;
	int high = St.length;//设置区间初值
	while( low<=high )
	{
		int mid = (low + high)/2;
		if( kval == ST.elem[mid].key )
			return mid;//找到待查元素
		else
			if( kval<ST.elem[mid].key )
				high = mid-1;//继续在前半区间内进行查找
			else
				low = mid+1;//继续在后半区间内进行查找
	}
	return 0;
}


/* 查找表--动态查找表 */