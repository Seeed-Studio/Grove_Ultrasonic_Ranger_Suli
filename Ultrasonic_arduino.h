/***************************************************************************/	
//	Function: Header file for Ultrasonic Ranger
//	Hardware: Grove - Ultrasonic Ranger
//	Arduino IDE: Arduino-1.0
//	Author:	 LG		
//	Date: 	 Jan 17,2013
//	Version: v1.0 modified by FrankieChu
//	by www.seeedstudio.com
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
/*****************************************************************************/

#ifndef __Ultrasonic_arduino_H__
#define __Ultrasonic_arduino_H__

#include "Arduino.h"

class Ultrasonic
{
	public:
		Ultrasonic(int pin)
		{
			_pin = pin;
		}
		
		
		
		
		long MeasureInCentimeters(void)
			{
				pinMode(_pin, OUTPUT);
				digitalWrite(_pin, LOW);
				delayMicroseconds(2);
				digitalWrite(_pin, HIGH);
				delayMicroseconds(5);
				digitalWrite(_pin,LOW);
				pinMode(_pin,INPUT);
				long duration;
				duration = pulseIn(_pin,HIGH);
				long RangeInCentimeters;
				RangeInCentimeters = duration/29/2;
				return RangeInCentimeters;
			}		
		
		
		
		
		long MeasureInInches(void)
			{
				pinMode(_pin, OUTPUT);
				digitalWrite(_pin, LOW);
				delayMicroseconds(2);
				digitalWrite(_pin, HIGH);
				delayMicroseconds(5);
				digitalWrite(_pin,LOW);
				pinMode(_pin,INPUT);
				long duration;
				duration = pulseIn(_pin,HIGH);
				long RangeInInches;
				RangeInInches = duration/74/2;
				return RangeInInches;
			}		
		
		
		
	private:
		int _pin;//pin number of Arduino that is connected with SIG pin of Ultrasonic Ranger.
};















#endif
