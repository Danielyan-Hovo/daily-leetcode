#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
int binary_search(std::vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr.at(mid) == target) return mid;
    if (arr.at(mid) < target) {

        left = mid + 1;
    } else {

        right = mid - 1;
    }
}
return -1;
}
template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}
void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int main() {
    std::vector<int> arr = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    int res = binary_search(arr, target);
    std::cout << res << '\n';
}