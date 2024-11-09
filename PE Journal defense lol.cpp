#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

// Function to validate name input
bool isValidName(string name) {
    int i = 0;
    while (i < name.size()) {
        char ch = name[i];
        if (!isalpha(ch) && ch != ' ' && ch != '-' && ch != '.' && ch != ',') {
            return false;
        }
        i++;
    }
    return true;
}

// Function to validate age input
bool isValidAge(string age) {
    int i = 0;
    while (i < age.size()) {
        if (!isdigit(age[i])) {
            return false;
        }
        i++;
    }
    return true;
}

// Function to convert a string to an integer safely
bool convertToInt(string str, int &number) {
    stringstream ss(str);
    ss >> number;
    return !ss.fail() && ss.eof();
}

// Function to display and confirm details
void displayDetails(string name, int age, double heightFeet, double heightInches, double weight) {
    cout << "\n--- Confirm Your Details ---" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << heightFeet << " ft " << heightInches << " in" << endl;
    cout << "Weight: " << weight << " KG" << endl;
}

// Function for heart rate calculations
int heartrate(int age, int RHR) {
    int MHR;
    double intensity1, intensity2, moderateTHR, highTHR;

    cout << "\nResting Heart Rate: ";
    cin >> RHR;

    cout << "Select the percentage of intensity for moderate intensity (70-80%): ";
    cin >> intensity1;
    cout << "Select the percentage of intensity for high intensity (80-90%): ";
    cin >> intensity2;

    MHR = 220 - age;
    cout << "\nYour Maximum Heart Rate: " << MHR << endl;

    // Convert intensity percentages to decimals
    intensity1 /= 100;
    intensity2 /= 100;

    // Calculate Target Heart Rate using Karvonen Formula
    moderateTHR = ((MHR - RHR) * intensity1) + RHR;
    highTHR = ((MHR - RHR) * intensity2) + RHR;

    // Display the target heart rate
    cout << "Your Target Heart Rate Training zone for moderate to high intensity is: "
         << moderateTHR << " - " << highTHR << endl;

    return 0;
}

// Function for workout recommendations
void workoutRecommendations() {
    int choice, subChoice;
    cout << "\n--- Workout Recommendations ---" << endl;
    cout << "Select the area you want to exercise:\n";
    cout << "1. Upper Body\n";
    cout << "2. Lower Body\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice) {
        case 1: // Upper Body
            cout << "\nSelect which part of the upper body you want to focus on:\n";
            cout << "1. Chest\n";
            cout << "2. Shoulders\n";
            cout << "3. Back\n";
            cout << "4. Arms\n";
            cout << "Enter your choice (1-4): ";
            cin >> subChoice;
            switch (subChoice) {
                case 1:
                    cout << "\nChest exercises: Push-ups, Bench Press, Chest Flyes.\n";
                    break;
                case 2:
                    cout << "\nShoulder exercises: Shoulder Press, Lateral Raises, Front Raises.\n";
                    break;
                case 3:
                    cout << "\nBack exercises: Pull-ups, Lat Pulldown, Rows.\n";
                    break;
                case 4:
                    cout << "\nArm exercises: Bicep Curls, Tricep Dips, Hammer Curls.\n";
                    break;
                default:
                    cout << "Invalid choice for upper body.\n";
            }
            break;
        case 2: // Lower Body
            cout << "\nSelect which part of the lower body you want to focus on:\n";
            cout << "1. Legs\n";
            cout << "2. Glutes\n";
            cout << "Enter your choice (1 or 2): ";
            cin >> subChoice;
            switch (subChoice) {
                case 1:
                    cout << "\nLeg exercises: Squats, Lunges, Leg Press.\n";
                    break;
                case 2:
                    cout << "\nGlute exercises: Hip Thrusts, Glute Bridges, Bulgarian Split Squats.\n";
                    break;
                default:
                    cout << "Invalid choice for lower body.\n";
            }
            break;
        default:
            cout << "Invalid choice for workout area.\n";
    }
}

int main() {
    int age, RHR;
    string name, ageInput;
    double heightFeet, heightInches, weight;
    char option;

    // Input personal details
    do {
        cout << "Insert personal details:" << endl;

        cout << "Enter your name: ";
        getline(cin, name);
        if (!isValidName(name)) {
            cout << "Invalid input. Name should only contain letters and punctuation.\n";
            continue;
        }

        cout << "Age: ";
        cin >> ageInput;
        if (!isValidAge(ageInput) || !convertToInt(ageInput, age)) {
            cout << "Invalid input. Age should only contain numbers.\n";
            cin.clear();
            cin.ignore();  // Clear input buffer
            continue;
        }

        // Input physical details
        cout << "\nInput Physical Details:" << endl;

        cout << "Height in Feet (0-8): ";
        cin >> heightFeet;
        cout << "Height in Inches (0-12): ";
        cin >> heightInches;
        cout << "Weight in KG (max 700): ";
        cin >> weight;

        // Display entered details and confirm
        displayDetails(name, age, heightFeet, heightInches, weight);

        cout << "\nAre these details correct? (Y/N): ";
        cin >> option;
        cin.ignore();  // Clear input buffer

    } while (option != 'Y' && option != 'y');

    // Wait for user input before proceeding to heart rate calculations
    cout << "\nPress any key to proceed to heart rate calculations...";
    cin.ignore();  // Wait for any key input
    cin.get();  // Wait for user to press a key

    // Call the heartrate function after confirmation
    heartrate(age, RHR);

    // Provide workout recommendations
    workoutRecommendations();

    return 0;
}
