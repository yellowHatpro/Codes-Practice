class Solution {
public:
   bool function(vector<int>arr,int e,int a, int b){
        int m;
                while(a<=b){
                    m=a+(b-a)/2;
                     if (arr[m]==2*e)
                    return true;
                    else if(arr[m]>2*e){
                    b=m-1;
                     }
                     else 
                    a=m+1;
                }
       return false;
   }
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        bool result;
        for(int i=0;i<arr.size();i++){
            int e=arr[i];
            if(e<0){
                int a=0,b=i-1;
                result=function(arr,e,a,b);
                if(result)
                    return true;
            }
            else{
            int a=i+1,b=arr.size()-1;
            result=function(arr,e,a,b);
            if(result)
                return true;
            }     
            }
        return false;
    }
};