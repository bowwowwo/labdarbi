/*
  Toms Gerbaševskis, tg25032

  Izveidot programmu gan C++, gan Python. Ievadot loģiski nepareizus datus, programmai jāizdod atbilstošs paziņojums. Jābūt iespējai programmu izpildīt atkārtoti. Atrādot programmu, jāatrāda
  a) programmas teksts,
  b) testa piemēri,
  c) programma darbībā.
  Precīzākas prasības sk. Laboratorijas darbu noteikumos.

  A2. Doti naturāli skaitļi m un n. Noskaidrot starpību starp m un n dažādo reizinātāju skaitu (piemēram, m=9, n=6, atbilde ir -1, jo m ir mazāk reizinātāju nekā n).

  Programma izveidota: 19.09.2025.
*/

#include <iostream>

int m;
int n;
int ok = 0;

int different_factor_count(int m, int n);                    //funkcijas deklarācija jo ir iespējams, ka nestrādā bez tās

int main()
{
    do
    {
        while (1) {
            std::cout << "Ievadiet skaitli m\n";
            std::cin >> m;                             

            if (m < 1) {                                    //nenaturāla skaitļa pārbaude
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



        std::cout << "Skaitļu reizinātāju starpība: " << different_factor_count(m, n) << std::endl; //tiek uzreiz ievietota funkcija, atmiņas ietaupei

        std::cout << "Vai turpināt (1) vai beigt (0)?\n";
        std::cin >> ok;

    } while (ok == 1);

    return 0;
}

int different_factor_count(int m, int n)          //funkcija, kas atgriež argumenta skaitļa reizinātāju skaitu
{
   
    int count = 0;
    int count_different_m = 0;
    int count_different_n = 0;
    int count_same = 0;


    for (int i = 1; i <= m; i++){                //for loop "sistēma" iegūst vienādo ciparu skaitu m un n
        if (m % i == 0){
            for (int j = 1; j <= n; j++){
                if (n % j == 0) {
                    if (i == j) {
                        count_same++;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= m; i++) {              //iegūst reizinātāju skaitu m
        if (m % i == 0) {
            count_different_m++;
        }
    }

    for (int i = 1; i <= n; i++) {              //iegūst reizinātāju skaitu n
        if (n % i == 0) {
            count_different_n++;
        }
    }

    count_different_m -= count_same;
    count_different_n -= count_same;



    return (count_different_m - count_different_n);
}

/* testa plāns

+--------------+-------------------------+-------------------------+
| Ievades dati |    Vēlamie rezultāti    |        Rezultāti        |
+--------------+-------------------------+-------------------------+
| m=9 n=6      | -1                      | -1                      |
| m=16 n=16    | 0                       | 0                       |
| m=100 n=10   | 5                       | 5                       |
| m=-1         | "nav naturāls skaitlis" | "nav naturāls skaitlis" |
| m=1 n=-1     | "nav naturāls skaitlis" | "nav naturāls skaitlis" |
+--------------+-------------------------+-------------------------+

*/