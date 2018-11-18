# AutoSonar
Urzadzenie z aplikacja Android do sterowania robotem z sonarem poprzez komunikacje Bluetooth

# Opis - elektronika
Urz�dzenie zwraca aktualn� pozycj� i dystans po BT wg schematu :
```
POZYCJA; DYSTANS
```
Aczkolwiek bez problemu mo�na to zmieni� na inny po��dany format.

Pozycja zawiera si� w przedziale 800-2200 - jest to bezpo�rednia warto�� OCR1A - odpowiadaj�cym odpowiedniu wychyleniu 0 i 90 stopni i po�rednim.

Dystans - jednostk� jest 0.1 mikrometra (co daje wzgl�dnie najwi�ksz� dok�adno�� bez kompensacji dla temperatury, przy zachowaniu zno�nej wydajno�ci).

# Uwagi og�le

Ostatnia aktualizacja: 18-11-2018

Sterowanie wychyleniem odbywa si� bezpo�rednioprzez modyfikowanie OCR1A. Bawiac si� z warto�ci� "skoku" iteracji mo�na sterowa� pr�dko�ci� skanowania, ale s� ograniczenia. Przy zbyt ma�ej warto�ci komunikacja przez UART i odczyt odleg�o�ci zajmuj� tyle czasu, �e skan zajmuje potwornie d�ugo.
Z kolei przy za du�ej serwo mo�e si� wychyla� bardzo gwa�townie lub w ograniczonym zakresie, a rozdzialczo�� skanu spada. Obecna warto�� 10 sprawdza si� nie�le, ale mo�naby j� zwi�kszy�.

Odczyt odleg�o�ci jest w g��wnej cz�ci p�tli bez u�ycia przerywa�. U�ycie przerywa� mog�oby zostawi� cz�� warto�ci skanu bez wskaza� (lub co gorsza - ze starymi warto�ciami). Ale ogranicza to wydajno�� i sprawia, �e okres przej�cia skanu nie jest deterministyczny. 

Pisane pod linuxem w visual studio code/platformio - slashe w drug� stron� mog� powodowa� problemy z kompilacj� pod windowsem ;)
# Aktualne problemy
Uk�ad:
- Serwo TowerPro nie dzia�a na uk�adzie testowym. Wygl�da to na zbyt du�y chwilowy pob�r pr�du (zmierzony >500mA), szczeg�lnie przy starcie. wymieni�em je na w�asne lekkie serwo e-sky. Polecam zosta� przy nim lub wstrzyma� zsi� z decyzj� po przetestowaniu ca�ego uk�adu na bateriach.
- Wewn�trzny zegar Atmeg jest zbyt niestabilny na szybk� komunikacj� UART, konieczne by�o zej�cie na 4800. Niestety nasze modu�y pozbawione s� przycisku pozwalaj�cego na konfiguracj�, tak�e korzystam chwilowo z w�asnego. Proponuj�: w ostatecznym projekcie korzysta� z zewn�trznego kwarca lub ods�oni� pola lutownicze i dolutowa� przycisk/zewrze� na chwil� i przekonfigurowa� modu�.
# TODO:
- posprz�ta� reszt� inicjalizacji i wrzuci� do biblioteki
- dorzuci� sterowanie nap�dem
- Zmodyfikowa� usound.c w celu ograniczenia maksymalnego odczytu sensora do racjonalnej odleg�o�ci.
