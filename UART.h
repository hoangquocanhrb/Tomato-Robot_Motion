#ifndef UART_H
#define UART_H

class UARTCom
{
private:
  short PWM;
  short MId;
  short MDir;
  short Leg;
public:
  UARTCom();
  void uSend(short do_rong_xung, short chan_xung, short _mId, short _mDir);
  short getPWM();
  short getLeg();
  short getMId();
  ~UARTCom();
};
#endif 
