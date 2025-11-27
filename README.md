# Cat-AI-ESP32-S3
 "Con mèo AI trên ESP32-S3 với XiaoZhi, màn OLED, mic I2S, điều khiển giọng nói".
# Con Mèo AI ESP32-S3
Dự án con mèo ảo với actions đầy đủ, dựa trên XiaoZhi ESP32. Hỗ trợ màn 0.96" SPI, INMP441, MAX98357.

## Hardware Pins
- OLED: SCK=12, MOSI=11, CS=10, DC=14, RES=13
- I2S: BCLK=4, WS=5, Mic=6, Amp=7

## Build
idf.py build flash monitor
