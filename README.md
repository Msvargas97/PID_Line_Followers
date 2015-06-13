# PID_Line_Followers
Libreria para seguidores de Linea
Version 1.0

#Bitacora:

  13/06/2015  ->         Version inicial
------------------------------------------------------


#Funciones

PID(int Setpoint,double Kp,double Ki,double Kd,int Max); //Instanciar parametros

 void ComputeSpeed(int position); //Calculamos la diferencia de potencial
 
 double getKp(); // Obtenemos el valor de las variables usadas
 
 double getKi();
 
 double getKd();
 
 int getSetpoint();
 
 int Speed(); //Obtenemos la velocidad o diferencia de potencial
 
 void setKp(double Kp); //Asignamos por separado cada parametro del PID
 
 void setKi(double Ki);
 
 void setKd(double Kd );
 
 void setSetpoint(int reference);
 
 void SetTunings(int Setpoint,double Kp,double Ki,double Kd); //Asignamos nuevos parametros al PID
 
 void SetSpeed(int Max); //Cambiamos la velocidad maxima 
 
 void SetMode(int Mode); //Podemos encender o apagar el PID
 
 bool Zero_Error=true; //Nos sirve para saber si el robot esta totalmente en linea

#Canal de Youtube:

https://www.youtube.com/channel/UCOZNJf3OX-E0kl-x7JjMbZA

Por favor hacer uso exclusivamente de forma didactica  o para uso propio

copyright 2015

Cualquier duda que tengas pueda hacermela saber

msvargas97@gmail.com

Creditos; Pololu, FKTBot y todas mis investigaciones hechas en internet :)

GitHub:https://github.com/Msvargas97?tab=repositories

#Open Source

#Msvargas97

2015
