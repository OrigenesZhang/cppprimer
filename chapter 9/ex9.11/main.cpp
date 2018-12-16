#include <vector>

int main() {
    std::vector<int> v1;
    std::vector<int> v2(v1);
    std::vector<int> v3 = v2;
    std::vector<int> v4{1, 2};
    std::vector<int> v5 = {1, 2};
    std::vector<int> v6(v5.begin(), v5.end());
    return 0;
}