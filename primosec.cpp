#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	int num,cont;
	num=atoi(argv[1]);
	for(int i=2; i<=num;i++)
	{
		cont=0;
		for(int j=2;j<=i;j++)
		{
			if(i%j==0)
			{
				cont++;
			}
		}
			if(cont==1)
			{
				cout<<i<<" - ";
			}
	}
}


