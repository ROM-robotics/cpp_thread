#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

int myAmount=0;
void addMoney()
{
    m.lock();
    ++myAmount;
    m.unlock();
}

int main(void)
{
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    std::cout << myAmount << std::endl;
    return 0;

}