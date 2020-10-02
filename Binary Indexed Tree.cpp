#include<bits/stdc++.h>
using namespace std;

/**
* This class implements Fenwick Tree Data Structure,
* It uses 1 based Indexing
* TODO: implement a generic method to support Binary search over the tree array
*/
template <typename T>
class BIT
{
	vector<T> tree;
	int sz;
	T def;
	std::function<T(T,T)> functor;
	void buildTree()
	{
		for(int i=1;i<=sz;i++)
		{
			int parent = i + (i&(-i));
			if(parent<=sz)
				tree[parent-1] = functor(tree[i-1],tree[parent-1]);
		}
	}
public:
	BIT(vector<T> array,int sz,T def,std::function<T(T,T)> functor)
		: tree(array.begin(),array.end()), sz(sz), functor(functor), def(def)
	{
		buildTree();
	}
	BIT(int sz,T def,std::function<T(T,T)> functor)
		: tree(sz,def), sz(sz), functor(functor), def(def)
	{
	}
	T query(int ind)
	{
		T result = def;
		for(; ind>0; ind-=ind&-ind)
		{
			result = functor(result,tree[ind-1]);
		}
		return result; 
	}
	void update(int ind,T val)
	{
		for(;ind<=sz;ind+=ind&-ind)
			tree[ind-1] = functor(tree[ind-1],val);
	}

	T getElementInTree(int ind)
	{
		return tree[ind-1];
	}
};


// testing on problem UPDATEIT Spoj 
int solve()
{
	int n, u;
	cin >> n >> u;

	BIT<long long> ftree(n,0,[](long long a,long long b){return a+b;});


	while(u--)
	{
		int i,j,val;
		cin >> i >> j >> val;
		ftree.update(i+1,val);
		ftree.update(j+2,-val);
	}

	int q;
	cin >> q;

	while(q--)
	{
		int i;
		cin >> i;
		cout << ftree.query(i+1) << endl;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}
