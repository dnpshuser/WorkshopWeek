//https://www.spoj.com/problems/INVCNT/
#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
#define rep(i,st,n) for(int i=st;i<n;i++)
typedef long long ll;
#define pri(n) printf("%d\n",n)
#define lpri(n) printf("%lld\n",n)
#define var(n) int n; scn(n)
#define all(x) (x).begin(),(x).end()
#define pb(n) push_back(n)
#define pii  pair<int,int>
#define F first
#define S second
const int N=2e5 + 5;
const ll M = 998244353;



ll tree[4*N];
int a[N];

void update(int node,int st,int ed,int pos,int val)
{
	if(st==ed)
	{
		tree[node] += val;
		return ;
	}
	int mid = (st + ed)/2;
	if(pos<=mid)
		update(2*node,st,mid,pos,val);
	else update(2*node + 1,mid+1,ed,pos,val);

	tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node,int st,int ed,int l,int r)
{
	if(l<=st and ed<=r)
		return tree[node];
	if(r<st or ed<l)
		return 0;
	int mid = (st + ed)/2;
	int ans = query(2*node,st,mid,l,r);
	ans += query(2*node + 1,mid+1,ed,l,r);

	return ans;
}

void solve()
{
	int n;
	cin>>n;
	

	vector<pair<int,int>> vp;
	for(int i = 1;i<=n;i++) 
	{
		int x;
		cin>>x;
		vp.push_back({x,i});
	}

	sort(all(vp));
	
	int val = 1;
	for(auto it : vp)
	{
		int pos = it.S;
		a[pos] = val++;
	}

	ll ans = 0;
	for(int i = 1;i<=n;i++)
	{
		update(1,1,n,a[i],1);
		int res = query(1,1,n,a[i]+1,n);
		ans+=res;
	}
	cout<<ans<<"\n";

	for(int i = 0;i<=4*n;i++)
	{
		if(i<=n)
			a[i] = 0;
		tree[i] = 0;
	}

}

int main()
{
	ios;
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
}