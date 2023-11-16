#ifndef ERRORS_HPP
#define ERRORS_HPP

#include "Init.hpp"

enum Errors
{
    OVERPRESSURE,
    UNDERPRESSURE,
    OVERHEAT,
    NONE
};

class ErrorHandler
{
    private:

    public:
        ErrorHandler();

        ~ErrorHandler();

        // //TODO: handleOverpressure
        // void HandleOverpressure();

        //TODO: handleOverheat
        void HandleOverheat();
        void HandleUnderPressure();
};


#endif