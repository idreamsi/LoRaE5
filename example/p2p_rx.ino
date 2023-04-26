#include <LoRaE5.h>
unsigned char buffer[128] = {0, };

#define GROVE_TX 21
#define GROVE_RX 20

void setup(void)
{
    SerialUSB.begin(115200);
    //lora.init(GROVE_RX, GROVE_TX);
    lora.init();
    lora.initP2PMode(866, SF12, BW125, 12, 15, 14);
}

void loop(void)
{
    short length = 0;
    short rssi = 0;
    
    memset(buffer, 0, 128);
    length = lora.receivePacketP2PMode(buffer, 128,  &rssi, 1);
    
    if(length)
    {
        SerialUSB.print("Length is: ");
        SerialUSB.println(length);
        SerialUSB.print("RSSI is: ");
        SerialUSB.println(rssi);
        SerialUSB.print("Data is: ");
        for(unsigned char i = 0; i < length; i ++)
        {
            SerialUSB.print("0x");
            SerialUSB.print(buffer[i], HEX);
            SerialUSB.print(" ");
        }
        SerialUSB.println();
    }
}
