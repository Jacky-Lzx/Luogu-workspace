#include <iostream>
#include <string>
using namespace std;

int main()
{
    int k1, k2, k3;
    cin >> k1;
    cin >> k2;
    cin >> k3;

    string raw;
    cin >> raw;

    int length = raw.length();
    //start from the second char
    for (int i = 1; i < length; i++)
    {
        if (raw.at(i) == '-')
        {
            int start = i - 1;
            int end = i + 1;

            //if 'd-d' was input
            if (raw.at(start) >= raw.at(end))
            continue;

            int insertLength = (int)raw.at(end) - (int)raw.at(start) - 1;
            string insertString;
            for (int j = 0; j < insertLength; j++)
            {
                insertString.push_back(raw.at(start) + 1 + j);
            }

            cout << raw.substr(0);

//            cout << insertString;
        }
    }

}