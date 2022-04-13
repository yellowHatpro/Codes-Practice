class Solution {
public:
    double myPow(double a, int b) {
        if (b==0) return 1;

	double temp = myPow(a,b/2);
	if (b%2==0)
	{   return temp*temp;
      
	}else{
       return b<0 ? 1/a*temp*temp : a*temp*temp;
	}
}
};