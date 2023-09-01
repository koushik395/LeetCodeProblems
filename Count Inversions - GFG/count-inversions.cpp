//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    long long cnt = 0;
    void merge(long long *arr, long long s, long long e) {
    
        long long mid = (s+e)/2;
    
        long long len1 = mid - s + 1;
        long long len2 = e - mid;
    
        long long *first = new long long[len1];
        long long *second = new long long[len2];
    
        //copy values
        int mainArrayIndex = s;
        for(int i=0; i<len1; i++) {
            first[i] = arr[mainArrayIndex++];
        }
    
        mainArrayIndex = mid+1;
        for(int i=0; i<len2; i++) {
            second[i] = arr[mainArrayIndex++];
        }
    
        //merge 2 sorted arrays     
        int index1 = 0;
        int index2 = 0;
        mainArrayIndex = s;
    
        while(index1 < len1 && index2 < len2) {
            if(first[index1] <= second[index2]) {
                arr[mainArrayIndex++] = first[index1++];
            }
            else{
                cnt += len1 - index1;
                arr[mainArrayIndex++] = second[index2++];
            }
        }   
    
        while(index1 < len1) {
            arr[mainArrayIndex++] = first[index1++];
        }
    
        while(index2 < len2 ) {
            arr[mainArrayIndex++] = second[index2++];
        }
    
        delete []first;
        delete []second;
    
    }
    void mergeSort(long long *arr, long long s, long long e) {

        //base case
        if(s >= e) {
            return;
        }
        
        long long mid = (s+e)/2;

        mergeSort(arr, s, mid);

        mergeSort(arr, mid+1, e);

        merge(arr, s, e);
    
    }

    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr,0,N-1);
        return cnt;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends