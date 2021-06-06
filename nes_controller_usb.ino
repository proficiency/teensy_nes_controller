#include "controller.h"

Controller controller( 5, 4, 6 );

void setup( )
{
    Joystick.useManualSend( true );
    controller.setup( );
}

void loop( )
{
    controller.think( );

    int16_t hat_angle = -1;

    const bool* pressed = controller.buttons( );

    if ( pressed[PRESS_UP] )
    {
        hat_angle = 0;

        if ( pressed[PRESS_LEFT] )
            hat_angle = 315;

        else if ( pressed[PRESS_RIGHT] )
            hat_angle = 35;
    }

    else if ( pressed[PRESS_DOWN] )
    {
        hat_angle = 180;

        if ( pressed[PRESS_LEFT] )
            hat_angle = 215;

        else if ( pressed[PRESS_RIGHT] )
            hat_angle = 145;
    }

    else if ( pressed[PRESS_RIGHT] )
        hat_angle = 90;

    else if ( pressed[PRESS_LEFT] )
        hat_angle = 270;

    Joystick.hat( hat_angle );

    for ( uint8_t i = 0; i < PRESS_UP; ++i )
        Joystick.button( i + 1, pressed[i] );

    Joystick.send_now( );
}