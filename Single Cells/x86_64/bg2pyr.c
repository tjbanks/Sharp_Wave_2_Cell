/* Created by Language version: 6.2.0 */
/* NOT VECTORIZED */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define _threadargscomma_ /**/
#define _threadargs_ /**/
 
#define _threadargsprotocomma_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define initW _p[0]
#define taun1 _p[1]
#define taun2 _p[2]
#define gNMDAmax _p[3]
#define enmda _p[4]
#define taua1 _p[5]
#define taua2 _p[6]
#define gAMPAmax _p[7]
#define eampa _p[8]
#define inmda _p[9]
#define gnmda _p[10]
#define gnmdas _p[11]
#define factorn _p[12]
#define normconstn _p[13]
#define iampa _p[14]
#define gampa _p[15]
#define gampas _p[16]
#define factora _p[17]
#define normconsta _p[18]
#define An _p[19]
#define Bn _p[20]
#define Aa _p[21]
#define Ba _p[22]
#define eca _p[23]
#define DAn _p[24]
#define DBn _p[25]
#define DAa _p[26]
#define DBa _p[27]
#define _g _p[28]
#define _tsav _p[29]
#define _nd_area  *_ppvar[0]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_sfunc();
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(_ho) Object* _ho; { void* create_point_process();
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt();
 static double _hoc_loc_pnt(_vptr) void* _vptr; {double loc_point_process();
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(_vptr) void* _vptr; {double has_loc_point();
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(_vptr)void* _vptr; {
 double get_loc_point_process(); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "sfunc", _hoc_sfunc,
 0, 0
};
#define sfunc sfunc_bg2pyr
 extern double sfunc( double );
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "taun1", "ms",
 "taun2", "ms",
 "gNMDAmax", "uS",
 "enmda", "mV",
 "taua1", "ms",
 "taua2", "ms",
 "gAMPAmax", "uS",
 "eampa", "mV",
 "inmda", "nA",
 "iampa", "nA",
 0,0
};
 static double Aa0 = 0;
 static double An0 = 0;
 static double Ba0 = 0;
 static double Bn0 = 0;
 static double delta_t = 0.01;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[2]._i
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "6.2.0",
"bg2pyr",
 "initW",
 "taun1",
 "taun2",
 "gNMDAmax",
 "enmda",
 "taua1",
 "taua2",
 "gAMPAmax",
 "eampa",
 0,
 "inmda",
 "gnmda",
 "gnmdas",
 "factorn",
 "normconstn",
 "iampa",
 "gampa",
 "gampas",
 "factora",
 "normconsta",
 0,
 "An",
 "Bn",
 "Aa",
 "Ba",
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 30, _prop);
 	/*initialize range parameters*/
 	initW = 6.3;
 	taun1 = 5;
 	taun2 = 125;
 	gNMDAmax = 0.0005;
 	enmda = 0;
 	taua1 = 0.5;
 	taua2 = 7;
 	gAMPAmax = 0.001;
 	eampa = 0;
  }
 	_prop->param = _p;
 	_prop->param_size = 30;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _net_receive(Point_process*, double*, double);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*f)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _bg2pyr_reg() {
	int _vectorized = 0;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 0,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
  hoc_register_prop_size(_mechtype, 30, 3);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 pnt_receive[_mechtype] = _net_receive;
 pnt_receive_size[_mechtype] = 1;
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 bg2pyr /storage/hpc/data/latimerb/Sharp_Wave_BLA/Single Cells/x86_64/bg2pyr.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 extern int state_discon_flag_;
 static int _slist1[4], _dlist1[4];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   DAn = - An / taun1 ;
   DBn = - Bn / taun2 ;
   DAa = - Aa / taua1 ;
   DBa = - Ba / taua2 ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 DAn = DAn  / (1. - dt*( ( - 1.0 ) / taun1 )) ;
 DBn = DBn  / (1. - dt*( ( - 1.0 ) / taun2 )) ;
 DAa = DAa  / (1. - dt*( ( - 1.0 ) / taua1 )) ;
 DBa = DBa  / (1. - dt*( ( - 1.0 ) / taua2 )) ;
 return 0;
}
 /*END CVODE*/
 static int states () {_reset=0;
 {
    An = An + (1. - exp(dt*(( - 1.0 ) / taun1)))*(- ( 0.0 ) / ( ( - 1.0 ) / taun1 ) - An) ;
    Bn = Bn + (1. - exp(dt*(( - 1.0 ) / taun2)))*(- ( 0.0 ) / ( ( - 1.0 ) / taun2 ) - Bn) ;
    Aa = Aa + (1. - exp(dt*(( - 1.0 ) / taua1)))*(- ( 0.0 ) / ( ( - 1.0 ) / taua1 ) - Aa) ;
    Ba = Ba + (1. - exp(dt*(( - 1.0 ) / taua2)))*(- ( 0.0 ) / ( ( - 1.0 ) / taua2 ) - Ba) ;
   }
  return 0;
}
 
static void _net_receive (_pnt, _args, _lflag) Point_process* _pnt; double* _args; double _lflag; 
{    _p = _pnt->_prop->param; _ppvar = _pnt->_prop->dparam;
  if (_tsav > t){ extern char* hoc_object_name(); hoc_execerror(hoc_object_name(_pnt->ob), ":Event arrived out of order. Must call ParallelContext.set_maxstep AFTER assigning minimum NetCon.delay");}
 _tsav = t; {
   double _lx ;
 _lx = _args[0] ;
   state_discontinuity ( _cvode_ieq + 0, & An , An + _lx ) ;
   state_discontinuity ( _cvode_ieq + 1, & Bn , Bn + _lx ) ;
   state_discontinuity ( _cvode_ieq + 2, & Aa , Aa + _lx ) ;
   state_discontinuity ( _cvode_ieq + 3, & Ba , Ba + _lx ) ;
   } }
 
double sfunc (  double _lv ) {
   double _lsfunc;
  _lsfunc = 1.0 / ( 1.0 + 0.33 * exp ( - 0.06 * _lv ) ) ;
    
return _lsfunc;
 }
 
static double _hoc_sfunc(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  sfunc (  *getarg(1) );
 return(_r);
}
 
static int _ode_count(int _type){ return 4;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 ();
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 4; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
 _ode_matsol1 ();
 }}

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  Aa = Aa0;
  An = An0;
  Ba = Ba0;
  Bn = Bn0;
 {
   An = 0.0 ;
   Bn = 0.0 ;
   factorn = taun1 * taun2 / ( taun2 - taun1 ) ;
   normconstn = - 1.0 / ( factorn * ( 1.0 / exp ( log ( taun2 / taun1 ) / ( taun1 * ( 1.0 / taun1 - 1.0 / taun2 ) ) ) - 1.0 / exp ( log ( taun2 / taun1 ) / ( taun2 * ( 1.0 / taun1 - 1.0 / taun2 ) ) ) ) ) ;
   Aa = 0.0 ;
   Ba = 0.0 ;
   factora = taua1 * taua2 / ( taua2 - taua1 ) ;
   normconsta = - 1.0 / ( factora * ( 1.0 / exp ( log ( taua2 / taua1 ) / ( taua1 * ( 1.0 / taua1 - 1.0 / taua2 ) ) ) - 1.0 / exp ( log ( taua2 / taua1 ) / ( taua2 * ( 1.0 / taua1 - 1.0 / taua2 ) ) ) ) ) ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _tsav = -1e20;
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   gnmda = normconstn * factorn * ( Bn - An ) ;
   gnmdas = gnmda ;
   if ( gnmdas > 1.0 ) {
     gnmdas = 1.0 ;
     }
   inmda = initW * gNMDAmax * gnmdas * ( v - enmda ) * sfunc ( _threadargscomma_ v ) ;
   gampa = normconsta * factora * ( Ba - Aa ) ;
   gampas = gampa ;
   if ( gampas > 1.0 ) {
     gampas = 1.0 ;
     }
   iampa = initW * gAMPAmax * gampas * ( v - eampa ) ;
   }
 _current += inmda;
 _current += iampa;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _g = _nrn_current(_v + .001);
 	{ state_discon_flag_ = 1; _rhs = _nrn_current(_v); state_discon_flag_ = 0;
 	}
 _g = (_g - _rhs)/.001;
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
 double _break, _save;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _break = t + .5*dt; _save = t;
 v=_v;
{
 { {
 for (; t < _break; t += dt) {
 error =  states();
 if(error){fprintf(stderr,"at line 85 in file bg2pyr.mod:\n	SOLVE states METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 
}}
 t = _save;
 }}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(An) - _p;  _dlist1[0] = &(DAn) - _p;
 _slist1[1] = &(Bn) - _p;  _dlist1[1] = &(DBn) - _p;
 _slist1[2] = &(Aa) - _p;  _dlist1[2] = &(DAa) - _p;
 _slist1[3] = &(Ba) - _p;  _dlist1[3] = &(DBa) - _p;
_first = 0;
}
