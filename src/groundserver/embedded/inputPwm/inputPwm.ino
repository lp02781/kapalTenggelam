int ch1 = 2;
int ch2 =  3;
int ch3 =  4;
unsigned long ch1v;
unsigned long ch2v;
unsigned long ch3v;

void setup()
{
 pinMode(ch1, INPUT);
 pinMode(ch2, INPUT);
 pinMode(ch3, INPUT);
 Serial.begin(9600);      // open the serial port at 9600 bps:    

}

void loop()
{
 ch1v = pulseIn(ch1, HIGH);
 ch2v = pulseIn(ch2, HIGH);
 ch3v = pulseIn(ch3, HIGH);

 //(... code here never gets executed ... (but does if you comment out the previous line)
}
