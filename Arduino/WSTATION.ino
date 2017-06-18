/**@file
*
* 	\brief Weather station system
*	
*	App running on Arduino UNO. It's gathering data from sensors and sending them
*	to database located on remote server.
*	
*	List of sensors:
*	-# Thermometer
*	-# Barometer
*	-# Humidity sensor
*	-# Anemometer
*	-# Wind vane
*		
*
*
*	\version 1.0
*	\date 06/2017
*
*	
*
*/




#include <dht11.h> 	//Library for thermometer and humidity sensor*/
#include <Wire.h>	//Library needed for barometer*/
#include <Adafruit_Sensor.h> //Library needed for barometer*/
#include <Adafruit_BMP085_U.h> //Library for barometer*/
#include <UIPEthernet.h> //Library used for Ethernet*/

#define DHT11PIN 2	/*!< Pin used for thermometer and humidity sensor*/
#define wdirPIN A4	/*!< Pin used for wind vane*/
#define wspdPIN A1	/*!< Pin used for anemometer*/
#define offset 0	/*!< Offset for calibration of wind director*/
#define intervalTime 300000 /*!< Interval between sending data*/

dht11 DHT11;	/*!< Instance of thermometer and humidity sensor*/
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085); /*!< Instance of barometer*/
EthernetClient client; /*!< Instance of ethernet client*/
byte mac[] = { 0x54, 0x34, 0x41, 0x30, 0x30, 0x31 }; /*!< Ethernet MAC address of device          */                 
char server[] = "192.168.1.100"; /*!< IP Adres (or name) of server to dump data to*/

char SID[] = "sid1"; /*!< Weather station identificator*/

float hum; /*!< Humidity*/
float temp; /*!< Temperature*/
float pres; /*!< Pressure*/
int wdirValue; /*!< Raw analog value from wind vane */
int wdir; /*!< Translated 0 - 360 wind direction */
int wspdValue; /*!< Raw analog value from anemometer*/
float wspdVoltage; /*!< Variable that stores the voltage (in Volts) from the anemometer being sent to the analog pin*/
float wspd; /*!< Wind speed in meters per second (m/s)*/
float voltageConstant = .004882814; /*!< This constant maps the value provided from the analog read function, which ranges from 0 to 1023, to actual voltage, which ranges from 0V to 5V*/
float VoltageMin = .4; /*!< Mininum output voltage from anemometer in mV*/
float wspdMin = 0; /*!< Wind speed in meters/sec corresponding to minimum voltage*/
float VoltageMax = 2.0; /*!< Maximum output voltage from anemometer in mV*/
float wspdMax = 32; /*!< Wind speed in meters/sec corresponding to maximum voltage*/



/**
*\brief Setting up the system
*Setting up the system
*/
void setup()
{
	Serial.begin(9600); 
	bmp.begin()
	Ethernet.begin(mac);
}



/**
*\brief Main loop of the program
*Main loop of the program
*/
void loop()
{
	getMeasurments(); //Getting data from sensors
	sendData();		//Sending data to server
	delay(intervalTime); //Waiting for getting next set of data
}

/**
*\brief Getting data from sensors
*Getting data from sensors
*/
void getMeasurments(){

	hum = (float)DHT11.humidity; //Getting humidity
	temp = (float)DHT11.temperature; //Getting humidity
	
	
	sensors_event_t event;
	bmp.getEvent(&event);
	pres = (float)event.pressure; //Getting humidity
	
	
	wspdValue = analogRead(wspdPIN); //Get a value between 0 and 1023 from the analog pin connected to the anemometer
	wspdVoltage = wspdValue * voltageConstant; //Convert sensor value to actual voltage.

	
	if (wspdVoltage <= VoltageMin){	//Convert voltage value to wind speed using range of max and min voltages and wind speed for the anemometer
	wspd = 0; //Check if voltage is below minimum value. If so, set wind speed to zero. 
	}else{ 
	wspd = ((wspdVoltage - VoltageMin) * wspdMax / (voltageMax - voltageMin)); //For voltages above minimum value, use the linear relationship to calculate wind speed. 
	} //Max wind speed calculation 

	
	wdirValue = analogRead(wdirPIN); //Get a value between 0 and 1023 from the analog pin connected to the wind vane
	wdir = map(wdirValue, 0, 1023, 0, 360); //Maps value between 0 and 1023 to degree value
	wdir = wdir + offset;  //Calibration

	if(wdir > 360) 
	wdir = wdir - 360; 

	if(wdir < 0) 
	wdir = wdir + 360; 
	
}


/**
*\brief Connecting device with remote server to store data. Using HTTP GET method
*Connecting device with remote server to store data. Using HTTP GET method
*/
void sendData(){

	client.connect(server, 80);
	  
    client.print( "GET /update.php?");
	client.print("SID=")
	client.print(SID);
	client.print("&temp=")
	client.print(temp);
	client.print("&pres=")
	client.print(pres);
	client.print("&hum=")
	client.print(hum);
	client.print("&wspd=")
	client.print(wspd);
	client.print("&wdir=")
	client.println(wdir);
	
    client.println( " HTTP/1.1");
    client.print(" Host: ");
    client.println(server);
    client.println( "Connection: close" );
    client.println();
    client.println();
    client.stop();

}









