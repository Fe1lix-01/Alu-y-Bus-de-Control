char  data[26];
int   number_of_bytes_received;
int A = 0;
int B = 0;

void setup() {

  Serial.begin  (9600);
  Serial.println ("Esperando instrucciones...");
  pinMode(2, INPUT); // A
  pinMode(3, INPUT); // B
  pinMode(4, OUTPUT); // LED1 (SUMA) (MULT) (RESTA) (DIVISION1)
  pinMode(5, OUTPUT); // LED2 (ACARREO) (SIGNO) (INDEFINIDO)
  pinMode(6, OUTPUT); // LED3 (INFINITO)
  pinMode(7, OUTPUT); // LED4 (DIVISION2)  
  
  }

void loop() {

  A = digitalRead(2);
  B = digitalRead(3);
  
  while(Serial.available())
  {

    number_of_bytes_received = Serial.readBytesUntil   (13, data, 25);     
    data[number_of_bytes_received] = 0;    
    
    // SUMA
    bool result0 = strcmp  (data, "SUM");    if (!result0)   {Serial.println("Operación suma"); 
                                                              if(A ^ B){digitalWrite(4, HIGH); delay(1000);} 
                                                              if(A && B){digitalWrite(5, HIGH); delay(1000);}}

    // MULTIPLICACION
    bool result1 = strcmp  (data, "MUL");    if (!result1)   {Serial.println("Operación multiplicación"); 
                                                              if(A && B){digitalWrite(4, HIGH); delay(1000);}}

    // RESTA
    bool result2 = strcmp  (data, "RES");    if (!result2)   {Serial.println("Operación resta"); 
                                                              if(A ^ B){digitalWrite(4, HIGH); delay(1000);} 
                                                              if(!A && B){digitalWrite(5, HIGH);delay(1000);}}

    // DIVISION
    bool result3 = strcmp  (data, "DIV");    if (!result3)   {Serial.println("Operación division"); 
                                                              if(!A && !B){digitalWrite(5, HIGH); delay(1000);} 
                                                              if(A && !B){digitalWrite(6, HIGH); delay(1000);} 
                                                              if(!A && B){digitalWrite(7, HIGH); delay(1000);} 
                                                              if(A && B){digitalWrite(4, HIGH);delay(1000);}}

    // AND
    bool result4 = strcmp  (data, "AND");    if (!result4)   {Serial.println("Operación AND"); 
                                                              if(A && B){digitalWrite(4, HIGH);delay(1000);}}

    // OR
    bool result5 = strcmp  (data, "OR");    if (!result5)   {Serial.println("Operación OR"); 
                                                              if(A || B){digitalWrite(4, HIGH);delay(1000);}}

    // XOR
    bool result6 = strcmp  (data, "XOR");    if (!result6)   {Serial.println("Operación XOR"); 
                                                              if(A ^ B){digitalWrite(4, HIGH);delay(1000);}} 
    // XNOR
    bool result7 = strcmp  (data, "XNOR");    if (!result7)   {Serial.println("Operación XNOR"); 
                                                              if(!(A ^ B)){digitalWrite(4, HIGH);delay(10000);}
                                                              else {digitalWrite(5, HIGH);delay(10000);}}
  }
  
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);

}