#include"UART.h"
#include<ArduinoHardware.h>

UARTCom::UARTCom(){};

//Hàm gửi byte đến driver
void UARTCom::uSend(short do_rong_xung, short chan_xung ,short _mId, short _mDir)
{
  this->MId = _mId;
  this->MDir = _mDir;
  this->Leg = chan_xung;
  if(do_rong_xung <= 0)
  {
    this->PWM = 0;
  }
  else if(do_rong_xung >= 255)
  {
    this->PWM = 255;
  }
  else this->PWM = do_rong_xung;

  analogWrite(this->Leg, this->PWM);
  digitalWrite(this->MId, this->MDir);
}
short UARTCom::getPWM()
{
  return this->PWM;
}
short UARTCom::getLeg()
{
  return this->Leg;
}
short UARTCom::getMId()
{
  return this->MId;
}
UARTCom::~UARTCom(){};
