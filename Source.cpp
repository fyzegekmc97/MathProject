using namespace std ;

#include <cmath>
#include <math.h>
#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>

/*
	Important Notice: Large integers are dealt by using vectors with each vector element containing 3 digits, where the higher order digits are stored in vector elements 
	indexed by smaller numbers, e.g 123456 is stored as [123, 456]

	Note 1: Function explanations are given next to the definition of each function, not next to the prototypes.

	Note 2: Progress of each function is given next to the prototypes.

	Note 3: Phases are given in radians and all trig functions take radians as input parameters.

	Note 4: Doubles are used when found necessary for large integers, instead of the afore-mentioned method of storing large integers.
*/

//Global variables

const double pi = 3.141592653589793238 ;
const double natural_number = 2.7182818284 ;
const double pythagoras_constrant = sqrt(2.0) ;
short int non_str_int_digit_count = 9 ;

//Global variables end

//Function prototypes 

string ReturnCompleteIntegerString(string number); //Done, Tested
double RadiansToDegrees(double rad_val) ; //Tested
double DegreesToRadians(double degree_val) ; //Tested
double ReturnEquivalentAngle(double x) ; //Tested
double sec(double x) ; //Tested
double cosec(double x) ; //Tested
double ln(double x) ; //Tested
double cot(double x) ;
double coth(double x) ;
double NumericalDifferentiator(int func_to_differentiate, double x, int precision) ;
double SimpsonsRule(int function_to_approximate, double begin_val, double end_val) ;
double NumericalIntegrator(int func_to_integrate, double interval_begin, double interval_end, int precision) ;
double TaylorApproximator(int function_to_approximate, int degree_to_approximate, bool isMacLaurin, double point_to_approximate_around, double point); //In progress
string factorial(string num_to_factorialize) ; //Done, Tested, Room for improvement
double factorial_double(int num_to_factorialize) ; 
string RemoveInsignificantZerosLeft(string str_to_format) ;
vector<int> returnLargeInteger(string largeintegerstr) ; //Done, Tested
vector<string> returnLargeIntegerStr(string largeintegerstr) ; //Done, Tested
vector<int> zeros(int num_of_zeros) ; //Done, Tested
string zeros_str(int num_of_zeros) ; //Done, Tested
bool FirstStrGreaterThanSecond(string str1, string str2) ; //Indirectly tested within another function test
bool SecondStrGreaterThanFirst(string str1, string str2) ; //Indirectly tested within another function test
bool StringsEqual(string str1, string str2) ; //Indirectly tested within another function test
vector<int> ones(int num_of_ones) ; //Done, Tested
string ones_str(int num_of_ones) ; //Done,Tested
string NormalizeStrings(string string1, string string2, int str_flag) ; //In progress
string PadZerosLeft(string str_to_pad, int zeros_to_add) ; //Done, Tested
string PadZerosRight(string str_to_pad, int zeros_to_add) ; //Done, Tested
string AddWithoutCarry(string number1, string number2, string carry_in) ; //Done, Tested
string ReturnCarry(string number1, string number2, string carry_in) ; //Done, Tested
vector<string> AddTwoIntegerStrings(string number1, string number2) ; //In progress
string AddTwoIntegerStringsString(string number1, string number2) ;
string SubtractStrings(string number1, string number2, string borrow) ;
vector<string> SubtractLargeIntegers(string number1, string number2) ;
bool IsGreater(string number1, string number2) ;
string SubtractLargeIntegersString(string number1, string number2) ;
bool NeedsBorrow(string number1, string number2) ;
string AddSingleDigitWithoutCarryReturn(char digit1, char digit2, char carry_digit) ;
string ReturnCarrySingleDigit(char digit1, char digit2, char carry_digit) ;
char AddSingleDigitWithoutCarryReturnChar(char digit1, char digit2, char carry_digit) ;
char ReturnCarrySingleDigitChar(char digit1, char digit2, char carry_digit) ;
string MultiplyLargeIntegers(string number1, string number2) ;
string DivideLargeIntegers(string number1, string number2) ;
string DivideSmallIntegers(string number1, string number2) ;
string DivideLargeIntegersRemainder(string number1 , string number2) ;
double polyval(double poly_coef[], double eval_point) ;
double polyval_vector(vector<double> poly_coef, double eval_point);
double dot_product(vector<double> vector1, vector<double> vector2) ;
void MyPlayFunc() ;
//Function prototypes end

//Class declerations

class ComplexNumber
{
	public:
		double realPart ;		
		double imaginaryPart ;
		bool isreal ;
		bool isimaginary ;
		double magnitude ;
		double phase ;
		void SetRealAndImaginaryParts(double real_part, double imaginary_part)
		{
			
			realPart = real_part ;
			imaginaryPart = imaginary_part ;
			isreal = ( imaginary_part == 0 ) ;
			isimaginary = ( real_part == 0 ) ;
			magnitude = sqrt((real_part*real_part) + (imaginary_part*imaginary_part)) ;
			phase = atan(imaginary_part) ; //Phase in radians

		}

};

//Class decleration end


int main()
{

	double number1 = 10*pi/2 ;

	MyPlayFunc() ;

	MyPlayFunc() ;

	cin >> number1 ;

	return 0 ;

}

string ReturnCompleteIntegerString(string number)
{
	bool char_is_integer = true ;
	int wrong_char_index = 0 ;
	string str_to_replace ;
	
	for(int index = 0 ; index < number.length() ; index++)
	{
		char_is_integer = (number[index] == '0') || (number[index] == '1') || (number[index] == '2') || (number[index] == '3') || (number[index] == '4') || (number[index] == '5') ||
			(number[index] == '6') || (number[index] == '7') || (number[index] == '8') || (number[index] == '9');
		if(char_is_integer)
		{
			
			continue ;

		}
		while(!char_is_integer)
		{
			
			cout << "Char at position " << index+1 << " is not an integer. Enter an integer value: " ;
			cin >> str_to_replace ;
			cout << endl ;
			while (str_to_replace.length() != 1)
			{

				cout << "Entered value must be char. Enter a char: " ;
				cin >> str_to_replace ; cout << endl ;

			}
			char_is_integer = (str_to_replace[0] == '0') || (str_to_replace[0] == '1') || (str_to_replace[0] == '2') || (str_to_replace[0] == '3') || (str_to_replace[0] == '4') || (str_to_replace[0] == '5') ||
			(str_to_replace[0] == '6') || (str_to_replace[0] == '7') || (str_to_replace[0] == '8') || (str_to_replace[0] == '9') ;
		}
		number.replace(index,1,str_to_replace) ;
	}
	
	return number ;
}

double RadiansToDegrees(double rad_val)
{
	bool greater_than_two_pi = (rad_val > (2*pi)) ;
	
	while(greater_than_two_pi)
	{
		rad_val = rad_val - 2*pi ;
		greater_than_two_pi = (rad_val > (2*pi)) ;
	}

	return (180*rad_val/pi) ;
}

double DegreesToRadians(double degree_val)
{
	
	bool greater_than_360 = (degree_val > 360) ;

	while(greater_than_360)
	{
		degree_val = degree_val - 360 ;
		greater_than_360 = (degree_val > 360) ;

	}

	return (degree_val*pi/180) ;

}

double ReturnEquivalentAngle(double x)
{
	bool num_greater_than_two_pi = (x > 2*pi) ;
	while(num_greater_than_two_pi)
	{
		
		x = x - 2*pi ;
		num_greater_than_two_pi = (x > 2*pi) ;
		
	}
	return x ;
}

double sec(double x)
{
	if((ReturnEquivalentAngle(x) == pi/2) || (ReturnEquivalentAngle(x) == 3*pi/2))
	{
		
		cout << "Returning a NaN" ;
		return 0  ;
	}

	return 1/cos(x) ;

}

double cosec(double x)
{
	if((ReturnEquivalentAngle(x) == 0) || (ReturnEquivalentAngle(x) == pi))
	{
		
		cout << "Returning a NaN" ;
		return 0  ;
	}

	return 1/sin(x) ;	

}

double ln(double x)
{
	
	return log10(x) / log10(natural_number) ;

}

double cot(double x)
{
	if( (ReturnEquivalentAngle(x) == pi) || (ReturnEquivalentAngle(x) == 0) )
	{
		
		cout << "Cotangent not defined here" ;
		return 0 ;
		
	}

	return 1/tan(x) ;

}

double coth(double x)
{
	if(x == 0)
	{
		cout << "Function undefined for x = 0" << endl ;
		return 0 ;
	}

	return 1/tanh(x) ;

}

double NumericalDifferentiator(int func_to_differentiate, double x, int precision)
{
	/*  
		Notice: For this function, the method of central difference is used, where f'(x) is the limit of (f(x+h) - f(x-h))/(2*h) as h goes to 0.
		Note 1: This function can only find the first order derivative. Higher orders will be implemented within other functions.		
		
	*/
	double temp_out = 0 ;
	double h = pow(0.1,precision) ;
	bool yes_or_no = 0 ;
	if(precision < 3)
	{
		
		cout << "Recommended precision value is at least 3. Are you sure to continue with this precision value? Enter 1 if yes and 0 if no." << endl ;
		cin >> yes_or_no ; 
		
		while(yes_or_no == 0)
		{
			cout << "Entered value is smaller than 3. Enter new value: " ;
			cin >> precision ;
			yes_or_no = (precision >= 3) ;
		}

	}

	switch(func_to_differentiate)
	{
		case 0:
			temp_out = 0 ;
			cout << "Function is sine" << endl ;
			temp_out = (sin(x+h)-sin(x-h)) / (2*h) ;
			break;

		case 1:
			temp_out = 0 ;
			cout << "Function is cosine" << endl ;
			temp_out = (cos(x+h)-cos(x-h)) / (2*h) ;
			break;

		case 2:
			temp_out = 0 ;
			cout << "Function is tangent" << endl ;
			if( (ReturnEquivalentAngle(x) == pi/2) || (ReturnEquivalentAngle(x) == 3*pi/2) || (ReturnEquivalentAngle(x+h) == pi/2) || (ReturnEquivalentAngle(x+h) == 3*pi/2) || (ReturnEquivalentAngle(x-h) == pi/2) || (ReturnEquivalentAngle(x-h) == 3*pi/2) )
			{

				cout << "Derivative is not defined for this point" ;
				return 0 ;
				
			}
			temp_out = (tan(x+h)-tan(x-h)) / (2*h) ;
			break ;
		case 3:
			temp_out = 0 ;
			cout << "Function is cotangent" << endl ;
			if( (ReturnEquivalentAngle(x) == pi) || (ReturnEquivalentAngle(x) == 0) || (ReturnEquivalentAngle(x+h) == pi) || (ReturnEquivalentAngle(x+h) == 0) || (ReturnEquivalentAngle(x-h) == pi) || (ReturnEquivalentAngle(x-h) == 0) )
			{

				cout << "Derivative is not defined for this point" ;
				return 0 ;
				
			}
			temp_out = (cot(x+h)-cot(x-h)) / (2*h) ;
			break ;

		case 4:
			temp_out = 0 ;
			cout << "Function is the natural number raised to the power x" << endl ;
			temp_out = ( ( pow(natural_number, (x+h) ) ) - ( pow(natural_number, x ) ) ) / (2*h) ;
			break ;

		case 5:
			temp_out = 0 ;
			cout << "Function is natural log of x" << endl ;
			if( (x+h == 0) || (x-h == 0) || (x == 0) || (x < 0) )
			{
				
				cout << "Derivative is not defined for this point" ;
				return 0 ;
				
			}
			temp_out = (ln(x+h) - ln(x-h)) / (2*h) ;
			break ;

		case 6:
			temp_out = 0 ;
			cout << "Function is log with base 10" << endl ;
			if( (x+h == 0) || (x-h == 0) || (x <= 0 ) )
			{
				cout << "Derivative is not defined for this point" ;
				return 0 ;
			}
			temp_out = (log10(x+h) - log(x-h)) / (2*h) ;
			break ;
		case 7:
			temp_out = 0 ;
			cout << "Function is cosh" << endl ;
			temp_out = (cosh(x+h) - cosh(x-h)) / (2*h) ;
			break ;
		case 8:
			temp_out = 0 ;
			cout << "Function is sinh" << endl ;
			temp_out = (sinh(x+h) - sinh(x-h)) / (2*h) ;
			break ;
		case 9:
			temp_out = 0 ;
			cout << "Function is tanh" << endl ;
			temp_out = (tanh(x+h) - tanh(x-h)) / (2*h) ;
			break ;
		case 10:
			temp_out = 0 ;
			cout << "Function is coth" ;
			if( (x+h == 0) || (x-h == 0) || ( x == 0 ) )
			{
				cout << "Derivative is not defined for this point." ;
				return 0 ;
			}
			temp_out = (coth(x+h) - coth(x-h)) / (2*h) ;
			break ;
		default:

			return 0 ;

			break;
			
			
			
	}
	return temp_out ;


}

double SimpsonsRule(int function_to_approximate, double begin_val, double end_val)
{
	
	
	return 0 ;
}

double NumericalIntegrator(int func_to_integrate, double interval_begin, double interval_end, int precision)
{
	double temp_out = 0 ;
	double h = pow(0.1,precision) ;
	bool yes_or_no = 0 ;
	if(precision < 3)
	{
		
		cout << "Recommended precision value is at least 3. Are you sure to continue with this precision value? Enter 1 if yes and 0 if no." << endl ;
		cin >> yes_or_no ; 
		
		while(yes_or_no == 0)
		{
			cout << "Entered value is smaller than 3. Enter new value: " ;
			cin >> precision ;
			yes_or_no = (precision >= 3) ;
		}

	}
	switch(func_to_integrate)
	{
		case 0:
			temp_out = 0 ;
			cout << "Function is sine" << endl ;
			
			break;

		case 1:
			temp_out = 0 ;
			cout << "Function is cosine" << endl ;
			
			break;

		case 2:
			temp_out = 0 ;
			cout << "Function is tangent" << endl ;
			
			break ;
		case 3:
			temp_out = 0 ;
			cout << "Function is cotangent" << endl ;
			
			break ;

		case 4:
			temp_out = 0 ;
			cout << "Function is the natural number raised to the power x" << endl ;
			
			break ;

		case 5:
			temp_out = 0 ;
			cout << "Function is natural log of x" << endl ;
			
			break ;

		case 6:
			temp_out = 0 ;
			cout << "Function is log with base 10" << endl ;
			
			break ;
		case 7:
			temp_out = 0 ;
			cout << "Function is cosh" << endl ;
			
			break ;
		case 8:
			temp_out = 0 ;
			cout << "Function is sinh" << endl ;
			
			break ;
		case 9:
			temp_out = 0 ;
			cout << "Function is tanh" << endl ;
			
			break ;
		case 10:
			temp_out = 0 ;
			cout << "Function is coth" ;
			
			break ;
		default:

			return 0 ;

			break;
			
	}

}

double TaylorApproximator(int function_to_approximate, int degree_to_approximate, bool isMacLaurin, double point_to_approximate_around, double point)
{
	/* 
		Notice: If the flag "isMacLaurin" is set to 1, the parameter point_to_approximate_around is overwritten by a value of 0.
		
	*/
	double temp_out = 0 ;

	while(degree_to_approximate < 1)
	{
		
		cout << "Taylor series can't be evaluated for nonpositive values. Enter a value greater than or equal to 1: " ; cin >> degree_to_approximate ;
		cout << endl ; 
		
	}

	if(isMacLaurin == 1)
	{
					
		point_to_approximate_around = 0 ;
					
	}
	else
	{

		point_to_approximate_around = point_to_approximate_around ;
					
	}

	switch(function_to_approximate)
	{
		case 0:
			temp_out = 0 ;
			cout << "Function is sine" << endl ;
			
			for(int i = 1 ; i <= degree_to_approximate ; i++)
			{
				
				temp_out += pow((point - point_to_approximate_around),i)*sin(point_to_approximate_around + pi*i/2)/factorial_double(i) ;
				
			}
			
			break;

		case 1:
			temp_out = 0 ;
			cout << "Function is cosine" << endl ;

			for(int i = 1 ; i <= degree_to_approximate ; i++)
			{
				
				temp_out += pow((point-point_to_approximate_around),i)*cos(point_to_approximate_around + i*pi/2)/factorial_double(i) ;
				
			}

			break;

		case 2:
			temp_out = 0 ;
			cout << "Function is tangent" << endl ;
			



			break ;
		case 3:
			temp_out = 0 ;
			cout << "Function is cotangent" << endl ;

			break ;

		case 4:
			
			temp_out = 0 ;
			cout << "Function is the natural number raised to the power x" << endl ;
			
			for(int i = 1 ; i <= degree_to_approximate ; i++)
			{
				
				temp_out += pow(natural_number,point_to_approximate_around)*pow((point - point_to_approximate_around) , i)/factorial_double(i) ;
				
			}

			break ;

		case 5:
			temp_out = 0 ;
			cout << "Function is natural log of x" << endl ;
			while((point == -point_to_approximate_around) || (point_to_approximate_around == 0))
			{
				
				cout << "Logarithm of 0 is undefined. Reenter the point to evaluate the series aorund and the point to plug into the series: " << endl ;
				cout << "Enter the point to evalue the series around: " ; cin >> point_to_approximate_around ; cout << endl ;
				cout << "Enter the point to plug into the series: " ; cin >> point ; cout << endl ;

			}

			for(int i = 1 ; i <= degree_to_approximate ; i++)
			{
				
				temp_out += pow((-1),(1+i))*pow(point_to_approximate_around,(-i))*pow((point-point_to_approximate_around),i)/i ;
				
			}
			temp_out += log10(point_to_approximate_around) ;
			break ;

		case 6:
			temp_out = 0 ;
			cout << "Function is log with base 10" << endl ;
			while((point == -point_to_approximate_around) || (point_to_approximate_around == 0))
			{
				
				cout << "Logarithm of 0 is undefined. Reenter the point to evaluate the series aorund and the point to plug into the series: " << endl ;
				cout << "Enter the point to evalue the series around: " ; cin >> point_to_approximate_around ; cout << endl ;
				cout << "Enter the point to plug into the series: " ; cin >> point ; cout << endl ;

			}

			for(int i = 1 ; i <= degree_to_approximate ; i++)
			{
				
				temp_out += pow((-1),(1+i))*pow(point_to_approximate_around,(-i))*pow((point-point_to_approximate_around),i)/i ;
				
			}
			temp_out += log10(point_to_approximate_around) ;
			temp_out = temp_out / ln(10) ;

			break ;
		case 7:
			temp_out = 0 ;
			cout << "Function is cosh" << endl ;
			for(int i = 0 ; i < degree_to_approximate ; i++ )
			{
				
				if(i % 2 == 0)
				{
					
					temp_out += pow((point- point_to_approximate_around),i)*cosh(point_to_approximate_around)/factorial_double(i) ;
					
				}
				else
				{
					
					temp_out += pow((point- point_to_approximate_around),i)*sinh(point_to_approximate_around)/factorial_double(i) ;
					
				}

			}
			
			break ;
		case 8:
			temp_out = 0 ;
			cout << "Function is sinh" << endl ;
			for(int i = 0 ; i < degree_to_approximate ; i++ )
			{
				
				if(i % 2 == 0)
				{
					
					temp_out += pow((point- point_to_approximate_around),i)*sinh(point_to_approximate_around)/factorial_double(i) ;
					
				}
				else
				{
					
					temp_out += pow((point- point_to_approximate_around),i)*cosh(point_to_approximate_around)/factorial_double(i) ;
					
				}

			}
			
			break ;
		case 9:
			temp_out = 0 ;
			cout << "Function is tanh" << endl ;

			temp_out = TaylorApproximator(7,degree_to_approximate,isMacLaurin,point_to_approximate_around,point)/TaylorApproximator(8,degree_to_approximate,isMacLaurin,point_to_approximate_around,point) ;

			break ;
		case 10:

			temp_out = 0 ;
			cout << "Function is coth" ;

			temp_out = 1/TaylorApproximator(9,degree_to_approximate,isMacLaurin,point_to_approximate_around,point) ;

			break ;
		default:

			return 0 ;

			break;
			
			
			
	}
	return temp_out ;
} 

string factorial(string num_to_factorialize)
{
	while(num_to_factorialize[0] == '-')
	{
		
		cout << "Input number can't be negative, enter a nonnegative number: " ; cin >> num_to_factorialize ; cout << endl ;
		
	}

	if((num_to_factorialize == "0") || (num_to_factorialize == "1"))
	{
		
		return "1" ;
		
	}

	string temp_out = "1" ;
	bool cont_condition = num_to_factorialize.compare("0") != 0 ;
	while(cont_condition)
	{
		temp_out = MultiplyLargeIntegers(temp_out,num_to_factorialize);
		num_to_factorialize = SubtractLargeIntegersString(num_to_factorialize,"1") ; //Problem here
		cont_condition = num_to_factorialize.compare("0") != 0 ;
	}
	return temp_out ;
}

double factorial_double(int num_to_factorialize)
{
	double temp_out = 1 ;
	while(num_to_factorialize < 0)
	{
		
		cout << "Entered negative number. Enter a nonnegative number: " ; cin >> num_to_factorialize ; cout << endl ;
		
	}

	if((num_to_factorialize == 0) || (num_to_factorialize == 1))
	{
		
		return 1 ;
		
	}
	else
	{
		
		for( int i = 1 ; i <= num_to_factorialize ; i++ )
		{
			
			temp_out *= i ;
			
		}
		return temp_out ;
	}
}

string RemoveInsignificantZerosLeft(string str_to_format)
{
	if(str_to_format == "")
	{
		
		return "" ;

	}
	bool digit_is_zero = (str_to_format[0] == '0') ;
	while(digit_is_zero)
	{

		str_to_format.erase(0,1) ;
		if(str_to_format == "")
		{
		
			return "" ;

		}
		digit_is_zero = (str_to_format[0] == '0') ;
	}
	return str_to_format ;
}

vector<int> returnLargeInteger(string largeintegerstr)
	{
		//Initialize variables
		int stringsize = largeintegerstr.size() ;
		vector<int> integer_vector ;
		int vector_size = stringsize / 3 ;
		//Initialization end


		//Push vector elements into vector
		for(int index = 0 ; index < stringsize ; index = index + 3)
		{
			
			integer_vector.push_back(stoi(largeintegerstr.substr(index , 3))) ;
			
		}
		//End of push

		return integer_vector ;
	}

vector<string> returnLargeIntegerStr(string largeintegerstr)
{
	vector<string> temp_out ;
	int zero_to_add = (largeintegerstr.length() % 3 == 0) ? 0 : 3 - (largeintegerstr.length() % 3) ;
	largeintegerstr = PadZerosLeft(largeintegerstr, zero_to_add) ; 
	for(int index = 0 ; index < largeintegerstr.length() ; index = index + 3)
	{

		temp_out.push_back(largeintegerstr.substr(index,3)) ;
		
	}
	return temp_out ;
}

vector<int> zeros(int num_of_zeros)
{
	int zero = 0 ;
	vector<int> temp ;
	if(num_of_zeros == 0)
	{
		
		return temp ;

	}
	else
	{
		
		for(int index = 0 ; index < num_of_zeros ; index++)
		{
		
			temp.push_back(zero) ; 

		}
		return temp ;
	}
}

string zeros_str(int num_of_zeros)
{
	int zero = 0 ;
	string str_to_add = to_string(zero) ;
	string temp = "" ; 
	
	if(num_of_zeros == 0)
	{
		
		return "" ; 
		
	}
	else
	{
		
		for(int index = 0 ; index < num_of_zeros ; index++)
			{
		
				temp = temp + str_to_add ; 
		
			}
		return temp ;
	}
}

bool FirstStrGreaterThanSecond(string str1, string str2)
{
	
	if(str1.size() > str2.size())
	{
		
		return true ; 

	}
	else
	{
		
		return false ;
		
	}

}

bool SecondStrGreaterThanFirst(string str1, string str2)
{
	
	if(str2.size() > str1.size())
	{
		
		return true ;

	}
	else
	{
		return false ;
	}




}

bool StringsEqual(string str1, string str2)
{
	if(str1.size() == str2.size())
	{
		
		return true ;

	}
	else
	{
		
		return false ;

	}
}

vector<int> ones(int num_of_ones)
{
	
	vector<int> temp ;
	int one = 1 ;
	
	if(num_of_ones == 0)
	{
		return temp ;
	}
	else
	{
		for(int index = 0 ; index < num_of_ones ; index++)
			{
		
				temp.push_back(one) ;

			}
		return temp ;
	}
}

string ones_str(int num_of_ones)
{
	int one = 1 ;
	string str_to_add = to_string(one) ;
	string temp = "" ;

	if(num_of_ones == 0)
	{
		
		return "" ;

	}
	else
	{
		
		for(int index = 0 ; index < num_of_ones ; index++)
		{
			
			temp = temp + str_to_add ;

		}
		return temp ;
	}
}

string NormalizeStrings(string string1, string string2, int str_flag)
{
		
	int string1_size = string1.size(), string2_size = string2.size() ;
	int str_len_diff = (string1_size >= string2_size) ? (string1_size - string2_size) : (string2_size - string1_size) ;
	
	if(str_flag == 1)
	{

		if(FirstStrGreaterThanSecond(string1,string2) || StringsEqual(string1,string2))
		{
			return string1 ;
		}
		else
		{
			return zeros_str(str_len_diff) + string1 ;
		}

	}
	else if(str_flag == 2)
	{

		if(SecondStrGreaterThanFirst(string1,string2) || StringsEqual(string1,string2))
		{
		
			return string2 ;
		
		}
		else
		{

			return zeros_str(str_len_diff) + string2 ;
			
		}
	}
	else
	{
		
		cout << "Invalid flag or forgotten flag" << endl ;
		while((str_flag != 1) || (str_flag != 2))
		{
			cout << "Enter a new flag: " ;
			cin >> str_flag ;
		}
		NormalizeStrings(string1,string2,str_flag) ;
	}
	
}

string PadZerosLeft(string str_to_pad, int zeros_to_add)
{
	if(zeros_to_add > 0)
	{
		for(int index = 0 ; index < zeros_to_add ; index++)
		{
		
			str_to_pad = "0" + str_to_pad ;
		
		}
		return str_to_pad ;
	}
	else
	{
		return str_to_pad ;
	}
	
}

string PadZerosRight(string str_to_pad, int zeros_to_add)
{
	
	if(zeros_to_add > 0)
	{
		for(int index = 0 ; index < zeros_to_add ; index++)
		{
		
			str_to_pad = str_to_pad + "0" ;
		
		}
		return str_to_pad ;
	}
	else
	{
		return str_to_pad ;
	}
	
	
}

string AddWithoutCarry(string number1, string number2, string carry_in)
{
	while((number1.length() > 3 ) || (number2.length() > 3) || (carry_in.length() > 3))
	{
		cout << "All numbers can have 3 digits at most, reenter the numbers below." << endl ;
		cout << "Number1: " ; cin >> number1 ; cout << endl ;
		cout << "Number2: " ; cin >> number2 ; cout << endl ;
		cout << "Input carry: " ; cin >> carry_in ;
	}
	int temp_num = 0, num1 = stoi(number1), num2 = stoi(number2), carry_int = stoi(carry_in);
	temp_num = num1 + num2 + carry_int ;
	string temp_str = to_string(temp_num) ;
	int zero_to_add = 0 ;
	if(temp_str.length() > 3)
	{

		temp_str = temp_str.substr( temp_str.length() - 3 , 3 ) ;
		return temp_str ;
	}
	else if(temp_str.length() == 3)
	{
		
		return temp_str ;
		
	}
	else
	{
		zero_to_add = 3 - (temp_str.length() % 3) ;
		return PadZerosLeft(temp_str,zero_to_add) ;

	}
}

string ReturnCarry(string number1, string number2, string carry_in)
{
	while((number1.length() > 3 ) || (number2.length() > 3))
	{
		cout << "Both numbers can have 3 digits at most, reenter the numbers below." << endl ;
		cout << "Number1: " ; cin >> number1 ;
		cout << "Number2: " ; cin >> number2 ;
	}
	int temp_num = 0, num1 = stoi(number1), num2 = stoi(number2), carry_int = stoi(carry_in);
	temp_num = num1 + num2 + carry_int;
	string temp_str = to_string(temp_num) ;
	if(temp_str.length() <= 3)
	{
		return "0" ;
	}
	else
	{
		return temp_str.substr(0,1) ;
	}
}

vector<string> AddTwoIntegerStrings(string number1, string number2)
{
	
	vector<string> temp_out;
	vector<string> vector1 , vector2 ;
	string carry = "0" ;
	string temp_sum = "0" ;
	string temp_sum_str = "" ;

	if(number1[0] == '-')
	{
		if(number2[0] == '-')
		{
			number1 = number1.erase(0,1) ;
			number2 = number2.erase(0,1) ;
			temp_out = AddTwoIntegerStrings(number1,number2) ;
			temp_out.insert(temp_out.begin(),"-") ;

		}
		else
		{

			number1 = number1.erase(0,1) ;
			if(stoi(number1) > stoi(number2))
			{
				
				temp_out = SubtractLargeIntegers(number1,number2) ;
				temp_out.insert(temp_out.begin(),"-") ;
				return temp_out ;
			}
			else
			{
				
				return SubtractLargeIntegers(number2,number1) ;
				
			}
		}

	}
	else if(number2[0] == '-')
	{
		number2 = number2.erase(0,1) ;
		if(stoi(number1) > stoi(number2))
		{
			
			return SubtractLargeIntegers(number1,number2) ;

		}
		else
		{
			temp_out = SubtractLargeIntegers(number2,number1) ;
			temp_out.insert(temp_out.begin(),"-") ;
			return temp_out ;
		}
	}
	//Define string lengths
	int num1_length = number1.length(), num2_length = number2.length(), len_diff ;

	//String length equalization
	if(num1_length < num2_length)
	{
		len_diff = num2_length - num1_length ;
		number1 = PadZerosLeft(number1,len_diff) ;
		vector1 = returnLargeIntegerStr(number1) ;
		vector2 = returnLargeIntegerStr(number2) ;
	}
	else if(num1_length == num2_length)
	{
		len_diff = 0 ;
		vector1 = returnLargeIntegerStr(number1) ;
		vector2 = returnLargeIntegerStr(number2) ;
	}
	else if(num1_length > num2_length)
	{
		len_diff = num1_length - num2_length ;
		number2 = PadZerosLeft(number2, len_diff) ;
		vector1 = returnLargeIntegerStr(number1) ;
		vector2 = returnLargeIntegerStr(number2) ;
	}

	//String length equalization end

	for(int index = vector1.size() - 1 ; index >= 0 ; index--)
	{
		temp_sum = AddWithoutCarry(vector1[index],vector2[index],carry) ;
		carry = ReturnCarry(vector1[index], vector2[index],carry) ;
		temp_out.insert(temp_out.begin(),temp_sum) ;
		if(index == 0)
		{
			if(carry != "0")
			{
				
				carry = PadZerosLeft(carry,3 - (carry.length())) ;
				temp_out.insert(temp_out.begin(),carry) ;

			}
			else
			{
				
				continue ;
				
			}
		}
	}

	

	return temp_out ;

}

string AddTwoIntegerStringsString(string number1, string number2)
{
	string temp_out = "" ;
	char digit1 = ' ', digit2 = ' ', carry_out = '0', char_to_append = ' ' ;
	int num1_len = number1.length(), num2_len = number2.length() ;
	int len_diff = (num1_len > num2_len) ? num1_len - num2_len : num2_len - num1_len ;

	
	if(num1_len > num2_len)
	{
		
		number2 = PadZerosLeft(number2,len_diff) ;
		number1 = number1 ;

	}
	else if(num1_len == num2_len)
	{
		
		number1 = number1 ;
		number2 = number2 ;

	}
	else
	{
		
		number1 = PadZerosLeft(number1,len_diff) ;
		number2 = number2 ;
		
	}

	for(int index = number1.length() - 1 ; index >= 0 ; index--)
	{
		digit1 = number1[index] ; digit2 = number2[index] ; 
		char_to_append = AddSingleDigitWithoutCarryReturnChar(digit1,digit2,carry_out) ;
		temp_out = char_to_append + temp_out ;
		carry_out = ReturnCarrySingleDigitChar(digit1,digit2,carry_out) ;

	}
	temp_out = carry_out + temp_out ;
	return RemoveInsignificantZerosLeft(temp_out) ;
}

string SubtractStrings(string number1, string number2, string borrow) //subtracts two 3 digit numbers.
{
	
	int num1 = stoi(number1) ;
	int num2 = stoi(number2) ;
	int borrow_num = stoi(borrow) ;
	int temp_num = 0 ;
	string str_to_return = "" ;

	bool res_negative = number1 < number2 ;
	bool res_zero = number1 == number2 ;
	bool res_positive = number1 > number2 ;

	if(res_zero)
	{
		
		return "000" ;
		
	}
	else if(res_positive)
	{
	
		temp_num = num1 - num2 - borrow_num ;
		str_to_return = to_string(temp_num) ;
		str_to_return = PadZerosLeft(str_to_return,3-str_to_return.length()) ;
		
		return str_to_return ;
	}
	else
	{
		
		temp_num = num2 - num1 - borrow_num ;
		str_to_return = to_string(temp_num) ;
		str_to_return = PadZerosLeft(str_to_return,3-str_to_return.length()) ;
		
		return "-" + str_to_return ;
		
	}
}

vector<string> SubtractLargeIntegers(string number1, string number2) //Subtracts two large integers, returns the difference as a vector. The output vector keeps the digits of the difference
{                                                                    //3 digits at a time at each element, i.e 789798 is kept as ["789","798"]
	
	vector<string> temp_out ;
	bool format_str = false ;
	if(number1[0] == '-')
	{
		if(number2[0] == '-')
		{
			
			number2 = number2.erase(0,1) ;
			number1 = number1.erase(0,1) ;
			temp_out = SubtractLargeIntegers(number2,number1) ;

		}
		else
		{
			
			number1 = number1.erase(0,1) ;
			temp_out.insert(temp_out.begin(),"-") ;
			temp_out.insert(temp_out.end(),AddTwoIntegerStrings(number1,number2).begin(),AddTwoIntegerStrings(number1,number2).end()) ;
			return temp_out ;
		}
	}
	else
	{
		if(number2[0] == '-')
		{
			
			number2 = number2.erase(0,1) ;
			return AddTwoIntegerStrings(number1,number2) ;

		}
		else
		{
		
			format_str = true ;
		
		}
	}

	int num1_length = number1.length(), num2_length = number2.length() ;
	int length_difference = (num1_length > num2_length) ? num1_length - num2_length : num2_length - num1_length ;
	string borrow_str = "" ;
	int borrow = 0 ;
	int digit1 = 0, digit2 = 0 ;
	int temp_diff = 0 ;
	string str_to_format = "" ;


	if(num1_length > num2_length)
	{
		
		number2 = PadZerosLeft(number2,length_difference) ;
		number1 = number1 ;
	}
	else if(num1_length == num2_length)
	{
		
		number1 = number1 ;
		number2 = number2 ;
		
	}
	else //num1_length < num2_length 
	{

		number1 = PadZerosLeft(number1,length_difference) ;
		number2 = number2 ;

	}

	for(int index = number1.length() - 1 ; index >= 0 ; index--)
	{
		digit1 = (number1[index]- '0') ; digit2 = (number2[index] - '0') ;
		if(digit1 < digit2)
		{

			temp_diff = 10 + digit1 - digit2 - borrow ;
			borrow = 1 ;
			str_to_format = to_string(temp_diff) + str_to_format ;
		}
		else
		{
			temp_diff = digit1 - digit2 - borrow ;
			borrow = 0 ;
			str_to_format = to_string(temp_diff) + str_to_format ;
		}
		
	}

	for(int index = 0 ; index < temp_out.size() ; index++)
	{
		
		cout << temp_out[index] << endl ;
		
	}
	
	if(format_str)
	{
		
		return returnLargeIntegerStr(str_to_format) ;
		
	}
	else
	{
		
		return temp_out ;
		
	}
	
}

bool IsGreater(string number1, string number2) //Compare two positive numbers
{

	int num1_len = number1.length() , num2_len = number2.length() ;
	int len_diff = ( num1_len > num2_len ) ? num1_len - num2_len : num2_len - num1_len ;
	bool isgreater = true ;

	if(num1_len > num2_len)
	{
		
		return true ;
		
	}
	else if(num1_len < num2_len)
	{
		
		return false ;

	}
	else //num1_len == num2_len
	{
		
		number1 = number1 ;
		number2 = number2 ;
		
	}

	for(int k = 0 ; k < number1.length() ; k++)
	{
		
		if( (number1[k] - '0') > (number2[k] - '0') )
		{
			
			isgreater = true ;
			break ;
			
		}
		else if((number1[k] - '0') == (number2[k] - '0'))
		{
			
			isgreater = true ;
			continue ;
			
		}
		else
		{
			
			return false ;
			
		}
	}
	return isgreater ;
}

string SubtractLargeIntegersString(string number1, string number2)
{
	string temp_out = "" ;
	if(number1[0] == '-')
	{
		if(number2[0] == '-') //Both numbers negative ;
		{
			number1 = number1.erase(0,1) ;
			number2 = number2.erase(0,1) ;
			if(IsGreater(number1,number2) == 1)
			{
				
				return "-" + RemoveInsignificantZerosLeft(SubtractLargeIntegersString(number1,number2)) ;
				
			}
			else
			{
				
				return RemoveInsignificantZerosLeft(SubtractLargeIntegersString(number2,number1)) ;
				
			}
		}
		else //Number1 negative, number2 positive
		{
			
			number1 = number1.erase(0,1) ;
			temp_out = RemoveInsignificantZerosLeft(AddTwoIntegerStringsString(number1,number2)) ;
			return "-" + temp_out ;
			
		}
	}
	else
	{
		if(number2[0] == '-') //Number 1 positive, number2 negative
		{
			
			number2 = number2.erase(0,1) ;
			return RemoveInsignificantZerosLeft(AddTwoIntegerStringsString(number1,number2)) ;

		}
		else //Both positive
		{
			
			number1 = number1 ;
			number2 = number2 ;
			
		}
		
	}

	int num1_len = number1.length(), num2_len = number2.length() ;
	int len_diff = (num1_len > num2_len) ? num1_len - num2_len : num2_len - num1_len ;
	char digit1 = '0' , digit2 = '0' ;
	int digit1_int = digit1 - '0' , digit2_int = digit2 - '0', borrow_int = 0 ;
	int temp_digit = 0 ;

	if(num1_len > num2_len)
	{
		
		number2 = PadZerosLeft(number2,len_diff) ;
		number1 = number1 ;
	}
	else if(num1_len < num2_len)
	{
		
		number1 = PadZerosLeft(number1,len_diff) ;
		number2 = number2 ;

	}
	else //num1_len == num2_len
	{
		
		number1 = number1 ;
		number2 = number2 ;
		
	}

	for(int k = number1.length() - 1 ; k >= 0 ; k--)
	{
		digit1 = number1[k] ; digit2 = number2[k] ; digit1_int = digit1 - '0' ; digit2_int = digit2 - '0' ;
		if(digit1 < digit2)
		{
			
			temp_digit = 10 + digit1_int - digit2_int - borrow_int ;
			borrow_int = 1 ;
			temp_out = to_string(temp_digit) + temp_out ;

		}
		else if(digit1 > digit2)
		{
			
			temp_digit = digit1_int - digit2_int - borrow_int ;
			borrow_int = 0 ;
			temp_out = to_string(temp_digit) + temp_out ;
			
		}
		else //digit1 == digit2
		{
			
			if(borrow_int == 1)
			{
				
				temp_digit = 10 + digit1_int - digit2_int - borrow_int ;
				borrow_int = 1 ;
				temp_out = to_string(temp_digit) + temp_out ;
				
			}
			else
			{
				
				temp_digit = digit1_int - digit2_int - borrow_int ;
				borrow_int = 0 ;
				temp_out = to_string(temp_digit) + temp_out ;
				
			}
		}

	}

	if(temp_out != "0")
	{
		
		return RemoveInsignificantZerosLeft(temp_out) ;
		
	}
	else
	{
		
		return "0" ;
		
	}
	
}

bool NeedsBorrow(string number1, string number2)
{
	while( (number1.length() > 1) || (number2.length() > 1) ) //Input check
	{
		
		cout << "Number 1 and number 2 must both be single digit numbers. Reenter number 1: " << endl ;
		cin >> number1 ; cout << endl ;
		cout << "Reenter number 2: " << endl ;
		cin >> number2 ;
		number1 = ReturnCompleteIntegerString(number1) ; //Input check
		number2 = ReturnCompleteIntegerString(number2) ; //Input check
	}

	if(number1 < number2)
	{
		
		return true ;
		
	}
	else
	{
		
		return false ;
		
	}
}

string AddSingleDigitWithoutCarryReturn(char digit1, char digit2, char carry_digit)
{
	short int digit1_int = digit1 - '0', digit2_int = digit2 - '0', carry_in_int = carry_digit - '0' ;
	while((digit1_int > 9) || (digit2_int > 9) || (carry_in_int > 9) || (digit1_int < 0) || (digit2_int < 0) || (carry_in_int < 0) )
	{
		
		cout << "Inputs must be single digit. Enter all the input arguments again. " << endl ;
		cout << "Input 1: " ; cin >> digit1 ; cout << endl ;
		cout << "Input 2: " ; cin >> digit2 ; cout << endl ;
		cout << "Input carry: " ; cin >> carry_digit ; cout << endl ;
		digit1_int = digit1 - '0', digit2_int = digit2 - '0', carry_in_int = carry_digit - '0' ; 
		cout << "New candidate for input digit 1: " << digit1 << endl ;
		cout << "New candidate for input digit 2: " << digit2 << endl ;
		cout << "New candidate for input digit 1: " << carry_digit << endl ;
	}
	short int temp_sum = digit1_int + digit2_int + carry_in_int ;
	string temp_sum_str = to_string(temp_sum) ;
	return temp_sum_str.substr(temp_sum_str.length()-1,1) ;
	
}

string ReturnCarrySingleDigit(char digit1, char digit2, char carry_digit)
{
	short int digit1_int = digit1 - '0', digit2_int = digit2 - '0', carry_in_int = carry_digit - '0' ;
	while((digit1_int > 9) || (digit2_int > 9) || (carry_in_int > 9) || (digit1_int < 0) || (digit2_int < 0) || (carry_in_int < 0))
	{
		
		cout << "Inputs must be single digit. Enter all the input arguments again. " << endl ;
		cout << "Input 1: " ; cin >> digit1 ; cout << endl ;
		cout << "Input 2: " ; cin >> digit2 ; cout << endl ;
		cout << "Input carry: " ; cin >> carry_digit ; cout << endl ;
		digit1_int = digit1 - '0', digit2_int = digit2 - '0', carry_in_int = carry_digit - '0' ; 
		cout << "New candidate for input digit 1: " << digit1 << endl ;
		cout << "New candidate for input digit 2: " << digit2 << endl ;
		cout << "New candidate for input carry " << carry_digit << endl ;
	}
	short int temp_sum = digit1_int + digit2_int + carry_in_int ;
	string temp_sum_str = to_string(temp_sum) ;
	if(temp_sum_str.length() > 1)
	{
		
		return temp_sum_str.substr(0,1) ;
		
	}
	else
	{
		
		return "0" ;
		
	}
}

char AddSingleDigitWithoutCarryReturnChar(char digit1, char digit2, char carry_digit)
{

	short int digit1_int = digit1 - '0', digit2_int = digit2 - '0', carry_digit_int = carry_digit - '0' ; 
	short int temp_sum = digit1_int + digit2_int + carry_digit_int ;
	string temp_sum_str = to_string(temp_sum) ;
	return temp_sum_str[temp_sum_str.length()-1] ;

}

char ReturnCarrySingleDigitChar(char digit1, char digit2, char carry_digit)
{
	short int digit1_int = digit1 - '0', digit2_int = digit2 - '0', carry_digit_int = carry_digit - '0' ; 
	short int temp_sum = digit1_int + digit2_int + carry_digit_int ;
	string temp_sum_str = to_string(temp_sum) ;
	if(temp_sum_str.length() > 1)
	{
		
		return temp_sum_str[0] ;

	}
	else
	{
		
		return '0' ;

	}
}

string MultiplyLargeIntegers(string number1, string number2)
{

	bool resultnegative = false ;
	string temp_out = "" ;
	int digit1 = 0, digit2 = 0 ;
	int carry_int = 0 ;
	string digit_to_add = "" ;
	string str_to_push = "" ;

	vector<string> mid_products ;
	if(number1[0] == '-')
	{
		number1 = number1.erase(0,1) ;
		if(number2[0] == '-')
		{
			number2 = number2.erase(0,1) ;
			resultnegative = false ;
			
		}
		else
		{
			
			resultnegative = true ;
			
		}
	}
	else
	{
		if(number2[0] == '-')
		{
			number2 = number2.erase(0,1) ;
			resultnegative = true ;
			
		}
		else
		{
			
			resultnegative = false ;
			
		}
	}

	int num1_length = number1.length(), num2_length = number2.length() ;
	int result_len_max = number1.length() + number2.length() ;
	temp_out = PadZerosLeft("",result_len_max) ;
	int zero_to_add = 0 ;

	for(int index2 = number2.length() - 1 ; index2 >= 0 ; index2--)
	{
		for(int index1 = number1.length() - 1 ; index1 >= 0 ; index1-- )
		{
			digit1 = number1[index1] - '0' ; digit2 = number2[index2] - '0' ;
			digit_to_add = to_string((digit1*digit2 + carry_int) % 10) ;
			str_to_push = digit_to_add + str_to_push ;
			carry_int = (((digit1*digit2 + carry_int)) - ((digit1*digit2 + carry_int) % 10)) / 10 ;
		}
		str_to_push = to_string(carry_int) + str_to_push ;
		str_to_push = PadZerosRight(str_to_push,zero_to_add) ;
		mid_products.insert(mid_products.begin(),str_to_push) ;
		zero_to_add += 1 ;
		carry_int = 0 ;
		str_to_push = "" ;
	}

	for(int index = 0 ; index < mid_products.size() ; index++)
	{
		
		temp_out = AddTwoIntegerStringsString(temp_out,mid_products[index]) ;
		
	}

	if(resultnegative)
	{
		
		temp_out = "-" + temp_out ;
		
	}
	else
	{
		
		temp_out = temp_out ;

	}

	return RemoveInsignificantZerosLeft(temp_out) ;
}

string DivideLargeIntegers(string number1, string number2) //Divides number1 by number2
{
	if(number2 == "1")
	{
		
		return number1 ;
		
	}
	string temp_out = "0" ;
	string curr_dividend = number1 ;
	bool dividend_greater_than_divisor = IsGreater(curr_dividend,number2) ;
	while(dividend_greater_than_divisor)
	{
		temp_out = AddTwoIntegerStringsString(temp_out,"1") ;
		curr_dividend = SubtractLargeIntegersString(curr_dividend,number2) ;
		dividend_greater_than_divisor = IsGreater(curr_dividend,number2) ;
	}

	return RemoveInsignificantZerosLeft(temp_out) ;

}

string DivideSmallIntegers(string number1, string number2)
{
	number1 = ReturnCompleteIntegerString(number1) ;
	number2 = ReturnCompleteIntegerString(number2) ;

	int num1_len = number1.length(), num2_len = number2.length() ;

	while((num1_len > non_str_int_digit_count) || (num2_len > non_str_int_digit_count))
	{
		
		cout << "Each number can have 9 digits at most, enter new numbers: " << endl << "Number1: " ; cin >> number1 ; cout << "Number 2: " << endl ; cin >> number2 ;
		num1_len = number1.length() ; num2_len = number2.length() ;

	}

	int number1_int = stoi(number1) , number2_int = stoi(number2) ;
	int result = number1_int / number2_int ;
	return to_string(result) ;

}

string DivideLargeIntegersRemainder(string number1 , string number2)
{
	
	return SubtractLargeIntegersString(number1,MultiplyLargeIntegers(DivideLargeIntegers(number1,number2),number2)) ;

}

double polyval(double poly_coef[], double eval_point)
{
	double temp_out = 0.0 ;
	
	for(int k = 0 ; k < sizeof(poly_coef) ; k++)
	{
		
		temp_out = (double)poly_coef[k]*(pow(eval_point,k)) + temp_out ;
		
	}
	
	return temp_out ;
}

double polyval_vector(vector<double> poly_coef, double eval_point)
{
	
	double temp_out = 0.0 ;
	
	for(int k = 0 ; k < poly_coef.size() ; k++)
	{
		
		temp_out = poly_coef[k]*(pow(eval_point,k)) + temp_out ;
		
	}
	
	return temp_out ;
	
}

double dot_product(vector<double> vector1, vector<double> vector2)
{
	int vector_size = vector1.size() ; double temp_out = 0.0 ;
	double temp_vector_element = 0.0 ;
	if(vector1.size() != vector2.size())
	{
		cout << "Vector sizes not equal, reenter expected vector size, then enter the input vector elements. " << endl ;
		cout << "Expected vector size: " ; cin >> vector_size ; cout << endl ;
		vector1.clear() ; vector2.clear() ;
		for(int k = 0 ; k < vector_size ; k++)
		{
			
			cout << "Expecting element " << k+1 << " of first vector: " ; cin >> temp_vector_element ; vector1.push_back(temp_vector_element) ; cout << endl ;
			
		}
		
		for(int k = 0 ; k < vector_size ; k++)
		{
			
			cout << "Expecting element " << k+1 << " of second vector: " ; cin >> temp_vector_element ; vector2.push_back(temp_vector_element) ; cout << endl ;
			
		}

	}

	for(int k = 0 ; k < vector_size ; k++)
	{
		
		temp_out = vector1[k] * vector2[k] + temp_out ;
		
	}
	
	return temp_out ;

}

void MyPlayFunc()
{
	static int a = 0 ;
	cout << "Previous a: " << a << endl ; 
	a = a + 1 ;
	cout << a << endl ;

}

/* vector<double> double_vector ;

	vector<double> *my_ptr = &double_vector ;

	for(int i = 0 ; i < number1 ; i++)
	{
		
		my_ptr->push_back(i*1.0) ;
		
	}

	cout << "Position 2 has value: " << (*my_ptr)[2] ; */