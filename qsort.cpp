#include <iostream>
using namespace std;
int cnt = 0;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int *arr, int front, int end){
    int pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            cnt++;
            //cout << "arr[i]=" << arr[i] << " , arr[j]=" << arr[j] << std::endl;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    cnt++;
    //cout << "\narr[i]=" << arr[i] << " , arr[end]=" << arr[end] <<"\n\n"<< std::endl;
    swap(&arr[i], &arr[end]);
    return i;
}
void QuickSort(int *arr, int front, int end){
    if (front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}
void PrintArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << std::endl;
}
int main() {

    int n = 15;
    int arr[] = {5,2,10,3,14,8,9,1,13,11,6,4,12,7,15};
    cout << "original:\n";
    PrintArray(arr, n);

    QuickSort(arr, 0, n-1);

    cout << "sorted:\n";
    PrintArray(arr, n);
    cout << "count: " << cnt << endl;
    return 0;
}