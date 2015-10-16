#include "neptune.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Neptune::Neptune()
    :   Planet( ":/texture/neptune.jpg" )
{
    transform.setScale( .75f );
}

//
// OVERRIDDEN FUNCTIONS
// 

void Neptune::update()
{
    transform.rotate( 1.0f, 0, 1, 0 );
}