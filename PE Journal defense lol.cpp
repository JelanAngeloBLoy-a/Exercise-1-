#include <iostream>
using namespace std;
int main()
{

	int age, RHR, MHR;
	string name;
	double height, weight, highTHR, moderateTHR, intensity, intensity1, intensity2;
	char option, option2;
	
	
	// Insert personal details
	cout<<"Insert personal details:"<<endl;  
	cout<<"Name:";
	getline (cin, name);
	cout<<"Age:";
	cin>> age;
	
	// Insert your physical details
	cout<<"       "<<endl;
	cout<<"Input Physicial details in Feet(ft):"<<endl;
	cout<<"Height:";
	cin>> height;
	cout<<"Weight:";
	cin>> weight;
	
	// Resting Heart rate
    cout<<"                   "<<endl;
	cout<<"Resting Heart Rate:";
	cin>> RHR;
	
	// Selecting the percentage of moderate and high intensity
	cout<<"select the percentage of intensity for moderate intensity (70-80%):"<<endl;
	cin>>intensity1;
	cout<<"select the percentage of intensity for moderate intensity (80-90%):"<<endl;
	cin>>intensity2;
	
	
	// Correction and making sure if the process is correct
	cout<<"                   "<<endl;
	cout<<"Are the inputted information correct? Insert (Y/N)";
	cin>>option;
	
	
	if (option=='Y'){
	cout<<" Let us continue";
	cout<<"                   "<<endl;	
    }
    
    else if(option=='N'){
    cout<<"Choose what you want to change"<<endl;
    cout<<"Press A to change name and age"<<endl;
    cout<<"Press B to change Physical details"<<endl;
    cout<<"Press C to change name and age"<<endl;
    cout<<"Press D to change Restart"<<endl;
    cin>>option2;
    
    switch(option2){
    	
    case 'A':
		cout<<"Insert personal details:"<<endl;  
	cout<<"Name:";
	getline (cin, name);
	cout<<"Age:";
	
	
	case 'B':
	cout<<"       "<<endl;
	cout<<"Input Physicial details in Feet(ft):"<<endl;
	cout<<"Height:";
	cin>> height;
	cout<<"Weight:";
	cin>> weight;
	
	case 'C':
		// Resting Heart rate
    cout<<"                   "<<endl;
	cout<<"Resting Heart Rate:";
	cin>> RHR;
	
	
	// Selecting the percentage of moderate and high intensity
	cout<<"select the percentage of intensity for moderate intensity (70-80%):"<<endl;
	cin>>intensity1;
	cout<<"select the percentage of intensity for moderate intensity (80-90%):"<<endl;
	cin>>intensity2;
	
	case 'D':
		// Change Everything Back
	cout<<"Insert personal details:"<<endl;  
	cout<<"Name:";
	getline (cin, name2);
	cout<<"Age:";
	cin>> age;
	
	cout<<"       "<<endl;
	cout<<"Input Physicial details in Feet(ft):"<<endl;
	cout<<"Height:";
	cin>> height;
	cout<<"Weight:";
	cin>> weight;
	
	// Resting Heart rate
    cout<<"                   "<<endl;
	cout<<"Resting Heart Rate:";
	cin>> RHR;
	
	// Selecting the percentage of moderate and high intensity
	cout<<"select the percentage of intensity for moderate intensity (70-80%):"<<endl;
	cin>>intensity1;
	cout<<"select the percentage of intensity for moderate intensity (80-90%):"<<endl;
	cin>>intensity2;
		
     }
		
	}
	
		// maximum hear rate calculations
	MHR=200-age;
    cout<<"                   "<<endl;
	cout<<"Your Maximum Heart Rate:"<<MHR;
	cout<<"       "<<endl;	
    
	// Conversion of intensity to percentage
	intensity1/=100;
	intensity2/=100;
	
	// Calculating Karvonen Formula 
	moderateTHR= ((MHR-RHR)*intensity1) + RHR;
	highTHR=((MHR-RHR)*intensity2) + RHR;
	cout<<"                   "<<endl;
	 
	// Display of  targeted heart rate
	cout<<"your Target Heart Rate Training zone for moderate to high intensity, should be: "<<endl;
	cout<<moderateTHR<<"-"<<highTHR<<endl;
     
    	
	
	
	
	
	return 0;
}
