/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: h2.c
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

#include "h2.h"

/* External outputs (root outports fed by signals with default storage) */
ExtY_h2_T h2_Y;

/* Real-time model */
static RT_MODEL_h2_T h2_M_;
RT_MODEL_h2_T *const h2_M = &h2_M_;

/* Model step function */
void h2_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void h2_initialize(void)
{
  /* ConstCode for Outport: '<Root>/Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  h2_Y.Output = 1.0;
}

/* Model terminate function */
void h2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
