
#define X_MAX_PIN          2
#define Y_MAX_PIN          15
#define Z_MAX_PIN          19

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_CS_PIN           53

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_CS_PIN           49

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_CS_PIN           40

String a;
int x = 0, y = 0, z = 0;
bool Button_Z = 0;
bool Button_Y = 0;
bool Button_Z = 0;

void setup() {
  Serial.begin(9600);
 
  pinMode(X_MAX_PIN, INPUT);
  digitalWrite(X_MAX_PIN, HIGH);
  pinMode(Y_MAX_PIN, INPUT);
  digitalWrite(Y_MAX_PIN, HIGH);
  pinMode(Z_MAX_PIN, INPUT);
  digitalWrite(Z_MAX_PIN, HIGH);

  pinMode(X_STEP_PIN, OUTPUT);
  digitalWrite(X_STEP_PIN, HIGH);
  pinMode(X_DIR_PIN, OUTPUT);
  digitalWrite(X_DIR_PIN, LOW);
  pinMode(X_ENABLE_PIN, OUTPUT);
  digitalWrite(X_ENABLE_PIN, LOW);
  pinMode(X_CS_PIN, OUTPUT);
  digitalWrite(X_CS_PIN, HIGH);

  pinMode(Y_STEP_PIN, OUTPUT);
  digitalWrite(Y_STEP_PIN, HIGH);
  pinMode(Y_DIR_PIN, OUTPUT);
  digitalWrite(Y_DIR_PIN, LOW);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);
  pinMode(Y_CS_PIN, OUTPUT);
  digitalWrite(Y_CS_PIN, HIGH);

  pinMode(Z_STEP_PIN, OUTPUT);
  digitalWrite(Z_STEP_PIN, HIGH);
  pinMode(Z_DIR_PIN, OUTPUT);
  digitalWrite(Z_DIR_PIN, LOW);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Z_ENABLE_PIN, LOW);
  pinMode(Z_CS_PIN, OUTPUT);
  digitalWrite(Z_CS_PIN, HIGH);

void loop() {

  Button_X = digitalRead(X_MAX_PIN);
  Button_Y = digitalRead(Y_MAX_PIN);
  Button_Z = digitalRead(Z_MAX_PIN);

while(Serial.available())
{
  Serial.setTimeout(100);
  a = Serial.readString('\n');
  sscanf(a.c_str(),"x %d y %d z %d", &x, &y, &z);
  
 if(x<0)
 {
  x = -x;
  digitalWrite(X_DIR_PIN, HIGH);
 }
  else
  {
  digitalWrite(X_DIR_PIN, LOW);
  }
  
   if(y<0)
 {
  y = -y;
  digitalWrite(Y_DIR_PIN, HIGH);
 }
  else
  {
  digitalWrite(Y_DIR_PIN, LOW);
  }
  
   if(z<0)
 {
  z = -z;
  digitalWrite(Z_DIR_PIN, HIGH);
 }
  else
  {
  digitalWrite(Z_DIR_PIN, LOW);
  }
}
 
  if(Button_X == 0 && x > 0)
    {
      digitalWrite(X_STEP_PIN, HIGH);
      x--;   
    }
  if(Button_Y == 0 && y > 0)
    {
      digitalWrite(Y_STEP_PIN, HIGH);
      y--;
    }    
  if(Button_Z == 0 && z > 0)
    {
      digitalWrite(Z_STEP_PIN, HIGH);
      z--;
    }
    
  delayMicroseconds(1000);
  digitalWrite(X_STEP_PIN, LOW);   
  digitalWrite(Y_STEP_PIN, LOW);   
  digitalWrite(Z_STEP_PIN, LOW);
  delayMicroseconds(1000);


}
