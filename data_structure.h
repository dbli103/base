/*****************************************************/
					顺序链表的数据结构
/*****************************************************/

/*初始化空间分配大小*/
#define MAXSIZE 20 
#define ERROR 0
#define OK 1

typedef int ElemType; /*类型根据实际情况而定，这里选择 int*/

/*status 是函数结果的状态代码，如OK等*/
typedef int status;

/*顺序表结构*/
typedef struct 
{
	ElemType date[MAXSIZE]; /*数组，储存数据元素*/
	int lenght; /*线性表当前长度*/
}SqList;

/*线性表的单链表储存结构*/
typedef struct Node
{
	ElemType date;
	struct Node *next;
}Node;
typedef struct Node *LinkList; /*定义LinkList*/


/*顺序表结构函数*/

void InitSqList(SqList *L);
status SqListEmpty(SqList L);
void ClearSqList(SqList *L);
status GetSqElem(SqList L, i, ElemType *e);
status SqListInsert(SqList *L ,i, ElemType e);
status locateSqElem(SqList L, ElemType e);
ElemType SqListDelete(SqList *L, i, ElemType *e);
int SqListLength(SqList L);

void unionSqList(SqList *La, SqList Lb);


/*单链表结构函数*/

void InitSLLList(LinkList *L);
status SLLListEmpty(LinkList L);
status ClearSLLList(LinkList *L);
status GetSLLElem(LinkList L, i, ElemType *e);
status SLLListInsert(LinkList *L ,i, ElemType e);
status locateSLLElem(LinkList L, ElemType e);
status SLLListDelete(LinkList *L, i, ElemType *e);
int SLLListLength(LinkList L);
void CreateListHead(LinkList *L, int n);
void CreateListTail(LinkList *L, int n);


void unionSLLList(LinkList *La, SqList Lb);

