// Utility.cpp
#include "Utility.h"
#include <iostream>
#include <limits>
#include <cstdarg>
#include <random>
#include <chrono>
#include <thread>


void Utility::ClearConsole() {
#ifdef _WIN32
    system("cls");
#else
    (void)system("clear");
#endif
}

void Utility::WaitForEnter() {
    ClearInputBuffer();
    Wait(1);
    PrintToConsole(true, "Press enter to continue");
    std::cin.get();
}

void Utility::ClearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool Utility::TestAgainstProb(float probability)
{
    std::random_device rd;  // Non-deterministic seed
    std::mt19937 gen(rd()); // Mersenne Twister PRNG
    std::uniform_int_distribution<int> dist(1, 100);

    int result = dist(gen);
    if (result > probability * 100)
    {
        return false;
    }
    return true;
}

int Utility::ChooseInRange(int start, int end)
{

    std::random_device rd;  // Non-deterministic seed
    std::mt19937 gen(rd()); // Mersenne Twister PRNG
    std::uniform_int_distribution<int> dist(start, end);
    int result = dist(gen);
    return result;

}

std::string Utility::RecieveInput()
{
    std::string buffer;
    std::cin >> buffer;
    return buffer;
}

void Utility::Wait(float seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds((long long)seconds));
}

