// Jaewon Park
// jaepark@chapman.edu
// 2328614
// CPSC 350 - 01
// Assignment #6

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;


void selectionSort(double *myArray, int n){
  int i, j, minIndex;
  double temp;
  for (i = 0; i < n-1; i++){
    minIndex = i;
    for (j = i+1; j < n; j++){
      if (myArray[j] < myArray[minIndex]){
        minIndex = j;
      }
      if (minIndex != i){
        temp = myArray[i];
        myArray[i] = myArray[minIndex];
        myArray[minIndex] = temp;
      }
    }
  }
  cout << "Selection sort: " << endl;
  for (int k = 0; k < n; ++k){
    cout << myArray[k] << endl;
  }
  cout << " " << endl;

}

void insertionSort(double* myArray, int n){
  for (int j = 0; j < n; ++j){
    double temp = myArray[j];
    int i = j;
    while (i > 0 && myArray[i-1] >= temp){
      myArray[i] = myArray[i-1];
      --i;
    }
    myArray[i] = temp;
  }
  cout << "Insertion sort: " << endl;
  for (int k = 0; k < n; ++k){
    cout << myArray[k] << endl;
  }
  cout << " " << endl;
}

void bubbleSort(double* myArray, int n){
  for (int i = 0; i < n; ++i) {
    double temp = 0;
    for (int j = i; j < n-1; ++j){
      if (myArray[j] > myArray[j + 1]) {
        temp = myArray[j + 1];
        myArray[j + 1] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
  cout << "Bubble Sort: " << endl;
  for (int k = 0; k < n; ++k){
    cout << myArray[k] << endl;
  }
  cout << " " << endl;
}

int partition(double* myArray, int start, int end){
  double temp;
  double piv = myArray[end];
  int j = start-1;
  for (int i = start; i < end; ++i){
    if (myArray[i] <= piv){
      ++j;
      temp = myArray[j];
      myArray[j] = myArray[i];
      myArray[i] = temp;
    }
  }
  temp = myArray[j + 1];
  myArray[j + 1] = myArray[end];
  myArray[end] = temp;
  return (j + 1);
}

void quickSort(double* myArray, int start, int end){
  int size;
  if (start < end){
    int idx = partition(myArray, start, end);
    quickSort(myArray, start, idx-1);
    quickSort(myArray, idx+1, end);
  }
}

// void printSort(double* myArray, int size)
// {
//   int i;
//   for(i=0; i<size; i++)
//   {
//     cout << "Quick Sort: " << endl;
//     cout << myArray[i] << endl;
//   }
// }


int mergeSort(double array[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1+ j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}



int main (int argc, char ** argv){
  //string userInput;
  string fileName;
  int count;
  string nElements;
  string line;
  int numLine = 1;
  int numbers;
  double fileArray;
  clock_t start;
  clock_t end;
  float calculatedTime;

  cout << "Enter a file to sort" << endl;
  cout << " " << endl;
  cin >> fileName;
  ifstream file(fileName);
  if (file.is_open()){
    while(getline(file, line)){
      ++numLine;
        cout << line << endl;
    }
  }
  file.close();

  cout << " " << endl;


  int size = 10;
  double insertionArray[size] = {10.2, 1.9, 2.8, 7.3, 5.1, 3.2, 9.3, 4.2, 4.3, 5.2, 9.3};
  double selectionArray[size] = {10.2, 1.9, 2.8, 7.3, 5.1, 3.2, 9.3, 4.2, 4.3, 5.2, 9.3};
  double bubbleArray[size] = {10.2, 1.9, 2.8, 7.3, 5.1, 3.2, 9.3, 4.2, 4.3, 5.2, 9.3};
  double quickArray[size] = {10.2, 1.9, 2.8, 7.3, 5.1, 3.2, 9.3, 4.2, 4.3, 5.2, 9.3};
  double mergeArray[size] = {10.2, 1.9, 2.8, 7.3, 5.1, 3.2, 9.3, 4.2, 4.3, 5.2, 9.3};

  start = clock();
  insertionSort(insertionArray, size);
  end = clock();
  calculatedTime = (float(end - start)/CLOCKS_PER_SEC)*1000;
  cout << "insertion sort time: " << calculatedTime << "seconds" << size << endl;
  cout << " " << endl;

  start = clock();
  selectionSort(selectionArray, size);
  end = clock();
  calculatedTime = (float(end - start)/CLOCKS_PER_SEC)*1000;
  cout << "selection sort time: " << calculatedTime << "seconds" << size << endl;
  cout << " " << endl;

  start = clock();
  quickSort(quickArray, 0, size - 1);
  end = clock();
  calculatedTime = (float(end - start)/CLOCKS_PER_SEC)*1000;
  cout << "Quick sort time: " << calculatedTime << "seconds" << size << endl;
  cout << " " << endl;

  start = clock();
  bubbleSort(bubbleArray, size);
  end = clock();
  calculatedTime = (float(end - start)/CLOCKS_PER_SEC)*1000;
  cout << "bubble sort time: " << calculatedTime << "seconds" << size << endl;
  cout << " " << endl;

  start = clock();
  mergeSort(mergeArray, 0, 0, size);
  end = clock();
  calculatedTime = (float(end - start)/CLOCKS_PER_SEC)*1000;
  cout << "Merge sort time: " << calculatedTime << "seconds" << size << endl;
  cout << " " << endl;

  return 0;
}
