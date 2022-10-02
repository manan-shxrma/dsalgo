#include <iostream>
#include <ctime>
#include <fstream>
#include <string.h>
#include <cmath>
#include <sstream>

using namespace std;

// classical method class
class BinaryMultiplier
{
public:
	string MakeMultiplication(string,string);	
	string MakeShifting(string,int);			
	string addBinary(string,string);
	void BinaryStringToDecimal(string);
};

// karatsuba method class
class Karatsuba
{
public:
	int lengthController(string &,string &);
	string addStrings(string,string);
	string multiply(string,string);
	string DecimalToBinary(long long int);
	string Subtraction(string,string);
	string MakeShifting(string,int);
};

// this function get strings and go over str2 bit
// if it sees 1 it calculates the shifted version according to position bit
// Makes add operation for binary strings
// returns result string
string BinaryMultiplier::MakeMultiplication(string str1, string str2)
{
	string allSum = "";
	for (int j = 0 ; j<str2.length(); j++)
	{
		int secondDigit = str2[j] - '0';
		if (secondDigit == 1)
		{
			string shifted = MakeShifting(str1,str2.size()-(j+1));
			allSum = addBinary(shifted, allSum);
		}
		else
		{
			continue;
		}
		
	}
	return allSum;
}


// this function adds binary strings with carry
string BinaryMultiplier::addBinary(string a, string b)
{
	string result = "";
	int s = 0;
	
	int i = a.size() - 1;
	int j = b.size() - 1;
	while (i >= 0 || j >= 0 || s == 1)
	{
		s += ((i >= 0)? a[i] - '0': 0);
		s += ((j >= 0)? b[j] - '0': 0);
		
		result = char(s % 2 + '0') + result;
		
		s /= 2;
	
		i--;
		j--;
	}
	return result;
}

// this function shifts the given string according to given number
// returns shifted version
string BinaryMultiplier::MakeShifting(string str, int stepnum)
{
	string shifted = str;
	for (int i = 0 ; i < stepnum ; i++)
		shifted = shifted + '0';
	return shifted;
}

// this function converts Binary String Number to Decimal Number
// After 32 bits it gives 0 because it overflows the size of int
void BinaryMultiplier::BinaryStringToDecimal(string result)
{
	cout<<"Binary Result : "<<result<<endl;
	unsigned long long int val = 0;
	for (int i = result.length()-1; i >= 0; i--)
	{
		if (result[i] == '1')
		{
			val += pow(2,(result.length()-1)-i);
		}
	}
	cout<<"Decimal Result (Not proper for Large Binary Numbers):" <<val<<endl;
}

// this function controls lengths of strings and make their lengths equal
// returns the maximum length
int Karatsuba::lengthController(string &str1, string &str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 < len2)
	{
		for (int i = 0 ; i < len2 - len1 ; i++)
			str1 = '0' + str1;
		return len2;
	}
	else if (len1 > len2)
	{
		for (int i = 0 ; i < len1 - len2 ; i++)
			str2 = '0' + str2;
	}
	return len1;
}

// this function add strings with carry
// uses one by one bit addition methodology
// returns result string
string Karatsuba::addStrings(string first, string second)
{
	string result; // To store the sum bits
	
	// make the lengths same before adding
	int length = lengthController(first, second);
	int carry = 0; // Initialize carry
	
	// Add all bits one by one
	for (int i = length-1 ; i >= 0 ; i--)
	{
		int firstBit = first.at(i) - '0';
		int secondBit = second.at(i) - '0';
		
		// boolean expression for sum of 3 bits
		int sum = (firstBit ^ secondBit ^ carry)+'0';
		
		result = (char)sum + result;
		
		// Boolean expression for 3-bit addition
		carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry);
	}
	
	// if overflow, then add a leading 1
	if (carry)
	{
		result = '1' + result;
	}
	
	return result;
}

// this function converts decimal number to binary string
string Karatsuba::DecimalToBinary(long long int number)
{
	string result = "";
	if (number <= 0)
	{
		return "0";
	}
	else
	{
		int i = 0;
		while (number > 0)
		{
			
			long long int num= number % 2;
			stringstream ss;
			ss<<num;
			result = ss.str() + result;
			number = number / 2;
			i++;
		}
		return result;
		
	}
}

// this function makes binary string subtraction with overflow
string Karatsuba::Subtraction(string lhs, string rhs)
{
	
	int length = lengthController(lhs, rhs);
	int diff;
	string result;
	
	for (int i = length-1; i >= 0; i--)
	{
		diff = (lhs[i]-'0') - (rhs[i]-'0');
		if (diff >= 0)
		{
			result = DecimalToBinary(diff) + result;
		}
		else
		{
			for (int j = i-1; j>=0; j--)
			{
				lhs[j] = ((lhs[j]-'0') - 1) % 10 + '0';
				if (lhs[j] != '1')
				{
					break;
				}
			}
			result = DecimalToBinary(diff+2) + result;
		}
	}
	return result;
}

// this function makes shifting
string Karatsuba::MakeShifting(string str, int stepnum)
{
	string shifted = str;
	for (int i = 0 ; i < stepnum ; i++)
		shifted = shifted + '0';
	return shifted;
}

// this function is the core of the Karatsuba
// divides problem into 4 subproblems
// recursively multiplies them
// returns the result string
string Karatsuba::multiply(string X, string Y)
{
	int n = lengthController(X, Y);
	
	if (n == 1) return ((Y[0]-'0' == 1) && (X[0]-'0' == 1)) ? "1" : "0";
	
	int fh = n/2; // First half of string, floor(n/2)
	int sh = (n-fh); // Second half of string, ceil(n/2)
	
	// Find the first half and second half of first string.
	string Xl = X.substr(0, fh);
	string Xr = X.substr(fh, sh);
	
	// Find the first half and second half of second string
	string Yl = Y.substr(0, fh);
	string Yr = Y.substr(fh, sh);
	
	// Recursively calculate the three products of inputs of size n/2
	string P1 = multiply(Xl, Yl);
	string P2 = multiply(Xr, Yr);
	string P3 = multiply(addStrings(Xl, Xr), addStrings(Yl, Yr));
	
	// return added string version
	return addStrings(addStrings(MakeShifting(P1, 2*(n-n/2)),P2),MakeShifting(Subtraction(P3,addStrings(P1,P2)), n-(n/2)));
}


int main(int argc, const char * argv[])
{
	// get the binary numbers as strings
	string firstNumber,secondNumber;

	cout<<"Please give the First Binary number : ";
	cin>>firstNumber;
	cout<<endl<<"Please give the Second Binary number : ";
	cin>>secondNumber;
	cout << endl;
	

	// make the initial lengths equal by adding zeros
	int len1 = firstNumber.size();
	int len2 = secondNumber.size();
	int general_len = firstNumber.size();
	
	if (len1 < len2)
	{
		for (int i = 0 ; i < len2 - len1 ; i++)
			firstNumber = '0' + firstNumber;
		general_len = firstNumber.size();
	}
	else if (len1 > len2)
	{
		for (int i = 0 ; i < len1 - len2 ; i++)
			secondNumber = '0' + secondNumber;
		general_len = secondNumber.size();
	}
	
	// In classical methodology Binary String Multiplication
	cout<<"Classical Algorithm : "<<endl;
	BinaryMultiplier newobj;
	const clock_t classical_time = clock();
	string classic = newobj.MakeMultiplication(firstNumber, secondNumber);
	cout << float( clock () - classical_time ) / CLOCKS_PER_SEC<<endl<<endl;
	float c_time = float( clock () - classical_time ) / CLOCKS_PER_SEC;
	newobj.BinaryStringToDecimal(classic);
	
	// Using Karatsuba Multiplication Algorithm Binary String Multiplication
	cout<<endl<<"Karatsuba Algorithm : "<<endl;
	Karatsuba obj;
	const clock_t karatsuba_time = clock();
	string karatsuba = obj.multiply(firstNumber, secondNumber);
	cout << float( clock () - karatsuba_time ) / CLOCKS_PER_SEC<<endl<<endl;
	float k_time = float( clock () - classical_time ) / CLOCKS_PER_SEC;
	newobj.BinaryStringToDecimal(karatsuba);
	
	return 0;
}
