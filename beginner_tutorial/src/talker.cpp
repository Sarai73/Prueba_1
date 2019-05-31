#include "ros/ros.h"
#include "std_msgs/String.h"

int main (int argc, char **argv){  //inicio de programa 
	ros::init(argc, argv, "talker_Sarai");  //declaracion del nombre del NODO (inicializacion)
	ros::NodeHandle n;  //Manejador del NODO
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",100); // declarar el nodo publicador- El nodo publica en un Topico con un buffer de 100 posiciones
	ros::Rate loop_rate(0.5); // Se ejecutara 10 veces por seg 
	
	//chatter_pub <-- envuelve al mensaje  & chatter es el nombre del topico 
	
	
	int count = 0;
	while (ros::ok()) { //mientras no hayamos enviado Ctrl -C
		std_msgs::String msg; // Crea el mensaje
		std::stringstream ss; //variable interna tipo stringstream (enviarla a la ventana)
		ss << "Hola mundo " << count;
		msg.data = ss.str();
		std::cout << msg.data.c_str() << std::endl;// Escribe en terminal  "Hola mundo" en el programa pudimos poner el ss 
		chatter_pub.publish(msg); // Envia mensaje al topico 
		ros::spinOnce();
		loop_rate.sleep();
		++count;
		
	}
	return 0; 
}
