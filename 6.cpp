#include <iostream>
using namespace std;

void Sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int bsearch(int arr[],int l,int r,int t)
//here l is left, r is right,t is target element
{
    while (l<=r)
    {
        int mid=l+(r-l)/2;

        if(arr[mid]==t)
        {
            cout<<"Element is found in index";

            return mid;
        }


        if(arr[mid]<t){
            
            l=mid+1;//search the element in right side
        }
         else{
            r=mid-1;//search the element in left side
        }
    }

    return -1;


}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

   Sort(arr,n);

    int target;
    cout << "Enter the element to search for: ";
    cin >> target;

    int result = bsearch(arr, 0, n - 1, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}