# Remote-Controlled IoT Robot

Acest proiect constă într-un robot controlat de la distanță, construit cu ajutorul platformelor **ESP32** și **Arduino**, comunicând între ele prin UART. Scopul proiectului este de a demonstra controlul wireless asupra unui robot autonom, cu posibilitatea de extindere pentru aplicații IoT.

## Arhitectură

- **ESP32**: controler principal, primește comenzi de la utilizator (Bluetooth, Serial, etc.) și le transmite mai departe.
- **Arduino**: execută comenzile primite de la ESP32 și controlează:
  - Motoare (prin driver L298N)
  - Senzori (ultrasunete, IR)
- **Comunicare**: UART între ESP32 și Arduino

## Structura fișierelor

| Fișier                | Descriere                                               |
|------------------------|----------------------------------------------------------|
| `control.ino`          | Codul pentru ESP32 – citește comenzi și le trimite prin UART |
| `RobotArduino.ino`     | Codul pentru Arduino – interpretează comenzile și controlează robotul |
| `README.md`            | Acest fișier                                            |

## Conectivitate hardware

- ESP32 `TX` → Arduino `RX`  
- ESP32 `RX` ← Arduino `TX`  
- GND comun  
- Motoare conectate la L298N  
- Senzori conectați la pinii digitali ai Arduino-ului

## Cum rulezi proiectul

1. Încarcă `RobotArduino.ino` pe Arduino (Uno/Nano)
2. Încarcă `control.ino` pe ESP32
3. Deschide Serial Monitor (sau aplicația mobilă Bluetooth)
4. Trimite comenzi (`F`, `B`, `L`, `R`, `S`) pentru control

## Comenzi disponibile

| Comandă | Acțiune        |
|--------|----------------|
| `F`    | Mers înainte   |
| `B`    | Mers înapoi    |
| `L`    | Viraj stânga   |
| `R`    | Viraj dreapta  |
| `S`    | Stop           |

## Capturi (opțional)

> Aici poți adăuga imagini cu robotul fizic, schema de conectare sau videoclipuri.

## Licență

Proiect open-source sub licență MIT. Poți modifica, distribui și folosi liber cu menționarea autorului.

## Autor

- Gabriela CND  
- GitHub: [@Gabrielacnd](https://github.com/Gabrielacnd)
