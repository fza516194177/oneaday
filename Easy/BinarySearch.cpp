#include <iostream>
#include <string>
#include <vector>
using namespace std;

Class Solution {
    public:
        int BS(vector<int> nums, target) {
            int low = 0, high = vector.size() - 1;
            
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (target > nums[mid]) low = mid + 1;
                if (target < nums[mid]) high  = mid - 1;
                if (target == nums[mid]) return mid;
            }
            return low;
        }        
};

int main() {
    Solution cls = new(Solution);
    int a[] = {1,3,5,9,10,11,13,18,20};
    vector<int> input(a,9);
    cls->BS(input, 3);
    return 0;
}