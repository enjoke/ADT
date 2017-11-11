#include "sysconf.h"
#include "SingleList.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

SLIST_HEAD(SList, MyList) head;
struct MyList {
	int data;
	SLIST_ENTRY(MyList) entry;
}l1, l2, *lp;

LIST_HEAD(List, xList) xhead;
typedef struct xList {
	int data;
	LIST_ENTRY(xList) entry;
}list;

int main(int argc, char **argv)
{

	LIST_INIT(&xhead);
	l1.data = 1;
	l2.data = 2;

	SLIST_INSERT_HEAD(&head, &l1, entry);
	SLIST_INSERT_AFTER(&l1, &l2, entry);

	SLIST_FOREACH(lp, &head, entry) {
		printf("data = %d\n", lp->data);
	}


	system("PAUSE");
	return OK;
}