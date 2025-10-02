"""
  Toms Gerbaševskis, tg25032

  Izveidot programmu gan C++, gan Python. Ievadot loģiski nepareizus datus, programmai jāizdod atbilstošs paziņojums. Jābūt iespējai programmu izpildīt atkārtoti. Atrādot programmu, jāatrāda
  a) programmas teksts,
  b) testa piemēri,
  c) programma darbībā.
  Precīzākas prasības sk. Laboratorijas darbu noteikumos.

  A2. Doti naturāli skaitļi m un n. Noskaidrot starpību starp m un n dažādo reizinātāju skaitu (piemēram, m=9, n=6, atbilde ir -1, jo m ir mazāk reizinātāju nekā n).

  Programma izveidota: 19.09.2025.
"""
m = 0
n = 0
ok = 1

def different_factor_count(m ,n):  #funkcija, kas atgriež argumenta skaitļu dažādo reizinātāju skaitu
    
    count_different_m = 0
    count_different_n = 0
    count_same = 0

    m = int(m) 
    n = int(n)   

    for i in range(m):         #nested for loop iegūst vienādo reizinātāju skaitu m un n          
        if m % (i+1) == 0:     #iegūst reizinātāju skaitu m
          count_different_m += 1
          for j in range(n):
            if n % (j+1) == 0:
              if i == j:       #pārbaude vienādiem reizinātājiem
                count_same += 1

    for i in range(n):        #iegūst reizinātāju skaitu n
      if n % (i+1) == 0:
        count_different_n += 1

    count_different_m -= count_same
    count_different_n -= count_same

    return(count_different_m - count_different_n)                                           

while ok == 1:                              #programmas darbības sākums
  while True:
    m = int(input("Ievadiet naturālu skaitli m: "))
    if m < 1:
      print("nav naturāls skaitlis")  # * ne naturāla skaitļa pārbaude
      continue
    else:
      break 

  while True:
    n = int(input("Ievadiet naturālu skaitli n: "))
    if n < 1:
      print("nav naturāls skaitlis")
      continue
    else:
      break 
        
  print(f"Skaitļu reizinātāju starpība:  {different_factor_count(m , n)}")
  ok = int(input("Vai turpināt (1) vai beigt (0)?"))

"""  testa plāns

+--------------+-------------------------+-------------------------+
| Ievades dati |    Vēlamie rezultāti    |        Rezultāti        |
+--------------+-------------------------+-------------------------+
| m=9 n=6      | -1                      | -1                      |
| m=10 n=10    | 0                       | 0                       |
| m=16 n=4     | 2                       | 2                       |
| m=-1         | "nav naturāls skaitlis" | "nav naturāls skaitlis" |
| m=1 n=-1     | "nav naturāls skaitlis" | "nav naturāls skaitlis" |
+--------------+-------------------------+-------------------------+

"""

  