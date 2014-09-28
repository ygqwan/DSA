#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node{
	int val;
	node *next;
};

node *build(){
	node *head = new node();
	head->next = NULL;
	head->val = 0;
	return head;
}
//头插法，head节点不保存数据,记录链表的长度
//返回链表的长度
int insert(node *head, int val){
	if(NULL == head){
		return 0;
	}
	node *newNode = new node();
	newNode->val = val;
	newNode->next = head->next;
	head->next = newNode;
	head->val += 1;
	return head->val;
}

//查找某个节点
node *search(node *head, int val){
	if(NULL == head){
		return NULL;
	}
	node *next = head->next;
	while(next != NULL){
		if(val == next->val){
			return next;
		}
		next = next->next;
	}
	return NULL;
}

int dele(node *head, int val){
	if(head == NULL){
		return -1;
	}
	//先查找到改节点
	node *sea = search(head, val);
	if(NULL == sea){
		return head->val;
	}
	//找到sea的前一个节点
	node *next = head;
	while(next != NULL){
		if(next->next == sea){
			break;
		}
		next = next->next;
	}
	next->next = sea->next;
        
	delete sea;
    head->val -= 1;
    return head->val;
}

//遍历
void tran(node *head){
	if(NULL == head){
		return;
	}
	node *next = head->next;
	while(NULL != next){
		cout << next->val << " ";
		next = next->next;
	}
	cout << endl;

}
node *head;

node *reve2(node *head){
	if(NULL == head || NULL == head->next || NULL == head->next->next){
		return head;
	}
	node *pre = NULL;
	node *now = head->next;
	node *next = now->next;

	while(now != NULL){
		now->next = pre;
		pre = now;
		now = next;
		if(next != NULL)
			next = next->next;
	}
	head->next = pre;
	return head;
}

int main(){
	head = build();
	insert(head, 1);
	insert(head, 2);
	insert(head, 3);
	insert(head, 4);
	insert(head, 5);
	dele(head, 5);
	insert(head, 6);
	insert(head, 7);
	insert(head, 8);
	tran(head);
	reve2(head);
	cout << endl;
	tran(head);
	return 0;
}
