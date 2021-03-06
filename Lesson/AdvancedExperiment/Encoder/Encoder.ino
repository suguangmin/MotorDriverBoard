#include "Emakefun_MotorDriver.h"
//#include "PinChangeInt.h"

static volatile int Encoder1Pulse = 0, Encoder2Pulse = 0;

Emakefun_MotorDriver mMotorDriver = Emakefun_MotorDriver(0x60, MOTOR_DRIVER_BOARD_V5);
FuncPtr Emakefun_EncoderMotor::CallBack[2] = {NULL, NULL};
Emakefun_EncoderMotor *EncodeMotor_1 = mMotorDriver.getEncoderMotor(1);
Emakefun_EncoderMotor *EncodeMotor_2 = mMotorDriver.getEncoderMotor(2);

static void encoder1(void)
{
  Encoder1Pulse++;
  Serial.print("Encoder1Pulse");
  Serial.println(Encoder1Pulse);
}

 void encoder2(void)
{
  Encoder2Pulse++;
  Serial.print("Encoder2Pulse");
  Serial.println(Encoder2Pulse);
}
 
void setup()
{
    Serial.begin(9600);
    mMotorDriver.begin();
    delay(500);
    Serial.println("start");
    EncodeMotor_1->init(encoder1);
    EncodeMotor_2->init(encoder2);
}

void loop()
{
  EncodeMotor_1->setSpeed(255);
  EncodeMotor_2->setSpeed(255);
  EncodeMotor_1->run(FORWARD);
  EncodeMotor_2->run(FORWARD);
}
