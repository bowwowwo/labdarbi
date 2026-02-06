/*

Izveidot programmu valodā C++, izmantojot objektorientētās programmēšanas līdzekļus un strukturējot programmu vismaz trīs failos.
Klases hederi obligāti novietot atsevišķā hedera failā (program.h).
Visas metodes realizēt ārpus hedera faila – speciālā C++ failā (program.cpp).
Funkcija main ievietojama vēl citā C++ failā (main.cpp). Klases dati pēc noklusēšanas ir slēpti (private),
bet metodes atklātas (public). Šīs programmas ietvaros NAV obligāti jānodrošina tāda lietotāja saskarne,
kāda tika prasīta iepriekšējos trīs uzdevumos (main funkciju drīkst “cieti” iekodēt). Citas prasības sk.
Laboratorijas darbu noteikumos.

D6. Izveidot klasi "Skaitļu rinda" - Nqueue (queue, pa vienu pusi ieliek, pa otru izņem!),
kurā glabājas masīvs ar skaitliskām vērtībām (int) garumā pieci un rindas elementu skaits.
Klasei izveidot šādas metodes: (1) konstruktors, (2) destruktors,
kurš paziņo par objekta likvidēšanu un likvidēto elementu skaitu (ja likvidēšanas brīdī rinda nav tukša),
(3) metode "Ielikt" - enqueue, kas pievieno rindai elementu, ja tā nav pilna, (4) metode "Izņemt" - dequeue,
kas izņem no rindas elementu un atgriež tā vērtību, (5) metode "CikElementu" - count,
kas atgriež elementu skaitu rindā, (6) metode "IrTukša" - isEmpty, kas noskaidro,
vai rinda ir tukša. Pirms uzdevuma veikšanas precīzi noskaidrot, ko nozīmē jēdziens rinda (queue) kā datu struktūra.

*/


class Nqueue{
int numValue[5];
int queueCount;
public:
    Nqueue();
    ~Nqueue();
    void enqueue(int x); // ieliek padoto skaitli
    int dequeue(); // izņem mainīgo no masīva ar kārtas skaitli, kas padots
    int Count();
    bool isEmpty();

};
