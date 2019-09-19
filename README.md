# Dispositivos-Smart-con-ESP8266-controlados-con-Amazon-ECHO
Repositorio de archivos utilizados en el proyecto Dispositivos Smarts contorlados por un amazon ECHO

# Diagrama de conexion 
![Diagrama](https://raw.githubusercontent.com/SETISAEDU/Dispositivos-Smart-con-ESP8266-controlados-con-Amazon-ECHO/master/ESP8266_AmazonECHO_Diagrama.jpg)

El proyecto consiste en poder recrear un dispositvo Smart haciendo uso de las tarjetas ESP8266 y que pueda ser controlado desde un Amazon ECHO. Hoy en dia podemos encontrar focos de 110 V AC que puden ser controlados desde un dispositivo movil por medio de una conexion WiFi, la limitante de estas tecnologias pude ser muchas veces sus altos costos es por eso que el proyecto propone una solucion para convertir los dispositivos que ya tenemos en nuestras casas como luces, ventiladores o cargadores de celular. 

El amazon Echo al ser un altavoz inteligente encaja perfectamente, ya que posee un asistente virtual llamado "Alexa", capaz de responder preguntas, reproducir podcast, musica o audilibros, consultas del clima y lo mas importante para nostros sera el control de dispositivos smart. El ESP8266 al ser un microcontrolador que posee conexion WiFi nos permite interactuar con el Amazon Echo gracias a la simulaion de un foco Philips Hue por medio de la libreria "FauxmoESP", agregando una tarjeta de modulos rele la tarea de control de dispositivos a 110 V AC se vuelve mas sencilla.
 
# Codigos
Dentro de la carpeta "Codigos" de este repositorio encontraran 3 carpetas con las variantes LIGHTS, FAN y CHARGER, esto se debe a que decidimos utilizar mas de un ESP y conectar cada uno de estos dispositivos a su propia tarjeta.  

# Fauxmo ESP
Esta es una libreria para dispositivos ESP8266 / ESP32 que simula el comportamiento de un foco Philips Hue por lo tanto permite controlar desde dispositivos con tecnología "Alexa" como Amazon Echo o Dot.
Dejamos el enlace del foro del creador para poder ver mas informacion:
FauxmoESP(https://bitbucket.org/xoseperez/fauxmoesp/src/master/)

Nota: La libreria fauxmoESP debe de ser agregado a la lista de librerias de nuestra computadora. Al descomprimir el archivo la carpeta posee el siguiente nombre "xoseperez-fauxmoesp-f60c46d80f9b" lo cual debera ser cambiado a "xoseperez_fauxmoesp"


# ESP Async TCP
NOTA: La libreria ESPAsyncTCP debe de ser agregada a la lista de librerias de nuestra computadora. Al descomprimir el archivo la carpeta posee el siguiente nombre "ESPAsyncTCP-master" lo cual debera ser cambiado a "ESPAsyncTCP".


