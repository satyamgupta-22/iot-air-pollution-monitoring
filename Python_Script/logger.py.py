import serial
import time
import requests

# Replace 'COM3' with your Arduino's port
arduino = serial.Serial('COM12', 9600, timeout=1)
time.sleep(2)

# ThingSpeak API details
THINGSPEAK_API_KEY = '6HUBPNZYMWGWPSAI'  # Replace with your API Key
THINGSPEAK_URL = 'https://api.thingspeak.com/update'

while True:
    if arduino.in_waiting > 0:
        data = arduino.readline().decode().strip()
        print("Data from Arduino:", data)

        # Parse the data (assuming format like "Temp: 25 Humidity: 45 Air Quality: 150")
        try:
            temp = data.split()[1]
            humidity = data.split()[3]
            air_quality = data.split()[6]
            
            # Send data to ThingSpeak
            payload = {
                'api_key': THINGSPEAK_API_KEY,
                'field1': temp,
                'field2': humidity,
                'field3': air_quality
            }
            response = requests.get(THINGSPEAK_URL, params=payload)
            print("Data sent to ThingSpeak, response:", response.status_code)
        except IndexError:
            print("Error parsing data format")

        time.sleep(15)  # Delay to avoid hitting ThingSpeak rate limit
