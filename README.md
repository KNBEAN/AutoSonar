# AutoSonar
Urzadzenie z aplikacja Android do sterowania robotem z sonarem poprzez komunikacje Bluetooth

# Opis - elektronika
Urz¹dzenie zwraca aktualn¹ pozycjê i dystans po BT wg schematu :
```
POZYCJA; DYSTANS
```
Aczkolwiek bez problemu mo¿na to zmieniæ na inny po¿¹dany format.

Pozycja zawiera siê w przedziale 800-2200 - jest to bezpoœrednia wartoœæ OCR1A - odpowiadaj¹cym odpowiedniu wychyleniu 0 i 90 stopni i poœrednim.

Dystans - jednostk¹ jest 0.1 mikrometra (co daje wzglêdnie najwiêksz¹ dok³adnoœæ bez kompensacji dla temperatury, przy zachowaniu znoœnej wydajnoœci).

# Uwagi ogóle

Ostatnia aktualizacja: 18-11-2018

Sterowanie wychyleniem odbywa siê bezpoœrednioprzez modyfikowanie OCR1A. Bawiac siê z wartoœci¹ "skoku" iteracji mo¿na sterowaæ prêdkoœci¹ skanowania, ale s¹ ograniczenia. Przy zbyt ma³ej wartoœci komunikacja przez UART i odczyt odleg³oœci zajmuj¹ tyle czasu, ¿e skan zajmuje potwornie d³ugo.
Z kolei przy za du¿ej serwo mo¿e siê wychylaæ bardzo gwa³townie lub w ograniczonym zakresie, a rozdzialczoœæ skanu spada. Obecna wartoœæ 10 sprawdza siê nieŸle, ale mo¿naby j¹ zwiêkszyæ.

Odczyt odleg³oœci jest w g³ównej czêœci pêtli bez u¿ycia przerywañ. U¿ycie przerywañ mog³oby zostawiæ czêœæ wartoœci skanu bez wskazañ (lub co gorsza - ze starymi wartoœciami). Ale ogranicza to wydajnoœæ i sprawia, ¿e okres przejœcia skanu nie jest deterministyczny. 

Pisane pod linuxem w visual studio code/platformio - slashe w drug¹ stronê mog¹ powodowaæ problemy z kompilacj¹ pod windowsem ;)
# Aktualne problemy
Uk³ad:
- Serwo TowerPro nie dzia³a na uk³adzie testowym. Wygl¹da to na zbyt du¿y chwilowy pobór pr¹du (zmierzony >500mA), szczególnie przy starcie. wymieni³em je na w³asne lekkie serwo e-sky. Polecam zostaæ przy nim lub wstrzymaæ zsiê z decyzj¹ po przetestowaniu ca³ego uk³adu na bateriach.
- Wewnêtrzny zegar Atmeg jest zbyt niestabilny na szybk¹ komunikacjê UART, konieczne by³o zejœcie na 4800. Niestety nasze modu³y pozbawione s¹ przycisku pozwalaj¹cego na konfiguracjê, tak¿e korzystam chwilowo z w³asnego. Proponujê: w ostatecznym projekcie korzystaæ z zewnêtrznego kwarca lub ods³oniæ pola lutownicze i dolutowaæ przycisk/zewrzeæ na chwilê i przekonfigurowaæ modu³.
# TODO:
- posprz¹taæ resztê inicjalizacji i wrzuciæ do biblioteki
- dorzuciæ sterowanie napêdem
- Zmodyfikowaæ usound.c w celu ograniczenia maksymalnego odczytu sensora do racjonalnej odleg³oœci.
