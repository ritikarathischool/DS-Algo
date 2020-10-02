/*
  KUNAL ANAND
  MNNIT ALLAHABAD
*/  
 
//Manacher's algorithm to find longest palindromic substring in O(n)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define debug1(x) cout << # x << " " << x << endl;
#define debug2(x,y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define debug3(x,y,z) cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z << endl;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
typedef long long int ll;
const ll INF=1e7;
const ll mod=1e9+7;
 
ll power(ll x,ll y)
{
    if(y==0)
        return 1;
    ll a=power(x,y/2);
    a=(a*a)%mod;
    if(y%2)
        a=(a*x%mod)%mod;
    return a;
}
 
ll num=0;
ll manacher(string s)
{
    ll i,j,k;
    ll n=s.length();
 
    ll dp[n];
    memset(dp,0,sizeof(dp));
 
    ll l=0,r=0;
    ll center=0;
    ll cnt=0;
    i=0;
  //  cout << s << " " << n << endl;
    while(i<n)
    {
        l=i-1;
        r=i+1;
        cnt=1;
 
        while(l>=0&&r<n&&s[l]==s[r])
        {
            l--;
            r++;
            cnt+=2;
        }
        dp[i]=cnt;
        if(cnt>1)
        {
            center=i;
            l++;
            r--;
            i++;
            break;
        }
        i++;
    }
   // debug3(center,l,r);
    while(i<n)
    {
        ll mirror=center-(i-center);
 
        if(i>r||mirror-(dp[mirror]/2)>=l )
        {
            if(i>r||i+(dp[mirror]/2)>=r)
            {
                if(i<=r)
                {    
                    l=i-(dp[mirror]/2)-1;
                    r=i+(dp[mirror]/2)+1;
                    cnt=dp[mirror];
                }
                else
                {
                   // cout << "okk" << i << endl;
                    l=i-1;
                    r=i+1;
                    cnt=1;
                }    
 
                while(l>=0&&r<n&&s[l]==s[r])
                {
                    l--;
                    r++;
                    cnt+=2;
                }
                dp[i]=cnt;
 
                center=i;
                l++;
                r--;
            }
            else
            {
                dp[i]=dp[mirror];
            }
        }
        else
        {
            dp[i]=2*(mirror-l)+1;
        }
        if(r==n-1)
            break;
        i++;
    }
    ll ans=0;
    /*for(i=0;i<n;i++)
        cout << dp[i] << " ";
    cout << endl;*/
    for(i=0;i<n;i++)
        ans=max(ans,dp[i]);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,i;
    cin >> n;
    //cout << "ok" << endl;
    string s;
    cin >> s;
   // cout << "ok" << endl;
    //cout << s << endl;
    n=s.length();
    string str;
    str.push_back('#');                 // to get maximum even palindrome substring insert an alphabet alternately which is not present  
    i=0;
    while(i<n)
    {
        str.push_back(s[i]);
        str.push_back('#');
        i++;
    }
   // cout << str << endl;
    ll ans=manacher(str)/2;
    ans=max(ans,manacher(s));
    cout << ans << endl;
    return 0;
}     