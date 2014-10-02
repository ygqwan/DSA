/*
带有最小值的栈
思路：
用两个栈模拟，栈一时主栈，栈二是辅助栈
入栈：数据val直接入栈一, 如果val 《= 栈2， 入栈2(当栈2为空时，栈2也是无条件入栈)
出栈：直接从栈一出栈为val，如果val等于栈2的top， 那么栈2也出栈
最小值：直接栈2的top


*/
#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class StackWithMin{
private:
	stack<int> s1, s2;
public:
	int top(){
		if(!s1.empty())
			return s1.top();
		else
			return -1;
	}
	void pop(){
		int top = s1.top();
		s1.pop();
		if(top == s2.top())
			s2.pop();
	}
	void push(int val){
		s1.push(val);
		if(s2.empty())
			s2.push(val);
		else{	
			int top2 = s2.top();
			if(val <= top2)
				s2.push(val);
		}
	}
	int min(){
		if(!s2.empty())
			return s2.top();
		else
			return -1;
	}
};


int main(){

	StackWithMin s = StackWithMin();
	s.push(1);
	s.push(2);s.push(3);
	s.push(-99);
	s.push(-100);
	s.push(-99);
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;

	return 0;
}
