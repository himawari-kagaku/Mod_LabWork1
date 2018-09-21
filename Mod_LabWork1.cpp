// Mod_LabWork1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <algorithm>

#define _USE_MATH_DEFINES
#include <math.h>

#include "ExpressCalculation.h"
#include "StandardCalculation.h"

using namespace std;

//-----------------------------------------------
// Lemer random algorithm
//-----------------------------------------------
double LemerRand()
{
	static double R = 4294965757; // 3571 3574
	const uint32_t a = 4294967279; // 4200000000
	const uint32_t m = 2147483629; // 2100000000

	
	R = fmod(a * R, m);

	return R/m;
}

//-----------------------------------------------
// Indirect test
//-----------------------------------------------
void IndirectTest(vector<double> xs)
{
	// Проверка по косвенным признакам
	double count = 0;
	for (int i = 0; i < xs.size(); i += 2)
	{
		double x12 = pow(xs[i], 2);
		double x22 = pow(xs[i + 1], 2);
		if (x12 + x22 < 1) count++;
	}
	cout << "Actual = " << 2 * count / xs.size() << " expected = " << M_PI / 4 << endl;
}

int main()
{
	double evExpress;
	double varExpress;
	vector<double> xs;
	const uint32_t sampleSize = 1000000;

	ExpressCalculation ec;

	for (int i = 0; i < sampleSize; i++)
	{
		double x = LemerRand();
		ec.Input(x);
		varExpress = ec.D;
		evExpress = ec.m;
		xs.push_back(x);
	}

	cout << "EV express = " << evExpress << endl;
	cout << "EV stand   = " << StandardCalculation::ExpectedValue(xs) << endl;
	cout << "VAR express = " << varExpress << endl;
	cout << "VAR stand   = " << StandardCalculation::Variance(xs) << endl;


	auto it = max_element(xs.begin(), xs.end());
	double max = *it;
	it = min_element(xs.begin(), xs.end());
	double min = *it;
	double rVar = max - min;
	double delta = rVar / 10;

	//HistogramTest(xs); TODO: Show histogram
	IndirectTest(xs);

	system("pause");
    return 0;
}















// Auxiliary
int checkPrimeNumber(int64_t);

int checkPrimeNumber(int64_t n)
{
	bool flag = false;

	for (int64_t i = 2; i <= n / 2; ++i)
	{
		if (n%i == 0)
		{
			flag = true;
			break;
		}
	}
	return flag;
}

void findPrime(int64_t min, int64_t max)
{
	for (int64_t num = min; num < max; num++)
		for (int64_t j = 2; j*j <= num; j++)
		{
			if (num % j == 0)
				break;
			else if (j + 1 > sqrt(num)) {
				cout << num << " is prime " << bitset<32>(num) << endl;

			}

		}
}
