#define V_WIRNIK 20  /* Wolny obrót koła */
#define V_GONDOLA 20 /* Taka sama prędkość korekty (żeby idealnie kontrować) */

Pause 1000

/* === START: PEŁNA SYNCHRONIZACJA === */
/* Wątki sprawią, że to wszystko ruszy NA RAZ */

Begin_Parallel_Actions
  /* 1. Wątek główny: Kręcimy kołem o 90 stopni */
  Rotate Mlyn.Wirnik OX V_WIRNIK 90
  
  /* 2. Wątki poboczne: 12 gondoli kontruje obrót o -90 stopni */
  Rotate Mlyn.Wirnik.R01.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R02.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R03.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R04.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R05.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R06.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R07.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R08.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R09.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R10.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R11.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R12.Gon OX V_GONDOLA -90
End_Parallel_Actions

/* Krótka przerwa na podziwianie efektu */
Pause 500

/* === POWRÓT (Druga ćwiartka) === */
Begin_Parallel_Actions
  Rotate Mlyn.Wirnik OX V_WIRNIK 90
  Rotate Mlyn.Wirnik.R01.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R02.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R03.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R04.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R05.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R06.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R07.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R08.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R09.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R10.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R11.Gon OX V_GONDOLA -90
  Rotate Mlyn.Wirnik.R12.Gon OX V_GONDOLA -90
End_Parallel_Actions