// https://atcoder.jp/contests/dp/tasks/dp_m

#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0)
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
typedef long long ll;
#define pri(n) printf("%d\n",n)
#define lpri(n) printf("%lld\n",n);
#define rep(i,st,ed) for(int i=st;i<ed;i++)
#define var(n) int n; scn(n)
#define F first
#define S second 
#define pb push_back
const int N=1e5+5;
const ll M=1e9+7;
const ll inf=1e18;

ll dp[101][N];

int main()
{
	var(n);var(k);
	rep(i,0,n)
	{
		var(x);
		if(i)
		{
			for(int j=0;j<N;j++)
			{
				ll sum = dp[i-1][j];
				if(j>x)
					sum = (sum - dp[i-1][j-x-1] + M)%M;
				dp[i][j] = sum;
			}
		}
		else
		{
			for(int j=0;j<=x;j++)
				dp[i][j]=1;
		}
		if(i<n-1)
		{
			for(int j=1;j<N;j++)
			{
				dp[i][j]+=dp[i][j-1];
				dp[i][j]%=M;
			}
		}
	}
	lpri(dp[n-1][k]);

}