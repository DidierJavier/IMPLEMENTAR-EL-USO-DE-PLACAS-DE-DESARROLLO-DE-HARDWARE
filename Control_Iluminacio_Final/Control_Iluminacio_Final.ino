/*Dídier Javier Ramírez Henao
---------------------------------------------
Control de intensidad de iluminación de dos lámparas por PWM
---------------------------------------------
Programa que controla dos lámparas de manera proporcional de
acuerdo a la cantidad de luz que incida en una
fotocelda.
*/
const int sensorPin = A0;    // seleccionar la entrada para el sensor análogo (fotoresistencia)
int sensorValue;       // variable que almacena el valor raw (0 a 1023)
float intensidadLuz = 0; //Variable para controlar la intensidad de la luz
int lamparaUno = 9;    //Variable de salida para la lámpara uno. Se controla su intensidad de acuerdo con el ancho de pulso del pin 9 (PWM)
int lamparaDos = 11;    //Variable de salida para la lámpara dos. Se controla su intensidad de acuerdo con el ancho de pulso del pin 11 (PWM)

void setup()
{
   Serial.begin(9600);
   pinMode (lamparaUno,OUTPUT);         //Se configura lamparaUno como salida (pin 9)
   pinMode (lamparaDos,OUTPUT);         //Se configura lamparaDos como salida (pin 11)
}
 
void loop() 
{
   sensorValue = analogRead(sensorPin);   // realizar la lectura de la intensidad de iluminación (Entrada análoga A0) 
   //mandar mensaje a puerto serie en función del valor leido
   if (sensorValue >= 0 and sensorValue <= 204.7)//Si el voltaje medido en el sensor análogo es menor a 1V(204.8) 
   {
      Serial.println("Aumentando la iluminación de la sala 1 y la sala 2 del 0% al 20% de forma gradual durante 12 segundos.");
      for (int i = 1; i <= 12; i++)
      {
        analogWrite(lamparaUno, intensidadLuz);
        analogWrite(lamparaDos, intensidadLuz);
        delay (1000);
        Serial.println(i);
        intensidadLuz = intensidadLuz + 4.25;
      }
      sensorValue = analogRead(sensorPin);
      while (sensorValue <= 204.7)
        {
          sensorValue = analogRead(sensorPin);
          Serial.println("Error en el sensor, han pasado 12 segundos y no se ha llegado al 20% de iluminación");
          delay (1000);
        }
      Serial.println("La iluminación ha llegado al 20%. Continuará así durante 1:59 horas");
      delay (10000); //Intensidad de la luz sigue en 20% durante 1:59 horas
      Serial.println("Han pasado 1:59 horas. La iluminación debe pasar del 20% al 40% en un minuto");
      Serial.println(sensorValue);
      delay (1000);//A las 2:00 la intensidad de luz aumenta del 20% al 60%
        }    
   else 
      if
      (sensorValue >= 204.8 and sensorValue < 409.6)
      {
        Serial.println("Aumentando la iluminación de la sala 1 y la sala 2 del 20% al 40% de forma gradual durante 12 segundos.");
        for (int i = 1; i <= 12; i++)
        {
          analogWrite(lamparaUno, intensidadLuz);
          analogWrite(lamparaDos, intensidadLuz);
          delay (1000);
          Serial.println(i);
          intensidadLuz = intensidadLuz + 4.25;
        }
        sensorValue = analogRead(sensorPin);
        while (sensorValue < 409.6)
        {
         sensorValue = analogRead(sensorPin);
         Serial.println("Error en el sensor, han pasado 12 segundos y no se ha llegado al 40% de iluminación");
         delay (1000);
        }
        Serial.println("La iluminación ha llegado al 40%. Continuará así hasta las 3:59 horas");
        delay (10000); //La intensidad de la luz sigue en 40% hasta las 3:59
        Serial.println("Han pasado 3:59 horas. La iluminación debe pasar del 40% al 60% en un minuto");
        Serial.println(sensorValue);
        delay (1000);//A las 4:00 la intensidad cambia del 40% al 60%
        }
      else
        if
        (sensorValue >= 409.6 and sensorValue < 614.4)
        {
          Serial.println("Aumentando la iluminación de la sala 1 y la sala 2 del 40% al 60% de forma gradual durante 12 segundos.");
          for (int i = 1; i <= 12; i++)
          {
            analogWrite(lamparaUno, intensidadLuz);
            analogWrite(lamparaDos, intensidadLuz);
            delay (1000);
            Serial.println(i);
            intensidadLuz = intensidadLuz + 4.25;
          }
          sensorValue = analogRead(sensorPin);
          while (sensorValue < 614.4)
          {
            sensorValue = analogRead(sensorPin);
            Serial.println("Error en el sensor, han pasado 12 segundos y no se ha llegado al 60% de iluminación");
            delay (1000);
          }
          Serial.println("La iluminación ha llegado al 60%. Continuará así hasta las 6:59 horas");
          delay (10000); //La intensidad de luz sigue en 60% hasta las 6:59
          Serial.println("Han pasado 6:59 horas. La iluminación debe pasar del 60% al 75% en un minuto");
          Serial.println(sensorValue);
          delay (1000);//A las 7:00 la intensidad cambia del 60% al 75%
          }
        else
          if
          (sensorValue >= 614.4 and sensorValue < 768)
          {
            Serial.println("Aumentando la iluminación de la sala 1 y la sala 2 del 60% al 75% de forma gradual durante 12 segundos.");
            for (int i = 1; i <= 12; i++)
            {
              analogWrite(lamparaUno, intensidadLuz);
              analogWrite(lamparaDos, intensidadLuz);
              delay (1000);
              Serial.println(i);
              intensidadLuz = intensidadLuz + 3.1875;
            }
            sensorValue = analogRead(sensorPin);
            while (sensorValue < 768)
            {
              sensorValue = analogRead(sensorPin);
              Serial.println("Error en el sensor, han pasado 12 segundos y no se ha llegado al 75% de iluminación");
              delay (1000);
            }
            Serial.println("La iluminación ha llegado al 75%. Continuará así hasta las 7:59 horas");
            delay (10000); //La intensidad de luz sigue en 75% hasta las 7:59
            Serial.println("Han pasado 7:59 horas. La iluminación se va a apagar de forma gradual durante 12 segundos");
            Serial.println(sensorValue);
            delay (1000);//A las 8:00 la intensidad cambia del 75% al 0%
            }
            else
            if
            (sensorValue >= 768)
            {
              Serial.println("Disminuyendo la iluminación del 75% al 0%");
              for (int i = 1; i <= 12; i++)
              {
                delay (1000);
                Serial.println(i);
                intensidadLuz = intensidadLuz - 15.9375;
                analogWrite(lamparaUno, intensidadLuz);
                analogWrite(lamparaDos, intensidadLuz);
              }     
              sensorValue = analogRead(sensorPin);
              while (sensorValue > 1)
              {
                sensorValue = analogRead(sensorPin);
                Serial.println("Error en el sensor, han pasado 12 segundos y no se ha llegado al 0% de iluminación");
                delay (1000);
              }
              Serial.println("La iluminación ha llegado al 0%. Hasta mañana");         
              delay (10000); //La intensidad de luz sigue en 0%
              Serial.println("Han pasado 24:00  horas. El ciclo vuelve a empezar");
              Serial.println(sensorValue);
              delay (1000);//A las 00:00 el ciclo vuelve a empezar
              }
   delay(1000);

}
