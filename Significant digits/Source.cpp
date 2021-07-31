#include <iostream>

#include<string>

using namespace std;


int calculateSignificant(string number)
{
    int significant = 0;
    int temp = 0;
    if (number[0] == '-')
        number.replace(0, 1, "");

    for (int i = 0; i < number.size(); i++)
    {
        if (number[i] != '0' && number[i] != '.')
        {
            significant = significant + temp;
            temp = 0;
            significant++;

            for (int j = i + 1; j < number.size(), number[j] == '0'; j++)
            {
                
                temp++;
                i = j;
            }

        }
        else if (number[i] == '.')
        {
            significant = significant + temp;
            i++;
            if (significant > 0)
            {
                for (int j = i; j < number.size(); j++)
                {
                    significant++;
                    i = j;
                }
            }
            else if (significant == 0)
            {
                for (int j = i; j < number.size(), number[j] == '0'; j++)
                {
                    i++;
                }
                for (int j = i; j < number.size(); j++)
                {
                    significant++;
                    i = j;
                }
            }
        }
    }
    return significant;
}

int main()
{
    string number;
    int significant = 0;
    string choice="y";
    do {

        cout << "Enter a number: ";
        getline(cin, number);
        significant = calculateSignificant(number);
        cout << "Significant digits are: " << significant << endl;

        cout << "Do you want  to check another? (y/n)"<<endl;
        getline(cin, choice);
        cout << endl << endl;
    } while (choice == "y");

}
