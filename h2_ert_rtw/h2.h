/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: h2.h
 *
 * Code generated for Simulink model 'h2'.
 *
 * Model version                  : 1.102
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Sep 29 23:09:57 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef h2_h_
#define h2_h_
#ifndef h2_COMMON_INCLUDES_
#define h2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* h2_COMMON_INCLUDES_ */

#include "h2_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Produccion;                   /* '<S1>/Chart' */
  real_T Consumo;                      /* '<S1>/Chart' */
} B_h2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Int_Estanque_DSTATE;          /* '<S2>/Int_Estanque' */
  real_T Int_SoC_DSTATE;               /* '<S2>/Int_SoC' */
  real_T Int_PDisponible_DSTATE;       /* '<S2>/Int_PDisponible' */
  uint8_T is_active_c3_h2;             /* '<Root>/Supervisor' */
  uint8_T is_Produccion;               /* '<Root>/Supervisor' */
  uint8_T is_Consumo;                  /* '<Root>/Supervisor' */
  uint8_T is_active_c1_h2;             /* '<S1>/Chart' */
  uint8_T is_c1_h2;                    /* '<S1>/Chart' */
  uint8_T is_Ambos;                    /* '<S1>/Chart' */
} DW_h2_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Estanqueinicial;        /* '<S2>/Estanque inicial' */
  const real_T PDisponibleinicial;     /* '<S2>/PDisponible inicial' */
  const real_T SoCinicial;             /* '<S2>/SoC inicial' */
} ConstB_h2_T;

/* Real-time Model Data Structure */
struct tag_RTM_h2_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_h2_T h2_B;

/* Block states (default storage) */
extern DW_h2_T h2_DW;
extern const ConstB_h2_T h2_ConstB;    /* constant block i/o */

/* Model entry point functions */
extern void h2_initialize(void);
extern void h2_step(void);
extern void h2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_h2_T *const h2_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Accion de control' : Unused code path elimination
 * Block '<Root>/Acciones de control permitidas' : Unused code path elimination
 * Block '<Root>/Estados' : Unused code path elimination
 * Block '<S44>/Proportional Gain' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'h2'
 * '<S1>'   : 'h2/Controlador'
 * '<S2>'   : 'h2/Planta'
 * '<S3>'   : 'h2/Supervisor'
 * '<S4>'   : 'h2/Controlador/Chart'
 * '<S5>'   : 'h2/Controlador/Discrete PID Controller1'
 * '<S6>'   : 'h2/Controlador/Discrete PID Controller1/Anti-windup'
 * '<S7>'   : 'h2/Controlador/Discrete PID Controller1/D Gain'
 * '<S8>'   : 'h2/Controlador/Discrete PID Controller1/External Derivative'
 * '<S9>'   : 'h2/Controlador/Discrete PID Controller1/Filter'
 * '<S10>'  : 'h2/Controlador/Discrete PID Controller1/Filter ICs'
 * '<S11>'  : 'h2/Controlador/Discrete PID Controller1/I Gain'
 * '<S12>'  : 'h2/Controlador/Discrete PID Controller1/Ideal P Gain'
 * '<S13>'  : 'h2/Controlador/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S14>'  : 'h2/Controlador/Discrete PID Controller1/Integrator'
 * '<S15>'  : 'h2/Controlador/Discrete PID Controller1/Integrator ICs'
 * '<S16>'  : 'h2/Controlador/Discrete PID Controller1/N Copy'
 * '<S17>'  : 'h2/Controlador/Discrete PID Controller1/N Gain'
 * '<S18>'  : 'h2/Controlador/Discrete PID Controller1/P Copy'
 * '<S19>'  : 'h2/Controlador/Discrete PID Controller1/Parallel P Gain'
 * '<S20>'  : 'h2/Controlador/Discrete PID Controller1/Reset Signal'
 * '<S21>'  : 'h2/Controlador/Discrete PID Controller1/Saturation'
 * '<S22>'  : 'h2/Controlador/Discrete PID Controller1/Saturation Fdbk'
 * '<S23>'  : 'h2/Controlador/Discrete PID Controller1/Sum'
 * '<S24>'  : 'h2/Controlador/Discrete PID Controller1/Sum Fdbk'
 * '<S25>'  : 'h2/Controlador/Discrete PID Controller1/Tracking Mode'
 * '<S26>'  : 'h2/Controlador/Discrete PID Controller1/Tracking Mode Sum'
 * '<S27>'  : 'h2/Controlador/Discrete PID Controller1/Tsamp - Integral'
 * '<S28>'  : 'h2/Controlador/Discrete PID Controller1/Tsamp - Ngain'
 * '<S29>'  : 'h2/Controlador/Discrete PID Controller1/postSat Signal'
 * '<S30>'  : 'h2/Controlador/Discrete PID Controller1/preSat Signal'
 * '<S31>'  : 'h2/Controlador/Discrete PID Controller1/Anti-windup/Disabled'
 * '<S32>'  : 'h2/Controlador/Discrete PID Controller1/D Gain/Disabled'
 * '<S33>'  : 'h2/Controlador/Discrete PID Controller1/External Derivative/Disabled'
 * '<S34>'  : 'h2/Controlador/Discrete PID Controller1/Filter/Disabled'
 * '<S35>'  : 'h2/Controlador/Discrete PID Controller1/Filter ICs/Disabled'
 * '<S36>'  : 'h2/Controlador/Discrete PID Controller1/I Gain/Disabled'
 * '<S37>'  : 'h2/Controlador/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S38>'  : 'h2/Controlador/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S39>'  : 'h2/Controlador/Discrete PID Controller1/Integrator/Disabled'
 * '<S40>'  : 'h2/Controlador/Discrete PID Controller1/Integrator ICs/Disabled'
 * '<S41>'  : 'h2/Controlador/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S42>'  : 'h2/Controlador/Discrete PID Controller1/N Gain/Disabled'
 * '<S43>'  : 'h2/Controlador/Discrete PID Controller1/P Copy/Disabled'
 * '<S44>'  : 'h2/Controlador/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S45>'  : 'h2/Controlador/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S46>'  : 'h2/Controlador/Discrete PID Controller1/Saturation/Enabled'
 * '<S47>'  : 'h2/Controlador/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S48>'  : 'h2/Controlador/Discrete PID Controller1/Sum/Passthrough_P'
 * '<S49>'  : 'h2/Controlador/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S50>'  : 'h2/Controlador/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S51>'  : 'h2/Controlador/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S52>'  : 'h2/Controlador/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S53>'  : 'h2/Controlador/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S54>'  : 'h2/Controlador/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S55>'  : 'h2/Controlador/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S56>'  : 'h2/Planta/Deltas'
 */
#endif                                 /* h2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
