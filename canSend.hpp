
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

class canSend
{
public:
    canSend();
   void sendBewertung();
    //sendBewertung(can_frame.can_id ,can_frame.data);
private:
    int s;
	struct sockaddr_can addr;
	struct ifreq ifr;
	struct can_frame frame;

};
