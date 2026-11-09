REVERSE ENGINEERING GOOGLE PAY POD2

EXACT MODEL: EC600NCNAC-N05-UNNSA
CHIP --> (QUECTEL EC600N-CN)[https://developer.quectel.com/modules-cat/ec600n-series] 

SPECFICATIONS:

- 4G MODULE (LTE), CAT 1 module
- NETWORK SPEED - DOWN: 10 Mbps, UP: 5 Mbps
- OTA: DFOTA remote

DEVELOPMENT TOOLS: (https://developer.quectel.com/resource-download?pid=133&cid=6)[https://developer.quectel.com/resource-download?pid=133&cid=6]


DEVICE ACTIVATE SERIAL CONN: PWR + VOL(+) | PWR + VOL(-) --> EXPOSES: /dev/cu.usbmodem00006




MACOS
---

list open serial ports: ```ls -l /dev/cu.* ```
