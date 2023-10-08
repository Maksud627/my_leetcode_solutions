class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        
        for(int i=0; i<n+1; i++){
            string bin_represent = intToBin(i);
            int count=0;
            
            for(char c: bin_represent){
                if(c=='1') count++;
            }
            
            ans[i] = count;
        }
        return ans;
    }
    
    string intToBin(int number){
        if(number == 0) return "0";
        
        string binary="";
        
        while(number>0){
            binary = to_string(number%2) + binary;
            number /= 2;
        }
        
        return binary;
    }
};


// TC: O(n^3) as traversing through 3 loops
// SC: O(n) vector<int> ans; as storing the value