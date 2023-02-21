/*
File name: fibonacci.cpp
Project 1: Part 2
Q: 3.3: Implement a program that runs and gives timings for the two Fibonacci sequence
functions provided in Exercise 2.11. Graph the resulting running
times for as many values of n as your computer can handle.
Date: 10/9/18
*/

#include<iostream>
#include<assert.h>
#include<chrono>

using namespace std;

typedef chrono::high_resolution_clock Clock;

long fibr(int n) // Recursive Fibonacci generator 
{ 
	assert((n > 0) && (n < 10000));
	if ((n == 1) || (n == 2)) return 1; // Base cases
	return fibr(n - 1) + fibr(n - 2); // Recursion
}

long fibi(int n) // Iterative Fibonacci generator
{ 
	assert((n > 0) && (n < 1000000000000));
	long past, prev, curr; // Store temporary values
	past = prev = curr = 1; // initialize
	for (int i = 3; i <= n; i++) { // Compute next value
		past = prev; // past holds fibi(i-2)
		prev = curr; // prev holds fibi(i-1)
		curr = past + prev; // curr now holds fibi(i)
	}
	return curr;
}

void usermenu(int &k, int &n)
{
	cout << "Choose the algorithm:\n 1.Recursive\n 2.Iterative\n\nChoosing: ";
	cin >> k;
	cout << "\nEnter the size of Fibonacci sequence: ";
	cin >> n;
}

// Display the Fibonacci Sequence
/*
void displaysequence(int k, int n)
{
	if (k == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << fibr(i);
			if (i != n)
				cout << ", ";
		}
	}
	else if (k == 2)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << fibr(j);
			if (j != n)
				cout << ", ";
		}
	}
	cout << endl;
}
*/

int main()
{
	int n = 0, k = 0;

	usermenu(k, n);

	//displaysequence(k, n);

	cout << "\nRuntime: ";
	if (k == 1) // Timing the recursive Fibonacci sequence
	{
		auto begin = Clock::now();
		fibr(n); // Highest n value attempted: 50 = 301 sec.
		auto stop = Clock::now();
		cout << chrono::duration_cast<chrono::nanoseconds>(stop - begin).count() << " nano sec.\n";
	}
	else if (k == 2) // Timing the iterative Fibonacci sequence
	{
		auto begin = Clock::now();
		fibi(n); // Highest n value attempted: 1,000,000,000 = 2 sec.
		auto stop = Clock::now();
		cout << chrono::duration_cast<chrono::nanoseconds>(stop - begin).count() << " nano sec.\n";
	}

	cout << endl;
	system("pause");
	return 0;
}
