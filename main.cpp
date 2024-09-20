#include<iostream>
#include<vector>

#define T_NUM 1
#define T_ADD 2
#define T_SUB 3

using namespace std;

struct s{
	unsigned int type;
	int value;
};
struct tr{
	int fa;
	vector<int> ch;
	s a;
};
tr t[105];
void print1(s a){
	if(a.type==T_ADD)printf("+");
	if(a.type==T_SUB)printf("-");
	if(a.type==T_NUM)printf("%d",a.value);
}
void print(int x){
	if(t[x].a.type==T_NUM){
		print1(t[x].a);
		return;
	}
	for(int i=0;i<t[x].ch.size();i++){
		print(t[x].ch[i]);
		if(i==t[x].ch.size()-1)break;
		print1(t[x].a);
	}
}
void add(int x,int a){
	t[x].ch.push_back(a);
}
void set(int x,int a,int b){
	t[x].a.type = a;
	t[x].a.value = b;
}

signed main(){
	printf("Hello, world!");	
	add(1,2);
	add(1,3);
	set(1,T_ADD,0);
	set(2,T_NUM,1);
	set(3,T_NUM,2);
	print(1);
	return 0;
}
