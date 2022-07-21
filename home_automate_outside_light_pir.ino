#define indicator 13
#define pir1 5
#define pir2 6
#define time_set A5
#define door 2
#define light 3
#define ldr A0

// long time_val;
long time_on;
int time_org, state = 0;
unsigned long long prev_time = 0;



void setup() {
  Serial.begin(9600);
  
  pinMode(indicator,OUTPUT);
  pinMode(pir1,INPUT);
  pinMode(pir2,INPUT);
  pinMode(door,INPUT);
  pinMode(light,OUTPUT);
  pinMode(time_set,INPUT);
  pinMode(ldr,INPUT);


  digitalWrite(indicator,HIGH);
  
}

void loop() {  
  Serial.print(analogRead(time_set));
  Serial.print("\t");
  Serial.print(digitalRead(door));

  // time_val = map(analogRead(time_set), 0, 1023, 120, 1200);

  time_on = map(analogRead(time_set), 0, 1023, 1800, 120) * 1000;

  // Serial.print("\t");
  // Serial.print(time_val);

  Serial.print("\t");
  Serial.print(time_on);

  // view original time 
  time_org = (time_on/1000)/60;
  Serial.print("\t");
  Serial.print(time_org);

  Serial.print("\t");
  Serial.println(analogRead(ldr));


  // main code
  if(digitalRead(door) == LOW && state ==0 && analogRead(ldr) > 300){
    digitalWrite(light,HIGH);
    state = 1;
  }

  if(state == 1){
    if(millis() - prev_time >= time_on){
      digitalWrite(light,LOW);
      prev_time = millis();
      state = 0;            
    }
  }

}
