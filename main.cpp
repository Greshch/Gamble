#include "Gamble.h"
#include <Windows.h>
#include <iostream>
#include <chrono>

typedef std::pair<std::string, int> UsersData;

CRITICAL_SECTION g_lock;
Gamble g_gamble;


DWORD  WINAPI Derived(LPVOID lpThreadParameter) {
	UsersData tmp = *static_cast<UsersData*>(lpThreadParameter);
	EnterCriticalSection(&g_lock);
	g_gamble.MakePrediction(tmp.first, tmp.second);
	LeaveCriticalSection(&g_lock);

	return 0;
}

int main() {
	InitializeCriticalSection(&g_lock);
	int guess = g_gamble.GetSecret();
	UsersData data;
	
	time_t const liveTime = 2 * 2;
	auto begin = std::chrono::system_clock::now();
	time_t beginTime = std::chrono::system_clock::to_time_t(begin);
	time_t curTime = std::chrono::system_clock::to_time_t(begin);
	time_t endTime = beginTime + liveTime;

	auto tmp = std::chrono::system_clock::now();
	for (time_t curTime = beginTime; curTime <= endTime; ) {
		std::string name;
		std::cout << "Type your name : ";
		std::cin >> name;
		tmp = std::chrono::system_clock::now();
		curTime = std::chrono::system_clock::to_time_t(tmp);
		if (curTime > endTime) {
			break;
		}

		int num;
		std::cout << "Type expected num : ";
		std::cin >> num;
		tmp = std::chrono::system_clock::now();
		curTime = std::chrono::system_clock::to_time_t(tmp);
		if (curTime > endTime) {
			break;
		}
		
		EnterCriticalSection(&g_lock);
		data.first = name;
		data.second = num;
		LeaveCriticalSection(&g_lock);

		HANDLE threadHandle = CreateThread(
			0,
			0,
			Derived,
			&data,
			0,
			0
		);

		if (WaitForSingleObject(threadHandle, INFINITE) == WAIT_FAILED) {
			std::cerr << "Wait's object error...\n";
			return 1;
		}
		CloseHandle(threadHandle);
	}

	std::cout << "\n\nCongraulations, " << g_gamble.GetWinner() << "!\tsecret = " 
		<< g_gamble.GetSecret() << std::endl;

	DeleteCriticalSection(&g_lock);
	return 0;
}