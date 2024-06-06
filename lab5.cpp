#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int HEAP_MAX_SIZE = 1000;
class MinHeap {
private:
    int heapArr[HEAP_MAX_SIZE] = {0};
    int size;
    void swap(int &x, int &y) {
        int temp = x;
		x = y;
		y = temp;
    }
    void percolateUp(int index) {
         int par_ind = (index-1)/2; // indentify parent
		 if(index == 0 || heapArr[index] > heapArr[par_ind]) // root or correct position
		 {
			return;
		 }
		 else
		 {
			 swap(heapArr[index], heapArr[par_ind]);
			 percolateUp(index);
		 }
    }
    void percolateDown(int index) {
         int left = 2*index+1; // find left child
		 int right = 2*index+2; // find right child
		 if(left > size || right > size) // check if children are beyond scope of heap
		 {
			 return;
		 }
		 if (!(heapArr[left] || heapArr[right]) || (heapArr[index] < heapArr[left] && heapArr[index] < heapArr[right])) // check if leaf node, or if at right place
		 {
			 return;
		 }
		 else if(heapArr[left] < heapArr[right] && heapArr[left] < heapArr[index]) // percolate down left sub tree
		 {
			 swap(heapArr[index], heapArr[left]);
			 percolateDown(2*index+1);
		 }
		 else if(heapArr[left] > heapArr[right] && heapArr[right] < heapArr[index]) // percolate doen right sub tree
		 {
			 swap(heapArr[index], heapArr[right]);
			 percolateDown(2*index+2);
		 }
    }
public:
    MinHeap() { size = -1; }
	void insert(int element) {
		if(size == HEAP_MAX_SIZE) // edge case
		{
			cout << "Maximum capacity reached." << endl;
			return;
		}
		size++; // increase size
		heapArr[size] = element; // instert at the end of the heap
		percolateUp(size); // percolate up
	}
	void deleteMin() {
		swap(heapArr[0], heapArr[size]); // swap root with last element
		heapArr[size] = 0; // remove last element
		size--; // decrease size
		percolateDown(0); // percolate down
	}
	int extractMin() {
		return heapArr[0];
	}
	int heapSize() {
		return size+1;
	}
	void heapDisplay() {
		for(int i = 0; i<=size;i++)
		{
			cout << heapArr[i] << " ";
		}
		cout << endl;
	}
};

// different sorting algorithms defined here
void heapSort (int A[], int n)
{
	MinHeap mh; // define heap
	for(int i = 0; i < n; i++)
	{
		mh.insert(A[i]); // build min heap
	}
	
	for(int i = 0; i < n; i++)
	{
		A[i] = mh.extractMin(); // store min value in temp array
		mh.deleteMin(); // delete min/head node
	}
}

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) 
{
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
  {
    L[i] = arr[p + i];
  }
  for (int j = 0; j < n2; j++)
  {
    M[j] = arr[q + 1 + j];
  }

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) 
  {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M, pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort (int A[], int i, int j)
{
	if (i >= j)
	{
		return;
	}
	int mid = (i+j) / 2;
	mergeSort(A, i, mid);
	mergeSort(A, mid+1, j);
	merge(A, i, mid, j);

}

void swapIt(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

int partition(int A[], int bot, int top)
{
	int pivot = A[bot]; // select pivot
	int count = 0;
    for(int i = bot + 1; i <= top; i++)
    {
        if(A[i] <= pivot)
        {
            count++;
        }
    }
	
	int pivotIndex = bot + count;
    swapIt(A[pivotIndex], A[bot]);

    int i = bot;
    int j = top;

    while (i < pivotIndex && j > pivotIndex) {
 
        while (A[i] <= pivot) {
            i++;
        }
 
        while (A[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swapIt(A[i++], A[j--]);
        }
    }
 
    return pivotIndex;

}

void quickSort (int A[], int i, int j)
{
	if (i >= j)
	{
        return;
    }
		int pivInd = partition(A, i, j);
		quickSort(A, i, pivInd-1);
		quickSort(A, pivInd+1, j);
}


int main()
{
    int size[] = {10,100,1000,10000};
	cout << "========== Heap Sort ==========" << endl;
	cout << endl;
    for(int i = 0; i < 3; i ++){
        int unsortedArray[size[i]]; 
        cout << "The current array size is: " << size[i] << endl;
        for(int j=0; j<size[i]; j++){
            unsortedArray[j] = rand() % 1000000;
        }
		
		//auto start = high_resolution_clock::now();
		
		heapSort(unsortedArray, size[i]);
		
		//auto stop = high_resolution_clock::now();
		//auto duration = duration_cast<nanoseconds>(stop - start);
		//cout << "Execution Time: " << duration.count() << " ns" << endl;
		
		cout << endl;
    }
	
	cout << "========== Merge Sort ==========" << endl;
	cout << endl;
	for(int i = 0; i < 4; i ++){
        int unsortedArray[size[i]]; 
        cout << "The current array size is: " << size[i] << endl;
        for(int j=0; j<size[i]; j++){
            unsortedArray[j] = rand() % 1000000;
        }
		
		auto start = steady_clock::now();
		
		mergeSort(unsortedArray, 0, size[i]-1);
		
		auto stop = steady_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Execution Time: " << duration.count() << " ns" << endl;
		
		cout << endl;
    }
	
	cout << "========== Quick Sort ==========" << endl;
	cout << endl;
	for(int i = 0; i < 4; i ++){
        int unsortedArray[size[i]]; 
        cout << "The current array size is: " << size[i] << endl;
        for(int j=0; j<size[i]; j++){
            unsortedArray[j] = rand() % 1000000;
        }
		
		/*cout << "Unsorted Array:" << endl;
		 for(int j=0; j<size[i]; j++){
		 	cout << unsortedArray[j] << " ";
		 }
		 cout << endl;*/
		
		auto start = steady_clock::now();
		
		quickSort(unsortedArray, 0, size[i]-1);
		
		auto stop = steady_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Execution Time: " << duration.count() << " ns" << endl;
		
		/* cout << "Sorted Array:" << endl;
		 for(int j=0; j<size[i]; j++){
		 	cout << unsortedArray[j] << " ";
		 }
		 cout << endl;*/
		 
		cout << endl;
    }
} 