#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> vec;
    int num;
    while (cin >> num)
        vec.push_back(num);
    for (auto &it : vec)
        it % 2 == 1 ? it *= 2 : 1;
    for (auto it : vec)
        cout << it << ' ';
    cout << endl;
    return 0;
}