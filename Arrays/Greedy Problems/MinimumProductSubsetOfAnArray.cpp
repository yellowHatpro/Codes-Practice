/*Given an array a, we have to find the minimum product possible with the subset of elements present in the array. 
The minimum product can be a single element also.

Examples: 
Input : a[] = { -1, -1, -2, 4, 3 }
Output : -24
Explanation : Minimum product will be ( -2 * -1 * -1 * 4 * 3 ) = -24

Input : a[] = { -1, 0 }
Output : -1
Explanation : -1(single element) is minimum product possible
 
Input : a[] = { 0, 0, 0 }
Output : 0
*/

#include <bits/stdc++.h>
using namespace std;

int minProductSubset(vector<int> a, int n)
{
    if (n == 1)
        return a[0];
    // Find count of negative numbers, count of zeros,
    // maximum valued negative number, minimum valued
    // positive number and product of non-zero numbers
    int max_neg = INT_MIN, min_pos = INT_MAX, count_neg = 0,
        count_zero = 0, prod = 1;
    for (int i = 0; i < n; i++) {
        // If number is 0, we don't multiply it with
        // product.
        if (a[i] == 0) {
            count_zero++;
            continue;
        }
        // Count negatives and keep track of maximum valued
        // negative.
        if (a[i] < 0) {
            count_neg++;
            max_neg = max(max_neg, a[i]);
        }
        // Track minimum positive number of array
        if (a[i] > 0)
            min_pos = min(min_pos, a[i]);
        prod = prod * a[i];
    }
    // If there are all zeros or no negative number present
    if (count_zero == n || (count_neg == 0 && count_zero > 0))
        return 0;
    // If there are all positive
    if (count_neg == 0)
        return min_pos;
 
    // If there are even number of negative numbers and
    // count_neg not 0
    if (!(count_neg & 1) && count_neg != 0)
        // Otherwise result is product of all non-zeros
        // divided by maximum valued negative.
        prod = prod / max_neg;
    return prod;
}
int main(){
	vector<int> v = { 2,1,-11,-1000,1,1,21,24,42};
	int n = v.size();
	cout<<minProductSubset(v,n)<<endl;
	return 0;
}
