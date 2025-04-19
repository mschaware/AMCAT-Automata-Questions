#include<bits/stdc++.h>
using namespace std;
int main()
{
    int base, exponent;
    cout << "Enter base and exponent: ";    
    cin >> base >> exponent;
    int result = 1; // Initialize result to 1
    for(int i=0;i<exponent;i++)
    {
        result *= base; // Multiply result by base in each iteration
    }
    cout << "Result: " << result << endl; // Output the final result    
}