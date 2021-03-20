
#include "canSend.hpp"

canSend::canSend(){

std::cout << "CAN Sockets" << std::endl;
}


void canSend::sendBewertung(){

// create a socket
if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		perror("Socket");
		return 1;
	}
//retrieve the interface index for the interface name can0
	strcpy(ifr.ifr_name, "can0" );
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

	frame.can_id = 0x555;
	frame.can_dlc = 5;
	sprintf(frame.data, "Hello");

	if (write(s, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
		perror("Write");
		return 1;
	}

	if (close(s) < 0) {
		perror("Close");
		return 1;
	}
}

// canSend::sendBewertung(can_frame.can_id ,can_frame.data)
