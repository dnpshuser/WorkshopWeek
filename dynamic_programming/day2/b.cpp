// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1#

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
const ll M = 1e9+7;


const int N=1e3 + 5;
int a[N],dp[N][N],n,pre[N];

int rec(int l,int r)
{
   if(l==r)
      return a[l];

   int &ret = dp[l][r];

   if(ret != -1)
      return ret;
   ret = 0;

   // choose a[l]
   {
      int other = rec(l+1,r);
      int me = pre[r] - pre[l];
      me -= other;

      me += a[l];
      ret = max(ret,me);
   }

   // choose a[r]
   {
      int other = rec(l,r-1);
      int me = pre[r-1];
      if(l)
         me -= pre[l-1];
      me += a[r];
      me -= other;
      ret = max(ret,me);
   }

   return ret;


}

int maximumAmount(int arr[],int len)
{
   n = len;
   for(int i = 0;i<n;i++)
   {
      a[i] = arr[i];
      pre[i] = a[i];
      if(i)
         pre[i] += pre[i-1];
   }
   memset(dp,-1,sizeof(dp));

   int ans = rec(0,n-1);
   return ans;
}
int main()
{
   ios;
   int T;
   cin>>T;
   while(T--)
   {
      int len;
      cin>>len;
      int arr[len];
      for(int i = 0;i<len;i++)
         cin>>arr[i];

      int ans = maximulAmount(arr,len);
      cout<<ans<<"\n";
   }
}