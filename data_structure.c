#include"date_structure.h"
#include<malloc.h>

/*****************************************************/
					顺序链表的数据结构
/*****************************************************/

/* 以下函数前提为L已存在，1<=i<=ListLength(L) */

/*获取链表L中第i个位置的值，并返回到e*/
status GetSqElem(SqList L, i, ElemType * e)
{
	if(i<0 || i>L.lenght)
		return ERROR
	*e = L.date[i-1];

	return OK;
}


/*在L中第i个位置之前插入新的元素e，L的长度+1*/
status SqListInsert(SqList * L, i, ElemType e)
{
	if(i<1 || i>L.lenght+1 || L.lenght == MAXSIZE) /*i=L.lenght+1时即i插入*/
		return ERROR			 		   					     /*到数组最后一个，大于此值则越界*/
	if(i<=L.lenght) /*插入位置不在表尾*/
	{
		for(k=L.lenght-1;k>=i-1;k--) /*lenght-1为数组下表最后一位*/
		{									 /*i-1为此时k插入的数组下表*/
			L->date[k+1] = L->date[k];
		}
	L->lenght++;
	L->date[i-1] = e;
	}
	
	return OK;
}

/*删除L第i个位置数据元素，并用e返回其值，L长度-1*/
ElemType SqListDelete(SqList * L, i, ElemType * e)
{
	int k;
	if(i<1 || i>L.lenght || L.lenght == 0)
		return ERROR
	*e = L->date[i-1];
	if(i<L->lenght)
	{
		for(k=i-1; k<=L.lenght-1; k++)
		{
			L->date[K-1] = L->date[k];
		}
	}
	L->lenght--;
	
	return OK;
}


/*****************************************************/
					单链表的数据结构
/*****************************************************/

/* 以下函数前提为L已存在，1<=i<=ListLength(L) */

/*用e返回L中第i个数据元素的值*/
status GetSLLElem(LinkList L, i, ElemType * e)
{
	int j = 1;	/*j为计数器*/
	LinkList p;	/*声明节点p*/
	p = L->next;		/*让p指向链表L的第一个节点*/
	while(p && j<i)	/*让p指向下一个节点*/
	{
		p = p->next;
		++j;
	}
	if(!p || j>i)	/*第i个元素不存在*/
	{
		return ERROR;
	}
	*e = p->date;

	return OK;
}

/*在L中第i个位置之前插入新的元素e，L的长度+1*/
/*插入需要插入节点前一个节点的消息*/
/*所以此函数p位置在j之前一个位置*/
status SLLListInsert(LinkList * L, i, ElemType e)
{
	LinkList p, s;
	int j = 1;
	p = *L;
	while(j<i && p)
	{
		p = p->next;
		++j;
	}
	if(!p || j>i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	if(NULL = s)
		return ERROR;
	s->date = e;
	s->next = p->next;
	p->next = s;
	
	return OK;
}

/*删除L的第i个数据元素，并用e返回其值，L的长度减一*/
/*删除需要插入节点前一个节点的消息*/
/*所以此函数p位置在j之前一个位置*/

status SLLListDelete(LinkList *L, i, ElemType * e)
{
	int j = 1;
	LinkList p, s;
	p = *L;
	while(P && i>j)
	{
		p = p->next;
		j++;

	}
	if(!(p->next) || j>i)
		return ERROR;
	s = p->next;
	p->next = s->next;
	*e = s->date;
	free(s);

	return OK;
}

/*随机产生n个元素的值，建立带表头的单链表L（头插法）*/
void CreateListHead(LinkList *L, int n)
{
	int j;
	LinkList p;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for(j =0; j<n; j++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->date = rand()%100+1;
		p->next = (*L)->next;
		(*L)->next = p;
	}																		

}

/*随机产生n个元素的值，建立带表头的单链表L（尾插法）*/
void CreateListTail(LinkList *L, int n)
{
	int j;
	LinkList p, r;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(j = 0; j<n; j++)
	{
		p = (Node *)malloc(sizeof(Node));
		p->date = rand()%100+1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

/*将L置为空表*/
status ClearSLLList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL；

	return OK;
}























































