#include"BasicDataStruct.h"

/*
 * The comment from the HUAWEI matebook X pro 2021
<<<<<<< HEAD
 * DESK add comment
=======
 *
 * 网页端新增注释 
>>>>>>> 276213b6a991f8204a972393e53505bebf22cf43
 */
 
int main(){
/*
    List L1 = NULL;
    printf("Please Input List:");
    L1 = createList(true, 3);
    printList(L1);
	printf("%d\n", lenList(L1));
	printf("The Header is Navi to %p, The Header's Addr is %p", L1, &L1);
	printf("\n------ Free Operation ------\n");
	freeList(&L1);
	printf("The Header is Navi to %p, The Header's Addr is %p", L1, &L1);
*/
	List L2 = NULL;
	L2 = createList(false, 0);
	printList(L2);
	printf("%d\n", lenList(L2));
	insertList(&L2, 22222, 0);
	printList(L2);

    return 0;

}
