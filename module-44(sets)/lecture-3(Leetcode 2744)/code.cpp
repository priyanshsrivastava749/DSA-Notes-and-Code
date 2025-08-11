//method 1
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& arr) {
        //method 1 o(n*n)
        int count = 0;
        for(int i=0;i<arr.size();i++){
            string rev = arr[i];
            reverse(rev.begin(),rev.end());
            for(int j=i+1;j<arr.size();j++){
                if(rev == arr[j]) count++;
            }
        }
        return count;
    }
};
// method 2
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& arr) {
        unordered_set<string> s;
        int count = 0;
        for(int i=0;i<arr.size();i++){
            s.insert(arr[i]);
        }
        for(int i=0;i<arr.size();i++){
            string rev = arr[i];
            reverse(rev.begin(),rev.end());
            if(rev == arr[i])continue;
            if(s.find(rev)!=s.end()){
                count++;
                s.erase(arr[i]);
            }
        } 
        return count;  
    }
};

//method 3 in one iteration
class Solution{
    public:
     int maximumNumberOfStringPairs(vector<string>& arr){
        unordered_set<string> s;
        int count = 0;
        for(int i=0;i<arr.size();i++){
            string rev = arr[i];
            reverse(rev.begin(),rev.end());
            if(s.find(rev) != s.end()){
                count++;
            }
            else{
                s.insert(arr[i]);
            }
        }
         return count;
        }
};
   