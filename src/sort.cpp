#include "sort.h"
/**
 * @file sort.cpp 
 * @brief Implementation of sorting algorithms and CSV parsing
 *
 * Contains:
 * - parseCSV() function for reading flight data from CSV files
 * - Template implementations of:
 *   - Bubble Sort
 *   - Shaker Sort (Cocktail Sort) 
 *   - Quick Sort
 * - Main function with performance benchmarking
 */
/**
 * Parses a CSV file containing flight data and stores the results in an array of Flight objects.
 * 
 * @param filename The path to the CSV file.
 * @param N The maximum number of entries to read.
 * @param result Pointer to the array where Flight objects will be stored.
 */
void parseCSV(std::string filename, int N, Flight* result) {
    std::ifstream in(filename);
    std::string line, flight_number_, airline_, arrival_date_, arrival_time_;
    int i1 = 0, i2 = 0, i3 = 0, i4 = 0, i = 0, passengers_;

    if (in.is_open()) {
        while (std::getline(in, line) && i < N) {
            // Locate the positions of commas to separate CSV fields
            for (int i = 0; i < (int)line.size(); i++) {
                if (line[i] == ',') {
                    if (i1 == 0) i1 = i;
                    else if (i2 == 0) i2 = i;
                    else if (i3 == 0) i3 = i;
                    else if (i4 == 0) i4 = i;
                }
            }

            // Extract fields using the comma positions
            flight_number_ = line.substr(0, i1);
            airline_ = line.substr(i1 + 1, i2 - i1 - 1);
            arrival_date_ = line.substr(i2 + 1, i3 - i2 - 1);
            arrival_time_ = line.substr(i3 + 1, i4 - i3 - 1);
            passengers_ = std::stoi(line.substr(i4 + 1, line.size() - i4 - 2));

            // Reset comma position trackers for the next line
            i1 = 0;
            i2 = 0;
            i3 = 0;
            i4 = 0;

            // Create a Flight object and store it in the result array
            Flight f(flight_number_, airline_, arrival_date_, arrival_time_, passengers_);
            result[i++] = f;
        }
        in.close();
    }
}

/**
 * Sorts an array in descending order using the Bubble Sort algorithm.
 * 
 * @tparam T The type of elements in the array.
 * @param a Pointer to the array to be sorted.
 * @param N The number of elements in the array.
 */
template<class T>
void bubbleSort(T* a, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = N - 1; j > i; --j) {
            if (a[j - 1] < a[j]) {
                std::swap(a[j - 1], a[j]);
            }
        }
    }
}

/**
 * Sorts an array in descending order using the Shaker Sort (Bidirectional Bubble Sort) algorithm.
 * 
 * @tparam T The type of elements in the array.
 * @param a Pointer to the array to be sorted.
 * @param N The number of elements in the array.
 */
template<class T>
void shakerSort(T* a, int N) {
    int lb = 0;         // Lower bound
    int ub = N - 1;     // Upper bound
    int k;              // Tracks the last swap position

    do {
        k = 0;
        // Pass from right to left
        for (int j = ub; j > lb; --j) {
            if (a[j - 1] < a[j]) {
                std::swap(a[j - 1], a[j]);
                k = j;
            }
        }
        lb = k;

        // Pass from left to right
        for (int j = lb; j < ub; ++j) {
            if (a[j] < a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                k = j;
            }
        }
        ub = k;
    } while (lb < ub);
}

/**
 * Sorts an array in descending order using the Quick Sort algorithm.
 * 
 * @tparam T The type of elements in the array.
 * @param a Pointer to the array to be sorted.
 * @param N The number of elements in the array.
 */
template<class T>
void quickSort(T* a, long N) {
    long i = 0, j = N - 1;      // Initialize bounds
    T p = a[N >> 1];            // Pivot: middle element

    // Partitioning phase
    do {
        while (i < N && a[i] > p) i++;
        while (j >= 0 && a[j] < p) j--;

        if (i <= j) {
            std::swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);

    // Recursively sort the partitions
    if (j > 0) quickSort(a, j + 1);
    if (N > i) quickSort(a + i, N - i);
}

int main() {
    std::ofstream out("/Users/anastasiatrufanova/Desktop/lab1_sorting_algorithms/plt/results.csv");
    out << "Size,BubbleSort,ShakerSort,QuickSort,StdSort\n";

    std::vector<std::string> filenames = {
        "100.csv",
        "200.csv",
        "500.csv",
        "1000.csv",
        "2000.csv",
        "5000.csv",
        "10000.csv",
        "20000.csv",
        "50000.csv",
        "75000.csv"
    };

    std::string path = "/Users/anastasiatrufanova/Desktop/lab1_sorting_algorithms/data/";

    for (int i = 0; i < 10; ++i) {
        std::string full_path = path + filenames[i];
        int N = std::stoi(filenames[i].substr(0, filenames[i].size() - 4));
        Flight* original = new Flight[N];
        parseCSV(full_path, N, original);

        // --- Bubble Sort ---
        Flight* a1 = new Flight[N];
        std::copy(original, original + N, a1);
        auto t1_start = std::chrono::high_resolution_clock::now();
        bubbleSort(a1, N);
        auto t1_end = std::chrono::high_resolution_clock::now();
        double t_bubble = std::chrono::duration<double, std::milli>(t1_end - t1_start).count();
        delete[] a1;

        // --- Shaker Sort ---
        Flight* a2 = new Flight[N];
        std::copy(original, original + N, a2);
        auto t2_start = std::chrono::high_resolution_clock::now();
        shakerSort(a2, N);
        auto t2_end = std::chrono::high_resolution_clock::now();
        double t_shaker = std::chrono::duration<double, std::milli>(t2_end - t2_start).count();
        delete[] a2;

        // --- Quick Sort ---
        Flight* a3 = new Flight[N];
        std::copy(original, original + N, a3);
        auto t3_start = std::chrono::high_resolution_clock::now();
        quickSort(a3, N);
        auto t3_end = std::chrono::high_resolution_clock::now();
        double t_quick = std::chrono::duration<double, std::milli>(t3_end - t3_start).count();
        delete[] a3;

        // --- std::sort (for comparison) ---
        Flight* a4 = new Flight[N];
        std::copy(original, original + N, a4);
        auto t4_start = std::chrono::high_resolution_clock::now();
        std::sort(a4, a4 + N, [](const Flight& a, const Flight& b) {
            return a > b;  // Sort in descending order
        });
        auto t4_end = std::chrono::high_resolution_clock::now();
        double t_std = std::chrono::duration<double, std::milli>(t4_end - t4_start).count();
        delete[] a4;

        delete[] original;

        // Write results to CSV
        out << N << "," << t_bubble << "," << t_shaker << "," << t_quick << "," << t_std << "\n";
    }

    out.close();
    return 0;
}