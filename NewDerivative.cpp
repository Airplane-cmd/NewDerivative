#include <iostream>
#include <string>
#include <math.h>
#include <vector>
char numbers[] = {'1','2','3','4','5','6','7','8','8','9','0'};
char variables[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
bool Check(char symbolType, char symbol)
{
	if(symbolType == 'n')
	{
		for(int k = 0; k < 10; k++)
		{
			if(symbol == numbers[k])
			{
//				std::cout<<"Fuck"<<std::endl;
				return 1;
			}
					
		}
		return 0;
		
	}
	else if(symbolType == 'v')
	{
		for(int g = 0; g < 26; g++)
		{
			if(symbol == variables[g])
			{
//				std::cout<<"Ass"<<std::endl;
				return 1;
			}
		
		}
		return 0;
		
	}
	else
		return 0;
}
void slide()
{
	std::cout<<"----------------------------------------------------------------------------------------------------------"<<std::endl;
}
void Derivative(std::string Function)
{
//	for (int j = 0; j < Function.length(); j++)
//	{
//		std::cout << Function[j];
//	}
	std::cout << "Function:  "<<Function<<std::endl;
	slide();
	std::string pluses = "";
	std::string minuses = "";
	std::string multiplies = "";
	std::string divisions = "";
	std::string breckets = "";
	std::string dots = "";
	std::string powers = "";
	std::string numbersR = "";
	std::string variables = "";
	
	int realNumbersCounter = 0;
	for(int i = 0; i < Function.length(); i++)
	{
		if ((Check('v', Function[i - 1]) && Check('v', Function[i])) || (Check('v', Function[i - 1]) && Check('n', Function[i])) || (Check('n', Function[i - 1]) && Check('v', Function[i])) || (Check('n', Function[i - 1]) && (Function[i] == '(')) || (Check('v', Function[i - 1]) && (Function[i] == '(')) || (Function[i - 1] == ')') && (Function[i] == '('))
			{
				Function += "`";
				char* FunctionFictional = new char[Function.length() + 1];
				for (int z = 0; z < Function.length() + 1; z++)
				{
					FunctionFictional[z] = Function[z];
				}
				for (int j = i; j < Function.length() + 1; j++)
				{
					Function[j + 1] = FunctionFictional[j];

				}
				Function[i] = '*';

			}
		if (Function[i] == '+')
			pluses += "+";
		else
			pluses += "_";
				
		if (Function[i] == '-')
			minuses += "-";
		else
			minuses += "_";
		if (Function[i] == '*')
			multiplies += "*";
		else
			multiplies += "_";
		if (Function[i] == '/')
			divisions += "/";
		else
			divisions += "_";
		if ((Function[i] == '(') || (Function[i] == ')'))
		{
			if (Function[i] == ')')
				breckets += ")";
			else if (Function[i] == '(')
				breckets += "(";
		}
		else
			breckets += "_";
		if (((Check('n', Function[i]))) || (Function[i] == '.'))
		{
			++realNumbersCounter;
			if(((Check('n', Function[i + 1]))) || (Function[i + 1] == '.'))
				--realNumbersCounter;
			if (Check('n', Function[i]))
				numbersR += Function[i];
			else if (Function[i] == '.')
				numbersR += ".";
		}
		else 
			numbersR += "_";
		if (Function[i] == '.')
			dots += ".";
		else
			dots += "_";
		if (Function[i] == '^')
			powers += "^";
		else
			powers += "_";
		if (Check('v', Function[i]))
			variables += Function[i];
		else
			variables += "_";
	}
	double *realDoubles = new double[realNumbersCounter];
	std::vector<std::string> realStrings;
	realStrings.resize(realNumbersCounter);
	int fuckingCounter = 0;
	for(int realNumbersCounterLocal = 0; realNumbersCounterLocal < Function.length(); ++realNumbersCounterLocal)
	{
		if(numbersR[realNumbersCounterLocal] != '_')
			realStrings[fuckingCounter] += numbersR[realNumbersCounterLocal];
		else
		{
			++fuckingCounter;
			if(numbersR[realNumbersCounterLocal + 1] == '_')
				--fuckingCounter;
		}		
	}
	for(int hui = 0; hui < realNumbersCounter; ++hui)
	{
		for(int cock = realStrings[hui].length(); cock != 0 ; cock--)
		{
			if(realStrings[hui][cock] == '0')
				realDoubles[hui] += 0.0;
			if(realStrings[hui][cock] == '1')
				realDoubles[hui] += 1.0;
			if(realStrings[hui][cock] == '2')
				realDoubles[hui] += 2.0;
			if(realStrings[hui][cock] == '3')
				realDoubles[hui] += 3.0;
			if(realStrings[hui][cock] == '4')
				realDoubles[hui] += 4.0;
			if(realStrings[hui][cock] == '5')
				realDoubles[hui] += 5.0;
			if(realStrings[hui][cock] == '6')
				realDoubles[hui] += 6.0;
			if(realStrings[hui][cock] == '7')
				realDoubles[hui] += 7.0;
			if(realStrings[hui][cock] == '8')
				realDoubles[hui] += 8.0;
			if(realStrings[hui][cock] == '9')
				realDoubles[hui] += 9.0;
			for(int oneMoreFuck = 0; oneMoreFuck < realStrings[hui].length(); ++oneMoreFuck)
			{
				realDoubles[hui] *= 10;
			}
		}
	}
	std::cout << std::endl;
		std::cout<<"Modified function: "<<Function<<std::endl;
		std::cout<<"Pluses:            "<<pluses<<std::endl;
		std::cout<<"Minuses:           "<<minuses<<std::endl;
		std::cout<<"Multiplies:        "<<multiplies<<std::endl;
		std::cout<<"Divisions:         "<<divisions<<std::endl;
		std::cout<<"Breckets:          "<<breckets<<std::endl;
		std::cout<<"Powers:            "<<powers<<std::endl;
		std::cout<<"Numbers:           "<<numbersR<<std::endl;
		std::cout<<"Variables:         "<<variables<<std::endl;
	slide();
		std::cout<<"Real numbers count:"<<realNumbersCounter<<std::endl;
		for (int you = 0; you < realNumbersCounter; ++you)
		{
			std::cout << realStrings[you] << std::endl;
		}
	slide();
		for (int you = 0; you < realNumbersCounter; ++you)
		{
			std::cout << realDoubles[you] << std::endl;
		}
	slide();
}
int main()
{
	Derivative("2*x^((2+4)/3)-44.4x+6xyz");
}

