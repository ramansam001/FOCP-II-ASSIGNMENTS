#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

int main()
{
    string name;

    // Ask user for student name
    cout << "===== Student Excuse Generator =====" << endl;
    cout << "Enter student name: ";
    getline(cin, name);

    // Vector storing funny excuses with {name} placeholder
    vector<string> excuses = {
        "{name} was late because the alarm clock joined a protest.",
        "{name} missed class because the dog ate the timetable.",
        "{name} couldn't submit homework because WiFi needed rest.",
        "{name} was absent because the pillow refused to let go.",
        "{name} forgot the assignment in another dimension.",
        "{name} was delayed because traffic was controlled by turtles.",
        "{name} missed lecture because coffee machine broke down.",
        "{name} could not attend because shoes went missing.",
        "{name} was late because the bus took a tea break.",
        "{name} forgot notes because memory was under maintenance."
    };

    /*
    BUG EXAMPLE:
    If we do not use srand(time(0));
    rand() gives same sequence every run,
    so same excuse may repeat.

    FIX:
    Use srand(time(0));
    */

    srand(time(0));   // Fix for repeating same excuse

    // Generate random index
    int index = rand() % excuses.size();

    // Select random excuse
    string finalExcuse = excuses[index];

    // Replace {name} with actual user name
    int pos = finalExcuse.find("{name}");
    if (pos != string::npos)
    {
        finalExcuse.replace(pos, 6, name);
    }

    // Display final result
    cout << "\nGenerated Excuse:\n";
    cout << finalExcuse << endl;

    return 0;
}