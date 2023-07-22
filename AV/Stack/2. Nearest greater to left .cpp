class Solution{
public:
    vector<int> nearestGreaterToLeft(vector<int> &arr){
        int n = arr.size();
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<n;i++){ //here is changes from question no. 1
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
        // for(int i=0;i<n;i++){
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