#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
int a=10,b=10;
double last_punch,last_attack,last_meat;
int meat,weapon;
int main()
{
	srand(time(0));
	ifstream fi;
	ofstream fo;
	fi.open("nona4");
	fi>>weapon>>meat;
	fi.close();
	printf("Press Space to attack.\nPress 1 to eat meat.\n");
	system("pause");
	last_punch=clock();
	last_attack=clock();
	last_meat=clock();
	bool ok=0;
	while(a>0&&b>0)
	{
		double tmp=clock();
		if((tmp-last_punch)/CLOCKS_PER_SEC>=1&&!ok)
		printf("Punch ready!\n"),ok=1;
		if(_kbhit())
		{
			char ch=getch();
			if(ch==' ')
			if((tmp-last_punch)/CLOCKS_PER_SEC>=1)
			{
				printf("@ punch! ");
				last_punch=tmp;
				if(rand()%100<90)
				{
					b-=1;
					printf("E %d/10\n",b);
				}	
				else printf("missed\n");
				ok=0;
			}	
			if(ch=='1')
			if((tmp-last_meat)/CLOCKS_PER_SEC>=3)
			{
				if(meat<1)
				{
					printf("Not enough meat!\n");
				}
				else
				{
					printf("@ eat meat! ");
					meat--;
					last_meat=tmp;
					a=min(10,a+8);
					printf("@ %d/10\n",a);
					ok=0;
				}
				
			}
		} 
		if((tmp-last_attack)/CLOCKS_PER_SEC>=0.8)
		{
			last_attack=tmp;
			printf("E Attack! ");
			if(rand()%100<70) 
			{
				a-=1;
				printf("@ %d/10\n",a);
			}
			else printf("missed\n");
		}
	}
	if(a==0)
	{
		fo.open("nona4");
		fo<<0;
		fo.close();
	}
	else
	{
		fo.open("nona4");
		fo<<1<<' '<<meat;
		fo.close();
	}
	return 0;
}

