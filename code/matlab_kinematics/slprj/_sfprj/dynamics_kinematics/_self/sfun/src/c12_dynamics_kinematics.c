/* Include files */

#include "blascompat32.h"
#include "dynamics_kinematics_sfun.h"
#include "c12_dynamics_kinematics.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "dynamics_kinematics_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c12_debug_family_names[5] = { "nargin", "nargout", "ee_pos",
  "ee_ang", "ref" };

/* Function Declarations */
static void initialize_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance);
static void initialize_params_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance);
static void enable_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance);
static void disable_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance);
static void c12_update_debugger_state_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance);
static void set_sim_state_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance, const mxArray *c12_st);
static void finalize_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance);
static void sf_c12_dynamics_kinematics(SFc12_dynamics_kinematicsInstanceStruct
  *chartInstance);
static void initSimStructsc12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_emlrt_marshallIn(SFc12_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c12_ref, const char_T *c12_identifier);
static real_T c12_b_emlrt_marshallIn(SFc12_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_c_emlrt_marshallIn(SFc12_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static uint8_T c12_d_emlrt_marshallIn(SFc12_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_dynamics_kinematics, const
  char_T *c12_identifier);
static uint8_T c12_e_emlrt_marshallIn(SFc12_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void init_dsm_address_info(SFc12_dynamics_kinematicsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance)
{
  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c12_is_active_c12_dynamics_kinematics = 0U;
}

static void initialize_params_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance)
{
}

static void enable_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c12_update_debugger_state_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  real_T c12_hoistedGlobal;
  real_T c12_u;
  const mxArray *c12_b_y = NULL;
  uint8_T c12_b_hoistedGlobal;
  uint8_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  real_T *c12_ref;
  c12_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellarray(2), FALSE);
  c12_hoistedGlobal = *c12_ref;
  c12_u = c12_hoistedGlobal;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_b_hoistedGlobal = chartInstance->c12_is_active_c12_dynamics_kinematics;
  c12_b_u = c12_b_hoistedGlobal;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c12_y, 1, c12_c_y);
  sf_mex_assign(&c12_st, c12_y, FALSE);
  return c12_st;
}

static void set_sim_state_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance, const mxArray *c12_st)
{
  const mxArray *c12_u;
  real_T *c12_ref;
  c12_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c12_doneDoubleBufferReInit = TRUE;
  c12_u = sf_mex_dup(c12_st);
  *c12_ref = c12_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u,
    0)), "ref");
  chartInstance->c12_is_active_c12_dynamics_kinematics = c12_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 1)),
     "is_active_c12_dynamics_kinematics");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_dynamics_kinematics(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance)
{
}

static void sf_c12_dynamics_kinematics(SFc12_dynamics_kinematicsInstanceStruct
  *chartInstance)
{
  int32_T c12_i0;
  int32_T c12_i1;
  int32_T c12_i2;
  real_T c12_ee_pos[3];
  int32_T c12_i3;
  real_T c12_ee_ang[3];
  uint32_T c12_debug_family_var_map[5];
  real_T c12_nargin = 2.0;
  real_T c12_nargout = 1.0;
  real_T c12_ref;
  real_T c12_x;
  real_T c12_b_x;
  real_T c12_y;
  real_T c12_b;
  real_T c12_b_y;
  real_T c12_a;
  real_T *c12_b_ref;
  real_T (*c12_b_ee_ang)[3];
  real_T (*c12_b_ee_pos)[3];
  boolean_T guard1 = FALSE;
  c12_b_ee_ang = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c12_b_ee_pos = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c12_b_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c12_b_ref, 0U);
  for (c12_i0 = 0; c12_i0 < 3; c12_i0++) {
    _SFD_DATA_RANGE_CHECK((*c12_b_ee_pos)[c12_i0], 1U);
  }

  for (c12_i1 = 0; c12_i1 < 3; c12_i1++) {
    _SFD_DATA_RANGE_CHECK((*c12_b_ee_ang)[c12_i1], 2U);
  }

  chartInstance->c12_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  for (c12_i2 = 0; c12_i2 < 3; c12_i2++) {
    c12_ee_pos[c12_i2] = (*c12_b_ee_pos)[c12_i2];
  }

  for (c12_i3 = 0; c12_i3 < 3; c12_i3++) {
    c12_ee_ang[c12_i3] = (*c12_b_ee_ang)[c12_i3];
  }

  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c12_debug_family_names,
    c12_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c12_nargin, 0U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_nargout, 1U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c12_ee_pos, 2U, c12_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c12_ee_ang, 3U, c12_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c12_ref, 4U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 3);
  c12_ref = c12_ee_ang[2];
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 4);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 0, c12_ee_pos[0] > 1.5)) {
    if (CV_EML_COND(0, 1, 1, c12_ee_pos[0] < 1.52)) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 0, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 5);
      c12_x = c12_ee_pos[0] - 1.5;
      c12_b_x = c12_x;
      c12_y = muDoubleScalarAbs(c12_b_x);
      c12_b = c12_y;
      c12_b_y = 0.17453292519943295 * c12_b;
      c12_a = c12_b_y;
      c12_ref = c12_a * 50.0;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 6);
    if (CV_EML_IF(0, 1, 1, c12_ee_pos[0] > 1.52)) {
      _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 7);
      c12_ref = 0.17453292519943295;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -7);
  sf_debug_symbol_scope_pop();
  *c12_b_ref = c12_ref;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  sf_debug_check_for_state_inconsistency(_dynamics_kinematicsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc12_dynamics_kinematics
  (SFc12_dynamics_kinematicsInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber)
{
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_dynamics_kinematicsInstanceStruct *chartInstance;
  chartInstance = (SFc12_dynamics_kinematicsInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static real_T c12_emlrt_marshallIn(SFc12_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c12_ref, const char_T *c12_identifier)
{
  real_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_ref), &c12_thisId);
  sf_mex_destroy(&c12_ref);
  return c12_y;
}

static real_T c12_b_emlrt_marshallIn(SFc12_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d0, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_ref;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_dynamics_kinematicsInstanceStruct *chartInstance;
  chartInstance = (SFc12_dynamics_kinematicsInstanceStruct *)chartInstanceVoid;
  c12_ref = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_ref), &c12_thisId);
  sf_mex_destroy(&c12_ref);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i4;
  real_T c12_b_inData[3];
  int32_T c12_i5;
  real_T c12_u[3];
  const mxArray *c12_y = NULL;
  SFc12_dynamics_kinematicsInstanceStruct *chartInstance;
  chartInstance = (SFc12_dynamics_kinematicsInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  for (c12_i4 = 0; c12_i4 < 3; c12_i4++) {
    c12_b_inData[c12_i4] = (*(real_T (*)[3])c12_inData)[c12_i4];
  }

  for (c12_i5 = 0; c12_i5 < 3; c12_i5++) {
    c12_u[c12_i5] = c12_b_inData[c12_i5];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

const mxArray *sf_c12_dynamics_kinematics_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo;
  c12_ResolvedFunctionInfo c12_info[6];
  c12_ResolvedFunctionInfo (*c12_b_info)[6];
  const mxArray *c12_m0 = NULL;
  int32_T c12_i6;
  c12_ResolvedFunctionInfo *c12_r0;
  c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  c12_b_info = (c12_ResolvedFunctionInfo (*)[6])c12_info;
  (*c12_b_info)[0].context = "";
  (*c12_b_info)[0].name = "mrdivide";
  (*c12_b_info)[0].dominantType = "double";
  (*c12_b_info)[0].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c12_b_info)[0].fileTimeLo = 1325124138U;
  (*c12_b_info)[0].fileTimeHi = 0U;
  (*c12_b_info)[0].mFileTimeLo = 1319729966U;
  (*c12_b_info)[0].mFileTimeHi = 0U;
  (*c12_b_info)[1].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c12_b_info)[1].name = "rdivide";
  (*c12_b_info)[1].dominantType = "double";
  (*c12_b_info)[1].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c12_b_info)[1].fileTimeLo = 1286818844U;
  (*c12_b_info)[1].fileTimeHi = 0U;
  (*c12_b_info)[1].mFileTimeLo = 0U;
  (*c12_b_info)[1].mFileTimeHi = 0U;
  (*c12_b_info)[2].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c12_b_info)[2].name = "eml_div";
  (*c12_b_info)[2].dominantType = "double";
  (*c12_b_info)[2].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c12_b_info)[2].fileTimeLo = 1313347810U;
  (*c12_b_info)[2].fileTimeHi = 0U;
  (*c12_b_info)[2].mFileTimeLo = 0U;
  (*c12_b_info)[2].mFileTimeHi = 0U;
  (*c12_b_info)[3].context = "";
  (*c12_b_info)[3].name = "mtimes";
  (*c12_b_info)[3].dominantType = "double";
  (*c12_b_info)[3].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c12_b_info)[3].fileTimeLo = 1289519692U;
  (*c12_b_info)[3].fileTimeHi = 0U;
  (*c12_b_info)[3].mFileTimeLo = 0U;
  (*c12_b_info)[3].mFileTimeHi = 0U;
  (*c12_b_info)[4].context = "";
  (*c12_b_info)[4].name = "abs";
  (*c12_b_info)[4].dominantType = "double";
  (*c12_b_info)[4].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c12_b_info)[4].fileTimeLo = 1286818694U;
  (*c12_b_info)[4].fileTimeHi = 0U;
  (*c12_b_info)[4].mFileTimeLo = 0U;
  (*c12_b_info)[4].mFileTimeHi = 0U;
  (*c12_b_info)[5].context =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c12_b_info)[5].name = "eml_scalar_abs";
  (*c12_b_info)[5].dominantType = "double";
  (*c12_b_info)[5].resolved =
    "[ILXE]/usr/local/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c12_b_info)[5].fileTimeLo = 1286818712U;
  (*c12_b_info)[5].fileTimeHi = 0U;
  (*c12_b_info)[5].mFileTimeLo = 0U;
  (*c12_b_info)[5].mFileTimeHi = 0U;
  sf_mex_assign(&c12_m0, sf_mex_createstruct("nameCaptureInfo", 1, 6), FALSE);
  for (c12_i6 = 0; c12_i6 < 6; c12_i6++) {
    c12_r0 = &c12_info[c12_i6];
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->context)), "context", "nameCaptureInfo",
                    c12_i6);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->name)), "name", "nameCaptureInfo", c12_i6);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      c12_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c12_i6);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->resolved)), "resolved",
                    "nameCaptureInfo", c12_i6);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c12_i6);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c12_i6);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      &c12_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c12_i6);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      &c12_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c12_i6);
  }

  sf_mex_assign(&c12_nameCaptureInfo, c12_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c12_nameCaptureInfo);
  return c12_nameCaptureInfo;
}

static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_dynamics_kinematicsInstanceStruct *chartInstance;
  chartInstance = (SFc12_dynamics_kinematicsInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static int32_T c12_c_emlrt_marshallIn(SFc12_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i7;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i7, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i7;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_dynamics_kinematicsInstanceStruct *chartInstance;
  chartInstance = (SFc12_dynamics_kinematicsInstanceStruct *)chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static uint8_T c12_d_emlrt_marshallIn(SFc12_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_dynamics_kinematics, const
  char_T *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_dynamics_kinematics), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_dynamics_kinematics);
  return c12_y;
}

static uint8_T c12_e_emlrt_marshallIn(SFc12_dynamics_kinematicsInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void init_dsm_address_info(SFc12_dynamics_kinematicsInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c12_dynamics_kinematics_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2926462430U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1687877584U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2674267345U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(57893165U);
}

mxArray *sf_c12_dynamics_kinematics_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("6wuFSAdD6CIv03SacLNImB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c12_dynamics_kinematics(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[9],T\"ref\",},{M[8],M[0],T\"is_active_c12_dynamics_kinematics\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_dynamics_kinematics_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_dynamics_kinematicsInstanceStruct *chartInstance;
    chartInstance = (SFc12_dynamics_kinematicsInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_dynamics_kinematicsMachineNumber_,
           12,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_dynamics_kinematicsMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_dynamics_kinematicsMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_dynamics_kinematicsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"ref");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ee_pos");
          _SFD_SET_DATA_PROPS(2,1,1,0,"ee_ang");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,226);
        _SFD_CV_INIT_EML_IF(0,1,0,73,106,160,181);
        _SFD_CV_INIT_EML_IF(0,1,1,160,181,-1,181);

        {
          static int condStart[] = { 76, 92 };

          static int condEnd[] = { 89, 106 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,76,106,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)c12_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c12_ref;
          real_T (*c12_ee_pos)[3];
          real_T (*c12_ee_ang)[3];
          c12_ee_ang = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c12_ee_pos = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          c12_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c12_ref);
          _SFD_SET_DATA_VALUE_PTR(1U, *c12_ee_pos);
          _SFD_SET_DATA_VALUE_PTR(2U, *c12_ee_ang);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_dynamics_kinematicsMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "t1hIgoWZ3JBR9A7h5IxrCH";
}

static void sf_opaque_initialize_c12_dynamics_kinematics(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_dynamics_kinematicsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c12_dynamics_kinematics
    ((SFc12_dynamics_kinematicsInstanceStruct*) chartInstanceVar);
  initialize_c12_dynamics_kinematics((SFc12_dynamics_kinematicsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c12_dynamics_kinematics(void *chartInstanceVar)
{
  enable_c12_dynamics_kinematics((SFc12_dynamics_kinematicsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c12_dynamics_kinematics(void *chartInstanceVar)
{
  disable_c12_dynamics_kinematics((SFc12_dynamics_kinematicsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c12_dynamics_kinematics(void *chartInstanceVar)
{
  sf_c12_dynamics_kinematics((SFc12_dynamics_kinematicsInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c12_dynamics_kinematics
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c12_dynamics_kinematics
    ((SFc12_dynamics_kinematicsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_dynamics_kinematics();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c12_dynamics_kinematics(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_dynamics_kinematics();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c12_dynamics_kinematics((SFc12_dynamics_kinematicsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c12_dynamics_kinematics(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c12_dynamics_kinematics(S);
}

static void sf_opaque_set_sim_state_c12_dynamics_kinematics(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c12_dynamics_kinematics(S, st);
}

static void sf_opaque_terminate_c12_dynamics_kinematics(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_dynamics_kinematicsInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c12_dynamics_kinematics((SFc12_dynamics_kinematicsInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_dynamics_kinematics_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_dynamics_kinematics((SFc12_dynamics_kinematicsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_dynamics_kinematics(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c12_dynamics_kinematics
      ((SFc12_dynamics_kinematicsInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_dynamics_kinematics(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_dynamics_kinematics_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,12,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,12,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,12,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1324166833U));
  ssSetChecksum1(S,(3587800318U));
  ssSetChecksum2(S,(1960794236U));
  ssSetChecksum3(S,(20368105U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c12_dynamics_kinematics(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_dynamics_kinematics(SimStruct *S)
{
  SFc12_dynamics_kinematicsInstanceStruct *chartInstance;
  chartInstance = (SFc12_dynamics_kinematicsInstanceStruct *)malloc(sizeof
    (SFc12_dynamics_kinematicsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc12_dynamics_kinematicsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c12_dynamics_kinematics;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c12_dynamics_kinematics;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c12_dynamics_kinematics;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c12_dynamics_kinematics;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c12_dynamics_kinematics;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c12_dynamics_kinematics;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c12_dynamics_kinematics;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c12_dynamics_kinematics;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_dynamics_kinematics;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_dynamics_kinematics;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c12_dynamics_kinematics;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c12_dynamics_kinematics_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_dynamics_kinematics(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_dynamics_kinematics(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_dynamics_kinematics(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_dynamics_kinematics_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
