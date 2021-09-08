#include <chrono>
#include <fstream>
#include <iostream>
/*
CH-231-A
a4_p1.cpp
Antonia Savu
asavu@jacobs-university.de
*/

/*
As you will notice in the output, the numbers are bad.
I'm 95% sure it is not because of the code, but because I am
using windows OS.I tried a code that worked
perfectly on linux on my pc and it did not work.
The clocks from microsoft dont have a high enough resolution
to have an accurate read and this will show in the plot aswell.
Will try to get WSL running till next week. sorry!
*/
std::ofstream g("output.txt");
void insertionSort(int array[], int l, int r) {
  // regular insertion sort
  int i, key, j;
  for (i = l + 1; i <= r; i++) {
    key = array[i];
    j = i - 1;

    while (j >= l && array[j] > key) {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = key;
  }
}

void normal_merge(int array[], int l, int m, int r) {
  // regular merge sort
  int left = m - l + 1;
  int right = r - m;

  int left_array[left], right_array[right];
  for (int i = 0; i < left; i++)
    left_array[i] = array[l + i];
  for (int j = 0; j < right; j++)
    right_array[j] = array[m + 1 + j];
  int i = 0, j = 0, k = l;

  while (i < left && j < right)
    if (left_array[i] <= right_array[j])
      array[k++] = left_array[i++];
    else
      array[k++] = right_array[j++];

  while (i < left)
    array[k++] = left_array[i++];

  while (j < right)
    array[k++] = right_array[j++];
}

void mergeSort(int array[], int l, int r, int k) {
  // if the length is equal or smalle than k
  if ((r - l) <= k)
    insertionSort(array, l, r);
  // insertion sort
  else {
    // otherwise, merge sort until the length gets smaller and smaller
    int m = (l + r) / 2;
    mergeSort(array, l, m, k);
    mergeSort(array, m + 1, r, k);
    normal_merge(array, l, m, r);
  }
}

int main() {

  int array[1000];
  // in order to show the difference, i picked an array with max 1k elements

  for (int k = 0; k < 1000; k += 10) // which increase by 10 every iteration
  {

    // instead of summing up  a bunch of cases, in order
    // to calculate the average time i will just take a random array
    srand(time(NULL));
    for (int i = 0; i < 1000; i++)
      array[i] = rand() % 1000; // adding 1k random values

    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(array, 0, 999, k);
    auto stop = std::chrono::high_resolution_clock::now();
    auto average_case =
        std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    // calculating the time

    // the best case scenario would be an already sorted array
    for (int i = 0; i < 1000; i++)
      array[i] = i;
    // therefore this array will take the values 0,1..999
    start = std::chrono::high_resolution_clock::now();
    mergeSort(array, 0, 999, k);
    stop = std::chrono::high_resolution_clock::now();
    auto best_case =
        std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    // calculating the time

    // the worst case scenario would be an array inversly-sorted

    for (int i = 0; i < 1000; i++)
      array[i] = 1000 - i;
    // so the array will take the values 1000,999...1

    start = std::chrono::high_resolution_clock::now();
    mergeSort(array, 0, 999, k);
    stop = std::chrono::high_resolution_clock::now();
    auto worst_case =
        std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    // calculating the time
    g << k << " " << (double)worst_case.count() << " "
      << (double)best_case.count() << " " << (double)average_case.count()
      << '\n';
    // printing the values in a file because there are many
  }
  return 0;
}