//洗牌在生活中十分常见，现在需要写一个程序模拟洗牌的过程。 现在需要洗2n张牌，从上到下依次是第1张，第2张，
//第3张一直到第2n张。首先，我们把这2n张牌分成两堆，左手拿着第1张到第n张（上半堆），右手拿着第n+1张到第2n张
//（下半堆）。接着就开始洗牌的过程，先放下右手的最后一张牌，再放下左手的最后一张牌，接着放下右手的倒数第二张
//牌，再放下左手的倒数第二张牌，直到最后放下左手的第一张牌。接着把牌合并起来就可以了。 例如有6张牌，最开始牌
//的序列是1,2,3,4,5,6。首先分成两组，左手拿着1,2,3；右手拿着4,5,6。在洗牌过程中按顺序放下了6,3,5,2,4,1。把这
//六张牌再次合成一组牌之后，我们按照从上往下的顺序看这组牌，就变成了序列1,4,2,5,3,6。 
//现在给出一个原始牌组，请输出这副牌洗牌k次之后从上往下的序列。 

#include<iostream>
using namespace std;
#include<vector>
#include<stack>
void Shuffle(vector<int> v,int k)
{
	stack<int> s;
	stack<int> s1;
	stack<int> s2;
	while (k--)
	{
		size_t i = 0;
		for (i = 0; i < v.size() / 2; ++i)
		{
			s1.push(v[i]);
		}
		for (i = v.size() / 2; i < v.size(); ++i)
		{
			s2.push(v[i]);
		}
		v.clear();
		while (!s1.empty() || !s2.empty())
		{
			s.push(s2.top());
			s2.pop();
			s.push(s1.top());
			s1.pop();
		}
		while (!s.empty())
		{
			v.push_back(s.top());
			s.pop();
		}
	}
	cout << v[0];
	for (int i = 1; i < v.size(); ++i)
	{
		cout << " " << v[i];
	}
    cout<<endl;
}
int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n = 0;//2n个数
		int k = 0;
		cin >> n >> k;
		vector<int> v;
		n *= 2;
		while (n--)
		{
			int tmp;
			cin >>tmp;
			v.push_back(tmp);
		}
		Shuffle(v, k);
	}
	return 0;
}