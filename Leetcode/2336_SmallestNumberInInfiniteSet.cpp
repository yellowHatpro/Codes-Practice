#include <bits/stdc++.h>
using namespace std;
class SmallestInfiniteSet {
public:
	set<int> s;
	int count;
    SmallestInfiniteSet() {
    	s = {};
        s.insert(1);
        count = 1;
    }
    
    int popSmallest() {
        if (*s.begin()>=count){
	    	count++;
	    	s.insert(count);
        	}
        int x = *s.begin();
    	s.erase(x);
    	return x;
    }
    
    void addBack(int num) {
       if (num<count) s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */