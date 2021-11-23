class Solution{
    public:
    int hammingDistance(int x, int y){
        int count = 0;
        int check = x^y;
        while(check){
            check &= check-1;
            count++;
            
        }
        return count;
    }
    
};
