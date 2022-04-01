#ifndef MOTOR_H
#define MOTOR_H

class Motor{
private:
  short mId;
  short mSpeed;
  short maxSpeed;
  short mDir;
  short chan_xung;
public:
  Motor();
  Motor(short _mDir, short _mId ,short _maxSpeed, short _chan_xung);
  void setMDir(short _mDir);
  short getMDir();
  void setId(short _mId);
  short getId();
  void setMSpeed(short _mSpeed);
  short getMSpeed();
  void setMaxSpeed(short _maxSpeed);
  short getMaxSpeed();
  void setLeg(short _chan_xung);
  short getLeg();
  void rotate(short _mDir, short _mSpeed);
  ~Motor();
};

#endif
