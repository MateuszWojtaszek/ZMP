#define V_TURN 30
#define V_GRAV 30

/* 1. START SYMULACJI */
Pause 1000

/* 2. OBRÓT O 45 STOPNI */
Rotate Mlyn.Wirnik OX V_TURN 45

/* KOREKTA GRAWITACYJNA DLA WSZYSTKICH GONDOL */
/* Wirnik poszedl +45, gondole musza isc -45, zeby wisialy pionowo */
Rotate Mlyn.Wirnik.R01.Gon OX V_GRAV -45
Rotate Mlyn.Wirnik.R02.Gon OX V_GRAV -45
Rotate Mlyn.Wirnik.R03.Gon OX V_GRAV -45
Rotate Mlyn.Wirnik.R04.Gon OX V_GRAV -45
Rotate Mlyn.Wirnik.R05.Gon OX V_GRAV -45
Rotate Mlyn.Wirnik.R06.Gon OX V_GRAV -45
Rotate Mlyn.Wirnik.R07.Gon OX V_GRAV -45
Rotate Mlyn.Wirnik.R08.Gon OX V_GRAV -45
Rotate Mlyn.Wirnik.R09.Gon OX V_GRAV -45
Rotate Mlyn.Wirnik.R10.Gon OX V_GRAV -45
Rotate Mlyn.Wirnik.R11.Gon OX V_GRAV -45
Rotate Mlyn.Wirnik.R12.Gon OX V_GRAV -45

Pause 500

/* 3. PEŁNA MOC (BEZ KOREKTY - pasazerowie krzycza) */
/* Żeby zobaczyć jak wszystko wiruje razem */
Rotate Mlyn.Wirnik OX 80 360