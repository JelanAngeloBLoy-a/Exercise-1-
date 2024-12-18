#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

bool isValidName(string name) {
    for (int i = 0; i < name.length(); i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return false;
        }
    }
    return true;
}


bool isValidAge(int age) {
    return age > 0;
}


bool isValidHeight(double heightFeet, double heightInches) {
    return heightFeet > 0 && heightInches >= 0;
}


bool isValidWeight(double weight) {
    return weight > 0;
}

bool has_suffix(const string &txt, const string &suffix)
{
    return txt.size() >= suffix.size() &&
           txt.compare(txt.size() - suffix.size(), suffix.size(), suffix) == 0;
}

bool askContinue() {
	cout<<"Caution! If the filename already exists, it will be overwritten by the new input. Continue?(Y/N): ";
	char answer;
    cin >> answer;
    return (answer == 'y' || answer == 'Y');
}

bool askNew() {
	cout<<"Would you like to enter a new filename?(Y/N): ";
	char answer;
    cin >> answer;
    return (answer == 'y' || answer == 'Y');
}



void displayDetails(string name, int age, double heightFeet, double heightInches, double weight) {
	system("CLS");
    cout << "\n--- Your Details ---" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << heightFeet << " ft " << heightInches << " in" << endl;
    cout << "Weight: " << weight << " KG" << endl;
}


void calculateHeartRate(int age, double& moderateTHR, double& highTHR) {
    int RHR;
    double intensity1, intensity2;
    int MHR = 220 - age;

    cout << "\nEnter your Resting Heart Rate (RHR): ";
    cin >> RHR;

    while (RHR <= 0) {
        cout << "Invalid Resting Heart Rate. Please enter a valid value: ";
        cin >> RHR;
    }

    do {
        cout << "Enter intensity for moderate exercise (70-80%): ";
        cin >> intensity1;
        if (intensity1 < 70 || intensity1 > 80) {
            cout << "Invalid input. Intensity for moderate exercise must be between 70% and 80%.\n";
        }
    } while (intensity1 < 70 || intensity1 > 80);

    do {
        cout << "Enter intensity for high exercise (80-90%): ";
        cin >> intensity2;
        if (intensity2 < 80 || intensity2 > 90) {
            cout << "Invalid input. Intensity for high exercise must be between 80% and 90%.\n";
        }
    } while (intensity2 < 80 || intensity2 > 90);

    moderateTHR = ((MHR - RHR) * (intensity1 / 100)) + RHR;
    highTHR = ((MHR - RHR) * (intensity2 / 100)) + RHR;

    cout << "Moderate Target Heart Rate: " << moderateTHR << endl;
    cout << "High Target Heart Rate: " << highTHR << endl;
    cout << "\nTarget Heart rate: " << moderateTHR <<"-"<<highTHR<< endl;
    
}


 void range(double moderateTHR, double highTHR, double currentTHR )
    {
    system("CLS");
	if ((currentTHR>=moderateTHR) && (currentTHR<=highTHR))
  {
     cout << "Congrats you have reached your target heart rate, keep up the work!/n";
  }
  else 
  {
     cout << "Your current heart did not reached the targeted heart rate, but lets try harder next time./n";
}
}

void saveWorkout(ofstream &file, const string &workout) {
    char saveOption;
    cout << "\nDo you want to save this workout to the file? (Y/N): ";
    cin >> saveOption;

    if (tolower(saveOption) == 'y') {
        file << workout << endl;
        cout << "Workout saved to file successfully.\n";
    } else {
        cout << "Workout not saved.\n";
    }
}

void StepExercise (ofstream &file)
{
	system("CLS");
	string step[50];
	char saveOption;
	bool condition=true;
	cout<<"Write here your exercise step plan that you will perform.\n";


	cout<<"\n---(Press ENTER key to move to your next step)---\n";
	cout<<"(Input STOP to end your list)\n";
	cout<<"\nExercise Steps:\n";
	cin.ignore();
		
    while (condition) {
    	int j;
    	for(int i=0;i<=50;i++) {
			getline (cin,step[i]);
    	
    		if(step[i]=="stop" || step[i]=="STOP") {
	  			system("CLS");
				condition=false;
				break;
	  		}
		}
		cout<<"Would you like to save this workout to the text file (Y/N)?";
    	cin >> saveOption;

    	if (tolower(saveOption) == 'y') {
    		for(int i=0;i<=50;i++) {
    			if(step[i]=="stop"||step[i]=="stop")
    			break;
    			else
        		file << step[i] << endl;
        	}
        	cout << "Workout saved to file successfully.\n";
        	break;
    	} else {
        	cout << "Workout not saved.\n";
        	break;
   		}
		
	}
}



void upperBodyWorkout(ofstream &file) {
	system("CLS");
	string workouts[] = {
        "\n--- Back Exercises ---\nMonday: Deadlifts, Bent-over Rows\nTuesday: Pull-ups, Lat Pulldowns\nThursday: T-bar Row, Seated Rows\nSaturday: Core: Russian Twists\n",
        "\n--- Arm Exercises ---\nMonday: Bicep Curls, Tricep Dips\nWednesday: Hammer Curls, Tricep Extensions\nFriday: Close-grip Push-ups, Preacher Curls(No added weights)\n",
		"\n--- Chest Exercises ---\nMonday: Bench Press, Chest Fly\nTuesday: Push-ups, Chest Press Machine\nThursday: Incline Dumbbell Press, Pec Deck\n",
        "\n--- Shoulder Exercises ---\nMonday: Shoulder Press, Lateral Raises\nWednesday: Front Raises, Arnold Press\nFriday: Shrugs, Reverse Fly\n"
	};
	string progression[] = {
        "\n--- Back Exercises ---\nMonday: Sumo Deadlifts,  Pendlay Rows\nTuesday: Weighted Pull-ups, Wider Grip Lat Pulldowns\nThursday: Heavy weight T-bar Row, Seated Rows with Resistance Bands\nSaturday: Core: Weighted Russian Twists\n",
        "\n--- Arm Exercises ---\nMonday: Barbell Curls, Heavy weight Tricep Dips\nWednesday: Hammer Curls(Add more weights), Overhead Tricep Extensions\nFriday: Close-grip Elevated Push-ups, Barbell Preacher Curls\n",
		"\n--- Chest Exercises ---\nMonday: Bench Press(Added weight), Dumbbell Chest Fly\nTuesday: Weighted Push-ups, Chest Press Machine(Perform slow negative reps)\nThursday: Dumbbell Unilateral Chest Press, Pec Deck(Hold longer)\n",
        "\n--- Shoulder Exercises ---\nMonday: Unilateral Shoulder Press, Lateral Raises(Pause at top)\nWednesday: Barbell Front Raises, Arnold Press(Perform slow negative reps)\nFriday: Barbell Shrugs, Heavy weight Reverse Fly\n"
	};
	string regression[] = {
        "\n--- Back Exercises ---\nMonday: Romanian Deadlifts, Dumbbell Rows\nTuesday: Assisted Pull-ups, Light weight Lat Pulldowns\nThursday: Chest-Supported Row, Light weight Seated Rows\nSaturday: Core: Bodyweight Russian Twists\n",
        "\n--- Arm Exercises ---\nMonday: Light weight Bicep Curls, Triceps Bench Dips\nWednesday: Light weight Hammer Curls, Light weight Tricep Extensions\nFriday: Wall Push-ups, Dumbbell Preacher Curls\n",
		"\n--- Chest Exercises ---\nMonday: Dumbbell Bench Press, Bodyweight Chest Fly\nTuesday: Wall or Knee Push-ups, Assisted Chest Press Machine\nThursday: Bodyweight Incline Dumbbell Press, Resistance bands Pec Deck\n",
        "\n--- Shoulder Exercises ---\nMonday: Assisted Shoulder Press, Bodyweight Lateral Raises\nWednesday: Light weight Front Raises, Seated Arnold Press\nFriday: Bodyweight Shrugs, Light weight Reverse Fly\n"
	};
    int choice;
    bool continueWorkout = true;
    char choose;

    while (continueWorkout) {
    	system("CLS");
    	bool intense=true;
        cout << "\n--- Upper Body Workout Options ---\n";
        cout << "1. Back Exercises\n";
        cout << "2. Arm Exercises\n";
        cout << "3. Chest Exercises\n";
        cout << "4. Shoulder Exercises\n";
        cout << "5. Go Back\n";
        cout << "Choose (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
            	system("CLS");
        		cout << workouts[choice - 1] << endl;
                
                while (intense)
                {
                cout << "\nWould you like to:\n";	
                cout << "Press (P) for progression of exercise\n";
                cout << "Press (R) for regression of exercise\n";
                cout << "Press (N) for No\n";
                cin >> choose;
                
                if (choose=='P' || choose=='p')
                {
                	system("CLS");
        			cout << progression[choice - 1] << endl;
        			saveWorkout(file, workouts[choice - 1]);
                	break;
				}
				
				else if (choose=='R' || choose=='r')
                {
                	system("CLS");
        			cout << regression[choice - 1] << endl;
        			saveWorkout(file, workouts[choice - 1]);
                	break;
				}
				
				else if (choose=='N' || choose=='n')
                {
        			saveWorkout(file, workouts[choice - 1]);
                	cout <<"Let us continue then\n";
                	intense=false;
				}
                
				else
				{
					system("CLS");
					cout<<"Option unavailable, please try again";
				}
				}
                break;
            case 2:
            	system("CLS");
        		cout << workouts[choice - 1] << endl;
                
                while (intense)
                {
                cout << "\nWould you like to:\n";	
                cout << "Press (P) for progression of exercise\n";
                cout << "Press (R) for regression of exercise\n";
                cout << "Press (N) for No\n";
                cin >>choose;
                
                if (choose=='P' || choose=='p')
                {
                	system("CLS");
        			cout << progression[choice - 1] << endl;
        			saveWorkout(file, workouts[choice - 1]);
                	break;
				}
				
				else if (choose=='R' || choose=='r')
                {
                	system("CLS");
        			cout << regression[choice - 1] << endl;
        			saveWorkout(file, workouts[choice - 1]);
                	break;
				}
				
				else if (choose=='N' || choose=='n')
                {
        			saveWorkout(file, workouts[choice - 1]);
                	cout <<"Let us continue then\n";
                	intense=false;
				}
                
				else
				{
					system("CLS");
					cout<<"Option unavailable, please try again";
				}
				}
                break;
            case 3:
            	system("CLS");
        		cout << workouts[choice - 1] << endl;
                
                while (intense)
                {
                cout << "\nWould you like to:\n";	
                cout << "Press (P) for progression of exercise\n";
                cout << "Press (R) for regression of exercise\n";
                cout << "Press (N) for No\n";
                cin >>choose;
                
                if (choose=='P' || choose=='p')
                {
                	system("CLS");
        			cout << progression[choice - 1] << endl;
        			saveWorkout(file, workouts[choice - 1]);
                	break;
				}
				
				else if (choose=='R' || choose=='r')
                {
                	system("CLS");
        			cout << regression[choice - 1] << endl;
        			saveWorkout(file, workouts[choice - 1]);
                	break;
				}
				
				else if (choose=='N' || choose=='n')
                {
        			saveWorkout(file, workouts[choice - 1]);
                	cout <<"Let us continue then\n";
                	intense=false;
				}
                
				else
				{
					system("CLS");
					cout<<"Option unavailable, please try again";
				}
				}
                break;
            case 4:
            	system("CLS");
        		cout << workouts[choice - 1] << endl;
                
                while (intense)
                {
                cout << "\nWould you like to:\n";	
                cout << "Press (P) for progression of exercise\n";
                cout << "Press (R) for regression of exercise\n";
                cout << "Press (N) for No\n";
                cin >>choose;
                
                if (choose=='P' || choose=='p')
                {
                	system("CLS");
        			cout << progression[choice - 1] << endl;
        			saveWorkout(file, workouts[choice - 1]);
                	break;
				}
				
				else if (choose=='R' || choose=='r')
                {
                	system("CLS");
        			cout << regression[choice - 1] << endl;
        			saveWorkout(file, workouts[choice - 1]);
                	break;
				}
				
				else if (choose=='N' || choose=='n')
                {
        			saveWorkout(file, workouts[choice - 1]);
                	cout <<"Let us continue then\n";
                	intense=false;
				}
                
				else
				{
					system("CLS");
					cout<<"Option unavailable, please try again";
				}
				}
                break;
            case 5:
            	system("CLS");
                cout << "Going back to workout options\n";
                continueWorkout = false;
                break;
            default:
            	system("CLS");
                cout << "Invalid choice. Please try again.\n";
        }

        if (continueWorkout) {
        	system("CLS");
            cout << "Do you want to choose another workout area (Y/N)? ";
            char again;
            cin >> again;
            if (again == 'N' || again == 'n') {
                continueWorkout = false;
            }
        }
    }
}


void lowerBodyWorkout(ofstream &file) {
	system("CLS");
	string workouts[] = {
        "\n--- Leg Exercises ---\nMonday: Squats, Lunges\nTuesday: Leg Press, Step-ups\nThursday: Deadlifts, Leg Extensions\n",
        "\n--- Glute Exercises ---\nMonday: Hip Thrusts, Glute Bridges\nTuesday: Bulgarian Split Squats, Lunges\nThursday: Deadlifts, Cable Kickbacks\n",
		"\n--- Calf Exercises ---\nMonday: Standing Calf Raises\nTuesday: Seated Calf Raises\nThursday: Donkey Calf Raises\n"
	};
	string progression[] = {
		"\n--- Leg Exercises ---\nMonday: Jump Squats, Bulgarian Split Squats\nTuesday: Single-leg Press, Weighted Step-ups\nThursday: Romanian Deadlifts, Weighted Leg Extensions\n",
        "\n--- Glute Exercises ---\nMonday: Single-leg Hip Thrusts, Weighted Glute Bridges\nTuesday: Weighted Bulgarian Split Squats, Weighted Walking Lunges\nThursday: Stiff-legged Deadlifts, Increase Resistance on Cable Kickbacks\n",
		"\n--- Calf Exercises ---\nMonday: Weighted Standing Calf Raises\nTuesday: Seated Calf Raises with heavier weights\nThursday: Donkey Calf Raises with heavier weights\n"
	};
	string regression[] = {
		"\n--- Leg Exercises ---\nMonday: Jump Squats, Bulgarian Split Squats\nTuesday: Single-leg Press, Weighted Step-ups\nThursday: Romanian Deadlifts, Weighted Leg Extensions\n",
        "\n--- Glute Exercises ---\nMonday: Glute Bridges, Glute Bridges(Hold the position)\nTuesday: Assisted Bulgarian Split Squats (hold a rail), Reverse Lunges with Body Weight\nThursday: Deadlifts with lesser weights, Cable Kickbacks with no added weight\n",
		"\n--- Calf Exercises ---\nMonday: Bodyweight Standing Calf Raises\nTuesday: Light weight Seated Calf Raises\nThursday: Body weight Donkey Calf Raises\n"
	};
    int choice;
    bool continueWorkout = true;
    char choose;

    while (continueWorkout) {
    	system("CLS");
    	bool intense=true;
        cout << "\n--- Lower Body Workout Options ---\n";
        cout << "1. Leg Exercises\n";
        cout << "2. Glute Exercises\n";
        cout << "3. Calf Exercises\n";
        cout << "4. Go Back\n";
        cout << "Choose (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
            	system("CLS");
        		cout << workouts[choice - 1] << endl;
                
                while (intense)
                {
                cout << "\nWould you like to:\n";	
                cout << "Press (P) for progression of exercise\n";
                cout << "Press (R) for regression of exercise\n";
                cout << "Press (N) for No\n";
                cin >>choose;
                
                if (choose=='P' || choose=='p')
                {
                	system("CLS");
        			cout << progression[choice - 1] << endl;
        			saveWorkout(file, workouts[choice - 1]);
                	break;
				}
				
				else if (choose=='R' || choose=='r')
                {
                	system("CLS");
        			cout << regression[choice - 1] << endl;
        			saveWorkout(file, workouts[choice - 1]);
                	break;
				}
				
				else if (choose=='N' || choose=='n')
                {
        			saveWorkout(file, workouts[choice - 1]);
                	cout <<"Let us continue then\n";
                	intense=false;
				}
                
				else
				{
					system("CLS");
					cout<<"Option unavailable, please try again";
				}
				}
                break;
            case 2:
            	system("CLS");
        		cout << workouts[choice - 1] << endl;
                
                while (intense)
                {
                cout << "\nWould you like to:\n";	
                cout << "Press (P) for progression of exercise\n";
                cout << "Press (R) for regression of exercise\n";
                cout << "Press (N) for No\n";
                cin >>choose;
                
                if (choose=='P' || choose=='p')
                {
                	system("CLS");
        			cout << progression[choice - 1] << endl;
        			saveWorkout(file, workouts[choice - 1]);
                	break;
				}
				
				else if (choose=='R' || choose=='r')
                {
                	system("CLS");
        			cout << regression[choice - 1] << endl;
        			saveWorkout(file, workouts[choice - 1]);
                	break;
				}
				
				else if (choose=='N' || choose=='n')
                {
        			saveWorkout(file, workouts[choice - 1]);
                	cout <<"Let us continue then\n";
                	intense=false;
				}
                
				else
				{
					system("CLS");
					cout<<"Option unavailable, please try again";
				}
				}
                break;
            case 3:
            	system("CLS");
        		cout << workouts[choice - 1] << endl;
                
                while (intense)
                {
                cout << "\nWould you like to:\n";	
                cout << "Press (P) for progression of exercise\n";
                cout << "Press (R) for regression of exercise\n";
                cout << "Press (N) for No\n";
                cin >>choose;
                
                if (choose=='P' || choose=='p')
                {
                	system("CLS");
        			cout << progression[choice - 1] << endl;
        			saveWorkout(file, workouts[choice - 1]);
                	break;
                	
				}
				
				else if (choose=='R' || choose=='r')
                {
                	system("CLS");
        			cout << regression[choice - 1] << endl;
        			saveWorkout(file, workouts[choice - 1]);
                	break;
				}
				
				else if (choose=='N' || choose=='n')
                {
        			saveWorkout(file, workouts[choice - 1]);
                	cout <<"Let us continue then\n";
                	intense=false;
				}
                
				else
				{
					system("CLS");
					cout<<"Option unavailable, please try again";
				}
				}
                break;
            case 4:
            	system("CLS");
                cout << "Going back to workout options\n";
                continueWorkout = false;
                break;
            default:
            	system("CLS");
                cout << "Invalid choice. Please try again.\n";
        }

        if (continueWorkout) {
        	system("CLS");
            cout << "Do you want to choose another workout area for lower body (Y/N)? ";
            char again;
            cin >> again;
            if (again == 'N' || again == 'n') {
                continueWorkout = false;
            }
        }
    }
}

int main() {
    string name;
	string txt;
    int age;
    double heightFeet, heightInches, weight, moderateTHR, highTHR, currentTHR;
    char option, option2;
    string date;
    
	cout<<"For you to save this output, please enter a file name ending with .txt: ";
	ofstream textFile;
	getline(cin, txt);
	while(!has_suffix(txt, ".txt")) {
		system("CLS");
		cout<<"that is incorrect! Please input again: ";
		getline(cin, txt);
	}
	
	textFile.open(txt);
	
	bool willContinue = askContinue();
	cin.ignore();
	if(willContinue) {
		system("CLS");
		
    	cout<<"Date:";
    	getline (cin, date);
    	
	
    	do {
    	    cout << "Enter your name: ";
    	    getline(cin, name);
	
    	    if (!isValidName(name)) {
    	        cout << "Invalid name. Only letters and spaces allowed.\n";
    	    }
    	} while (!isValidName(name));
	
    	do {
    	    cout << "Enter your age: ";
   	     cin >> age;
	
    	    if (!isValidAge(age)) {
    	        cout << "Invalid age. Please enter a valid age (greater than 0).\n";
    	    }
    	} while (!isValidAge(age));
	
    	cout << "Enter height in feet: ";
    	cin >> heightFeet;
    	cout << "Enter height in inches: ";
    	cin >> heightInches;
    	cout << "Enter weight in kg: ";
    	cin >> weight;
	
    	displayDetails(name, age, heightFeet, heightInches, weight);
    	
    	cout << "Are these details correct? (Y/N): ";
    	cin >> option;
	
    	if (option == 'Y' || option == 'y') {
			system("CLS");
    		textFile << "\n--- Your Details ---" << endl << "Name: " << name << endl << "Age: " << age << endl << "Height: " << heightFeet << " ft " << heightInches << " in" << endl << "Weight: " << weight << " KG" << endl;
		
    	    calculateHeartRate(age, moderateTHR, highTHR);
	
    	    int choice;
    	    bool continueChoosing = true;
    	    while (continueChoosing) {
    	        cout << "\nChoose your workout area:\n";
    	        cout << "1. Upper Body\n";
    	        cout << "2. Lower Body\n";
    	        cout << "3. Exit\n";
    	        cout << "Choose (1-3): ";
    	        cin >> choice;
	
    	        switch (choice) {
    	            case 1:
    	                upperBodyWorkout(textFile);
    	                break;
    	            case 2:
   		                lowerBodyWorkout(textFile);
    	                break;
    	            case 3:
    	                
    	                cout<<"Exiting...";
    	                continueChoosing = false;
    	                break;
    	            default:
    	                cout << "Invalid choice. Exiting...\n";
    	                continueChoosing = false;
    	        }
    	    }
    	} else {
    	    cout << "Please restart and enter the details again.\n";
    	}
    	cout << "\n Have you achieved your targeted heart rate? input your current heart rate\n";
    	cout<<"Current heart rate:";
    	cin>> currentTHR;
                    
    	range( moderateTHR, highTHR, currentTHR);
    
    	cout<<"\nWould you like to write your step plan procedure?:\n";
    	cout<<"Press (Y) for yes\n";
    	cout<<"Press (N) for No\n";
    	cin>>option2;
    	
    	if(option2=='Y' || option2=='y')
    	{
    		 StepExercise (textFile);
		}
		
		else if(option2=='N' || option2=='n')
    	{
    		cout<<"EXERCISE ACTIVITY END";
		}
    	
    	cout<<"EXERCISE ACTIVITY END";
    }
    
	else {
		system("CLS");
		bool willNew=askNew();
		cin.ignore();
		if(willNew) {
			system("CLS");
			return main();
		}
		else {
			system("CLS");
			cout<<"Thank you for using our program.";
		}
	}
}
