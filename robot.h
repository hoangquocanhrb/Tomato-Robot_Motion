#ifndef ROBOT_H
#define ROBOT_H

#include"motor.h"
#include"UART.h"

class TomatoCar: public Motor, public UARTCom
{
private:
  short tang_toc ;
  short giam_toc ;
 
public:
  UARTCom uartcom1;
  UARTCom uartcom2;
  Motor m1;
  Motor m2;
  TomatoCar();
  void configCar(short _mId1, short maxSpeed1, short _chan_xung1, short _mId2, short maxSpeed2, short _chan_xung2, short _tang_toc, short _giam_toc);
  void ForWard();
  void GiamToc();
  void BackWard();
  void Stop();
  void Turn_right();
  void Turn_left();
  void Move();
  ~TomatoCar(){};
};
#endif 
