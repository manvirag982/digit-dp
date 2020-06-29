//https://www.geeksforgeeks.org/digit-dp-introduction///
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mxN =150000;

// Memoization for the state results 
long long dp[20][165][2]; 

// Stores the digits in x in a vector digit 
long long getDigits(long long x, vector <int> &digit) 
{ 
	while (x) 
	{ 
		digit.push_back(x%10); 
		x /= 10; 
	} 
} 

// Return sum of digits from 1 to integer in 
// digit vector 
long long digitSum(int idx, int sum, int tight, 
						vector <int> &digit) 
{ 
	// base case 
	if (idx == -1) 
	return sum; 

	// checking if already calculated this state 
	if (dp[idx][sum][tight] != -1 and tight != 1) 
		return dp[idx][sum][tight]; 

	long long ret = 0; 

	// calculating range value 
	int k = (tight)? digit[idx] : 9; 

	for (int i = 0; i <= k ; i++) 
	{ 
		// caclulating newTight value for next state 
		int newTight = (digit[idx] == i)? tight : 0; 

		// fetching answer from next state 
		ret += digitSum(idx-1, sum+i, newTight, digit); 
	} 

	if (!tight) 
	dp[idx][sum][tight] = ret; 

	return ret; 
} 

// Returns sum of digits in numbers from a to b. 
int rangeDigitSum(int a, int b) 
{ 
	// initializing dp with -1 
	memset(dp, -1, sizeof(dp)); 

	// storing digits of a-1 in digit vector 
	vector<int> digitA; 
	getDigits(a-1, digitA); 

	// Finding sum of digits from 1 to "a-1" which is passed 
	// as digitA. 
	long long ans1 = digitSum(digitA.size()-1, 0, 1, digitA); 

	// Storing digits of b in digit vector 
	vector<int> digitB; 
	getDigits(b, digitB); 

	// Finding sum of digits from 1 to "b" which is passed 
	// as digitB. 
	long long ans2 = digitSum(digitB.size()-1, 0, 1, digitB); 

	return (ans2 - ans1); 
} 

int32_t main(){
  ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

    /*
        problem statement==  find the sum of digit of all number between the range a and b like  5-10 == (5+6+7+8+9+1+0)
	*/
     
     /*
         looking recursive type
         how to think dp
         
         suppose non tight number  like 05_     solution --> 05+000,05+001,05+002.......... here ix=1 and presum=5
         
         suppose another non tight number  like 23_  solution --> (2+3)+000,(2+3)+001,(2+3)+002,  here ix=1 and presum=5
         
         it means that both will get same sum so we can make state like dp(ix,sum,tight)
         
         res=  summation i=0,i<=k   dp(i+1,sum+i,tight)
	 
	     so result === function(b)-function(a)
	 */
	 
	 
	 // Given two integers a and b. The task is to print 
// sum of all the digits appearing in the 
// integers between a and b 

 
	long long a = 123, b = 1024; 
	cout << "digit sum for given range : "
		<< rangeDigitSum(a, b) << endl; 
 return 0;}


