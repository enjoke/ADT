#pragma once
/*
------------------------------------------------------------------------------------------------------
|存储类别		 |顺序表							            |单链表                                        |
|存储分配方式	 |用一段连续的存储单元依次存储线性表的数据元素	    |采用链式存储结构，用一组任意的存储单元存放线性表的元素|
|时间性能	     |查找O（1）、插入和删除O（n）	                |查找O（n）、插入和删除O（1）					  |
|空间性能	     |需要预分配存储空间，分大了浪费，小了容易发生上溢	|不需要分配存储空间，只要有就可以分配，元素个数不受限制|
------------------------------------------------------------------------------------------------------
*/


/*----------------------------------------------------------------------------------------------------
	从libevent 抄出来的通用单链表代码
------------------------------------------------------------------------------------------------------*/
/*
* Singly-linked List definitions.
*/
#define SLIST_HEAD(name, type)							\
struct name {											\
	struct type *slh_first;	/* first element */			\
}

#define	SLIST_HEAD_INITIALIZER(head)					\
	{ NULL }


#define SLIST_ENTRY(type)								\
struct {												\
	struct type *sle_next;	/* next element */			\
}


/*
* Singly-linked List access methods.
*/
#define	SLIST_FIRST(head)		((head)->slh_first)
#define	SLIST_END(head)			NULL
#define	SLIST_EMPTY(head)		(SLIST_FIRST(head) == SLIST_END(head))
#define	SLIST_NEXT(elm, field)	((elm)->field.sle_next)

#define	SLIST_FOREACH(var, head, field)					\
	for((var) = SLIST_FIRST(head);						\
	    (var) != SLIST_END(head);						\
	    (var) = SLIST_NEXT(var, field))

/*
* Singly-linked List functions.
*/
#define	SLIST_INIT(head) {								\
	SLIST_FIRST(head) = SLIST_END(head);				\
}

#define	SLIST_INSERT_AFTER(slistelm, elm, field) do {	\
	(elm)->field.sle_next = (slistelm)->field.sle_next;	\
	(slistelm)->field.sle_next = (elm);					\
} while (0)

#define	SLIST_INSERT_HEAD(head, elm, field) do {		\
	(elm)->field.sle_next = (head)->slh_first;			\
	(head)->slh_first = (elm);							\
} while (0)

#define	SLIST_REMOVE_HEAD(head, field) do {				\
	(head)->slh_first = (head)->slh_first->field.sle_next;\
} while (0)

/*----------------------------------------------------------------------------------------------------
从libevent 抄出来的通用单链表代码
------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------------------
	普通单链表代码
------------------------------------------------------------------------------------------------------*/

typedef struct node {
	int data;
	struct node *next;
}Node, *nptr;

typedef struct xslist {
	nptr head;  /* 只要知道头部就可以了，除了插入（追加）跟删除节点每次操作都是从head开始*/
}xSlist;

