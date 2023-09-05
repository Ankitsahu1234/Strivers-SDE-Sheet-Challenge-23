int minCharsforPalindrome(string str) {
	// Write your code here.
	
	// Method 2: 2 Pointer approach
	
	int i=0, j=str.length()-1;
	int count=0;
	int k=j;
	while(i<=j)
	{
		if(str[i]==str[j])
		{
			i++;
			j--;
		}
		else
		{
			i=0;
			k--;
			j=k;
			count++;
		}
	}
	return count;
}
