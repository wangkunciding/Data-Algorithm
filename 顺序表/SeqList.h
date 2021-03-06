
#include <stdio.h>

/////////////////// 线性顺序表存储结构操作 //////////////////////

/*
时间复杂度：
插入和删除平均时间复杂度为 O(n)，其余为 O(1)

优点：算法简单，内存单位利用率较高
缺点：需要预先确定数据元素的最大个数
*/



typedef struct
{
	DataType list[MaxSize];
	int size;          // 个数
} SeqList;


// 初始化
void ListInitiate(SeqList * L)
{
	L->size = 0;
}

// 求元素个数
int ListLength(SeqList L)
{
	return L.size;
}

// 插入元素 x
int ListInsert(SeqList * L, int i, DataType x)
{
	if (L->size >= MaxSize)
	{
		printf("顺序表已满无法插入!\n");
		return 0;
	}
	else if (i < 0 || i> L->size)
	{
		printf("参数 i 不合法！\n");
		return 0;
	}
	else
	{
		// 从后向前依次后移数据，为插入做准备
		for (int j = L->size; j > i; j--)
			L->list[j] = L->list[j-1];
		L->list[i] = x;
		L->size++;
		return 1;
	}
}


// 删除数据
int ListDelete(SeqList *L, int i, DataType *x)
{
	if (L->size <= 0)
	{
		printf("顺序表已为空，无数据可删除！\n");
		return 0;
	}
	else if (i < 0 || i > L->size-1)
	{
		printf("参数 i 不合法！\n");
		return 0;
	}
	else
	{
		*x = L->list[i];    // 保存要删的元素

		// 从前向后依次前移
		for (int j = i+1; j <= L->size-1; j++)
			L->list[j-1] = L->list[j];
		L->size--;
		return 1;
	}
}


// 取出数据
int ListGet(SeqList L, int i, DataType *x)
{
	if (i < 0 || i > L.size-1)
	{
		printf("参数 i 不合法！\n");
		return 0;
	}
	else
	{
		*x = L.list[i];   
		return 1;
	}
}


// 删除全部的x
int ListMoreDataDelete(SeqList *L, DataType x)
{
	int tag = 0;    // 初始删除标记置0
	for (int i = 0; i < L->size; i++)
	{
		if (x == L->list[i])    // 找到x
		{
			for (int j = i; j < L->size-1; j++)  // 依次前移
				L->list[j] = L->list[j+1];

			L->size--;   // 个数减一
			i--;         // 退回一个位置，保证两个相邻的x都能被删除
			tag = 1;
		}
	}
	return tag;
}
