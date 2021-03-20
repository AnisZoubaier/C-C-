#pragma once
#include "gpio.hpp"
#include <memory>
#include <iostream> //debug
#include <vector>

enum gpioReference
{
    feedback1 = 0,
    feedback2 = 1,
    feedback3 = 2,
    feedback4 = 3,
    feedback5 = 4,
    feedback6 = 5,
    feedback7 = 6,

    audioOn = 7,
    audioOff = 8,

    userYes = 9,
    userNo = 10,

    startQuestions = 11,

    stateLED = 12
};

class InputPanel
{
public:
    /* Hier mit WiringPi https://www.ics.com/blog/how-control-gpio-hardware-c-or-c */

    InputPanel();
    unsigned int init();
    void listAllPins();
    void checkPressed(/*float delay */); //maybe add delay (<Thread> Library?)
    void toggle_state_LED();
    void restore(); //call after catching a pressed button

    std::vector<std::unique_ptr<GPIO>> gpioList;

private:


    unsigned int feedback_scalar;
    bool flag_questionlist_start;
    bool answer_yes;
    bool answer_no;


/* Frageborgen starten u. stopen aus XML  TODO */
void startQuestionlist();
void stopQuestionlist();

/* Aufnahme ueber Tablet */
void startVoiceRecording();
void stopVoiceRecording();

/* Skalarueckmeldung Fahrer ueber GPIO Pinbelegung TODO */
void getFedbackScalar();
// an CAN senden ..?   void setFedbackScalar();
};
