# Adquisición ECG con AD8232 — Grupo 11

Proyecto de integración del curso **Electrónica para Ingeniería Biomédica**.
Sistema de adquisición de ECG de una derivación basado en el módulo **AD8232** y un **Arduino UNO**, con una PCB de integración diseñada en **KiCad** y fabricable en la ruteadora CNC del laboratorio.

## Integrantes
- Juan Pablo Monsalve — [j.monsalvebudd.cl]
- Benjamin Ulloa — [b.ulloapudd.cl]

Curso y sección: Electronica Biomedica · Grupo: 11

## Descripción
El módulo AD8232 amplifica y filtra la señal biopotencial captada por tres electrodos (RA, LA, RL). Su salida analógica se digitaliza en el ADC de 10 bits del Arduino UNO y se envía por puerto serie al computador para visualizarla (Serial Plotter). Los pines LO+ y LO- indican si algún electrodo está desconectado.

## Conexiones
| AD8232 | Arduino UNO |
|---|---|
| 3.3V | 3.3V |
| GND | GND |
| OUTPUT | A0 |
| LO+ | D10 |
| LO- | D11 |

## Estructura del repositorio
```
ecg-ad8232-grupo11/
|-- README.md
|-- LICENSE
|-- docs/
|   |-- datasheets/     hojas de datos (AD8232, Arduino UNO)
|   |-- bitacora.md     registro del trabajo del equipo
|   `-- informes/       informes en PDF de cada parte
|-- electronica/
|   |-- kicad/          proyecto de KiCad (.kicad_sch, .kicad_pcb, .kicad_pro)
|   |-- libraries/      símbolos, footprints y modelos 3D propios
|   `-- outputs/        Gerber, drill, BOM, STEP, PDF e imágenes
|-- firmware/
|   `-- ecg_ad8232/     sketch de Arduino
`-- software/           visualización y procesamiento en el computador
```

## Uso del firmware
1. Abrir `firmware/ecg_ad8232/ecg_ad8232.ino` en el IDE de Arduino y cargarlo en el Arduino UNO.
2. Abrir el **Serial Plotter** a **115200 baudios**.
3. Colocar los electrodos: rojo (RA) brazo derecho, amarillo (LA) brazo izquierdo, verde (RL) pierna derecha.

Un valor `!` en la salida indica electrodo desconectado.

## Seguridad
Este es un prototipo educativo y **no es un dispositivo médico**. Al probarlo con electrodos puestos en una persona, usar un computador alimentado por batería (sin cargador conectado) o una batería externa.

## Estado
- [x] Parte I: definición del problema y requerimientos
- [ ] Parte II: esquemático, layout y archivos de fabricación

## Referencias
- Tutorial de referencia: https://how2electronics.com/ecg-monitoring-with-ad8232-ecg-sensor-arduino/
- Hoja de datos del AD8232 (Analog Devices): agregar en `docs/datasheets/`

## Licencia
MIT (ver archivo `LICENSE`).
