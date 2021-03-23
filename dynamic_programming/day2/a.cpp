// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/jump-k-forward-250d464b/
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
const int N=3e5 + 5;
const ll M = 1e9+7;

int main()
{
   ios;
   int n,k;
   cin>>n>>k;

   ll ans[n+1],pre[n+1];
   memset(ans,0,sizeof(ans));
   ans[0] = pre[0] = 1;

   for(int i = 1;i<n;i++)
   {
      ans[i] = 0;
      
      ll add = pre[i-1];
      if(i-k>0)
         add = (add - pre[i-k-1] + M)%M;

      ans[i] = (ans[i] + add)%M;
      pre[i] = (ans[i] + pre[i-1])%M;

   }
   cout<<ans[n-1]<<"\n";
   // done

}