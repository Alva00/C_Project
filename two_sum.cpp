#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> nums;
  int target;
  /* DFS */
  for(int i = 0; i < nums.size() - 1; i++)
  {
    for(int j = i + 1; j < nums.size(); j++)
    {
      if(nums[i] + nums[j] == target)
      {
        cout << i << " " << j << endl;
        break;
      }
    }
  }
  return 0;
}

