/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: h2.h
 *
 * Code generated for Simulink model 'h2'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Sep 29 18:38:11 2024
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

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output;                       /* '<Root>/Output' */
} ExtY_h2_T;

/* Real-time Model Data Structure */
struct tag_RTM_h2_T {
  const char_T * volatile errorStatus;
};

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_h2_T h2_Y;

/* Model entry point functions */
extern void h2_initialize(void);
extern void h2_step(void);
extern void h2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_h2_T *const h2_M;

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
 */
#endif                                 /* h2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
