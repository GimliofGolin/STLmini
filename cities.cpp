#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{


    // Open the inFile file
    ifstream inFile("cities.txt");
    if (!inFile.is_open())
    {
        cout << "Failed to open file." << endl;
        return 1;
    }

    // Read the state/city pairs from the inFile file
    unordered_map<string, vector<string>> state_cities;
    string line;
    while (getline(inFile, line))
    {
        stringstream ss(line);
        string state, city;
        getline(ss, state, ',');
        getline(ss, city);
        state_cities[state].push_back(city);
        cout << state << endl;
    }
    cout << "---------------------------------------------------------" << endl;

    // Count the cities for each state in the command line arguments
    for (int i = 1; i < argc; i++)
    {
        string state = argv[i];
        cout << "\n" << state << endl;
        if (state_cities.count(state) == 0)
        {
            // State not found, output 0
            cout << "0" << endl;
        } else
        {
            // State found, output the number of cities
            cout << state_cities[state].size() << endl;
        }
    }

    return 0;
}
