#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>

void setProgress(int position, int ms)
{
    for (size_t i = 0; i < position; i++)
    {
        std::cout << "\n";
    }

    float progress = 0.0;
    while (progress <= 1.0)
    {
        int barWidth = 70;
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));

        std::cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i)
        {
            if (i <= pos)
                std::cout << char(219);
            else
                std::cout << " ";
        }
        std::cout << "] " << int(progress * 100.0) << " %";
        std::cout << "\r";
        // for (size_t i = 0; i < position; i++)
        // {
        //     std::cout << "\r";
        // }
        // std::cout.flush();

        progress += 0.01; // for demonstration only
    }
}

int main()
{

    std::cout << "#\t Progress bar \t\t\t time" << std::endl;

    std::thread j1(setProgress, 0, 50);
    std::thread j2(setProgress, 2, 30);

    j1.join();
    j2.join();

    std::cout << std::endl;

    return 0;
}
