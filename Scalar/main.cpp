/*
 * Program to demonstrate SAE
 *
 * @author : Vishnu Tej MP(vm9069)
 *
 */

#include "SAE.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{

   cin.exceptions( std::istream::eofbit );

   while ( true )
   {
      float a, b, c, d;

      try
      {
         cin >> a >> b >> c >> d;
      }
      catch ( std::istream::failure &e )
      {
         break;
      }

      SAE v1( a, b );
      SAE v2( c, d );
      cout << "        v1: " << v1 << endl;
      cout << "        v2: " << v2 << endl;

      SAE mul = v1 * v2;
      SAE mul2 = mul * v2;
      SAE add = v1 + v2;
      SAE sub = v1 - v2;
      SAE div = mul / v2;

      cout << "    Divide: " << div << endl;
      cout << "  Multiply: " << mul << endl;
      cout << "       Add: " << add << endl;
      cout << "  Subtract: " << sub << endl;
      cout << "Multiply 2: " << mul2 << endl;

      SAE scalarMultiply = v1 * c;
      cout << "Scalar Multiply: " << scalarMultiply << endl;

      SAE scalarDivide;
      try
      {
         scalarDivide = v1 / c;
      }
      catch ( overflow_error &e )
      {
         cerr << e.what() << endl;
      }
      cout << "  Scalar Divide: " << scalarDivide << endl;
      cout << endl;

      SAE inlineMultiply = v1;
      inlineMultiply *= v2;

      SAE inlineAdd = v1;
      inlineAdd += v2;

      SAE inlineSubtract = v1;
      inlineSubtract -= v2;


      cout << endl;
      cout << "Inline Multiply: " << inlineMultiply << endl;
      cout << "     Inline Add: " << inlineAdd << endl;
      cout << "Inline Subtract: " << inlineSubtract << endl;

      try
      {
         SAE divbad = v1/v2;
      }
      catch ( underflow_error &e )
      {
         cerr << e.what() << endl;
      }


      cout << endl;
   }
}
