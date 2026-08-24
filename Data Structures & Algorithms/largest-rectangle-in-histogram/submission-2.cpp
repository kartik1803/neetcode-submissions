class Solution {
public:
vector<int> solve(vector<int>& arr) {
    vector<int> ans;
    stack<int> st;

    st.push(-1);

    for(int i = arr.size() - 1; i >= 0; i--) {
        while(st.top() != -1 && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        ans.push_back(st.top());
        st.push(i);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> solfr(vector<int>& arr) {
    vector<int> ans;
    stack<int> st;

    st.push(-1);

    for(int i = 0; i <arr.size(); i++) {
        while(st.top() != -1 && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        ans.push_back(st.top());
        st.push(i);
    }

    
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nge=solve(heights);
        vector<int>pge=solfr(heights);
        int maxarea=INT_MIN;
        for(int i=0;i<heights.size();i++){
            if(nge[i]==-1){
                nge[i]=heights.size();
            }
            int w=nge[i]-pge[i]-1;
            int h=heights[i];
            int area=w*h;
            if(area>maxarea){
                maxarea=area;
            }
        }
        return maxarea;
    }
};
