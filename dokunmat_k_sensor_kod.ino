const int touchSensorPin = 2;
          
          const int ledPins[] = {3, 4, 5};
          const int numLeds = 3;
          
          int currentLed = 0;
          bool lastTouchState = LOW;
          bool currentTouchState = LOW;
          
          void setup() {
                    for (int i = 0; i < numLeds; i++) {
                              pinMode(ledPins[i], OUTPUT);
                              digitalWrite(ledPins[i], LOW);
                    }
                    
                    pinMode(touchSensorPin, INPUT);
                    
                    Serial.begin(9600);
          }
          
          void loop() {
                    currentTouchState = digitalRead(touchSensorPin);
                    
                    if (currentTouchState != lastTouchState && currentTouchState == HIGH) {
                              digitalWrite(ledPins[currentLed], LOW);
                              
                              currentLed++;
                              if (currentLed >= numLeds) {
                                        currentLed = 0;
                              }
                              
                              digitalWrite(ledPins[currentLed], HIGH);
                              
                              Serial.print("LED ");
                              Serial.print(currentLed + 1);
                              Serial.println(" yandı");
                    }
                    
                    lastTouchState = currentTouchState;
                    
                    delay(50);
          }
