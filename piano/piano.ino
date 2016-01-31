void setup()
{
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  Serial.begin(9600);
}
int piano[4]={0,0,0,0};
char key[4]={'z','x','c','v'};
void loop()
{
  Keyboard.begin();
  for(int i=0;i<4;i++)
  {
    if(piano[i]==0 && digitalRead(i+3)==0)
    {Serial.print(i+3);
    Keyboard.press(key[i]);
    Keyboard.releaseAll();
    }
    if(piano[i]==1 && digitalRead(i+3)==1)
    delay(200);
    piano[i]=!digitalRead(i+3);  
}
  Keyboard.end();
}
