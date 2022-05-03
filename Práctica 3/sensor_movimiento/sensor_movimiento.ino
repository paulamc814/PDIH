// Detector de luz con LDR 
void setup() { 
 
  pinMode(13, OUTPUT); 
  Serial.begin(9600); 
} 
 
void loop() { 
 
  int v = analogRead(A0); 
  
  if (v < 550) digitalWrite(13, HIGH);  
  else digitalWrite(13, LOW); 
  Serial.println(v); 
}
