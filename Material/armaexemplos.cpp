#include<RcppArmadillo.h>
// [[Rcpp::depends("RcppArmadillo")]]

using namespace Rcpp;


//[[Rcpp::export()]]
double prodinterno2(arma::vec x, arma::vec y){
  double prod = arma::as_scalar(x.t()*y);
  return(prod);
}

//[[Rcpp::export()]]
arma::mat exemplo1(arma::mat x){
  return(x);
}



//[[Rcpp::export()]]
arma::vec exemplo2(arma::vec x){
  return(x);
}


//[[Rcpp::export()]]
arma::mat exemplo3(NumericMatrix x){
  arma::mat y=as<arma::mat>(x);
  return (y);
}

//[[Rcpp::export()]]
NumericMatrix exemplo4(arma::mat x){
  NumericMatrix y=wrap(x);
  return (y);
}

//[[Rcpp::export()]]
arma::mat exemplo5(arma::mat x){
  int r=x.n_rows; // na classe rcpp havia .nrow();
  int c=x.n_cols;
  printf(" linhas:%d \n colunas:%d \n",r,c);
  return(x);
}

// [[Rcpp::export()]]
List exemplo6(int n, int r, double v) {
  arma::mat x1;
  x1.print();
  x1.reshape(n, r);
  x1.fill(v);
  arma::mat x2(n, r);
  x2 = diagmat(x1);
  arma::vec x3 = vectorise(x2);
  
  List retorne;
  retorne["x1"] = x1;  retorne["x2"] = x2;  retorne["x3"] = x3;
  return(retorne) ;
}


//[[Rcpp::export()]]
List exemplo7(int n, int m, double v){
  arma::mat x(n,m); x.fill(v);
  arma::colvec y( rnorm(n,0,1) ); 
  arma::rowvec z(rgamma(m,2,5));
  List retorno;
  retorno["X"]=x; retorno["Y"]=y; retorno["Z"]=z;
  return retorno;
}

//[[Rcpp::export()]]
arma::mat exemplo8(int n, int r){
  arma::mat x(n, r);
  x.print("");
  x.ones();
  return(x);
}

//[[Rcpp::export()]]
double exemplo9(arma::mat x, int i, int j){
  return(x(i,j));
}

//[[Rcpp::export()]]
arma::mat exemplo10(arma::mat x, int i){
  return(x.row(i));
}

//[[Rcpp::export()]]
arma::mat exemplo11(arma::mat x, int j){
  return(x.col(j));
}

//[[Rcpp::export()]]
arma::mat exemplo12(arma::mat x){
  return (x+x);
}

//[[Rcpp::export()]]
arma::mat exemplo13(arma::mat x){
  return (x-x);
}

//[[Rcpp::export()]]
arma::mat exemplo14(arma::mat x){
  return (x%x);
}

//[[Rcpp::export()]]
arma::mat exemplo15(arma::mat x){
  return (exp(x));
}

//[[Rcpp::export()]]
arma::mat exemplo16(arma::mat x){
  return (x.t());
}

//[[Rcpp::export()]]
arma::mat exemplo17(arma::mat x){
  return (x.t()*x);
}

//[[Rcpp::export()]]
arma::mat exemplo18(arma::mat x){
  return (  (x.t()*x).i() );
}

//[[Rcpp::export()]]
arma::mat exemplo19(int i){
  arma::mat A(2,3);
  arma::mat B(i,1);
  A.randu(); A.print();
  B.randu(); B.print();
  return (A*B);
}



// [[Rcpp::export]]
List ajustaML(arma::vec y, arma::mat x){
  int n = x.n_rows;
  int k = x.n_cols;
  arma::colvec beta = arma::solve(x, y); // estima os betas
  
  // arma::colvec beta = (x.t()*x).i() * x.t()*y ;
  
  arma::colvec erro = y - x*beta;       // calcula os resíduos
  double sig2 = arma::as_scalar( erro.t()*erro / (n-k) );
  
  arma::colvec sdbeta = sqrt( sig2*diagvec( (x.t()*x).i() ) );
  
  return( List::create(Named("coeficientes", beta),
                       Named("desvio padrao beta", sdbeta)
  ) );
}



//[[Rcpp::export()]]
arma::mat exemplo20(arma::mat M){
  arma::mat Z = M * M.t();
  arma::vec vetor = Z.elem( find(Z >= 100) );
  return(vetor);
}


//[[Rcpp::export()]]
DataFrame exemplo21( ){
  arma::vec v1(rpois(15,5));
  arma::vec v2(rgamma(15,2,4));
  arma::vec v3(rbinom(15,7,0.6));
  arma::vec v4(runif(15,-2,3));
  DataFrame df = DataFrame::create( Named("Poisson",v1),
                                    Named("Gamma", v2) ,
                                    Named("Binomial", v3),
                                    Named("Uniforme", v4)
                                    );
  return(df);
}

//[[Rcpp::export()]]
DataFrame exemplo22( ){
  arma::vec v1(rpois(15,5));
  arma::vec v2(rgamma(15,2,4));
  arma::vec v3(rbinom(15,7,0.6));
  arma::vec v4(runif(15,-2,3));
  DataFrame df = DataFrame::create( Named("Poisson",v1),
                                    Named("Gamma", v2) ,
                                    Named("Binomial", v3),
                                    Named("Uniforme", v4) );
  
  List GU = List::create(Named("dist.gama", df["Gamma"]),
                         Named("dist.uniforme", df[3]) );

  return(GU);
}


//[[Rcpp::export()]]
DataFrame exemplo23( ){
  NumericVector v = {2,4,6};
  DataFrame df = DataFrame::create( Named("vetor1",v),
                                    Named("vetor2", clone(v) ) );
  v = 2*v;
  return(df);
}


//[[Rcpp::export()]]
DataFrame exemplo24(CharacterVector u ){
  int n = u.length();
  NumericVector w = NumericVector::create(1,2,3,4,5);
  arma::vec w1 = as<arma::vec>(w);
  arma::vec x(rbinom(n, 10, 0.7)); 
  double z = arma::as_scalar( x.t()*w1 );
  return(DataFrame::create( Named("Times",u),
                            Named("vetor criado",w1),
                            Named("vetor gerado", x),
                            Named("conta",z)) );
  
}









//calculo da area de uma circulo de raio 1. Aproximacao de pi 
/*
 
 //[[Rcpp::export()]]
 double valorpi(int n){
arma::vec x = runif(n,-1,1);
arma::vec y = runif(n,-1,1);
arma::vec I = sqrt( pow(x,2) + pow(y,2) );
double conta = 0;
for(int i = 0; i < I.size(); i++){
if( I[i] <= 1 ){ conta += 1;}
}
conta = (4*conta)/n;
return(conta);
 }

*/
