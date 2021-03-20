#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>


class canSend
{
public:
    canSend();
   void sendBewertung();
    //sendBewertung(can_frame.can_id ,can_frame.data);
private:
    int s;


};
