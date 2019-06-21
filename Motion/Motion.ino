int val = 0;                 // variable to store the sensor status (value)
int sensor = 2;

//Set low time delay (Left )
//set high distance sensitivity / high IR sensitivity

void setup() {
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  Serial.println(val);
  
  if (val == LOW){
    //LOW means there is no change in IR level
    Serial.println("No Motion!");
  }else{
    //HIGH means a change is detected in IR level
    Serial.println("Motion!");
  }

}
