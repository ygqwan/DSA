#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
const int M = 10004;

class node{
public:
	int val;
	node *left;
	node *right;
	node(int val):val(val), left(NULL), right(NULL){}
	node():val(0), left(NULL), right(NULL){};
	~node(){delete left;delete right;}
};
class BTree{
public:
	node *root;
	BTree():root(NULL){}
	~BTree(){
		//todo 递归delete
	}
	void insert(node *& root, int val);
	void dele(node *& root, int val);
	node * searchs(node * root, int val);
	//树的深度
	int dep(node *root);

	//镜像二叉树
	void mirror(node *& root);
	void pre_tran(node *root);
	void las_tran(node *root);
	void mid_tran(node *root);
	void cen_tran(node *root);
	//树形结构的形状打印
	void tre_tran(node *root);
};

//插入节点
void BTree::insert(node *& root, int val){
	if(root == NULL){
		root = new node(val);
		return;
	}
	if(val <= root->val){
		insert(root->left, val);
	}else{
		insert(root->right, val);
	}
}
//深度
int BTree::dep(node *root){
	if(NULL == root){
		return 0;
	}
	return 1 + max(dep(root->left), dep(root->right));
}
//镜像二叉树
void BTree::mirror(node *& root){
	node *tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	if(root->left)
		mirror(root->left);
	if(root->right)
		mirror(root->right);
}

//先序遍历
void BTree::pre_tran(node *root){
	if(root){
		cout << root->val << " ";
	}
	if(root->left)
		pre_tran(root->left);
	if(root->right)
		pre_tran(root->right);
}
//中序
void BTree::mid_tran(node *root){
	if(root->left)
		mid_tran(root->left);
	cout << root->val << " ";
	if(root->right)
		mid_tran(root->right);
}
//后序
void BTree::las_tran(node *root){
	if(root->left)
		las_tran(root->left);
	if(root->right)
		las_tran(root->right);
	cout << root->val << " ";
}
//层次
void BTree::cen_tran(node *root){
	if(NULL == root)
		return;
	queue<node *> q;
	q.push(root);
	while(!q.empty()){
		node *front = q.front();
		q.pop();
		cout << front->val << " ";
		if(front->left != NULL)
			q.push(front->left);
		if(front->right != NULL)
			q.push(front->right);
	}
}
//树形
void BTree::tre_tran(node *root){
	if(NULL == root){
		return;
	}
	node *now[M];
	node *next[M];
	int remain = 1, newR = 0;
	now[0] = root;
	while(remain > 0){
		for(int i = 0; i < remain; i++){
			cout << now[i]->val << " ";
			if(now[i]->left){
				next[newR++] = now[i]->left;
			}
			if(now[i]->right){
				next[newR++] = now[i]->right;
			}
		}
		cout << endl;
		for(int i = 0; i < newR; i++){
			now[i] = next[i];
		}
		remain = newR;
		newR = 0;
	}
}



void BTree::dele(node *& root, int val){}

node * BTree::searchs(node *root, int val){
	if(NULL == root)
		return NULL;
	if(root->val == val)
		return root;
	if(val <= root->val)
		searchs(root->left, val);
	if(val > root->val)
		searchs(root->right, val);
}


int main(){
	BTree *bt = new BTree();
	for(int i = 0; i < 10; i++){
		bt->insert(bt->root, rand() % 100);
	}
	bt->mid_tran(bt->root);
	cout << endl;
	//bt->mirror(bt->root);
	bt->mid_tran(bt->root);
	cout << endl;
	bt->cen_tran(bt->root);
	cout << endl;
	bt->tre_tran(bt->root);
	cout << endl;
	cout << bt->dep(bt->root) << endl;
}

