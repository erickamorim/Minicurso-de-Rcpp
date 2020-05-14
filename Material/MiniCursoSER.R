rm(list=ls())
#install.packages("Rcpp")
#install.packages("RcppArmadillo")
#install.packages("microbenchmark")
library("microbenchmark")
library("Rcpp")
#library("RcppArmadillo")
wd = getwd()
sourceCpp(paste(wd,"/functions.cpp",sep=""));

library("microbenchmark")
#teste da funcao microbenchmark
x=runif(100)
microbenchmark(sqrt(x),x^0.5,x^(1/2),(x)^(1/2))

#primeiro exemplo
#funcao1
f_if=function(x,a,b){
  ifelse(x<=a,a,ifelse(x>=b,b,x))  
}
#funcao2
f_pm=function(x,a,b){
  pmax(pmin(x,b),a)
}
#funcao3
f_colchet=function(x,a,b){
  x[x<=a]=a
  x[x>=a]=b
  x
}
x=runif(1000,-1,1)
microbenchmark(f_if(x,-1,1),f_pm(x,-1,1),f_colchet(x,-1,1),f_if_Rcpp(x,-1,1),times=1000)


#segundo exemplo
## serie fibonacci no R
fibR=function(n){ 
  if(n==0){ return (0)}
  if(n==1){ return (1)}
  return(fibR(n-1) + fibR(n-2))
}

microbenchmark(fibR(27),fibRcpp(27),times=10,unit = "ms")

###################################################################################################################

rm(list=ls())
#install.packages("Rcpp")
library("Rcpp")
wd = getwd()
sourceCpp(paste(wd,"/functions.cpp",sep=""))

gvn1()
gvn2()
gvl1()
gvl2()
gmn()
gml()

#Exercicio
#crie uma função para calcular o minimo, o maximo,
#a media e o desvio padrao dos dados abaixo

w=c(66, 117, 132, 111, 107, 85, 89, 79, 91, 97,
    138, 103, 111, 86, 78, 96, 93, 101, 102, 110,
    95, 96, 88, 122, 115, 92, 137, 91, 84, 96,
    97, 100, 105, 104, 137, 80, 104, 104, 106, 84,
    92, 86, 103, 132, 94, 99, 102, 101, 104, 107,
    99, 85, 95, 89, 102, 100, 98, 97, 104, 114,
    111, 98, 99, 102, 91, 95, 111, 104, 97, 98,
    102, 109, 88, 91, 103, 94, 105, 103, 96, 100,
    101, 98, 97, 97, 101, 102, 98, 94, 100, 98,
    99, 92, 102, 87, 99, 62, 92, 100, 96, 98)
