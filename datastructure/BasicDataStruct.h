/*
 * Author:zhaojie
 * create date:2021-07-10
 * copyright (c) Huawei technology Co.td
 */

#ifndef BASIC_DATA_STRUCT_H
#define BASIC_DATA_STRUCT_H

#include<stdio.h>
#include<stdlib.h>

#define CHAR char
#define UCHAR unsigned char
#define SHORT short
#define USHORT unsigned short
#define int32 int
#define int64 long long
#define uint32 unsigned int
#define uint64 unsigned long long

typedef enum {false, true} bool;

#endif



/*
 * 单向链表节点定义
 */
typedef struct Node{
	int32 data;
	struct Node* next;
}Node, *pNode, *List;


/*
 * 二叉树节点定义
 */
typedef struct BNode{
	int32 data;
	struct BNode* lc;
	struct BNode* rc;
}BNode, *pBNode, *Btree;


/*
 * 建立链表，读入数字组成没有头结点的数字链表；
 * 输入：布尔值TRUE为指定链表长度，第二个参数生效；布尔值为FALSE，第二个参数不生效并且以-1为结束；
 * 返回：List型链表指针；如果长度为0则返回空；
 */
List createList(bool flag, uint32 length){
	//定义链表头和遍历器
	pNode head, pointer;
	//初始化
	pointer = head = NULL;
	if(flag){
		//以给定长度建立链表
		printf("Assigned Length Mode.\n");
		if(length < 1)
			return NULL;
		pointer = head = (Node*)malloc(sizeof(Node));
		pointer->next = NULL;
		for(uint32 i = 0; i < length-1; i++){
			scanf("%d", &pointer->data);
			pointer->next = (Node*)malloc(sizeof(Node));
			pointer = pointer->next;
			pointer->next = NULL;
		}
		scanf("%d", &pointer->data);
		return head;
	}else{
		//以-1为链表结尾动态创建链表
		printf("Unassigned Length Mode.\n");
		int32 val = 0;
		scanf("%d", &val);
		if(val == -1)
			return NULL;
		pointer = head = (Node*)malloc(sizeof(Node));
		pointer->data = val;
		pointer->next = NULL;
		scanf("%d", &val);
		while(val != -1){
			pointer->next = (Node*)malloc(sizeof(Node));
			pointer = pointer->next;
			pointer->data = val;
			pointer->next = NULL;
			scanf("%d", &val);
		}
		return head;
	}
}

/*
 * 打印链表
 */
void printList(List head){
    pNode pointer = head;
	if(pointer == NULL){
		printf("Empty List!\n");
		return;
	}
	int32 ListLen = 1;
    while(pointer->next){
        printf("%d   ->\t",pointer->data);
        pointer = pointer->next;
		ListLen++;
    }
    printf("%d\t",pointer->data);
    printf("\n");
	printf("The Length of List is %d.\n",ListLen);
}

/*
 * 计算表长
 */
int32 lenList(List head){
	pNode pointer = head;
	//如果传来空链表，返回0
	if(pointer == NULL)	return 0;
	//如果非空，则从1开始计数
	int32 ret = 1;
	while(pointer->next){
		ret++;
		pointer = pointer->next;
	}
	return ret;
}

/*
 * 释放链表，并将头指针置空
 */
bool freeList(List *head){
	pNode pointer_s = *head;
	if(pointer_s == NULL) return true;
	pNode pointer_t = pointer_s->next;
	while(pointer_t){
		free(pointer_s);
		pointer_s = pointer_t;
		pointer_t = pointer_t->next;
	}
	free(pointer_t);
	*head = NULL;
	return true;
}

/*
 * 链表插入操作，输入n，头结点为1，在第n个元素后插入新值。
 * 输入0则插在链表头，输入-1则插入链表尾。
 * 如果插入成功返回true，插入失败返回false。
 */
bool insertList(List *head, int32 insert_value, int32 pos){
	int32 p = pos;
	//链表判空
	if(head == NULL){
		return false;
		printf("Info:%s: %d: Empty List!\n", __FUNCTION__, __LINE__);
	}
	//判断位置是否溢出
	if(pos > lenList(*head)){
		return false;
		printf("Info:%s: %d: Out of Range!\n", __FUNCTION__, __LINE__);
	}
	//判断是否是0，如果是0则要改变输入指针值
	if(pos == 0){
		pNode new_node = (pNode)malloc(sizeof(Node));
		new_node->data = insert_value;
		new_node->next = *head;
		*head = new_node;
		return true;
	}
	//判断位置是否是-1
	if(pos == -1){
		p = lenList(*head);
	}
	USHORT i = 1;
	pNode pointer = *head;
	pNode new_node = (pNode)malloc(sizeof(Node));
	new_node->next = NULL;
	//遍历到要目标位置前面的结点
	while(i < p){
		pointer = pointer->next;
		i++;
	}
	new_node->data = insert_value;
	new_node->next = pointer->next;
	pointer->next = new_node;
	return true;
}

/*
 * 链表删除函数
 * 输入需要删除的数值，删除链表中所有该值
 * 返回删除节点个数
 */
 int deleteNodeByValue(List *head, int32 target){
	pNode pointer = *head;
	pNode linker = *head;
	uint32 ret = 0;
	//处理首节点
	if(pointer->data == target){
		//head = *head->next;
	}
	//这里其实在倒数第二个节点的时候就已经能判断最后一个节点是否是目标值并且将其删除了，所以不用处理最后一个节点
	while(pointer->next){
		if(pointer->next->data == target){
			//如果下一个节点是要删除的，则把下一个节点的指针（下下个节点的地址）存起来
			linker = pointer->next->next;
			//释放下一个节点
			free(pointer->next);
			//将下下个节点的地址存到本节点下
			pointer->next = linker;
			ret++;
		}else{
			//如果没有匹配到，则指针往后走
			pointer = pointer->next;
		}
	}
	return ret;
 }
