class Solution{
public:
    vector<int> nearestSmallerToRight(vector<int> &arr){
        int n = arr.size();
        vector<int> ans;
        stack<int> st;
        for(int i=n-1;i>=0;i++){
            if(st.empty()){
                ans.push_back(-1);
            }
            else if(!st.empty() && st.top() < arr[i]){
                ans.push_back(st.top());
            }
            else if(!st.empty() && st.top() >= arr[i]){
                while(!st.empty() && st.top() >= arr[i]){
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
        reverse(ans.begin(),ans.end());
        return ans;
       
    }
}