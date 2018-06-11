#ifndef CPLEXCHECK
#define CPLEXCHECK

#include <ilcplex/ilocplex.h>

#include <vector>
#include <list>

#include "Process.h"
#include "InstanceUCP.h"

using namespace std;


class CplexChecker {
 public:

  InstanceUCP* inst ;
  const Parameters Param ;
  IloEnv   env;
  IloModel model;
  IloCplex cplex;

  IloBoolVarArray x;
  IloBoolVarArray u;
  IloNumVarArray pp ;

  double IntegerObj;
  double LRValue ;
  double LRCplexVal ;

  CplexChecker(InstanceUCP* inst, const Parameters & param) ;
  double getIntegerObjValue() ;
  double getLRValue() ;
  double getLRCplex() ;
  void CplexPrimalHeuristic(IloNumArray solution, IloNumArray solution_p) ;

  double printSolution();
  void checkSolution(const vector<double> & x_frac);

};



#endif
