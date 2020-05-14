rm(list=ls())
#install.packages("RcppArmadillo")
library("RcppArmadillo")
library("Rcpp")
wd = getwd()
sourceCpp(paste(wd,"/armaexemplos.cpp",sep=""))

exemplo1(diag(3))
exemplo2(c(2,4,6,8))
exemplo3(diag(4)) #transforma de NumericMatrix para arma
exemplo4(matrix(runif(12),3,4)) #transforma de arma para NumericMatrix
exemplo5(matrix(runif(8),4,2)) #print e dimensao
exemplo6(2,3,3/4) #lista
exemplo6(3,4,5/7) #lista
exemplo7(3,4,4/5) #lista
exemplo8(3,4)  #inicializacao de valores 
set.seed(8)
Z=matrix(rnorm(6),2,3)
Z
exemplo9(Z,1,2) #elemento (i+1,j+1) da matriz Z
exemplo10(Z,1)   #linha (i+1) da matriz
exemplo11(Z,2)   #coluna (i+1) da matriz

exemplo12(Z)  #realiza a soma Z+Z
exemplo13(Z)  #realiza a diferenca Z-Z
exemplo14(Z)  #multiplica elemento por elemento de Z
exemplo15(Z)  #calcula exponencial de Z
exemplo16(Z)  #calcula a transposta de Z
exemplo17(Z)  #multiplicacao
exemplo18(Z)  #matriz inversa da multiplicacao no exemplo 17

exemplo19(3)  # nao havera mensagem de erro (dimensao ok!)
exemplo19(2)  # aqui havera mensagens de erro (dimensao nao ok)

M = matrix(1:9, nrow = 3, ncol = 3)
M
exemplo20(M)
exemplo21()
exemplo22()
exemplo23()
exemplo24(c("Paysandu","Ceará","Goiás","Atlético-MG","Chapecoense"))


# ajuste de um modelo de regressão linear

n=1000
x1=rnorm(n,0,sqrt(2))
x2=rt(n,7)
b0=0.1
b1=0.8
b2=-0.65
sigma2=1.5
erro=rnorm(n,0,sqrt(sigma2))
y=b0+b1*x1+b2*x2+erro
y=as.matrix(y)
x=as.matrix( cbind(rep(1,n),x1,x2) )

ajustaML(y,x)




