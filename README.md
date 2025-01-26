# Kartoizko Errotagailua - Informatikako Oinarriak

## Proiektuaren Deskribapena

Proiektu hau 24/25 Ikasturtea Ingeniaritza biomedikako grauda POPBL S1n parte da, kartoizko errotagailu bat eraiki eta aztertzeko. Osagai honek software alderdian oinarritzen da: kamera bidezko jarraitzaile batetik datorren ibilbide-datuak prozesatzen dituen C programa bat garatuko duzu, errotazio-diskoak lortutako abiadura angeluar maximoa kalkulatu eta zehazteko.

## Taldekideak

*   [1. June Senar] - [JuneSenar]
*   [2. Araitz Cuadrado] - [Aaraaiitzcm]
*   [3. Aitor Abio] - [Aitor Abio]
*   [4. Danel Barrutia] - [DanelBarru8]
*   [5. Nerea Calzada] - [nereacalzada]

## Konfigurazio Argibideak

Biltegi hau `vcpkg` eta `libcsv` (CSV fitxategiak irakurtzeko) erabiltzeko aurrez konfiguratuta dago.

1.  **Forkatu Biltegia:** Forkatu biltegi hau zure taldeko GitHub erakundera. Horrek zure kodea garatuko duzun proiektuaren kopia bat sortuko du.

2.  **Klonatu Biltegia:** Klonatu forkatu duzun biltegia zure ordenagailu lokalera Git bezeroa edo komando-lerroa erabiliz:

    ```bash
    git clone https://github.com/[Zure GitHub Erakundea]/[Zure Biltegiaren Izena].git
    ```

3.  **Ez da konfigurazio gehiago behar:** Beharrezkoak diren liburutegiak (`libcsv` ) `vcpkg` erabiliz aurrez konfiguratuta daude. Ez da konfigurazio gehiago behar hirugarren liburutegiak instalatzeko.

## Konpilazio Argibideak

Proiektua eta test-exekutagarria eraikitzeko, jarraitu urrats hauek:

1.  **Ireki proiektua Visual Studio 2022-rekin:** Ireki Visual Studio 2022 eta kargatu proiektuaren soluzioa (`.sln` fitxategia). Proiektua `Visual Studio 2022`-rekin soilik eraiki daiteke.
2.  **Eraiki proiektua:** Erabili Visual Studio-ko eraikuntza aukerak proiektua konpilatzeko.
    *   Eraikuntzak exekutagarri bat sortuko du `x64/debug/[proiektuaren izena].exe` helbidean.
    *   Test-suitea ere konpilatuko da `x64/debug/[proiektuaren izena]-Tests.exe` helbidean.
## Erabilera Argibideak

1.  **Exekutatu programa:** Programa exekutatzeko, erabili komando hau zure terminalean edo komando-gonbitan, eta ordezkatu `data.csv` zure ibilbide-datuen fitxategiaren bidearekin.

    ```bash
     x64/debug/[proiektuaren izena].exe data.csv
    ```

    *   Programak emandako CSV fitxategiko ibilbide-datuak prozesatuko ditu.
    *   Programak kalkulatutako abiadura angeluar maximoa kontsolan bistaratuko du.

2.  **Adibide-Sarrerako Fitxategia:** Ziurtatu zure sarrerako CSV fitxategiak formatu egokia duela. 

3.  **Irteera:**
    Programak disko birakariaren abiadura angeluar maximoa bistaratuko du. Honelako itxura izango du:
    ```
    Abiadura angeluar maximoa: [balioa] rad/s
    ```
    Non `[balioa]` kalkulatutako balioarekin ordezkatuko den.

## Test Argibideak

Unitate-testak exekutatzeko, jarraitu urrats hauek:

1.  **Eraiki Test Exekutagarria:** Ziurtatu test-proiektua eraiki duzula. Visual Studio-k test exekutagarria ere eraikiko du proiektua eraikitzean.
2.  **Exekutatu Testak:** Ireki Visual Studio IDE eta ireki **Test Explorer** panela, eta exekutatu testak IDEko interfaze integratua erabiliz. Bestela, test exekutagarria `build/debug/tests.exe` helbidean exekutatu dezakezu arazketa bertsioa eraiki baduzu, edo `x64/[proiektuaren izena]/tests.exe` helbidean kaleratze eraikuntza bat baduzu terminalean.

## Tracker Irteerako Formatua

Tracker irteerako fitxategia CSV (Komaz Banatutako Balioak) formatuan dago. Lerro bakoitzak datu-puntu bat adierazten du, une zehatz batean. Hona hemen identifikatu dugun egitura (gehitu hau fitxategia alderantziz ingeniarizatu ondoren).

| Zutabea    | Datu Mota  | Deskribapena                                                    |
| ----------- | --------- | -------------------------------------------------------------- |
| `t` |         `float`   | Datu-puntua kapturatu zeneko unea (segundotan).                 |
| `x`         | `float`   | Diskoan jarraitutako puntuaren x koordenatua (metrotan).         |
| `y`         | `float`   | Diskoan jarraitutako puntuaren y koordenatua (metrotan).         |
| ...         | ...       | (Gehitu beste zutabe batzuk zure aurkikuntzen arabera)          |

## Kodigoaren laburpena
Lehenik, Tracker programatik ateratako .txt fitxategia irakurtzen da readPoints funtzioan: Funtzio honek tabuladoreekin bereizitako datuak irakurri eta  array batean sartzen ditu eta array horren dimentsioa buetatu egten du (puntu kopurua) dena ondo badoa.
Gero, computeMaximumAngularVelocity funtzioak puntuak gordetzen dituen array-a nahiz haren puntu kopurua jasotzen ditu, eta puntuen harteko angulu aldaketa denbora aldaketarekin zatituz, abiadura angeluarra kalkulatzen du, eta maximoa bueltatu egiten du.
Azkenik, freepoints funtzioa puntuak gordetzen zituen array-a askatu egiten du.


