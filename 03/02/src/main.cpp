#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <future>
#include <algorithm>

template <typename It, typename Fn>
void parallel_for_each(It begin, It end, Fn &&function)
{
    const size_t block_size = 4;
    size_t diff = static_cast<size_t>(std::distance(begin, end));
    // std::cout << "diff: " << diff << std::endl;
    std::future<void> q;
    if (diff > 0)
    {
        size_t size = diff;

        // Если размер превышает размер то дели на 2
        if (diff > block_size)
        {
            size = size / 2;
        }


        for (size_t i = 0; i < size; i++)
        {
            function(*begin);
            begin++;
        }

        if (diff > block_size)
        {
            q = std::async(std::launch::async, [begin, end, function]
                           { parallel_for_each(begin, end, function); });
            q.wait();
        }
    }
}

int main()
{
    std::vector<int> numb{15, 16, 2, 8, 7, 34};
    int numb_ret;
    auto print = [](const int &n)
    { std::cout << n << ", "; };
    parallel_for_each(numb.begin(), numb.end(), print);
    std::cout << std::endl;
    return 0;
}
