#include<iostream>
#include<fcntl.h>
#include<unistd.h>


using namespace std;
int main()

{
	int f1;
//	int f1=creat("f111",0777);
	int f2=open("f111",O_CREAT|O_RDWR,0777);

	cout<<f1<<"        "<<f2<<endl;
	write(f2,"\nzaharan",8);

}
