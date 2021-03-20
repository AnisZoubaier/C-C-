#include <iostream>
#include "inputPanel.hpp"


int main(){

    std::cout << "starting" << std::endl;

    InputPanel newPanel;
    newPanel.init();

    newPanel.listAllPins();


    //newPanel.gpioList[7]->setState(1);

    for(int j = 0;j <= 100;j++)
    {
        newPanel.checkPressed();
        newPanel.restore();

        if(j == 20)
        {
           // newPanel.gpioList[3]->setState(1);
        }
        if(j == 25)
        {
          //  newPanel.gpioList[3]->setState(0);
        }
    }

    std::cout << "finished" << std::endl;


    //std::cout << idCheck << std::endl;

    return 0;
}
