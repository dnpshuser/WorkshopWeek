// https://codeforces.com/contest/1398/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0)
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
typedef long long ll;
#define pri(n) printf("%d\n",n)
#define lpri(n) printf("%lld\n",n)
#define rep(i,st,ed) for(int i=st;i<ed;i++)
#define var(n) int n; scn(n)
#define F first
#define S second 
#define pb(n) push_back(n)
#define pii pair<int,int> 
#define all(x) (x).begin(),(x).end()
#define vi vector<int>
const int N=203;
const ll M = 1e9+7;
const ll inf=1e18+5;

int r,g,b;
vector<int> red,green,blue;
ll dp[N][N][N];

ll rec(int posr,int posg,int posb)
{
	int ct = (posr == r) + (posg == g) + (posb == b);
	if(ct > 1)
	{
		return 0;
	}
	ll &res = dp[posr][posg][posb];
	if(res != -1)
		return res;
	res = 0;
	if(posr == r)
	{
		res =  ( 1ll*green[posg]*blue[posb] + rec(posr,posg+1,posb+1));
	}
	else if(posg == g)
	{
		res = (1ll*red[posr]*blue[posb] + rec(posr+1,posg,posb+1));
	}
	else if(posb == b)
	{
		res = (1ll*red[posr]*green[posg] + rec(posr+1,posg+1,posb));
	}
	else
	{
		//red green

		ll rg = (1ll*red[posr]*green[posg] + rec(posr+1,posg+1,posb)); 


		// red blue

		ll rb = (1ll*red[posr]*blue[posb] + rec(posr+1,posg,posb+1));

		// green blue
		ll gb = (1ll*green[posg]*blue[posb] + rec(posr,posg+1,posb+1));
		
		res = max({rg,rb,gb});
	}
	return res;
}
int main()
{
	scn(r);
	scn(g);
	scn(b);
	red.resize(r);
	green.resize(g);
	blue.resize(b);
	for(int i = 0;i<r;i++)
		scn(red[i]);
	for(int i = 0;i<g;i++)
		scn(green[i]);
	for(int i = 0;i<b;i++)
		scn(blue[i]);
	sort(all(red),greater<int>());
	sort(all(green),greater<int>());
	sort(all(blue),greater<int>());

	memset(dp,-1,sizeof(dp));

	ll ans = rec(0,0,0);
	lpri(ans);
}