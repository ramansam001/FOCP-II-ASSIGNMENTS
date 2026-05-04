#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string name;

    // List of funny roast messages
    vector<string> roasts = {
        "You run slower than free WiFi!",
        "Your brain has too many tabs open.",
        "You are proof that even Google can't solve everything.",
        "You shine... but only when electricity fails.",
        "You bring everyone happiness... when you leave the room.",
        "You are like a cloud. When you disappear, it's a beautiful day.",
        "Your secrets are always safe with me. I never listen anyway.",
        "You are not lazy, just on energy-saving mode."
    };

    // Take user input
    cout << "Enter your name: ";
    getline(cin, name);

    // Random roast selection
    srand(time(0));
    int randomIndex = rand() % roasts.size();

    // Display result
    cout << "\nHello " << name << "!\n";
    cout << "Roast of the day: " << roasts[randomIndex] << endl;

    return 0;
}