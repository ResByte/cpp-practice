#include <iostream>


using namespace std;

void DoIt(int &foo, int goo);

int main(){
	int *foo,*goo;
	foo = new int ;
	*foo = 1;
	goo = new int ;
	*goo = 5;
	*foo = *goo + *foo;

	foo = goo;
	*goo = 5;

	*foo = *foo + *goo;

	DoIt(*foo, *goo);

	cout << (*foo) << endl; 

	return 0; 
}

void DoIt(int &foo,int goo){
	foo = goo + 3;
	goo = foo + 4;
	foo = goo + 3;
	goo = foo;
}
