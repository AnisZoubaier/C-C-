#include "inputPanel.hpp"


InputPanel::InputPanel(){

    feedback_scalar=0; //no feedback given
    flag_questionlist_start=false;
    answer_no=false;
    answer_yes=false;

    std::cout << "panel created" << std::endl;

}

unsigned int InputPanel::init()
{
if(false) //placeholder
    {
        return -1;
    }


    std::unique_ptr<GPIO> p_fb1(new GPIO(feedback_1_pin, INPUT, "feedback1"));
	std::unique_ptr<GPIO> p_fb2(new GPIO(feedback_2_pin, INPUT, "feedback2"));
    std::unique_ptr<GPIO> p_fb3(new GPIO(feedback_3_pin, INPUT, "feedback3"));
	std::unique_ptr<GPIO> p_fb4(new GPIO(feedback_4_pin, INPUT, "feedback4"));
    std::unique_ptr<GPIO> p_fb5(new GPIO(feedback_5_pin, INPUT, "feedback5"));
	std::unique_ptr<GPIO> p_fb6(new GPIO(feedback_6_pin, INPUT, "feedback6"));
    std::unique_ptr<GPIO> p_fb7(new GPIO(feedback_7_pin, INPUT, "feedback7"));

	std::unique_ptr<GPIO> p_audio_on(new GPIO(audio_on_pin, INPUT, "audio_on"));
    std::unique_ptr<GPIO> p_audio_off(new GPIO(audio_off_pin, INPUT, "audio_off"));

    std::unique_ptr<GPIO> p_yes(new GPIO(user_yes_pin, INPUT, "yes"));
	std::unique_ptr<GPIO> p_no(new GPIO(user_no_pin, INPUT, "no"));

    std::unique_ptr<GPIO> p_start(new GPIO(start_questions_pin, INPUT, "start"));

	std::unique_ptr<GPIO> p_led_0(new GPIO(led_0_pin, OUTPUT, "state_led"));
    std::unique_ptr<GPIO> p_led_1(new GPIO(led_1_pin, OUTPUT)); //unnamed

    //append Feedback GPI/O
	this->gpioList.push_back(std::move(p_fb1));
    this->gpioList.push_back(std::move(p_fb2));
    this->gpioList.push_back(std::move(p_fb3));
    this->gpioList.push_back(std::move(p_fb4));
    this->gpioList.push_back(std::move(p_fb5));
    this->gpioList.push_back(std::move(p_fb6));
    this->gpioList.push_back(std::move(p_fb7));

    //append Other Controls GPI/O
    this->gpioList.push_back(std::move(p_audio_on));
    this->gpioList.push_back(std::move(p_audio_off));
    this->gpioList.push_back(std::move(p_yes));
    this->gpioList.push_back(std::move(p_no));
    this->gpioList.push_back(std::move(p_start));

    //append LED GPI/O
    this->gpioList.push_back(std::move(p_led_0));
    this->gpioList.push_back(std::move(p_led_1));


    return 0;
}

void InputPanel::listAllPins()
{
    for(std::vector<std::unique_ptr<GPIO>>::iterator it = gpioList.begin() ; it != gpioList.end() ; ++it )
    {
        std::string localID = (*it)->getID();
        std::cout << "Pin:" << (*it)->gpioPin << ", ID: " << localID << std::endl;
    }


}

void InputPanel::checkPressed()
{
    for(int i = feedback1 ; i <= feedback7 ; i++ )    //feedback-buttons
    {
        if(this->gpioList[i]->read() == 1)
        {
            feedback_scalar = i+1;
            std::cout << "Pin:" <<  this->gpioList[i]->getID() << "pressed!" << std::endl;
        }

    }

    if(this->gpioList[audioOn]->read() == 1)      {/*audio_on*/}
    else if(this->gpioList[audioOff]->read() == 1) {/*audio_off*/}
    else if(this->gpioList[userYes]->read() == 1) {answer_yes = true;}
    else if(this->gpioList[userNo]->read() == 1){answer_no = true;}
    else if(this->gpioList[startQuestions]->read() == 1){flag_questionlist_start = true;}
    else {std::cout << "no buttons pressed" << std::endl;}
}

void InputPanel::toggle_state_LED()
{

    this->gpioList[stateLED]->LED_Toggle();

}

void InputPanel::restore()
{
    feedback_scalar=0; //no feedback given
    flag_questionlist_start=false;
    answer_no=false;
    answer_yes=false;

    std::cout << "restored!" << std::endl;
}
