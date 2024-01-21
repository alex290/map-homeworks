#include <iostream>
#include <chrono>
#include <thread>



int main()
{
    int count_client{0};
    std::thread t1(client, std::ref(count_client), 5);
	std::thread t2(operators, std::ref(count_client));

    t1.join();

    return 0;
}
