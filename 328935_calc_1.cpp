// Zadanie: Kalkulator
// Autor: Adrian Fabisiewicz
// Nr indeksu: 328935
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	char token;

	stack<int> numbers;
	stack<char> operators;

	while (cin >> token)
	{
		if (token == '+' || token == '-' || token == '*' || token == '/')
		{
			operators.push(token);	// dodanie operatora na stos operatorow
		}

		if (token >= '0' && token <= '9')
		{
			numbers.push(token - '0');	// dodanie liczby na stos liczb
		}

		if (token == '(')	// jesli napotykamy nawias otwierajacy, nie wykonujemy dzialan
			continue;

		if (token == ')')
		{
			char o = operators.top();	// zdjecie operatora ze stosu operatorow
			operators.pop();	// usuniecie operatora ze stosu operatorow

			int number1 = numbers.top();	// zdjecie pierwszej liczby ze stosu liczb
			numbers.pop();	// usuniecie pierwszej liczby ze stosu liczb

			int number2 = numbers.top();	// zdjecie drugiej liczby ze stosu liczb
			numbers.pop();	// usuniecie drugiej liczby ze stosu liczb

			switch (o)
			{
				case '+':
					numbers.push(number1 + number2);	// dodajemy zdjete ze stosu liczby jesli operator to + i dodajemy wynik na stos liczb
					break;

				case '-':
					numbers.push(number2 - number1);	// odejmujemy zdjete ze stosu liczby jesli operator to - i dodajemy wynik na stos liczb
					break;

				case '*':
					numbers.push(number1 *number2);	// mnozymy zdjete ze stosu liczby jesli operator to *i dodajemy wynik na stos liczb
					break;

				case '/':
					if (number1 == 0)
					{
						cout << "NaN" << endl;	// jesli druga liczba jest rowna 0, dzielenie jest niemozliwe, wiec wypisujemy NaN
						return 0;
					}

					numbers.push(number2 / number1);	// dzielimy zdjete ze stosu liczby jesli operator to / i dodajemy wynik na stos liczb
					break;
			}
		}
	}

	cout << numbers.top() << endl;	// wypisanie liczby na szczycie stosu liczb, czyli ostatecznego wyniku dzialan
	return 0;
}