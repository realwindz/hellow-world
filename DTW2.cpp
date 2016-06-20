// ConsoleApplication15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
# include <iostream>
# include <chrono>
# include <cstdlib>
# include <cstring>
#include <cmath>
using namespace std;
using  ns = chrono::nanoseconds;
using get_time = chrono::steady_clock;

double tripleMin(double d1, double d2, double d3){
	double dt = (double)0.0;
	if (d1<d2)
		dt = d1;
	else{
		dt = d2;
	}
	return dt<d3 ? dt : d3;

}
//Simply DTW using array. It should be fine when the len is very small and array is very fast for using.
double DTW(double *v1, double *v2, int len_v1, int len_v2) {
	double cost;
	double INF = std::numeric_limits<double>::max();
	double** DTW = (double **)malloc(sizeof(double*)*(len_v1 + 1));
	for (int i = 0; i<len_v1 + 1; i++){
		DTW[i] = (double*)malloc(sizeof(double)*(len_v2 + 1));
		std::memset((void*)DTW[i], 0, (len_v2 + 1)*sizeof(double));
	}
	for (int i = 1; i <= len_v1; i++) {
		DTW[0][i] = INF;
	}
	for (int i = 1; i <= len_v2; i++) {
		DTW[i][0] = INF;
	}
	DTW[0][0] = 0;

	for (int i = 0; i < len_v1; i++) {
		for (int j = 0; j <len_v2; j++) {

			cost = abs(v1[i] - v2[j]);
			DTW[i + 1][j + 1] = cost + tripleMin(DTW[i][j + 1], DTW[i + 1][j], DTW[i][j]);
		}
	}
	double ret = DTW[len_v1][len_v2];
	for (int i = 0; i<len_v1 + 1; i++){
		std::free(DTW[i]);
	}
	free(DTW);
	return ret;
}
int _tmain()
{
	auto start = get_time::now();
	//For generating 2*63 random double  numbers range of (1.0~200.0);
	/*double *vec1 = (double*)std::malloc(sizeof(double)* 63);
	double *vec2 = (double*)std::malloc(sizeof(double)* 63);
	srand(0221);
	int left = 0;
	for (int i = 0; i<63; i++){
		left = rand() % 200000 + 1;
		vec1[i] = (double)left / (double)1000;
		left = rand() % 200000 + 1;
		vec2[i] = (double)left / (double)1000;
	}*/
	double vec1[] = {3,4,5,2,1,3,5,8,3,4};
	double vec2[] = {3,4,5,2,1,3,5,8,3,4};
	int left = 0;
	// random numer generating ends
	for (int i = 0; i < 40000; i++){
		DTW(vec1, vec2, 10, 10);
	}
	auto end = get_time::now();
	auto diff = end - start;
	cout << "Elapsed time is :  " << chrono::duration_cast<ns>(diff).count() << " ns " << endl;
//	free(vec1);
//	free(vec2);
	cin >> left;
	return 0;
}


