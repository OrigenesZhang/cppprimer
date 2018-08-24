#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> vec;
    std::string now;
    while (std::cin >> now)
        vec.push_back(now);
    std::sort(vec.begin(), vec.end());
    int max = 0, cnt = 0;
    now = "";
    std::string ans;
    auto cur = vec.begin();
    // If multiple words appear for max times, the first one would be displayed
    while (cur != vec.end()) {
        if (*cur != now) {
            if (cnt > max) {
                max = cnt;
                ans = now;
            }
            cnt = 1;
            now = *cur;
        } else {
            cnt++;
        }
        ++cur;
    }
    if (cnt > max) {
        max = cnt;
        ans = now;
    }
    if (max <= 1) {
        std::cout << "No duplicates." << std::endl;
    } else {
        std::cout << ans << " appeared for " << max << " times." << std::endl;
    }
    return 0;
}