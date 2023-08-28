#include <iostream>
using namespace std;
//shift array left by making a function
void rl(int arr[], int n, int d) {
    int temp[d];
    
    // lets store the first 2 elements in a temporary array
    for (int i = d; i < d+2; i++) {
        temp[i-d] = arr[i];
    }
    
    // Shift the remaining elements to the left by 'd' positions
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }
    
    // Copy back the stored elements from the temporary array
    for (int i = n - d; i < n; i++) {
        arr[i] = temp[i - n + d];
    }
}

int main() {
    int n, d;

     //storing value in d 
    cout << "Enter the value of 'd': ";
    cin >> d;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = d; i < n; i++) {
        cout<<"arr["<<i<<"] = ";
        cin >> arr[i];
    }
    
    
   
    //use of function
    rl(arr, n, d);
    //printing final array after swapping
    cout << "Array after rotation:\n";
    for (int i = d; i < n; ++i) {
        cout<<"arr["<<i<<"] = ";
        cout << arr[i] << "\n ";
    }
    
    return 0;
}
