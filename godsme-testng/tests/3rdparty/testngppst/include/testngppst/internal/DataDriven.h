/**
    TestNG++ is a practical, easy-to-use C/C++ xUnit framework.
    Copyright (C) <2009>  <Arthur Yuan: arthur.ii.yuan@gmail.com>

    TestNG++ is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    TestNG++ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with TestNG++.  If not, see <http://www.gnu.org/licenses/>.
**/

#ifndef __TESTNGPPST_DATA_DRIVEN_H
#define __TESTNGPPST_DATA_DRIVEN_H

#include <sstream>

#include <testngppst/testngppst.h>
#include <testngppst/Any.h>
#include <testngppst/DataDrivenDef.h>
#include <testngppst/internal/Error.h>

TESTNGPPST_NS_START

template <typename Type>
Type castTo
     ( DataProvider* dataProvider
     , unsigned int index
     , unsigned int item)
{
   try
   {
      if(index >= dataProvider->size() || item >= dataProvider->numberOfItems())
      {
          std::ostringstream oss;
          oss << "Out of data provider range : \"" << dataProvider->getName() 
              << "[" << index << "][" << item <<"]\"" 
              << ", max size \"" << dataProvider->getName()
              << "[" << dataProvider->size() << "][" << dataProvider->numberOfItems() << "].";

          throw TESTNGPPST_NS::Error(oss.str());
      }

      return TESTNGPPST_NS::any_cast<Type>(dataProvider->data(index, item));
   }
   catch(TESTNGPPST_NS::empty_any_object)
   {
      std::ostringstream oss;
      oss << "\"" << dataProvider->getName() 
          << "[" << index << "][" << item <<"] = DATA_GROUP("
          << dataProvider->toString(index) << ") \"" 
          << " contains a empty object, probably 'coz it was incorrectly defined.";

      throw TESTNGPPST_NS::Error(oss.str());
   }
   catch(TESTNGPPST_NS::bad_any_cast& except)
   {
      std::ostringstream oss;
      oss << "\"" << dataProvider->getName() 
          << "[" << index << "][" << item <<"] = DATA_GROUP("
          << dataProvider->toString(index) << ")\"" 
          << " contains a data with a mismatched type("
          << except.what() << ").";

      throw TESTNGPPST_NS::Error(oss.str());
   }
}

#define __TESTNGPPST_CAST(m, n) TESTNGPPST_NS::castTo<P##n>(dataProvider, m, n)

//////////////////////////////////////////////////////////////////////
template < typename FixtureClass
         , typename P0 >
void runParameterizedTest
      ( FixtureClass* fixture
      , void (FixtureClass::*test)(P0)
      , DataProvider* dataProvider
      , unsigned int n)
{
   (fixture->*test)
         ( __TESTNGPPST_CAST(n, 0) );
}

//////////////////////////////////////////////////////////////////////
template < typename FixtureClass
         , typename P0
         , typename P1 >
void runParameterizedTest
      ( FixtureClass* fixture
      , void (FixtureClass::*test)(P0, P1)
      , DataProvider* dataProvider
      , unsigned int n)
{
   (fixture->*test)
         ( __TESTNGPPST_CAST(n, 0)
         , __TESTNGPPST_CAST(n, 1)
         );
}

//////////////////////////////////////////////////////////////////////
template < typename FixtureClass
         , typename P0
         , typename P1
         , typename P2>
void runParameterizedTest
      ( FixtureClass* fixture
      , void (FixtureClass::*test)(P0, P1, P2)
      , DataProvider* dataProvider
      , unsigned int n)
{
   (fixture->*test)
         ( __TESTNGPPST_CAST(n, 0)
         , __TESTNGPPST_CAST(n, 1)
         , __TESTNGPPST_CAST(n, 2)
         );
}

//////////////////////////////////////////////////////////////////////
template < typename FixtureClass
         , typename P0
         , typename P1
         , typename P2
         , typename P3 > 
void runParameterizedTest
      ( FixtureClass* fixture
      , void (FixtureClass::*test)(P0, P1, P2, P3)
      , DataProvider* dataProvider
      , unsigned int n)
{
   (fixture->*test)
         ( __TESTNGPPST_CAST(n, 0)
         , __TESTNGPPST_CAST(n, 1)
         , __TESTNGPPST_CAST(n, 2)
         , __TESTNGPPST_CAST(n, 3)
         );
}

//////////////////////////////////////////////////////////////////////
template < typename FixtureClass
         , typename P0
         , typename P1
         , typename P2
         , typename P3 
         , typename P4 > 
void runParameterizedTest
      ( FixtureClass* fixture
      , void (FixtureClass::*test)(P0, P1, P2, P3, P4)
      , DataProvider* dataProvider
      , unsigned int n)
{
   (fixture->*test)
         ( __TESTNGPPST_CAST(n, 0)
         , __TESTNGPPST_CAST(n, 1)
         , __TESTNGPPST_CAST(n, 2)
         , __TESTNGPPST_CAST(n, 3)
         , __TESTNGPPST_CAST(n, 4)
         );
}

//////////////////////////////////////////////////////////////////////
template < typename FixtureClass
         , typename P0
         , typename P1
         , typename P2
         , typename P3 
         , typename P4 
         , typename P5 >
void runParameterizedTest
      ( FixtureClass* fixture
      , void (FixtureClass::*test)(P0, P1, P2, P3, P4, P5)
      , DataProvider* dataProvider
      , unsigned int n)
{
   (fixture->*test)
         ( __TESTNGPPST_CAST(n, 0)
         , __TESTNGPPST_CAST(n, 1)
         , __TESTNGPPST_CAST(n, 2)
         , __TESTNGPPST_CAST(n, 3)
         , __TESTNGPPST_CAST(n, 4)
         , __TESTNGPPST_CAST(n, 5)
         );
}

//////////////////////////////////////////////////////////////////////
template < typename FixtureClass
         , typename P0
         , typename P1
         , typename P2
         , typename P3 
         , typename P4 
         , typename P5
         , typename P6 >
void runParameterizedTest
      ( FixtureClass* fixture
      , void (FixtureClass::*test)(P0, P1, P2, P3, P4, P5, P6)
      , DataProvider* dataProvider
      , unsigned int n)
{
   (fixture->*test)
         ( __TESTNGPPST_CAST(n, 0)
         , __TESTNGPPST_CAST(n, 1)
         , __TESTNGPPST_CAST(n, 2)
         , __TESTNGPPST_CAST(n, 3)
         , __TESTNGPPST_CAST(n, 4)
         , __TESTNGPPST_CAST(n, 5)
         , __TESTNGPPST_CAST(n, 6)
         );
}

//////////////////////////////////////////////////////////////////////
template < typename FixtureClass
         , typename P0
         , typename P1
         , typename P2
         , typename P3 
         , typename P4 
         , typename P5
         , typename P6
         , typename P7 >
void runParameterizedTest
      ( FixtureClass* fixture
      , void (FixtureClass::*test)(P0, P1, P2, P3, P4, P5, P6, P7)
      , DataProvider* dataProvider
      , unsigned int n)
{
   (fixture->*test)
         ( __TESTNGPPST_CAST(n, 0)
         , __TESTNGPPST_CAST(n, 1)
         , __TESTNGPPST_CAST(n, 2)
         , __TESTNGPPST_CAST(n, 3)
         , __TESTNGPPST_CAST(n, 4)
         , __TESTNGPPST_CAST(n, 5)
         , __TESTNGPPST_CAST(n, 6)
         , __TESTNGPPST_CAST(n, 7)
         );
}

//////////////////////////////////////////////////////////////////////
template < typename FixtureClass
         , typename P0
         , typename P1
         , typename P2
         , typename P3 
         , typename P4 
         , typename P5
         , typename P6
         , typename P7
         , typename P8 >
void runParameterizedTest
      ( FixtureClass* fixture
      , void (FixtureClass::*test)(P0, P1, P2, P3, P4, P5, P6, P7, P8)
      , DataProvider* dataProvider
      , unsigned int n)
{
   (fixture->*test)
         ( __TESTNGPPST_CAST(n, 0)
         , __TESTNGPPST_CAST(n, 1)
         , __TESTNGPPST_CAST(n, 2)
         , __TESTNGPPST_CAST(n, 3)
         , __TESTNGPPST_CAST(n, 4)
         , __TESTNGPPST_CAST(n, 5)
         , __TESTNGPPST_CAST(n, 6)
         , __TESTNGPPST_CAST(n, 7)
         , __TESTNGPPST_CAST(n, 8)
         );
}

//////////////////////////////////////////////////////////////////////
template < typename FixtureClass
         , typename P0
         , typename P1
         , typename P2
         , typename P3 
         , typename P4 
         , typename P5
         , typename P6
         , typename P7
         , typename P8
         , typename P9>
void runParameterizedTest
      ( FixtureClass* fixture
      , void (FixtureClass::*test)(P0, P1, P2, P3, P4, P5, P6, P7, P8, P9)
      , DataProvider* dataProvider
      , unsigned int n)
{
   (fixture->*test)
         ( __TESTNGPPST_CAST(n, 0)
         , __TESTNGPPST_CAST(n, 1)
         , __TESTNGPPST_CAST(n, 2)
         , __TESTNGPPST_CAST(n, 3)
         , __TESTNGPPST_CAST(n, 4)
         , __TESTNGPPST_CAST(n, 5)
         , __TESTNGPPST_CAST(n, 6)
         , __TESTNGPPST_CAST(n, 7)
         , __TESTNGPPST_CAST(n, 8)
         , __TESTNGPPST_CAST(n, 9)
         );
}

TESTNGPPST_NS_END

#endif

