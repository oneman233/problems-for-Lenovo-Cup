#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("t1_7.txt","w",stdout);
	srand(time(0));
	int cnt=10;
	cout<<cnt<<endl;
//	int a=2,b=4;
	while(cnt--) {
		int a=rand()%9+2;
		int b=rand()%9+2;
		while(a==b) b=rand()%9+2;
		int w=rand()%19+2;
		int h=1000000000-rand();
		cout<<a<<' '<<b<<' '<<w<<' '<<h<<endl;
	}
	return 0;
}
