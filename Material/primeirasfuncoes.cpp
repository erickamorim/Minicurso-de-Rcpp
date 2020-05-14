#include <Rcpp.h>
using namespace Rcpp;

// exemplo da distancia euclidiana entra um vetor e sai um escalar

//[[Rcpp::export]]
double distEuclid(NumericVector x, NumericVector y){
  int n = x.size();
  double out=0;
  for(int i = 0; i < n; i++){
    out += pow(x[i]-y[i], 2);
  }
  return( sqrt(out) );
}

/* exemplos com listas */

//[[Rcpp::export]]
List cpplist(int x, CharacterVector y, NumericVector z){
  return List::create(Rcpp::Named("x", rnorm(x,0,1)),
                      Rcpp::Named("y", y),
                      Rcpp::Named("z", pow(z,2) ) );
}

/* exemplos de funcoes que chamam funcoes */

//[[Rcpp::export]]
NumericVector cppfun(NumericVector x, Function f){
  NumericVector out(x.length());
  for(int i=0; i<100; i++){ 
    out=f(x);
  }
  return out;
}

/* chamando uma funcao do R no C++ */

//[[Rcpp::export]]
NumericVector Rcppfunc(NumericVector x, Function f){
  NumericVector out=f(x);
  return out;
}

/* funcao que calcula o produto interno, 
 entra dois vetores e sai um escalar */

//[[Rcpp::export]]
double prodinterno1(NumericVector x, NumericVector y){
  int k = x.length();
  double prod = 0;
  for(int i = 0; i < k; i++){
    prod += x(i)*y(i);
  }
  return(prod);
}


/*** R
x=rpois(100,6)
  Rcppfunc(x,fivenum)
  Rcppfunc(x,sum)
  */




