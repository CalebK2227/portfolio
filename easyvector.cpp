#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    vector<int> g1; 
    int n;
    cout << "Input n:\n";
    cin >> n;
    for(int i = 1; i <= n; i++)
        g1.push_back(i);
    cout << "numbers from one to " << n << " are: ";
    for(auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << " ";

}