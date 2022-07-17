#define indicator 13
#define pir1 5
#define pir2 6
#define time_set A5
#define door 2
#define light 3

// long time_val;
long time_on;


void setup() {
  Serial.begin(9600);
  
  pinMode(indicator,OUTPUT);
  pinMode(pir1,INPUT);
  pinMode(pir2,INPUT);
  pinMode(door,INPUT);
  pinMode(light,OUTPUT);
  pinMode(time_set,INPUT);
}

void loop() {
  digitalWrite(indicator,HIGH);
  Serial.print(analogRead(time_set));

  // time_val = map(analogRead(time_set), 0, 1023, 120, 1200);

  time_on = map(analogRead(time_set), 0, 1023, 120, 1200) * 1000;

  // Serial.print("\t");
  // Serial.print(time_val);
  
  Serial.print("\t");
  Serial.println(time_on);
}
