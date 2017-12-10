/*
** svn $Id: icetest.h 1307 2008-01-10 00:22:36Z bgalton $
*******************************************************************************
** Copyright (c) 2002-2008 The ROMS/TOMS Group                               **
**   Licensed under a MIT/X style license                                    **
**   See License_ROMS.txt                                                    **
*******************************************************************************
**
** Options for idealised Ice Shelf Ocean Cavity Model for FISOC testing.
**
** Application flag:   ICESHELF2D
** Input script:       ocean_iceshelf2d.in
*/
#define UV_ADV
#define DJ_GRADPS
#undef UV_COR
#define UV_VIS2
#define UV_QDRAG
#define MIX_GEO_UV
#undef MIX_S_UV
#define TS_C4HADVECTION
#define TS_C4VADVECTION
#define TS_DIF2
#define MIX_GEO_TS
#undef  MIX_S_TS
#define SOLVE3D
#define SALINITY
#define NONLIN_EOS
#define CURVGRID
#undef SPHERICAL
#define SPLINES_VDIFF
#define SPLINES_VVISC
#define LIMIT_BSTRESS

#define ICESHELF
#ifdef ICESHELF
# undef ICESHELF_2EQN_VBC
# define ICESHELF_3EQN_VBC
# undef ICESHELF_TEOS10
# undef ICESHELF_MORPH
# define LIMIT_ICESTRESS
#endif

/* 
** Coupling through FISOC (framework for ice sheet ocean couping).
** The FISOC option can be set in the build script.
** FISOC_DDDT is short for d(ice draft)/d(time), i.e. we get rate of change of ice draft 
** from the coupling to the ice sheet model.
*/

#ifdef FISOC
# define FISOC_DDDT
# define ICESHELF_MORPH
#endif

#undef  AVERAGES
#undef ATM_PRESS
#undef ANA_PAIR
#define MASKING
#define ANA_MASK
#define WET_DRY
#define ANA_GRID
#define ANA_INITIAL
#define ANA_SMFLUX
#define ANA_STFLUX
#define ANA_SSFLUX
#define ANA_BSFLUX
#define ANA_BTFLUX
#define ANA_SRFLUX

/* Define SET_VBC.F for open ocean boundary layer. Can be one of:
* * ANA_SEAICE
*  Note that both undef will set surface fluf of salt and temp to zero*/
#define ANA_SEAICE
/* Define SET_VBC.F for ice-ocean Thermodynamics. Can be one of:
*  * VBC_ICE_2EQN
*  * VBC_ICE_3EQN       
*  * Note that both undef will set surface fluf of salt and temp to zero */

#undef  ANA_VMIX
#undef MY25_MIXING
#define LMD_MIXING

#ifdef MY25_MIXING
#define N2S2_HORAVG
#define K_C4ADVECTION
#endif

#ifdef  LMD_MIXING
#define LMD_CONVEC 
#undef LMD_DDMIX 
#undef LMD_RIMIX
#undef LMD_SKPP
#endif

/* Test groundwater fluxes */
#undef UV_PSOURCE
#undef ANA_PSOURCE
#undef TS_PSOURCE
