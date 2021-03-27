// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/tower-of-hanoi-17/
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
   int T;
   cin>>T;
   while(T--)
   {
      int n;
      cin>>n;
      vector<pair<int,int>> vp;
      for(int i = 0;i<n;i++)
      {
         int x,y;
         cin>>x>>y;
         vp.push_back({x,y});
      }
      sort(all(vp));
      ll ans[n],answer = 0;
      for(int i = 0;i<n;i++)
      {
         ans[i] = vp[i].S;
         ll add = 0;
         for(int j = 0;j<i;j++)
         {
            if(vp[j].S<vp[i].S and vp[j].F != vp[i].F)
               add = max(add,ans[j]);
         }
         ans[i] += add;
         answer = max(answer,ans[i]);
      }
      cout<<answer<<"\n";
   }  
}
