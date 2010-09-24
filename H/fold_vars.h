#ifndef __VIENNA_RNA_PACKAGE_FOLD_VARS_H__
#define __VIENNA_RNA_PACKAGE_FOLD_VARS_H__

#include "data_structures.h"

/** \file fold_vars.h **/

/* to use floats instead of doubles in pf_fold() comment next line */
#define LARGE_PF
#ifdef  LARGE_PF
#define FLT_OR_DBL double
#else
#define FLT_OR_DBL float
#endif

#define PUBLIC
#define PRIVATE static

/**
*** Get the minimum of two comparable values
**/
#define MIN2(A, B)      ((A) < (B) ? (A) : (B))
/**
*** Get the maximum of two comparable values
**/
#define MAX2(A, B)      ((A) > (B) ? (A) : (B))
/**
*** Get the minimum of three comparable values
**/
#define MIN3(A, B, C)   (MIN2(  (MIN2((A),(B))) ,(C)))
/**
*** Get the maximum of three comparable values
**/
#define MAX3(A, B, C)   (MAX2(  (MAX2((A),(B))) ,(C)))

/** Global switch to activate/deactivate folding with structure constraints */
int    fold_constrained;
/** Global switch to avoid/allow helices of length 1 */
int    noLonelyPairs;
/** Switch the energy model for dangling end contributions (0, 1, 2, 3) */
int  dangles;
/** Global switch to forbid/allow GU base pairs at all */
int  noGU;
/** GU allowed only inside stacks */
int  no_closingGU;
/** Fold with specially stable 4-loops */
int  tetra_loop;
/** 0 = BP; 1=any mit GC; 2=any mit AU-parameter */
int  energy_set;
/** backward compatibility variable.. this does not effect anything */
int  circ;


extern int oldAliEn;        /* use old alifold energies (with gaps) */
extern int ribo;            /* use ribosum matrices */
extern char *RibosumFile;   /* warning this variable will vanish in the future
                               ribosums will be compiled in instead */
extern char *nonstandards;  /* contains allowed non standard bases */
extern double temperature;   /* rescale parameters to this temperature */
extern int  james_rule;     /* interior loops of size 2 get energy 0.8Kcal and
                               no mismatches, default 1 */
extern int  logML;          /* use logarithmic multiloop energy function */
extern int  cut_point;      /* first position of 2nd strand for co-folding */

extern bondT  *base_pair; /* list of base pairs */

extern FLT_OR_DBL *pr;          /* base pairing prob. matrix */
extern int   *iindx;            /* pr[i,j] -> pr[iindx[i]-j] */
extern double pf_scale;         /* scaling factor to avoid float overflows*/
extern int    do_backtrack;     /* calculate pair prob matrix in part_func() */
extern char backtrack_type;     /* usually 'F'; 'C' require (1,N) to be bonded;
                                   'M' seq is part of a multi loop */
char * option_string(void);
#endif
