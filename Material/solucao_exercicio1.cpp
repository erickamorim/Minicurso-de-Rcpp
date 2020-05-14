#include <Rcpp.h>
using namespace Rcpp;

// solucao usando funcoes prontas

// [[Rcpp::export]]
List func(NumericVector x) {
  double media = mean(x);
  double sdx = sqrt( var(x) );
  double minimo = min(x);
  double maximo = max(x);
    
  return( List::create(Named("media",media),
                       Named("desvio padrao", sdx),
                       Named("minimo", minimo),
                       Named("maximo", maximo)  ) );
}


// solucao construindo as funcoes

// [[Rcpp::export]]
List func2(NumericVector x) {
  int n=x.size();
  double media = 0; 
  double numer = 0;
  for(int i=0; i < n;i++){
    media+=x[i];
  }
  media = media/n;
  for(int j=0; j < n; j++){
    numer += pow(x[j]- media, 2);
    
  }
  numer = numer/(n-1);
  double desviopadrao = sqrt( numer );
  double y = x[0];
  double z = y;
  for(int j=0; j < n; j++){
    if(y>x[j]){ y = x[j];}
    if(z<x[j]){ z = x[j];}
  }

  return( List::create(Named("media", media),
                       Named("desvio padrao", desviopadrao),
                       Named("minimo", y),
                       Named("maximo", z) ) );
}
