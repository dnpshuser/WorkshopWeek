// link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
typedef long long ll;
struct trie
{
  trie* a[2];
  trie(){
    for(int i=0;i<2;i++)
      a[i]=NULL;
  }

};
void insert(trie* root,ll n)
{
  trie* pCrawl = root;
  for (int i = 30; i >=0 ; i--)
  {
    if( ! pCrawl->a[n>>i & 1] ) pCrawl->a[n>>i & 1] = new trie();
    pCrawl = pCrawl->a[n>>i & 1]; 
  }
}

ll query(trie* root, ll n)
{
  trie* pCrawl = root;
  ll ans=0;
  for (int i = 30; i >=0 ; i--)
  {
    if(  pCrawl->a[ !(n>>i & 1) ] ) {

      ans += pow(2,i);
      pCrawl = pCrawl->a[ !(n>>i & 1) ];

    }
    else{
      pCrawl = pCrawl->a[ (n>>i & 1) ];
    }
  }
  return ans;
}
class Solution {
public:
    int findMaximumXOR(vector<int>& v) {

  trie *dict = new trie();

  for(ll i:v) {
    insert(dict,i);
  }

  ll ans = 0;

  for(auto i:v)
  {
    ans = max(ans,query(dict,i));
  }

  return (int)ans;
}   
    
};