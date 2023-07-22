class Solution{
public:
    vector<int> nearestGreaterToRight(vector<int> &arr){
        int n = arr.size();
        vector<int> ans;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans.push_back(-1);
            }
            else if(!st.empty() && st.top() > arr[i]){
                ans.push_back(st.top());
            }
            else if(!st.empty() && st.top() <= arr[i]){
                while(!st.empty() && st.top() <= arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(st.top());
                }
            }
            st.push(arr[i]);
        }
        return ans;
        // int n = arr.size();
        // vector<int> ans(n,-1);
        // stack<int> st;
        // for(int i=n-1;i>=0;i--){
        //     while(!st.empty() && st.top() <= arr[i]){
        //         st.pop();
        //     }
        //     if(!st.empty()){
        //         ans[i] = st.top();
        //     }
        //     st.push(arr[i]);
        // }
        // return ans;
    }
}