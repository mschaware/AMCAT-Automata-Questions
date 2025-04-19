#include <iostream>
#include <string>
using namespace std;

char findLostChar(const string& stringSent, const string& stringRec) {
    int i = 0, j = 0;

    // Traverse both strings
    while (i < stringSent.size() && j < stringRec.size()) {
        if (stringSent[i] != stringRec[j]) {
            // Found the missing character
            return stringSent[i];
        }
        i++;
        j++;
    }

    // If no mismatch is found, the missing character is at the end of stringSent
    return stringSent[i];
}

int main() {
    string stringSent, stringRec;

    // Input for stringSent
    getline(cin, stringSent);

    // Input for stringRec
    getline(cin, stringRec);

    char missingChar = findLostChar(stringSent, stringRec);
    cout << "Missing Character: " << missingChar << endl;

    return 0;
}
