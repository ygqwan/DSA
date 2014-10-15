/*
code by : ygqwan
date: 2014/10/15
实现大数的加法与减法
*/
#include <iostream>
#include <cstring>
using namespace std;



void add(const char *a, const char *b, char *c){
	int a_len = strlen(a), b_len = strlen(b);
	int e = 0, i = a_len - 1, j = b_len - 1, k = 0;
	while(i >= 0 && j >= 0){
		int tmp = a[i] - '0' + b[j] - '0' + e;
		c[k] = tmp % 10 + '0';
		e = tmp / 10;
		i--;
		j--;
		k++;
	}
	while(i >= 0){
		int tmp = a[i] - '0' + e;
		c[k++] = tmp % 10 + '0';
		e = tmp / 10;
		i--;
	}
	while(j >= 0){
		int tmp = b[j] - '0' + e;
		c[k++] = tmp % 10 + '0';
		e = tmp / 10;
		j--;
	}
	if(e){
		c[k++] = e + '0';
	}
	for(int i = 0; i < k / 2; i++){
		char tmp = c[i];
		c[i] = c[k - 1 - i];
		c[k - 1 - i] = tmp;
	}
	c[k] = '\0';
}


/*
 123
-182

*/

void mulit(const char *a, const char *b, char *c){
	int a_len = strlen(a), b_len = strlen(b);
	int un = 1;
	//判断符号
	if(a_len > b_len)
		un = 1;
	else if(a_len < b_len)
		un = 0;
	else{
		int i = 0;
		for(; i < a_len; i++){
			if(a[i] > b[i]){
				un = 1;
				break;
			}else if(a[i] < b[i]){
				un = 0;
				break;
			}
		}
		if(i == a_len){
			c[0] = '0';
			c[1] = '\0';
			return;
		}
	}
	if(un == 0){
		const char *tmp = a;
		a = b;
		b = tmp;
		a_len = strlen(a);
		b_len = strlen(b);
	}
	int e = 0, i = a_len - 1, j = b_len - 1, k = 0;
	while(i >= 0 && j >= 0){
		int tmp = a[i] - '0' - e - (b[j] - '0');
		if(tmp < 0){
			c[k++] = (tmp + 10) % 10 + '0';
			e = 1;
		}else{
			c[k++] = tmp % 10 + '0';
			e = 0;
		}
		i--;
		j--;
	}
	while(i >= 0){
		int tmp = a[i] - '0' - e;
		c[k++] = tmp % 10 + '0';
		i--;
	}
	//如果是负数
	if(un == 0)
	{
		//如果最后一位是0（最高位是0）
		if(c[k - 1] == '0'){
			c[k - 1] = '-';
			c[k] = '\0';
		}else{
			c[k++] = '-';
			c[k] = '\0';
		}
	}else{
		if(c[k - 1] == '0'){
			c[--k] = '\0';
		}else{
			c[k] = '\0';
		}
	}
	for(int i = 0; i < k / 2; i++){
		char tmp = c[i];
		c[i] = c[k - 1 - i];
		c[k - 1 - i] = tmp;
	}
}

int main() {
	char a[] = "10";
	char b[] = "777";
	char c[100];
	add(a, b, c);
	cout << c << endl;
	mulit(a, b, c);
	cout << c << endl;
	return 0;
}
