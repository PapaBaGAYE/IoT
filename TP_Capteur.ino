void setup() 
{
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

void loop() 
{
  if (digitalRead(2) == 0)
  {
    digitalWrite(13, HIGH); 
    delay(10000);
    digitalWrite(13, LOW); 
  }
  else digitalWrite(13, LOW); 
}
