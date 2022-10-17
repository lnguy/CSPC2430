#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

void ramanujan(int depth, double prev_sum);
int doubleInt(int x);
int halveInt(int x);
void egyptDivision(int dividend, int divisor);
void root5(int n, double guess);
int sumDigits(int n);

int main()
{
	cout << sumDigits(567) << endl;
	root5(250, 1);
	egyptDivision(1960, 56);
	ramanujan(100, 0);
}

//
//////////////// Part 2 ////////////////
//

int sumDigits(int n)
{
	if (n < 1) // base case (not an integer)
	{
		return 0;
	}
	else
	{
		return (n%10) + sumDigits(n/10); // modulo to take digit on the right, and integer division to remove the digit on the right
	}
}

//
//////////////// Part 3 ////////////////
//

void root5(int n, double guess)
{
	double calc = (double) (1.0/5.0)*((4*guess)+(n/(pow(guess, 4))));
	if (abs(pow(guess, 5)-n)< 0.00001)
	{
		cout << guess << endl;
		return;
	}
	root5(n, calc);
}

//
//////////////// Part 4 ////////////////
//
void egyptDivision(int dividend, int divisor)
{
	int a = 1;
	int b = divisor;
	int c = dividend;
	int d = 0;
	
	while(b <= c)
	{
		a = doubleInt(a);
		b = doubleInt(b);
	}
	while(c > 1)
	{
		if(b <= c)
		{
			c = c-b;
			d = d+a;
		}
		a = halveInt(a);
		b = halveInt(b);
	}
	cout << d << endl;
}

int doubleInt(int x)
{
	return x+x;
}

int halveInt(int x)
{
	if(x == 0) // checks for base case
	{
		return 0;
	}
	else if ((x-1) == 0) // checks for case before the base case
	{
		return 0;
	}
	else // recrusive call until base case
	{
		return 1 + halveInt(x-2);
	}
}

//
//////////////// Part 5 ////////////////
//
void ramanujan(int depth, double prev_sum)
{
	double sum = 6 + depth + prev_sum;
	double result = sqrt(sum)*(depth+1);
	
	if (depth == 0)
	{
		cout << result;
		return;
	}
	ramanujan(depth-1, result);
	
}

// At infinity it converges to 4.