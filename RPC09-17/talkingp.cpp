#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	string n;
	getline(cin,n);
	int x = atoi(n.c_str());
	while(x>0)
	{
		string s="";
		string res = "";
		getline(cin,s);
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == 'a')
			{
				res= res + "apa";	
			}else if(s[i] == 'e')
			{
				res= res + "epe";	
			}else if(s[i] == 'i')
			{
				res= res +  "ipi";
			}else if(s[i] == 'o')
			{
				res= res + "opo";	
			}else if(s[i] == 'u')
			{
				res= res +  "upu";
			}else{
				res= res + s[i];
			} 
		}
		cout << res << endl;
		x--;
	}
	return 0;
}