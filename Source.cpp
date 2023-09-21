#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <map>
#include <iomanip>

using namespace std;

string message;

void read_from_file()
{
    char line[100];
    string file_name;
    int lines = 0;
    fstream fin;
    cout << " Enter The Name of File with .txt : ";
    cin >> file_name;
    fin.open(file_name.c_str());

    if (!fin) {
        cout << file_name << " file does not exist ..." << endl;
        exit(0);  // exite and end the programming 
    }

    while (fin.eof() == 0)
    {
        fin.getline(line, sizeof(line));
        message += line;
    }

    fin.close();
    cout << message << endl;
}

void check_spam()
{
    int total = 0, con = 0;
    string box = "";
    vector<string> y;
    map<string, int> x;


    string words[30] = { "amazon", "official", "bank", "security", "urgent", "alert",
     "important", "information", "ebay", "password", "credit", "verify",
     "confirm", "account", "bill", "immediately", "address", "telephone",
     "ssn", "charity", "check", "secure", "personal", "confidential",
     "atm", "warning", "fraud", "citibank", "irs", "paypal" };

    int numbers[30] = { 2, 2, 1, 1, 1, 1, 1, 2,
      3, 3, 3, 1, 1, 1, 1, 1, 2, 2, 3, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1 };

    map<string, int>::iterator itr;


    for (int i = 0; i < 30; i++)
    {
        x.insert(pair<string, int>(words[i], numbers[i]));
    }

    cout << "KEY\t\t\tELEMENT\n";
    for (itr = x.begin(); itr != x.end(); ++itr) {
        cout  << itr->first << setw(30) << itr->second
            << '\n';
    }
    cout << endl;


    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] != ' ')
        {
            box += message[i];

        }
        else
        {
            y.push_back(box);
            box = "";


        }
    }
    y.push_back(box);
    for (size_t i = 0; i < 30; i++)
    {
        for (size_t j = 0; j < y.size(); j++) {
            if (words[i] == y[j])
            {
                total += numbers[i];
                con++;
            }
        }
    }




    cout << con << endl;
    cout << total << endl;

}
int main()
{
    
    
    
    read_from_file();
    check_spam();


    

}