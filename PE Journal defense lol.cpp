#include <iostream>
#include <string>
#include <cctype>
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

void displayDetails(string name, int age, double heightFeet, double heightInches, double weight) {
    cout << "\n--- Your Details ---" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << heightFeet << " ft " << heightInches << " in" << endl;
    cout << "Weight: " << weight << " KG" << endl;
}

void calculateHeartRate(int age) {
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

    double moderateTHR = ((MHR - RHR) * (intensity1 / 100)) + RHR;
    double highTHR = ((MHR - RHR) * (intensity2 / 100)) + RHR;

    cout << "Moderate Target Heart Rate: " << moderateTHR << endl;
    cout << "High Target Heart Rate: " << highTHR << endl;
}

void upperBodyWorkout() {
    int choice;
    bool continueWorkout = true;

    while (continueWorkout) {
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
                cout << "\n--- Back Exercises ---\n";
                cout << "Monday: Deadlifts, Bent-over Rows\n";
                cout << "Tuesday: Pull-ups, Lat Pulldowns\n";
                cout << "Thursday: T-bar Row, Seated Rows\n";
                cout << "Saturday: Core: Russian Twists\n";
                break;
            case 2:
                cout << "\n--- Arm Exercises ---\n";
                cout << "Monday: Bicep Curls, Tricep Dips\n";
                cout << "Wednesday: Hammer Curls, Tricep Extensions\n";
                cout << "Friday: Close-grip Push-ups, Preacher Curls\n";
                break;
            case 3:
                cout << "\n--- Chest Exercises ---\n";
                cout << "Monday: Bench Press, Chest Fly\n";
                cout << "Tuesday: Push-ups, Chest Press Machine\n";
                cout << "Thursday: Incline Dumbbell Press, Pec Deck\n";
                break;
            case 4:
                cout << "\n--- Shoulder Exercises ---\n";
                cout << "Monday: Shoulder Press, Lateral Raises\n";
                cout << "Wednesday: Front Raises, Arnold Press\n";
                cout << "Friday: Shrugs, Reverse Fly\n";
                break;
            case 5:
                cout << "Going back to workout options\n";
                continueWorkout = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        if (continueWorkout) {
            cout << "Do you want to choose another workout area (Y/N)? ";
            char again;
            cin >> again;
            if (again == 'N' || again == 'n') {
                continueWorkout = false;
            }
        }
    }
}

void lowerBodyWorkout() {
    int choice;
    bool continueWorkout = true;

    while (continueWorkout) {
        cout << "\n--- Lower Body Workout Options ---\n";
        cout << "1. Leg Exercises\n";
        cout << "2. Glute Exercises\n";
        cout << "3. Calf Exercises\n";
        cout << "4. Go Back\n";
        cout << "Choose (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n--- Leg Exercises ---\n";
                cout << "Monday: Squats, Lunges\n";
                cout << "Tuesday: Leg Press, Step-ups\n";
                cout << "Thursday: Deadlifts, Leg Extensions\n";
                break;
            case 2:
                cout << "\n--- Glute Exercises ---\n";
                cout << "Monday: Hip Thrusts, Glute Bridges\n";
                cout << "Tuesday: Bulgarian Split Squats, Lunges\n";
                cout << "Thursday: Deadlifts, Cable Kickbacks\n";
                break;
            case 3:
                cout << "\n--- Calf Exercises ---\n";
                cout << "Monday: Standing Calf Raises\n";
                cout << "Tuesday: Seated Calf Raises\n";
                cout << "Thursday: Donkey Calf Raises\n";
                break;
            case 4:
                cout << "Going back to workout options\n";
                continueWorkout = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        if (continueWorkout) {
            cout << "Do you want to choose another workout area (Y/N)? ";
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
    int age;
    double heightFeet, heightInches, weight;
    char option;

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
        calculateHeartRate(age);

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
                    upperBodyWorkout();
                    break;
                case 2:
                    lowerBodyWorkout();
                    break;
                case 3:
                    cout << "Exiting workout options.\n";
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

    return 0;
}
