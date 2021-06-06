// NES controller library
// https://wiki.nesdev.com/w/index.php/Controller_port_pinout
// https://wiki.nesdev.com/w/index.php/Standard_controller
// https://wiki.nesdev.com/w/index.php/Controller_reading

enum Press
{
    PRESS_A = 0,
    PRESS_B,
    PRESS_SELECT,
    PRESS_START,
    PRESS_UP,
    PRESS_DOWN,
    PRESS_LEFT,
    PRESS_RIGHT,
    PRESS_MAX,
};

class Controller
{
public:
    Controller( const uint8_t latch, const uint8_t clock, const uint8_t data ) :
        m_latch( latch ), m_clock( clock ), m_data( data )
    {
    }

    void setup( )
    {
        pinMode( m_latch, OUTPUT );
        pinMode( m_clock, OUTPUT );
        pinMode( m_data, INPUT );

        clear( );
    }

    void think( )
    {
        digitalWrite( m_latch, LOW );
        digitalWrite( m_clock, LOW );
        digitalWrite( m_latch, HIGH );

        digitalWrite( m_latch, LOW );

        m_latched = true;

        clear( );

        for ( uint8_t i = 0; i < 8; ++i )
        {
            poll( i );
            digitalWrite( m_clock, HIGH );

            digitalWrite( m_clock, LOW );
        }

        m_latched = false;
    }

    bool pressed( const uint8_t button )
    {
        return ( bool ) m_buttons[button];
    }

    bool latched( )
    {
        return m_latched;
    }

    bool* buttons( )
    {
        return m_buttons;
    }

private:
    void poll( uint8_t bit_pos )
    {
        m_buttons[bit_pos] = digitalRead( m_data ) == LOW;
    }

    void clear( )
    {
        memset( m_buttons, 0, sizeof( m_buttons ) );
    }

    bool m_buttons[PRESS_MAX];
    bool m_latched;

    // I/O pins
    uint8_t m_latch, m_clock, m_data;
};