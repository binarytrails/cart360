#define SONAR_IN A0

#define MOT_A 3
#define MOT_B 5

long inches; // sonar

int motor_from = 0;
int motor_to = 255;

const int motor_from_range = 0;
const int motor_to_range = 255;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReference(INTERNAL);

  pinMode(SONAR_IN, INPUT);

  pinMode(MOT_A, OUTPUT);
  pinMode(MOT_B, OUTPUT);
}

void loop()
{
  inches = analogRead(SONAR_IN) / 8;
 
  Serial.print("sonar ");
  Serial.print(inches);
  Serial.println("inches ");

  delay(100);

  if (inches < 20)
  {
    if (motor_from == motor_from_range)
    {
      for(int i = motor_from_range; i < motor_to_range; i++)
      {
        digitalWrite(MOT_A, motor_to_range);
        digitalWrite(MOT_B, motor_from_range);   
        delay(5);
      }


    }
    else if (motor_from == motor_to_range)
    {
      for(int i = motor_from_range; i < motor_to_range; i++)
      {
        digitalWrite(MOT_A, motor_from_range);
        digitalWrite(MOT_B, motor_to_range);
        delay(5);
      }

    }
    int temp = motor_from;
    motor_from = motor_to;
    motor_to = temp;
  }
}
