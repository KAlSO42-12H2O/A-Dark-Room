#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
#define ll long long
const int mod=1000000007;
map<string,bool> ok;
map<string,string> mp;
string name[2005];
void init()
{
	name[1]="Wood";
	name[2]="Charcoal";
	name[3]="Meat";
	name[4]="Cooked Meat";
	name[1001]="Stick";
}
void display(string s)
{
	if(ok[s]) cout<<s<<" - "<<mp[s]<<endl;
}
int main()
{
	init();
	ifstream fi;
	ofstream fo;
	MAIN:
	system("cls");
	
	fi.open("nona3");
	int n;
	printf("---- Materials -----\n");
	fi>>n;
	int ta;
	for(int i=1;i<=n;i++)
	{
		fi>>ta;
		cout<<name[i]<<" - "<<ta<<endl;
	}
	
	fi>>n;
	if(n) printf("---- Tools -----\n");
	for(int i=1;i<=n;i++)
	{
		fi>>ta;
		cout<<name[i+1000]<<" - "<<ta<<endl;
	}
	fi.close();
    Sleep(2500);
	goto MAIN;
	return 0;
}

