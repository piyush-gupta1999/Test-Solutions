// C++ program to find the sum of
// the addition of all possible subsets.
#include <bits/stdc++.h>
using namespace std;

// Function to perform step-1
vector<int> findSubset(vector<int>& temp, int& last, int k)
{
	vector<int> ans;

	// Iterate from left till 0
	// till we get a bit set of K numbers
	for (int i = last; i >= 0; i--) {
		int cnt = 0;

		// Count the numbers whose
		// i-th bit is set
		for (auto it : temp) {
			int bit = it & (1 << i);
			if (bit > 0)
				cnt++;
		}

		// If the array has numbers>=k
		// whose i-th bit is set
		if (cnt >= k) {
			for (auto it : temp) {
				int bit = it & (1 << i);
				if (bit > 0)
					ans.push_back(it);
			}

			// Update last
			last = i - 1;

			// Return the new set of numbers
			return ans;
		}
	}

	return ans;
}

// Function to find the maximum '&' value
// of K elements in subsequence
int findMaxiumAnd(int arr[], int n, int k)
{
	int last = 31;
	// Temporary arrays
	vector<int> temp1, temp2;

	// Initially temp = arr
	for (int i = 0; i < n; i++) {
		temp2.push_back(arr[i]);
	}

	// Iterate till we have >=K elements
	while ((int)temp2.size() >= k) {

		// Temp array
		temp1 = temp2;

		// Find new temp array if
		// K elements are there
		temp2 = findSubset(temp2, last, k);
	}

	// Find the & value
	int ans = temp1[0];
	for (int i = 0; i < k; i++)
		ans = ans & temp1[i];

	return ans;
}

// Driver Code
int main()
{
	int n,k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>k;
	cout << findMaxiumAnd(arr, n, k)<<endl;
}
