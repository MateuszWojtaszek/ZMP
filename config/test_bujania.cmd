#define V_KO 10    /* Wolny obrót koła */
#define V_G  50    /* Prędkość korekty grawitacyjnej (dla stabilnych) */
#define V_S  80    /* Szybkie bujnięcie (dla bocznych) */

/* Start */
Pause 1000

/* =================================================================== */
/* CYKL 1: WYCHYLENIE NA ZEWNĄTRZ (Boki "rozjeżdżają się")             */
/* =================================================================== */
/* Koło: +10 stopni */
/* Stabilne (Góra/Dół): -10 (tylko grawitacja) */
/* Prawe (R03-05): -10 (graw) + 30 (bujnięcie w prawo) = +20 stopni */
/* Lewe (R09-11):  -10 (graw) - 30 (bujnięcie w lewo)  = -40 stopni */

Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KO 10

  /* --- STABILNE (Góra/Dół) --- */
  Rotate Mlyn.Wirnik.R01.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R02.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R12.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R06.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R07.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R08.Gon OX V_G -10

  /* --- PRAWA STRONA (Wychylenie w prawo) --- */
  Rotate Mlyn.Wirnik.R03.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R04.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R05.Gon OX V_S 20

  /* --- LEWA STRONA (Wychylenie w lewo) --- */
  Rotate Mlyn.Wirnik.R09.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R10.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R11.Gon OX V_S -40
End_Parallel_Actions


/* =================================================================== */
/* CYKL 2: POWRÓT DO PIONU                                             */
/* =================================================================== */
/* Koło: +10 stopni */
/* Stabilne: -10 */
/* Prawe: Muszą "zgasić" poprzednie +30, więc robią -30 (swing) -10 (graw) = -40 */
/* Lewe:  Muszą "zgasić" poprzednie -30, więc robią +30 (swing) -10 (graw) = +20 */

Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KO 10

  /* --- STABILNE --- */
  Rotate Mlyn.Wirnik.R01.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R02.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R12.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R06.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R07.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R08.Gon OX V_G -10

  /* --- PRAWA STRONA (Powrót) --- */
  Rotate Mlyn.Wirnik.R03.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R04.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R05.Gon OX V_S -40

  /* --- LEWA STRONA (Powrót) --- */
  Rotate Mlyn.Wirnik.R09.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R10.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R11.Gon OX V_S 20
End_Parallel_Actions


/* =================================================================== */
/* CYKL 3: WYCHYLENIE DO WEWNĄTRZ (Przecięcie osi)                     */
/* =================================================================== */
/* Koło: +10 stopni */
/* Prawe: Lecą w lewo (-30 swing - 10 graw = -40) */
/* Lewe:  Lecą w prawo (+30 swing - 10 graw = +20) */

Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KO 10

  /* --- STABILNE --- */
  Rotate Mlyn.Wirnik.R01.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R02.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R12.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R06.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R07.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R08.Gon OX V_G -10

  /* --- PRAWA STRONA (W lewo) --- */
  Rotate Mlyn.Wirnik.R03.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R04.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R05.Gon OX V_S -40

  /* --- LEWA STRONA (W prawo) --- */
  Rotate Mlyn.Wirnik.R09.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R10.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R11.Gon OX V_S 20
End_Parallel_Actions


/* =================================================================== */
/* CYKL 4: POWRÓT DO PIONU                                             */
/* =================================================================== */
/* Koło: +10 stopni */
/* Prawe: Wracają z lewej (+30 swing - 10 graw = +20) */
/* Lewe:  Wracają z prawej (-30 swing - 10 graw = -40) */

Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KO 10

  /* --- STABILNE --- */
  Rotate Mlyn.Wirnik.R01.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R02.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R12.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R06.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R07.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R08.Gon OX V_G -10

  /* --- PRAWA STRONA (Powrót) --- */
  Rotate Mlyn.Wirnik.R03.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R04.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R05.Gon OX V_S 20

  /* --- LEWA STRONA (Powrót) --- */
  Rotate Mlyn.Wirnik.R09.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R10.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R11.Gon OX V_S -40
End_Parallel_Actions


/* =================================================================== */
/* FINAŁ: USPOKOJENIE WSZYSTKICH                                       */
/* =================================================================== */
/* Koło: +10 stopni */
/* Wszyscy robią tylko korektę grawitacyjną (-10) */

Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KO 10
  Rotate Mlyn.Wirnik.R01.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R02.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R03.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R04.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R05.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R06.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R07.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R08.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R09.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R10.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R11.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R12.Gon OX V_G -10
End_Parallel_Actions

/* =================================================================== */
/* CYKL 1: WYCHYLENIE NA ZEWNĄTRZ (Boki "rozjeżdżają się")             */
/* =================================================================== */
/* Koło: +10 stopni */
/* Stabilne (Góra/Dół): -10 (tylko grawitacja) */
/* Prawe (R03-05): -10 (graw) + 30 (bujnięcie w prawo) = +20 stopni */
/* Lewe (R09-11):  -10 (graw) - 30 (bujnięcie w lewo)  = -40 stopni */

Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KO 10

  /* --- STABILNE (Góra/Dół) --- */
  Rotate Mlyn.Wirnik.R01.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R02.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R12.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R06.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R07.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R08.Gon OX V_G -10

  /* --- PRAWA STRONA (Wychylenie w prawo) --- */
  Rotate Mlyn.Wirnik.R03.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R04.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R05.Gon OX V_S 20

  /* --- LEWA STRONA (Wychylenie w lewo) --- */
  Rotate Mlyn.Wirnik.R09.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R10.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R11.Gon OX V_S -40
End_Parallel_Actions


/* =================================================================== */
/* CYKL 2: POWRÓT DO PIONU                                             */
/* =================================================================== */
/* Koło: +10 stopni */
/* Stabilne: -10 */
/* Prawe: Muszą "zgasić" poprzednie +30, więc robią -30 (swing) -10 (graw) = -40 */
/* Lewe:  Muszą "zgasić" poprzednie -30, więc robią +30 (swing) -10 (graw) = +20 */

Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KO 10

  /* --- STABILNE --- */
  Rotate Mlyn.Wirnik.R01.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R02.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R12.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R06.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R07.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R08.Gon OX V_G -10

  /* --- PRAWA STRONA (Powrót) --- */
  Rotate Mlyn.Wirnik.R03.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R04.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R05.Gon OX V_S -40

  /* --- LEWA STRONA (Powrót) --- */
  Rotate Mlyn.Wirnik.R09.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R10.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R11.Gon OX V_S 20
End_Parallel_Actions


/* =================================================================== */
/* CYKL 3: WYCHYLENIE DO WEWNĄTRZ (Przecięcie osi)                     */
/* =================================================================== */
/* Koło: +10 stopni */
/* Prawe: Lecą w lewo (-30 swing - 10 graw = -40) */
/* Lewe:  Lecą w prawo (+30 swing - 10 graw = +20) */

Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KO 10

  /* --- STABILNE --- */
  Rotate Mlyn.Wirnik.R01.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R02.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R12.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R06.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R07.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R08.Gon OX V_G -10

  /* --- PRAWA STRONA (W lewo) --- */
  Rotate Mlyn.Wirnik.R03.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R04.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R05.Gon OX V_S -40

  /* --- LEWA STRONA (W prawo) --- */
  Rotate Mlyn.Wirnik.R09.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R10.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R11.Gon OX V_S 20
End_Parallel_Actions


/* =================================================================== */
/* CYKL 4: POWRÓT DO PIONU                                             */
/* =================================================================== */
/* Koło: +10 stopni */
/* Prawe: Wracają z lewej (+30 swing - 10 graw = +20) */
/* Lewe:  Wracają z prawej (-30 swing - 10 graw = -40) */

Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KO 10

  /* --- STABILNE --- */
  Rotate Mlyn.Wirnik.R01.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R02.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R12.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R06.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R07.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R08.Gon OX V_G -10

  /* --- PRAWA STRONA (Powrót) --- */
  Rotate Mlyn.Wirnik.R03.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R04.Gon OX V_S 20
  Rotate Mlyn.Wirnik.R05.Gon OX V_S 20

  /* --- LEWA STRONA (Powrót) --- */
  Rotate Mlyn.Wirnik.R09.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R10.Gon OX V_S -40
  Rotate Mlyn.Wirnik.R11.Gon OX V_S -40
End_Parallel_Actions


/* =================================================================== */
/* FINAŁ: USPOKOJENIE WSZYSTKICH                                       */
/* =================================================================== */
/* Koło: +10 stopni */
/* Wszyscy robią tylko korektę grawitacyjną (-10) */

Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KO 10
  Rotate Mlyn.Wirnik.R01.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R02.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R03.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R04.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R05.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R06.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R07.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R08.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R09.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R10.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R11.Gon OX V_G -10
  Rotate Mlyn.Wirnik.R12.Gon OX V_G -10
End_Parallel_Actions