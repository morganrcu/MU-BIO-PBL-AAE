# Kartoizko Errotagailuaren Abiadura Angeluar Maximoaren Kalkulua

## Programaren Deskribapena

Eskuzko disko zentrifugagailuak lortutako abiadura maximoa kalkula dezakeen C programa bat garatu da. Programak kamera-jarraipen sistema batek jasotako ibilbide-datuak prozesatzen ditu. Horretarako, datu horiek (diskoaren puntu jakin batek denboran zehar duen posizio angeluarra) biltzen dituen CSV fitxategi bat jasotzen du. Behin datuak prozesatu dituela, gorputzak lortutako abiadura angeluar maximoa kalkulatu eta balio hori pantailan erakutsiko dio erabiltzaileari. Fitxategi hori Tracker-etik etortzea espero da, bideoetan mugimenduak aztertzeko erabiltzen den softwarea. 

## Programaren Zenbait Xehetasun

Diskoaren puntu jakin batek duen posizio angeluarra zehaztasun handiagoz aztertzeko, kamera geldoan grabatutako bideo bat erabili da (Tracker-ak prozesatu duena). Denbora tarte laburretan gertatzen diren mugimenduak xehetasunez behatzeko aukera ematen du teknika honek. Hala ere, kamera geldoan egindako grabazioak abiadura murrizteko faktore bat sartzen du. Hau da, programak itzultzen duen abiadura maximoaren balioa benetako abiadura baino txikiagoa da.

Bideoa abiadura errealaren 1/4-ean grabatu da; beraz, benetako abiadura angeluarra lortzeko, programak lortutako emaitza 4rekin biderkatu beharko da. Horrek bermatzen du neurketek zehaztasunez islatzea aztertutako sistemaren benetako baldintzak.

Aipatzekoa da programak ez duela kalkulu hori automatizatu, abiadura errealean grabatutako gorputz baten datu-puntuak biltzen dituen beste CSV fitxategi bat jasoz gero, abiadura angeluarra behar bezala kalkulatzeko.

## Taldekideak

*   [Maider Beitia] - [MaiderB]
*   [Irati Cid] - [iraticid]
*   [Inge Iruretagoyena] - [ingeiruretagoyena]
*   [Irene Jurado] - [IreneJurado]
*   [Ignacio Lamberto] - [Ignacio-bot]

## Konfigurazio Argibideak

1. **Klonatu Biltegia:** Klonatu biltegia zure ordenagailu lokalera Git bezeroa edo komando-lerroa erabiliz:

    ```bash
    git clone https://github.com/1mailaPBL1/MU-BIO-PBL-AAE.git
    ```

## Konpilazio Argibideak

1.  **Ireki proiektua Visual Studio 2022-rekin:** Ireki Visual Studio 2022 eta kargatu proiektuari dagokion .sln irtenbide-fitxategia.
   
2.  **Proiektua konpilatu:** Erabili Visual Studio-ko eraikuntza aukerak proiektua konpilatzeko.
    *   Eraikuntzak exekutagarri bat sortuko du `x64/debug/MU-BIO-PBL-AAE.exe` helbidean.
    *   Test-suitea ere konpilatuko da `x64/debug/MU-BIO-PBL-AAE-Tests.exe` helbidean.
      
## Erabilera Argibideak

1.  **CSV fitxategiaren kokapena:** Ziurtatu sarrerako datuak dituen .csv fitxategia konpilatu ondoren sortutako .exe fitxategiaren direktorio berean dagoela. Hala ez bada, .csv fitxategia .exe-ren direktorioan jarri programak datuak behar bezala atzitu ahal izateko.

2.  **Exekutatu programa:** Programa exekutatzeko, erabili komando hau zure terminalean edo komando-gonbitan. Kontuan izan biltegi honetan erantsi den .csv fitxategiak izen hau duela: data.csv. 

    ```bash
     x64/debug/MU-BIO-PBL-AAE.exe data.csv
    ```

    *   Programak emandako CSV fitxategiko ibilbide-datuak prozesatuko ditu.
    *   Programak kalkulatutako abiadura angeluar maximoa kontsolan bistaratuko du.

2.  **Ibilbide-datuen fitxategia:** Biltegian erantsitako fitxategia data.csv erabiltzen ez baduzu, ziurtatu zure sarrerako CSV fitxategiak formatu egokia duela. Izan ere, Tracker-ak .txt fitxategiak sortzen ditu, eta .csv-era bihurtu behar direnak. 

3.  **Irteera:**
    Programak disko birakariaren abiadura angeluar maximoa bistaratuko du. Honelako itxura izango du:
    ```
    Abiadura angeluar maximoa: [balioa] rad/s
    ```
    Non `[balioa]` kalkulatutako balioarekin ordezkatuko den.

## Test Argibideak

Biltegiak test izeneko karpeta bat du, eta bertan programaren funtzio nagusiak baliozkotzeko unitate-testak daude.

1.  **Exekutatu Testak:** Ireki Visual Studio IDE eta ireki **Test Explorer** panela, eta exekutatu testak IDEko interfaze integratua erabiliz. Bestela, test exekutagarria `build/debug/tests.exe` helbidean exekutatu dezakezu, edo `x64/MU-BIO-PBL-AAE/tests.exe` helbidean kaleratze eraikuntza bat baduzu terminalean.

## Tracker Irteerako Formatua

Tracker irteerako fitxategia CSV (Komaz Banatutako Balioak) formatuan dago. Lerro bakoitzak datu-puntu bat adierazten du, une zehatz batean. Hona hemen identifikatutako egitura. 

| Zutabea    | Datu Mota  | Deskribapena                                                   |
| ----------- | --------- | -------------------------------------------------------------- |
| `timestamp` | `float`   | Datu-puntua kapturatu zeneko unea (segundotan).                |
| `θ`         | `float`   | Datu-puntuaren posizio angeluarra (radianetan).                |

## Programaren Oinarri Teorikoa

Programak abiadura angeluarra kalkulatzen du diferentzia finituen metodoa erabiliz, hau da, posizio angeluarraren eta denboraren datu bikote jarraituak hartuz. Pare bakoitzarentzat, posizio angeluarraren diferentzia kalkulatzen da, eta dagokion denbora-diferentziarekin zatitzen da. Horren ondorioz, bi une horien arteko batez besteko abiadura angeluarra hurbiltzen da. Prozesua fitxategiko datu-bikote guztietan errepikatzen da. Programa exekutatu ahala kalkulatutako abiadura-baliorik handiena gordez, abiadura angeluar maximoa lortzen da.
       
