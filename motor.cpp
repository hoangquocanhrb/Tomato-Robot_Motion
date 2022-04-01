#include"motor.h"
using namespace std;

Motor::Motor(){};

//Hàm khởi tạo giá trị ban đầu cho động cơ
Motor::Motor(short _mDir, short _mId ,short _maxSpeed, short _chan_xung)
{
  this->mDir = _mDir;
  this->mId = _mId;
  this->mSpeed = 255;
  this->maxSpeed = _maxSpeed;
  this->chan_xung = _chan_xung;
}

//Thiết lập hướng quay của động cơ
void Motor::setMDir(short _mDir)
{
  if(_mDir == 1)
  {
    this->mDir = 1;
  }
  else this->mDir = 0;
}

short Motor::getMDir()
{
  return this->mDir;
}

//Thiết lập id của động cơ
void Motor::setId(short _mId)
{
  this->mId = _mId;
}

short Motor::getId()
{
  return this->mId;
}

//Thiết lập tốc độ quay của động cơ
void Motor::setMSpeed(short _mSpeed)
{
  if(_mSpeed >= 255)
  {
    this->mSpeed = 255;
  }
  else if(_mSpeed < this->maxSpeed)
  {
    this->mSpeed = this->maxSpeed;
  }
  else this->mSpeed = _mSpeed;
}

short Motor::getMSpeed()
{
  return this->mSpeed;
}

//Thiết lập tốc độ tối đa
void Motor::setMaxSpeed(short _maxSpeed)
{
  if(_maxSpeed >= 255)
  {
    this->maxSpeed = 255;
  }
  else if(_maxSpeed <= 0)
  {
    this->maxSpeed = 0;
  }
  else this->maxSpeed = _maxSpeed;
}

short Motor::getMaxSpeed()
{
  return this->maxSpeed;
}
void Motor::setLeg(short _chan_xung)
{
  this->chan_xung = _chan_xung;
}
short Motor::getLeg()
{
  return this->chan_xung;
}
void Motor::rotate(short _mDir, short _mSpeed)
{
  Motor::setMSpeed(_mSpeed);
  Motor::setMDir(_mDir);
}
Motor::~Motor(){};
