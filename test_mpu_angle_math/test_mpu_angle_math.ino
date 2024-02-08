       
#include <Wire.h>

#include <MPU6050.h>

#include <Servo.h> 

#include <math.h>
 
Servo sg90;          

int servo_pin = 2;

MPU6050 sensor ;

int16_t ax, ay, az ;

int16_t gx, gy, gz ;

int16_t angle = gx/ax;

void setup ( )

{ 

sg90.attach ( servo_pin );

Wire.begin ( );

Serial.begin  (9600); 

Serial.println  ( "Initializing the sensor" ); 

sensor.initialize ( ); 

Serial.println (sensor.testConnection ( ) ? "Successfully Connected" : "Connection failed"); 

delay (1000); 

Serial.println ( "Taking Values from the sensor" );

delay (1000);

}




void loop ( ) 

{ 

sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);

ax = map (ax, -17000, 17000, 0, 180) ;

az = map (az, -17000, 17000, 0, 180) ;

Serial.println (ax);

Serial.println (az);

Serial.println(angle);

sg90.write (atan(angle)); 

delay (200);

}
