/*

Toms Gerbaševskis, tg25032

Izveidot programmu gan C++, gan Python, obligāti izmantojot norādītās vai kādas citas funkcijas.
Prasības tādas pašas kā iepriekšējā uzdevumā, precīzāk sk. Laboratorijas darbu noteikumos.

B4. Noskaidrot, vai dotajā naturālajā skaitlī ir atrodami vienādi cipari.
Ja ir, izdrukāt tos un skaitu, cik reižu dotais cipars ir sastopams.
Skaitļa dalīšana ciparos jāveic skaitliski.

Programma izveidota: 02.10.2025.

*/

#include <iostream>

void common_numbers(int sk); //funkcijas deklarācija

int main()
{
    int ok;
    unsigned int n;

    do
    {

        do {
            std::cout << "Ievadiet skaitli n: ";
            std::cin >> n;

            if (n < 1) {
                std::cout << "nav naturāls skaitlis\n";
            }
        } while (n < 1);

        common_numbers(n);


        std::cout << "Vai turpināt (1) vai beigt (0)?\n";
        std::cin >> ok;

    } while (ok == 1);
}

void common_numbers(int sk) {

    int count = 0;
    int count_no_common_num = 0;
    unsigned int sk2 = sk;
    int num;


    for (int i = 0; i <= 9; i++) { //tiek izmantota iterācija, lai pārbaudītu ciparu skaitu

        if (sk2 < 10) {				// pārbauda vai ir jēga pildīt for ciklu
            std::cout << "skaitlis ir mazāks par 10\n";
            return;
        }

        sk = sk2; //tiek "atdots" skaitlis katru iterāciju
        count = 0;

        while (sk) { // while ciklā tiek iegūts pēdējais cipars ja tas vienāds ar iterāciju tiek papildināts to skaits skaitlī
            num = sk % 10;
            sk /= 10;

            if (i == num) {
                count++;
            }
        }

        if (count > 1) {
            std::cout << i << " skaitlī: " << count << " reizes" << std::endl;
        }
        else {
            count_no_common_num++;
        }

        if (count_no_common_num == 9) {
            std::cout << "nav vienādu ciparu\n";
        }
    }
}

/*

+--------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+
| Ievades dati |                                 Vēlamie rezultāti                                 |                                     Rezultāti                                     |
+--------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+
| n=1          | nav                                                                               | "skaitlis ir mazāks par 10"                                                       |
+--------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+
| n=80976      | nav                                                                               | "nav vienādu ciparu"                                                              |
+--------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+
| n=100        | "0 skaitlī: 2 reizes"                                                             | "0 skaitlī: 2 reizes"                                                             |
+--------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+
| n=1223344455 | "2 skaitlī: 2 reizes                                                              | "2 skaitlī: 2 reizes                                                              |
|              |  3 skaitlī: 2 reizes                                                              |  3 skaitlī: 2 reizes                                                              |
|              |  4 skaitlī: 3 reizes                                                              |  4 skaitlī: 3 reizes                                                              |
|              |  5 skaitlī: 2 reizes"                                                             |  5 skaitlī: 2 reizes"                                                             |
+--------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+
| n=77777777   | "7 skaitlī: 8 reizes"                                                             | "7 skaitlī: 8 reizes"                                                             |
+--------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+


*/