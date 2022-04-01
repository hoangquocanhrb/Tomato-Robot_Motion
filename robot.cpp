
#include"robot.h"

using namespace std;

TomatoCar::TomatoCar()
{
  m1 = Motor(1, 7, 50, 3);
  m2 = Motor(1, 12, 50, 5);
  this->tang_toc = 20;
  this->giam_toc = 20;
}

//Cấu hình xe với các chỉ số của động cơ
void TomatoCar::configCar( short _mId1, short maxSpeed1, short _chan_xung1, short _mId2, short maxSpeed2, short _chan_xung2, short _tang_toc, short _giam_toc)
{
  m1 = Motor(0, _mId1, maxSpeed1, _chan_xung1);
  m2 = Motor(0, _mId2, maxSpeed2, _chan_xung2);
  this->tang_toc = _tang_toc;
  this->giam_toc = _giam_toc;
}


void TomatoCar::ForWard()
{
//  if(m1.getMSpeed() < 255  && m1.getMDir() == 0)
//  {
//    //TomatoCar::GiamToc();
//    m1.setMSpeed(m1.getMSpeed() + this->giam_toc);
//    m2.setMSpeed(m2.getMSpeed() + this->giam_toc);
//  }
//  else{
//  m1.rotate(1, m1.getMSpeed() - this->tang_toc);
//  m2.rotate(0, m2.getMSpeed() - this->tang_toc);
//  }
m1.setMSpeed(230);
m2.setMSpeed(230);
m1.setMDir(1);
m2.setMDir(0);
}

void TomatoCar::GiamToc()
{
  m1.setMSpeed(m1.getMSpeed() + this->giam_toc);
  m2.setMSpeed(m2.getMSpeed() + this->giam_toc);
}

void TomatoCar::BackWard()
{
  if(m1.getMSpeed() < 255  && m1.getMDir() == 1)
  {
    //TomatoCar::GiamToc();
   m1.setMSpeed(m1.getMSpeed() + this->giam_toc);
   m2.setMSpeed(m2.getMSpeed() + this->giam_toc);
  }
  else
  {
  m1.rotate(0, m1.getMSpeed() - this->tang_toc);
  m2.rotate(1, m2.getMSpeed() - this->tang_toc);
  }
}

void TomatoCar::Stop()
{
  m1.setMSpeed(255);
  m2.setMSpeed(255);
  
  //uartcom.uSend(m1.getMSpeed(), m1.getLeg(), m1.getId(), 0);
  //uartcom.uSend(m2.getMDir(), m2.getId(), 0);
}

void TomatoCar::Turn_right()
{
 m1.setMSpeed(210);
 m2.setMSpeed(210);
 m1.setMDir(0);
  m2.setMDir(0);  
}

void TomatoCar::Turn_left()
{
  m1.setMSpeed(230);
  m2.setMSpeed(230);
  m1.setMDir(1);
  m2.setMDir(1);
}

void TomatoCar::Move()
{
  //uartcom.uSend(m1.getMDir(), m1.getId(), m1.getMSpeed());
  //uartcom.uSend(m2.getMDir(), m2.getId(), m2.getMSpeed());
  uartcom1.uSend(m1.getMSpeed(), m1.getLeg(), m1.getId(), m1.getMDir());
  uartcom2.uSend(m2.getMSpeed(), m2.getLeg(), m2.getId(), m2.getMDir());
}

TomatoCar::~TomatoCar();
