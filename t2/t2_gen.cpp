#include <bits/stdc++.h>
using namespace std;

int n,m,h;
char ans[35][35][35];

int cnt=0;

bool ok(int l,int x,int y) {
	if(x<1||x>n||y<1||y>m||l<1||l>h) return 0;
	if(ans[l][x][y]!='$') return 0;
	return 1;
}

int dfs(int l,int x,int y,char c) {
	if(cnt==0) return 0;
	ans[l][x][y]=c;
	--cnt;
	int tmp=1;
	if(ok(l,x+1,y)) tmp+=dfs(l,x+1,y,c);
	if(ok(l,x-1,y)) tmp+=dfs(l,x-1,y,c);
	if(ok(l,x,y+1)) tmp+=dfs(l,x,y+1,c);
	if(ok(l,x,y-1)) tmp+=dfs(l,x,y-1,c);
	if(ok(l+1,x,y)) tmp+=dfs(l+1,x,y,c);
	return tmp;
}

void gao(int mode) {
	if(mode==0) {
		for(int k=1;k<=h;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					ans[k][i][j]=(char)(rand()%26+'A');
	}
	else if(mode==1) {
		int tot=n*m*h;
		char flg='A';
		for(int k=1;k<=h;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					if(ans[k][i][j]=='$') {
						cnt=rand()%tot+1;
						int act=dfs(k,i,j,flg);
						flg++;
						tot-=act;
						if(tot==0) return;
					}
	}
}

int main() {
	freopen("t2_9.txt","w",stdout);
	srand(time(0));
	int _=10;
	cout<<_<<endl;
	while(_--) {
		n=rand()%30+1,m=rand()%30+1,h=rand()%30+1;
		cout<<n<<' '<<m<<' '<<h<<endl;
		for(int k=1;k<=h;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
					ans[k][i][j]='$';
		gao(rand()%2);
		for(int k=h;k>=1;--k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j) {
					cout<<ans[k][i][j];
					if(j==m) cout<<endl;
				}
	}
	return 0;
}
