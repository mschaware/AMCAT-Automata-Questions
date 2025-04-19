#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<char> getDesktopProductIDs() {
    // Define all productIDs and laptop productIDs
    set<char> allProductIDs;
    for (char c = 'a'; c <= 'z'; ++c) allProductIDs.insert(c);  // Lowercase
    for (char c = 'A'; c <= 'Z'; ++c) allProductIDs.insert(c);  // Uppercase
    
    set<char> laptopProductIDs = {'a', 'i', 'e', 'o', 'u', 'A', 'I', 'E', 'O', 'U'};
    
    // Result container for desktop productIDs
    vector<char> desktopProductIDs;
    
    // Identify desktop products
    for (char id : allProductIDs) {
        if (laptopProductIDs.find(id) == laptopProductIDs.end()) { // If not a laptop product
            desktopProductIDs.push_back(id);
        }
    }
    
    return desktopProductIDs;
}

int main() {
    vector<char> desktopIDs = getDesktopProductIDs();
    
    cout << "Desktop productIDs are: ";
    for (char id : desktopIDs) {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}
/*
#include <iostream>
#include <vector>
using namespace std;

vector<char> getDesktopProductIDs() {
    vector<char> desktopProductIDs;  // To store desktop productIDs

    // Loop through all lowercase and uppercase letters
    for (char c = 'a'; c <= 'z'; ++c) {
        // Check if the current productID is a vowel (laptop product)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            continue;  // Skip laptop productIDs
        }
        desktopProductIDs.push_back(c);  // Add to desktop products
    }

    for (char c = 'A'; c <= 'Z'; ++c) {
        // Check if the current productID is a vowel (laptop product)
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            continue;  // Skip laptop productIDs
        }
        desktopProductIDs.push_back(c);  // Add to desktop products
    }

    return desktopProductIDs;
}

int main() {
    vector<char> desktopIDs = getDesktopProductIDs();

    // Output the desktop productIDs
    cout << "Desktop productIDs are: ";
    for (char id : desktopIDs) {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}

*/