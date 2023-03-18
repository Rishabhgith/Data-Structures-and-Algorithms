#include <bits/stdc++.h>
using namespace std;

// User function Template
int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0]; // Maximum possible height difference

    int tempmin, tempmax;
    tempmin = arr[0];
    tempmax = arr[n - 1];

    for (int i = 1; i < n; i++) {
        tempmin= min(arr[0] + k,arr[i] - k); // Minimum element when we
                                                // add k to whole array
        tempmax = max(arr[i - 1] + k, arr[n - 1] - k); // Maximum element when we
                                                         // subtract k from whole
        // ABOVE TEMPMAX STEP IS DONE IN SUCH WAY SO THAT COMPARISION BETWEEN 
        //LAST AND SECOND LAST ELEMENT COULD BE DONE . 
        // TRUST YOUR MEMORIZING POWER                                                 
        ans = min(ans, tempmax - tempmin); 
    }
    return ans;
}

// Driver Code Starts
int main()
{
    int k = 2, n = 4;
    int arr[n] = {1,5,8,10};
    int ans = getMinDiff(arr, n, k);
    cout << ans;
}