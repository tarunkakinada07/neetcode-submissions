class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // 1. Count frequency of each number
        unordered_map<int, int> m;

        for (auto i : nums) {
            m[i]++;
        }

        // 2. Min heap: {frequency, number}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        // 3. Keep only k most frequent elements
        for (auto i : m) {

            pq.push({i.second, i.first});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        // 4. Put the k elements into answer
        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};