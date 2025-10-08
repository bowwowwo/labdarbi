"""

Toms Gerbaševskis, tg25032

Izveidot programmu gan C++, gan Python, obligāti izmantojot norādītās vai kādas citas funkcijas.
Prasības tādas pašas kā iepriekšējā uzdevumā, precīzāk sk. Laboratorijas darbu noteikumos.

B4. Noskaidrot, vai dotajā naturālajā skaitlī ir atrodami vienādi cipari.
Ja ir, izdrukāt tos un skaitu, cik reižu dotais cipars ir sastopams.
Skaitļa dalīšana ciparos jāveic skaitliski.

Programma izveidota: 04.10.2025.

"""

ok = 1
n = 0

def common_numbers(sk):
    count = 0
    count_no_common_num = 0
    sk2 = sk
    num = 0

    for i in range(10):
        if sk2 < 10:
            print("skaitlis ir mazāks par 10")
            return
        
        temp = sk2
        count = 0

        while temp > 0:
            num = temp % 10
            temp //= 10
            if(i == num):
                count += 1
        if count > 1:
            print(f"{i} skaitlī: {count} reizes")
        else:
            count_no_common_num += 1

        if count_no_common_num == 9:
            print("nav vienādu ciparu")


while ok == 1:
    while True:
        n = int(input("Ievadiet naturālu skaitli n: "))
        if n < 1:
            print("nav naturāls skaitlis")
            continue
        else:
            break

    common_numbers(n)

    ok = int(input("Vai turpināt (1) vai beigt (0)?"))

"""
+--------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+
| Ievades dati |                                 Vēlamie rezultāti                                 |                                     Rezultāti                                     |
+--------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+
| n=0          | nav                                                                               | "skaitlis ir mazāks par 10"                                                       |
+--------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+
| n=901        | nav                                                                               | "nav vienādu ciparu"                                                              |
+--------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+
| n=8088       | "8 skaitlī: 3 reizes"                                                             | "8 skaitlī: 3 reizes"                                                             |
+--------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+
| n=55666900   | "0 skaitlī: 2 reizes                                                              | "0 skaitlī: 2 reizes                                                              |
|              |  5 skaitlī: 2 reizes                                                              |  5 skaitlī: 2 reizes                                                              |
|              |  6 skaitlī: 3 reizes                                                              |  6 skaitlī: 3 reizes                                                              |
+--------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+
| n=9999999999 | "9 skaitlī: 10 reizes"                                                            | "9 skaitlī: 10 reizes"                                                            |
+--------------+-----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------+

"""