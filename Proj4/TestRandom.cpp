#include "Random.h"
#include <iostream>
using namespace std;

    // Test program
int main( )
{

	int stopper;

    Random r( 1 );

    for( int i = 0; i < 20; i++ )
        cout << r.randomInt( ) << endl;

	cin >> stopper;

    return 0;
}