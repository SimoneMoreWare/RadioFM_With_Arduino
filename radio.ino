//-------------------------
//TEA5767 FM Radio Receiver
//-------------------------
#include <Wire.h>
#include <TEA5767N.h>
#include <LiquidCrystal.h>
//-------------------------------------------
TEA5767N radio = TEA5767N();
LiquidCrystal lcd(3, 4, 5, 6, 7, 8);
//-------------------------------------------
float station[] = {101.3,107.9,91.1,104.5};
int i=0, numStations = *(&station+1)-station;
boolean powerOnOff = false, muteAudio = false;
//===============================================================
void setup()
{ 
  pinMode(9,INPUT); pinMode(13,INPUT);
  radio.setStereoNoiseCancellingOn();
  lcd.begin(16, 2);
  lcd.clear();
  attachInterrupt(0, ISR_powerOnOff, RISING);
}
//===============================================================
void loop()
{ 
  if(powerOnOff == false)
  {
    lcd.setCursor(0, 0);
    lcd.print("TEA5767 FM Radio");
    lcd.setCursor(0, 1);
    lcd.print("Power OFF");
    radio.setStandByOn();
  }
  if(powerOnOff == true)
  {
    lcd.setCursor(0, 0);
    lcd.print("Power ON");
    lcd.setCursor(0, 1);
    lcd.print("Select Station");
    radio.setStandByOff();
    radio.mute();
  }
  //-------------------------------------------
  while(powerOnOff)
  {
    if(digitalRead(9) == HIGH) changeStation();
    if(digitalRead(13) == HIGH) muteStatus();
  }
}
//===============================================================
void changeStation()
{
  radio.turnTheSoundBackOn();
  radio.selectFrequency(station[i]);
  lcd.clear();
  delay(200);
  if(radio.isStereo()==1) lcd.print("FM Stereo");
  if(radio.isStereo()==0) lcd.print("FM Mono");
  lcd.setCursor(0, 1);
  lcd.print(radio.readFrequencyInMHz());
  lcd.setCursor(6, 1); lcd.print("MHz");
  lcd.setCursor(10,1);
  lcd.print("SL:"); lcd.print(radio.getSignalLevel()*100/15);
  lcd.setCursor(15,1); lcd.print("%");
  i++;
  if(i == numStations) i = 0;
}
//===============================================================
void ISR_powerOnOff()
{
  powerOnOff = !powerOnOff;
  lcd.clear();
}
//===============================================================
void muteStatus()
{
  delay(200);
  muteAudio = !muteAudio;
  if(muteAudio == true) radio.mute();
  else radio.turnTheSoundBackOn();
}
