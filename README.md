# 🏁 Rapid Flipper App

O aplicație custom creată pentru **Flipper Zero** dedicată suporterilor **FC Rapid București**. Aplicația include grafică Pixel Art (128x64), meniu interactiv, scandări text și un motor dedicat redării liniei melodice pe buzzer-ul intern (piezo speaker).

---

## 🚀 Caracteristici (Features)

* **🖼️ HomeScreen Pixel Art (128x64):** Sigla oficială, acvila și delfinul din Giulești convertite fidel în format XBM monocrom pe tot ecranul Flipper-ului.
* **🎵 Meniu Cântece & Scandări:** Sub-meniu dedicat cu 8 piese/repertorii de peluză adaptate pentru buzzer-ul hardware:
  1. *Imnul Rapidului* (Victor Socaciu)
  2. *În 1923 s-a născut un mit*
  3. *Gândul ce mereu îl port*
  4. *Samba din Giulești*
  5. *C-așa sunt eu rapidist*
  6. *Prima oară pe Giulești*
  7. *Haide Rapidul, Haide Realul*
  8. *Olé, olé, mulțumim Rapidule!*
* **🔥 Ecrane dedicate Peluza Nord:** Meniu interactiv cu scandările clasice de rivalitate (*Anti Steaua, Anti Dinamo, Anti FCSB*).
* **🎮 Navigare fluidă:** Scrolling automat în meniuri și control facil din D-Pad + butonul Back.
* **⚡ Multithreading curat:** Redarea muzicală rulează pe un thread separat, protejat prin Mutex-uri pentru a preveni blocarea interfeței grafice (UI).

---

## 📂 Structura Proiectului

```text
RapidBucurestiFlipperApp/
├── application.fam       # Manifestul aplicatiei pentru FBT/uFBT
├── rapid_flipper_app.c   # Codul sursa principal (UI, Audio Engine, XBM Graphics)
├── icon.png              # Iconita aplicatiei (10x10 pixel art 'R')
└── README.md             # Documentatia proiectului


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
