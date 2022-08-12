void setup() 
{
  pinMode(5, INPUT);
  Serial.begin(9600);
}

void loop() 
{
    Serial.println(digitalRead(5));
}
