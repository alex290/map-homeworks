#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <future>
#include <algorithm>

template <typename It, typename Fn>
void parallel_for_each(It begin, It end, Fn &&function)
{
    const auto diff = std::distance(begin, end);
    std::future<void> q;
    constexpr auto num_threads = 8;
    if (begin != end)
    {
        function(*begin);
        begin++;
        q = std::async(std::launch::async, [begin, end, function]
                       { parallel_for_each(begin, end, function); });
        q.wait();
    }
}

int main()
{
    std::vector<int> numb{15, 16, 2, 8, 7, 34};
    int numb_ret;
    auto print = [](const int &n)
    { std::cout << n << ", "; };
    parallel_for_each(numb.begin(), numb.end(), print);
    return 0;
}
