#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m;
	while(cin >>n >> m)
	{
		int vec[n];
		int sum = 0 ,ini = 0, fin = 0;
		for(int i = 0; i<n; i++)
			cin >> vec[i];
		sum = vec [0];
		while(sum != m)
		{
			if(sum < m)
			{
				++fin;
				sum += vec[fin];
				
			}else
			{
				
				sum -= vec[ini];
				++ini;
			}
		}
		cout << ini+1 << " "<< fin+1 << endl;
	}
	return 0;
}