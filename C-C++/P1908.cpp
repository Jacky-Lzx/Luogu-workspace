#include <iostream>
#include <vector>

using namespace std;

int insert(vector<int> &array, int number)
{
//    std::vector<int>::iterator temp = array.begin();
    auto temp = array.begin();
    for(int i = 0; i < array.size(); i++)
    {
        if (array.at(i) > number)
        {
            array.insert(temp,number);
            return array.size() - i - 1;
        }
        temp++;
    }
    array.push_back(number);
    return 0;
}

int main()
{
    int n;
    cin >> n;

    vector<int> array;
    int temp;
    cin >> temp;
    array.push_back(temp);

    int count = 0;
    int input;
    for (int i = 1; i < n; i++)
    {
        cin >> input;
        count += insert(array, input);
    }
    cout << count << endl;

    //each time a new number is input, compare it with the least number before, then the second least...
    //new number will be inserted into the array with the correct order(increasing or decreasing)


}