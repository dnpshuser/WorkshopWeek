// link: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/search-engine/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,j,n)    for(ll i=j;i<n;i++)
#define tc           ll t1; cin>>t1; while(t1--)
#define inp          ll n; cin>>n; ll a[n]; fr(i,0,n) cin>>a[i];
#define inp1         ll n1; cin>>n1; ll a[n1]; fr(i,0,n1) cin>>a[i];
#define vec          vector<ll>
#define pb           push_back
#define pii          pair<ll,ll>
#define mp           make_pair
#define F            first
#define S            second
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define srt(v)       sort(v.begin(),v.end())
#define srte(v)      sort(v.rbegin(),v.rend())
#define maxx         1000005
#define lb(v,n)      lower_bound(v.begin(),v.end(),n)-v.begin()
#define ub(v,n)      upper_bound(v.begin(),v.end(),n)-v.begin()
#define inf          LONG_MAX
#define zer          LONG_MIN
const long           mod=pow(10,9)+7;

struct BSTnode {
  ll data;
  BSTnode *left,*right;

  BSTnode(ll val){
    data=val;
    left=NULL;
    right=NULL;
  }

  // BSTnode(){

  // }

};
// node* constructTree(node *root,ll *a,ll ind)
// {
//     if(ind>=n || a[ind]==-1 || !root) {nullCnt++; return NULL;}

//     root->data = a[ind];

//     int temp = minusOneCnt[ind];

//     root->left = constructTree(new node(),a,2*ind+1-2*temp);
//     root->right = constructTree(new node(),a,2*ind+2-2*temp);

//     return root;
// }
BSTnode* insertInBST(BSTnode *root,ll val)
{
  if(!root) {
    root = new BSTnode(val);
    return root;
  }
  if(val == root->data) return root;
  else if( root->data > val ) root->left = insertInBST(root->left,val);
  else root->right = insertInBST(root->right,val);
  return root;
}

void traverse(BSTnode *root)
{
  if(!root) return;
  traverse(root->left);
  cout<< root->data <<" ";
  traverse(root->right);
}

struct trie
{
  // type data;
  ll mx_wt;
  trie* a[26];
  trie(){
    mx_wt = 0;
    for(int i=0;i<26;i++)
      a[i]=NULL;
  }

};

// building of trie
void insertInTrie(trie *root,string s,ll wt)
{
  trie *pCrawl = root;

  for(int i=0;i<s.size();i++)
  {
    int ind = s[i] - 'a'; 
    if(!pCrawl->a[ind]){
      pCrawl->a[ind] = new trie();
    }
    pCrawl = pCrawl->a[ind];
    pCrawl->mx_wt = max(pCrawl->mx_wt,wt);
  }

}
// updation => deletion
// query
ll queryInTrie(trie *root,string s)
{
  ll ans=0;
  trie *pCrawl = root;

  for(int i=0;i<s.size();i++)
  {
    int ind = s[i] - 'a'; 
    if(!pCrawl->a[ind]){
      return -1;
    }
    pCrawl = pCrawl->a[ind];
    ans = pCrawl->mx_wt;
  }
  return ans;
}


// q = 1000000
// n = 10000
void solve()
{
  
  ll n,q;
  cin>>n>>q;

  string s;

  trie *dict = new trie(); // dict or dic

  fr(i,0,n){
    ll wt;
    cin>>s>>wt;
    insertInTrie(dict,s,wt);
  }

  while(q--) {
    cin>>s;

    cout<<queryInTrie(dict,s)<<endl;
  }

}

int main() 
{

    #ifndef ONLINE_JUDGE
    freopen("in2.txt" , "r" , stdin);
    freopen("op2.txt" , "w" , stdout);
    #endif

    // tc
    solve();



    return 0; 
}


// hackerearth 10
// hackerrank 9
// hack