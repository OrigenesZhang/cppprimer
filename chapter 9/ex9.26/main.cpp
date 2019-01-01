#include <iostream>
#include <list>
#include <vector>

int main() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    std::list<int> lis(std::begin(ia), std::end(ia));
    std::vector<int> vec(std::begin(ia), std::end(ia));
    for (auto it = lis.begin(); it != lis.end(); )
        if (*it % 2)
            it = lis.erase(it);
        else
            ++it;
    for (auto it = vec.begin(); it != vec.end(); )
        if (*it % 2)
            ++it;
        else
            it = vec.erase(it);
    for (auto it : lis)
        std::cout << it << ' ';
    std::cout << std::endl;
    for (auto it : vec)
        std::cout << it << ' ';
    std::cout << std::endl;
    return 0;
}