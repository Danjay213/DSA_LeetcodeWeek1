#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    
    int n = 2 + rand() % 9;
    vector<int> nums(n);


    for (int i = 0; i < n; i++) {
        nums[i] = -10 + rand() % 21;
    }


    int index1 = rand() % n;
    int index2;
    do {
        index2 = rand() % n;
    } while (index2 == index1);

    int target = nums[index1] + nums[index2];

  
    unordered_map<int, int> num_to_index;
    vector<int> result;
    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (num_to_index.find(complement) != num_to_index.end()) {
            result.push_back(num_to_index[complement]);
            result.push_back(i);
            break;
        }
        num_to_index[nums[i]] = i;
    }

   
    cout << "Input: nums = [";
    for (int i = 0; i < n; i++) {
        cout << nums[i];
        if (i != n - 1) cout << ",";
    }
    cout << "], target = " << target << endl;

   
    cout << "Output: [" << result[0] << "," << result[1] << "]" << endl;

    return 0;
}