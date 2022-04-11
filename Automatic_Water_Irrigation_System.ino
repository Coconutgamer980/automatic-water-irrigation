
//1 variables
int relayPin1 = 8;
int sensor_pin1 = A0; 
int output_value1;
//2 variable
int relayPin2 = 12;
int sensor_pin2 = A1; 
int output_value2;
//3 variable
int relayPin3 = 13;
int sensor_pin3 = A2; 
int output_value3;
//Bread board
int relayPin4 = 7;
//Bluetooth
char Incoming_value = 0;

void setup()         
{ 
  WaterIrrigationStart();
}
void loop() 
{
  WaterIrrigationLoop();
}
void WaterIrrigationLoop()
{
    if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();              
    if(Incoming_value == '1') 
    {
      //1 value input
      output_value1 = analogRead(sensor_pin1);
      output_value1 = map(output_value1,550,10,0,100);
      //2 value input
      output_value2 = analogRead(sensor_pin2);
      output_value2 = map(output_value2,550,10,0,100);
      //3 value input
      output_value3 = analogRead(sensor_pin3);
      output_value3 = map(output_value3,550,10,0,100);

      //1 value output
      Serial.print("1:");
      Serial.print(output_value1);
      Serial.print("%  ");
      //2 m value output
      Serial.print("2:");
      Serial.print(output_value2);
      Serial.print("%  ");
      //3 value output
      Serial.print("3:");
      Serial.print(output_value3);
      Serial.println("%  ");

      //1
      if(output_value1<20){
        digitalWrite(relayPin1, LOW);
        digitalWrite(relayPin4, LOW);
      }
      else
      {
        digitalWrite(relayPin1, HIGH);    
        digitalWrite(relayPin4, HIGH);    
      }
      //2
      if(output_value2<20){
        digitalWrite(relayPin2, LOW);
        digitalWrite(relayPin4, LOW);
      }
      else
      {
        digitalWrite(relayPin2, HIGH);
        digitalWrite(relayPin4, HIGH);        
      }
      //3
      if(output_value3<20){
        digitalWrite(relayPin3, LOW);
        digitalWrite(relayPin4, LOW);
      }
      else
      {
        digitalWrite(relayPin3, HIGH);
        digitalWrite(relayPin4, HIGH);        
      }
    }
  }
 
   delay(10);
}
void WaterIrrigationStart()
{
  Serial.begin(9600);
  
  //1 input and output              
  pinMode(relayPin1, OUTPUT); 
  pinMode(sensor_pin1, INPUT);
  //2 input and output 
  pinMode(relayPin2, OUTPUT); 
  pinMode(sensor_pin2, INPUT);
  //3 input and output 
  pinMode(relayPin3, OUTPUT); 
  pinMode(sensor_pin3, INPUT);
  
  Serial.println("Starting Project");
  Serial.println(" ");
  delay(0);
}