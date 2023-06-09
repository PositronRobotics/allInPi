/**
 * @file       BlynkSimpleTinyGSM.h
 * @author     Volodymyr Shymanskyy
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2015 Volodymyr Shymanskyy
 * @date       Nov 2016
 * @brief
 *
 */

#ifndef BlynkSimpleTinyGSM_h
#define BlynkSimpleTinyGSM_h

#include <Adapters/BlynkGsmClient.h>

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_BLYNK)
  static BlynkArduinoClient _blynkTransport;
  BlynkSIM Blynk(_blynkTransport);
#else
  extern BlynkSIM Blynk;
#endif

#include <BlynkWidgets.h>

#endif
