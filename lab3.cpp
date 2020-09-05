#include "lab3.h"
#include <windows.h>
#include <stdio.h>


using namespace std;

//����� ��������
HANDLE Mutex;

//������ ���������
HANDLE SemB, SemC, SemD, SemM, SemK, wait_interval, start_interval;

unsigned int lab3_thread_graph_id()
{
	return 3;
}

const char* lab3_unsynchronized_threads()
{
	return "defh";
}

const char* lab3_sequential_threads()
{
	return "bcd";
}

const char* lab3_additional_sequential_threads()
{
	return "mk";
}


DWORD WINAPI thread_a(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		// If dwMilliseconds is INFINITE, the function will return only when the object is signaled
		// ���� dwMilliseconds ����� �������� INFINITE, ������� �������� ������ �����, ����� ������ ������� ������
		// ����� ���� ������ ��������
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'a' << flush;
		ReleaseMutex(Mutex);
		computation();
	}
	return 0;
}

DWORD WINAPI thread_b(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'b' << flush;
		ReleaseMutex(Mutex);
		computation();
	}

	ReleaseSemaphore(wait_interval, 1, nullptr);    //������� �������� ����������
	WaitForSingleObject(start_interval, INFINITE);  //����� ����� ��������

	for (int i = 0; i < 4; i++) {

		WaitForSingleObject(SemB, INFINITE);
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'b' << flush;
		ReleaseMutex(Mutex);
		computation();
		ReleaseSemaphore(SemC, 1, nullptr);
	}

	return 0;
}

DWORD WINAPI thread_c(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(SemC, INFINITE);
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'c' << flush;
		ReleaseMutex(Mutex);
		computation();
		ReleaseSemaphore(SemD, 1, nullptr);
	}

	return 0;
}

DWORD WINAPI thread_d(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'd' << flush;
		ReleaseMutex(Mutex);
		computation();
	}

	ReleaseSemaphore(wait_interval, 1, nullptr);    //������� �������� ����������
	WaitForSingleObject(start_interval, INFINITE);  //����� ����� ��������

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(SemD, INFINITE);
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'd' << flush;
		ReleaseMutex(Mutex);
		computation();
		ReleaseSemaphore(SemB, 1, nullptr);
	}

	ReleaseSemaphore(wait_interval, 1, nullptr);    //������� �������� ����������
	WaitForSingleObject(start_interval, INFINITE);  //����� ����� ��������

	for (int i = 0; i < 4; ++i)
	{
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'd' << flush;
		ReleaseMutex(Mutex);
		computation();
	}


	return 0;
}

DWORD WINAPI thread_e(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'e' << flush;
		ReleaseMutex(Mutex);
		computation();
	}

	return 0;
}

DWORD WINAPI thread_g(LPVOID lpParam)
{
	for (int i = 0; i < 4; ++i)
	{
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'g' << flush;
		ReleaseMutex(Mutex);
		computation();
	}

	return 0;
}

DWORD WINAPI thread_h(LPVOID lpParam)
{
	for (int i = 0; i < 4; ++i)
	{
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'h' << flush;
		ReleaseMutex(Mutex);
		computation();
	}

	ReleaseSemaphore(wait_interval, 1, nullptr);    //������� �������� ����������
	WaitForSingleObject(start_interval, INFINITE);  //����� ����� ��������

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'h' << flush;
		ReleaseMutex(Mutex);
		computation();
	}

	ReleaseSemaphore(wait_interval, 1, nullptr);    //������� �������� ����������
	WaitForSingleObject(start_interval, INFINITE);  //����� ����� ��������

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'h' << flush;
		ReleaseMutex(Mutex);
		computation();
	}

	return 0;
}

DWORD WINAPI thread_f(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'f' << flush;
		ReleaseMutex(Mutex);
		computation();
	}

	ReleaseSemaphore(wait_interval, 1, nullptr);    //������� �������� ����������
	WaitForSingleObject(start_interval, INFINITE);  //����� ����� ��������

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'f' << flush;
		ReleaseMutex(Mutex);
		computation();
	}

	return 0;
}
DWORD WINAPI thread_i(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'i' << flush;
		ReleaseMutex(Mutex);
		computation();
	}

	return 0;
}
DWORD WINAPI thread_k(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'k' << flush;
		ReleaseMutex(Mutex);
		computation();
	}

	ReleaseSemaphore(wait_interval, 1, nullptr);    //������� �������� ����������
	WaitForSingleObject(start_interval, INFINITE);  //����� ����� ��������

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(SemK, INFINITE);
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'k' << flush;
		ReleaseMutex(Mutex);
		computation();
		ReleaseSemaphore(SemM, 1, nullptr);
	}

	return 0;
}
DWORD WINAPI thread_m(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(SemM, INFINITE);
		WaitForSingleObject(Mutex, INFINITE);
		cout << 'm' << flush;
		ReleaseMutex(Mutex);
		computation();
		ReleaseSemaphore(SemK, 1, nullptr);
	}

	return 0;
}




int lab3_init()
{
	Mutex = CreateMutex(NULL, FALSE, NULL);


	if (Mutex == NULL)
	{
		cout << "CreateMutex error " << GetLastError() << endl;
		return 1;
	}

	SemB = CreateSemaphore(NULL, 1, 1, NULL);
	if (SemB == NULL)
	{
		cout << "CreateSemaphore error: SemB" << GetLastError() << endl;
		return 1;
	}

	SemC = CreateSemaphore(NULL, 0, 1, NULL);
	if (SemC == NULL)
	{
		cout << "CreateSemaphore error: SemC" << GetLastError() << endl;
		return 1;
	}

	SemD = CreateSemaphore(NULL, 0, 1, NULL);
	if (SemD == NULL)
	{
		cout << "CreateSemaphore error: SemD" << GetLastError() << endl;
		return 1;
	}

	SemM = CreateSemaphore(NULL, 1, 1, NULL);
	if (SemM == NULL)
	{
		cout << "CreateSemaphore error: SemM" << GetLastError() << endl;
		return 1;
	}

	SemK = CreateSemaphore(NULL, 0, 1, NULL);
	if (SemK == NULL)
	{
		cout << "CreateSemaphore error: SemK" << GetLastError() << endl;
		return 1;
	}

	wait_interval = CreateSemaphore(NULL, 0, 3, NULL);
	if (wait_interval == NULL)
	{
		cout << "CreateSemaphore error: wait_interval" << GetLastError() << endl;
		return 1;
	}
	start_interval = CreateSemaphore(NULL, 0, 3, NULL);
	if (start_interval == NULL)
	{
		cout << "CreateSemaphore error: start_interval" << GetLastError() << endl;
		return 1;
	}

	HANDLE threadA, threadB, threadC, threadD, threadE, threadF, threadG, threadH, threadI, threadK, threadM;

	//1-� ��������

	threadA = CreateThread(nullptr, 0, thread_a, nullptr, 0, nullptr);
	if (threadA == nullptr) return GetLastError();

	threadB = CreateThread(nullptr, 0, thread_b, nullptr, 0, nullptr);
	if (threadB == nullptr) return GetLastError();

	threadD = CreateThread(nullptr, 0, thread_d, nullptr, 0, nullptr);
	if (threadD == nullptr) return GetLastError();


	WaitForSingleObject(threadA, INFINITE);                         //join with ended thread A
	WaitForSingleObject(wait_interval, INFINITE);                   //wait for thread B to finish
	WaitForSingleObject(wait_interval, INFINITE);					//wait for thread D to finish

	//2-�� ��������

	ReleaseSemaphore(start_interval, 1, nullptr);					//continue thread B
	ReleaseSemaphore(start_interval, 1, nullptr);					//continue thread D


	threadC = CreateThread(nullptr, 0, thread_c, nullptr, 0, nullptr);
	if (threadC == nullptr) return GetLastError();

	WaitForSingleObject(threadC, INFINITE);							//join with ended thread C
	WaitForSingleObject(threadB, INFINITE);							//join with ended thread B
	WaitForSingleObject(wait_interval, INFINITE);					//wait for thread D to finish

	//3-� ���������

	ReleaseSemaphore(start_interval, 1, nullptr);					//continue thread D

	threadF = CreateThread(nullptr, 0, thread_f, nullptr, 0, nullptr);
	if (threadF == nullptr) return GetLastError();

	threadE = CreateThread(nullptr, 0, thread_e, nullptr, 0, nullptr);
	if (threadE == nullptr) return GetLastError();

	threadH = CreateThread(nullptr, 0, thread_h, nullptr, 0, nullptr);
	if (threadH == nullptr) return GetLastError();

	WaitForSingleObject(threadD, INFINITE);							//join with ended thread D
	WaitForSingleObject(threadE, INFINITE);							//join with ended thread E
	WaitForSingleObject(wait_interval, INFINITE);                   //wait for thread F to finish
	WaitForSingleObject(wait_interval, INFINITE);					//wait for thread H to finish

	//4-� ��������

	ReleaseSemaphore(start_interval, 1, nullptr);					//continue thread F
	ReleaseSemaphore(start_interval, 1, nullptr);					//continue thread H

	threadG = CreateThread(nullptr, 0, thread_g, nullptr, 0, nullptr);
	if (threadG == nullptr) return GetLastError();

	WaitForSingleObject(threadG, INFINITE);							//join with ended thread G
	WaitForSingleObject(threadF, INFINITE);							//join with ended thread F

	WaitForSingleObject(wait_interval, INFINITE);					//wait for thread H to finish


	//5-�� ��������

	ReleaseSemaphore(start_interval, 1, nullptr);					//continue thread H
	threadI = CreateThread(nullptr, 0, thread_i, nullptr, 0, nullptr);
	if (threadI == nullptr) return GetLastError();
	threadK = CreateThread(nullptr, 0, thread_k, nullptr, 0, nullptr);
	if (threadK == nullptr) return GetLastError();
	WaitForSingleObject(threadH, INFINITE);							//join with ended thread H
	WaitForSingleObject(threadI, INFINITE);							//join with ended thread I
	WaitForSingleObject(wait_interval, INFINITE);					//wait for thread K to finish

	//6-�� ��������

	ReleaseSemaphore(start_interval, 1, nullptr);					//continue thread K

	threadM = CreateThread(nullptr, 0, thread_m, nullptr, 0, nullptr);
	if (threadM == nullptr) return GetLastError();

	WaitForSingleObject(threadM, INFINITE);							//join with ended thread M
	WaitForSingleObject(threadK, INFINITE);							//join with ended thread K


	//������������ ��������

	CloseHandle(threadA);
	CloseHandle(threadB);
	CloseHandle(threadC);
	CloseHandle(threadD);
	CloseHandle(threadE);
	CloseHandle(threadF);
	CloseHandle(threadG);
	CloseHandle(threadH);
	CloseHandle(threadI);
	CloseHandle(threadK);
	CloseHandle(threadM);

	CloseHandle(SemB);
	CloseHandle(SemC);
	CloseHandle(SemD);
	CloseHandle(SemM);
	CloseHandle(SemK);
	CloseHandle(wait_interval);
	CloseHandle(start_interval);
	CloseHandle(Mutex);
	cout << endl;
	return 0;
}