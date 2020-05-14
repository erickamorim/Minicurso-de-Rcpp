#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector f_if_Rcpp(NumericVector x, double a, double b){
  
  int n =x.length(); NumericVector out(n);
  for(int i=0; i<n; i++){
    double xi=x[i];
    if(xi<a){out[i]=a;} else if (xi>b){out[i]=b;} else {out[i]=xi;}
  }
  return(out);
}

// [[Rcpp::export]]
int fibRcpp(const int x) { 
  if(x<2){return x;}
  else {return ( fibRcpp(x-1) + fibRcpp(x-2) ) ; } 
  }


// [[Rcpp::export()]]
Rcpp::NumericVector gvn1(){
  /* cria um vetor de tamanho 4 com
   entradas sendo o valor zero */
  Rcpp::NumericVector x(4);
  return(x);
}

// [[Rcpp::export()]]
Rcpp::NumericVector gvn2(){
  /* cria um vetor de tamanho 4 com
   entradas sendo o valor 7.3 */
  Rcpp::NumericVector x(4, 7.3);
  return(x);
}


// [[Rcpp::export()]]
Rcpp::LogicalVector gvl1(){
  /* cria um vetor de tamanho 4 com
   entradas sendo o valor FALSE */
  Rcpp::LogicalVector x(4);
  return(x);
}

// [[Rcpp::export()]]
Rcpp::LogicalVector gvl2(){
  /* cria um vetor de tamanho 4 com
   entradas sendo o valor TRUE */
  Rcpp::LogicalVector x(4, true);
  return(x);
}


// [[Rcpp::export()]]
Rcpp::NumericMatrix gmn(){
  // cria uma matriz 4 por 6 com
  // entradas sendo o valor zero
  Rcpp::NumericMatrix x(4, 6);
  return(x);
}

// [[Rcpp::export()]]
Rcpp::LogicalMatrix gml(){
  // cria uma matriz 4 por 6 com
  // entradas sendo o valor FALSE
  Rcpp::LogicalMatrix x(4, 6);
  return(x);
}

