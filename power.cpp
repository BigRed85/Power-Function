#include <iostream>
#include <iomanip>
using namespace std;



double power(double base, double exponent);

double simplePower(double base, int exponent);

double nthRoot(double base, unsigned int root);

void simplify( int& numerator, unsigned int& denominator);

bool isPrime( int n );

const unsigned int PRECISION = 10000;

int TEMP = 0;

int main()
{
	double base;
	double exponent;
	cout << "Base: ";
	cin >> base;
	cout << "Exponent: ";
	cin >> exponent;
	cout << endl;
	cout << setprecision(100) << power( base, exponent ) << endl;
	
	return 0;
}

double power(double base, double exponent)
{
	long double product = base;
	long double productFinal = 1;
	unsigned int root = 1;
	
	bool simplified = false;
	
	int exp = exponent * PRECISION;
	root = PRECISION;
	
	cout << exp << " " << root << endl;
	
	simplify(exp, root);
	
	cout << exp << " " << root << endl;


	product = simplePower(base, exp);
	product = nthRoot(product, root);
	
	productFinal = simplePower(base, exponent);
	productFinal *= product;
	
	
	return productFinal;
}


double simplePower(double base, int exponent)
{
	double product = 1;
	  
	if (exponent > 0)
	{
		for (int i = 1; i <= exponent; i++)
		{
			product *= base;
		}
			
		
	}
	else if (exponent < 0)
	{
		for (int i = 1; i <= -exponent; i++)
		{
			product /= base; 
		}
	}
	return product;
}

double nthRoot(double base, unsigned int root)
{
	const unsigned int ITERATIONS = 100;
	unsigned int count = 0;
	
	
	long double x = 1;
	long double last1 = 0;
	long double last2 = 0;
	
	while (x != last1 && x != last2 && count < 1000 )
	{
		count++;
		last2 = last1;
		last1 = x;
		x = x - (( simplePower(x, root) - base ) / ( root * simplePower(x, root - 1)));
		
		cout << setprecision(100) << x <<endl;
		
	}		
	
	
	
	return x;
}

void simplify(int& n, unsigned int& d)
{
	
	
	int a = 0, b = 1, c = 1, d1 = 1, e = 1;
	
	double temp = (double)n / (double)d;
	
	
	temp = temp - (int)temp;
	
	if (temp > 0.00001)
	{
		temp = 1 / temp;
		b = (int)temp;
		temp = temp - (int)temp;
		
		d = b;
		n = a * b + 1;
		
		cout << "1" << endl;
		
		if (temp > 0.00001)
		{
			cout << "2" << endl;
			
			temp = 1 / temp;
			c = (int)temp;
			temp = temp - (int)temp;
			
			d = b * c + 1;
			n = a * (b * c + 1) + c;
			
			if (temp > 0.00001)
			{
				cout << "3" << endl;
				
				temp = 1 / temp;
				d1 = (int)temp;
				temp = temp - (int)temp;
				
				d = b * ( c * d1 + 1 ) + d1;
				n = a * ( b * ( c * d1 + 1 ) + d1 ) + c * d1 + 1;
				
				if (temp > 0.00001)
				{
					cout << "4" << endl;
					
					temp = 1 / temp;
					e = (int)temp;
					temp = temp - (int)temp;
					
					d = b * ( c * ( d1 * e + 1 ) + e ) + d1 * e + 1;
					n = a * ( b * ( c * (d1 * e + 1 ) + e ) + d1 * e + 1 ) + c * (d1 * e + 1 ) + e;
					
					cout << a << " " << b << " " << c << " " << d1 << " " << e << endl;
				}
			}
			
			
			
		}
	}
	
	
	
}

bool isPrime( int n )
{
	for (int count = 2; count < n; count++)
	{
		if ( n % count == 0 )
		{
			return false;
		}
	}

	return true;
}