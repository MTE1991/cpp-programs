#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> num;
    for (int i=0; i < 10; i++)
        num.push_back(i);
    for (int i=0; i < 10; i++)
        cout << num[i] << " ";
    return 0;
}
