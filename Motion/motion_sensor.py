import RPi.GPIO as GPIO
import time
import requests

API_ENDPOINT = "10.10.10.172:1880/dat"

#Note:
#While using the function GPIO.setup(PIR_input, GPIO.IN) or GPIO.input(PIR_input), 
#the pin number given is a physical pin number. I.e. 
#if the pin is 8th row second column, the pin number is 16.



PIR_input = 16
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(PIR_input, GPIO.IN)

HUMAN_PRESENT = 1
HUMAN_NOT_PRESENT = 0

motion = 0;
last_state = HUMAN_NOT_PRESENT;

last_saved = time.time();
last_sent = time.time();


while True:
    motion = GPIO.input(PIR_input)
    if (motion):
        #HIGH means a change is detected in IR level
        last_state = HUMAN_PRESENT
        last_saved = time.time()
        # print("Motion detected.")
    else:
        #LOW means there is no change in IR level
        if (time.time()-last_saved > 30):
            last_state = HUMAN_NOT_PRESENT
            last_saved = time.time()

    if (time.time() - last_sent > 30):
        post_data = "{\"HUMAN_PRESENT\":" + str(last_state) + "}"
        print ("Sending....\n",data)
        res = requests.post(url=API_ENDPOINT, data=post_data)
        print (res)
        last_sent = time.time();
