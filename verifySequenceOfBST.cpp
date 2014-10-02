/*
给定bst的后续遍历的序列，判定是否是合法的序列，也就是说是否存在这么一颗二叉树，有该后续遍历序列
思路：
1.序列的最后一个值一定是根节点
2.那么从序列第一个值开始找到一段连续小于根节点的值，这段是左子树
3. 相似的办法找右子树（如果在右子树段里面存在小于根节点的值，那么就非法）
4. 如果子树有两个及其以上的节点，那么递归左右子树（重复上面3步）
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

bool verifySequenceOfBST(int seq[], int len){
	if(seq == NULL || len <= 0)
		return false;
	//根节点
	int root = seq[len - 1];

	//寻找根节点的左子树
	int i = 0;
	//len - 1 是排除了根节点
	for(; i < len - 1; i++){
		if(seq[i] > root){
			break;
		}
	}
	//寻找根节点的右子树, 主要是判断是否合法
	int j = i;
	for(; j < len - 1; j++){
		if(seq[j] < root)
			return false;
	}
	//递归判断左右子树是否合法
	//假如是合法的
	bool left = true;
	//至少有两个节点，千万注意这里是至少两个节点，也就是i > 0 ,如果i是等于0那么就是一个节点，右子树也一样是两个
	if(i > 0)
		left = verifySequenceOfBST(seq, i);
	bool right = true;
	if(j - i > 0){
		right = verifySequenceOfBST(seq + i, j - i);
	}
	return left && right;
}


int main(){
	int seq[] = {5, 7, 6, 9, 11, 10, 8};
	int seq2[] = {7, 4, 6, 5};
	cout << verifySequenceOfBST(seq, 7) << endl;
}
