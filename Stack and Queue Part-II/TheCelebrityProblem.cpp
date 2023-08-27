int findCelebrity(int n) {
 	  // Write your code here.
    
    for(int i=0; i<n; i++)
	  {
		    int j=0;
        while(j<n)
        {
            if(j==i)
            {
                j++;
                continue;
            }
            if(knows(i,j)==false && knows(j,i))
            {
                j++;
            }
            else 
                break;
        }
        if(j==n)
            return i;
	  }
    return -1;
}
