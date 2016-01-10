int light = D3;     //pin to control the outlet 
int led = D7;       //pin to turn on the built in led, this is just to see if the program works 
                    //when the relay is not used. Could be removed. 
bool toggle = true; //variable to keep track of current position of the relay
void setup() {
    pinMode(light, OUTPUT);     //pin D3 is initialized as a output pin 
    pinMode(led, OUTPUT);       //pin D7 is initialized as a output pin. 
    
    //Spark.function is used to turn on or off the relay using the internet
    Spark.function("lightTimer",lightTimer);
    //The name inside the quotes is the name that will be visible when creating a recipe in IFTTT. This  
    // will call the lightTimer function. 
}

void loop() {
//nothing to loop
}

int lightTimer(String command){//command will be the string passed when this function is called from IFTTT
    if(command =="on"){             // turn on the relay
        toggle = true;
        digitalWrite(light, HIGH);
        digitalWrite(led, HIGH);
        return 1;
    }
    else if(command =="off"){       //turn off the relay
        toggle = false;
        digitalWrite(light, LOW);
        digitalWrite(led, LOW);
        return 0;
    }
    else if(command == "toggle"){   //toggle between on and off, using the DO button app. 
        if(toggle == true){         //turn off the relay since its already on
            digitalWrite(light, LOW);
            digitalWrite(led, LOW);
            toggle = false;
            return 0;
        }
        else{                       //turn on the relay since its already off
            digitalWrite(light, HIGH); 
            digitalWrite(led, HIGH);
            toggle = true;
            return 1;
        }
    }
    else{                       //other inputs return -1
        return -1;
    }
}
