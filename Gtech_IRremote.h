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
#ifndef GTech_IRremote_h
#define GTech_IRremote_h

#include "Arduino.h"
#include "IRremote_Button.h"

class Gtech_IRremote
{
  public:
    Gtech_IRremote();
	bool setup();
	bool setup(int);
	byte getIR();
	
  private:
	unsigned long pulses[128];
	unsigned char IRCOM[7];
	unsigned long z;
    int Coder();
	int w,n;
	int IR_LED;
	
};

#endif
