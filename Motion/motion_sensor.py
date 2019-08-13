import RPi.GPIO as GPIO
import time
import requests
import json

API_ENDPOINT = "http://10.10.5.82:1880/dat"

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
motion_in_last5s = 0;
last_state = HUMAN_NOT_PRESENT;

last_seen = time.time()-5;
last_sent = time.time()-5;


while True:
    motion = GPIO.input(PIR_input)
    if (motion):
        #HIGH means a change is detected in IR level
        last_state = HUMAN_PRESENT
        motion_in_last5s = motion;
        last_seen = time.time()
        # print("Motion detected.")
    else:
        #LOW means there is no change in IR level
	if (time.time()-last_seen > 5):
            motion_in_last5s = 0
        if (time.time()-last_seen > 35):
            last_state = HUMAN_NOT_PRESENT
            #last_seen = time.time()

    if (time.time() - last_sent > 2.5):	#send data at every 2.5 seconds
        last_sent = time.time();
        interval = int(last_sent - last_seen)
        post_data = json.dumps({"LOCATION":"BATHROOM2", "HUMAN_PRESENT":last_state, "HUMAN_MOTION":motion,"MOTION_IN_LAST_5S":motion_in_last5s, "LAST_ACTIVITY":str(interval)+" seconds ago"})
        #post_data = '{\\'+'\"HUMAN_PRESENT'+ '\\'+  '\":' + str(last_state) + '}'
        print ("Sending....",post_data)
        try:
            res = requests.post(url=API_ENDPOINT, data=post_data, timeout=1.5)
            #print (res)
        except Exception as e:
            print("...problem connecting to IoT server!")

