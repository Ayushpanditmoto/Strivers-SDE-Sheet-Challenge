class Solution{
public:
    vector<int> nearestSmallerToLeft(vector<int> &arr){
        int n = arr.size();
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<n;i++){ 
            if(st.empty()){
                ans.push_back(-1);
            }
            else if(!st.empty() && st.top() < arr[i]){ //here is changes from question no. 1
                ans.push_back(st.top());
            }
            else if(!st.empty() && st.top() >= arr[i]){ //here is changes from question no. 1
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
        return ans;
    }
}