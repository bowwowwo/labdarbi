/*
Toms Gerbaševskis, tg25032

C6. Doti naturāls skaitlis n un veseli skaitļi a(1), a(2), ... a(n).
Atrast skaitli, kurš dotajā virknē atkārtojas visvairāk reižu pēc kārtas.
Cik reizes? Ja tādi skaitļi ir vairāki, tad izdrukāt lielāko.

Programma izveidota: 02.11.2025.
*/

#include <iostream>
#include <vector>

std::vector<int> most_common_numbers(int arr[], int arr_size);
/*

std::vector<int> most_common_numbers(int arr[], int arr_size);

Funkcija most_common_numbers(arr, arr_size) -
atgriež vektoru no 2 veseliem skaitļiem, kur 1.elements ir skaitlis, kas naturālu skaitļu virknē arr ar garumu arr_size atkārtojas visvairāk reižu pēc kārtas,
un 2. elements - cik reižu pēc kārtas tas atkārtojas.

*/

int main()
{
    int ok;
    int arr_size;
    int *num_arr;

    do
    {

        do
        {
            std::cout << "Ievadiet skaitļu daudzumu virknē: ";
            std::cin >> arr_size;

            if (arr_size < 1)
            {
                std::cout << "Virknes lielumam ir jābūt lielākam par 1!\n";
            }
        } while (arr_size < 1);

        num_arr = new int[arr_size];

        for (int i = 0; i < arr_size; i++)
        {
            std::cout << "Ievadiet " << i + 1 << ". ciparu: ";
            std::cin >> num_arr[i];
        }

        std::vector<int> common_num_arr = most_common_numbers(num_arr, arr_size);

        std::cout << "virknē pēc kārtas visvairāk atkārtojas skaitlis " << common_num_arr[0] << ", " << common_num_arr[1] << " reizes" << std::endl;

        delete[] num_arr;

        std::cout << "Vai turpināt (1) vai beigt (0)?\n";
        std::cin >> ok;

    } while (ok == 1);
}

std::vector<int> most_common_numbers(int arr[], int arr_size)
{
    int current_num = arr[0], count = 1;
    std::vector<int> result = {arr[0], 1};

    for (int i = 0; i < arr_size - 1; i++)
    {                                  // tiek pāriets pāri parametros iegūtajam masīvam
        if (current_num == arr[i + 1]) // ja skaitlis vienāds ar pašreizējo skaitli tiek palielināts tā skaits
            count++;
        else
        {
            if (count == result[1])
            { // izmanto lielāko skaitli, ja skaits bija vienāds
                if (current_num > result[0])
                {
                    result[0] = current_num;
                    result[1] = count;
                }
            }
            else if (count > result[1]) // ja skaits bija lielāks masīvā ieliek jauno skaitli
            {
                result[0] = current_num;
                result[1] = count;
            }
            current_num = arr[i + 1];
            count = 1;
        }
    }

    if (count > result[1])
    { // pārbauda vai skaitlis beidzot ciklu bija vairāk
        result[0] = current_num;
        result[1] = count;
    }
    else if (count == result[1])
    { // izmanto lielāko skaitli, ja skaits bija vienāds
        if (current_num >= result[0])
        {
            result[0] = current_num;
            result[1] = count;
        }
    }

    return result;
}

/*

╔══════════════════╦═══════════════════╦══════════════════════════════════════════════════════════════╗
║   Ievades dati   ║ Vēlamie rezultāti ║                          Rezultāti                           ║
╠══════════════════╬═══════════════════╬══════════════════════════════════════════════════════════════╣
║ 8;56;67;67;67;88 ║ 67; 3 reizes      ║ virknē pēc kārtas visvairāk atkārtojas skaitlis 67, 3 reizes ║
║ 2;2;8;8;8;8      ║ 8; 4 reizes       ║ virknē pēc kārtas visvairāk atkārtojas skaitlis 8, 4 reizes  ║
║ 1;2;3;3;4        ║ 3; 2 reizes       ║ virknē pēc kārtas visvairāk atkārtojas skaitlis 3, 2 reizes  ║
║ 9;9;1;4;4        ║ 9; 2 reizes       ║ virknē pēc kārtas visvairāk atkārtojas skaitlis 9, 2 reizes  ║
╚══════════════════╩═══════════════════╩══════════════════════════════════════════════════════════════╝

*/
