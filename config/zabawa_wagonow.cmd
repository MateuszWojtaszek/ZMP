#define V_KOLO 15
#define V_SWING 40 

/* Czekamy na pasażerów */
Pause 1000

/* === FAZA 1: Zerwanie się wiatru (Bujanie w miejscu) === */
/* Tylko gondole się ruszają, koło stoi */

Begin_Parallel_Actions
  /* Wychylenie wszystkich w prawo */
  Rotate Mlyn.Wirnik.R01.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R02.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R03.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R04.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R05.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R06.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R07.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R08.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R09.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R10.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R11.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R12.Gon OX V_SWING 15
End_Parallel_Actions

Begin_Parallel_Actions
  /* Przelot na lewą stronę (-30 stopni zmiany) */
  Rotate Mlyn.Wirnik.R01.Gon OX V_SWING -30
  Rotate Mlyn.Wirnik.R02.Gon OX V_SWING -30
  Rotate Mlyn.Wirnik.R03.Gon OX V_SWING -30
  Rotate Mlyn.Wirnik.R04.Gon OX V_SWING -30
  Rotate Mlyn.Wirnik.R05.Gon OX V_SWING -30
  Rotate Mlyn.Wirnik.R06.Gon OX V_SWING -30
  Rotate Mlyn.Wirnik.R07.Gon OX V_SWING -30
  Rotate Mlyn.Wirnik.R08.Gon OX V_SWING -30
  Rotate Mlyn.Wirnik.R09.Gon OX V_SWING -30
  Rotate Mlyn.Wirnik.R10.Gon OX V_SWING -30
  Rotate Mlyn.Wirnik.R11.Gon OX V_SWING -30
  Rotate Mlyn.Wirnik.R12.Gon OX V_SWING -30
End_Parallel_Actions

Begin_Parallel_Actions
  /* Powrót do pionu (+15) */
  Rotate Mlyn.Wirnik.R01.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R02.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R03.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R04.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R05.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R06.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R07.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R08.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R09.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R10.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R11.Gon OX V_SWING 15
  Rotate Mlyn.Wirnik.R12.Gon OX V_SWING 15
End_Parallel_Actions


/* === FAZA 2: Start Młyna z bujaniem === */
/* Koło rusza, a wagoniki wciąż mają pęd od wiatru */

/* KROK A: Koło +10, Gondola -5 (Słaba korekta -> Wychyla się w prawo) */
Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KOLO 10
  Rotate Mlyn.Wirnik.R01.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R02.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R03.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R04.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R05.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R06.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R07.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R08.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R09.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R10.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R11.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R12.Gon OX V_SWING -5
End_Parallel_Actions

/* KROK B: Koło +10, Gondola -15 (Mocna korekta -> Wraca do środka) */
Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KOLO 10
  Rotate Mlyn.Wirnik.R01.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R02.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R03.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R04.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R05.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R06.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R07.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R08.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R09.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R10.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R11.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R12.Gon OX V_SWING -15
End_Parallel_Actions

/* KROK C: Koło +10, Gondola -15 (Mocna korekta -> Przelatuje na lewo) */
Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KOLO 10
  Rotate Mlyn.Wirnik.R01.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R02.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R03.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R04.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R05.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R06.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R07.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R08.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R09.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R10.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R11.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R12.Gon OX V_SWING -15
End_Parallel_Actions

/* KROK D: Koło +10, Gondola -5 (Słaba korekta -> Wraca do środka) */
Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KOLO 10
  Rotate Mlyn.Wirnik.R01.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R02.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R03.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R04.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R05.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R06.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R07.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R08.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R09.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R10.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R11.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R12.Gon OX V_SWING -5
End_Parallel_Actions


/* === Powtórka cyklu (Kolejne 40 stopni) === */

Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KOLO 10
  Rotate Mlyn.Wirnik.R01.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R02.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R03.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R04.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R05.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R06.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R07.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R08.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R09.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R10.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R11.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R12.Gon OX V_SWING -5
End_Parallel_Actions

Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KOLO 10
  Rotate Mlyn.Wirnik.R01.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R02.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R03.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R04.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R05.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R06.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R07.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R08.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R09.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R10.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R11.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R12.Gon OX V_SWING -15
End_Parallel_Actions

Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KOLO 10
  Rotate Mlyn.Wirnik.R01.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R02.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R03.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R04.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R05.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R06.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R07.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R08.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R09.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R10.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R11.Gon OX V_SWING -15
  Rotate Mlyn.Wirnik.R12.Gon OX V_SWING -15
End_Parallel_Actions

Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_KOLO 10
  Rotate Mlyn.Wirnik.R01.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R02.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R03.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R04.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R05.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R06.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R07.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R08.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R09.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R10.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R11.Gon OX V_SWING -5
  Rotate Mlyn.Wirnik.R12.Gon OX V_SWING -5
End_Parallel_Actions

/* Pełna moc na koniec - szybki obrót bez korekty (wirowanie) */
Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX 60 360
End_Parallel_Actions