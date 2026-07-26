class Solution {
public:
    vector<int> f(int drop, vector<int>& arr) {
        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {

            while (!st.empty() && drop > 0 && st.top() < arr[i]) {
                st.pop();
                drop--;
            }

            st.push(arr[i]);
        }

        while (drop > 0 && !st.empty()) {
            st.pop();
            drop--;
        }

        vector<int> fin;

        while (!st.empty()) {
            fin.push_back(st.top());
            st.pop();
        }

        reverse(fin.begin(), fin.end());
        return fin;
    }
    bool choose(vector<int> &arr1 , vector<int> &arr2 ,  int i , int j) {
        while(i < arr1.size() && j < arr2.size() && arr1[i] == arr2[j]){
            
            i++; 
            j++; 
            
        }
        if (j == arr2.size()) return true;
        if (i == arr1.size()) return false;  
        return arr1[i] > arr2[j];
    }
    vector<int> merge(vector<int>& arr1, vector<int>& arr2) {
        int i = 0;
        int j = 0;
        vector<int> merged;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] > arr2[j]) {
                merged.push_back(arr1[i]);
                i++;
            } else if (arr1[i] < arr2[j]) {
                merged.push_back(arr2[j]);
                j++;
            } else {
                if (choose(arr1, arr2, i, j) == true) {
                    merged.push_back(arr1[i]);
                    i++;
                } else {
                    merged.push_back(arr2[j]);
                    j++;
                }
            }
        }
        while( i < arr1.size()){
            merged.push_back(arr1[i]) ; 
            i++; 
        }
        while( j < arr2.size()) {
            merged.push_back(arr2[j]) ;
            j++;  
        }
        return merged;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans = {};
        for (int i = max(0, k - n); i <= min(k, m); i++) {
            int drop1 = m - i;
            int drop2 = n - (k - i);
            vector<int> valid1 = f(drop1, nums1);
            vector<int> valid2 = f(drop2, nums2);
            auto cur = merge(valid1, valid2);
            if (cur > ans) {
                ans = cur;
            }
        }

        return ans;
    }
};