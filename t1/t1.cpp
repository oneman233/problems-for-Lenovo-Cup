#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;
const int MAX=120;

int t,a,b,w,h,tot=0,hh;
vector<vector<int>> ans;
vector<int> tmp;
ll mp[MAX][MAX],ini[MAX][MAX],sum[MAX][MAX];

bool ok(vector<int> a,vector<int> b) {
	if(a[0]==b[0]) return 0;
	int sa=a[0],sb=b[0],i=0,j=0;
	while(i!=a.size()-1||j!=b.size()-1) {
		while(sa<sb&&i<a.size()) sa+=a[++i];
		if(sa==sb&&sa!=w) return 0;
		while(sb<sa&&j<b.size()) sb+=b[++j];
		if(sa==sb&&sb!=w) return 0;
	}
	return 1;
}

void gao2() {
	for(int i=0;i<tot;++i)
		for(int j=i+1;j<tot;++j)
			if(ok(ans[i],ans[j]))
				mp[i][j]=mp[j][i]=1ll;
}

void gao(int now) {
	if(now==0) {
		ans.push_back(tmp);
		return;
	}
	if(now<min(a,b)) return;
	if(now>=a) {
		tmp.push_back(a);
		gao(now-a);
		tmp.pop_back();
	}
	if(now>=b) {
		tmp.push_back(b);
		gao(now-b);
		tmp.pop_back();
	}
}

void mul(ll a[MAX][MAX],ll b[MAX][MAX]) {
	memset(sum,0,sizeof(sum));
	for(int i=0;i<tot;++i)
		for(int j=0;j<tot;++j)
			for(int k=0;k<tot;++k)
				sum[i][j]=(sum[i][j]+a[i][k]*b[k][j]%mod)%mod;
	for(int i=0;i<tot;++i)
		for(int j=0;j<tot;++j)
			a[i][j]=sum[i][j];
}

void qpow() {
	--h;
	while(h) {
		if(h&1) mul(ini,mp);
		mul(mp,mp);
		h>>=1;
	}
}

signed main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d%d",&a,&b,&w,&h);
		hh=h;
		ans.clear();
		gao(w);
		tot=ans.size();
		assert(tot<MAX);
		if(tot==0) {
			puts("0");
			continue;
		}
		memset(mp,0,sizeof(mp));
		gao2();
		memset(ini,0,sizeof(ini));
		for(int i=0;i<tot;++i)
			ini[i][i]=1ll;
		qpow();
		ll out=0ll;
		for(int i=0;i<tot;++i)
			for(int j=0;j<tot;++j)
				out=(out+ini[i][j])%mod;
		if((w==a||w==b)&&hh!=1) ++out;
		printf("%lld\n",out);
	}
	return 0;
}

