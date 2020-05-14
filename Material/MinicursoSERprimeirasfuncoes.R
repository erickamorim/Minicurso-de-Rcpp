rm(list=ls())
#install.packages("Rcpp")
library("Rcpp")
library("microbenchmark")
##usando o rcpp fora do ambiente .cpp
#exemplo que entra-se com um vetor e sai um vetor
sourceCpp(code='#include <Rcpp.h>
          using namespace Rcpp;
          
          //[[Rcpp::export]]
          NumericVector funcao1(NumericVector x){ return(x);}
          ')

funcao1(c(1,2,3,4))

#exemplo que entra-se com uma matriz e sai uma matriz
sourceCpp(code='#include <Rcpp.h>
          using namespace Rcpp;
          
          //[[Rcpp::export]]
          NumericMatrix funcao2(NumericMatrix x){ return(x);}
          ')

funcao2(matrix(c(1,2,3,4,5,6,7,8,9),nrow = 3))

#exemplo que entra-se com um vetor e sai a soma dos elementos
sourceCpp(code='#include <Rcpp.h>
          using namespace Rcpp;
          
          //[[Rcpp::export]]
          double sumRcpp(NumericVector x){ 
          int n=x.size();
          double total=0;
          for(int i=0; i<n; i++){
             total+=x[i];
            }
           return(total);}
          ')

##outra forma de criar funcoes no C++ e carrega-las para o R
code=' double sumRcpp2(NumericVector x){ 
          int n=x.size();
          double total=0;
          for(int i=0; i<n; i++){
             total+=x[i];
            }
           return(total);}
          '
cppFunction(code)

sumRcpp2(c(6,2,4,3,5))
sumRcpp(c(6,2,4,3,5))

#funcao sign criada em .cpp
code2=' int signCpp(int x){ 
            if(x > 0){ 
                return(1);
              } else if (x==0){
                return(0);
              } else { 
                return(-1);
              }
            }'

cppFunction(code2)
signCpp(-57)
signCpp(0)
signCpp(9)

#funcao Soma criada no R
sumR=function(x){
  total=0
  for(i in 1:length(x)){
    total=total+x[i]
  }
}
x=rpois(1000,6)
microbenchmark(sumR(x),sumRcpp(x),sum(x),times=1000) #veja que o tempo da funcao sum é menor

#exemplo distancia euclidiana, entra vetores sai um escalar
wd = getwd()
sourceCpp(paste(wd,"/primeirasfuncoes.cpp",sep="")) # carrega o arquivo .cpp onde estão as funcoes

distEuclid(c(1,3,5),c(3,4,5))        #funcao no arquivo .cpp
dist(matrix(c(1,3,4,3,5,5),nrow=2) ) #funcao do proprio R


##exemplos com listas
set.seed(9)
#exemplo no R
rlist=function(x,y,z){
  return( list(x=rnorm(x), y=y, z=z^2) )
}

#lista no R
rlist(5,c("Adriana","Patrícia","Renato","Silvio"),seq(-4,4))
#lista no Rcpp
cpplist(4,c("Adriana","Patrícia","Renato","Silvio"),seq(-4,4))


##exemplos de funcoes que chamam funcoes
rfun=function(x,f){
  for(i in 1:100){ out=f(x)}
  return(out)
}

#exemplos com funcoes no R
rfun(c(1,4,9),sqrt)
rfun(c(1,4,9),function(x){1/x})
#exemplos com funcoes no Rcpp
cppfun(c(1,4,9),sqrt)
cppfun(c(1,4,9),function(x){1/x})

x=1:7
f=sqrt
microbenchmark(rfun(x,f),cppfun(x,f)) #veja aqui que o tempo no R é menor


#exemplo chamando uma funcao do R no C++

x=rnorm(1000)
fivenum(x) # retorna o mínimo,1 quartil, mediana, 3 quartil e maximo
sum(x)
Rcppfunc(x,fivenum)
Rcppfunc(x,sum)

#exemplo da funcao produto interno
a=c(2,4,1,5,8)
b=c(3,5,9,1,6)
prodinterno1(a,b)
