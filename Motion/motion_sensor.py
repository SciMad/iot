import RPi.GPIO as GPIO

#Note:
#While using the function GPIO.setup(PIR_input, GPIO.IN) or GPIO.input(PIR_input), 
#the pin number given is a physical pin number. I.e. 
#if the pin is 8th row second column, the pin number is 16.



PIR_input = 16
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(PIR_input, GPIO.IN)

while True:
    if (GPIO.input(PIR_input)):
        #HIGH means a change is detected in IR level
        print("Motion detected.")
    else:
        #LOW means there is no change in IR level
        print("No motion.")
