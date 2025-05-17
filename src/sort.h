#ifndef SORT_H
#define SORT_H
#include <string>
#include "flight.h"
#include <fstream>
#include <algorithm> // std::sort
#include <chrono>
void parseCSV(std::string filename, int N, Flight *result);
template<class T>
void bubbleSort(T* a, int N);
template<class T>
void shakerSort(T* a, int N);
template<class T>
void quickSort(T *a, long N);
#endif