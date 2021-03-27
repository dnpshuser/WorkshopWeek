// https://atcoder.jp/contests/dp/tasks/dp_n
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
   int n;
   cin>>n;
   ll mat[n][n];
   ll a[n];
      
   for(int i = 0;i<n;i++)
   {
      for(int j = 0;j<n;j++)
      {
         mat[i][j] = 1e18;
      }
   }

   for(int i = 0;i<n;i++) 
   {
      cin>>a[i];
      if(i)
         a[i] += a[i-1];
      mat[i][i] = 0;
   }

   for(int len = 2;len<=n;len++)
   {
      for(int i = 0;i<n;i++)
      {
         int j = i + len - 1;
         if(j>=n)
            break;

         ll sum = a[j];
         if(i)
            sum-=a[i-1];

         for(int k = i;k<j;k++)
         {
            mat[i][j] = min(mat[i][j],mat[i][k] + mat[k+1][j] + sum);
         }
      }
   }
   
   cout<<mat[0][n-1]<<"\n";
   // done


}