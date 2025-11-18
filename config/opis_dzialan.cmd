#define V_WOLNO   10   /* Prędkość koła */
#define V_SZYBKO  100  /* Prędkość korekty (musi być szybka) */

/* 1. Start - chwila na załadowanie widoku */
Pause 1000

/* === KROK 1: Obrót o 10 stopni === */
Rotate Mlyn.Wirnik OX V_WOLNO 10

/* KOREKTA: Wszystkie gondole wracają do pionu (-10) */
/* Jeśli naprawiłeś kod, to ten ruch powinien być szybki i skuteczny */
Rotate Mlyn.Wirnik.R01.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R02.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R03.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R04.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R05.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R06.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R07.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R08.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R09.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R10.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R11.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R12.Gon OX V_SZYBKO -10
Pause 200

/* === KROK 2: Kolejne 10 stopni (Razem 20) === */
Rotate Mlyn.Wirnik OX V_WOLNO 10

Rotate Mlyn.Wirnik.R01.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R02.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R03.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R04.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R05.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R06.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R07.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R08.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R09.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R10.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R11.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R12.Gon OX V_SZYBKO -10
Pause 200

/* === KROK 3: Kolejne 10 stopni (Razem 30) === */
Rotate Mlyn.Wirnik OX V_WOLNO 10

Rotate Mlyn.Wirnik.R01.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R02.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R03.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R04.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R05.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R06.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R07.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R08.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R09.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R10.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R11.Gon OX V_SZYBKO -10
Rotate Mlyn.Wirnik.R12.Gon OX V_SZYBKO -10
Pause 200

/* === KROK 4: Większy skok na koniec (30 stopni) === */
Rotate Mlyn.Wirnik OX V_WOLNO 30

/* Korekta o -30 */
Rotate Mlyn.Wirnik.R01.Gon OX V_SZYBKO -30
Rotate Mlyn.Wirnik.R02.Gon OX V_SZYBKO -30
Rotate Mlyn.Wirnik.R03.Gon OX V_SZYBKO -30
Rotate Mlyn.Wirnik.R04.Gon OX V_SZYBKO -30
Rotate Mlyn.Wirnik.R05.Gon OX V_SZYBKO -30
Rotate Mlyn.Wirnik.R06.Gon OX V_SZYBKO -30
Rotate Mlyn.Wirnik.R07.Gon OX V_SZYBKO -30
Rotate Mlyn.Wirnik.R08.Gon OX V_SZYBKO -30
Rotate Mlyn.Wirnik.R09.Gon OX V_SZYBKO -30
Rotate Mlyn.Wirnik.R10.Gon OX V_SZYBKO -30
Rotate Mlyn.Wirnik.R11.Gon OX V_SZYBKO -30
Rotate Mlyn.Wirnik.R12.Gon OX V_SZYBKO -30

Pause 1000