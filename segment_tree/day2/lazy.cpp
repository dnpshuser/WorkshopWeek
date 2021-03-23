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
const int N=1e5 + 5;
const ll M = 1e9+7;

// https://www.spoj.com/problems/HORRIBLE/

ll tree[4*N],lazy[4*N];

void update(int node,int st,int ed,int l,int r,int val)
{
   if(lazy[node] != 0)
   {
      tree[node] += lazy[node]*(ed-st + 1);

      if(st != ed)
      {
         lazy[2*node] += lazy[node];
         lazy[2*node + 1] += lazy[node];
      }
      lazy[node] = 0;
   }
      
   if(l<=st and ed<=r)
   {
      tree[node] += val*(ed-st + 1);
      if(st != ed)
      {
         lazy[2*node] += val;
         lazy[2*node + 1] += val;
      }
      return ;
   }
   if(r<st or ed<l)
      return ;

   int mid = (st + ed)/2;

   update(2*node,st,mid,l,r,val);
   update(2*node + 1,mid+1,ed,l,r,val);

   tree[node] = tree[2*node]+tree[2*node + 1];
}

ll query(int node,int st,int ed,int l,int r)
{

   if(lazy[node] != 0)
   {
      tree[node] += lazy[node]*(ed-st + 1);

      if(st != ed)
      {
         lazy[2*node] += lazy[node];
         lazy[2*node + 1] += lazy[node];
      }
      lazy[node] = 0;
   }

   if(l<=st and ed<=r) // complete inclusion
      return tree[node]; 
   if(r<st or ed<l)     // complete exclusion
      return 0;

   // partial overlap

   int mid= (st + ed)/2;

   ll ans1 = query(2*node,st,mid,l,r);
   ll ans2 =  query(2*node+1,mid+1,ed,l,r);

   ll ans = ans1 + ans2;

   return ans;
}



int main()
{
	ios;
   int T;
   cin>>T;
   while(T--)
   {

      int n,q;
      cin>>n>>q;
      
      while(q--)
      {
         int type,l,r,val;
         cin>>type>>l>>r;
         if(type==0) 
         {
            cin>>val;
            update(1,1,n,l,r,val);
         }
         else
         {
            ll ans = query(1,1,n,l,r);
            cout<<ans<<"\n";
         }
      }

      memset(tree,0,sizeof(tree));
      memset(lazy,0,sizeof(lazy));
   }
}