#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
const int M = 10004;
class Heap{
private:
	int n;	//元素个数
	int bucket[M];
	void heapify(int cur);
	
	int left(int i){
		return i << 1;
	}
	int right(int i){
		return (i << 1) + 1;
	}
	void swap(int i, int j){
		bucket[i] ^= bucket[j];
		bucket[j] ^= bucket[i];
		bucket[i] ^= bucket[j];
	}
	inline int count(){
		return n - 1;
	}
public:
	Heap():n(1){
		memset(bucket, 0, sizeof(bucket));
	}
	int top();
	void push(int val);
	int pop();
};

void Heap::heapify(int cur){
	if(cur > count()){
		return;
	}
	//有左儿子,无右儿子
	if(left(cur) <= count() && right(cur) > count()){
		if(bucket[cur] > bucket[left(cur)]){
			swap(cur, left(cur));
			heapify(left(cur));
		}
	}
	//无左儿子，有右儿子
	if(left(cur) > count() && right(cur) <= count()){
		if(bucket[cur] > bucket[right(cur)]){
			swap(cur, right(cur));
			heapify(right(cur));
		}
	}
	//有两个儿子
	if(left(cur) <= count() && right(cur) <= count()){
		int tmp_min_index = cur;
		tmp_min_index = bucket[left(cur)] > bucket[right(cur)] ? right(cur) : left(cur);
		tmp_min_index = bucket[tmp_min_index] < bucket[cur] ? tmp_min_index : cur;
		swap(tmp_min_index, cur);
		heapify(tmp_min_index);
	}
	//没有儿子
	if(left(cur) > count() && right(cur) > count()){
		return;
	}

}

//插入节点
void Heap::push(int val){
	bucket[n++] = val;
	int index = n - 1;
	while(index != 1 && bucket[index] < bucket[index >> 1]){
		swap(index, index >> 1);
		index >>= 1;
	}
}
//弹出堆首
int Heap::pop(){
	swap(1, n - 1);
	n -= 1;
	heapify(1);
}
//top
int Heap::top(){
	return bucket[1];
}



int main(){
	Heap *heap = new Heap();
	for(int i = 20; i >= 1; i--){
		heap->push(i);
	}
	for(int i = 20; i >= 1; i--){
		cout << heap->top() << endl;
		heap->pop();
	}
}
