#include <LoRaE5.h>
unsigned char buffer[128] = {0xef, 0xff, 0x55, 3, 4, 5, 6, 7, 8, 9,};

//#define GROVE_TX 21
//#define GROVE_RX 20

void setup(void)
{
    SerialUSB.begin(115200);
    //lora.init(GROVE_RX, GROVE_TX);
    lora.init();
    lora.initP2PMode(866, SF12, BW125, 12, 15, 14);
}

void loop(void)
{
    lora.transferPacketP2PMode("Hello World!");
    SerialUSB.println("Send string.");
    delay(3000);
    lora.transferPacketP2PMode(buffer, 10);
    SerialUSB.println("Send hex.");
    delay(3000);
}
