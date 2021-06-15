#include <bits/stdc++.h>
using namespace std;

int _,n,m,h;
char mp[35][35][35];
int d[26],v[26],hav[26];
vector<int> e[26];
vector<char> ord;
priority_queue<int> q;

bool topo() {
	ord.clear();
	while(!q.empty()) q.pop();
	for(int i=0;i<26;++i) v[i]=0;
	for(int i=0;i<26;++i) if(hav[i]&&d[i]==0) q.push(i);
	if(q.empty()) return 0;
	int tot=0;
	while(!q.empty()) {
		int f=q.top();
		q.pop();
		++tot;
		v[f]=1;
		ord.push_back(f+'A');
		for(auto i:e[f]) {
			if(v[i])
				return 0;
			d[i]--;
			if(!d[i]) q.push(i);
		}
	}
	for(int i=0;i<26;++i) tot-=hav[i];
	if(tot!=0) return 0;
	return 1;
}

int main() {
	scanf("%d",&_);while(_--) {
		scanf("%d%d%d",&n,&m,&h);
		for(int i=0;i<26;++i) hav[i]=0;
		for(int i=1;i<=h;++i)
			for(int j=1;j<=n;++j) {
				scanf("%s",mp[i][j]+1);
				for(int k=1;k<=m;++k)
					if(isalpha(mp[i][j][k]))
						hav[mp[i][j][k]-'A']=1;
			}
		for(int i=0;i<26;++i) d[i]=0,e[i].clear();
		for(int i=h;i>=2;--i)
			for(int j=1;j<=n;++j)
				for(int k=1;k<=m;++k)
					if(mp[i][j][k]!=mp[i-1][j][k])
						e[mp[i][j][k]-'A'].push_back(mp[i-1][j][k]-'A'),
						d[mp[i-1][j][k]-'A']++;
		if(topo()) {
			for(auto i:ord) printf("%c",i);
			puts("");
		}
		else puts("-1");
	}
	return 0;
}
