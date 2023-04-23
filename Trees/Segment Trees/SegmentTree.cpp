	// Classic Segment Tree
	void build(int id = 1,int l = 0,int r = n)         //root index 1,children 2x,2x+1
	{						   // root = [0,n)
		if( l+1 == r )
		{
		    s[id] = a[l];			// put values in leaf nodes
		    return;				// comes from array
		}					   
		
		ll mid = l + (r-l)/2;
		build( id*2, l, mid);			// interval = [left,right)
		build( id*2+1, mid, r);
		
		s[id]= [id * 2] + s[id * 2 + 1];	// put values in non-leaf nodes
							// comes from child nodes
	}

	void modify(int p, int x, int id=1, int l=0, int r=n)    // call modify(p,x)
	{
					    //x is the value to which a[p] is changed
		s[id] += x-a[p] ;  		// change the value of the segtree node

		if( l+1 == r){			// l=r-1=p
		   a[p]=x;                 // change the value in the array
		   return;		
		}

		ll mid = l + (r-l)/2;
		
		if( p < mid )
		{
		   modify(p, x, id*2, l, mid);	
		}
		else
		{
		   modify(p, x, id*2+1, mid, r);
		}
		
	}

	ll query(int x,int y,int id=1,int l=0,int r=n){		//verify return type
								// call query(l,r)
		if( x >= r or l >= y )  return 0;	// no overlap

		if( x <= l and r <= y )  return s[id];      // complete overlap

		ll mid = l + (r-l)/2;			  // partial overlap
		return query(x, y, id*2, l, mid) + query(x, y, id*2+1, mid, r);

	}
