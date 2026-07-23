/*
 * RapidFlipperApp - Imnul Rapidului, Cantece de Peluza, HomeScreen Pixel Art (128x64) si Meniu
 * Compilare: ufbt / ufbt launch
 */

#include <furi.h>
#include <furi_hal.h>
#include <furi_hal_speaker.h>
#include <gui/gui.h>
#include <input/input.h>

/* ---------------- Grafica HomeScreen (128x64 XBM Monocrom) ---------------- */

#define RAPID_LOGO_WIDTH  128
#define RAPID_LOGO_HEIGHT 64

static const uint8_t rapid_logo_bits[] = {
    0x3F, 0xBF, 0xDF, 0xEF, 0x07, 0x7E, 0x66, 0x7E, 0x77, 0x3F, 0xBF, 0xFF, 0xFF, 0x07, 0x00, 0x00,
    0x33, 0xB3, 0x3B, 0xE3, 0x0E, 0xEE, 0x66, 0x66, 0x77, 0x33, 0x83, 0x03, 0x87, 0x03, 0x00, 0x00,
    0x3F, 0xBF, 0x1F, 0xE3, 0x0E, 0x7E, 0x66, 0x06, 0x77, 0x3F, 0x8F, 0x1F, 0x87, 0x03, 0x00, 0x00,
    0x33, 0xB3, 0x03, 0xE3, 0x0E, 0xEE, 0x66, 0x76, 0x77, 0x33, 0x03, 0x38, 0x87, 0x03, 0x00, 0x00,
    0x33, 0xB3, 0xC3, 0xEF, 0x07, 0x7E, 0x7E, 0x7E, 0x3E, 0x33, 0xBF, 0x1F, 0xE6, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xFC, 0x3F, 0x30, 0x7C, 0x00, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xFE, 0xF1, 0x70, 0x4C, 0xE6, 0xF1, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x7F, 0x98, 0x79, 0x7C, 0x66, 0xC6, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3F, 0xF0, 0xF8, 0x0C, 0x66, 0x04, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1F, 0xD0, 0xCC, 0x0C, 0x66, 0x06, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xC0, 0xFF, 0xFF, 0x1F, 0xB8, 0x01, 0x3E, 0xE6, 0x03, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x1C, 0x00, 0x00, 0xF0, 0x0F, 0xC0, 0x8A, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00,
    0x08, 0x00, 0x00, 0x00, 0x18, 0xA0, 0x05, 0x01, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
    0xF0, 0xFF, 0xFF, 0x7F, 0x42, 0xE0, 0x01, 0x81, 0xD8, 0xFF, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x20, 0x88, 0x00, 0x01, 0x01, 0x84, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFF, 0xFF, 0x7F, 0x10, 0x01, 0x03, 0x21, 0x82, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x02, 0x00, 0x40, 0x10, 0x01, 0x01, 0x10, 0x41, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xF8, 0xFF, 0xFF, 0x20, 0x42, 0x00, 0x12, 0xE1, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xE0, 0xFF, 0x7F, 0x41, 0x3C, 0x00, 0x86, 0xD0, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1F, 0x01, 0xF8, 0xC0, 0x47, 0x10, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0F, 0x03, 0xFD, 0xFB, 0x0F, 0x10, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x8F, 0x02, 0xEF, 0xFF, 0x3C, 0x68, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
    0x00, 0x00, 0x00, 0x3F, 0xC4, 0x03, 0x1E, 0xF0, 0x04, 0x1F, 0x00, 0x00, 0x00, 0x80, 0x03, 0x00,
    0x00, 0x00, 0x00, 0x1F, 0xEA, 0x00, 0x1F, 0xC0, 0x03, 0x1E, 0x00, 0x00, 0x00, 0xC0, 0x3F, 0x00,
    0x00, 0x00, 0x00, 0xBF, 0x70, 0x80, 0x3B, 0xC0, 0xA3, 0x1F, 0x00, 0x00, 0xC0, 0xFF, 0xC7, 0x3F,
    0x00, 0x00, 0x00, 0x5F, 0x68, 0xC0, 0xE8, 0xC0, 0x85, 0x1E, 0x00, 0x00, 0x58, 0x80, 0x1D, 0x80,
    0x00, 0x00, 0x00, 0x5E, 0x64, 0xE0, 0xFF, 0xC1, 0x49, 0x0F, 0x00, 0x00, 0x02, 0x00, 0x7F, 0xF8,
    0x00, 0x00, 0x00, 0x9E, 0xE1, 0xE3, 0xFE, 0xF9, 0x71, 0x0F, 0x00, 0x00, 0x01, 0x00, 0xFF, 0x1F,
    0x00, 0x00, 0x00, 0x3E, 0xF1, 0xCF, 0x73, 0xFC, 0x91, 0x0F, 0x00, 0x80, 0x00, 0x00, 0xFE, 0x0F,
    0x00, 0x00, 0x00, 0x3C, 0xCC, 0x9F, 0x38, 0xFF, 0x8C, 0x0F, 0x00, 0x40, 0x00, 0x00, 0xFE, 0x0F,
    0x00, 0x00, 0x00, 0x3C, 0xE0, 0x7E, 0xC0, 0xFF, 0x82, 0x0F, 0x00, 0x40, 0x00, 0x00, 0x7B, 0x1E,
    0x00, 0x00, 0x00, 0x7C, 0xC0, 0x7D, 0xCC, 0x6F, 0x80, 0x07, 0x00, 0x40, 0x30, 0x80, 0xB3, 0x17,
    0x00, 0x00, 0x00, 0x7C, 0x80, 0xFD, 0xEC, 0x77, 0xC0, 0x07, 0x00, 0xC0, 0x30, 0x80, 0x9F, 0x1F,
    0x00, 0x00, 0x00, 0xF8, 0x80, 0xF3, 0xFD, 0x33, 0xC0, 0x03, 0x00, 0x00, 0x05, 0xE0, 0x3C, 0x1E,
    0x00, 0x00, 0x00, 0xF8, 0x00, 0xE3, 0xFF, 0x18, 0xE0, 0x03, 0x00, 0x08, 0x02, 0x38, 0xB0, 0x3B,
    0x00, 0x00, 0x00, 0xF0, 0x01, 0x06, 0x0E, 0x1C, 0xE0, 0x03, 0x00, 0xF8, 0xFE, 0x1F, 0x84, 0x39,
    0x00, 0x00, 0x00, 0xF0, 0x01, 0x0E, 0x0C, 0x1E, 0xF0, 0x01, 0x00, 0xF0, 0x01, 0x1F, 0xDA, 0x38,
    0x00, 0x00, 0x00, 0xE0, 0x03, 0x9E, 0x6A, 0x17, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x7E, 0x36,
    0x00, 0x00, 0xC0, 0xF0, 0x07, 0xBE, 0xEA, 0x1F, 0xF8, 0xC0, 0x00, 0x00, 0x00, 0x5E, 0xFE, 0x37,
    0x00, 0x30, 0x1F, 0xD0, 0x07, 0xEA, 0xE0, 0x10, 0x7C, 0x01, 0xBF, 0x01, 0x00, 0x5C, 0xF6, 0x3E,
    0x00, 0x40, 0xC0, 0x9F, 0xEF, 0xF5, 0xF3, 0xE3, 0x7E, 0x7F, 0x80, 0x00, 0x00, 0x08, 0xE4, 0x1F,
    0x00, 0x80, 0xC0, 0x1F, 0xDF, 0x17, 0x3F, 0x7E, 0x3F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xE2, 0x1D,
    0x00, 0x00, 0xC1, 0x1F, 0x7F, 0x00, 0x0C, 0xC0, 0x1F, 0xFF, 0x10, 0x00, 0x00, 0x00, 0xE0, 0x1F,
    0x00, 0x00, 0x41, 0xFF, 0x07, 0x20, 0x00, 0x01, 0xFC, 0xBF, 0x20, 0x00, 0x00, 0x00, 0xE0, 0x0F,
    0x00, 0x40, 0x40, 0x00, 0x00, 0x6C, 0x4B, 0x04, 0x00, 0x80, 0x40, 0x00, 0x00, 0x00, 0xE0, 0x07,
    0x00, 0x20, 0x40, 0x00, 0x40, 0x69, 0x1A, 0x24, 0x00, 0x80, 0x80, 0x00, 0x00, 0xFE, 0xF1, 0x03,
    0x00, 0x10, 0x60, 0x00, 0x70, 0x01, 0x00, 0x68, 0x03, 0x80, 0x00, 0x01, 0x00, 0xFF, 0xFF, 0x01,
    0x00, 0x00, 0x60, 0x00, 0x30, 0x00, 0x00, 0x80, 0x03, 0x80, 0x00, 0x00, 0x00, 0xF0, 0x7F, 0x00,
    0x00, 0x00, 0x40, 0x00, 0x00, 0xFE, 0xFF, 0x0F, 0x00, 0x80, 0x00, 0xF8, 0x07, 0xE0, 0x3F, 0x00,
    0x00, 0x00, 0x40, 0x00, 0xE0, 0xFF, 0xE1, 0xFF, 0x00, 0x80, 0x00, 0xC4, 0x08, 0x80, 0x1F, 0x00,
    0x00, 0x00, 0x80, 0x03, 0x1F, 0xFF, 0xFF, 0x1F, 0x1E, 0x70, 0x00, 0xC6, 0x18, 0x80, 0x1F, 0x00,
    0x00, 0x00, 0x00, 0xFC, 0x00, 0xFC, 0xFF, 0x07, 0xE0, 0x0F, 0x00, 0xFF, 0x3B, 0x80, 0x1F, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0x03, 0x00, 0x00, 0x00, 0xE3, 0x31, 0xC0, 0x0F, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xE3, 0x39, 0xC1, 0x07, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x13, 0x1D, 0xE0, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x5F, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xCF, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF3, 0x01, 0x00, 0x00,
};

/* ---------------- Note Muzicale (Frecvente Hz) ---------------- */

#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define REST    0

typedef struct {
    uint16_t frequency;
    uint16_t duration_ms;
} Note;

typedef struct {
    const char* name;
    const Note* notes;
    size_t length;
} Song;

/* --- 1. Imnul Rapidului --- */
static const Note SONG_IMN[] = {
    {NOTE_E4, 250}, {NOTE_G4, 250}, {NOTE_A4, 350}, {NOTE_A4, 200}, {NOTE_G4, 200}, {NOTE_E4, 450},
    {REST, 150},    {NOTE_E4, 250}, {NOTE_A4, 250}, {NOTE_B4, 350}, {NOTE_B4, 200}, {NOTE_A4, 200},
    {NOTE_G4, 450}, {REST, 150},    {NOTE_G4, 250}, {NOTE_C5, 250}, {NOTE_C5, 350}, {NOTE_B4, 200},
    {NOTE_A4, 200}, {NOTE_G4, 400}, {REST, 150},    {NOTE_E4, 250}, {NOTE_G4, 250}, {NOTE_A4, 350},
    {NOTE_G4, 200}, {NOTE_E4, 200}, {NOTE_D4, 550}, {REST, 300},    {NOTE_A4, 300}, {NOTE_C5, 300},
    {NOTE_A4, 500}, {REST, 200},    {NOTE_C5, 220}, {NOTE_D5, 220}, {NOTE_E5, 350}, {NOTE_D5, 220},
    {NOTE_C5, 220}, {NOTE_B4, 550}, {REST, 200},    {NOTE_G4, 300}, {NOTE_B4, 300}, {NOTE_G4, 500},
    {REST, 200},    {NOTE_B4, 220}, {NOTE_C5, 220}, {NOTE_D5, 350}, {NOTE_C5, 220}, {NOTE_B4, 220},
    {NOTE_A4, 700}, {REST, 400},
};

/* --- 2. In 1923 s-a nascut un mit --- */
static const Note SONG_1923[] = {
    {NOTE_A4, 250}, {NOTE_A4, 250}, {NOTE_C5, 250}, {NOTE_A4, 250}, {NOTE_G4, 300}, {REST, 100},
    {NOTE_G4, 250}, {NOTE_A4, 250}, {NOTE_B4, 250}, {NOTE_G4, 250}, {NOTE_E4, 350}, {REST, 150},
    {NOTE_A4, 250}, {NOTE_A4, 250}, {NOTE_C5, 250}, {NOTE_D5, 250}, {NOTE_E5, 450}, {REST, 150},
    {NOTE_D5, 250}, {NOTE_C5, 250}, {NOTE_B4, 250}, {NOTE_C5, 250}, {NOTE_A4, 550}, {REST, 300},
};

/* --- 3. Gandul ce mereu il port --- */
static const Note SONG_GANDUL[] = {
    {NOTE_C5, 200}, {NOTE_C5, 200}, {NOTE_B4, 200}, {NOTE_A4, 200}, {NOTE_G4, 350}, {REST, 100},
    {NOTE_A4, 200}, {NOTE_B4, 200}, {NOTE_C5, 200}, {NOTE_A4, 200}, {NOTE_E4, 350}, {REST, 100},
    {NOTE_G4, 200}, {NOTE_A4, 200}, {NOTE_B4, 200}, {NOTE_C5, 250}, {NOTE_D5, 350}, {REST, 100},
    {NOTE_C5, 200}, {NOTE_B4, 200}, {NOTE_A4, 200}, {NOTE_G4, 200}, {NOTE_A4, 500}, {REST, 300},
};

/* --- 4. Samba din Giulesti --- */
static const Note SONG_SAMBA[] = {
    {NOTE_E5, 180}, {NOTE_E5, 180}, {NOTE_D5, 180}, {NOTE_C5, 180}, {NOTE_B4, 180}, {NOTE_C5, 250},
    {REST, 80},     {NOTE_D5, 180}, {NOTE_D5, 180}, {NOTE_C5, 180}, {NOTE_B4, 180}, {NOTE_A4, 180},
    {NOTE_B4, 250}, {REST, 80},     {NOTE_C5, 180}, {NOTE_C5, 180}, {NOTE_B4, 180}, {NOTE_A4, 180},
    {NOTE_G4, 180}, {NOTE_A4, 250}, {REST, 80},     {NOTE_B4, 180}, {NOTE_C5, 180}, {NOTE_D5, 250},
    {NOTE_E5, 400}, {REST, 300},
};

/* --- 5. C-asa sunt eu rapidist --- */
static const Note SONG_RAPIDIST[] = {
    {NOTE_G4, 200}, {NOTE_C5, 200}, {NOTE_E5, 250}, {NOTE_E5, 200}, {NOTE_D5, 200}, {NOTE_C5, 350},
    {REST, 100},    {NOTE_D5, 200}, {NOTE_D5, 200}, {NOTE_C5, 200}, {NOTE_B4, 200}, {NOTE_C5, 200},
    {NOTE_D5, 350}, {REST, 100},    {NOTE_G4, 200}, {NOTE_C5, 200}, {NOTE_E5, 250}, {NOTE_D5, 200},
    {NOTE_C5, 200}, {NOTE_B4, 350}, {REST, 100},    {NOTE_A4, 200}, {NOTE_B4, 200}, {NOTE_C5, 200},
    {NOTE_D5, 200}, {NOTE_C5, 500}, {REST, 300},
};

/* --- 6. Prima oara pe Giulesti --- */
static const Note SONG_PRIMA_OARA[] = {
    {NOTE_E4, 220}, {NOTE_A4, 220}, {NOTE_C5, 300}, {NOTE_B4, 220}, {NOTE_A4, 220}, {NOTE_G4, 400},
    {REST, 100},    {NOTE_G4, 220}, {NOTE_B4, 220}, {NOTE_D5, 300}, {NOTE_C5, 220}, {NOTE_B4, 220},
    {NOTE_A4, 400}, {REST, 100},    {NOTE_A4, 220}, {NOTE_C5, 220}, {NOTE_E5, 350}, {NOTE_D5, 220},
    {NOTE_C5, 220}, {NOTE_B4, 400}, {REST, 100},    {NOTE_G4, 220}, {NOTE_A4, 220}, {NOTE_B4, 220},
    {NOTE_C5, 220}, {NOTE_A4, 550}, {REST, 300},
};

/* --- 7. Haide Rapidul, Haide Realul --- */
static const Note SONG_REALUL[] = {
    {NOTE_C5, 250},
    {NOTE_C5, 250},
    {NOTE_A4, 250},
    {NOTE_C5, 250},
    {NOTE_D5, 400},
    {REST, 120},
    {NOTE_D5, 250},
    {NOTE_D5, 250},
    {NOTE_B4, 250},
    {NOTE_D5, 250},
    {NOTE_E5, 400},
    {REST, 120},
    {NOTE_E5, 200},
    {NOTE_D5, 200},
    {NOTE_C5, 200},
    {NOTE_B4, 200},
    {NOTE_A4, 550},
    {REST, 300},
};

/* --- 8. Ole, ole, multumim Rapidule --- */
static const Note SONG_MULTUMIM[] = {
    {NOTE_A4, 300},
    {NOTE_C5, 300},
    {NOTE_E5, 450},
    {REST, 150},
    {NOTE_D5, 250},
    {NOTE_C5, 250},
    {NOTE_B4, 250},
    {NOTE_A4, 450},
    {REST, 150},
    {NOTE_G4, 250},
    {NOTE_A4, 250},
    {NOTE_B4, 250},
    {NOTE_C5, 250},
    {NOTE_A4, 600},
    {REST, 350},
};

static const Song SONGS[] = {
    {"1. Imnul Rapidului", SONG_IMN, sizeof(SONG_IMN) / sizeof(SONG_IMN[0])},
    {"2. 1923 s-a nascut un mit", SONG_1923, sizeof(SONG_1923) / sizeof(SONG_1923[0])},
    {"3. Gandul ce mereu il port", SONG_GANDUL, sizeof(SONG_GANDUL) / sizeof(SONG_GANDUL[0])},
    {"4. Samba din Giulesti", SONG_SAMBA, sizeof(SONG_SAMBA) / sizeof(SONG_SAMBA[0])},
    {"5. C-asa sunt eu rapidist", SONG_RAPIDIST, sizeof(SONG_RAPIDIST) / sizeof(SONG_RAPIDIST[0])},
    {"6. Prima oara pe Giulesti",
     SONG_PRIMA_OARA,
     sizeof(SONG_PRIMA_OARA) / sizeof(SONG_PRIMA_OARA[0])},
    {"7. Haide Rapidul Realul", SONG_REALUL, sizeof(SONG_REALUL) / sizeof(SONG_REALUL[0])},
    {"8. Ole, multumim Rapidule", SONG_MULTUMIM, sizeof(SONG_MULTUMIM) / sizeof(SONG_MULTUMIM[0])},
};
#define SONGS_COUNT (sizeof(SONGS) / sizeof(SONGS[0]))

typedef enum {
    ScreenHome,
    ScreenMenuMain,
    ScreenMenuSongs,
    ScreenPlaying,
    ScreenSteaua,
    ScreenDinamo,
    ScreenFCSB,
} AppScreen;

typedef struct {
    FuriMutex* mutex;
    AppScreen screen;
    int menu_main_index;
    int menu_songs_index;
    int selected_song;
    int current_note;
    bool stop_requested;
} AppState;

static const char* main_menu_items[] = {
    "1. Cancete & Scandari",
    "2. Inapoi la Poza",
    "3. Anti Steaua",
    "4. Anti Dinamo",
    "5. Anti FCSB",
    "6. Iesire",
};
#define MAIN_MENU_COUNT (sizeof(main_menu_items) / sizeof(main_menu_items[0]))

/* ---------------- Redare melodie ---------------- */

static int32_t play_melody_thread(void* ctx) {
    AppState* app = ctx;

    if(!furi_hal_speaker_acquire(1000)) {
        return -1;
    }

    furi_mutex_acquire(app->mutex, FuriWaitForever);
    int song_idx = app->selected_song;
    furi_mutex_release(app->mutex);

    if(song_idx < 0 || song_idx >= (int)SONGS_COUNT) {
        furi_hal_speaker_release();
        return 0;
    }

    const Song* song = &SONGS[song_idx];

    for(size_t i = 0; i < song->length; i++) {
        furi_mutex_acquire(app->mutex, FuriWaitForever);
        bool stop = app->stop_requested;
        app->current_note = (int)i;
        furi_mutex_release(app->mutex);

        if(stop) break;

        if(song->notes[i].frequency > 0) {
            furi_hal_speaker_start((float)song->notes[i].frequency, 1.0f);
            furi_delay_ms(song->notes[i].duration_ms);
            furi_hal_speaker_stop();
        } else {
            furi_delay_ms(song->notes[i].duration_ms);
        }
        furi_delay_ms(25);
    }

    furi_hal_speaker_stop();
    furi_hal_speaker_release();

    furi_mutex_acquire(app->mutex, FuriWaitForever);
    app->current_note = -1;
    app->screen = ScreenMenuSongs;
    furi_mutex_release(app->mutex);

    return 0;
}

/* ---------------- Draw callback ---------------- */

static void draw_callback(Canvas* canvas, void* ctx) {
    AppState* app = ctx;
    furi_mutex_acquire(app->mutex, FuriWaitForever);

    canvas_clear(canvas);

    switch(app->screen) {
    case ScreenHome:
        canvas_draw_xbm(canvas, 0, 0, RAPID_LOGO_WIDTH, RAPID_LOGO_HEIGHT, rapid_logo_bits);
        break;

    case ScreenMenuMain: {
        canvas_set_font(canvas, FontPrimary);
        canvas_draw_str(canvas, 2, 10, "FC Rapid Bucuresti");
        canvas_set_font(canvas, FontSecondary);

        size_t start_item = 0;
        if(app->menu_main_index >= 4) {
            start_item = (size_t)(app->menu_main_index - 3);
        }

        for(size_t i = start_item; i < start_item + 4 && i < MAIN_MENU_COUNT; i++) {
            int y_pos = 24 + (int)(i - start_item) * 10;
            if((int)i == app->menu_main_index) {
                canvas_draw_str(canvas, 2, y_pos, ">");
            }
            canvas_draw_str(canvas, 10, y_pos, main_menu_items[i]);
        }
        break;
    }

    case ScreenMenuSongs: {
        canvas_set_font(canvas, FontPrimary);
        canvas_draw_str(canvas, 2, 10, "Alege Melodia:");
        canvas_set_font(canvas, FontSecondary);

        size_t start_item = 0;
        if(app->menu_songs_index >= 4) {
            start_item = (size_t)(app->menu_songs_index - 3);
        }

        for(size_t i = start_item; i < start_item + 4 && i < SONGS_COUNT; i++) {
            int y_pos = 24 + (int)(i - start_item) * 10;
            if((int)i == app->menu_songs_index) {
                canvas_draw_str(canvas, 2, y_pos, ">");
            }
            canvas_draw_str(canvas, 10, y_pos, SONGS[i].name);
        }
        break;
    }

    case ScreenPlaying: {
        canvas_set_font(canvas, FontPrimary);
        if(app->selected_song >= 0 && app->selected_song < (int)SONGS_COUNT) {
            canvas_draw_str(canvas, 2, 12, SONGS[app->selected_song].name);
        } else {
            canvas_draw_str(canvas, 2, 12, "Se canta...");
        }
        canvas_set_font(canvas, FontSecondary);
        char buf[32];
        int total_notes = (app->selected_song >= 0 && app->selected_song < (int)SONGS_COUNT) ?
                              (int)SONGS[app->selected_song].length :
                              0;
        snprintf(buf, sizeof(buf), "Nota: %d / %d", app->current_note + 1, total_notes);
        canvas_draw_str(canvas, 2, 32, buf);
        canvas_draw_str(canvas, 2, 52, "Apasa Back = Stop");
        break;
    }

    case ScreenSteaua:
        canvas_set_font(canvas, FontPrimary);
        canvas_draw_str(canvas, 2, 10, "MUIE STEAUA HEY HEY!");
        canvas_set_font(canvas, FontSecondary);
        canvas_draw_str(canvas, 2, 23, "In padurea cu alune");
        canvas_draw_str(canvas, 2, 33, "Aveau casa doi pitici");
        canvas_draw_str(canvas, 2, 43, "Vine pupaza si spune:");
        canvas_draw_str(canvas, 2, 53, "MUIE STEAUA MUIE STEAUA");
        break;

    case ScreenDinamo:
        canvas_set_font(canvas, FontPrimary);
        canvas_draw_str(canvas, 2, 10, "Caini spurcati...");
        canvas_set_font(canvas, FontSecondary);
        canvas_draw_str(canvas, 2, 23, "de pula sa ne luati!");
        canvas_draw_str(canvas, 2, 38, "Ce rusine sa fii caine,");
        canvas_draw_str(canvas, 2, 50, "sa se pise toti pe tine!");
        break;

    case ScreenFCSB:
        canvas_set_font(canvas, FontPrimary);
        canvas_draw_str(canvas, 2, 12, "FCSB NU E STEAUA!");
        canvas_set_font(canvas, FontSecondary);
        canvas_draw_str(canvas, 2, 30, "CSA FCSB");
        canvas_draw_str(canvas, 2, 44, "ACEEASI MIZERIE!");
        canvas_draw_str(canvas, 2, 58, "Back = Inapoi");
        break;
    }

    furi_mutex_release(app->mutex);
}

/* ---------------- Input callback ---------------- */

static void input_callback(InputEvent* input_event, void* ctx) {
    FuriMessageQueue* queue = ctx;
    furi_message_queue_put(queue, input_event, FuriWaitForever);
}

/* ---------------- Main ---------------- */

int32_t rapid_flipper_app(void* p) {
    UNUSED(p);

    AppState* app = malloc(sizeof(AppState));
    app->mutex = furi_mutex_alloc(FuriMutexTypeNormal);
    app->screen = ScreenHome;
    app->menu_main_index = 0;
    app->menu_songs_index = 0;
    app->selected_song = -1;
    app->current_note = -1;
    app->stop_requested = false;

    FuriMessageQueue* event_queue = furi_message_queue_alloc(8, sizeof(InputEvent));

    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, draw_callback, app);
    view_port_input_callback_set(view_port, input_callback, event_queue);

    Gui* gui = furi_record_open(RECORD_GUI);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    FuriThread* music_thread = NULL;

    InputEvent event;
    bool running = true;

    while(running) {
        FuriStatus status = furi_message_queue_get(event_queue, &event, 100);

        if(status == FuriStatusOk &&
           (event.type == InputTypePress || event.type == InputTypeRepeat)) {
            furi_mutex_acquire(app->mutex, FuriWaitForever);

            if(app->screen == ScreenHome) {
                if(event.key == InputKeyOk) {
                    app->screen = ScreenMenuMain;
                } else if(event.key == InputKeyBack) {
                    running = false;
                }
            } else if(app->screen == ScreenMenuMain) {
                if(event.key == InputKeyBack) {
                    app->screen = ScreenHome;
                } else if(event.key == InputKeyUp) {
                    app->menu_main_index =
                        (app->menu_main_index - 1 + MAIN_MENU_COUNT) % MAIN_MENU_COUNT;
                } else if(event.key == InputKeyDown) {
                    app->menu_main_index = (app->menu_main_index + 1) % MAIN_MENU_COUNT;
                } else if(event.key == InputKeyOk) {
                    if(app->menu_main_index == 0) { // Sub-Meniu Cantece
                        app->screen = ScreenMenuSongs;
                    } else if(app->menu_main_index == 1) { // Inapoi la Poza
                        app->screen = ScreenHome;
                    } else if(app->menu_main_index == 2) { // Anti Steaua
                        app->screen = ScreenSteaua;
                    } else if(app->menu_main_index == 3) { // Anti Dinamo
                        app->screen = ScreenDinamo;
                    } else if(app->menu_main_index == 4) { // Anti FCSB
                        app->screen = ScreenFCSB;
                    } else if(app->menu_main_index == 5) { // Iesire
                        running = false;
                    }
                }
            } else if(app->screen == ScreenMenuSongs) {
                if(event.key == InputKeyBack) {
                    app->screen = ScreenMenuMain;
                } else if(event.key == InputKeyUp) {
                    app->menu_songs_index =
                        (app->menu_songs_index - 1 + SONGS_COUNT) % SONGS_COUNT;
                } else if(event.key == InputKeyDown) {
                    app->menu_songs_index = (app->menu_songs_index + 1) % SONGS_COUNT;
                } else if(event.key == InputKeyOk) {
                    app->selected_song = app->menu_songs_index;
                    app->screen = ScreenPlaying;
                    app->stop_requested = false;
                    app->current_note = 0;
                    if(music_thread) {
                        furi_thread_join(music_thread);
                        furi_thread_free(music_thread);
                    }
                    music_thread = furi_thread_alloc();
                    furi_thread_set_name(music_thread, "RapidMelody");
                    furi_thread_set_stack_size(music_thread, 1024);
                    furi_thread_set_context(music_thread, app);
                    furi_thread_set_callback(music_thread, play_melody_thread);
                    furi_thread_start(music_thread);
                }
            } else if(app->screen == ScreenPlaying) {
                if(event.key == InputKeyBack) {
                    app->stop_requested = true;
                }
            } else { // Ecranele de text (Steaua, Dinamo, FCSB)
                if(event.key == InputKeyBack || event.key == InputKeyOk) {
                    app->screen = ScreenMenuMain;
                }
            }

            furi_mutex_release(app->mutex);
        }

        view_port_update(view_port);
    }

    if(music_thread) {
        furi_mutex_acquire(app->mutex, FuriWaitForever);
        app->stop_requested = true;
        furi_mutex_release(app->mutex);
        furi_thread_join(music_thread);
        furi_thread_free(music_thread);
    }

    gui_remove_view_port(gui, view_port);
    furi_record_close(RECORD_GUI);
    view_port_free(view_port);
    furi_message_queue_free(event_queue);
    furi_mutex_free(app->mutex);
    free(app);

    return 0;
}
