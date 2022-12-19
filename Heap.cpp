#include <iostream>
using namespace std;

class MaxHeap {
                                    //Formulas:
	int* arr;						// parent = i/2	
	int capacity;					// left child = 2i
	int count = 1;					// right child = 2i+1

public:
	MaxHeap() {}
	MaxHeap(int n) {
		arr = new int[n];
		capacity = n;
	}

	void insert(int data) {
		int i = count;
		if (count > capacity) {
			cout << "Overflow!";
			return;
		}
		
		//Fix the max heap property
		while (i > 1 && data > arr[i / 2]) {
			arr[i] = arr[i / 2];
			i = i / 2;
		}
		
		//Adding element int the heap
		count++;
		arr[i] = data;            
	}
	
	void deletetop() {
		int temp = arr[1];              
		arr[1] = arr[count - 1];
		siftDown(1);
		arr[count - 1] = temp;          //Storing it at the end
		count--;
	}

	void swap(int* x, int* y) {
		int temp = *x;
		*x = *y;
		*y = temp;
	}

	void siftDown(int i) {
		int left, right;
		int max = i;
		left = (2 * i);
		right = (2 * i) + 1;

		if (left > 1 && right > 1 && left < count && right < count) {
			if (arr[left] > arr[right])
				max = left;
			else 
				max = right;
		}

		if (arr[i] < arr[max]) 
			swap(&arr[i], &arr[max]);

		else 
			return;
			
		siftDown(max);
	}

	void heapsort() {
		while (count > 1) {
			deletetop();
		}
	}

	void printArray() {
		for (int i = 1; i < capacity; i++)
			cout << arr[i] << " ";
			cout << endl;
	}
};

int main() {
	MaxHeap h1(8);
	h1.insert(30);
	h1.insert(15);
	h1.insert(20);
	h1.insert(40);
	h1.insert(60);
	h1.insert(25);
	h1.insert(10);
	
	cout << "Max Heap: " << endl; 
	h1.printArray();
	
	cout << endl << "After Deleting the Top element: " << endl;
	h1.deletetop();
	h1.printArray();
	
	cout << endl << "Heap Sort: " << endl;
	h1.heapsort();
	h1.printArray();
}
