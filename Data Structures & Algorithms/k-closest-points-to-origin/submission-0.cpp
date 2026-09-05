class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<int> pq;

        priority_queue<pair<int, vector<int>>,
                       vector<pair<int, vector<int>>>,
                       greater<pair<int, vector<int>>>> pq1;

        for(int i = 0; i < points.size(); i++) {

            for(int j = 0; j < points[i].size(); j++)
                pq.push(points[i][j]);

            int num1 = pq.top();
            pq.pop();

            int num2 = pq.top();
            pq.pop();

            int ans = num1 * num1 + num2 * num2;

            pq1.push({ans, points[i]});
        }

        vector<vector<int>> finalans;

        while(k--) {
            finalans.push_back(pq1.top().second);
            pq1.pop();
        }

        return finalans;
    }
};
