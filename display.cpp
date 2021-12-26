#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
#define ll long long
const int mod=1000000007;
map<string,bool> ok;
map<string,string> mp;
string name[500];
void init()
{
	name[1]="Wood";
	name[2]="Charcoal";
	name[3]="Meat";
	name[4]="Cooked Meat";
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
	printf("---- materials -----\n");
	fi.open("nona3");
	int n;
	fi>>n;
	int ta;
	for(int i=1;i<=n;i++)
	{
		fi>>ta;
		cout<<name[i]<<" - "<<ta<<endl;
	}
	fi.close();
    Sleep(3000);
	goto MAIN;
	return 0;
}

