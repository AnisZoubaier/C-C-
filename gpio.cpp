//#include <wiringPi>
#include "gpio.hpp"

#include <iostream> //debug

//pin descriptions shortcut (easy to change the currently used I/O)
//testing needed -- wiringPi physical pins or defined GPI/O
//currently using *physical pins*
enum pin{

	feedback_1 = 3,
	feedback_2 = 5,
	feedback_3 = 7,
	feedback_4 = 8,
	feedback_5 = 10,
	feedback_6 = 11,
	feedback_7 = 12,

    audio_on = 13,
    audio_off = 15,

	user_yes = 16,
	user_no = 18,

	start_questions = 29,

	led_0 = 31,
	led_1 = 32
};

/**************************************************************************************************
 Inputs:

feedback 1-7 -> gpioList[0]-gpioList[6]
audio on -> gpioList[7]
audio off -> gpioList[8]
"yes" user input -> gpioList[9]
"no" user input -> gpioList[10]
 start questionary -> gpioList[11]

 Outputs:

 State LED -> gpioList[12]
 State LED (reserved) -> gpioList[13]


 -->> these will stay constant when using different I/O Pins

****************************************************************************************************/

GPIO::GPIO(unsigned int _gpioPin, unsigned int _pinMode, std::string _ID)
{

    gpioPin = _gpioPin;
    pinMode = _pinMode;
    ID = _ID;
    state=0;

    //GPIO::init(); -->> Call init() in Constructor to have pinMode() set


    //std::cout << "created instance with ID: " << ID << std::endl;

};

GPIO::~GPIO()
{
    //std::cout << "removed instance: " << ID << std::endl;
}



//---------------------hardware and wiringPi-Library dependent----------------


void GPIO::init()   //init of the GPI/O Port
{
   //pinMode(this->gpioPin,this->pinMode);
}

void GPIO::write(unsigned int digitalValue)
{
    //digitalWrite(this->gpioPin,this->state);
}

unsigned int GPIO::read()
{
   // return digitalRead(this->gpioPin)
   return -1;
}


//---------------------might be useful-----------------------------------------

void GPIO::LED_Toggle()
{
    if(this->state==0)
    {
        this->state=1;
    }
    else if(this->state==1)
    {
        this->state=0;
    }

}

//-----------------------get()-methods----------------------------------------

unsigned int GPIO::getState()
{
    return state;
}

std::string GPIO::getID()
{
    return ID;
}





//-----------------------class usage functions---------------------------------



 unsigned int init_gpio(std::vector<std::unique_ptr<GPIO>> &gpioField){       //generate a list of all GPIO to continue with

    //setting up GPI/O with wiringPi
    // if(wiringPiSetup() == -1)


   if(false) //placeholder
    {
        return -1;
    }


    std::unique_ptr<GPIO> p_fb1(new GPIO(feedback_1, INPUT, "feedback1"));
	std::unique_ptr<GPIO> p_fb2(new GPIO(feedback_2, INPUT, "feedback2"));
    std::unique_ptr<GPIO> p_fb3(new GPIO(feedback_3, INPUT, "feedback3"));
	std::unique_ptr<GPIO> p_fb4(new GPIO(feedback_4, INPUT, "feedback4"));
    std::unique_ptr<GPIO> p_fb5(new GPIO(feedback_5, INPUT, "feedback5"));
	std::unique_ptr<GPIO> p_fb6(new GPIO(feedback_6, INPUT, "feedback6"));
    std::unique_ptr<GPIO> p_fb7(new GPIO(feedback_7, INPUT, "feedback7"));

	std::unique_ptr<GPIO> p_audio_on(new GPIO(audio_on, INPUT, "audio_on"));
    std::unique_ptr<GPIO> p_audio_off(new GPIO(audio_off, INPUT, "audio_off"));

    std::unique_ptr<GPIO> p_yes(new GPIO(user_yes, INPUT, "yes"));
	std::unique_ptr<GPIO> p_no(new GPIO(user_no, INPUT, "no"));

    std::unique_ptr<GPIO> p_start(new GPIO(start_questions, INPUT, "start"));

	std::unique_ptr<GPIO> p_led_0(new GPIO(led_0, OUTPUT, "state_led"));
    std::unique_ptr<GPIO> p_led_1(new GPIO(led_1, OUTPUT)); //unnamed

    //append Feedback GPI/O
	gpioField.push_back(std::move(p_fb1));
    gpioField.push_back(std::move(p_fb2));
    gpioField.push_back(std::move(p_fb3));
    gpioField.push_back(std::move(p_fb4));
    gpioField.push_back(std::move(p_fb5));
    gpioField.push_back(std::move(p_fb6));
    gpioField.push_back(std::move(p_fb7));

    //append Other Controls GPI/O
    gpioField.push_back(std::move(p_audio_on));
    gpioField.push_back(std::move(p_audio_off));
    gpioField.push_back(std::move(p_yes));
    gpioField.push_back(std::move(p_no));
    gpioField.push_back(std::move(p_start));

    //append LED GPI/O
    gpioField.push_back(std::move(p_led_0));
    gpioField.push_back(std::move(p_led_1));


    return 0;

}
