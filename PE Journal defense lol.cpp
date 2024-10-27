#include <iostream>
using namespace std;
int main()
{

	int age, RHR, MHR;
	string name;
	double height, weight;
	
	// 	Insert personal details
	cout<<"Insert personal details:"<<endl;  
	cout<<"Name:";
	getline (cin, name);
	cout<<"Age:";
	cin>> age;
	
	cout<<"       "<<endl;
	cout<<"Input Physicial details:"<<endl;
	cout<<"Height:";
	cin>> height;
	cout<<"Weight:";
	cin>> weight;
	
	cout<<"Calculate your Resting Heart Rate:";
	cin>> RHR;

// maximum hear rate calculations
	MHR=200-age;
    cout<<"                   "<<endl;
	cout<<"Your Maximum Heart Rate:"<<MHR;
		
	
	return 0;
}
