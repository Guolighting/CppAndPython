#include <bits/stdc++.h>
using namespace std;
class StockPrice
{
public:
	map<int, int> t_p;
	StockPrice()
	{
	}

	void update(int timestamp, int price)
	{
		t_p[timestamp] = price;
	}

	int current()
	{
		if (t_p.size() <= 0)
		{
			return -1;
		}
		return t_p[t_p.size() - 1];
	}

	int maximum()
	{
		if (t_p.size() <= 0)
		{
			return -1;
		}
		int mx = 0;
		for (map<int, int>::iterator it = t_p.begin(); it != t_p.end(); ++it)
		{
			if(mx < it->second){
				mx = it->second;
			}	
		}
		return mx;
	}

	int minimum()
	{
		if (t_p.size() <= 0)
		{
			return -1;
		}
		int mn = 100000000;
		for (map<int, int>::iterator it = t_p.begin(); it != t_p.end(); ++it)
		{
			if(mn > it->second){
				mn = it->second;
			}	
		}
		return mn;
	}
};

int main()
{
}