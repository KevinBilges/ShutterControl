#include <CD74HC4067.h>
#include <ShutterButton.h>

               
CD74HC4067 my_muxOut(4, 5, 6, 7);  
const int g_common_pinOut = A0; 

CD74HC4067 my_muxIn(A2, A3, A4, A5); 
const int g_common_pinIn = A6; 

ShutterButton shBtn(A6, my_muxIn, 1, true,(long)2000,(long)30000);

void setup()
{ 
  Serial.begin(500000);
  while (!Serial) {;}
  Serial.println("Hi there");
  
  pinMode(g_common_pinIn, INPUT); 
  pinMode(g_common_pinOut, OUTPUT);
}

int signal1;

void loop()
{   
    signal1 = shBtn.GetSignal();
    for (int i = 15; i >= 0; i--)
	{
      digitalWrite(g_common_pinOut, signal1);
      my_muxOut.channel(i);
      delay(20);      
    }
}

//      my_muxIn.channel(i);
//      delay(1);
//      tmp = analogRead(g_common_pinIn);
      
//      Serial.print(tmp);  
//      Serial.print("\r\n");