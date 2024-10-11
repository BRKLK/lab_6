#include <iostream>
#include <cmath>

using namespace std;
// Лаба 6 Вариант 4
// 1. 	Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). 
// Если в последовательности нет ни одного простого числа, упорядочить последовательность по невозрастанию.
 
// 2. 	Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). 
// Упорядочить последовательность по неубыванию первой цифры числа, числа с одинаковыми 
// первыми цифрами дополнительно упорядочить по неубыванию наименьшей цифры числа,
// числа с одинаковыми первыми цифрами и  одинаковыми наименьшими цифрами дополнительно 
// упорядочить по неубыванию самого числа.
 
// 3. 	Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). 
// Найти строку с наименьшей суммой элементов и заменнить все элементы этой строки этой суммой.

// 4. Сначала введите последовательность. Затем удалите и продублируйте элементы. 
// Затем выведите полученную последовательность (каждый элемент по одному разу). 
// Используйте в программе только один массив.

// Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000).
// Удалить из последовательности числа-палиндромы, а среди оставшихся продублировать простые числа.


int main()
{
    // 1
    int n;
    cout << "Enter the size of an array: "; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a number: "; cin >> arr[i];
    }
    
    bool is_prime;
    for (int i = 0; i < n; i++)
    {
        is_prime = true;
        for (int d = 2; d <= sqrt(arr[i]); d++)
        {
            if (arr[i] % d == 0) {
                is_prime = false;
                }
        }
        if (is_prime) {cout << arr[i]; break;}
    }

    if (is_prime) 
    {
        cout << "There is a prime number in the sequence, should not do sorting." << endl;
    }
    else 
    {
        cout << "There is no prime numbers in the sequence, there's a sorted array:" << endl;
        // Sorting an array
        for(int i = 0; i < n-1; i++)
        {
            int max_pos = i;
            for(int j = i+1; j < n; j++)
            {
                if (arr[j] > arr[i]) {max_pos = j;}
            }
            swap(arr[i], arr[max_pos]);
        }
        //Print array
        for(int i = 0; i < n; i++) {cout << arr[i] << " ";}
        cout << endl;
    }
    // 2
    // Entering an array
    cout << "Enter the size of an array: "; cin >> n;
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a number: "; cin >> arr2[i];
    }

    // sorting 
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            // Finding first digit
            int j_dig = arr2[j];
            int i_dig = arr2[i];
            while (j_dig >= 10)
                j_dig /= 10;
            while (i_dig >= 10)
                i_dig /= 10;

            if (j_dig > i_dig) {swap(arr2[i], arr2[j]);}
            else if (j_dig == i_dig)
            {
                // Finding smallest digits
                int j_n = arr2[j];
                int i_n = arr2[i];                
                int j_min_dig = arr2[j] % 10;
                int i_min_dig = arr2[i] % 10;
                while(j_n != 0)
                {
                    if(j_n % 10 < j_min_dig) {j_min_dig = j_n % 10;}
                    j_n /= 10;
                }
                while(i_n != 0)
                {
                    if(i_n % 10 < i_min_dig) {i_min_dig = i_n % 10;}
                    i_n /= 10;
                }

                if (j_min_dig > i_min_dig) {swap(arr2[i], arr2[j]);}
                else if(j_min_dig == i_min_dig)
                {
                    if (arr2[j] > arr2[i]) {swap(arr2[i], arr2[j]);}
                }

            }
        }
    }
    //Print an array
    for(int i = 0; i < n; i++) {cout << arr2[i] << " ";}

    //3
    int n_strings, n_columns;
    cout << "Enter the amount of strings: "; cin >> n_strings;
    cout << "Enter the amount of columns: "; cin >> n_columns;
    int matrx[n_strings][n_columns];
    for(int i = 0; i < n_strings; i++)
    {
        for(int j = 0; j < n_columns; j++)
        {
            cout << "Enter a number: "; cin >> matrx[i][j];
        }
    }
    // Searching for a string with the smallest elements sum
    int min_pos, min_sum = 1000000;
    for(int i = 0; i < n_strings; i++)
    {
        int s = 0;
        for(int j = 0; j < n_columns; j++)
        {
            s += matrx[i][j];
        }

        if (s < min_sum)
        {
            min_pos = i;
            min_sum = s;
        }
    }

    // Replacing elements in the string with the smallest sum
    for(int j = 0; j < n_columns; j++)
    {
        matrx[min_pos][j] = min_sum;
    }
    // Printing matrix
    for(int i = 0; i < n_strings; i++)
    {
        for(int j = 0; j < n_columns; j++)
        {
            cout << matrx[i][j] << " ";
        }
        cout << endl;
    }
    // 4 
    int n;
    cout << "4." << endl << "Enter the size of an array: "; cin >> n;
    int Max_N = 20000;
    int arr3[Max_N];
    for(int i = 0; i < n; i++)
    {
        cout << "Enter a number: "; cin >> arr3[i];
    }
    // Deleting palindromes
    int n_of_deleted = 0;
    for(int i = 0, j = 0; i < n; i++)
    {
        bool is_palindrome = false;
        int reverse_num = 0, num = arr3[i];
        while(num != 0)
        {
            reverse_num = reverse_num*10 + num%10;
            num /= 10;
        }
        cout << reverse_num << " " << endl;
        arr3[j] = arr3[i];
        if(not (reverse_num == arr3[i]))
        {
            j++;
        }
        else {n_of_deleted++;}
    }
    n -= n_of_deleted;

    cout << endl;
    // Duplicating prime numbers
    for(int i = 0; i < n; i++)
    {
        bool is_prime = true;
        for(int d = 2; d < sqrt(arr3[i]); d++)
        {
            if(arr3[i] % d == 0) {is_prime = false;}
        }
        if(is_prime)
        {
            for(int j = n; j > i; j--)
            {
                arr3[j] = arr3[j-1];
            }
            n++;
            i++;
        }
    }
    // Printing an array
    for(int i = 0; i < n; i++)
    {
        cout << arr3[i] << " ";
    }



    return 0;
}
