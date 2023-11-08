#ifndef ERRORS_HPP
#define ERRORS_HPP

#include "Ui.hpp"
#include "Init.hpp"

enum Errors
{
    OVERPRESSURE,
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
};


#endif