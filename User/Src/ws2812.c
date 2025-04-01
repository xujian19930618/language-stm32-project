//
// Created by 徐剑 on 25-4-1.
//

#include "ws2812.h"
#include "ws2812.h"
#define Led_Pin P14

void WS2812_SendData(unsigned char R,unsigned char G,unsigned char B)
{
    unsigned char i,j,temp[3];
    temp[0]=G;
    temp[1]=R;
    temp[2]=B;
    for(j=0;j<3;j++)
    {
        for(i=0;i<8;i++)
        {
            if(temp[j] & (0x80>>i)) //发送1
            {
                Led_Pin=1;
                _nop_();_nop_();_nop_();_nop_();_nop_();//_nop_();    delay 41ns
                _nop_();_nop_();_nop_();_nop_();_nop_();
                _nop_();_nop_();_nop_();_nop_();_nop_();
                _nop_();_nop_();_nop_();_nop_();_nop_();
                Led_Pin=0;
                _nop_();_nop_();_nop_();_nop_();_nop_();
                _nop_();_nop_();
            }
            else                //发送0
            {
                Led_Pin=1;
                _nop_();_nop_();_nop_();_nop_();_nop_();
                _nop_();_nop_();
                Led_Pin=0;
                _nop_();_nop_();_nop_();_nop_();_nop_();
                _nop_();_nop_();_nop_();_nop_();_nop_();
                _nop_();_nop_();_nop_();_nop_();_nop_();
                _nop_();_nop_();_nop_();_nop_();_nop_();
            }
        }
    }
}
void delay_ms(unsigned int ms)		//@24.000MHz
{
    unsigned char i, j;
    while(ms--)
    {
        i = 24;
        j = 85;
        do
        {
            while (--j);
        } while (--i);
    }

}
