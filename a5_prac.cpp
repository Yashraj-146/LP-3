#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class QuickSort {
    public:
    int partition(vector<int>& a, int low, int high) {
        int pivot = a[high];
        int i = low - 1;

        for(int j = low; j < high; j++) {
            if(a[j] < pivot) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i+1], a[high]);
        return i+1;
    }

    void quickSortDet(vector<int>& a, int low, int high) {
        if(low < high) {
            int pi = partition(a, low, high);
            quickSortDet(a, low, pi - 1);
            quickSortDet(a, pi + 1, high);
        }
    }

    int randomPartition(vector<int>& a, int low, int high) {
        int randPivot = low + rand()%(high - low + 1);
        swap(a[randPivot], a[high]);
        return partition(a, low, high);
    }

    void quickSortRand(vector<int>& a, int low, int high) {
        if(low < high) {
            int pi = randomPartition(a, low, high);
            quickSortRand(a, low, pi - 1);
            quickSortRand(a, pi + 1, high);
        }
    }
};

int main() {
    srand(time(0));
    int n;
    cout<<"Enter the size of array = ";
    cin >> n;

    vector<int>arr(n);
    cout<<"Enter elements of the array : "<<endl;
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }


    vector<int> arr1 = arr, arr2 = arr;
    QuickSort qs;
    qs.quickSortDet(arr1, 0, n-1);
    qs.quickSortRand(arr2, 0, n-1);

    cout<<"Sorted array by Deterministic QS : ";
    for(int x : arr1) {
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"Sorted array by Randomized QS : ";
    for(int x : arr2) {
        cout<<x<<" ";
    }

    return 0;
}