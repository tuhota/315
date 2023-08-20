#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <omp.h>

using namespace std::chrono;
using namespace std;

void randomVector(int vector[], int size)
{
	#pragma omp parallel for
	for (int i = 0; i < size; i++)
	{
		//generate random data
		vector[i] = rand() % 100;
	}
}

int main() {

	unsigned long size = 100000000;

	srand(time(0));

	int *v1, *v2, *v3;

	//start timer
	auto start = high_resolution_clock::now();

	//allocate memory
	v1 = (int *)malloc(size * sizeof(int *));
	v2 = (int *)malloc(size * sizeof(int *));
	v3 = (int *)malloc(size * sizeof(int *));

	#pragma omp parallel 
	{
		randomVector(v1, size);
	}

	#pragma omp parallel 
	{
		randomVector(v2, size);
	}

	#pragma omp parallel for 
	for (int i = 0; i < size; i++)
	{
		v3[i] = v1[i] + v2[i];
	}

	auto stop = high_resolution_clock::now();

	//stop timer
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "
	 << duration.count() << " microseconds" << endl;

	free(v1);
	free(v2);
	free(v3);

	return 0;
}
