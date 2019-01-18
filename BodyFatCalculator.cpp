/*
Anthony Ronca
CIT 133
Due 10/11
4 hours


    Variables used:
    weight - store user's name (string)
    wrist - store user's name (string)
    hip - store user's name (string)
    forearm -  store user's name (string)
    B -  store user's name (string)
    bodyFat - store user's name (string)
    bodyFatPer - store user's name (string)

*/


/*
Anthony Ronca
CIT 133
Due 10/11
2 hours so far

    Variables used:
    weight - store user's weight
    wrist - store user's wrist measurement, only if female
    hip - store user's hip, only if female
    forearm -  store user's forearm measurement, only if female
    B -  Formula provided by Naser
    bodyFat - stores a caclulated double from weight
    bodyFatPer - calculates and stores user's body fat percentage
    gender  -   stores a char for M or F
    choice  -   stores char for Y or N
    name    -   stores user's name for save file
    fileName    -   stores user's designated file name

*/

#include <iostream> // cout, cin
#include <iomanip> // setw
#include <String>
#include <fstream>

using namespace std; //cin,cout

int main()
{
    //initialize variables before if statements
    double weight = 0;  // holds user input
    double wrist = 0;   // holds user wrist
    double waist = 0;   // holds user waist
    double hip = 0; // holds female hip
    double forearm = 0; // holds female forearm
    double B = 0;   // holds body calculation
    double bodyFat = weight - B;    // holds calculated bodyFat
    double bodyFatPer = (bodyFat * 100) /weight;    //calculated percentage
    char gender;    // holds either m or f
    char choice;    // holds sentinel choice for file
    string fileName;    //holds user selected save name
    string name;    // hold's user's name for save file

    double A1 = 0; // holds formula depending on gender
    double A2 = 0; // holds formula depending on gender
    double A3 = 0; // holds formula depending on gender
    double A4 = 0; // holds formula depending on gender
    double A5 = 0; // holds formula depending on gender

    //  Questions held in variables
    //  Different questions for Male/Female
    string q1 = "Enter your weight: ";
    string q2 = "Enter your wrist measurement: ";
    string q3 = "Enter your waist measurement: ";
    string q4 = "Enter your hip measurement: ";
    string q5 = "Enter your forearm measurement: ";

    // GET gender
    cout << "Enter your Gender( M or F ): " ;
    cin >> gender;
    // Convert gender to uppercase for data validation
    gender = toupper(gender);

    // Validate data for either M or F
    if (( gender == 'F') || ( gender == 'M')) {

        // GET weight
        cout << q1;
        cin >> weight;

        // Validate user input for weight
        if ( weight < 0 || weight > 300){

            // if incorrect do not display/calculate
            cout << "ERROR - weight must be between 0 - 300 "
                    "\n";

        } else {

            if ( gender == 'F' ){

                // GET waist
                cout << q3;
                cin >> waist;
                // GET wrist
                cout << q2;
                cin >> wrist;
                // GET hip
                cout << q4;
                cin >> hip;
                // GET forearm
                cout << q5;
                cin >> forearm;

                // Calculate A and B/Bodyfat
                A1 = (weight * .732) + 8.987;
                A2 = (wrist / 3.14);
                A3 = (waist * .157);
                A4 = (hip * .249);
                A5 = (forearm * .434);
                B = A1 + A2 - A3 - A4 + A5;
                bodyFat = weight - B;
                bodyFatPer = (bodyFat * 100) / weight;

                // Display calculated results
                cout << setprecision(5);
                cout << "A1 = " << A1 << "\n" ;
                cout << "A2 = " << A2 << "\n";
                cout << "A3 = " << A3 << "\n";
                cout << "A4 = " << A4 << "\n";
                cout << "A5 = " << A5 << "\n";
                cout << "B = " << B << "\n";
                cout << setprecision(5);
                cout << "body fat = " << bodyFat << "\n";
                cout << setprecision(2);
                cout << "Body Fat Percentage = " << bodyFatPer << "%" << "\n";

            } else {

                // MALE CALULCATIONS

                // GET waist
                cout << q3 << "\n";
                cin >> waist;

                // Calculate A1 & A2 & BodyFat
                A1 = ( weight * 1.082 ) + 94.4;
                A2 = waist * 4.15;
                B = A1 - A2;
                bodyFat = weight - B;
                bodyFatPer = (bodyFat * 100) / weight;

                // Display calculated results
                cout << setprecision(5);
                /*cout << "A1 = " << A1 << "\n";
                cout << "A2 = " << A2 << "\n";
                cout << "B = " << B << "\n";*/
                cout << setprecision(5);
                cout << "bodyfat = " << bodyFat << "\n";
                cout << setprecision(2);
                cout << "Body Fat Percentage = " << bodyFatPer << "%" << "\n";

            } // end if-else 'F' or 'M'


        } //end else ( 2nd Layer )

    } else { // top of nested if statements

        cout << "ERROR - Must input either \"M\" or \"F\"" << "\n" ;

    } // end nested if statements

    if (( gender == 'F') || ( gender == 'M')) {

        // GET choice
        cout << "Would you like to save to a file? (Y or N): ";
        cin >> choice;
        // Validate user data by converting to upper-case
        choice = toupper(choice);

        // validate user data
        if ( choice == 'Y'){

            // GET name
            cout << "Enter your name: " << "\n";
            cin >> name;
            // GET fileName
            cout << "Enter the save name of the file: " << "\n" ;
            cin >> fileName;

            // create an ofstream myFile
            ofstream myFile;

            // use stream to create new file under variable fileName
            // output to file
            myFile.open(fileName.c_str() );

            // write name then bodyfatper to file
            myFile << name << "\n";
            myFile << setprecision(2);
            myFile << bodyFatPer << "%";

        } else {


        }

    } //end else


    return 0;

}//end main