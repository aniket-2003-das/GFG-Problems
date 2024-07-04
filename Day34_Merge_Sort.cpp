//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution{
    public:
    void merge(int arr[], int l, int m, int r){
        vector<int> temp;
        int i = l;
        int j = m+1;
        while (i<=m && j<=r){
            if (arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while (i<=m){
            temp.push_back(arr[i]);
            i++;
        }
        while (j<=r){
            temp.push_back(arr[j]);
            j++;
        }
        for (int k=l; k<=r; k++){
            arr[k]=temp[k-l];
        }
    }

    public:
    void mergeSort(int arr[], int l, int r){
        if(l>=r) return;
        int mid=(l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
};
  
  
  
  
    
// public:
//     void merge(int arr[], int l, int m, int r) {
//         int n1 = m-l+1;
//         int n2 = r-m;

//         // Create temporary arrays
//         vector<int> left(n1), right(n2);

//         // Copy data to temporary arrays left[] and right[]
//         for (int i=0; i<n1; ++i)    left[i] = arr[l+i];
//         for (int i=0; i<n2; ++i)    right[i] = arr[m+1+i];

//         // Merge the temporary arrays back into arr[l..r]
//         int i=0, j=0, k=l;
//         while (i<n1 && j<n2){
//             if(left[i]<=right[j]){
//                 arr[k]=left[i];
//                 i++;
//             } 
//             else{
//                 arr[k]=right[j];
//                 j++;
//             }
//             k++;
//         }
//         // Copy the remaining elements of left[], if any
//         while (i<n1) {
//             arr[k]=left[i];
//             i++;
//             k++;
//         }
//         // Copy the remaining elements of right[], if any
//         while (j<n2) {
//             arr[k]=right[j];
//             j++;
//             k++;
//         }
//     }
// public:
//     void mergeSort(int arr[], int l, int r) {
//         if (l >= r) return;
//         int mid = l + (r-l) / 2;
//         mergeSort(arr, l, mid);
//         mergeSort(arr, mid + 1, r);
//         merge(arr, l, mid, r);
//     }
// };



//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends