### Revision 1.0

The first PCB revision - has 2024-09-03 on the back of the board. Was received on 2024-09-16 and tested. As it was the first iteration of the board, I was prepared for magic smoke, but it worked remarkably well - it could be powered from USB and programmed using standard tooling. Serial debugging worked, although it did require some extra configuration. In particular, see the `src/spanet-pcb-blink` directory for the code, but most importantly the platformio.ini file needs the following to work:

```ini
[env:spa-control-pcb]
platform = espressif32
board = esp32-s3-devkitc-1
framework = arduino
monitor_speed = 115200
build_flags = 
  -D ARDUINO_USB_MODE=0
  -D ARDUINO_USB_CDC_ON_BOOT=1
```

There was one mistake in this board though - the RJ-45 pins were numbered incorrectly, so pin 1 was actually pin 8, and so on. Despite this, with a cross-over cable this should still work correctly:

| Expected Pin | Function | Actual Pin | Function |
|--------------|----------|------------|----------|
| 5            | RX       | 4          | RX       |
| 6            | TX       | 3          | TX       |
| 7            | GND      | 2          | GND      |
| 8            | +12V     | 1          | +12V     |

### Revision 1.1

This revision was never sent to the manufacturer, as I was still waiting on the Revision 1.0 boards to arrive. Despite this, in this revision I made the board smaller, and move more of the signals onto layer one, to ensure layer two was as complete of a ground plane as possible.

### Revision 1.2

This board was worked on following receipt of the rev 1.0 boards, and so it fixes up the RJ-45 pin numbering issue. Never sent for manufacturing.

### Revision 1.3

Replaces the RJ-45 port with a metal-cased shielded RJ-45 port. This is a much more robust port, and should be more reliable in the long term. It is also cheaper (at least in the quantities I am buying) than the previous RJ-45 port. Never sent for manufacturing.

### Revision 1.4

Changes the board layout to have the RJ-45 port on the bottom of the board, and the USB-C port on the right. Better layout in terms of cable management when put inside a case. Never sent for manufacturing.

### Revision 1.5

Minor layout tweaks, never sent for manufacturing.

### Revision 1.6

Switched to a different power supply that is more efficient with the 12v input. This revision was sent for manufacturing.

### Revision 1.7

Improved placement of ESP32 decoupling capacitors to be before the ESP32, and introduced four status LEDs.

### Revision 1.8

Thicker traces all over PCB.

### Revision 1.9

Replaced some components with smaller alternatives, and improved the layout of the board to make it easier to manufacture. Kept same board size as previous revisions.

### Revision 2.0 - eSpa Max

Introduced a new board variant - the eSpa Max. It is bigger than the eSpa Mini, but it has three M3 mounting holes and two RJ-45 connectors to support 'loop' mode. It also has support for a CT clamp to measure the power usage of the spa pool.