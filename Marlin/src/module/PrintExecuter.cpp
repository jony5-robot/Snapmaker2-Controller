#include "../inc/MarlinConfig.h"

#include "../Marlin.h"
#include "../module/temperature.h"
#include "../module/configuration_store.h"
#include "CNCExecuter.h"
#include "CanBus.h"

/**
 * EStepperInit:E stepper control io initialze
 */
void PrintExecuter::EStepperInit()
{
  #if HAS_E0_DIR
    SET_OUTPUT(E0_DIR_PIN);
  #endif
  #if HAS_E1_DIR
    SET_OUTPUT(E1_DIR_PIN);
  #endif
  #if HAS_E2_DIR
    SET_OUTPUT(E2_DIR_PIN);
  #endif
  #if HAS_E3_DIR
    SET_OUTPUT(E3_DIR_PIN);
  #endif
  #if HAS_E4_DIR
    SET_OUTPUT(E4_DIR_PIN);
  #endif
  #if HAS_E5_DIR
    SET_OUTPUT(E5_DIR_PIN);
  #endif

  #if HAS_E0_ENABLE
    SET_OUTPUT(E0_ENABLE_PIN);
    if (!E_ENABLE_ON) WRITE(E0_ENABLE_PIN, HIGH);
  #endif
  #if HAS_E1_ENABLE
    SET_OUTPUT(E1_ENABLE_PIN);
    if (!E_ENABLE_ON) WRITE(E1_ENABLE_PIN, HIGH);
  #endif
  #if HAS_E2_ENABLE
    SET_OUTPUT(E2_ENABLE_PIN);
    if (!E_ENABLE_ON) WRITE(E2_ENABLE_PIN, HIGH);
  #endif
  #if HAS_E3_ENABLE
    SET_OUTPUT(E3_ENABLE_PIN);
    if (!E_ENABLE_ON) WRITE(E3_ENABLE_PIN, HIGH);
  #endif
  #if HAS_E4_ENABLE
    SET_OUTPUT(E4_ENABLE_PIN);
    if (!E_ENABLE_ON) WRITE(E4_ENABLE_PIN, HIGH);
  #endif
  #if HAS_E5_ENABLE
    SET_OUTPUT(E5_ENABLE_PIN);
    if (!E_ENABLE_ON) WRITE(E5_ENABLE_PIN, HIGH);
  #endif

  SET_OUTPUT(E0_STEP_PIN);
}

#if ENABLED(EXECUTER_CANBUS_SUPPORT)

/**
 * Init
 */
void PrintExecuter::Init()
{
  EStepperInit();
}

#else

/**
 * Init
 */
void PrintExecuter::Init()
{
  EStepperInit();

  #if HAS_HEATER_0
    OUT_WRITE(HEATER_0_PIN, HEATER_0_INVERTING);
  #endif
  #if HAS_HEATER_1
    OUT_WRITE(HEATER_1_PIN, HEATER_1_INVERTING);
  #endif
  #if HAS_HEATER_2
    OUT_WRITE(HEATER_2_PIN, HEATER_2_INVERTING);
  #endif
  #if HAS_HEATER_3
    OUT_WRITE(HEATER_3_PIN, HEATER_3_INVERTING);
  #endif
  #if HAS_HEATER_4
    OUT_WRITE(HEATER_4_PIN, HEATER_4_INVERTING);
  #endif
  #if HAS_HEATER_5
    OUT_WRITE(HEATER_5_PIN, HEATER_5_INVERTING);
  #endif
  #if HAS_FAN0
    INIT_FAN_PIN(FAN_PIN);
  #endif
  #if HAS_FAN1
    INIT_FAN_PIN(FAN1_PIN);
  #endif
  #if HAS_FAN2
    INIT_FAN_PIN(FAN2_PIN);
  #endif
  #if ENABLED(USE_CONTROLLER_FAN)
    INIT_FAN_PIN(CONTROLLER_FAN_PIN);
  #endif
}

#endif // ENABLED EXECUTER_CANBUS_SUPPORT