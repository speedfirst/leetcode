#include <vector>

namespace Candy {
    class Solution {
    public:
        int candy(std::vector<int> &ratings) {
            if (ratings.empty()) {
                return 0;
            }

            if (ratings.size() == 1) {
                return 1;
            }
            
            // initialize an all 1 vector
            std::vector<int> candies(ratings.size(), 1);

            // scan from left to right
            for (int i = 1; i < ratings.size(); i++) {
                if (ratings[i] > ratings[i - 1]) {

                }
            }
            
            // scan from right to left
            for (int i = ratings.size() - 2; i >= 0; i--) {
                if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                    candies[i] = candies[i + 1] + 1;
                }
            }
            
            // sum up
            int sum = 0;
            for (int i = 0; i < candies.size(); i++) {
                sum += candies[i];
            }
            
            return sum;

        }

    };
}
