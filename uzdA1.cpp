/*
  Toms Gerbaševskis, tg25032

  Izveidot programmu gan C++, gan Python. Ievadot loģiski nepareizus datus, programmai jāizdod atbilstošs paziņojums. Jābūt iespējai programmu izpildīt atkārtoti. Atrādot programmu, jāatrāda
  a) programmas teksts,
  b) testa piemēri,
  c) programma darbībā.
  Precīzākas prasības sk. Laboratorijas darbu noteikumos.

  A2. Doti naturāli skaitļi m un n. Noskaidrot starpību starp m un n dažādo reizinātāju skaitu (piemēram, m=9, n=6, atbilde ir -1, jo m ir mazāk reizinātāju nekā n).

  Programma izveidota: 09.09.2025.
*/

#include <iostream>

int m;
int n;
int ok = 0;
int count;

int factors(int x);                                    //funkcijas deklarācija jo ir iespējams, ka nestrādā bez tās

int main()
{
    do
    {
        while(1){
            std::cout << "Ievadiet skaitli m\n";
            std::cin >> m;                             //nav jāpārbauda vai ievade ir float, jo mainīgais ir int

            if (m < 1) {
                std::cout << "nav naturāls skaitlis\n";
            }
            else break;
        }
        
        while (1) {
            std::cout << "Ievadiet skaitli n\n";
            std::cin >> n;

            if (n < 1) {
                std::cout << "nav naturāls skaitlis\n";
            }
            else break;
        }

        std::cout << "Skaitļu reizinātāju starpība: " << factors(m) - factors(n) << std::endl;

        std::cout << "Vai turpināt (1) vai beigt (0)?\n";
        std::cin >> ok;

    } while (ok == 1);

    return 0;
}

int factors(int x)
{

    count = 0;

    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0) {
            count++;
        }
    }

    return count;
}

/* testa plāns

+--------------+-------------------------+-------------------------+
| Ievades dati |    Vēlamie rezultāti    |        Rezultāti        |
+--------------+-------------------------+-------------------------+
| m=9 n=6      | -1                      | -1                      |
| m=16 n=16    | 0                       | 0                       |
| m=100 n=10   | 5                       | 5                       |
| m=-1         | "nav naturāls skaitlis" | "nav naturāls skaitlis" |
+--------------+-------------------------+-------------------------+

*/