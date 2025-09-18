"""
  Toms Gerbaševskis, tg25032

  Izveidot programmu gan C++, gan Python. Ievadot loģiski nepareizus datus, programmai jāizdod atbilstošs paziņojums. Jābūt iespējai programmu izpildīt atkārtoti. Atrādot programmu, jāatrāda
  a) programmas teksts,
  b) testa piemēri,
  c) programma darbībā.
  Precīzākas prasības sk. Laboratorijas darbu noteikumos.

  A2. Doti naturāli skaitļi m un n. Noskaidrot starpību starp m un n dažādo reizinātāju skaitu (piemēram, m=9, n=6, atbilde ir -1, jo m ir mazāk reizinātāju nekā n).

  Programma izveidota: 08.09.2025.
"""
m = 0
n = 0
ok = 1

def factors(x):                                          # funkcija izmantota, lai kods būtu vieglāk lasāms
    count = 0
    x = int(x)    
    for i in range(x):                                      
        if x % (i+1) == 0:
            count += 1
    return(count)                                           

while ok == 1:
  while True:
    m = int(input("Ievadiet naturālu skaitli m: "))
    if m < 1:                                            # pārbauda vai ir nenaturāls skaitlis
      print("nav naturāls skaitlis")
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
        
  print(f"Skaitļu reizinātāju starpība:  {factors(m) - factors(n)}")
  ok = int(input("Vai turpināt (1) vai beigt (0)?"))

"""  testa plāns

+--------------+-------------------------+-------------------------+
| Ievades dati |    Vēlamie rezultāti    |        Rezultāti        |
+--------------+-------------------------+-------------------------+
| m=9 n=6      | -1                      | -1                      |
| m=10 n=10    | 0                       | 0                       |
| m=16 n=4     | 2                       | 2                       |
| m=-1         | "nav naturāls skaitlis" | "nav naturāls skaitlis" |
+--------------+-------------------------+-------------------------+

"""


  
