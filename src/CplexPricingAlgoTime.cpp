#include "CplexPricingAlgo.h"
#include <iostream>

using namespace std;

DualCostsTime::DualCostsTime(InstanceUCP* inst) {
//    int n = inst->getn() ;
//    int T= inst->getT() ;
//    Mu.resize(T, 0) ;
//    Nu.resize(n*T, 0) ;
//    Phi.resize(n*T, 0) ;
//    Psi.resize(n*T, 0) ;
//    Sigma.resize(inst->getS(), 0) ;
}



CplexPricingAlgoTime::CplexPricingAlgoTime(InstanceUCP* inst, int site) {
//    Site=site ;

//    int ns = inst->nbUnits(Site) ;
//    int first = inst->firstUnit(Site) ;
//    int T = inst->getT() ;
//    model = IloModel(env) ;


//    x = IloBoolVarArray(env, ns*T) ;
//    u = IloBoolVarArray(env, ns*T) ;


//    //AddSSBI(env, model, x,u, site, inst) ;

//    obj = IloAdd(model, IloMinimize(env, 0.0));

//    //    // Conditions initiales
//    //    for (int i=0; i<ns; i++) {
//    //        model.add(u[i*T] >= x[i*T] - 1 ) ;
//    //    }

//    //    for (int i=0; i<ns; i++) {
//    //        IloExpr sum(env) ;
//    //        for (int k= 0; k < inst->getl(first+i) ; k++) {
//    //            sum += u[i*T + k] ;
//    //        }
//    //        model.add(sum <= 0 ) ;
//    //        sum.end() ;
//    //    }

//    // Min up constraints
//    for (int i=0; i<ns; i++) {
//        for (int t=inst->getL(first+i) ; t < T ; t++) {
//            IloExpr sum(env) ;
//            for (int k= t - inst->getL(first+i) + 1; k <= t ; k++) {
//                sum += u[i*T + k] ;
//            }
//            model.add(sum <= x[i*T + t]) ;
//            sum.end() ;
//        }
//    }


//    // Min down constraints
//    for (int i=0; i<ns; i++) {
//        for (int t=inst->getl(first+i) ; t < T ; t++) {
//            IloExpr sum(env) ;
//            for (int k= t - inst->getl(first+i) + 1; k <= t ; k++) {
//                sum += u[i*T + k] ;
//            }
//            model.add(sum <= 1 - x[i*T + t - inst->getl(first+i)]) ;
//            sum.end() ;
//        }
//    }

//    //Relation entre u et x
//    for (int i=0; i<ns; i++) {
//        for (int t=1 ; t < T ; t++) {
//            model.add(x[i*T + t] - x[i*T + t-1] <= u[i*T + t]);
//        }
//    }

//    //Contraintes intra-site
//    for (int t=1 ; t < T ; t++) {
//        IloExpr sum(env) ;
//        for (int i=0 ; i <ns ; i++) {
//            sum+=u[i*T+t] ;
//        }
//        model.add(sum <= 1);
//        sum.end() ;
//    }


//    //Objectif pour u
//    for (int i=0 ; i<ns ; i++) {
//        for (int t=0 ; t < T ; t++) {
//            obj.setLinearCoef(u[i*T +t],inst->getc0(first+i));
//        }
//    }

//    cplex = IloCplex(model);
//    cplex.setParam(IloCplex::EpGap, 0.00001) ;

//    //Initialisation des coefficients objectifs (primaux) de x
//    BaseObjCoefX.resize(ns, 0) ;
//    for (int i=0 ; i <ns ; i++) {
//        BaseObjCoefX[i] = inst->getcf(first+i) + (inst->getPmin(first+i))*inst->getcp(first+i) ;
//        //  cout << "unit i: " << inst->getcf(first+i) + (inst->getPmax(first+i) - inst->getPmin(first+i))*inst->getcp(first+i) << endl ;
//    }

}

void CplexPricingAlgoTime::updateObjCoefficients(InstanceUCP* inst, const Parameters & Param, const DualCostsTime & Dual, bool Farkas) {
//    int ns = inst->nbUnits(Site) ;
//    int T = inst->getT();
//    int first = inst->firstUnit(Site) ;
//    for (int i=0 ; i<ns ; i++) {

//        double RU = (inst->getPmax(first+i) - inst->getPmin(first+i))/3 ;
//        double RD = (inst->getPmax(first+i) - inst->getPmin(first+i))/2 ;

//        for (int t=0 ; t < T ; t++) {
//            //RAMPSTUFF
//            double dual_coef = - inst->getPmin(first+i)*Dual.Mu[t] - (inst->getPmax(first+i) - inst->getPmin(first+i))*Dual.Nu[(first+i)*T+t] ;
//            if (Param.Ramp) {
//                if (t > 0) {
//                    dual_coef += RD*Dual.Psi[(first+i)*T+t] ;
//                }
//                if (t < T-1) {
//                    dual_coef += RU*Dual.Phi[(first+i)*T+t+1] ;
//                }
//            }
//            if (!Farkas) {
//                obj.setLinearCoef(x[i*T +t],BaseObjCoefX[i]  + dual_coef );
//                obj.setLinearCoef(u[i*T +t],inst->getc0(first+i)) ;
//            }
//            else{
//                obj.setLinearCoef(x[i*T +t],  dual_coef );
//                obj.setLinearCoef(u[i*T +t],0.0) ;
//            }
//            //cout << "obj coef: " << BaseObjCoefX[i] - inst->getPmin(first+i)*Dual.Mu[t] - (inst->getPmax(first+i) - inst->getPmin(first+i))*Dual.Nu[(first+i)*T+t] - Dual.Sigma[Site] << endl ;
//        }
//    }
}


bool CplexPricingAlgoTime::findUpDownPlan(InstanceUCP* inst, const DualCostsTime & Dual, IloNumArray UpDownPlan, double& objvalue, double& realCost) {
    //returns True if an improving Up/Down plan has been found

//    ofstream LogFile("LogFile.txt");
//    cplex.setOut(LogFile);

//    if ( !cplex.solve() ) {
//        env.error() << "Failed to optimize Pricer with Cplex" << endl;
//        exit(1);
//    }

//    if (cplex.getStatus()==CPX_STAT_INFEASIBLE){
//        cout<<"NO SOLUTION TO PRICER"<<endl;
//        cout<<endl<<" ************************* END PRICER with CPLEX"<<endl<<endl;

//        return false;
//    }
//    else {

//        cplex.getValues(x, UpDownPlan) ;

//        /*cout << "for site " << Site << "; " << endl ;
//       cout << "obj value without sigma: " << cplex.getObjValue() << endl;*/
//        objvalue = cplex.getObjValue() - Dual.Sigma[Site] ;
//    }


    return true;
}
