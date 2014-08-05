/*
 * Ultrasonic_Suli.cpp
 * A library for ultrasonic ranger
 *
 * Copyright (c) 2012 seeed technology inc.
 * Website    : www.seeed.cc
 * Author     : jacobyan
 * Create Time: AUG,2014
 * Change Log :
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "Ultrasonic_Suli.h"



IO_T 	ioUltrasonic;
PIN_T 	pinUltrasonic;

void Ultrasonic_init(int pin)
{
	pinUltrasonic = pin;
	suli_pin_init(&ioUltrasonic,pinUltrasonic);
}



/*The measured distance from the range 0 to 400 Centimeters*/
long MeasureInCentimeters(void)
{
	
	suli_pin_dir(&ioUltrasonic,HAL_PIN_OUTPUT);
	suli_pin_write(&ioUltrasonic,HAL_PIN_LOW);
	suli_delay_ms(2);
	suli_pin_write(&ioUltrasonic,HAL_PIN_HIGH);
	suli_delay_ms(5);
	suli_pin_write(&ioUltrasonic,HAL_PIN_LOW);
	suli_pin_dir(&ioUltrasonic,HAL_PIN_INPUT);
	long duration;
	duration=suli_pulse_in(&ioUltrasonic,HAL_PIN_HIGH,10000);
	long RangeInCentimeters;
	RangeInCentimeters = duration/29/2;
	return RangeInCentimeters;
}




/*The measured distance from the range 0 to 157 Inches*/
long MeasureInInches(void)
{
	suli_pin_dir(&ioUltrasonic,HAL_PIN_OUTPUT);
	suli_pin_write(&ioUltrasonic,HAL_PIN_LOW);
	suli_delay_ms(2);
	suli_pin_write(&ioUltrasonic,HAL_PIN_HIGH);
	suli_delay_ms(5);
	suli_pin_write(&ioUltrasonic,HAL_PIN_LOW);
	suli_pin_dir(&ioUltrasonic,HAL_PIN_INPUT);
	long duration;
	duration=suli_pulse_in(&ioUltrasonic,HAL_PIN_HIGH,10000);
	long RangeInInches;
	RangeInInches = duration/74/2;
	return RangeInInches;
}