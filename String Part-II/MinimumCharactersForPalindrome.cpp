#include<bits/stdc++.h>

vector<int> calculateLPSArray(string str)
{
	int m=str.length();
	vector<int> lps(m);
	int len=0;
	lps[0]=0;
	int i=1;
	while(i<m)
	{
		if(str[i]==str[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
				len=lps[len-1];
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
	return lps;
}

int minCharsforPalindrome(string str) {
	// Write your code here.
	
	// Method 3: Using "LPS array" 

	string revStr=str;
	reverse(revStr.begin(), revStr.end());
	string concat=str+"$"+revStr;
	vector<int> lps=calculateLPSArray(concat);
	return (str.length()-lps[lps.size()-1]);
}

// int minCharsforPalindrome(string str) {
// 	// Write your code here.
	
// 	// Method 2: 2 Pointer approach
	
// 	int i=0, j=str.length()-1;
// 	int count=0;
// 	int k=j;
// 	while(i<=j)
// 	{
// 		if(str[i]==str[j])
// 		{
// 			i++;
// 			j--;
// 		}
// 		else
// 		{
// 			i=0;
// 			k--;
// 			j=k;
// 			count++;
// 		}
// 	}
// 	return count;
// }
