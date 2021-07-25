# 作业

```bash
#include <MsTimer2.h>  
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
	int tick=0;
void setup()
    {
	    MsTimer2::set(1000, ontimer);
	    MsTimer2::start();
        Serial.begin(9600);
	    pinMode(IN1,OUTPUT);
	    pinMode(IN2,OUTPUT);
	    pinMode(IN3,OUTPUT);
	    pinMode(IN4,OUTPUT);
	  	pinMode(11,OUTPUT);
	  	pinMode(12,OUTPUT);
	  	pinMode(2,INPUT);	
	};
	void ontimer()
    {
	  tick++;
	}
void xianshi(int control,int n)
    {
	    int pin;
	    digitalWrite(control,LOW);
	    int array[10][4]=
        {
	        {0,0,0,0},
	        {0,0,0,1},
	        {0,0,1,0},
	        {0,0,1,1},
	        {0,1,0,0},
	        {0,1,0,1},
	        {0,1,1,0},
	        {0,1,1,1},
	        {1,0,0,0},
	        {1,0,0,1},
	    };
	    for(pin=IN1;pin<=IN4;pin++)
	        digitalWrite(pin,array[n][IN4-pin]);
	    digitalWrite(control,HIGH);
	};
	void loop()
    {
	    int shi,ge;
	    ge=tick%10;
	    shi=tick/10;
      	Serial.print(digitalRead(2));
	    Serial.print(shi);
      	Serial.println(ge);
	    xianshi(11,ge);
	    xianshi(12,shi);
	  	if(digitalRead(2)==1)tick=0;
	}


```
