# QueueSimulation
QueueSimulation C++

Temat: Symulacja czasu obslugi klientów w supermarkecie

Dane wejsciowe:
- liczba otwartych kas (kasjerów)
- widelki czasowe predkosc skanowania produktu w ms przez kasjerów
- 3 kategorie klientów z parametrami:
-- widelki od do czasu platnosci w kasie per transakcja w sekundach,
-- widelki od do liczby kupowanych produktów,
-- widelki od do czasu pakowania produktów w ms per produkt,
-- widelki od do liczby odwiedzin w kazdej godzinie otwarcia sklepu,
-- widelki od do czasu wybierania produktów w sklepie zanim dojdzie do kasy w sek
- interwal analizy danych w minutach
- minimalna róznica w dlugosci kolejek, po której przekroczeniu klienci przechodza do innych kas
- godziny od do otwarcia sklepu

Przykladowe dane:
- 4 kasy
- skanowanie w ms od 300 do 10000
- otwarcie sklepu od 8.00 do 22.00
- interwal analizy: 5m
- minimalna róznica kolejki dla migracji: 4
- klienci
-- seniorzy: platnosc (20 - 90 sek), liczba produktów (10-40), pakowanie (2000 - 18000 ms),  czas wyboru produktów (10-30min), liczba odwiedzin (0-10,5-50,20-80,25-120,15-120,5-80, itd...)
-- mlodziez: .....

Zalozenia:
- przy wyborze wartosci stosujemy rozklad normalny (czyli losujemy wartosc na podstawie rozkladu normalnego w zakresie od 0 do (do-od) i dodajemy do od)
- w przypadku przechodzenia klientów do inny, traktujemy ze klient przechodzi do innej kasy natychmiastowo, w 0s, teleportacja , czyli operacja migracji do innych kas jest wykonywana natychmiast (w jednym interwale) przez wszystkich oczekujacych i wynikiem migracji jest dlugosc kolejek maksymalnie rózniaca sie jednym klientem
- nastepny klient jest obslugiwany dopiero gdy poprzedni przeszedl cala operacje (skanowanie, platnosc, pakowanie)
- gdy klient przejdzie procedure pakowania, traktujemy to jako opuszczenie sklepu

Dane wyjsciowe: dla kazdego chwili zgodnie z zadanym interwalem (w formie np csv)
- liczba klientów na sklepie lacznie
- liczba klientów na sklepie z kazdej kategorii
- dlugosc kolejek na kazdej kasie
- narastajaco maksymalny czas postoju obecnych klientów w kolejce
- narastajaco maksymalny czas kasjera oczekujacego na klienta
- sredni czas obslugi w kasie klienta ogólnie
- sredni czas obslugi w kasie klienta z kazdej kategorii

Simulation results:

![simulationresults](https://user-images.githubusercontent.com/17216605/27081181-7ea5e83e-503f-11e7-9dcf-fd0f629fce65.png)
