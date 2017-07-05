/***********************************************************************
01-07-2014
GRAVITECH THAI (THAILAND) CO.,LTD
27/14 Soi Sri Bamphen, Rama4 Rd. Tungmahamek, Sathon, Bangkok, 10120
by Sunon Aengchuen
Version: 1.0.0

This library create in specifically for
IR Remote Control 0038B Module DIY Kit from gravitechthai & gravitech
http://www.gravitech.us/
http://gravitechthai.com/
in Gravitechthai, please support us by purchase our products.

All code below is Protected by Lunchware license.
(these are all FREE but you give me a delicious Lunch when we met)

All text above must be included in any adept, copy or cut for some reason
we appreciate that you use both of our software and hardware.
thank you (three times)

This library is base on IR Transmission and Receiving Demo Code by geeetech 
http://www.geeetech.com/ir-remote-control-0038b-module-diy-kit-p-252.html

๐๑-๐๗-๒๕๕๗
บริษัท กราวิเทคไทย (ไทยแลนด์) จำกัด
เลขที่ ๒๗/๑๔ ซ.ศรีบำเพ็ญ ถ.พระราม ๔ แขวงทุ่งมหาเมฆ สาทร กรุงเทพ ๑๐๑๒๐
โดย สุนนท์ เอ่งฉ้วน
เวอร์ชั่น: ๑.๐.๐

นี้คือ library รังสรรค์อย่างมีศิลปะเพื่อใช้งานร่วมกับ
IR Remote Control 0038B Module DIY Kit จาก กราวิเทคไทย และ กราวิเทค
http://www.gravitech.us/
http://gravitechthai.com/
ใน บริษัทกราวิเทคไทย พวกเราคาดหวังเป็นอย่างยิ่งว่าเหล่าท่านทั้งหลายจะสนับสนุนเราโดยการเหมาสินค้าจากทางเรา

โค๊ด ด้านล่างนี้ทั้งหมดอยู่ภายใต้ใบอณุญาต Lunchware
(โค๊ดเหล่านี้ ฟรี หากแต่ท่านทั้งหลายควรให้มื้อเที่ยงสุดแสนอร่อยแก่ข้าพเจ้า เมื่อท่านทั้งหลายได้ประสบพบกับข้าพเจ้าแล้ว)

คำพูดทั้งหลายด้านบนนี้ จะต้องถูกคัดลอก และรวมอยู่ใน ทุกๆการ ดัดแปลง ทำซ้ำ หรือ ตัดไปทำบางอย่าง
ข้าพเจ้าทั้งหลายใคร่ขอขอบพระคุณเหล่าท่านๆ ที่ใช้ ซอฟต์แวร์และฮาร์ดแวร์ของเรา
ขอขอบคุณ (สามครั้ง)

library นี้ ดัดแปลงมาจากโค้ดตัวอย่าง IR Transmission and Receiving ของ geeetech
http://www.geeetech.com/ir-remote-control-0038b-module-diy-kit-p-252.html

***********************************************************************/
#include "Gtech_IRremote.h"


#define MAX 128
#define MICRO_STEP 10
#define IDLE_PULSE 4000


Gtech_IRremote::Gtech_IRremote()
{ 

}

bool Gtech_IRremote::setup()
{
	IR_LED=2;
	pinMode(2,INPUT);
}

bool Gtech_IRremote::setup(int d_pin)
{
	IR_LED=d_pin;
	pinMode(d_pin,INPUT);
}

int Gtech_IRremote::Coder()
{
	n=0;
	byte f = B00000000;
	if(digitalRead(IR_LED)==LOW)
	{
		int count = 0;
		int exit = 0;
		while(!exit)
		{
			while(digitalRead(IR_LED)==LOW)
			delayMicroseconds(MICRO_STEP);
			unsigned long start = micros();
			int max_high = 0;
			while(digitalRead(IR_LED)==HIGH)
			{
				delayMicroseconds(MICRO_STEP);
				max_high += MICRO_STEP;
				if(max_high > IDLE_PULSE)
				{
					exit = 1;
					break;
				}
			}
			unsigned long duration = micros()-start;
			pulses[count++]=duration;
		}
		for(int i=3;i<4;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(pulses[i*8+j+1]>IDLE_PULSE)
				{
					IRCOM[i]=IRCOM[i]>>1;
					if((pulses[i*8+j+1])>1000 )
					{
						IRCOM[i]=IRCOM[i]|0x80;
					}
				}
				z=pulses[i*8+j+1];
				if(z<800)
					w=10000000;
				else
					w=00000000;
				f=f>>1;
				f=f+w;
			}
		}
		n=int(f);
		return n;
	}
}

byte Gtech_IRremote::getIR()
{
	switch(Coder())
	{
		case 69	: return(IRremote_Button_CH_N);
		case 70	: return(IRremote_Button_CH);
		case 71	: return(IRremote_Button_CH_P);
		case 68	: return(IRremote_Button_PREV);
		case 64	: return(IRremote_Button_NEXT);
		case 67	: return(IRremote_Button_PLAY_PAUSE);
		case 7	: return(IRremote_Button_N);
		case 21	: return(IRremote_Button_P);
		case 9	: return(IRremote_Button_EQ);
		case 22	: return(IRremote_Button_0);
		case 25	: return(IRremote_Button_100_P);
		case 13	: return(IRremote_Button_200_P);
		case 12	: return(IRremote_Button_1);
		case 24	: return(IRremote_Button_2);
		case 94	: return(IRremote_Button_3);
		case 8	: return(IRremote_Button_4);
		case 28	: return(IRremote_Button_5);
		case 90	: return(IRremote_Button_6);
		case 66	: return(IRremote_Button_7);
		case 82	: return(IRremote_Button_8);
		case 74	: return(IRremote_Button_9);
		default : return(0);
	}
}

