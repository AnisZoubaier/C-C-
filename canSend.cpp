
#include "canSend.hpp"

canSend::canSend(){

std::cout << "CAN Sockets" << std::endl;
canID=0x555;;
frageID=1;
bewertung=2;
}


int canSend::sendBewertung(){

// create a socket
if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		perror("Socket");
		return 1;
	}
//retrieve the interface index for the interface name can0
	strcpy(ifr.ifr_name, "vcan0" );
	ioctl(s, SIOCGIFINDEX, &ifr);
// bind the socket to the CAN Interface

	memset(&addr, 0, sizeof(addr));
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;


	if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("Bind");
		return 1;
	}
//Sending a frame

	frame.can_id = canID;
	frame.can_dlc = 5;
	frame.data[1]=frageID;
	frame.data[2]=bewertung;
	

	if (write(s, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
		perror("Write");
		return 1;
	}

	if (close(s) < 0) {
		perror("Close");
		return 1;
	}
	return 0;
}

int canSend::sendBewertung(__u32  canID,__u8 frageID ,__u8 bewertung){
// create a socket
if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		perror("Socket");
		return 1;
	}
//retrieve the interface index for the interface name can0
	strcpy(ifr.ifr_name, "vcan0" );
	ioctl(s, SIOCGIFINDEX, &ifr);
// bind the socket to the CAN Interface

	memset(&addr, 0, sizeof(addr));
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;


	if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("Bind");
		return 1;
	}
//Sending a frame

	frame.can_id = canID;
	frame.can_dlc = 2;
	frame.data[1]=frageID;
	frame.data[2]=bewertung;
	

	if (write(s, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
		perror("Write");
		return 1;
	}

	if (close(s) < 0) {
		perror("Close");
		return 1;
	}
	return 0;
}
