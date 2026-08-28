#include <iostream>
#include <string>
using namespace std;

int main()
{
    string developerName;
    string projectName;

    cout << "C++ Application Setup Check" << endl;
    cout << "---------------------------" << endl;

    cout << "Enter your name: ";
    getline(cin, developerName);

    cout << "Enter the name of your application: ";
    getline(cin, projectName);

    cout << endl;
    cout << "Developer: " << developerName << endl;
    cout << "Project: " << projectName << endl;
    cout << "Development environment is configured successfully." << endl;
    cout << "Project is ready for future modules." << endl;

    return 0;
}
