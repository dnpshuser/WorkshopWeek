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


int tree[4*N];
int a[N];

void build(int node,int st,int ed)
{
   if(st==ed)
   {
      tree[node] = a[st];
      return ;
   }
   int mid = (st + ed)/2;
   build(2*node,st,mid);
   build(2*node+1,mid+1,ed);

   tree[node] = max(tree[2*node],tree[2*node + 1]);
}

void update(int node,int st,int ed,int pos,int val)
{
   if(st==ed)
   {
      tree[node] = val;
      return ;
   }
   int mid = (st + ed)/2;
   if(pos<=mid)
      update(2*node,st,mid,pos,val);
   else
      update(2*node + 1,mid+1,ed,pos,val);

   tree[node] = max(tree[2*node],tree[2*node + 1]);
}

int query(int node,int st,int ed,int l,int r)
{

   if(l<=st and ed<=r) // complete inclusion
      return tree[node]; 
   if(r<st or ed<l)     // complete exclusion
      return 0;

   // partial overlap

   int mid= (st + ed)/2;

   int ans1 = query(2*node,st,mid,l,r);

   int ans2 =  query(2*node+1,mid+1,ed,l,r);

   return max(ans1,ans2);

}



int main()
{
	ios;
   int n,q;
   cin>>n>>q;
   for(int i = 1;i<=n;i++)
      cin>>a[i];

   build(1,1,n);

   
   while(q--)
   {
      char type;
      int ans;
      cin>>type;
      if(type=='q') 
      {
         int l,r;
         cin>>l>>r;
         ans = query(1,1,n,l,r);
         cout<<ans<<"\n";
      }
      else
      {
         int pos,val;
         cin>>pos>>val;
         update(1,1,n,pos,val);
      }
   }
}