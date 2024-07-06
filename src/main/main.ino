#include <CurieBLE.h>

BLEPeripheral blePeripheral;  // BLE Peripheral Device (the board you're programming)
BLEService TotalService("19B10000-E8F2-537E-4F6C-D104768A1214"); // BLE LED Service

// BLE LED Switch Characteristic - custom 128-bit UUID, read and writable by central
BLEFloatCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLEWrite | BLERead);

const int ledPin = 13; // pin to use for the LED

bool a = true;

// Setup ponte H
int enA = 9;
int in1 = 8;
int in2 = 7;



// Setup variabili potenza motori
const float maxPower = 255.0;
float motorPower = 255.0;
float percentage = 100.0;

void setup() {
  Serial.begin(9600);

  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  
  // Setup pin ponte H
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Inizia a muovere i motori in verso orario
  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);

  // set LED pin to output mode
  pinMode(13, OUTPUT);

  // set advertised local name and service UUID:
  blePeripheral.setLocalName("Arduino");
  blePeripheral.setAdvertisedServiceUuid(TotalService.uuid());

  // add service and characteristic:
  blePeripheral.addAttribute(TotalService);
  blePeripheral.addAttribute(switchCharacteristic);

  // set the initial value for the characeristic:
  switchCharacteristic.setValue(100.0);

  // begin advertising BLE service:
  blePeripheral.begin();

  Serial.println("BLE LED Peripheral");
}

void loop() {
  // listen for BLE peripherals to connect:
  BLECentral central = blePeripheral.central();

  digitalWrite(13, HIGH);

  // if a central is connected to peripheral:
  if (central) {
    digitalWrite(13, LOW);
    Serial.print("Connected to central: ");
    // print the central's MAC address:
    Serial.println(central.address());
    // while the central is still connected to peripheral:
    while (central.connected()) {
      analogWrite(enA, motorPower);

      if (switchCharacteristic.written()) {
        Serial.println(switchCharacteristic.value());
        
        float pressedKey = switchCharacteristic.value();

        keyPressed(pressedKey, motorPower);
        Serial.print("Speed: ");
        Serial.println(motorPower);
      }
    }

    /*
    0.5 = +0.5
    0.51 = -0.5
    1.0 = +1
    1.1 = -1
    5.0 = +5
    5.1 = -5
    10.0 = +10
    10.1 = -10
    401 = 0%
    402 = 50%
    403 = 100%

    */

    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    digitalWrite(13, HIGH);
    analogWrite(enA, 0);
    Serial.println(central.address());
  }
}


void keyPressed(float key, float & motorPower){
  if (key == 40.0){
    if (motorPower < 255.0){
      motorPower += 0.50;
      percentage = motorPower / 2.55;
    } else{
      Serial.println("Errore");
    }
  } else if (key == 45.0){
    if (motorPower > 0){
      motorPower -= 0.50;
      percentage = motorPower / 2.55;
    } else{
      Serial.println("Errore");
    }
  } else if (key == 50.0){
    if (motorPower <= 254.00){
      motorPower += 1.00;
      percentage = motorPower / 2.55;
    } else{
      Serial.println("Errore");
    }
  } else if (key == 55.0){
    if (motorPower >= 1.00){
      motorPower -= 1.00;
      percentage = motorPower / 2.55;
    } else{
      Serial.println("Errore");
    }
  } else if (key == 60.0){
    if (motorPower <= 250.00){
      motorPower += 5.00;
      percentage = motorPower / 2.55;
    } else{
      Serial.println("Errore");
    }
  } else if (key == 65.0){
    if (motorPower >= 5.00){
      motorPower -= 5.00;
      percentage = motorPower / 2.55;
    } else{
      Serial.println("Errore");
    }
  } else if (key == 70.0){
    if (motorPower <= 245.00){
      motorPower += 10.00;
      percentage = motorPower / 2.55;
    } else{
      Serial.println("Errore");
    }
  } else if (key == 75.0){
    if (motorPower >= 10.00){
      motorPower -= 10.00;
      percentage = motorPower / 2.55;
    } else{
      Serial.println("Errore");
    }
  } else if (key == 401.00){
    motorPower = 0;
    percentage = 0;
  } else if (key == 402.00){
    motorPower = 127.50;
    percentage = 50;
  } else if (key == 403.00){
    motorPower = 255.00;
    percentage = 1000;
  } else {
    Serial.print(key);
    Serial.println("  nessuna corrispondenza trovata");
  }
}

