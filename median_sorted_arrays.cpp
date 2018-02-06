#include<iostream>
#include<algorithm>
#include<vector>;
using namespace std;
/*
 *There are two sorted arrays nums1 and nums2 of size m and n respectively
 *Find the median of the two sorted arrars.The overall run time complexity should be O(log(m+n))
 */

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	/* get an array */
	int arrayLen = nums1.length() + nums2.length();
	int res[arrayLen];
	for(int i = 0; i < nums1.size(); i++)
	{
		res[i] = nums1[i];
	}
	for(int i = 0; i < nums2.size(); i++)
	{
		res[i + nums1.length()] = nums2[i];
	}
	/*sort the array,order is not important */
	sort(res, res + arrayLen);
	/* odd */
	if(arrayLen % 2)
	{
		return res[(arrayLen + 1) / 2 - 1];
	}
	else
	{
		return (res[arrayLen / 2 - 1] + res[arrayLen / 2]) / 2.0;
	}
}

int main()
{
	vector<int> nums1, nums2;
	int nums1_tmp, nums2_tmp;
	while(cin >> nums1_tmp && nums1_tmp != 0)
	{
		nums1.push_back(nums1_tmp);
	}
	while(cin >> nums2_tmp && nums2_tmp != 0)
	{
		nums2.push_back(nums2_tmp);
	}
	cout << findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}
