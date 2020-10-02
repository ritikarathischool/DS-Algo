#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1e15
#define ll long long
#define ld long double
#define int ll
#define pii pair<int,int>
#define pli pair<long long,int>
#define pll pair<long long,long long>
#define MAX 300009
#define pb push_back
#define mp map<int,int>
#define F first
#define S second
#define popi __builtin_popcount
#define popll __builtin_popcountll
#define grp vector<int> graph[MAX];
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
//////////////////////TEMPLATE ENDS///////////////////////////////////////////////////////////////////////
ll power(ll,ll);
ll mpower(ll,ll);
//////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 /* copy from here */
template <typename T>
class SparseTable
{
	vector<vector<T>> table;
	int maxN;
	vector<int> logArr;
	std::function<T(T,T)> functor;
public:
	SparseTable(vector<T>& array,std::function<T(T,T)> functor,int maxN,T infinity)
		: maxN(maxN), logArr(maxN+1), table(log2(maxN)+1,vector<T>(maxN,infinity)), functor(functor)
	{
		buildTable(array,maxN);
		logArr[1] = 0;
		for(int i=2;i<=maxN;i++)
			logArr[i] = logArr[i/2] + 1;
	}
	void buildTable(vector<T>& array,int maxN)
	{
		for(int i=0;i<maxN;i++)
			table[0][i] = array[i];
		for(int i=1;i<=log2(maxN);i++)
		{
			for(int j=0;j+(1<<i)<=maxN;j++)
			{
				table[i][j] = functor(table[i-1][j],table[i-1][j+(1<<(i-1))]);
			}
		}
	}
 
	// When functor is associtive only
	// This method runs in O(log(maxN)) time
	T query(int l,int r)
	{
		T result = table[0][l];
		for(int p = logArr[r-l+1]; l<=r; p = logArr[r-l+1])
		{
			result = functor(result,table[p][l]);
			l += (1<<p);
		}
		return result;
	}
 
	// when functor is associative as well as satisfies overlap property 
	// This method runs in O(1) time
	T queryOverlap(int l,int r)
	{
		int len = r - l + 1;
		int p = logArr[len];
		return functor(table[p][l],table[p][r-(1<<p)+1]);
	}
};
/* copy till here */
 
int32_t main() {
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif
 
 
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	auto gcd = [](int a,int b)
	{
		return __gcd(a,b);
	};
	auto mini = [](int a,int b)
	{
		return min(a,b);
	};
	SparseTable<int> g(arr,gcd,n,1),m(arr,mini,n,INT_MAX);
	auto check = [&](int idx,int len)
	{
		if(len+idx-1>=n) return false;
		if(len==1) return true;
		int a = g.queryOverlap(idx,idx+len-1);
		int b = m.queryOverlap(idx,idx+len-1);
		return a==b;
	};
	auto ok = [&](int len) -> bool
	{
		for(int i=0;i<n;i++)
			if(check(i,len)) return true;
				return false;
	};
	int l = 1, r = n;
	while(l<r)
	{
		int m = l + (r-l+1)/2;
		if(ok(m)) l = m;
		else r = m-1;
	}
	std::vector<int > ans;
	for(int i=0;i<n;i++)
	{
		if(check(i,l))
			ans.pb(i);
	}
 
	cout<<ans.size()<<" "<<l-1<<endl;
	for (int u : ans)
	{
		cout << u + 1 << " ";
	}
	return 0;
}
 
 
 
 
 
 
 
/*_________________________________________________Utility Functions HERE_______________________________*/
 
ll power(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b%2==1)
		res=res*a;
		a=a*a;
		b=b/2;
	}
	return res;
}
ll mpower(ll a ,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b%2==1)
		{
			res=(res*a)%MOD;
		}
		a=(a*a)%MOD;
		b=b/2;
	}
	return res;
}
