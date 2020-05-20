#include <iostream>
using namespace std;


void Max_Heapify(int A[],int i,int n){
    int l = i * 2;
    int r = i * 2 + 1;
    int largest = i;
    if(l<=n && A[l]>A[i]){
        largest = l;
    }
    if(r<=n && A[r]>A[largest]){
        largest = r;
    }
    if(i!=largest){
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        Max_Heapify(A, largest, n);
    }
}

void Build_Max_Heap(int A[],int n){
    for (int i = n / 2; i >0;i--){
        Max_Heapify(A, i, n);
    }
}

void HeapSort(int A[],int n){
    Build_Max_Heap(A, n);
    for (int i = n; i >= 2;i--){
        for (int i = 0; i < 13;i++)
            cout << A[i] << " ";
        cout << endl;
        int temp = A[i];
        A[i] = A[1];
        A[1] = temp;
        Max_Heapify(A, 1, i - 1);
    }
}

int main(){
    int a[13] = {-1, 3, 1, 5, 6, 2, 8, 9, 14, 17, 12, 15, 11};
    HeapSort(a, 13);
    for (int i = 0; i < 13;i++)
        cout << a[i] << " ";
    cout << endl;
}