# RapidFlipperApp

Aplicație de „fun" pentru Flipper Zero care cântă o melodie pe buzzer-ul intern, cu redare pe thread separat (UI-ul rămâne responsiv în timp ce cântă).

## ⚠️ Notă despre melodie

Imnul Rapidului (versuri Adrian Păunescu, muzică Victor Socaciu, 1979) este o compoziție cu autor, protejată prin drepturi de autor. **Nu** am inclus transcrierea ei exactă notă-cu-notă.

Ce găsești în `MELODY[]` e o fanfară scurtă, generică, compusă ca placeholder — tot motorul de redare (frecvențe + durate) e funcțional și gata de folosit. Dacă vrei să cânți chiar imnul, înlocuiește conținutul array-ului cu propria transcriere (din ureche, cu un tuner, sau după o partitură pe care o ai).

## Control

- **Sus / Jos** — navigare în meniu
- **OK** — pornește redarea melodiei / intră în ecranul selectat
- **Back** — oprește melodia din mers (dacă cântă) / înapoi în meniu / iese din aplicație

## Compilare & rulare

```
ufbt launch
```

sau doar compilare:

```
ufbt
```

## Structură cod

- `application.fam` — manifestul aplicației
- `rapid_flipper_app.c` — tot codul:
  - `Note` — struct simplu `{frecvență_Hz, durată_ms}`, cu `REST` (0 Hz) pentru pauze
  - `MELODY[]` — array-ul cu melodia (placeholder-ul de înlocuit)
  - `play_melody_thread()` — rulează pe un `FuriThread` separat, controlează buzzer-ul via `furi_hal_speaker_*`
  - bucla principală de UI — meniu, ecran „Se cântă...", ecran „Despre"
- `icon.png` / `images/` — iconița din meniul Flipper-ului

## Cum pui propria melodie

Ai la dispoziție notele predefinite `NOTE_C4` ... `NOTE_A5` (frecvențe standard). Scrii melodia ca listă de perechi:

```c
static const Note MELODY[] = {
    {NOTE_G4, 300}, {NOTE_A4, 300}, {NOTE_B4, 400},
    {REST, 100},
    {NOTE_C5, 500},
};
```

Restul aplicației (thread-ul, meniul, oprirea cu Back) rămâne neschimbat — doar înlocuiești conținutul array-ului.

## Idei de extindere

- Mai multe melodii selectabile din meniu (un `MELODY_SETS[]` cu mai multe array-uri)
- Sincronizare cu LED-uri de notificare pe fiecare notă (efect de „vizualizator")
- Volum ajustabil cu Stânga/Dreapta în timpul redării
# RapidBucurestiFlipperApp
