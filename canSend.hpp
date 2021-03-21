
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#pragma once
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

class canSend
{
public:
    canSend();
   int sendBewertung();
   int sendBewertung(__u32  canID,__u8 frageID ,__u8 bewertung);
private:
    int s;
	struct sockaddr_can addr;
	struct ifreq ifr;
	struct can_frame frame;
    __u32  canID;
    __u8 frageID;
    __u8 bewertung;
};
