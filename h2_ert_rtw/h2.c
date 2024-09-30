/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: h2.c
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

#include "h2.h"
#include "rtwtypes.h"
#include "h2_private.h"

/* Named constants for Chart: '<S1>/Chart' */
#define h2_IN_Ambos                    ((uint8_T)1U)
#define h2_IN_Consumo                  ((uint8_T)2U)
#define h2_IN_Consumo_a                ((uint8_T)1U)
#define h2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define h2_IN_Ninguno                  ((uint8_T)3U)
#define h2_IN_Produccion               ((uint8_T)4U)
#define h2_IN_Produccion_m             ((uint8_T)2U)

/* Named constants for Chart: '<Root>/Supervisor' */
#define h2_IN_Deshabilitado            ((uint8_T)1U)
#define h2_IN_Habilitado               ((uint8_T)2U)

/* Block signals (default storage) */
B_h2_T h2_B;

/* Block states (default storage) */
DW_h2_T h2_DW;

/* Real-time model */
static RT_MODEL_h2_T h2_M_;
RT_MODEL_h2_T *const h2_M = &h2_M_;

/* Model step function */
void h2_step(void)
{
  real_T GainEstanque;
  real_T GainPDisponible;
  real_T GainSoC;
  real_T rtb_Product;
  real_T rtb_Product1;
  int32_T rtb_Consumo;
  int32_T rtb_Produccion;

  /* Chart: '<Root>/Supervisor' incorporates:
   *  DiscreteIntegrator: '<S2>/Int_Estanque'
   *  DiscreteIntegrator: '<S2>/Int_SoC'
   */
  if (h2_DW.is_active_c3_h2 == 0U) {
    h2_DW.is_active_c3_h2 = 1U;
    h2_DW.is_Produccion = h2_IN_Deshabilitado;
    rtb_Produccion = 0;
    h2_DW.is_Consumo = h2_IN_Deshabilitado;
    rtb_Consumo = 0;
  } else {
    if (h2_DW.is_Produccion == h2_IN_Deshabilitado) {
      rtb_Produccion = 0;
      if ((h2_DW.Int_SoC_DSTATE > 0.85) && (h2_DW.Int_Estanque_DSTATE < 35.0)) {
        h2_DW.is_Produccion = h2_IN_Habilitado;
        rtb_Produccion = 1;
      }
    } else {
      /* case IN_Habilitado: */
      rtb_Produccion = 1;
      if ((h2_DW.Int_SoC_DSTATE < 0.5) || (h2_DW.Int_Estanque_DSTATE >= 35.0)) {
        h2_DW.is_Produccion = h2_IN_Deshabilitado;
        rtb_Produccion = 0;
      }
    }

    if (h2_DW.is_Consumo == h2_IN_Deshabilitado) {
      rtb_Consumo = 0;
      if (h2_DW.Int_Estanque_DSTATE >= 7.0) {
        h2_DW.is_Consumo = h2_IN_Habilitado;
        rtb_Consumo = 1;
      }
    } else {
      /* case IN_Habilitado: */
      rtb_Consumo = 1;
      if (h2_DW.Int_Estanque_DSTATE < 4.0) {
        h2_DW.is_Consumo = h2_IN_Deshabilitado;
        rtb_Consumo = 0;
      }
    }
  }

  /* End of Chart: '<Root>/Supervisor' */

  /* Chart: '<S1>/Chart' incorporates:
   *  DiscreteIntegrator: '<S2>/Int_PDisponible'
   */
  if (h2_DW.is_active_c1_h2 == 0U) {
    h2_DW.is_active_c1_h2 = 1U;
    h2_DW.is_c1_h2 = h2_IN_Ninguno;
    h2_B.Produccion = 0.0;
    h2_B.Consumo = 0.0;
  } else {
    switch (h2_DW.is_c1_h2) {
     case h2_IN_Ambos:
      if ((rtb_Produccion != 1) || (rtb_Consumo != 1)) {
        h2_DW.is_Ambos = h2_IN_NO_ACTIVE_CHILD;
        h2_DW.is_c1_h2 = h2_IN_Ninguno;
        h2_B.Produccion = 0.0;
        h2_B.Consumo = 0.0;
      } else if (h2_DW.is_Ambos == h2_IN_Consumo_a) {
        h2_B.Produccion = 0.0;
        h2_B.Consumo = 1.0;
        if (h2_DW.Int_PDisponible_DSTATE > 115.0) {
          h2_DW.is_Ambos = h2_IN_Produccion_m;
          h2_B.Produccion = 1.0;
          h2_B.Consumo = 0.0;
        }
      } else {
        /* case IN_Produccion: */
        h2_B.Produccion = 1.0;
        h2_B.Consumo = 0.0;
        if (h2_DW.Int_PDisponible_DSTATE < 105.0) {
          h2_DW.is_Ambos = h2_IN_Consumo_a;
          h2_B.Produccion = 0.0;
          h2_B.Consumo = 1.0;
        }
      }
      break;

     case h2_IN_Consumo:
      h2_B.Consumo = 1.0;
      if ((rtb_Produccion == 1) || (rtb_Consumo != 1)) {
        h2_DW.is_c1_h2 = h2_IN_Ninguno;
        h2_B.Produccion = 0.0;
        h2_B.Consumo = 0.0;
      }
      break;

     case h2_IN_Ninguno:
      h2_B.Produccion = 0.0;
      h2_B.Consumo = 0.0;
      if ((rtb_Produccion == 1) && (rtb_Consumo == 1)) {
        h2_DW.is_c1_h2 = h2_IN_Ambos;
        h2_DW.is_Ambos = h2_IN_Produccion_m;
        h2_B.Produccion = 1.0;
      } else if (rtb_Produccion == 1) {
        h2_DW.is_c1_h2 = h2_IN_Produccion;
        h2_B.Produccion = 1.0;
      } else if (rtb_Consumo == 1) {
        h2_DW.is_c1_h2 = h2_IN_Consumo;
        h2_B.Consumo = 1.0;
      }
      break;

     default:
      /* case IN_Produccion: */
      h2_B.Produccion = 1.0;
      if ((rtb_Consumo == 1) || (rtb_Produccion != 1)) {
        h2_DW.is_c1_h2 = h2_IN_Ninguno;
        h2_B.Produccion = 0.0;
        h2_B.Consumo = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* Product: '<S1>/Product' incorporates:
   *  Constant: '<S1>/Obj_Estanque'
   *  DiscreteIntegrator: '<S2>/Int_Estanque'
   *  Gain: '<S1>/Gain'
   *  RelationalOperator: '<S1>/GreaterThan'
   */
  rtb_Product = (real_T)(h2_DW.Int_Estanque_DSTATE < 30.0 ? 200 : 0) * 0.5 *
    h2_B.Produccion;

  /* Saturate: '<S46>/Saturation' incorporates:
   *  Constant: '<S1>/Obj_SoC'
   *  DiscreteIntegrator: '<S2>/Int_SoC'
   *  Sum: '<S1>/Subtract1'
   */
  if (0.9 - h2_DW.Int_SoC_DSTATE > 15.0) {
    rtb_Product1 = 15.0;
  } else if (0.9 - h2_DW.Int_SoC_DSTATE < 0.0) {
    rtb_Product1 = 0.0;
  } else {
    rtb_Product1 = 0.9 - h2_DW.Int_SoC_DSTATE;
  }

  /* Product: '<S1>/Product1' incorporates:
   *  Saturate: '<S46>/Saturation'
   */
  rtb_Product1 *= h2_B.Consumo;

  /* MATLAB Function: '<S2>/Deltas' */
  GainEstanque = 0.0;
  GainSoC = 0.0;
  GainPDisponible = 0.0;
  if (rtb_Product > 0.0) {
    GainEstanque = 0.2;
  }

  if (rtb_Product >= 2.0) {
    GainSoC = -0.01;
    GainPDisponible = -0.1;
  }

  if (rtb_Product1 > 0.0) {
    GainEstanque -= rtb_Product1 * 0.1;
    GainSoC += rtb_Product1 * 0.01;
    GainPDisponible += rtb_Product1 * 0.1;
  }

  /* Update for DiscreteIntegrator: '<S2>/Int_Estanque' incorporates:
   *  MATLAB Function: '<S2>/Deltas'
   */
  h2_DW.Int_Estanque_DSTATE += 20.0 * GainEstanque;

  /* Update for DiscreteIntegrator: '<S2>/Int_SoC' incorporates:
   *  MATLAB Function: '<S2>/Deltas'
   */
  h2_DW.Int_SoC_DSTATE += 20.0 * GainSoC;

  /* Update for DiscreteIntegrator: '<S2>/Int_PDisponible' incorporates:
   *  MATLAB Function: '<S2>/Deltas'
   */
  h2_DW.Int_PDisponible_DSTATE += 20.0 * GainPDisponible;
}

/* Model initialize function */
void h2_initialize(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S2>/Int_Estanque' */
  h2_DW.Int_Estanque_DSTATE = h2_ConstB.Estanqueinicial;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Int_SoC' */
  h2_DW.Int_SoC_DSTATE = h2_ConstB.SoCinicial;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Int_PDisponible' */
  h2_DW.Int_PDisponible_DSTATE = h2_ConstB.PDisponibleinicial;
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
