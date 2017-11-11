#pragma once
/*
------------------------------------------------------------------------------------------------------
|�洢���		 |˳���							            |������                                        |
|�洢���䷽ʽ	 |��һ�������Ĵ洢��Ԫ���δ洢���Ա������Ԫ��	    |������ʽ�洢�ṹ����һ������Ĵ洢��Ԫ������Ա��Ԫ��|
|ʱ������	     |����O��1���������ɾ��O��n��	                |����O��n���������ɾ��O��1��					  |
|�ռ�����	     |��ҪԤ����洢�ռ䣬�ִ����˷ѣ�С�����׷�������	|����Ҫ����洢�ռ䣬ֻҪ�оͿ��Է��䣬Ԫ�ظ�����������|
------------------------------------------------------------------------------------------------------
*/


/*----------------------------------------------------------------------------------------------------
	��libevent ��������ͨ�õ��������
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
��libevent ��������ͨ�õ��������
------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------------------
	��ͨ���������
------------------------------------------------------------------------------------------------------*/

typedef struct node {
	int data;
	struct node *next;
}Node, *nptr;

typedef struct xslist {
	nptr head;  /* ֻҪ֪��ͷ���Ϳ����ˣ����˲��루׷�ӣ���ɾ���ڵ�ÿ�β������Ǵ�head��ʼ*/
}xSlist;

